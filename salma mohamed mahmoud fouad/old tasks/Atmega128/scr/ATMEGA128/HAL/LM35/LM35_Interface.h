#ifndef LM35_INTEFACE_H_
#define LM35_INTEFACE_H_

#include"../../MCAL/ADC/ADC_Interface.h"
#include"../../MCAL/DIO/DIO_Interface.h"
#include"LM35_Config.h"
#include <util/delay.h>


void LM35_Init();
uint8_t LM35_Read();

#endif