/**
 * @file LCD_Config.h
 * @author salma mohamed mahmoud fouad(salmafouadothman@gmail.com)
 * @brief this file contain pin config it can be changed from here
 * @version 0.1
 * @date 2026-09-16
 * 
 * @copyright Copyright (c) 2026
 * 
 */
#ifndef _LCD_CONFIG_H
#define _LCD_CONFIG_H

#include"../../MCAL/DIO/DIO_Interface.h"

#define LCD_RSPin      Dio_Pin0
#define LCD_RSGroup    Dio_GroupA
#define LCD_RWPin      Dio_Pin1
#define LCD_RWGroup    Dio_GroupA
#define LCD_EPin       Dio_Pin2
#define LCD_EGroup     Dio_GroupA
#define LCD_DataGroup  Dio_GroupC

#endif