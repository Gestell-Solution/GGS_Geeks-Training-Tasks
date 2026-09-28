#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H

#include"LCD_Config.h"
#include"LCD_Private.h"
#include"../../MCAL/DIO/DIO_Interface.h"


void LCD_Init(uint8_t ModeType);
void LCD_WriteChar(uint8_t Char, uint8_t ModeType);
void LCD_WriteInstruction(uint8_t Instruction, uint8_t ModeType);
void LCD_WriteString(uint8_t *String, uint8_t ModeType);
void LCD_GotoXY(uint8_t X,uint8_t Y);

void LCD_WriteNumber(uint16_t Number, uint8_t ModeType);


#endif