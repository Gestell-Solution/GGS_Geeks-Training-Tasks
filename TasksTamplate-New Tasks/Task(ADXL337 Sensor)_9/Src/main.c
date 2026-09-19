/**
 * @file main.c
 * @brief This file contains the main application for ADXL337 Sensor.
 * @author Developer: Abdulrahman Ali 
 * @author Reviewer : Eng/Hesham Ahmed
 * @date 9/20/2026
 * @copyright Copyright (c) 2026 , Gestell Company. All rights reserved.
 * @version 1.0.0
*/

#include <stdint.h>
#include <util/delay.h>
#include "MCAL/DIO/DIO_Interface.h"
#include "MCAL/ADC/ADC_Interface.h"
#include "HAL/LCD/LCD_Interface.h"
#include "HAL/ADXL337/ADXL_Interface.h"
#include "LIB/Definition.h"

/** 
 * @brief Main application function.
 *
 * @return int.
*/
int main(void)
{
float16_t X_acc=0.0f;
float16_t Y_acc=0.0f;
float16_t Z_acc=0.0f;
        
/**
* Initialize ADXL337 Sensor
*/
ADXL_Init();

        
/**
* Initialize LCD
*/
LCD_Init(Lcd_4bitMode);
LCD_GotoXY(0,0);
LCD_WriteString((uint8_t*)"X: ",Lcd_4bitMode);
LCD_GotoXY(0,8);
LCD_WriteString((uint8_t*)"Y: ",Lcd_4bitMode);
LCD_GotoXY(1,0);
LCD_WriteString((uint8_t*)"Z: ",Lcd_4bitMode);

while (1)
{
        
/**
* Starting to read the 3_Axis
*/
ADXL337_GetAcceleration(&X_acc ,&Y_acc ,&Z_acc);        
/**
* Reading the X_Axis from LCD
*/
LCD_GotoXY(0,2);
LCD_WriteNumber(X_acc,Lcd_4bitMode);
LCD_WriteString((uint8_t *)"%", Lcd_4bitMode);    
/**
* Reading the Y_Axis from LCD
*/
LCD_GotoXY(0,10);
LCD_WriteNumber(Y_acc,Lcd_4bitMode);
LCD_WriteString((uint8_t *)"%", Lcd_4bitMode);       
/**
* Reading the Z_Axis from LCD
*/
LCD_GotoXY(1, 2);
LCD_WriteNumber(Z_acc,Lcd_4bitMode);    
LCD_WriteString((uint8_t *)"%", Lcd_4bitMode);
_delay_ms(200);

}
return 0;
}


/**
 * The Output Calculation 
 * 
 * AT 100% of Resistance that means we use the full voltage 3.3V 
 * that mean that the Acceleration=(the read Voltage 3.3V - voltage 1.65V)/Sensitivity 0.3V)=5%
 * 
 * AT 90% of Resistance that means we dont use the full voltage 3.3V we use 2.97V
 * that mean that the Acceleration=(the read Voltage 2.97V - voltage 1.65V)/Sensitivity 0.3V)=4%
 * 
 * And So on for the rest of Calculation
 * 
 */