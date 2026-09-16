/**
 * @file BT_Interface.h
 * @brief Bluetooth driver interface for the ATmega32.
 * @details This file contains the public function prototypes and data structures
 *          for interacting with the Bluetooth driver.
 *
 * 
 * @version 2.1.0
 * @author Ali Sotohy <email: alielsotohy2006@gmail.com>
 * @date 2026-09-14
 * @copyright Copyright (c) 2026, Gestell Company
 */
#ifndef BT_INTERFACE_H
#define BT_INTERFACE_H

#include <stdint.h>
#include "CH_05_Config.h"
#include "CH_05_Private.h"
#include "../../MCAL/Uart/Uart_Interface.h"

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
void Bluetooth_ReceiveString(uint8_t* buffer, uint16_t MaxLength, uint8_t terminator);

 /** 
  * @brief Registers a callback function for asynchrnous receive events
  * @param callback pointer to the callback function 
  */
void Bluetooth_SetReceiveCallback(void (*callback)(uint16_t));




#endif /* BT_INTERFACE_H */