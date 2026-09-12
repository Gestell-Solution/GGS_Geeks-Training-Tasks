#ifndef _LED_INTERFACE_H
#define _LED_INTERFACE_H
/**
 * @file LED_Interface.h
 * @author salma mohamed mahmoud fouad(salmafouadothman@gmail.com)
 * @brief driver to control led 
 * @version 0.1
 * @date 2026-09-12
 * @copyright Copyright (c) 2026
 */
#include<stdio.h>
#include"LED_Private.h"
#include"../../MCAL/DIO/DIO_Interface.h"

void Led_Init(uint8_t GroupName , uint8_t PinNumber,uint8_t ConnectionType );
void Led_on(uint8_t GroupName , uint8_t PinNumber );
void Led_off(uint8_t GroupName , uint8_t PinNumber );
void Led_Toggle(uint8_t GroupName , uint8_t PinNumber);
#endif