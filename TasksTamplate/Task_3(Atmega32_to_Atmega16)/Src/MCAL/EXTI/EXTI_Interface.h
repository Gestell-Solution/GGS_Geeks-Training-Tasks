/**
 * @file EXTI_Interface.h
 * @brief EXTI Interface public interface.
 * @details Declares the public APIs exposed by the module.
 * @version 1.0.0
 * @author Yousef
 * @date 2026-09-12
 * @copyright Copyright (c) 2026, Embedded Systems Project
 */

#ifndef _EXTI_INTERFACE_H
#define _EXTI_INTERFACE_H

#include <stdint.h>
#include "../../COMMON/Bitmath.h"
#include "../../COMMON/Definition.h"
#include "../Atmega16regmap.h"
#include "EXTI_Private.h"
#include "EXTI_Config.h"

/**
 * @defgroup EXTI_INTERFACE_H_GROUP EXTI Interface definitions
 * @brief Related exti interface definitions.
 * @{
 */
/**
 * @fn       EXTI_Init
 * @brief    Select the Configuration of Sens contorl for the Specific Interrupt
 * @details
 * @param InterruptName  this Parameter can on of this following option (Exti_Interrupt0,Exti_Interrupt1,Exti_Interrupt2)
 * @param SensConfig
 */
/**
 * @fn EXTI_Init
 * @brief Executes the exti init operation.
 * @details Performs the operation required by the module while preserving the module interface.
 * @param InterruptName Input parameter.
 * @param SensConfig Module configuration structure.
 * @return void
 * @note Ensure module initialization is completed before calling dependent APIs.
 */
void EXTI_Init(uint8_t InterruptName,uint8_t SensConfig);
/**
 * @fn EXTI_Enable
 * @brief Executes the exti enable operation.
 * @details Performs the operation required by the module while preserving the module interface.
 * @param InterruptName Input parameter.
 * @return void
 * @note Ensure module initialization is completed before calling dependent APIs.
 */
void EXTI_Enable(uint8_t InterruptName);
/**
 * @fn EXTI_Disable
 * @brief Executes the exti disable operation.
 * @details Performs the operation required by the module while preserving the module interface.
 * @param InterruptName Input parameter.
 * @return void
 * @note Ensure module initialization is completed before calling dependent APIs.
 */
void EXTI_Disable(uint8_t InterruptName);




/** @} */

#endif
