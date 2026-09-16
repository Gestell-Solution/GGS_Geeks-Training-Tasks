#ifndef ADXL355_INTERFACE_H_
#define ADXL355_INTERFACE_H_

#include"../../MCAL/UART/UART_Interface.h"
#include"../../MCAL/ADC/ADC_Interface.h"
#include"../../MCAL/DIO/DIO_Interface.h"
#include"ADXL335_Config.h"

void ADXL355_Init();
void ADXL355_PrintData();

#endif