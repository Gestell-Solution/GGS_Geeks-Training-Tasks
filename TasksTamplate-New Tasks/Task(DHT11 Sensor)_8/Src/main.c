/**
 * @file main.c
 * @brief This file contains the main application for DHT11 Sensor.
 * @author Developer: Abdulrahman Ali 
 * @author Reviewer : Eng/Hesham Ahmed
 * @date 9/18/2026
 * @copyright Copyright (c) 2026 , Gestell Company. All rights reserved.
 * @version 1.0.0
*/

#include <stdint.h>
#include<util/delay.h>
#include "MCAL/DIO/DIO_Interface.h"
#include "HAL/LCD/LCD_Interface.h"
#include "HAL/DHT11/dht11_Interface.h"


/** 
 * @brief Main application function.
 *
 * @return int.
*/
int main(void)
{
uint8_t Temperature=0;
uint8_t Humidity=0;
uint8_t Status=0;

/**
* Initialize LEDs
*/
DIO_InitPin(Dio_GroupC, Dio_Pin0,Output);           
DIO_InitPin(Dio_GroupC,Dio_Pin5,Output);
        
/**
* Initialize LCD
*/
LCD_Init(Lcd_4bitMode);             
/**
* Initialize DHT11 Sensor
*/
DHT11_Init();
_delay_ms(50);
/**
*  Initial LED state
*/
DIO_WritePin(Dio_GroupC, Dio_Pin0,Low);
DIO_WritePin(Dio_GroupC,Dio_Pin5,Low);
                 
                                         
/* Display Temperature */
LCD_GotoXY(0, 0);
LCD_WriteString((uint8_t *)"Hum: ",Lcd_4bitMode);

/* Display Humidity */
LCD_GotoXY(1, 0);
LCD_WriteString((uint8_t *)"Temp: ",Lcd_4bitMode);

while (1)
{
// Read temperature & Humidity 
Status = DHT11_ReadData(&Temperature ,&Humidity);

if (Status == DHT11_OK)
{
/* Green LED ON */
DIO_WritePin(Dio_GroupC,Dio_Pin0,High);              
/* Red LED OFF */
DIO_WritePin(Dio_GroupC,Dio_Pin5,Low);
/* Displaying Temperature*/
LCD_GotoXY(0, 6);
LCD_WriteNumber(Humidity,Lcd_4bitMode);
LCD_WriteString((uint8_t *)"%", Lcd_4bitMode);
/*  Displaying Humidity */
LCD_GotoXY(1, 6);
LCD_WriteNumber(Temperature,Lcd_4bitMode);    
LCD_WriteString((uint8_t *)"C", Lcd_4bitMode);
}
else
{
/* Green LED OFF */
DIO_WritePin(Dio_GroupC,Dio_Pin0,Low);                
/* Red LED ON */
DIO_WritePin(Dio_GroupC,Dio_Pin5,High);
                           
LCD_WriteInstruction(Lcd_ClearScreen,Lcd_4bitMode);
LCD_GotoXY(0, 0);
LCD_WriteString((uint8_t *)"DHT11 Error",Lcd_4bitMode);

}
_delay_ms(2000);
}
return 0;
}