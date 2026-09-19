/**
 * @file      ADC_interface.h
 * @author    Abdulrahman Ali 
 * @author    ENG/Hesham Ahmed (Reviewer)
 * @brief     Interface of the ADC (Analog-to-Digital Converter) Driver.
 * @details   This file contains the function prototypes of ADC Driver
 * @version   1.0.0
 * @date      26 August 2026
 * @copyright Copyright (c) 2026, Gestell Company
 */



#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#include "ADC_Private.h"
#include<stdint.h>
#include"../../LIB/Definition.h"
#include"../../LIB/Bitmath.h"
#include"../Atmega32regmap.h"


void ADC_Init(uint8_t Voltage_Mode);
void ADC_Enable();
void ADC_Disable();
void ADC_Adjust(uint8_t Adjust_Direction);
void ADC_Channel(uint8_t Channel);
void ADC_StartConversion(uint8_t Mode);
void ADC_Prescaler(uint8_t Prescaler);
uint16_t ADC_ReadResult(); // For using the 10Bits



#endif /* ADC_INTERFACE_H_ */