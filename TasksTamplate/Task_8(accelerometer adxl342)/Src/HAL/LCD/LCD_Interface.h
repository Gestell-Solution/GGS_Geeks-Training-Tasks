/**
 * @file LCD_Interface.h
 * @brief LCD public interface.
 * @details Declares the APIs of the character LCD driver (HD44780 compatible,
 *          16x2, 4-bit or 8-bit interface, write-only).
 * @version 1.1.0
 * @author Yousef Mohamed
 * @date 2026-09-24
 * @copyright Copyright (c) 2026, Gestell Company. All rights reserved.
 */

#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H

#include <stdint.h>

#include "../../MCAL/DIO/DIO_Interface.h"

#include "LCD_Private.h"
#include "LCD_Config.h"


void LCD_Init(uint8_t ModeType);

void LCD_WriteData(uint8_t Data, uint8_t ModeType);

void LCD_WriteInstruction(uint8_t Instruction, uint8_t ModeType);

void LCD_WriteString(const uint8_t *String, uint8_t ModeType);

void LCD_GotoXY(uint8_t Row, uint8_t Column);

void LCD_WriteNumber(uint16_t Number, uint8_t ModeType);

#endif 
