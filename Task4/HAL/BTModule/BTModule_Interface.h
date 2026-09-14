#ifndef _BTMODULE_INTERFACE_H
#define _BTMODULE_INTERFACE_H

#include <stdint.h>

void Bluetooth_Init(void);
void Bluetooth_SendChar(uint8_t data);
uint8_t Bluetooth_ReceiveChar(void);
void Bluetooth_SendString(uint8_t* string);
void Bluetooth_ReceiveString(uint8_t* buffer, uint8_t terminator);
void Bluetooth_SetReceiveCallback(void (*callback)(uint16_t));

#endif