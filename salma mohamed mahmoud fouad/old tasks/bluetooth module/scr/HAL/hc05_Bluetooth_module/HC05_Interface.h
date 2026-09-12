#ifndef HC05_INTERFACE_H_
#define HC05_INTERFACE_H_

#include <util/delay.h>
#include "../../MCAL/UART/UART_Interface.h"
#include "../../MCAL/DIO/DIO_Interface.h"

void HC05_Init();
uint16_t HC05_Get_Data();

#endif