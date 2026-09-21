/**
 * @file ADC_Interface.h
 * @author salma mohamed mahmoud fouad(salmafouadothman@gmail.com)
 * @brief adc driver for making it work
 * @details it let config the driver it read the data and enable interrupt
 * @version 0.1
 * @date 2026-09-21
 * @copyright Copyright (c) 2026
 */
#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#include<stdint.h>
#include "../../COMMON/Bitmath.h"
#include "../../COMMON/Definition.h"
#include"../Atmega32regmap.h"
#include"ADC_Private.h"
#include"ADC_Config.h"
#include"../../MCAL/DIO/DIO_Interface.h"
/**
 * @brief to initazle it 
 * @fn ADC_Init 
 * @param config you open the struct and choose things to be on off and other things to 
 * @note dont forget to put it 
 */
void ADC_Init(ADC_Config_t config);
/**
 * @brief choose the channel you are sending to
 * @fn ADC_ReadChannelPolling
 * @param Channel you choose from ADC_SINGLE_ENDED_ADC 0to 1
 * @return the data
 */
uint16_t ADC_ReadChannelPolling(uint8_t Channel);
/**
 * @brief start interrupt
 * @fn ADC_StartConvserionInterrupt
 * @param Channel you choose from ADC_SINGLE_ENDED_ADC 0to 1
 */
void ADC_StartConvserionInterrupt(uint8_t Channel);

#endif