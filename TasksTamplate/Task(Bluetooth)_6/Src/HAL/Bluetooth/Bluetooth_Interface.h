/**
 * @file Bluetooth_Interface.h
 * @brief This file contains the interface functions for for the BLUETOOTH module.
 * @author Developer: Abdulrahman Ali 
 * @author Reviewer : Eng/Hesham Ahmed
 * @date 9/13/2026
 * @copyright Copyright (c) 2026 , Gestell Company. All rights reserved.
 * @version 1.0.0
 */

#ifndef BLUETOOTH_INTERFACE_H
#define BLUETOOTH_INTERFACE_H
#include <stdint.h>
#include "Bluetooth_Private.h"
#include "Bluetooth_Config.h"



/**
 * @brief Initializes the HC-05 Bluetooth module.
 *
 * @return void
 */
void Bluetooth_Init(void);

/**
 * @brief Sends one byte through the HC-05 module.
 *
 * @param Data Byte to be transmitted.
 *
 * @return void
 */
void Bluetooth_SendByte(uint8_t Data);

/**
 * @brief Receives one byte from the HC-05 using polling with timeout.
 *
 * @param Data Pointer to store the received byte.
 * @param Timeout Maximum polling count.
 *
 * @return UART_OK if data is received, otherwise UART_TIMEOUT.
 */
uint8_t Bluetooth_ReceiveByte(uint8_t *Data, uint32_t Timeout);

/**
 * @brief Sends a string through the HC-05 module.
 *
 * @param String Pointer to the string to be transmitted.
 *
 * @return void
 */
void Bluetooth_SendString(uint8_t *String);

/**
 * @brief Receive a string from HC-05 using polling with timeout
 * @param String: Pointer to store the received string
 * @return void
 */
void Bluetooth_ReceiveString(uint8_t *String , uint8_t Terminator);


#endif /* BLUETOOTH_INTERFACE_H */