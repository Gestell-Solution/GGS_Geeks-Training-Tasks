/**
 * @file LCD_Program.c
 * @brief LCD driver implementation.
 * @details Implements the HD44780 compatible character LCD driver declared in
 *          LCD_Interface.h. The public API is documented in the header.
 * @version 1.1.0
 * @author Yousef Mohamed
 * @date 2026-09-24
 * @copyright Copyright (c) 2026, Gestell Company. All rights reserved.
 */

#include "LCD_Interface.h"
#include <util/delay.h>   /* Needs F_CPU, defined by Definition.h (included above). */

/** Interface mode selected by LCD_Init(), used by functions without a ModeType argument. */
static uint8_t LCD_ActiveMode = Lcd_4bitMode;

static void LCD_PulseEnable(void)
{
    DIO_WritePin(Lcd_EGroup, Lcd_EPin, High);
    _delay_ms(Lcd_EnablePulseMs);
    DIO_WritePin(Lcd_EGroup, Lcd_EPin, Low);
}

static void LCD_SendByte(uint8_t Byte, uint8_t RegisterSelect, uint8_t ModeType)
{
    DIO_WritePin(Lcd_RSGroup, Lcd_RSPin, RegisterSelect);
    DIO_WritePin(Lcd_RWGroup, Lcd_RWPin, Low);

    if (ModeType == Lcd_8bitMode)
    {
        DIO_WriteGroup(Lcd_DataGroup, Byte);
        LCD_PulseEnable();
    }
    else if (ModeType == Lcd_4bitMode)
    {
        /* Upper nibble */
        DIO_WriteGroup(Lcd_DataGroup, (uint8_t)(Byte & Lcd_UpperNibbleMask));
        LCD_PulseEnable();

        /* Lower nibble */
        DIO_WriteGroup(Lcd_DataGroup, (uint8_t)((Byte << Lcd_NibbleShift) & Lcd_UpperNibbleMask));
        LCD_PulseEnable();
    }
    else
    {
        /* Invalid mode: nothing is sent. */
    }
}

void LCD_WriteData(uint8_t Data, uint8_t ModeType)
{
    LCD_SendByte(Data, High, ModeType);
}

void LCD_WriteInstruction(uint8_t Instruction, uint8_t ModeType)
{
    LCD_SendByte(Instruction, Low, ModeType);
}

void LCD_Init(uint8_t ModeType)
{
    if ((ModeType == Lcd_8bitMode) || (ModeType == Lcd_4bitMode))
    {
        LCD_ActiveMode = ModeType;

        /* Control pins and data port as outputs */
        DIO_InitPin(Lcd_RSGroup, Lcd_RSPin, Output);
        DIO_InitPin(Lcd_RWGroup, Lcd_RWPin, Output);
        DIO_InitPin(Lcd_EGroup, Lcd_EPin, Output);
        DIO_InitGroup(Lcd_DataGroup, Dio_AllOutput);

        /* Wait for the LCD power-on */
        _delay_ms(Lcd_PowerOnDelayMs);

        if (ModeType == Lcd_8bitMode)
        {
            LCD_WriteInstruction(Lcd_8bitMode2Line5x8F, Lcd_8bitMode);
            _delay_ms(Lcd_CommandDelayMs);
            LCD_WriteInstruction(Lcd_CursorOn, Lcd_8bitMode);
            _delay_ms(Lcd_CommandDelayMs);
            LCD_WriteInstruction(Lcd_ClearScreen, Lcd_8bitMode);
            _delay_ms(Lcd_ClearDelayMs);
            LCD_WriteInstruction(Lcd_EntryMode1, Lcd_8bitMode);
            _delay_ms(Lcd_CommandDelayMs);
        }
        else
        {
            LCD_WriteInstruction(Lcd_ReturnHome, Lcd_4bitMode);         /* Switches the LCD to 4-bit mode. */
            _delay_ms(Lcd_CommandDelayMs);
            LCD_WriteInstruction(Lcd_4bitMode2Line5x8F, Lcd_4bitMode);
            _delay_ms(Lcd_CommandDelayMs);
            LCD_WriteInstruction(Lcd_DisplayOn, Lcd_4bitMode);
            _delay_ms(Lcd_CommandDelayMs);
            LCD_WriteInstruction(Lcd_ClearScreen, Lcd_4bitMode);
            _delay_ms(Lcd_ClearDelayMs);
            LCD_WriteInstruction(Lcd_EntryMode1, Lcd_4bitMode);
            _delay_ms(Lcd_CommandDelayMs);
        }
    }
}

void LCD_WriteString(const uint8_t *String, uint8_t ModeType)
{
    uint16_t index = 0U;

    if (String != Null)
    {
        while (String[index] != NullChar)
        {
            LCD_WriteData(String[index], ModeType);
            index++;
        }
    }
}

void LCD_GotoXY(uint8_t Row, uint8_t Column)
{
    uint8_t address;

    if ((Row <= Lcd_MaxRow) && (Column <= Lcd_MaxColumn))
    {
        if (Row == 0U)
        {
            address = Lcd_Row0Address;
        }
        else
        {
            address = Lcd_Row1Address;
        }

        address = (uint8_t)(address + Column);
        LCD_WriteInstruction((uint8_t)(address | Lcd_SetDdramAddress), LCD_ActiveMode);
    }
}

void LCD_WriteNumber(uint16_t Number, uint8_t ModeType)
{
    uint8_t  digits[Lcd_NumberBufferSize] = {0U};
    uint8_t  count = 0U;
    uint16_t value = Number;

    /* Extract the digits, least significant first (0 gives the single digit "0"). */
    do
    {
        digits[count] = (uint8_t)((value % 10U) + Lcd_AsciiZero);
        count++;
        value = (uint16_t)(value / 10U);
    } while (value > 0U);

    /* Send them most significant first. */
    while (count > 0U)
    {
        count--;
        LCD_WriteData(digits[count], ModeType);
    }
}
