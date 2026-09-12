/**
 * @file RFID_Program.c
 * @brief RFID Program driver implementation.
 * @details Contains the implementation of the module APIs and internal helper functions.
 * @version 1.0.0
 * @author Yousef
 * @date 2026-09-12
 * @copyright Copyright (c) 2026, Embedded Systems Project
 */

#include "RFID_Interface.h"


// Low level SPI access

/**
 * @fn RFID_CS_Select
 * @brief Executes the rfid cs select operation.
 * @details Performs the operation required by the module while preserving the module interface.
 * @return void Return value of the operation.
 * @retval 0 Operation completed successfully when a status code is used.
 * @retval Non-zero Module-specific error or status code when applicable.
 * @note Ensure module initialization is completed before calling dependent APIs.
 */
static void RFID_CS_Select(void)
{
    DIO_WritePin(RFID_CS_GROUP, RFID_CS_PIN, Low);
}

/**
 * @fn RFID_CS_Release
 * @brief Executes the rfid cs release operation.
 * @details Performs the operation required by the module while preserving the module interface.
 * @return void Return value of the operation.
 * @retval 0 Operation completed successfully when a status code is used.
 * @retval Non-zero Module-specific error or status code when applicable.
 * @note Ensure module initialization is completed before calling dependent APIs.
 */
static void RFID_CS_Release(void)
{
    DIO_WritePin(RFID_CS_GROUP, RFID_CS_PIN, High);
}

/**
 * @fn RFID_WriteRegister
 * @brief Writes a value to an MFRC522 register.
 * @details Performs the operation required by the module while preserving the module interface.
 * @param Reg Register address or register identifier.
 * @param Value Value to be written or configured.
 * @return void Return value of the operation.
 * @retval 0 Operation completed successfully when a status code is used.
 * @retval Non-zero Module-specific error or status code when applicable.
 * @note Ensure module initialization is completed before calling dependent APIs.
 */
static void RFID_WriteRegister(uint8_t Reg, uint8_t Value)
{
    RFID_CS_Select();
    SPI_Transfer((Reg << 1) & 0x7E);
    SPI_Transfer(Value);
    RFID_CS_Release();
}

/**
 * @fn RFID_ReadRegister
 * @brief Reads a value from an MFRC522 register.
 * @details Performs the operation required by the module while preserving the module interface.
 * @param Reg Register address or register identifier.
 * @return uint8_t Return value of the operation.
 * @retval 0 Operation completed successfully when a status code is used.
 * @retval Non-zero Module-specific error or status code when applicable.
 * @note Ensure module initialization is completed before calling dependent APIs.
 */
static uint8_t RFID_ReadRegister(uint8_t Reg)
{
    uint8_t Value;

    RFID_CS_Select();
    SPI_Transfer(((Reg << 1) & 0x7E) | 0x80);
    Value = SPI_Transfer(0x00);
    RFID_CS_Release();

    return Value;
}

/**
 * @fn RFID_SetBitMask
 * @brief Sets selected bits in an MFRC522 register.
 * @details Performs the operation required by the module while preserving the module interface.
 * @param Reg Register address or register identifier.
 * @param Mask Input parameter.
 * @return void Return value of the operation.
 * @retval 0 Operation completed successfully when a status code is used.
 * @retval Non-zero Module-specific error or status code when applicable.
 * @note Ensure module initialization is completed before calling dependent APIs.
 */
static void RFID_SetBitMask(uint8_t Reg, uint8_t Mask)
{
    uint8_t Temp = RFID_ReadRegister(Reg);
    RFID_WriteRegister(Reg, Temp | Mask);
}

/**
 * @fn RFID_ClearBitMask
 * @brief Clears selected bits in an MFRC522 register.
 * @details Performs the operation required by the module while preserving the module interface.
 * @param Reg Register address or register identifier.
 * @param Mask Input parameter.
 * @return void Return value of the operation.
 * @retval 0 Operation completed successfully when a status code is used.
 * @retval Non-zero Module-specific error or status code when applicable.
 * @note Ensure module initialization is completed before calling dependent APIs.
 */
static void RFID_ClearBitMask(uint8_t Reg, uint8_t Mask)
{
    uint8_t Temp = RFID_ReadRegister(Reg);
    RFID_WriteRegister(Reg, Temp & (~Mask));
}

/**
 * @fn RFID_AntennaOn
 * @brief Enables the MFRC522 RF antenna.
 * @details Performs the operation required by the module while preserving the module interface.
 * @return void Return value of the operation.
 * @retval 0 Operation completed successfully when a status code is used.
 * @retval Non-zero Module-specific error or status code when applicable.
 * @note Ensure module initialization is completed before calling dependent APIs.
 */
static void RFID_AntennaOn(void)
{
    uint8_t Temp = RFID_ReadRegister(RFID_REG_TX_CONTROL);

    if (!(Temp & 0x03))
    {
        RFID_SetBitMask(RFID_REG_TX_CONTROL, 0x03);
    }
}

//  Card communication (anti-collision protocol)


/**
 * @fn RFID_ToCard
 * @brief Exchanges a command and data frame with an RFID card.
 * @details Performs the operation required by the module while preserving the module interface.
 * @param Command Input parameter.
 * @param SendData Data value or data buffer used by the operation.
 * @param SendLen Length of the data in bytes or bits, as applicable.
 * @param BackData Data value or data buffer used by the operation.
 * @param BackLenBits Length of the data in bytes or bits, as applicable.
 * @return uint8_t Return value of the operation.
 * @retval 0 Operation completed successfully when a status code is used.
 * @retval Non-zero Module-specific error or status code when applicable.
 * @note Ensure module initialization is completed before calling dependent APIs.
 */
static uint8_t RFID_ToCard(uint8_t Command, uint8_t *SendData, uint8_t SendLen,
                            uint8_t *BackData, uint16_t *BackLenBits)
{
    uint8_t  Status  = RFID_ERR;
    uint8_t  IrqEn   = 0x00;
    uint8_t  WaitIRq = 0x00;
    uint8_t  LastBits;
    uint8_t  N;
    uint16_t i;

    if (Command == PCD_AUTHENT)
    {
        IrqEn   = 0x12;
        WaitIRq = 0x10;
    }
    else if (Command == PCD_TRANSCEIVE)
    {
        IrqEn   = 0x77;
        WaitIRq = 0x30;
    }

    RFID_WriteRegister(RFID_REG_COM_IRQ_EN, IrqEn | 0x80);
    RFID_ClearBitMask(RFID_REG_COM_IRQ, 0x80);
    RFID_SetBitMask(RFID_REG_FIFO_LEVEL, 0x80);     // flush FIFO
    RFID_WriteRegister(RFID_REG_COMMAND, PCD_IDLE);

    // push the outgoing bytes into the FIFO
    for (i = 0; i < SendLen; i++)
    {
        RFID_WriteRegister(RFID_REG_FIFO_DATA, SendData[i]);
    }

    RFID_WriteRegister(RFID_REG_COMMAND, Command);
    if (Command == PCD_TRANSCEIVE)
    {
        RFID_SetBitMask(RFID_REG_BIT_FRAMING, 0x80);   // StartSend = 1
    }

    // wait for the command to finish or time out
    i = 2000;
    do
    {
        N = RFID_ReadRegister(RFID_REG_COM_IRQ);
        i--;
    } while ((i != 0) && !(N & 0x01) && !(N & WaitIRq));

    RFID_ClearBitMask(RFID_REG_BIT_FRAMING, 0x80);

    if (i == 0)
    {
        return RFID_ERR;   // no answer from the card
    }

    if (RFID_ReadRegister(RFID_REG_ERROR) & 0x1B)   // BufferOvfl | CollErr | CRCErr | ParityErr
    {
        return RFID_ERR;
    }

    Status = RFID_OK;

    if (N & IrqEn & 0x01)
    {
        Status = RFID_NOTAGERR;
    }

    if (Command == PCD_TRANSCEIVE)
    {
        N = RFID_ReadRegister(RFID_REG_FIFO_LEVEL);
        LastBits = RFID_ReadRegister(RFID_REG_CONTROL) & 0x07;

        *BackLenBits = LastBits ? ((N - 1) * 8 + LastBits) : (N * 8);

        if (N == 0) { N = 1;  }
        if (N > 16) { N = 16; }

        for (i = 0; i < N; i++)
        {
            BackData[i] = RFID_ReadRegister(RFID_REG_FIFO_DATA);
        }
    }

    return Status;
}

/**
 * @fn RFID_Request
 * @brief Requests an RFID card in the field.
 * @details Performs the operation required by the module while preserving the module interface.
 * @param ReqMode Operating mode selection.
 * @param TagType Input parameter.
 * @return uint8_t Return value of the operation.
 * @retval 0 Operation completed successfully when a status code is used.
 * @retval Non-zero Module-specific error or status code when applicable.
 * @note Ensure module initialization is completed before calling dependent APIs.
 */
static uint8_t RFID_Request(uint8_t ReqMode, uint8_t *TagType)
{
    uint8_t  Status;
    uint16_t BackBits;

    RFID_WriteRegister(RFID_REG_BIT_FRAMING, 0x07);   // send only 7 bits of the last byte

    TagType[0] = ReqMode;
    Status = RFID_ToCard(PCD_TRANSCEIVE, TagType, 1, TagType, &BackBits);

    if ((Status != RFID_OK) || (BackBits != 0x10))
    {
        Status = RFID_ERR;
    }

    return Status;
}

/**
 * @fn RFID_Anticoll
 * @brief Performs RFID anti-collision and reads the card UID.
 * @details Performs the operation required by the module while preserving the module interface.
 * @param SerNum Input parameter.
 * @return uint8_t Return value of the operation.
 * @retval 0 Operation completed successfully when a status code is used.
 * @retval Non-zero Module-specific error or status code when applicable.
 * @note Ensure module initialization is completed before calling dependent APIs.
 */
static uint8_t RFID_Anticoll(uint8_t *SerNum)
{
    uint8_t  Status;
    uint8_t  Check = 0;
    uint16_t Len;
    uint8_t  i;

    RFID_WriteRegister(RFID_REG_BIT_FRAMING, 0x00);

    SerNum[0] = PICC_ANTICOLL;
    SerNum[1] = 0x20;

    Status = RFID_ToCard(PCD_TRANSCEIVE, SerNum, 2, SerNum, &Len);

    if (Status == RFID_OK)
    {
        // byte 5 of the reply is a checksum of the first 4 UID bytes
        for (i = 0; i < 4; i++)
        {
            Check ^= SerNum[i];
        }

        if (Check != SerNum[4])
        {
            Status = RFID_ERR;
        }
    }

    return Status;
}

/**
 * @fn RFID_CalculateCRC
 * @brief Requests CRC calculation from the MFRC522.
 * @details Performs the operation required by the module while preserving the module interface.
 * @param Data Data value or data buffer used by the operation.
 * @param Len Length of the data in bytes or bits, as applicable.
 * @param Result Input parameter.
 * @return void Return value of the operation.
 * @retval 0 Operation completed successfully when a status code is used.
 * @retval Non-zero Module-specific error or status code when applicable.
 * @note Ensure module initialization is completed before calling dependent APIs.
 */
static void RFID_CalculateCRC(uint8_t *Data, uint8_t Len, uint8_t *Result)
{
    uint8_t  N;
    uint16_t i;

    RFID_ClearBitMask(RFID_REG_DIV_IRQ, 0x04);
    RFID_SetBitMask(RFID_REG_FIFO_LEVEL, 0x80);

    for (i = 0; i < Len; i++)
    {
        RFID_WriteRegister(RFID_REG_FIFO_DATA, Data[i]);
    }

    RFID_WriteRegister(RFID_REG_COMMAND, PCD_CALCCRC);

    i = 0xFF;
    do
    {
        N = RFID_ReadRegister(RFID_REG_DIV_IRQ);
        i--;
    } while ((i != 0) && !(N & 0x04));

    Result[0] = RFID_ReadRegister(RFID_REG_CRC_RESULT_LSB);
    Result[1] = RFID_ReadRegister(RFID_REG_CRC_RESULT_MSB);
}

// Public API


/**
 * @fn RFID_Init
 * @brief Initializes the MFRC522 RFID reader.
 * @details Performs the operation required by the module while preserving the module interface.
 * @return void
 * @note Ensure module initialization is completed before calling dependent APIs.
 */
void RFID_Init(void)
{
    DIO_InitPin(RFID_RST_GROUP, RFID_RST_PIN, Output);
    DIO_WritePin(RFID_RST_GROUP, RFID_RST_PIN, High);   // keep the module out of reset

    DIO_InitPin(RFID_CS_GROUP, RFID_CS_PIN, Output);
    DIO_WritePin(RFID_CS_GROUP, RFID_CS_PIN, High);     // release the bus for now

    RFID_WriteRegister(RFID_REG_COMMAND, PCD_RESETPHASE);

    // timer used internally by the module for its own ~25 ms timeout
    RFID_WriteRegister(RFID_REG_T_MODE, 0x8D);
    RFID_WriteRegister(RFID_REG_T_PRESCALER, 0x3E);
    RFID_WriteRegister(RFID_REG_T_RELOAD_L, 30);
    RFID_WriteRegister(RFID_REG_T_RELOAD_H, 0);

    RFID_WriteRegister(RFID_REG_TX_ASK, 0x40);    // force 100% ASK modulation
    RFID_WriteRegister(RFID_REG_MODE, 0x3D);      // CRC preset value 0x6363

    RFID_AntennaOn();
}

/**
 * @fn RFID_CheckCard
 * @brief Checks for an RFID card and retrieves its UID.
 * @details Requests a card and performs anti-collision when a card is detected.
 * @param CardID Input parameter.
 * @return uint8_t Return value of the operation.
 * @retval 0 Operation completed successfully when a status code is used.
 * @retval Non-zero Module-specific error or status code when applicable.
 * @note Ensure module initialization is completed before calling dependent APIs.
 */
uint8_t RFID_CheckCard(uint8_t *CardID)
{
    uint8_t Status;
    uint8_t TagType[2];

    /* WUPA lets the same card be detected again after RFID_Halt(). */
    Status = RFID_Request(PICC_WUPA, TagType);

    if (Status == RFID_OK)
    {
        Status = RFID_Anticoll(CardID);
    }

    return Status;
}

/**
 * @fn RFID_Halt
 * @brief Requests the selected RFID card to enter the HALT state.
 * @details Builds the HALT command, calculates its CRC, and transmits it to the card.
 * @return void
 * @note Ensure module initialization is completed before calling dependent APIs.
 */
void RFID_Halt(void)
{
    uint8_t  Buffer[4];
    uint16_t Len;

    Buffer[0] = PICC_HALT;
    Buffer[1] = 0x00;
    RFID_CalculateCRC(Buffer, 2, &Buffer[2]);

    RFID_ToCard(PCD_TRANSCEIVE, Buffer, 4, Buffer, &Len);
}
