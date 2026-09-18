/**
 * @file DHT11_Program.c
 * @brief Implementation of the DHT11 sensor driver
 * @details This file contains the implementation of the DHT11 APIs (Initialization&Reading)
 * @version 0.1
 * @author Malak Mohammed (malak.mohammed.esmail@gmail.com) 
 * @date 17-09-2026
 * @copyright Copyright (c) 2026, Gestell Company
 */
 #include "../../Common/Definition.h"
 #include "DHT11_Config.h"
 #include "DHT11_Interface.h"
 #include "DHT11_Private.h"
 #include <util/delay.h>
 

void DHT11_Init(void)
{
    DIO_InitPin(DHT11_Group, DHT11_Pin, Input);
}


uint8_t DHT11_ReadData(uint8_t* Humidity, uint8_t* Temperature)
{
    uint8_t data[5] = {0};

    uint8_t PinState = High;

    uint8_t i = 0;
    uint8_t j = 0;

    uint16_t timeout = 0;


    /* Check input pointers */

    if(Humidity == Null || Temperature == Null)
    {
        return DHT11_Reading_Error;
    }


    /* Send start signal */

    DIO_InitPin(DHT11_Group, DHT11_Pin, Output);

    DIO_WritePin(DHT11_Group, DHT11_Pin, Low);

    _delay_ms(18);

    DIO_WritePin(DHT11_Group, DHT11_Pin, High);

    _delay_us(30);


    /* Switch pin to input */

    DIO_InitPin(DHT11_Group, DHT11_Pin, Input);


    /* Wait for sensor response: Low */

    timeout = DHT11_Timeout_Value;

    do
    {
        DIO_ReadPin(DHT11_Group, DHT11_Pin, &PinState);

        timeout--;

        if(timeout == 0)
        {
            return DHT11_Reading_Error;
        }

    } while(PinState == High);


    /* Wait for sensor response: High */

    timeout = DHT11_Timeout_Value;

    do
    {
        DIO_ReadPin(DHT11_Group, DHT11_Pin, &PinState);

        timeout--;

        if(timeout == 0)
        {
            return DHT11_Reading_Error;
        }

    } while(PinState == Low);


    /* Wait for sensor response: Low */

    timeout = DHT11_Timeout_Value;

    do
    {
        DIO_ReadPin(DHT11_Group, DHT11_Pin, &PinState);

        timeout--;

        if(timeout == 0)
        {
            return DHT11_Reading_Error;
        }

    } while(PinState == High);


    /* Read 40 bits */

    for(i = 0; i < 5; i++)
    {
        for(j = 0; j < 8; j++)
        {
            /* Waits for the beginning of the bit. The sensor keeps the line LOW first*/

            timeout = DHT11_Timeout_Value;

            do
            {
                DIO_ReadPin(DHT11_Group,DHT11_Pin,&PinState);

                timeout--;

                if(timeout == 0)
                {
                    return DHT11_Reading_Error;
                }

            } while(PinState == Low);

            _delay_us(40);

            DIO_ReadPin(DHT11_Group,DHT11_Pin, &PinState);


            if(PinState == High)
            {
                /* Bit is 1 */

                data[i] |= (uint8_t)(1 << (7- j));
            }

            else
            {
                /* Bit is 0 */

                data[i] &= (uint8_t)~(1 << (7 - j));
            }


            /*
             * Wait until the sensor releases the line LOW.
             * This is required before reading the next bit.
             */

            timeout = DHT11_Timeout_Value;

            do
            {
                DIO_ReadPin(DHT11_Group,DHT11_Pin, &PinState);

                timeout--;

                if(timeout == 0)
                {
                    return DHT11_Reading_Error;
                }

            } while(PinState == High);

        }
    }


    /* Verify checksum */

    if(data[4] == (uint8_t)(data[0]+ data[1] + data[2]+ data[3]))
    {
        *Humidity = data[0];

        *Temperature = data[2];

        return DHT11_Reading_Success;
    }

    else
    {
        return DHT11_Reading_Error;
    }

}