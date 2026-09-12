#ifndef _EXTI_INTERFACE_H
#define _EXTI_INTERFACE_H

#include <stdint.h>
#include "../../COMMON/Bitmath.h"
#include "../../COMMON/Definition.h"
#include "../Atmega32regmap.h"
#include "EXTI_Private.h"
#include "EXTI_Config.h"

/**
 * @fn       EXTI_Init
 * @brief    Select the Configuration of Sens contorl for the Specific Interrupt 
 * @details
 * @param InterruptName  this Parameter can on of this following option (Exti_Interrupt0,Exti_Interrupt1,Exti_Interrupt2)
 * @param SensConfig 
 */
void EXTI_Init(uint8_t InterruptName,uint8_t SensConfig);
void EXTI_Enable(uint8_t InterruptName);
void EXTI_Disable(uint8_t InterruptName);




#endif 