/**
 * @file DIO_Interface.h
 * @brief DIO Interface public interface.
 * @details Declares the public APIs exposed by the module.
 * @version 1.0.0
 * @author Yousef
 * @date 2026-09-12
 * @copyright Copyright (c) 2026, Embedded Systems Project
 */

#ifndef _DIO_INTERFACE_H
#define _DIO_INTERFACE_H

#include<stdint.h>
#include"../../COMMON/Definition.h"
#include"../../COMMON/Bitmath.h"
#include"../Atmega32regmap.h"
#include"DIO_Private.h"

// select direction  initpin
/**
 * @defgroup DIO_INTERFACE_H_GROUP DIO Interface definitions
 * @brief Related dio interface definitions.
 * @{
 */
/**
 * @fn DIO_InitPin
 * @brief Initializes the direction of a single DIO pin.
 * @details Validates the requested port and pin, then configures the selected direction.
 * @param GroupName DIO port group identifier.
 * @param PinNumber DIO pin identifier.
 * @param DirState Pin direction selection.
 * @return void
 * @note Ensure module initialization is completed before calling dependent APIs.
 */
void DIO_InitPin(uint8_t GroupName,uint8_t PinNumber,uint8_t DirState);
// outputvalue    writepin
/**
 * @fn DIO_WritePin
 * @brief Writes a logic value to a single DIO pin.
 * @details Performs the operation required by the module while preserving the module interface.
 * @param GroupName DIO port group identifier.
 * @param PinNumber DIO pin identifier.
 * @param OutputValue Output value to write.
 * @return void
 * @note Ensure module initialization is completed before calling dependent APIs.
 */
void DIO_WritePin(uint8_t GroupName,uint8_t PinNumber,uint8_t OutputValue);
// read  readpin
// uint8_t DIO_ReadPin(uint8_t GroupName,uint8_t PinNumber);
/**
 * @fn DIO_ReadPin
 * @brief Reads the logic state of a single DIO pin.
 * @details Validates the requested pin and stores its input state through the supplied pointer.
 * @param GroupName DIO port group identifier.
 * @param PinNumber DIO pin identifier.
 * @param PinState DIO pin identifier.
 * @return void
 * @note Ensure module initialization is completed before calling dependent APIs.
 */
void DIO_ReadPin(uint8_t GroupName,uint8_t PinNumber,uint8_t *PinState);
/**
 * @fn DIO_TogglePin
 * @brief Toggles the output state of a single DIO pin.
 * @details Performs the operation required by the module while preserving the module interface.
 * @param GroupName DIO port group identifier.
 * @param PinNumber DIO pin identifier.
 * @return void
 * @note Ensure module initialization is completed before calling dependent APIs.
 */
void DIO_TogglePin(uint8_t GroupName,uint8_t PinNumber);

// select direction  initGroup
/**
 * @fn DIO_InitGroup
 * @brief Initializes the direction of a complete DIO port.
 * @details Performs the operation required by the module while preserving the module interface.
 * @param GroupName DIO port group identifier.
 * @param DirState Pin direction selection.
 * @return void
 * @note Ensure module initialization is completed before calling dependent APIs.
 */
void DIO_InitGroup(uint8_t GroupName,uint8_t DirState);
// outputvalue    writeGroup
/**
 * @fn DIO_WriteGroup
 * @brief Writes a logic value to a complete DIO port.
 * @details Performs the operation required by the module while preserving the module interface.
 * @param GroupName DIO port group identifier.
 * @param OutputValue Output value to write.
 * @return void
 * @note Ensure module initialization is completed before calling dependent APIs.
 */
void DIO_WriteGroup(uint8_t GroupName,uint8_t OutputValue);
// read  readGroup
/**
 * @fn DIO_ReadGroup
 * @brief Reads the logic state of a complete DIO port.
 * @details Performs the operation required by the module while preserving the module interface.
 * @param GroupName DIO port group identifier.
 * @param InputStates State value associated with the operation.
 * @return void
 * @note Ensure module initialization is completed before calling dependent APIs.
 */
void DIO_ReadGroup(uint8_t GroupName,uint8_t * InputStates);

/** @} */

#endif
