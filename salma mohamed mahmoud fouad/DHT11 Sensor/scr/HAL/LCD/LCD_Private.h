/**
 * @file LCD_Private.h
 * @author salma mohamed mahmoud fouad(salmafouadothman@gmail.com)
 * @brief private thigs that  only is used with lcd
 * @details we have lcd mode either 4 or 8bit mode and clearscreen we have cursor on blinking on 
 * @version 0.1
 * @date 2026-09-16
 * @copyright Copyright (c) 2026
 */
#ifndef _LCD_PRIVATE_H
#define _LCD_PRIVATE_H
/**
 * @brief for 4bit mode
 * @def LCD_4bitMode
 */
#define LCD_4bitMode 0
/**
 * @brief for 8bit mode
 * @def LCD_8bitMode
 */
#define LCD_8bitMode 1
/**
 * @brief for clearing screen
 * @def LCD_ClearScreen
 */
#define LCD_ClearScreen 0x01

#define LCD_8bitMode2Line5x8f 0x38
/**
 * @brief for screen
 * @def LCD_DisplayOff
 */
#define LCD_DisplayOff 0x08
/**
 * @brief for screen on
 * @def LCD_DisplayON
 */
#define LCD_DisplayON 0x0C
/**
 * @brief for to make the cursor on on screen
 * @def LCD_CursorON
 */
#define LCD_CursorON 0x0E
/**
 * @brief for cursor blinking
 * @def LCD_BlinkingON
 */
#define LCD_BlinkingON 0x0F

#define entrymodeR 0x04
#define entrymodeL 0x07
#define entrymodeI_D 0x06
#define entrymodeS 0x05

#endif