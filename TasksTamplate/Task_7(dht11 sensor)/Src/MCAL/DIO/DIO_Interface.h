#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#include <stdint.h>
#include "../../COMMON/Definition.h"
#include "../../COMMON/Bitmath.h"
#include "../Atmega32regmap.h"
#include "DIO_Private.h"

void DIO_InitPin(uint8_t GroupName, uint8_t PinNumber, uint8_t DirState);
void DIO_WritePin(uint8_t GroupName, uint8_t PinNumber, uint8_t OutputValue);
void DIO_ReadPin(uint8_t GroupName, uint8_t PinNumber, uint8_t *PinState);
void DIO_InitGroup(uint8_t GroupName, uint8_t DirState);
void DIO_WriteGroup(uint8_t GroupName, uint8_t OutputValue);
void DIO_ReadGroup(uint8_t GroupName, uint8_t *InputStates);
void DIO_Toggle(uint8_t GroupName, uint8_t PinNumber);

#endif /* DIO_INTERFACE_H_ */
