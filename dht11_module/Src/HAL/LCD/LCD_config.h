/**
 * @file      LCD_config.h
 * @author    Rohayem
 * @author    Hesham Ahmed (Reviewer)
 * @brief     Configuration file for the LCD Driver.
 * @details   This file contains user-configurable parameters such as the hardware 
 *            ports and pins to which the LCD is connected (RS, EN, and Data pins).
 *            Note: The RW (Read/Write) pin is assumed to be connected to GND.
 * @version   1.0.0
 * @date      3 August 2026
 * @copyright Copyright (c) 2026, Gestell Company
 */

#ifndef _LCD_CONFIG_C_
#define _LCD_CONFIG_C_

#include "../../MCAL/DIO/DIO_private.h"


#define LCD_datapins   0xF0 
#define LCD_datapins_all 0xFF
#define LCD_RSPin      Dio_pin2 // Register_Select pin + group
#define LCD_RSGroup    Dio_groupC

 // RW(read_write) will be with ground

#define LCD_EPin       Dio_pin3 //enable pin + group
#define LCD_EGroup     Dio_groupC

#define LCD_DataGroup  Dio_groupC //DataGroup: its for pins for 8bit Modetype(D0 : D7)
                                 //                for pins for 4bit Modetype(D4 : D7)


#endif
