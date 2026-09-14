#ifndef EXTI_INTERFACE_H 
#define EXTI_INTERFACE_H 

#include <stdint.h>
#include"EXTI_Config.h"
#include "EXTI_Private.h"
#include "../Atmega16regmap.h"
#include "../../COMMON/Definition.h"
#include "../../COMMON/Bitmath.h"

void EXTI_Init(uint8_t InterruptName,uint8_t SensConfig);
void EXTI_Enable(uint8_t InterruptName);
void  EXTI_Disable(uint8_t InterruptName);




#endif