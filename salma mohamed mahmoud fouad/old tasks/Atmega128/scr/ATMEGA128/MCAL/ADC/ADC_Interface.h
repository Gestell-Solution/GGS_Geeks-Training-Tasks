#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#include<stdint.h>
#include "../../COMMEN/Bitmath.h"
#include "../../COMMEN/Definition.h"
#include "../ATMEGA128_REG.h"
#include"ADC_Private.h"
#include"ADC_Config.h"
#include"../../MCAL/DIO/DIO_Interface.h"

void ADC_Init(ADC_Config_t config);
uint16_t ADC_ReadChannelPolling(uint8_t Channel);
void ADC_StartConvserionInterrupt(uint8_t Channel);

#endif