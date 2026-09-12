/**
 * @file Timer0_Interface.h
 * @brief Timer0 Interface public interface.
 * @details Declares the public APIs exposed by the module.
 * @version 1.0.0
 * @author Yousef
 * @date 2026-09-12
 * @copyright Copyright (c) 2026, Embedded Systems Project
 */

#ifndef _TIMER0_INTERFACE_H
#define _TIMER0_INTERFACE_H
#include  <stdint.h>
#include "../../COMMON/Bitmath.h"
#include "../../COMMON/Definition.h"
#include "../Atmega32regmap.h"

#include "Timer0_Private.h"
#include "Timer0_Config.h"


/**
 * @defgroup TIMER0_INTERFACE_H_GROUP Timer0 Interface definitions
 * @brief Related timer0 interface definitions.
 * @{
 */
/**
 * @fn TIMER0_Init
 * @brief Executes the init operation for Timer0.
 * @details Performs the operation required by the module while preserving the module interface.
 * @param Config Module configuration structure.
 * @return void
 * @note Ensure module initialization is completed before calling dependent APIs.
 */
void TIMER0_Init(Timer0_Config_t Config);

/**
 * @fn TIMER0_Start
 * @brief Executes the start operation for Timer0.
 * @details Performs the operation required by the module while preserving the module interface.
 * @param ClockSelectValue Value to be written or configured.
 * @return void
 * @note Ensure module initialization is completed before calling dependent APIs.
 */
void TIMER0_Start(uint8_t ClockSelectValue);

/**
 * @fn TIMER0_Stop
 * @brief Executes the stop operation for Timer0.
 * @details Performs the operation required by the module while preserving the module interface.
 * @return void
 * @note Ensure module initialization is completed before calling dependent APIs.
 */
void TIMER0_Stop(void);
/**
 * @fn TIMER0_SetPreload
 * @brief Executes the setpreload operation for Timer0.
 * @details Performs the operation required by the module while preserving the module interface.
 * @param PreloadValue Value to be written or configured.
 * @return void
 * @note Ensure module initialization is completed before calling dependent APIs.
 */
void TIMER0_SetPreload(uint8_t PreloadValue);
/**
 * @fn TIMER0_SetCompare
 * @brief Executes the setcompare operation for Timer0.
 * @details Performs the operation required by the module while preserving the module interface.
 * @param CompareValue Value to be written or configured.
 * @return void
 * @note Ensure module initialization is completed before calling dependent APIs.
 */
void TIMER0_SetCompare(uint8_t CompareValue);

/**
 * @fn TIMER0_SetCallBackFunction
 * @brief Executes the setcallbackfunction operation for Timer0.
 * @details Performs the operation required by the module while preserving the module interface.
 * @param TimerInterruptType Input parameter.
 * @param CopyFunc Callback function invoked by the module.
 * @return void
 * @note Ensure module initialization is completed before calling dependent APIs.
 */
void TIMER0_SetCallBackFunction(uint8_t TimerInterruptType, void (*PF)(void));

// comparevalue=2^n*DutyCycle
/**
 * @fn TIMER0_SetPWMDutyCycle
 * @brief Executes the setpwmdutycycle operation for Timer0.
 * @details Performs the operation required by the module while preserving the module interface.
 * @param DutyCyclePercentage Input parameter.
 * @return void
 * @note Ensure module initialization is completed before calling dependent APIs.
 */
void TIMER0_SetPWMDutyCycle(uint8_t DutyCyclePercentage);
/** @} */

#endif
