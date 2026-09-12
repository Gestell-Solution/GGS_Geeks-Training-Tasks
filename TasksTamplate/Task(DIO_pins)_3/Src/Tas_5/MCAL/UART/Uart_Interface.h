#ifndef _UART_INTERFACE_H
#define _UART_INTERFACE_H

#include <stdint.h>

#include "../../LIB/Definition.h"
#include "../../LIB/Bitmath.h"
#include "../Atmega32regmap.h"

#include "UART_Private.h"
#include "UART_Config.h"

/*
    1- Mode Select -> Asynch / Synch 
    2- Stop Bit not -> 1Stop / 2 Stop 
    3- Parity Check status -> even / odd / disable 
    4- 
*/


void UART_Init(Uart_Config_t Uart_Config);
void UART_SendBytePolling(uint16_t Data);
uint16_t UART_ReceiveBytePolling();
void UART_SendStringPolling(uint8_t* String);
void UART_ReceiveStringPolling(uint8_t* Buffer, uint8_t Terminator);


uint8_t UART_ReceiveByteInterrupt(uint16_t *Data); // interrupt receive  Ring Buffer








void UART_EnableRXInterrupt();
void UART_EnableTXInterrupt();
void UART_EnableREInterrupt();

void UART_DisableRXInterrupt();
void UART_DisableTXInterrupt();
void UART_DisableREInterrupt();


void UART_EnableRX();
void UART_EnableTX();
void UART_DisableRX();
void UART_DisableTX();


void UART_SendByteAsync(uint16_t Data);
void UART_SetRXCallback(void (*Callback)(uint16_t));
void UART_SetTXCallback(void (*Callback)(void));
void UART_SetRECallback(void (*Callback)(void));



#endif