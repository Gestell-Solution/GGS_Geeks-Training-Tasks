#include "HAL/ADXL342/ADXL342_Interface.h"
#include "HAL/LCD/LCD_Interface.h"

static void LCD_WriteSignedNumber(int16_t Number)
{
    uint16_t AbsoluteValue;

    if (Number < 0)
    {
        LCD_WriteData((uint8_t)'-', Lcd_4bitMode);

        AbsoluteValue = (uint16_t)(-(Number + 1));
        AbsoluteValue++;
    }
    else
    {
        LCD_WriteData((uint8_t)'+', Lcd_4bitMode);

        AbsoluteValue = (uint16_t)Number;
    }

    LCD_WriteNumber(AbsoluteValue, Lcd_4bitMode);
}

int main(void)
{
    uint8_t Status;

    int16_t X_Axis;
    int16_t Y_Axis;
    int16_t Z_Axis;

    LCD_Init(Lcd_4bitMode);

    Status = ADXL342_Init();

    if (Status == ADXL342_OK)
    {
        LCD_GotoXY(0U, 0U);
        LCD_WriteString((const uint8_t *)"ADXL345 OK", Lcd_4bitMode);

        while (1)
        {
            ADXL342_ReadXYZ_mg(&X_Axis , &Y_Axis , &Z_Axis);

            LCD_GotoXY(0U, 0U);
            LCD_WriteString((const uint8_t *)"X:", Lcd_4bitMode);
            LCD_WriteSignedNumber(X_Axis);

            LCD_WriteString((const uint8_t *)" Y:", Lcd_4bitMode);
            LCD_WriteSignedNumber(Y_Axis);

            LCD_GotoXY(1U, 0U);
            LCD_WriteString((const uint8_t *)"Z:", Lcd_4bitMode);
            LCD_WriteSignedNumber(Z_Axis);
        }
    }
    else
    {
        LCD_GotoXY(0U, 0U);
        LCD_WriteString((const uint8_t *)"ADXL345 ERROR", Lcd_4bitMode);
        while (1)
        {
        }
    }

    return 0;
}