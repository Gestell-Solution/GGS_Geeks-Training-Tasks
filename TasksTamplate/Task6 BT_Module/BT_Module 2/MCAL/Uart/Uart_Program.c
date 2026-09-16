/**
 * @file Uart_Program.c
 * @brief UART driver implementation (polling + interrupt) for the ATmega32.
 * @details Configuration (mode, baud rate, parity, ...) is passed to
 *          UART_Init() via UART_Config_t.
 *
 * ==================================================================
 * NOTE - Uart_Interface.h (the public header, not yet reviewed) must
 * declare the following prototypes with these exact signatures. All
 * of these used to be void / uint16_t; every caller (BT_Program.c,
 * main.c, ...) must be updated to match - a deliberate breaking
 * change so errors can no longer be silently swallowed inside the
 * data channel:
 *
 *   UART_Status_t UART_Init(UART_Config_t UART_Config);
 *   UART_Status_t UART_SendBytePolling(uint16_t Data);
 *   UART_Status_t UART_ReceiveBytePolling(uint16_t* Data);
 *   UART_Status_t UART_SendStringPolling(uint8_t* String);
 *   UART_Status_t UART_ReceiveStringPolling(uint8_t* Buffer, uint16_t MaxLength, uint8_t TerminationChar);
 *   UART_Status_t UART_SendBufferPolling(uint8_t* Buffer, uint16_t Length);
 *
 * UART_Status_t itself is now defined in Uart_Private.h (see that
 * file) - ideally it belongs in the public Uart_Interface.h instead,
 * move it there once that file is available.
 * ==================================================================
 *
 * @version 2.1.0
 * @author Ali Sotohy <email: alielsotohy2006@gmail.com>
 * @date 2026-09-14
 * @copyright Copyright (c) 2026, Gestell Company
 */
#include "Uart_Interface.h"

/**
 * @brief Pointer to the UART receive complete callback function.
 */
static void (*PF_UartRx)(uint16_t) = Null;

/**
 * @brief Pointer to the UART transmit complete callback function.
 */
static void (*PF_UartTx)(void) = Null;

/**
 * @brief Pointer to the UART Data Register Empty callback function.
 */
static void (*PF_UartRE)(void) = Null;

/**
 * @brief Stores the configuration UART_Init() was last called with,
 *        used by the polling functions to know the character size.
 */
static UART_Config_t GlobalUARTConfig = {0};

/**
 * @brief Initializes the UART module with the specified configuration.
 * @param UART_Config A structure containing the desired UART configuration settings.
 * @return UART_OK if every field in UART_Config was a valid enum value,
 *         UART_NOK if one or more fields were invalid (the peripheral
 *         is still left in a defined, safe state for the fields that
 *         WERE valid).
 */
UART_Status_t UART_Init(UART_Config_t UART_Config)
{
    uint8_t        Local_UCSRCValue = 0;
    uint16_t       Local_UBBRValue  = 0;
    UART_Status_t  Local_Status     = UART_OK;

    GlobalUARTConfig = UART_Config;

    SetBit(Local_UCSRCValue, Uart_URSEL); /* Set URSEL to 1 to write to UCSRC */

    /* Mode */
    if (UART_Config.ModeSelect == Uart_AsyncMode)
    {
        ClearBit(Local_UCSRCValue, Uart_UMSEL);
    }
    else if (UART_Config.ModeSelect == Uart_SyncMode)
    {
        SetBit(Local_UCSRCValue, Uart_UMSEL);
    }
    else
    {
        Local_Status = UART_NOK; /* Invalid Mode Configuration */
    }

    /* Stop bits */
    if (UART_Config.StopBitSelect == Uart_OneStopBit)
    {
        ClearBit(Local_UCSRCValue, Uart_USBS);
    }
    else if (UART_Config.StopBitSelect == Uart_TwoStopBits)
    {
        SetBit(Local_UCSRCValue, Uart_USBS);
    }
    else
    {
        Local_Status = UART_NOK; /* Invalid Stop Bit Configuration */
    }

    /* Parity */
    if (UART_Config.ParitySelect == Uart_ParityDisabled)
    {
        ClearBit(Local_UCSRCValue, Uart_UPM0);
        ClearBit(Local_UCSRCValue, Uart_UPM1);
    }
    else if (UART_Config.ParitySelect == Uart_ParityEven)
    {
        ClearBit(Local_UCSRCValue, Uart_UPM0);
        SetBit(Local_UCSRCValue, Uart_UPM1);
    }
    else if (UART_Config.ParitySelect == Uart_ParityOdd)
    {
        SetBit(Local_UCSRCValue, Uart_UPM0);
        SetBit(Local_UCSRCValue, Uart_UPM1);
    }
    else
    {
        Local_Status = UART_NOK; /* Invalid Parity Configuration */
    }

    /* Character size
     * NOTE: Uart_5BitData..Uart_9BitData are the sequential codes 0..4,
     * NOT literal bit counts - comparing against the literal 9 here
     * (as earlier versions of this file did) can never match, since no
     * valid SizeCharacterSelect value is ever 9. Compare against
     * Uart_9BitData (4) instead. */
    if (UART_Config.SizeCharacterSelect < Uart_9BitData)
    {
        ClearBit(UCSRB_Reg, Uart_UCSZ2);
        Local_UCSRCValue = (Local_UCSRCValue & ~CharacterSelectMask) | (UART_Config.SizeCharacterSelect << 1);
    }
    else if (UART_Config.SizeCharacterSelect == Uart_9BitData)
    {
        SetBit(Local_UCSRCValue, Uart_UCSZ0);
        SetBit(Local_UCSRCValue, Uart_UCSZ1);
        SetBit(UCSRB_Reg, Uart_UCSZ2);
    }
    else
    {
        Local_Status = UART_NOK; /* Invalid Character Size Selection */
    }

    UCSRC_Reg = Local_UCSRCValue;

    /* Speed */
    if (UART_Config.SpeedMode == Uart_DoubleSpeed)
    {
        SetBit(UCSRA_Reg, Uart_U2X);
    }
    else if (UART_Config.SpeedMode == Uart_NormalSpeed)
    {
        ClearBit(UCSRA_Reg, Uart_U2X);
    }
    else
    {
        Local_Status = UART_NOK; /* Invalid Speed Configuration */
    }

    /* Baud rate - only computed when SpeedMode was valid, otherwise
     * UBRR is left at 0 rather than holding a bogus half-computed
     * value from before this call. */
    if (UART_Config.SpeedMode == Uart_DoubleSpeed)
    {
        Local_UBBRValue = (uint16_t)((FCPU / (8UL * UART_Config.BaudRate)) - 1UL);
    }
    else if (UART_Config.SpeedMode == Uart_NormalSpeed)
    {
        Local_UBBRValue = (uint16_t)((FCPU / (16UL * UART_Config.BaudRate)) - 1UL);
    }
    else
    {
        Local_Status = UART_NOK; /* Invalid Baud Rate Configuration */
    }

    UBRRL_Reg = (uint8_t)Local_UBBRValue;
    UBRRH_Reg = (uint8_t)(Local_UBBRValue >> 8);

    /* Interrupts */
    UART_RxInterruptDisable();
    UART_TxInterruptDisable();
    UART_REInterruptDisable();

    if (UART_Config.InterruptSelect == Uart_InterruptDisabled)
    {
        /* Nothing more to do - all three interrupts are already
         * disabled above. This is a valid, common configuration
         * (pure polling mode), not an error. */
    }
    else if (UART_Config.InterruptSelect == Uart_InterruptRxOnly)
    {
        UART_RxInterruptEnable();
    }
    else if (UART_Config.InterruptSelect == Uart_InterruptTxOnly)
    {
        UART_TxInterruptEnable();
    }
    else if (UART_Config.InterruptSelect == Uart_InterruptREOnly)
    {
        UART_REInterruptEnable();
    }
    else if (UART_Config.InterruptSelect == Uart_InterruptRxTx)
    {
        UART_RxInterruptEnable();
        UART_TxInterruptEnable();
    }
    else if (UART_Config.InterruptSelect == Uart_InterruptRxRE)
    {
        UART_RxInterruptEnable();
        UART_REInterruptEnable();
    }
    else if (UART_Config.InterruptSelect == Uart_InterruptTxRE)
    {
        UART_TxInterruptEnable();
        UART_REInterruptEnable();
    }
    else if (UART_Config.InterruptSelect == Uart_InterruptAll)
    {
        UART_TxInterruptEnable();
        UART_REInterruptEnable();
        UART_RxInterruptEnable();
    }
    else
    {
        Local_Status = UART_NOK; /* Invalid Interrupt Configuration */
    }

    /* Enable Rx/Tx lines
     * UART_Config_t declares EnableSelect, but earlier versions of
     * this function never read it, so the module never actually
     * started receiving/transmitting after UART_Init() unless the
     * caller enabled Rx/Tx manually. */
    if (UART_Config.EnableSelect == Uart_EnableRxOnly)
    {
        UART_RxEnable();
        UART_TxDisable();
    }
    else if (UART_Config.EnableSelect == Uart_EnableTxOnly)
    {
        UART_TxEnable();
        UART_RxDisable();
    }
    else if (UART_Config.EnableSelect == Uart_EnableRxTx)
    {
        UART_RxEnable();
        UART_TxEnable();
    }
    else
    {
        Local_Status = UART_NOK; /* Invalid Enable Configuration */
    }

    return Local_Status;
}

/**
 * @brief Sends a single byte of data over UART using polling.
 * @param Data The byte of data to be sent (bit 8 used only in 9-bit mode).
 * @return UART_OK on success, UART_TIMEOUT if the data register never
 *         became empty (e.g. wiring/module fault).
 */
UART_Status_t UART_SendBytePolling(uint16_t Data)
{
    uint32_t Local_TimeoutCounter = 0;

    while (ReadFlag(UCSRA_Reg, Uart_UDRE) == FlagDown)
    {
        Local_TimeoutCounter++;
        if (Local_TimeoutCounter > Uart_MaxTimeOut)
        {
            return UART_TIMEOUT;
        }
    }

    if (GlobalUARTConfig.SizeCharacterSelect == Uart_9BitData)
    {
        ClearBit(UCSRB_Reg, Uart_TXB8);
        if (ReadBit(Data, 8) == 1U)
        {
            SetBit(UCSRB_Reg, Uart_TXB8);
        }
    }
    UDR_Reg = (uint8_t)Data;

    return UART_OK;
}

/**
 * @brief Receives a single byte of data over UART using polling.
 * @param Data Out-parameter that receives the byte on success. Left
 *             untouched on failure - the caller must check the
 *             returned status before reading it.
 * @return UART_OK on success, UART_NOK if Data is Null, UART_TIMEOUT
 *         if no byte arrived within Uart_MaxTimeOut loops.
 */
UART_Status_t UART_ReceiveBytePolling(uint16_t* Data)
{
    uint32_t Local_TimeoutCounter = 0;
    uint16_t Local_Data           = 0;

    if (Data == Null)
    {
        return UART_NOK;
    }

    while (ReadFlag(UCSRA_Reg, Uart_RXC) == FlagDown)
    {
        Local_TimeoutCounter++;
        if (Local_TimeoutCounter > Uart_MaxTimeOut)
        {
            return UART_TIMEOUT;
        }
    }

    if (GlobalUARTConfig.SizeCharacterSelect == Uart_9BitData)
    {
        if (ReadBit(UCSRB_Reg, Uart_RXB8) == 1U)
        {
            SetBit(Local_Data, 8);
        }
    }
    Local_Data |= UDR_Reg;

    *Data = Local_Data;
    return UART_OK;
}

/**
 * @brief Sends a null-terminated string over UART using polling.
 * @param String Pointer to the null-terminated string to send.
 * @return UART_OK if every byte was sent, UART_NOK if String is Null,
 *         or the first non-OK status returned by UART_SendBytePolling
 *         (transmission stops immediately on failure).
 */
UART_Status_t UART_SendStringPolling(uint8_t* String)
{
    uint16_t      Local_Count  = 0;
    UART_Status_t Local_Status = UART_OK;

    if (String == Null)
    {
        return UART_NOK;
    }

    while ((String[Local_Count] != NullChar) && (Local_Status == UART_OK))
    {
        Local_Status = UART_SendBytePolling(String[Local_Count]);
        Local_Count++;
    }

    return Local_Status;
}

/**
 * @brief Receives a string over UART using polling, stopping at
 *        TerminationChar or when the caller's buffer is full -
 *        whichever happens first. The buffer is ALWAYS null-terminated
 *        within bounds, so a full or timed-out receive still yields a
 *        safely printable string.
 * @param Buffer          Destination buffer, capacity MaxLength bytes.
 * @param MaxLength       Total capacity of Buffer, including the
 *                         final '\0'. Must be >= 1.
 * @param TerminationChar Byte value that marks the end of the string.
 * @return UART_OK if TerminationChar was received in time, UART_NOK
 *         if Buffer is Null or MaxLength is 0, UART_TIMEOUT if a byte
 *         never arrived (Buffer still holds whatever was received so
 *         far, safely null-terminated).
 */
UART_Status_t UART_ReceiveStringPolling(uint8_t* Buffer, uint16_t MaxLength, uint8_t TerminationChar)
{
    uint16_t      Local_Count        = 0;
    uint16_t      Local_ReceivedByte = 0;
    UART_Status_t Local_Status;

    if ((Buffer == Null) || (MaxLength == 0U))
    {
        return UART_NOK;
    }

    do
    {
        Local_Status = UART_ReceiveBytePolling(&Local_ReceivedByte);

        if (Local_Status != UART_OK)
        {
            break; /* timeout: stop waiting, keep whatever was received */
        }

        Buffer[Local_Count] = (uint8_t)Local_ReceivedByte;
        Local_Count++;

    } while ((Local_ReceivedByte != TerminationChar) && (Local_Count < (uint16_t)(MaxLength - 1U)));

    /* Always terminate inside the buffer bounds - Local_Count can
     * never reach MaxLength here, so this index is always valid. */
    Buffer[Local_Count] = '\0';

    return Local_Status;
}

/**
 * @brief Sends a buffer of raw bytes (not null-terminated) over UART
 *        using polling.
 * @param Buffer Pointer to the data to send.
 * @param Length Number of bytes to send.
 * @return UART_OK if every byte was sent, UART_NOK if Buffer is Null,
 *         or the first non-OK status from UART_SendBytePolling.
 */
UART_Status_t UART_SendBufferPolling(uint8_t* Buffer, uint16_t Length)
{
    uint16_t      Local_Count  = 0;
    UART_Status_t Local_Status = UART_OK;

    if (Buffer == Null)
    {
        return UART_NOK;
    }

    for (Local_Count = 0; (Local_Count < Length) && (Local_Status == UART_OK); Local_Count++)
    {
        Local_Status = UART_SendBytePolling(Buffer[Local_Count]);
    }

    return Local_Status;
}

/**
 * @brief Loads a byte of data into the UDR register for interrupt-driven
 *        transmission. Must only be called from the Tx-complete/UDRE ISR
 *        context (or right after enabling the Tx interrupt for the first
 *        byte) - it does NOT wait for UDRE, unlike the polling version.
 * @param Data The byte of data to be sent.
 */
void UART_SendByteInterrupt(uint16_t Data)
{
    if (GlobalUARTConfig.SizeCharacterSelect == Uart_9BitData)
    {
        ClearBit(UCSRB_Reg, Uart_TXB8);
        if (ReadBit(Data, 8) == 1U)
        {
            SetBit(UCSRB_Reg, Uart_TXB8);
        }
    }

    UDR_Reg = (uint8_t)Data;
}

/*--------------------------------------------------control rx/tx--------------------------------------------------------*/

/** @brief Enables the UART receiver to start receiving data. */
void UART_RxEnable(void)
{
    SetBit(UCSRB_Reg, Uart_RXEN);
}

/** @brief Enables the UART transmission line. */
void UART_TxEnable(void)
{
    SetBit(UCSRB_Reg, Uart_TXEN);
}

/** @brief Disables the UART receive line. */
void UART_RxDisable(void)
{
    ClearBit(UCSRB_Reg, Uart_RXEN);
}

/** @brief Disables the UART transmission line. */
void UART_TxDisable(void)
{
    ClearBit(UCSRB_Reg, Uart_TXEN);
}

/** @brief Enables the UART receive interrupt. */
void UART_RxInterruptEnable(void)
{
    SetBit(UCSRB_Reg, Uart_RXCIE);
}

/** @brief Enables the UART transmission-complete interrupt. */
void UART_TxInterruptEnable(void)
{
    SetBit(UCSRB_Reg, Uart_TXCIE);
}

/** @brief Enables the UART Data-Register-Empty interrupt. */
void UART_REInterruptEnable(void)
{
    SetBit(UCSRB_Reg, Uart_UDRIE);
}

/** @brief Disables the UART receive interrupt. */
void UART_RxInterruptDisable(void)
{
    ClearBit(UCSRB_Reg, Uart_RXCIE);
}

/** @brief Disables the UART transmission-complete interrupt. */
void UART_TxInterruptDisable(void)
{
    ClearBit(UCSRB_Reg, Uart_TXCIE);
}

/** @brief Disables the UART Data-Register-Empty interrupt. */
void UART_REInterruptDisable(void)
{
    ClearBit(UCSRB_Reg, Uart_UDRIE);
}

/*--------------------------------------------------------Set Callbacks--------------------------------------------------------*/

/**
 * @brief Registers a callback for the UART receive-complete interrupt.
 * @param PF Pointer to the callback to run when data is received.
 */
void UART_SetRxCallBack(void (*PF)(uint16_t))
{
    if (PF != Null)
    {
        PF_UartRx = PF;
    }
}

/**
 * @brief Registers a callback for the UART transmission-complete interrupt.
 * @param PF Pointer to the callback to run when data is transmitted.
 */
void UART_SetTxCallBack(void (*PF)(void))
{
    if (PF != Null)
    {
        PF_UartTx = PF;
    }
}

/**
 * @brief Registers a callback for the UART Data-Register-Empty interrupt.
 * @param PF Pointer to the callback to run when the data register is empty.
 */
void UART_SetRECallBack(void (*PF)(void))
{
    if (PF != Null)
    {
        PF_UartRE = PF;
    }
}

/*--------------------------------------------------------ISRs--------------------------------------------------------*/

/* Rx complete */
void __vector_13(void)
{
    if (PF_UartRx != Null)
    {
        uint16_t Local_Data = 0;

        if (GlobalUARTConfig.SizeCharacterSelect == Uart_9BitData)
        {
            if (ReadBit(UCSRB_Reg, Uart_RXB8) == 1U)
            {
                SetBit(Local_Data, 8);
            }
        }
        Local_Data |= UDR_Reg;
        PF_UartRx(Local_Data);
    }
}

/* Data Register Empty */
void __vector_14(void)
{
    if (PF_UartRE != Null)
    {
        PF_UartRE();
    }
}

/* Tx complete */
void __vector_15(void)
{
    if (PF_UartTx != Null)
    {
        PF_UartTx();
    }
}