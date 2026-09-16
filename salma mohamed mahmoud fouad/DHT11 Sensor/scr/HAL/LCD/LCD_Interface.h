/**
 * @file LCD_Interface.h
 * @author salma mohamed mahmoud fouad(salmafouadothman@gmail.com)
 * @brief this file contain all the command the lcd can do
 * @details we have here lcd initilaze and writting data like just one charcter between '' we have 
 *          instruction for clear screen cursosr on off binking on lcd screen off ,we can write string,
 *          we can go to line 1 or 2 any place on it,and we can display number
 * @version 0.1
 * @date 2026-09-16
 * @copyright Copyright (c) 2026
 */
#ifndef _LCD_INTERFACE_H
#define _LCD_INTERFACE_H

#include"../../MCAL/DIO/DIO_Interface.h"
#include"LCD_Private.h"
#include"LCD_Config.h"
/**
 * @fn  LCD_Init
 * @brief to initilaze the lcd
 * @param ModeType either 8 or 4 bit
 * @note dont forget it or it wont work
 */
void LCD_Init(uint8_t ModeType);
/**
 * @brief write data like just one charcter between ''
 * @fn LCD_WriteData
 * @param Data a charcter
 * @param ModeType either 8 or 4 bit
 */
void LCD_WriteData(uint8_t Data,uint8_t ModeType);
/**
 * @brief instruction for clear screen cursosr on off binking on lcd screen off ect.
 * @fn LCD_Instruction
 * @param Instruction here we write clear screen cursosr on off binking on lcd screen off ect.
 * @param ModeType either 8 or 4 bit
 */
void LCD_Instruction(uint8_t Instruction,uint8_t ModeType);
/**
 * @brief we can write string
 * @fn LCD_WriteString
 * @param String write a string between ""
 * @param ModleType either 8 or 4 bit
 */
void LCD_WriteString(uint8_t *String,uint8_t ModleType);
/**
 * @brief  we can go to line 1 or 2 any place on it
 * @fn LCD_Go_To_XY
 * @param x line
 * @param y row
 */
void LCD_Go_To_XY(uint8_t x,uint8_t y);
/**
 * @brief it display number it can be postive or negative
 * @fn LCD_Number
 * @param num number to disply
 * @param ModleType either 8 or 4 bit
 */
void LCD_Number(int32_t num ,uint8_t ModleType);



#endif