#ifndef ADC_INTERFACE_H 
#define ADC_INTERFACE_H 

#include <stdint.h>
#include "../Atmega32regmap.h"
#include "../../Common/Bitmath.h"
#include "../../Common/Definition.h"
#include "ADC_Private.h"
#include "ADC_Config.h"

void ADC_Init(Adc_Config_t  Configuration);
uint16_t ADC_ReadChannelPolling(uint8_t Channel);
void ADC_StartConvserionInterrupt(uint8_t Channel);
void ADC_SetCallback(void (*CopyFuncPtr)(uint16_t));





#endif