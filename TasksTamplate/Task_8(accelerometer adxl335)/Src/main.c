/**
 * @file main.c
 * @brief Demo application for the ADXL335 accelerometer driver.
 * @details Initializes the ADXL335 (via the MCAL ADC driver) and a
 *          character LCD, then continuously reads the X, Y and Z
 *          acceleration in milli-g and prints them on the LCD, refreshing
 *          the values in a loop. This file exercises the public API
 *          documented in ADXL335_Interface.h and README.md.
 * @version 1.0.0
 * @author Yousef Mohamed
 * @date 2026-09-24
 * @copyright Copyright (c) 2026, Gestell Company. All rights reserved.
 */

#include <util/delay.h>

#include "COMMON/Definition.h"
#include "HAL/ADXL335/ADXL335_Interface.h"
#include "HAL/LCD/LCD_Interface.h"

/** Delay between two readings, in milliseconds. */
#define MAIN_SAMPLE_PERIOD_MS   200U

static void Main_PrintSignedMg(int16_t ValueMg)
{
    uint16_t magnitude;

    if (ValueMg < 0)
    {
        LCD_WriteData('-', Lcd_4bitMode);
        magnitude = (uint16_t)(-(int32_t)ValueMg);
    }
    else
    {
        LCD_WriteData('+', Lcd_4bitMode);
        magnitude = (uint16_t)ValueMg;
    }

    LCD_WriteNumber(magnitude, Lcd_4bitMode);
}

int main(void)
{
    int16_t x_mg;
    int16_t y_mg;
    int16_t z_mg;
    uint8_t status;

    /* Bring up the ADC (through the ADXL335 driver) and the LCD. */
    ADXL335_Init();
    LCD_Init(Lcd_4bitMode);

    LCD_GotoXY(0U, 0U);
    LCD_WriteString((const uint8_t *)"ADXL335 Demo", Lcd_4bitMode);

    for (;;)
    {
        status = ADXL335_ReadXYZ_mg(&x_mg, &y_mg, &z_mg);

        if (status == ADXL335_OK)
        {
            /* Row 0: X and Y, in milli-g. */
            LCD_GotoXY(0U, 0U);
            LCD_WriteString((const uint8_t *)"X:", Lcd_4bitMode);
            Main_PrintSignedMg(x_mg);
            LCD_WriteString((const uint8_t *)"    ", Lcd_4bitMode);

            LCD_GotoXY(0U, 8U);
            LCD_WriteString((const uint8_t *)"Y:", Lcd_4bitMode);
            Main_PrintSignedMg(y_mg);
            LCD_WriteString((const uint8_t *)"    ", Lcd_4bitMode);

            /* Row 1: Z, in milli-g. */
            LCD_GotoXY(1U, 0U);
            LCD_WriteString((const uint8_t *)"Z:", Lcd_4bitMode);
            Main_PrintSignedMg(z_mg);
            LCD_WriteString((const uint8_t *)"    ", Lcd_4bitMode);
        }
        else
        {
            LCD_GotoXY(1U, 0U);
            LCD_WriteString((const uint8_t *)"Sensor error!   ", Lcd_4bitMode);
        }

        _delay_ms(MAIN_SAMPLE_PERIOD_MS);
    }

    return 0;
}
