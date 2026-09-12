/**
 * @file ADC_Interface.h
 * @brief ADC Interface public interface.
 * @details Declares the public APIs exposed by the module.
 * @version 1.0.0
 * @author Yousef
 * @date 2026-09-12
 * @copyright Copyright (c) 2026, Embedded Systems Project
 */

#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H

#include <stdint.h>

#include "../../COMMON/Definition.h"
#include "../../COMMON/Bitmath.h"
#include "../Atmega16regmap.h"
#include "ADC_Private.h"
#include "ADC_Config.h"

/**
 * @defgroup ADC_INTERFACE_H_GROUP ADC Interface definitions
 * @brief Related adc interface definitions.
 * @{
 */
/**
 * @fn ADC_Init
 * @brief Initializes the ADC peripheral.
 * @details Performs the operation required by the module while preserving the module interface.
 * @param Configuration Module configuration structure.
 * @return void
 * @note Ensure module initialization is completed before calling dependent APIs.
 */
void ADC_Init(Adc_Config_t Configuration);
/**
 * @fn ADC_ReadChannelPolling
 * @brief Reads an ADC channel using polling.
 * @details Performs the operation required by the module while preserving the module interface.
 * @param Channel Input parameter.
 * @param Timeout Input parameter.
 * @return uint16_t Return value of the operation.
 * @retval 0 Operation completed successfully when a status code is used.
 * @retval Non-zero Module-specific error or status code when applicable.
 * @note Ensure module initialization is completed before calling dependent APIs.
 */
uint16_t ADC_ReadChannelPolling(uint8_t Channel, uint32_t Timeout);
/**
 * @fn ADC_StartConversionInterrupt
 * @brief Starts an ADC conversion using interrupt mode.
 * @details Performs the operation required by the module while preserving the module interface.
 * @param Channel Input parameter.
 * @return void
 * @note Ensure module initialization is completed before calling dependent APIs.
 */
void ADC_StartConversionInterrupt(uint8_t Channel);
/**
 * @fn ADC_SetCallBack
 * @brief Registers the ADC interrupt callback function.
 * @details Performs the operation required by the module while preserving the module interface.
 * @param CopyFunc Callback function invoked by the module.
 * @return void
 * @note Ensure module initialization is completed before calling dependent APIs.
 */
void ADC_SetCallBack(void (*Copy_pvCallBack)(uint16_t));

/** @} */

#endif
