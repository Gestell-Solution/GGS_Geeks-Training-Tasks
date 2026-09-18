/**
 * @file main.c
 * @brief Main application file for testing DHT11 Sensor 
 * @details This file is to test the initialization and reading the data with DHT11 using LCD
 * @version 0.1
 * @author Malak Mohammed (malak.mohammed.esmail@gmail.com) 
 * @date 18-09-2026
 * @copyright Copyright (c) 2026, Gestell Company
 */

#include "Common/Definition.h"
#include <util/delay.h>
#include "HAL/DHT11/DHT11_Interface.h"
#include "MCAL/DIO/DIO_Interface.h" 
#include "HAL/LCD/LCD_Interface.h" /
#include "Common/Bitmath.h"
#include "MCAL/Atmega32regmap.h" 


void main()
{
    uint8_t humidity = 0;
    uint8_t temperature = 0;
    uint8_t read_status = 0;

    /* Initializing both drivers */
    DHT11_Init();
    LCD_Init(Lcd_8bitMode);
    _delay_ms(50);

    /* Print static labels once */
    LCD_GotoXY(0, 0);
    LCD_WriteString((uint8_t *)"Temp: ", Lcd_8bitMode);
    
    LCD_GotoXY(1, 0);
    LCD_WriteString((uint8_t *)"Hum : ", Lcd_8bitMode);

    while (1)
    {
        read_status = DHT11_ReadData(&humidity, &temperature);

        if (read_status == DHT11_Reading_Success)
        {
            /* Displaying Temperature*/
            LCD_GotoXY(0, 6);
            LCD_WriteNumber(temperature / 10); // Tens digit 
            LCD_WriteNumber(temperature % 10); // Units digit 
            LCD_WriteData('C', Lcd_8bitMode);

            /*  Displaying Humidity */
            LCD_GotoXY(1, 6);
            LCD_WriteNumber(humidity / 10);    // Tens digit
            LCD_WriteNumber(humidity % 10);    // Units digit
            LCD_WriteData('%', Lcd_8bitMode);
        }
        else
        {
            /* Error Handling on Screen */
            LCD_GotoXY(0, 0);
            LCD_WriteString((uint8_t *)"Sensor Error", Lcd_8bitMode);
        }

        /* DHT11 requires at least 2 seconds delay between reads */
        _delay_ms(2000);
    }

}


