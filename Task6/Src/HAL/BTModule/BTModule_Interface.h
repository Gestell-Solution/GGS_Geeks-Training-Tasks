/**
 * @file BTModule_Interface.h
 * @brief  Interface of the bluetooth module driver 
 * @details This file contains the protypes of the functions required for the implementation of bluethooth module
 * @version 0.1
 * @author Malak Mohammed (malak.mohammed.esmail@gmail.com) 
 * @date 14-09-2026
 * @copyright Copyright (c) 2026, Gestell Company
 */



#ifndef _BTMODULE_INTERFACE_H
#define _BTMODULE_INTERFACE_H

#include "BTModule_Config.h"
#include <stdint.h>

/** 
 * @defgroup BTModule_Driver Bluetooth Module Driver
 * @brief Public interface of the Bluetooth Module driver 
 * @{ 
 */

 /** 
  * @brief Initializes the Bluetooth module and its underlying UART communication
  */
void Bluetooth_Init(void);

 /** 
  * @brief sends a single character via Bluetooth
  * @param data the character byte to be sent
  */
void Bluetooth_SendChar(uint8_t data);

 /** 
  * @brief receives a single character via Bluetooth
  * @return the received characetr byte
  */
uint8_t Bluetooth_ReceiveChar(void);

 /** 
  * @brief sends a string via Bluetooth
  * @param string the string to be sent
  */
void Bluetooth_SendString(uint8_t* string);

 /** 
  * @brief receives a string via Bluetooth until terminator character is reached
  * @param buffer pointer to the recieved string storage buffer 
  * @param terminator the character that signifies the end of the received string
  */
void Bluetooth_ReceiveString(uint8_t* buffer, uint8_t terminator);

 /** 
  * @brief Registers a callback function for asynchrnous receive events
  * @param callback pointer to the callback function 
  */
void Bluetooth_SetReceiveCallback(void (*callback)(uint16_t));

/** @} */

#endif