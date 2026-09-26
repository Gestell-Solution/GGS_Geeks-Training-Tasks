/**
 * @file Uart_Program.c
 * @brief ATmega32 UART driver implementation.
 * @version 1.1.0
 * @author Yousef Mohamed <email: yousefmohammed867@gmail.com>
 * @date 2026-09-24
 * @copyright Copyright (c) 2026, Gestell Company
 *
 * @details Fixes applied to the originally-delivered file (see project
 *          review notes for the full list):
 *            - All register accesses now use the exact symbols defined in
 *              Atmega32regmap.h (UCSRA_Reg, UCSRB_Reg, UCSRC_Reg, UDR_Reg,
 *              UBRRH_Reg, UBRRL_Reg) instead of undeclared bare names
 *              (UCSRA, UCSRB, ...), which would not compile at all.
 *            - UART_ReceiveBytePolling() now returns the assembled 9-bit
 *              value instead of discarding it and returning raw UDR_Reg.
 *            - 9-bit character size was compared against the literal `9`
 *              instead of the symbolic Uart_9BitSize (whose real value is
 *              7), so 9-bit handling was silently dead code. Fixed.
 *            - UART_ReceiveStringPolling_Timeout() was implemented under
 *              the name UART_ReceiveBytePolling_Timeout(), which did not
 *              match its own header declaration -> guaranteed linker error.
 *              Split into two correctly-named functions: a byte-level and
 *              a line-level bounded-timeout receive.
 *            - The timeout unit was `Timeout * 100` loop iterations of
 *              _delay_ms(1), i.e. passing Timeout=50 actually waited 5000ms.
 *              Timeout_ms is now taken at face value, in milliseconds.
 *            - RX_Buffer/RX_front/RX_rear are written by an ISR and read by
 *              mainline code, but were neither `volatile` nor `static`.
 *              Both are fixed (correctness + MISRA Rule 8.9).
 */
#include "Uart_Interface.h"
#include <util/delay.h>

static void (*PF_UartRX)(uint16_t) = Null;
static void (*PF_UartTX)(void)     = Null;
static void (*PF_UartRE)(void)     = Null;
static Uart_Config_t GlobalUart_Config = {0};

static volatile uint16_t RX_Buffer[UART_RX_BUFFER_SIZE] = {0};
static volatile uint8_t  RX_front = 0U;
static volatile uint8_t  RX_rear  = 0U;

/**
 * @brief Reads UDR_Reg (and, for 9-bit frames, the RXB8 bit in UCSRB_Reg)
 *        and assembles the full received value. Shared by every receive
 *        API so the 9-bit handling logic exists in exactly one place.
 * @note  Caller must have already confirmed RXC is set (a byte is ready)
 *        before calling this - it performs no waiting of its own.
 */
static uint16_t UART_ReadDataRegister(void)
{
    uint16_t LocalData = 0U;

    if (GlobalUart_Config.SizeCharacterSelect == Uart_9BitSize)
    {
        if (ReadBit(UCSRB_Reg, Uart_RXB8) == 1U)
        {
            LocalData = (uint16_t)(1U << 8U);
        }
    }
    else
    {
        /* 5..8-bit frames: nothing to pre-load, UDR_Reg alone is enough. */
    }

    LocalData |= (uint16_t)UDR_Reg;

    return LocalData;
}

/* ============================== Initialization API ============================== */
void UART_Init(Uart_Config_t Uart_Config)
{
    uint8_t  Local_UCSRCValue = 0U;
    uint16_t Local_UBRRValue  = 0U;

    GlobalUart_Config = Uart_Config;

    /* UCSRC and UBRRH share the same I/O address; URSEL=1 selects UCSRC. */
    SetBit(Local_UCSRCValue, Uart_URSEL);

    /* 1- Mode Select */
    if (Uart_Config.ModeSelect == Uart_AsynchronousMode)
    {
        ClearBit(Local_UCSRCValue, Uart_UMSEL);
    }
    else if (Uart_Config.ModeSelect == Uart_SynchronousMode)
    {
        SetBit(Local_UCSRCValue, Uart_UMSEL);
    }
    else
    {
        /* Invalid selection - leave the bit at its URSEL-only default. */
    }

    /* 2- Parity */
    if (Uart_Config.ParitySelect == Uart_ParityEven)
    {
        SetBit(Local_UCSRCValue, Uart_UPM1);
        ClearBit(Local_UCSRCValue, Uart_UPM0);
    }
    else if (Uart_Config.ParitySelect == Uart_ParityOdd)
    {
        SetBit(Local_UCSRCValue, Uart_UPM0);
        SetBit(Local_UCSRCValue, Uart_UPM1);
    }
    else /* Uart_ParityDisabled (or invalid) */
    {
        ClearBit(Local_UCSRCValue, Uart_UPM0);
        ClearBit(Local_UCSRCValue, Uart_UPM1);
    }

    /* 3- Stop Bit */
    if (Uart_Config.StopBitSelect == Uart_1StopBit)
    {
        ClearBit(Local_UCSRCValue, Uart_USBS);
    }
    else if (Uart_Config.StopBitSelect == Uart_2StopBit)
    {
        SetBit(Local_UCSRCValue, Uart_USBS);
    }
    else
    {
        /* Invalid selection - leave the bit cleared (1 stop bit). */
    }

    /* 4- Character Size */
    if (Uart_Config.SizeCharacterSelect == Uart_5BitSize)
    {
        ClearBit(Local_UCSRCValue, Uart_UCSZ2);
        ClearBit(Local_UCSRCValue, Uart_UCSZ1);
        ClearBit(Local_UCSRCValue, Uart_UCSZ0);
    }
    else if (Uart_Config.SizeCharacterSelect == Uart_6BitSize)
    {
        ClearBit(Local_UCSRCValue, Uart_UCSZ2);
        ClearBit(Local_UCSRCValue, Uart_UCSZ1);
        SetBit(Local_UCSRCValue, Uart_UCSZ0);
    }
    else if (Uart_Config.SizeCharacterSelect == Uart_7BitSize)
    {
        ClearBit(Local_UCSRCValue, Uart_UCSZ2);
        SetBit(Local_UCSRCValue, Uart_UCSZ1);
        ClearBit(Local_UCSRCValue, Uart_UCSZ0);
    }
    else if (Uart_Config.SizeCharacterSelect == Uart_8BitSize)
    {
        ClearBit(Local_UCSRCValue, Uart_UCSZ2);
        SetBit(Local_UCSRCValue, Uart_UCSZ1);
        SetBit(Local_UCSRCValue, Uart_UCSZ0);
    }
    else if (Uart_Config.SizeCharacterSelect == Uart_9BitSize)
    {
        SetBit(Local_UCSRCValue, Uart_UCSZ2);
        SetBit(Local_UCSRCValue, Uart_UCSZ1);
        SetBit(Local_UCSRCValue, Uart_UCSZ0);
    }
    else
    {
        /* Invalid selection - leave the bits at their 5-bit default. */
    }

    UCSRC_Reg = Local_UCSRCValue;

    /* 5- Speed Mode */
    if (Uart_Config.SpeedMode == Uart_NormalSpeed)
    {
        ClearBit(UCSRA_Reg, Uart_U2X);
    }
    else if (Uart_Config.SpeedMode == Uart_DoubleSpeed)
    {
        SetBit(UCSRA_Reg, Uart_U2X);
    }
    else
    {
        /* Invalid selection - leave U2X untouched. */
    }

    /* 6- Baud Rate (ATmega32 datasheet formulas, Normal vs Double speed) */
    if (Uart_Config.SpeedMode == Uart_DoubleSpeed)
    {
        Local_UBRRValue = (uint16_t)((F_CPU / (8UL * Uart_Config.BaudRate)) - 1UL);
    }
    else
    {
        Local_UBRRValue = (uint16_t)((F_CPU / (16UL * Uart_Config.BaudRate)) - 1UL);
    }

    UBRRL_Reg = (uint8_t)(Local_UBRRValue);
    UBRRH_Reg = (uint8_t)(Local_UBRRValue >> 8U);

    /* 7- Interrupts: start clean, then enable only what was requested. */
    UART_DisableRXInterrupt();
    UART_DisableTXInterrupt();
    UART_DisableREInterrupt();

    if (Uart_Config.InterruptSelect == Uart_InterruptRxOnly)
    {
        UART_EnableRXInterrupt();
    }
    else if (Uart_Config.InterruptSelect == Uart_InterruptTxOnly)
    {
        UART_EnableTXInterrupt();
    }
    else if (Uart_Config.InterruptSelect == Uart_InterruptUdreOnly)
    {
        UART_EnableREInterrupt();
    }
    else if (Uart_Config.InterruptSelect == Uart_InterruptRxTx)
    {
        UART_EnableRXInterrupt();
        UART_EnableTXInterrupt();
    }
    else if (Uart_Config.InterruptSelect == Uart_InterruptRxUdre)
    {
        UART_EnableRXInterrupt();
        UART_EnableREInterrupt();
    }
    else if (Uart_Config.InterruptSelect == Uart_InterruptTxUdre)
    {
        UART_EnableTXInterrupt();
        UART_EnableREInterrupt();
    }
    else if (Uart_Config.InterruptSelect == Uart_InterruptAll)
    {
        UART_EnableTXInterrupt();
        UART_EnableRXInterrupt();
        UART_EnableREInterrupt();
    }
    else
    {
        /* Uart_InterruptDisabled (or invalid) - already cleared above. */
    }

    /* 8- RX/TX Enable */
    if (Uart_Config.EnableSelect == Uart_EnableRxOnly)
    {
        UART_EnableRX();
        UART_DisableTX();
    }
    else if (Uart_Config.EnableSelect == Uart_EnableTxOnly)
    {
        UART_EnableTX();
        UART_DisableRX();
    }
    else if (Uart_Config.EnableSelect == Uart_EnableRxAndTx)
    {
        UART_EnableRX();
        UART_EnableTX();
    }
    else
    {
        /* Invalid selection - leave RX/TX untouched. */
    }
}

/* ============================ Polling (Blocking) API ============================ */
void UART_SendBytePolling(uint16_t Data)
{
    /* 1- Wait until the transmit data register is empty. */
    while (ReadFlag(UCSRA_Reg, Uart_UDRE) == FlagDown)
    {
        /* Busy-wait for UDRE. */
    }

    /* 2- For 9-bit frames, TXB8 must be written before UDR_Reg. */
    if (GlobalUart_Config.SizeCharacterSelect == Uart_9BitSize)
    {
        ClearBit(UCSRB_Reg, Uart_TXB8);
        if (((Data >> 8U) & 0x01U) == 1U)
        {
            SetBit(UCSRB_Reg, Uart_TXB8);
        }
    }
    else
    {
        /* 5..8-bit frames: nothing extra to configure. */
    }

    /* 3- Writing UDR_Reg starts the actual transmission. */
    UDR_Reg = (uint8_t)Data;
}

uint16_t UART_ReceiveBytePolling(void)
{
    /* Wait until a full byte/frame has been received. */
    while (ReadFlag(UCSRA_Reg, Uart_RXC) == FlagDown)
    {
        /* Busy-wait for RXC. */
    }

    return UART_ReadDataRegister();
}

void UART_SendStringPolling(const uint8_t * String)
{
    uint8_t LocalCount = 0U;

    if (String != Null)
    {
        while (String[LocalCount] != (uint8_t)'\0')
        {
            UART_SendBytePolling(String[LocalCount]);
            LocalCount++;
        }
    }
    else
    {
        /* Null pointer guard - nothing to send. */
    }
}

void UART_ReceiveStringPolling(uint8_t * Buffer, uint8_t Terminator)
{
    uint8_t LocalCount = 0U;

    if (Buffer != Null)
    {
        Buffer[LocalCount] = (uint8_t)UART_ReceiveBytePolling();
        while (Buffer[LocalCount] != Terminator)
        {
            LocalCount++;
            Buffer[LocalCount] = (uint8_t)UART_ReceiveBytePolling();
        }
        Buffer[LocalCount] = (uint8_t)'\0';
    }
    else
    {
        /* Null pointer guard - nothing to receive into. */
    }
}

void UART_SendBufferPolling(const uint8_t * Buffer, uint16_t Length)
{
    uint16_t LocalCount = 0U;

    if (Buffer != Null)
    {
        for (LocalCount = 0U; LocalCount < Length; LocalCount++)
        {
            UART_SendBytePolling(Buffer[LocalCount]);
        }
    }
    else
    {
        /* Null pointer guard - nothing to send. */
    }
}


uint8_t UART_ReceiveBytePolling_Timeout(uint16_t * Data, uint32_t Timeout_ms)
{
    uint32_t ElapsedTime_ms = 0U;
    uint8_t  Local_Status;

    if (Data != Null)
    {
        while ((ReadFlag(UCSRA_Reg, Uart_RXC) == FlagDown) && (ElapsedTime_ms < Timeout_ms))
        {
            _delay_ms(1);
            ElapsedTime_ms++;
        }

        if (ElapsedTime_ms < Timeout_ms)
        {
            *Data = UART_ReadDataRegister();
            Local_Status = UART_OK;
        }
        else
        {
            Local_Status = UART_TIMEOUT;
        }
    }
    else
    {
        Local_Status = UART_TIMEOUT;
    }

    return Local_Status;
}

uint8_t UART_ReceiveStringPolling_Timeout(uint8_t * Data, uint32_t Timeout_ms)
{
    uint8_t  Counter        = 0U;
    uint32_t ElapsedTime_ms = 0U;
    uint16_t ReceivedByte   = 0U;
    uint8_t  Local_Status   = UART_TIMEOUT;

    if (Data != Null)
    {
        while (Counter < (uint8_t)(UART_RX_BUFFER_SIZE - 1U))
        {
            ElapsedTime_ms = 0U;

            while ((ReadFlag(UCSRA_Reg, Uart_RXC) == FlagDown) && (ElapsedTime_ms < Timeout_ms))
            {
                _delay_ms(1);
                ElapsedTime_ms++;
            }

            if (ElapsedTime_ms >= Timeout_ms)
            {
                /* Nothing new arrived before the deadline. */
                if (Counter > 0U)
                {
                    /* Partial data already collected -> return it. */
                    Data[Counter] = (uint8_t)'\0';
                    Local_Status  = UART_OK;
                }
                else
                {
                    Local_Status = UART_TIMEOUT;
                }
                break;
            }
            else
            {
                /* A byte is ready - fall through and consume it. */
            }

            ReceivedByte = UDR_Reg;
            Data[Counter] = (uint8_t)ReceivedByte;

            if ((ReceivedByte == (uint16_t)'\r') || (ReceivedByte == (uint16_t)'\n'))
            {
                Data[Counter] = (uint8_t)'\0';
                Local_Status  = UART_OK;
                break;
            }
            else
            {
                Counter++;
                Local_Status = UART_OK;
            }
        }

        if (Counter >= (uint8_t)(UART_RX_BUFFER_SIZE - 1U))
        {
            Data[UART_RX_BUFFER_SIZE - 1U] = (uint8_t)'\0';
            Local_Status = UART_OK;
        }
        else
        {
            /* Loop already exited via one of the `break`s above. */
        }
    }
    else
    {
        Local_Status = UART_TIMEOUT;
    }

    return Local_Status;
}

/* ==================== Interrupt-Driven Reception (Ring Buffer) ==================== */
uint8_t UART_ReceiveByteInterrupt(uint16_t * Data)
{
    uint8_t Local_Status = 0U;

    if (Data != Null)
    {
        if (RX_front == RX_rear)
        {
            /* Ring buffer empty - nothing to read. */
            Local_Status = 0U;
        }
        else
        {
            *Data = RX_Buffer[RX_rear];

            RX_rear++;
            if (RX_rear >= UART_RX_BUFFER_SIZE)
            {
                RX_rear = 0U;
            }
            else
            {
                /* No wrap needed. */
            }

            Local_Status = 1U;
        }
    }
    else
    {
        Local_Status = 0U;
    }

    return Local_Status;
}

/* ================================ Driver Control API ================================ */
void UART_EnableRX(void)
{
    SetBit(UCSRB_Reg, Uart_RXEN);
}
void UART_EnableTX(void)
{
    SetBit(UCSRB_Reg, Uart_TXEN);
}
void UART_DisableRX(void)
{
    ClearBit(UCSRB_Reg, Uart_RXEN);
}
void UART_DisableTX(void)
{
    ClearBit(UCSRB_Reg, Uart_TXEN);
}

/* =================================== Interrupt API =================================== */
void UART_SendByteInterrupt(uint16_t Data)
{
    UDR_Reg = (uint8_t)Data;
}
void UART_EnableRXInterrupt(void)
{
    SetBit(UCSRB_Reg, Uart_RXCIE);
}
void UART_EnableTXInterrupt(void)
{
    SetBit(UCSRB_Reg, Uart_TXCIE);
}
void UART_EnableREInterrupt(void)
{
    SetBit(UCSRB_Reg, Uart_UDRIE);
}
void UART_DisableRXInterrupt(void)
{
    ClearBit(UCSRB_Reg, Uart_RXCIE);
}
void UART_DisableTXInterrupt(void)
{
    ClearBit(UCSRB_Reg, Uart_TXCIE);
}
void UART_DisableREInterrupt(void)
{
    ClearBit(UCSRB_Reg, Uart_UDRIE);
}

void UART_SetRXCallback(void (*PF)(uint16_t))
{
    if (PF != Null)
    {
        PF_UartRX = PF;
    }
    else
    {
        /* Ignore a null callback registration. */
    }
}
void UART_SetTXCallback(void (*PF)(void))
{
    if (PF != Null)
    {
        PF_UartTX = PF;
    }
    else
    {
        /* Ignore a null callback registration. */
    }
}
void UART_SetRECallback(void (*PF)(void))
{
    if (PF != Null)
    {
        PF_UartRE = PF;
    }
    else
    {
        /* Ignore a null callback registration. */
    }
}

/* RX Complete */
void __vector_13(void)
{
    uint16_t LocalData = UART_ReadDataRegister();

    /* Store the received value in the RX ring buffer, at RX_front. */
    RX_Buffer[RX_front] = LocalData;

    RX_front++;
    if (RX_front >= UART_RX_BUFFER_SIZE)
    {
        RX_front = 0U;
    }
    else
    {
        /* No wrap needed. */
    }

    if (PF_UartRX != Null)
    {
        PF_UartRX(LocalData);
    }
    else
    {
        /* No user callback registered. */
    }
}

/* TX Complete */
void __vector_15(void)
{
    if (PF_UartTX != Null)
    {
        PF_UartTX();
    }
    else
    {
        /* No user callback registered. */
    }
}

/* UDR Empty */
void __vector_14(void)
{
    if (PF_UartRE != Null)
    {
        PF_UartRE();
    }
    else
    {
        /* No user callback registered. */
    }
}
