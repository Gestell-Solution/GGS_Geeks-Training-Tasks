/**
 * @file main.c
 * @brief Application test file for the ADXL335 Accelerometer Driver on ATmega32.
 * @details Configures ADC and gets the g readings of x-axis displayed on LCD  
 * @version 0.1
 * @author Malak Mohammed (malak.mohammed.esmail@gmail.com) 
 * @date 24-09-2026
 * @copyright Copyright (c) 2026, Gestell Company
 */

#include <math.h>
#include "Common/Definition.h"
#include "MCAL/ADC/ADC_Interface.h"
#include "HAL/ADXL335/ADXL335_Interface.h"
#include "HAL/LCD/LCD_Interface.h"
#include <util/delay.h>

void main(void)
{
    Adc_Config_t adcConfig = {
        .ReferenceSelection = Adc_AVCC,
        .AdjustResult       = Adc_RightAdjust,
        .ConversionMode     = SingleMode,
        .InterruptState     = Disable,
        .PrescalerSelection = Adc_Prescaler_64
    };
    
    LCD_Init(Lcd_8bitMode); 
    ADC_Init(adcConfig);
    ADXL335_Init();

    float X_G = 0.0;
    float Y_G = 0.0;
    float Z_G = 0.0;

    while(1)
    {
        
    ADXL335_ReadG(&X_G, &Y_G, &Z_G);
    
    /** @details a variable that stores the reading of float as integer(float*10)initially because lcd doesn't handle floats */
    int16_t val = (int16_t)roundf(X_G * 10.0);

    LCD_GotoXY(0, 0);
    LCD_WriteString((uint8_t*)"X:", Lcd_8bitMode);

    if (val < 0)
     { 
    LCD_WriteData('-', Lcd_8bitMode);  /* print negative sign before the number*/
    val = -val; /* convert the negative value to positive to handle calculations */
     }
     else  
       { 
        LCD_WriteData('+', Lcd_8bitMode); /* print positive sign before the number*/

       }

      LCD_WriteNumber(val / 10);    /* print the integer before the floating point*/
      LCD_WriteData('.', Lcd_8bitMode); /* print floating point*/
      LCD_WriteNumber(val % 10); /* print the fraction after the floating point*/
      LCD_WriteString((uint8_t*)"g ", Lcd_8bitMode); /* print acceleration force unit*/
    }
}