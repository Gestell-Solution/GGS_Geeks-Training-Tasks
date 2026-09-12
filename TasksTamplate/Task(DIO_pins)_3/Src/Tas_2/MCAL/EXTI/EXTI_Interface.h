#ifndef _EXTI_INTERFACE_H
#define _EXTI_INTERFACE_H
#include <stdint.h>
#include"../../LIB/Definition.h"
#include"../../LIB/Bitmath.h"
#include"../Atmega32regmap.h"


void EXTI_Init(uint8_t InterruptName,uint8_t SensConfig);
void EXTI_Enable(uint8_t InterruptName);
void EXTI_Disable(uint8_t InterruptName);
void EXTI_CallBack(uint8_t InterruptName, void (*Func)(void));

#endif 
