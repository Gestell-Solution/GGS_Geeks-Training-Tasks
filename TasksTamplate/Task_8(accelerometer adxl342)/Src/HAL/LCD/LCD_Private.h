/**
 * @file LCD_Private.h
 * @brief LCD private definitions.
 * @details Contains the mode selectors, HD44780 instruction codes and
 *          timing constants used by the LCD driver. The file is included by
 *          LCD_Interface.h so the mode selectors are visible to the user.
 * @version 1.1.0
 * @author Yousef Mohamed
 * @date 2026-09-24
 * @copyright Copyright (c) 2026, Gestell Company. All rights reserved.
 */

#ifndef LCD_PRIVATE_H
#define LCD_PRIVATE_H

#define Lcd_4bitMode            0U      /**< 4-bit interface (data on D4..D7). */
#define Lcd_8bitMode            1U      /**< 8-bit interface (data on D0..D7). */

#define Lcd_ClearScreen         0x01U   /**< Clear display and return cursor home. */
#define Lcd_ReturnHome          0x02U   /**< Return cursor home (used to enter 4-bit mode). */
#define Lcd_EntryMode1          0x06U   /**< Entry mode: increment cursor, no display shift. */
#define Lcd_DisplayOff          0x08U   /**< Display off. */
#define Lcd_DisplayOn           0x0CU   /**< Display on, cursor off. */
#define Lcd_CursorOn            0x0EU   /**< Display on, cursor on. */
#define Lcd_CursorBlink         0x0FU   /**< Display on, cursor blinking. */
#define Lcd_4bitMode2Line5x8F   0x28U   /**< Function set: 4-bit, 2 lines, 5x8 font. */
#define Lcd_8bitMode2Line5x8F   0x38U   /**< Function set: 8-bit, 2 lines, 5x8 font. */
#define Lcd_SetDdramAddress     0x80U   /**< Set DDRAM (cursor) address command bit. */

#define Lcd_MaxRow              1U      /**< Last valid row index. */
#define Lcd_MaxColumn           15U     /**< Last valid column index. */
#define Lcd_Row0Address         0x00U   /**< DDRAM address of row 0, column 0. */
#define Lcd_Row1Address         0x40U   /**< DDRAM address of row 1, column 0. */

#define Lcd_UpperNibbleMask     0xF0U   /**< Mask of the upper nibble (D4..D7). */
#define Lcd_NibbleShift         4U      /**< Shift that moves the lower nibble up. */
#define Lcd_AsciiZero           0x30U   /**< ASCII code of the character '0'. */
#define Lcd_NumberBufferSize    5U      /**< Digits needed for the largest uint16_t (65535). */

#define Lcd_EnablePulseMs       1.0     /**< Width of the Enable pulse in ms. */
#define Lcd_PowerOnDelayMs      35.0    /**< Wait after power-up before the first command, in ms. */
#define Lcd_CommandDelayMs      1.0     /**< Wait after a normal instruction, in ms. */
#define Lcd_ClearDelayMs        2.0     /**< Wait after the clear-screen instruction, in ms. */

#endif 
