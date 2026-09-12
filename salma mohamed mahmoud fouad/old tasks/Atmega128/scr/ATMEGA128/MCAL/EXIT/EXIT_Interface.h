#ifndef EXIT_INTERFACE_H_
#define EXIT_INTERFACE_H_

#include<stdint.h>
#include "../../COMMEN/Bitmath.h"
#include "../../COMMEN/Definition.h"
#include "../ATMEGA128_REG.h"
#include"EXIT_Private.h"

void EXTI_Init(uint8_t InterruptName,uint8_t SensConfig);
void EXTI_Enable(uint8_t InterruptName);
void EXTI_Disable(uint8_t InterruptName);

#endif