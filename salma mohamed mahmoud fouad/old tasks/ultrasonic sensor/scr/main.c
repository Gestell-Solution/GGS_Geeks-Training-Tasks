#include <util/delay.h>
#include"HAL/ULTRASONIC/ULTS_Interface.h"

int main(){
    uint16_t distance=0;
    ULTS_Init();
    LCD_Init(Lcd_8bitMode);
    LCD_GotoXY(0,1);
    LCD_WriteString("read ults",Lcd_8bitMode);
    _delay_ms(100);
    LCD_WriteInstruction(Lcd_ClearScreen,Lcd_8bitMode);
    while (1){
       distance= ULTS_Start();
        LCD_GotoXY(0,1);
        LCD_WriteString("distance:",Lcd_8bitMode);
        TIMER1_captureEvent(distance);
        LCD_GotoXY(1,0);
        LCD_Number(distance,Lcd_8bitMode);
        _delay_ms(200);
    }
}

