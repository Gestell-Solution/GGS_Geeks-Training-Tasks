/**
 * @file DIO_Interface.h
 * @brief DIO public interface.
 * @details Declares the public APIs used to configure, read and write the
 *          digital I/O ports (A..D) of the ATmega32.
 * @version 1.1.0
 * @author Yousef Mohamed
 * @date 2026-09-24
 * @copyright Copyright (c) 2026, Gestell Company. All rights reserved.
 */

#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

#include <stdint.h>

#include "../../COMMON/Definition.h"
#include "../../COMMON/Bitmath.h"
#include "../Atmega32regmap.h"
#include "DIO_Private.h"
#include "DIO_Config.h"

void DIO_InitPin(uint8_t GroupName, uint8_t PinNumber, uint8_t DirState);

void DIO_WritePin(uint8_t GroupName, uint8_t PinNumber, uint8_t OutputValue);

void DIO_ReadPin(uint8_t GroupName, uint8_t PinNumber, uint8_t *PinState);

void DIO_TogglePin(uint8_t GroupName, uint8_t PinNumber);

void DIO_InitGroup(uint8_t GroupName, uint8_t DirState);

void DIO_WriteGroup(uint8_t GroupName, uint8_t OutputValue);

void DIO_ReadGroup(uint8_t GroupName, uint8_t *InputStates);

#endif 
