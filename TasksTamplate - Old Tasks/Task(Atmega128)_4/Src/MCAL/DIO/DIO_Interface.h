/**
 * @file      DIO_Interface.h
 * @author    Abdulrahman Ali 
 * @author    ENG/Hesham Ahmed (Reviewer)
 * @brief     Interface of the DIO Driver.
 * @details   This file contains the function prototypes Of DIO driver
 * @version   1.0.0
 * @date      26 August 2026
 * @copyright Copyright (c) 2026, Gestell Company
 */






#ifndef _DIO_INTERFACE_H
#define _DIO_INTERFACE_H

#include<stdint.h>
#include"../../LIB/Definition.h"
#include"../../LIB/Bitmath.h"
#include"../Atmega128regmap.h"
#include"DIO_Private.h"

// select direction  initpin 
void DIO_InitPin(uint8_t GroupName,uint8_t PinNumber,uint8_t DirState);
// outputvalue    writepin  
void DIO_WritePin(uint8_t GroupName,uint8_t PinNumber,uint8_t OutputValue);
// read  readpin 
// uint8_t DIO_ReadPin(uint8_t GroupName,uint8_t PinNumber);
void DIO_ReadPin(uint8_t GroupName,uint8_t PinNumber,uint8_t *PinState);

// select direction  initGroup 
void DIO_InitGroup(uint8_t GroupName,uint8_t DirState);
// outputvalue    writeGroup   
void DIO_WriteGroup(uint8_t GroupName,uint8_t OutputValue);
// read  readGroup  
void DIO_ReadGroup(uint8_t GroupName,uint8_t * InputStates);

void DIO_Toggle(uint8_t GroupName , uint8_t PinNumber);

#endif