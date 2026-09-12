#ifndef _SENSOR_INTERFACE_H
#define _SENSOR_INTERFACE_H

#include"../../MCAL/DIO/DIO_Interface.h"

void SENSOR_Init(uint8_t group ,uint8_t pin);
void SENSOR_GetReading(uint8_t group ,uint8_t pin,uint8_t *sensorState);

#endif