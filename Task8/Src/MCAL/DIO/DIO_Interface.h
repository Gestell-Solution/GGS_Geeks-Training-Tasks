/**
 * @file DIO_Interface.h
 * @brief  Interface of the DIO Peripheral driver
 * @details This file contains function prototypes required to interface with DIO peripheral driver  
 * @version 0.1
 * @author Malak Mohammed (malak.mohammed.esmail@gmail.com) 
 * @date 17-09-2026
 * @copyright Copyright (c) 2026, Gestell Company
 */

#ifndef _DIO_INTERFACE_H
#define _DIO_INTERFACE_H

#include <stdint.h>
#include "../../Common/Definition.h"
#include "../../Common/Bitmath.h"
#include "../Atmega32regmap.h"
#include "DIO_Private.h"
#include "DIO_Config.h"

/**
 * @defgroup DIO_Driver DIO Driver
 * @brief Public interface of the DIO peripheral driver 
 * @{
 */

 /** @brief initializes a specific pin with the desired direction
  * @param GroupName group name of initialized pin 
  * @param PinNumber number of pin to be initialized 
  * @param DirState direction of pin (input or output)
  */
void DIO_InitPin(uint8_t GroupName, uint8_t PinNumber, uint8_t DirState);

 /** @brief writes a value to a specific pin 
  * @param GroupName group name of the pin 
  * @param PinNumber number of pin to write to
  * @param OutputValue value to be written [High or Low]
  */
void DIO_WritePin(uint8_t GroupName,uint8_t PinNumber,uint8_t OutputValue);

 /** @brief reads the value of a specific pin 
  * @param GroupName group name of the pin
  * @param PinNumber number of pin to read its value
  * @param PinState pointer to store the digital value of a pin
  */
void DIO_ReadPin(uint8_t GroupName,uint8_t PinNumber,uint8_t *PinState);

 /** @brief toggles a specific pin 
  * @param GroupName group name of the pin
  * @param PinNumber number of pin to toggle its output 
  */
void DIO_TogglePin(uint8_t GroupName,uint8_t PinNumber);

 /** @brief initializes all pins of a specific group
  * @param GroupName name of the group to be initialized 
  * @param DirState direction of group pins (input or output)
  */

void DIO_InitGroup(uint8_t GroupName,uint8_t DirState);

 /** @brief writes a specific output to all the pins of a group
  * @param GroupName group name to write to its pins 
  * @param OutputValue the digital output to be written to group pins(High or Low)
  */

void DIO_WriteGroup(uint8_t GroupName,uint8_t OutputValue );

 /** @brief reads the values of group pins
  * @param GroupName the name of the group to read its pin values 
  * @param InputStates Pointer to store the digital output of group pins
  */
void DIO_ReadGroup(uint8_t GroupName, uint8_t *InputStates);

/** @} */




#endif