/**
 * @file      EXTI_Interface.h
 * @author    Abdulrahman Ali 
 * @author    ENG/Hesham Ahmed (Reviewer)
 * @brief     Interface of the EXTI Driver.
 * @details   This file contains the function prototypes of EXTI driver
 * @version   1.0.0
 * @date      26 August 2026
 * @copyright Copyright (c) 2026, Gestell Company
 */




#ifndef _EXTI_INTERFACE_H
#define _EXTI_INTERFACE_H
#include <stdint.h>
#include"../../LIB/Definition.h"
#include"../../LIB/Bitmath.h"
#include"../Atmega128regmap.h"


void EXTI_Init(uint8_t InterruptName,uint8_t SensConfig);
void EXTI_Enable(uint8_t InterruptName);
void EXTI_Disable(uint8_t InterruptName);
void EXTI_CallBack(uint8_t InterruptName, void (*Func)(void));

#endif 
