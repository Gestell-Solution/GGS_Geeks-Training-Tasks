#ifndef _TIMER1_INTERFACE_H
#define _TIMER1_INTERFACE_H
#include  <stdint.h>
#include "../../COMMON/Bitmath.h"
#include "../../COMMON/Definition.h"
#include "../Atmega32regmap.h"

#include "TIMER1_Private.h"
#include "TIMER1_Config.h"


void TIMER1_Init(Timer1_config_t config);
void TIMER1_Start(uint8_t clockValue);
void TIMER1_Stop(void);
void TIMER1_set_preloadValue(uint16_t preloadvalue);
void TIMER1_comparevalue(uint16_t comparevalue);
void TIMER1_SetpwmDutyCycle(uint8_t dutyCycle);
void TIMER1_captureEvent(uint16_t captureValue);
void TIMER1_SETcallBackFunction(uint8_t timerInterruptType,void (*PF)(void));

#endif