#include "LCD_Interface.h"
#include "LCD_Private.h"
#include <util/delay.h>

void LCD_WriteData(uint8_t Data,uint8_t ModeType)
{
    if(ModeType==Lcd_8bitMode)
    {
    // RS=1 
    DIO_WritePin(Lcd_RSGroup,Lcd_RSPin,High);
    // RW=0
    DIO_WritePin(Lcd_RWGroup,Lcd_RWPin,Low);
    // Update Data 
    DIO_WriteGroup(Lcd_DataGroup,Data);
    // E=1
    DIO_WritePin(Lcd_EGroup,Lcd_EPin,High);
    // delay 
    _delay_ms(1);
    // E=0
    DIO_WritePin(Lcd_EGroup,Lcd_EPin,Low);
    }
    else if(ModeType==Lcd_4bitMode)
    {
    // your code  
         // RS=1
    DIO_WritePin(Lcd_RSGroup,Lcd_RSPin,High);
    // RW=0
    DIO_WritePin(Lcd_RWGroup,Lcd_RWPin,Low);

    //Update Data UPPER NIBBLE
    DIO_WriteGroup(Lcd_DataGroup, Data & 0xF0);
    //E=1
    DIO_WritePin(Lcd_EGroup,Lcd_EPin,High);
    //delay
    _delay_ms(1);
    //E=0
    DIO_WritePin(Lcd_EGroup,Lcd_EPin,Low);

    //Update Data LOWER NIBBLE
    DIO_WriteGroup(Lcd_DataGroup, (Data << 4) & 0xF0);
    //E=1
    DIO_WritePin(Lcd_EGroup,Lcd_EPin,High);
    //delay
    _delay_ms(1);
    //E=0
    DIO_WritePin(Lcd_EGroup,Lcd_EPin,Low);
    }
    
}

void LCD_WriteInstruction(uint8_t Instruction,uint8_t ModeType)
{
    if(ModeType==Lcd_8bitMode)
    {
    // RS=0 
    DIO_WritePin(Lcd_RSGroup,Lcd_RSPin,Low);
    // RW=0
    DIO_WritePin(Lcd_RWGroup,Lcd_RWPin,Low);
    // Update Data 
    DIO_WriteGroup(Lcd_DataGroup,Instruction);
    // E=1
    DIO_WritePin(Lcd_EGroup,Lcd_EPin,High);
    // delay 
    _delay_ms(1);
    // E=0
    DIO_WritePin(Lcd_EGroup,Lcd_EPin,Low);
    }
    else if(ModeType==Lcd_4bitMode)
    {
    // your code 
         // RS=1
    DIO_WritePin(Lcd_RSGroup,Lcd_RSPin,Low);
    // RW=0
    DIO_WritePin(Lcd_RWGroup,Lcd_RWPin,Low);

    //Update Data UPPER NIBBLE
    DIO_WriteGroup(Lcd_DataGroup, Instruction & 0xF0);
    //E=1
    DIO_WritePin(Lcd_EGroup,Lcd_EPin,High);
    //delay
    _delay_ms(1);
    //E=0
    DIO_WritePin(Lcd_EGroup,Lcd_EPin,Low);

    //Update Data LOWER NIBBLE
    DIO_WriteGroup(Lcd_DataGroup, (Instruction << 4) & 0xF0);
    //E=1
    DIO_WritePin(Lcd_EGroup,Lcd_EPin,High);
    //delay
    _delay_ms(1);
    //E=0
    DIO_WritePin(Lcd_EGroup,Lcd_EPin,Low);
    }
    
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
     else if (ModeType == Lcd_4bitMode)
    {
        // --- 4-Bit Mode Initialization ---
        
        // 1. Set Control Pins Direction
        DIO_InitPin(Lcd_RSGroup, Lcd_RSPin, Output);
        DIO_InitPin(Lcd_RWGroup, Lcd_RWPin, Output);
        DIO_InitPin(Lcd_EGroup, Lcd_EPin, Output);
        
        // 2. Set Data Group Direction
        DIO_InitGroup(Lcd_DataGroup, 0xFF);
        
        // 3. Wait for LCD power-on
        _delay_ms(35);
        
        // 4. Send Initialization Commands for 4-Bit Mode
        LCD_WriteInstruction(0x02, Lcd_4bitMode);                  // Return Home / Switch to 4-Bit Mode
        _delay_ms(1);
        LCD_WriteInstruction(Lcd_4bitMode2Line5x8F, Lcd_4bitMode); // 0x28 (2 Lines, 5x8 Font)
        _delay_ms(1);
        LCD_WriteInstruction(Lcd_DisplayOn, Lcd_4bitMode);         // 0x0C (Display ON, Cursor OFF)
        _delay_ms(1);
        LCD_WriteInstruction(Lcd_ClearScreen, Lcd_4bitMode);       // 0x01 (Clear Screen)
        _delay_ms(2);
        LCD_WriteInstruction(Lcd_EntryMode1, Lcd_4bitMode);        // 0x06 (Increment Cursor)
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


void LCD_GotoXY(uint8_t X , uint8_t Y)
{
    uint8_t DigitAddress = 0 ;
    switch(X)
    {
        case 0 : DigitAddress = 0x00+Y ; break;
        case 1 : DigitAddress = 0x40+Y ; break;
    }
    LCD_WriteInstruction(DigitAddress|0x80,Lcd_4bitMode);
}

void LCD_WriteNumber(uint32_t Number, uint8_t ModeType)
{
    char Buffer[11];
    sprintf(Buffer, "%lu", (unsigned long)Number);
    LCD_WriteString(Buffer, ModeType);
}