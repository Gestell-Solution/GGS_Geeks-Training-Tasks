#ifndef RFID_INTERFACE_H
#define RFID_INTERFACE_H
#include <stdint.h>
#include "RFID_Private.h"
#include "RFID_Config.h"

void RFID_Init();

void RFID_WriteRegister(uint8_t Address, uint8_t Data);

uint8_t RFID_ReadRegister(uint8_t Address);

uint8_t RFID_GetUID(uint8_t *UID);




#endif