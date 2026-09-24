/**
 * @file ADC_Interface.h
 * @brief  Interface of ADC Peripheral driver
 * @details This file contains function prototypes required to interface with ADC Peripheral driver  
 * @version 0.1
 * @author Malak Mohammed (malak.mohammed.esmail@gmail.com) 
 * @date 21-09-2026
 * @copyright Copyright (c) 2026, Gestell Company
 */

#ifndef ADC_INTERFACE_H 
#define ADC_INTERFACE_H 

#include <stdint.h>
#include "../Atmega32regmap.h"
#include "../../Common/Bitmath.h"
#include "../../Common/Definition.h"
#include "ADC_Private.h"
#include "ADC_Config.h"

/** @brief Initializes and configures ADC Peripheral
 * @param Configuration Configuration Parameters of the ADC 
 */
void ADC_Init(Adc_Config_t  Configuration);

/** @brief Reads an analog signal from specified ADC Channel using polling method 
 * @param Channel the channel carrying the signal to be converted 
 * @return Digital ADC Conversion Result
 */
uint16_t ADC_ReadChannelPolling(uint8_t Channel);

/** @brief selects and ADC channel and starts conversion
 * @param Channel ADC channel to be converted 
 */
void ADC_StartConvserionInterrupt(uint8_t Channel);

/** @brief Sets the callback function for ADC conversion completion
 * @param CopyFuncPtr pointer to the callback function 
 */
void ADC_SetCallback(void (*CopyFuncPtr)(uint16_t));


#endif