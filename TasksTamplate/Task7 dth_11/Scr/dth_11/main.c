#include <stdint.h>
#include <util/delay.h>
#include "Common/Bitmath.h"
#include "Common/Defination.h"
#include "MCAL/AtmegaReg16.h"
#include "MCAL/DIO/DIO_Interface.h"
#include "HAL/LCD/LCD_Interface.h"
#include "HAL/dth_11/dth_11_Interface.h"


int main ()
{

    LCD_Init(Lcd_8bitMode);
    LCD_GotoXY(0,4);
    LCD_WriteString("54568",Lcd_8bitMode);
    _delay_ms (200);
    uint8_t Local_Data[5];
    LCD_WriteInstruction(Lcd_ClearScreen,Lcd_8bitMode);

    while (1)
    {
        DTH_11_SendRequest();
 
        if (DTH_11_ReceiveResponse() == 0)
        {
            LCD_WriteString((uint8_t*)"rec: ", Lcd_8bitMode);

        }
        else if (DTH_11_ReadData(Local_Data) == 0)
        {
            LCD_WriteString((uint8_t*)"ghh: ", Lcd_8bitMode);

        }

        else
        {
            LCD_GotoXY(0,0);
            LCD_WriteString("Humidity: ", Lcd_8bitMode);
            LCD_WriteNumber(Local_Data[0], Lcd_8bitMode);
            LCD_GotoXY(1,0);
            LCD_WriteString("Temperature: ", Lcd_8bitMode);
            LCD_WriteNumber(Local_Data[2], Lcd_8bitMode);
            
        }
 
        _delay_ms(2000); 
    }

}
