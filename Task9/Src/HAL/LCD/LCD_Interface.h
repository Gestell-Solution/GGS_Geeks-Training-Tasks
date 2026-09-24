#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H

#include "../../MCAL/DIO/DIO_Interface.h"
#include "LCD_Private.h"
#include "LCD_Config.h"

void LCD_Init (uint8_t ModeType);
void LCD_WriteData (uint8_t Data,uint8_t ModeType);
void LCD_WriteInstruction (uint8_t Instruction,uint8_t ModeType);
void LCD_WriteString (uint8_t *string,uint8_t ModeType); 
void LCD_GotoXY (uint8_t X, uint8_t Y);
void LCD_WriteNumber(uint16_t  Number);


#endif
