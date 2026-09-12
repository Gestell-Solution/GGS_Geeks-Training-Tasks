#ifndef ULTS_INTERFACE_H
#define ULTS_INTERFACE_H

#include"../LCD/LCD_Interface.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include"ULTS_Config.h"
#include"ULTRS_Private.h"
#include"../../MCAL/TIMER1/TIMER1_Interface.h"
#include"../LCD/LCD_Interface.h"
#include <util/delay.h>
#include"../../MCAL/GIE/GIE_Interface.h"

void ULTS_Init();
void ULTS_ISR();
uint16_t ULTS_Start();
void timer1_captureFlag();

#endif