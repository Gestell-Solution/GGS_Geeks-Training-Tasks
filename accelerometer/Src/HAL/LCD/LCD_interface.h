/**
 * @file      LCD_interface.h
 * @author    Rohayem
 * @author    Hesham Ahmed (Reviewer)
 * @brief     Interface of the LCD (Liquid Crystal Display) Driver.
 * @details   This file contains the function prototypes and public APIs used by 
 *            upper layers to initialize and interact with the LCD module.
 * @version   1.0.0
 * @date      3 August 2026
 * @copyright Copyright (c) 2026, Gestell Company
 */

#ifndef _LCD_INTERFACE_H_
#define _LCD_INTERFACE_H_

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/COMMON_MACROS.h"
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/REG_MAP.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include <util/delay.h>

#include "LCD_config.h"
#include "LCD_private.h"

void LCD_init         (u8 ModeType);
void LCD_write_command(u8 command );
void LCD_write_data   (u8 data );
void LCD_write_string (u8 *str );
void LCD_go_to_XY     (u8 row , u8 column );
void LCD_write_number (u16 Number);

#endif
