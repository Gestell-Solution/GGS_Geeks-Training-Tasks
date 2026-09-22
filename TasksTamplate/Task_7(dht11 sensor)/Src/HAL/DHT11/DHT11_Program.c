/**
 * @file    DHT11_Program.c
 * @brief   Implementation of the DHT11 driver.
 * @author  Yousef Mohamed
 * @date    2026-09-22
 */
#include <stdint.h>
#include <util/delay.h>

#include "DHT11_Interface.h"
#include "DHT11_Private.h"
#include "DHT11_Config.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../COMMON/Definition.h"

static DHT11_Status_t DHT11_WaitForLevel(uint8_t ExpectedLevel);
static DHT11_Status_t DHT11_ReadByte(uint8_t *ByteValue);

/**
 * @brief Initialize the DHT11 data line to idle high state.
 * @return void.
 */
void DHT11_Init(void)
{
    DIO_InitPin(DHT11_DATA_GROUP, DHT11_DATA_PIN, Output);
    DIO_WritePin(DHT11_DATA_GROUP, DHT11_DATA_PIN, High);
}

/**
 * @brief Read one complete DHT11 frame.
 * @param[out] Humidity Humidity result.
 * @param[out] Temperature Temperature result.
 * @return DHT11_Status_t Result of the read operation.
 */
DHT11_Status_t DHT11_ReadData(uint8_t *Humidity, uint8_t *Temperature)
{
    uint8_t Data[DHT11_FRAME_SIZE] = {0U};
    uint8_t ByteIndex = 0U;
    uint8_t Checksum = 0U;
    DHT11_Status_t Status = DHT11_OK;

    if ((Humidity == Null) || (Temperature == Null))
    {
        Status = DHT11_ERROR_NULL_PTR;
    }
    else
    {
        /* Start signal from the MCU. */
        DIO_InitPin(DHT11_DATA_GROUP, DHT11_DATA_PIN, Output);
        DIO_WritePin(DHT11_DATA_GROUP, DHT11_DATA_PIN, Low);
        _delay_ms(DHT11_START_LOW_MS);
        DIO_WritePin(DHT11_DATA_GROUP, DHT11_DATA_PIN, High);
        _delay_us(DHT11_START_RELEASE_US);
        DIO_InitPin(DHT11_DATA_GROUP, DHT11_DATA_PIN, Input);

        /* DHT11 response signal. */
        Status = DHT11_WaitForLevel(Low);
        if (Status == DHT11_OK)
        {
            Status = DHT11_WaitForLevel(High);
        }
        if (Status == DHT11_OK)
        {
            Status = DHT11_WaitForLevel(Low);
        }

        /* Read 5 bytes = 40 bits. */
        while ((ByteIndex < DHT11_FRAME_SIZE) && (Status == DHT11_OK))
        {
            Status = DHT11_ReadByte(&Data[ByteIndex]);
            ByteIndex++;
        }

        if (Status == DHT11_OK)
        {
            Checksum = (uint8_t)(Data[DHT11_HUMIDITY_INT_INDEX] +
                                 Data[DHT11_HUMIDITY_DEC_INDEX] +
                                 Data[DHT11_TEMPERATURE_INT_INDEX] +
                                 Data[DHT11_TEMPERATURE_DEC_INDEX]);

            if (Checksum != Data[DHT11_CHECKSUM_INDEX])
            {
                Status = DHT11_ERROR_CHECKSUM;
            }
        }

        if (Status == DHT11_OK)
        {
            *Humidity = Data[DHT11_HUMIDITY_INT_INDEX];
            *Temperature = Data[DHT11_TEMPERATURE_INT_INDEX];
        }

        /* Return the line to its idle state after every read attempt. */
        DIO_InitPin(DHT11_DATA_GROUP, DHT11_DATA_PIN, Output);
        DIO_WritePin(DHT11_DATA_GROUP, DHT11_DATA_PIN, High);
    }

    return Status;
}

/**
 * @brief Wait until the DHT11 data line reaches the required level.
 * @param ExpectedLevel Required pin level.
 * @return DHT11_Status_t DHT11_OK or DHT11_ERROR_TIMEOUT.
 */
static DHT11_Status_t DHT11_WaitForLevel(uint8_t ExpectedLevel)
{
    uint8_t PinLevel = Low;
    uint16_t TimeUs = 0U;
    DHT11_Status_t Status = DHT11_ERROR_TIMEOUT;

    while ((TimeUs < DHT11_WAIT_TIMEOUT_US) && (Status != DHT11_OK))
    {
        DIO_ReadPin(DHT11_DATA_GROUP, DHT11_DATA_PIN, &PinLevel);

        if (PinLevel == ExpectedLevel)
        {
            Status = DHT11_OK;
        }
        else
        {
            _delay_us(1.0);
            TimeUs++;
        }
    }

    return Status;
}

/**
 * @brief Read one byte from the DHT11 sensor.
 * @param[out] ByteValue Received byte.
 * @return DHT11_Status_t DHT11_OK or DHT11_ERROR_TIMEOUT.
 */
static DHT11_Status_t DHT11_ReadByte(uint8_t *ByteValue)
{
    uint8_t BitIndex = 0U;
    uint8_t PinLevel = Low;
    uint8_t Value = 0U;
    DHT11_Status_t Status = DHT11_OK;

    if (ByteValue == Null)
    {
        Status = DHT11_ERROR_NULL_PTR;
    }
    else
    {
        while ((BitIndex < DHT11_BITS_PER_BYTE) && (Status == DHT11_OK))
        {
            /* Each bit starts with about 50 us LOW. */
            Status = DHT11_WaitForLevel(High);

            if (Status == DHT11_OK)
            {
                _delay_us(DHT11_SAMPLE_TIME_US);
                DIO_ReadPin(DHT11_DATA_GROUP, DHT11_DATA_PIN, &PinLevel);

                Value = (uint8_t)(Value << 1U);
                if (PinLevel == High)
                {
                    Value = (uint8_t)(Value | 0x01U);
                }

                /* Wait for the HIGH pulse to end. */
                Status = DHT11_WaitForLevel(Low);
            }

            BitIndex++;
        }

        if (Status == DHT11_OK)
        {
            *ByteValue = Value;
        }
    }

    return Status;
}
