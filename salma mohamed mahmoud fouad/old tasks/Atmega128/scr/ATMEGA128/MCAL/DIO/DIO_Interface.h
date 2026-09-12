#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

#include"../ATMEGA128_REG.h"
#include"DIO_Private.h"
#include"../../COMMEN/Bitmath.h"
#include"../../COMMEN/Definition.h"

//dirstate = output and input 
void DIO_InitPin(uint8_t GroupName,uint8_t PinNumber,uint8_t DirState);
void DIO_InitGroup(uint8_t GroupName,uint8_t DirState);

// outputvalue =   high or low 
void DIO_WritePin(uint8_t GroupName,uint8_t PinNumber,uint8_t OutputValue);
void DIO_WriteGroup(uint8_t GroupName,uint8_t OutputValue);

void DIO_ReadPin(uint8_t GroupName,uint8_t PinNumber,uint8_t *PinState);
void DIO_ReadGroup(uint8_t GroupName,uint8_t * InputStates);
//toggle
void DIO_TogglePin(uint8_t GroupName,uint8_t PinNumber);

#endif