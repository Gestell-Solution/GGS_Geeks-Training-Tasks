#include "LCD_Interface.h"
#include <util/delay.h>


void LCD_WriteChar(uint8_t Char, uint8_t ModeType)
{
   if (ModeType==Lcd_8bitMode)
   {
    // RS -> 1 
     DIO_WritePin(LCD_RSGroup,LCD_RSPin,High);
    // RW -> 0
     DIO_WritePin(LCD_RWGroup,LCD_RWPin,Low);
    // Update Data 
     DIO_WriteGroup(LCD_DataGroup,Char);
    // E -> 1
     DIO_WritePin(LCD_EGroup,LCD_EPin,High);
    // wait 
     _delay_ms(1);
    // E -> 0
     DIO_WritePin(LCD_EGroup,LCD_EPin,Low);

   }
}



void LCD_WriteInstruction(uint8_t Instruction, uint8_t ModeType)
{
      if (ModeType==Lcd_8bitMode)
   {
    // RS -> 0
     DIO_WritePin(LCD_RSGroup,LCD_RSPin,Low);
    // RW -> 0
     DIO_WritePin(LCD_RWGroup,LCD_RWPin,Low);
    // Update Data 
     DIO_WriteGroup(LCD_DataGroup,Instruction);
    // E -> 1
     DIO_WritePin(LCD_EGroup,LCD_EPin,High);
    // wait 
     _delay_ms(1);
    // E -> 0
     DIO_WritePin(LCD_EGroup,LCD_EPin,Low);

   }
}



void LCD_Init(uint8_t ModeType)
{
    if (ModeType ==Lcd_8bitMode)
    {

//RS Direction output
    DIO_InitPin(LCD_RSGroup,LCD_RSPin,Output);
//RW Direction output
    DIO_InitPin(LCD_RWGroup,LCD_RWPin,Output);
//E Direction output
    DIO_InitPin(LCD_EGroup,LCD_EPin,Output);
//Data
    DIO_InitGroup(LCD_DataGroup,0xFF);

//8BitModeInit
         _delay_ms(31);
        LCD_WriteInstruction(Lcd_8bitMode2Line5x8F,Lcd_8bitMode);
         _delay_ms(.05);
        LCD_WriteInstruction(Lcd_DisplayOn,Lcd_8bitMode);
         _delay_ms(.05);
        LCD_WriteInstruction(Lcd_ClearScreen,Lcd_8bitMode);
         _delay_ms(1.54);
        LCD_WriteInstruction(Lcd_EntryMode1,Lcd_8bitMode);
         _delay_ms(1);    

    }     
}



void LCD_WriteString(uint8_t *String, uint8_t ModeType)
{
    if (String!=Null)
    {
        uint8_t count =0;
        while(String[count]!='\0')
        {
            LCD_WriteChar(String[count],ModeType);
            count++;
        }
    }
    
}

 

void LCD_GotoXY(uint8_t X,uint8_t Y)
{
   uint8_t DigitAddress= 0;
   switch(X)
   {
   case 0 :  DigitAddress=0x00 +Y; break;
   case 1 :  DigitAddress=0x40 +Y; break;
   }
   LCD_WriteInstruction(DigitAddress|0x80,Lcd_8bitMode);
}


void LCD_WriteNumber(uint16_t Number, uint8_t ModeType)
{
    uint8_t Local_Digits[5];   // uint16_t max is 65535 -> 5 digits
    uint8_t Local_Count = 0;
    int8_t  Local_Index = 0;

    if (Number == 0)
    {
        LCD_WriteChar('0', ModeType);
        return;
    }

    // Extract digits right-to-left (last digit first)
    while (Number != 0)
    {
        Local_Digits[Local_Count] = (Number % 10) + '0';
        Number /= 10;
        Local_Count++;
    }

    // Print them back out in the correct left-to-right order
    for (Local_Index = Local_Count - 1; Local_Index >= 0; Local_Index--)
    {
        LCD_WriteChar(Local_Digits[Local_Index], ModeType);
    }
}