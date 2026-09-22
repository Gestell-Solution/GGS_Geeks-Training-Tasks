/**
 * @file    main.c
 * @brief   Simple test application for the DHT11 driver.
 * @author  Yousef Mohamed
 * @date    2026-09-22
 */
#include <stdint.h>
#include <util/delay.h>

#include "HAL/DHT11/DHT11_Interface.h"
#include "MCAL/DIO/DIO_Interface.h"
#include "COMMON/Definition.h"

int main(void)
{
    uint8_t Humidity = 0U;
    uint8_t Temperature = 0U;
    DHT11_Status_t Status = DHT11_ERROR_TIMEOUT;

    DHT11_Init();

    /* PC0 = successful read, PC1 = read error. */
    DIO_InitPin(Dio_GroupC, Dio_Pin0, Output);
    DIO_InitPin(Dio_GroupC, Dio_Pin1, Output);

    while (TRUE)
    {
        Status = DHT11_ReadData(&Humidity, &Temperature);

        if (Status == DHT11_OK)
        {
            DIO_WritePin(Dio_GroupC, Dio_Pin0, High);
            DIO_WritePin(Dio_GroupC, Dio_Pin1, Low);
        }
        else
        {
            DIO_WritePin(Dio_GroupC, Dio_Pin0, Low);
            DIO_WritePin(Dio_GroupC, Dio_Pin1, High);
        }

        /* DHT11 should not be read more than once per second. */
        _delay_ms(2000.0);
    }
}
