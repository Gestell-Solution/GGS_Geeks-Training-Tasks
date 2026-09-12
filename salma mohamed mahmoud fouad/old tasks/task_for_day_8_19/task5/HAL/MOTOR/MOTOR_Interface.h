#ifndef _MOTOR_INTERFACE_H
#define _MOTOR_INTERFACE_H

#include"MOTOR_Config.h"
#include"MOTOR_Private.h"
#include"../../MCAL/DIO/DIO_Interface.h"
#include"../../MCAL/Timer0/Timer0_Interface.h"

void MOTOR_Init(uint8_t GROUP ,uint8_t PIN1,uint8_t PIN2);
void MOTOR_Mode(uint8_t motor_mode);
void MOTOR_Speed(uint8_t motor_speed);


#endif