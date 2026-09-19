/**
 * @file DTH_11_Program.c
 * @author Ali Sotohy (alielsotohy2006@gmail.com)
 * @brief  Implementation of the DHT11 driver (bit-banged single-wire protocol).
 * @version 2.0.0
 * @date 2026-09-18
 * @copyright Copyright Gestell (c) 2026
 */
#include "DTH_11_Interface.h"

void DTH_11_SendRequest(void)
{
    DIO_InitPin(DTH_11_PORT, DTH_11_PIN, Output);
    DIO_WritePin(DTH_11_PORT, DTH_11_PIN, Low);
    _delay_ms(DTH_11_ReqestTime);   /* >= 18ms per datasheet */
    DIO_WritePin(DTH_11_PORT, DTH_11_PIN, High);
    _delay_us(DTH_11_Receivedtime); /* 20-40us release time */
    DIO_InitPin(DTH_11_PORT, DTH_11_PIN, Input);
}

uint8_t DTH_11_ReceiveResponse(void)
{
    uint16_t Local_u16Timeout;
    uint8_t  Local_u8PinState;

    /* wait for the sensor to pull the line low */
    Local_u16Timeout = 0;
    DIO_ReadPin(DTH_11_PORT, DTH_11_PIN, &Local_u8PinState);
    while (Local_u8PinState == High)
    {
        Local_u16Timeout++;
        if (Local_u16Timeout > DTH_11_MaxTimeOut) { return 0; }
        DIO_ReadPin(DTH_11_PORT, DTH_11_PIN, &Local_u8PinState);
    }

    /* wait for it to go high */
    Local_u16Timeout = 0;
    DIO_ReadPin(DTH_11_PORT, DTH_11_PIN, &Local_u8PinState);
    while (Local_u8PinState == Low)
    {
        Local_u16Timeout++;
        if (Local_u16Timeout > DTH_11_MaxTimeOut) { return 0; }
        DIO_ReadPin(DTH_11_PORT, DTH_11_PIN, &Local_u8PinState);
    }

    /* wait for it to drop low again - sensor is now ready to send data */
    Local_u16Timeout = 0;
    DIO_ReadPin(DTH_11_PORT, DTH_11_PIN, &Local_u8PinState);
    while (Local_u8PinState == High)
    {
        Local_u16Timeout++;
        if (Local_u16Timeout > DTH_11_MaxTimeOut) { return 0; }
        DIO_ReadPin(DTH_11_PORT, DTH_11_PIN, &Local_u8PinState);
    }

    return 1;
}

uint8_t DTH_11_ReadData(uint8_t *data)
{
    uint8_t  Local_u8ByteIndex;
    uint8_t  Local_u8BitIndex;
    uint16_t Local_u16Timeout;
    uint16_t Local_u16HighCount;
    uint8_t  Local_u8Checksum;
    uint8_t  Local_u8PinState;

    for (Local_u8ByteIndex = 0; Local_u8ByteIndex < DTH_11_FrameBytes; Local_u8ByteIndex++)
    {
        data[Local_u8ByteIndex] = 0;
    }

    for (Local_u8ByteIndex = 0; Local_u8ByteIndex < DTH_11_FrameBytes; Local_u8ByteIndex++)
    {
        for (Local_u8BitIndex = 0; Local_u8BitIndex < 8U; Local_u8BitIndex++)
        {
            /* every bit starts with the same fixed ~50us low phase */
            Local_u16Timeout = 0;
            DIO_ReadPin(DTH_11_PORT, DTH_11_PIN, &Local_u8PinState);
            while (Local_u8PinState == Low)
            {
                Local_u16Timeout++;
                if (Local_u16Timeout > DTH_11_MaxTimeOut) { return 0; }
                DIO_ReadPin(DTH_11_PORT, DTH_11_PIN, &Local_u8PinState);
            }

            /* the LENGTH of the high phase that follows is the bit value */
            Local_u16HighCount = 0;
            DIO_ReadPin(DTH_11_PORT, DTH_11_PIN, &Local_u8PinState);
            while (Local_u8PinState == High)
            {
                Local_u16HighCount++;
                if (Local_u16HighCount > DTH_11_MaxTimeOut) { return 0; }
                DIO_ReadPin(DTH_11_PORT, DTH_11_PIN, &Local_u8PinState);
            }

            data[Local_u8ByteIndex] <<= 1;
            if (Local_u16HighCount > DTH_11_BitThreshold)
            {
                data[Local_u8ByteIndex] |= 1U;
            }
        }
    }

    Local_u8Checksum = (uint8_t)(data[0] + data[1] + data[2] + data[3]);
    if (Local_u8Checksum != data[4])
    {
        return 0;
    }

    return 1;
}