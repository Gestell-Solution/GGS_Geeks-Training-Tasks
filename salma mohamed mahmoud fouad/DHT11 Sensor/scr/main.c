#include <util/delay.h>
#include"HAL/LCD/LCD_Interface.h"
#include"HAL/DHT11/DHT11_Interface.h"
#include"HAL/LED/LED_Interface.h"

void main()
{    
    Led_Init(Dio_GroupB,Dio_Pin3,SourceConnection);
    LCD_Init(LCD_8bitMode);
    DHT11_Init();
    uint8_t data=0;
    LCD_WriteString("welcome",LCD_8bitMode);
    LCD_Instruction(LCD_ClearScreen,LCD_8bitMode);
    _delay_ms(100);
    while(1){
        LCD_Go_To_XY(0,1);
        LCD_WriteString("humidity  ",LCD_8bitMode);
        LCD_Number(-250,LCD_8bitMode);
        data=DHT11_Get_data();
        LCD_Number(data,LCD_8bitMode);
        if(data==70){
            Led_off(Dio_GroupB,Dio_Pin3);
        }
        else{
            Led_on(Dio_GroupB,Dio_Pin3);
        }
    }
}


