#ifndef _BUZZER_INTERFACE_H
#define _BUZZER_INTERFACE_H
#include<stdint.h>
#include "../../MCAL/DIO/DIO_Interface.h"

void Buzzer_Init(uint8_t Group_name ,uint8_t Pin_number);
void Buzzer_On(uint8_t Group_name ,uint8_t Pin_number);
void Buzzer_Off(uint8_t Group_name ,uint8_t Pin_number);
void Buzzer_toggle(uint8_t Group_name ,uint8_t Pin_number);

#endif
