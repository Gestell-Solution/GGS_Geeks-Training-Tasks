#ifndef _DIO_INTERFACE_H
#define _DIO_INTERFACE_H
/**
 * @file DIO_Interface.h
 * @author salma mohamed mahmoud fouad(salmafouadothman@gmail.com)
 * @brief driver to control pin and groups
 * @details here we can control the state of pin as input to output 
 *          and give it high or low we read the pin we toggle it and
 *          we do the same thing for group 
 * @version 0.1
 * @date 2026-09-12
 * @copyright Copyright (c) 2026
 */
#include<stdint.h>
#include"../../COMMON/Definition.h"
#include"../../COMMON/Bitmath.h"
#include"../Atmega32regmap.h"
#include"DIO_Private.h"
/**
 * @brief it initialize one pin at a time 
 * @fn DIO_InitPin
 * @param GroupName choose a group
 * @param PinNumber choose a pin 
 * @param DirState choose if the pin is input or output
 */
void DIO_InitPin(uint8_t GroupName,uint8_t PinNumber,uint8_t DirState);
/**
 * @brief  it write the pin to either high or low 
 * @fn DIO_WritePin
 * @param GroupName choose a group
 * @param PinNumber  choose a pin 
 * @param OutputValue choos ehigh or low
 */
void DIO_WritePin(uint8_t GroupName,uint8_t PinNumber,uint8_t OutputValue);
/**
 * @brief read the pin 
 * @fn DIO_ReadPin
 * @param GroupName choose a group
 * @param PinNumber  choose a pin 
 * @param PinState   a pointer for saving the readed pin state
 */
void DIO_ReadPin(uint8_t GroupName,uint8_t PinNumber,uint8_t *PinState);
/**
 * @brief to toggle the bin
 * @fn DIO_TogglePin
 * @param GroupName choose a group
 * @param PinNumber  choose a pin 
 */
void DIO_TogglePin(uint8_t GroupName,uint8_t PinNumber);
/**
 * @brief it initialize the whole group
 * @fn DIO_InitGroup
 * @param GroupName choose a group
 * @param DirState choose if the pin is input or output
 */
void DIO_InitGroup(uint8_t GroupName,uint8_t DirState);
/**
 * @brief it write the whole group to either high or low 
 * @fn DIO_WriteGroup
 * @param GroupName choose a group
 * @param OutputValue choos ehigh or low
 */
void DIO_WriteGroup(uint8_t GroupName,uint8_t OutputValue);
/**
 * @brief read the group
 * @fn DIO_ReadGroup
 * @param GroupName choose a group
 * @param InputStates a pointer for saving the readed pin state
 */
void DIO_ReadGroup(uint8_t GroupName,uint8_t * InputStates);

#endif