#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

#include<stdint.h>
#include<util/delay.h>
#include "../../Common/Bitmath.h"
#include "../../Common/Defination.h"
#include "../AtmegaReg16.h"

#include"DIO_Private.h"
#include "DIO_Config.h"


//Slect Directioon init Pin
void DIO_InitPin(uint8_t GroupName, uint8_t PinNummber, uint8_t DirState);

//outputvalue writepin
void DIO_WritePin(uint8_t GroupName, uint8_t PinNummber ,uint8_t OutputValue);

//InputValue ReadPin  
void DIO_ReadPin(uint8_t GroupName, uint8_t PinNummber ,uint8_t *PinState);



//Slect Directioon init Group
void DIO_InitGroup(uint8_t GroupName ,uint8_t DirState );//From 0x00 To 0xFF

//outputvalue writeGroup
void DIO_WriteGroup(uint8_t GroupName ,uint8_t OutputValue );

//InputValue ReadPin
void DIO_ReadGroup(uint8_t GroupName,uint8_t *InputStates);

//Toggle Pin
void DIO_TogglePin(uint8_t GroupName, uint8_t PinNummber);




#endif