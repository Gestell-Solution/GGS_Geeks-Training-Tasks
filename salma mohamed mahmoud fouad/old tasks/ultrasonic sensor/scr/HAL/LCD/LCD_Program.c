#include "LCD_Interface.h"
#include <util/delay.h>
void LCD_WriteData(uint8_t Data,uint8_t ModeType)
{
    if(ModeType==Lcd_8bitMode)
    {
    // RS -> 1 
    DIO_WritePin(Lcd_RSGroup,Lcd_RSPin,High);
    // RW -> 0
    DIO_WritePin(Lcd_RWGroup,Lcd_RWPin,Low);
    // Update Data 
    DIO_WriteGroup(Lcd_DataGroup,Data);
    // E -> 
    DIO_WritePin(Lcd_EGroup,Lcd_EPin,High);
    // wait 
    _delay_ms(1);
    // E -> 
    DIO_WritePin(Lcd_EGroup,Lcd_EPin,Low);
    }
    else if(ModeType==Lcd_4bitMode)
    {
        // your code  
    }
    
}

void LCD_WriteInstruction(uint8_t Instruction,uint8_t ModeType)
{
  if(ModeType==LCD_8bitMode){
DIO_WritePin(LCD_RSGroup,LCD_RSPin,Low);
DIO_WritePin(LCD_RWGroup,LCD_RWPin,Low);
DIO_WriteGroup(LCD_DataGroup,Instruction);
DIO_WritePin(LCD_EGroup,LCD_EPin,High);
_delay_ms(1);
DIO_WritePin(LCD_EGroup,LCD_EPin,Low);
    }
    else if(ModeType==LCD_4bitMode){}
    
}

void LCD_Init(uint8_t ModeType)
{
    if (ModeType==Lcd_8bitMode)
    {
        //RS pin as output 
        DIO_InitPin(Lcd_RSGroup,Lcd_RSPin,Output);
        DIO_InitPin(Lcd_RWGroup,Lcd_RWPin,Output);
        DIO_InitPin(Lcd_EGroup,Lcd_EPin,Output);
        //Data
        DIO_InitGroup(Lcd_DataGroup,0xFF);
        // 8 bit Mode Init
        _delay_ms(35);
        LCD_WriteInstruction(Lcd_8bitMode2Line5x8F,Lcd_8bitMode);
        _delay_ms(1);
        LCD_WriteInstruction(Lcd_CursorOn,Lcd_8bitMode);
        _delay_ms(1);
        LCD_WriteInstruction(Lcd_ClearScreen,Lcd_8bitMode);
        _delay_ms(2);
        LCD_WriteInstruction(Lcd_EntryMode1,Lcd_8bitMode);
        _delay_ms(1);


    }
}


void LCD_WriteString(uint8_t *String, uint8_t ModeType)
{
    if(String!=Null)
    {   
        uint8_t count = 0 ;
        while(String[count]!='\0')
        {
            LCD_WriteData(String[count],ModeType);
            count++;
        }
    }
}

/**
    -                 1 AC6 AC5 AC4 AC3 AC2 AC1 AC0  
    - DigitAddress  : AC7 AC6 AC5 AC4 AC3 AC2 AC1 AC0
    - Command       : 1    0   0   0   0   0   0   0
    - 
    - DigitAddress | 0x80 
 */
void LCD_GotoXY(uint8_t X , uint8_t Y)
{
    uint8_t DigitAddress = 0 ;
    switch(X)
    {
        case 0 : DigitAddress = 0x00+Y ; break;
        case 1 : DigitAddress = 0x40+Y ; break;
    }
    LCD_WriteInstruction(DigitAddress|0x80,Lcd_8bitMode);
}

void LCD_Number(int32_t num ,uint8_t ModleType){
int32_t x=0,
    reverse=0;
    if(num==0){
        LCD_WriteData('0',LCD_8bitMode);
    }
    else if(num<0){
        LCD_WriteData('-',LCD_8bitMode);
        num=-num;
    }
    while(num!=0){
        reverse=reverse*10+(num%10);
        num=num/10;
    }
    while(reverse!=0){
     x=reverse%10;
     x+=48;
     LCD_WriteData(x,ModleType);
     reverse/=10;
   }  
}
