#ifndef ULTS_INTERFACE_H
#define ULTS_INTERFACE_H

#include "../../MCAL/DIO/DIO_Interface.h"
#include"ULTS_Config.h"
#include"ULTRS_Private.h"
#include"../../MCAL/TIMER1/TIMER1_Interface.h"
#include <util/delay.h>
#include"../../MCAL/GIE/GIE_Interface.h"

void ULTS_Init(void);

uint16_t ULTS_GetDistance(void);
void ULTS_OverflowISR(void);
/* ISR Callback */
void ULTS_CaptureISR(void);

#endif