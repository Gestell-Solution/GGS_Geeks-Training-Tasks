#include <stdint.h>
#include <util/delay.h>
#include "Common/Bitmath.h"
#include "Common/Defination.h"
#include "MCAL/DIO/DIO_Interface.h"
#include "HAL/LCD/LCD_Interface.h"
#include "HAL/ADXL_335/ADXL_Interface.h"




int main(void)
{
    uint16_t X_G;
    uint16_t Y_G;
    uint16_t Z_G;

    LCD_Init(Lcd_8bitMode);
    LCD_GotoXY(0, 3);
    LCD_WriteString("ADXL Test",Lcd_8bitMode);
    _delay_ms(2000);

    while (1)
    {
        /* ADAPT: these three names must match the functions declared in
         * your real ADXL_Interface.h - that is exactly what the linker
         * is complaining about. */
        ADXL335_ReadG(X_G, Y_G, Z_G);
        

        LCD_WriteInstruction(Lcd_ClearScreen, Lcd_8bitMode);

        LCD_GotoXY(0, 0);
        LCD_WriteString("X:",Lcd_8bitMode);
        LCD_WriteString(X_G,Lcd_8bitMode);
        LCD_WriteString(" Y:",Lcd_8bitMode);
        LCD_WriteString(Y_G,Lcd_8bitMode);

        LCD_GotoXY(1, 0);
        LCD_WriteString( "Z:",Lcd_8bitMode);
        LCD_WriteNumber( Z_G,Lcd_8bitMode);
        LCD_WriteString( " mg",Lcd_8bitMode);

        _delay_ms(500);
    }
}