/**
 * @file ADXL342_Program.c
 * @brief ADXL342 accelerometer driver implementation.
 * @details Implements the ADXL342 driver declared in ADXL342_Interface.h on
 *          top of the SPI and DIO drivers. The public API is documented in
 *          the header.
 * @version 1.0.0
 * @author Yousef Mohamed
 * @date 2026-09-24
 * @copyright Copyright (c) 2026, Gestell Company. All rights reserved.
 */

#include "ADXL342_Interface.h"
#include "ADXL342_Config.h"
#include "ADXL342_Private.h"


static void ADXL342_CS_Low(void)
{
    DIO_WritePin(ADXL342_CS_GROUP, ADXL342_CS_PIN, Low);
}


static void ADXL342_CS_High(void)
{
    DIO_WritePin(ADXL342_CS_GROUP, ADXL342_CS_PIN, High);
}


static void ADXL342_ReadBurst(uint8_t StartAddress, uint8_t *Buffer, uint8_t Length)
{
    uint8_t command;
    uint8_t index;

    if ((Buffer != Null) && (Length > 0U))
    {
        /* R/W = 1, MB = 1, address = bits 5:0. */
        command = (uint8_t)((StartAddress & ADXL342_ADDRESS_MASK) |
                            ADXL342_READ_COMMAND | ADXL342_MULTI_BYTE);

        ADXL342_CS_Low();

        (void)SPI_Transfer(command);

        for (index = 0U; index < Length; index++)
        {
            /* The dummy byte only generates the SPI clock. */
            Buffer[index] = SPI_Transfer(ADXL342_DUMMY_BYTE);
        }

        ADXL342_CS_High();
    }
}

static int16_t ADXL342_ToSigned16(uint8_t LowByte, uint8_t HighByte)
{
    uint16_t raw;
    int32_t  value;

    raw = (uint16_t)(((uint16_t)HighByte << 8U) | (uint16_t)LowByte);

    if (raw >= ADXL342_SIGN_LIMIT)
    {
        value = (int32_t)raw - ADXL342_WORD_RANGE;
    }
    else
    {
        value = (int32_t)raw;
    }

    return (int16_t)value;
}


static int16_t ADXL342_RawToMilliG(int16_t Raw)
{
    return (int16_t)(((int32_t)Raw * ADXL342_SCALE_NUMERATOR) / ADXL342_SCALE_DENOMINATOR);
}

uint8_t ADXL342_Init(void)
{
    SPI_Config_t spiConfig;
    uint8_t      status = ADXL342_ERROR;

    /* Set CS high before making the pin an output: no low glitch on CS. */
    ADXL342_CS_High();
    DIO_InitPin(ADXL342_CS_GROUP, ADXL342_CS_PIN, Output);

    /* SPI mode 3 (CPOL = 1, CPHA = 1), MSB first, as required by the sensor. */
    spiConfig.ModeSelect    = Master_mode;
    spiConfig.DataOrder     = MSB_First;
    spiConfig.ClockPolarity = SPI_CPOL_HIGH;
    spiConfig.ClockPhase    = SPI_SAMPLE_TRAILING;
    spiConfig.ClockRate     = ADXL342_SPI_CLOCK_RATE;
    SPI_Init(spiConfig);

    if (ADXL342_ReadDeviceID() == ADXL342_EXPECTED_DEVICE_ID)
    {
        ADXL342_WriteRegister(ADXL342_DATA_FORMAT_REG, ADXL342_DATA_FORMAT_VALUE);
        ADXL342_WriteRegister(ADXL342_BW_RATE_REG, ADXL342_DATA_RATE);
        ADXL342_StartMeasurement();

        status = ADXL342_OK;
    }

    return status;
}

void ADXL342_WriteRegister(uint8_t RegisterAddress, uint8_t Data)
{
    /* R/W = 0, MB = 0, address = bits 5:0. */
    uint8_t command = (uint8_t)(RegisterAddress & ADXL342_ADDRESS_MASK);

    ADXL342_CS_Low();

    (void)SPI_Transfer(command);
    (void)SPI_Transfer(Data);

    ADXL342_CS_High();
}

uint8_t ADXL342_ReadRegister(uint8_t RegisterAddress)
{
    /* R/W = 1, MB = 0, address = bits 5:0. */
    uint8_t command = (uint8_t)((RegisterAddress & ADXL342_ADDRESS_MASK) | ADXL342_READ_COMMAND);
    uint8_t data;

    ADXL342_CS_Low();

    (void)SPI_Transfer(command);
    data = SPI_Transfer(ADXL342_DUMMY_BYTE);    /* Dummy byte generates the clock. */

    ADXL342_CS_High();

    return data;
}

uint8_t ADXL342_ReadDeviceID(void)
{
    return ADXL342_ReadRegister(ADXL342_DEVID_REG);
}

void ADXL342_StartMeasurement(void)
{
    ADXL342_WriteRegister(ADXL342_POWER_CTL_REG, ADXL342_POWER_MEASURE);
}

void ADXL342_Standby(void)
{
    ADXL342_WriteRegister(ADXL342_POWER_CTL_REG, ADXL342_POWER_STANDBY);
}

void ADXL342_ReadXYZ(int16_t *X, int16_t *Y, int16_t *Z)
{
    uint8_t data[ADXL342_DATA_LENGTH] = {0U};

    if ((X != Null) && (Y != Null) && (Z != Null))
    {
        ADXL342_ReadBurst(ADXL342_DATAX0_REG, data, ADXL342_DATA_LENGTH);

        *X = ADXL342_ToSigned16(data[0], data[1]);
        *Y = ADXL342_ToSigned16(data[2], data[3]);
        *Z = ADXL342_ToSigned16(data[4], data[5]);
    }
}

void ADXL342_ReadXYZ_mg(int16_t *X, int16_t *Y, int16_t *Z)
{
    int16_t rawX = 0;
    int16_t rawY = 0;
    int16_t rawZ = 0;

    if ((X != Null) && (Y != Null) && (Z != Null))
    {
        ADXL342_ReadXYZ(&rawX, &rawY, &rawZ);

        *X = ADXL342_RawToMilliG(rawX);
        *Y = ADXL342_RawToMilliG(rawY);
        *Z = ADXL342_RawToMilliG(rawZ);
    }
}
