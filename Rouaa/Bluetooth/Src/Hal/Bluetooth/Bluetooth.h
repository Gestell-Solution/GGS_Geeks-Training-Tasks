/*
 * @file         Bluetooth.h
 * @brief        Bluetooth driver interface for HC-05 module.
 * @details      Provides basic Bluetooth communication functions.
 * @copyright    Copyright (c) 2026 Gestell-Co. All rights reserved.
 * @author       Rouaa Ayman (Rouaaayman2602@gmail.com)
 * @version      0.1
 * @date         2026-09-14
 * 
 * @copyright    Copyright (c) 2026
 * 
 */



#ifndef BLUETOOTH_H
#define BLUETOOTH_H

#include "STD_Types.h"
/**
 * @brief Bluetooth driver status.
 */
typedef enum
{
    BLUETOOTH_OK,
    BLUETOOTH_TIMEOUT
}
Bluetooth_StatusType;
/**
 * @brief Initializes the HC-05 Bluetooth module.
 */
void Bluetooth_Init(void);

/**
 * @brief Receives one byte from the HC-05 module with timeout.
 * @param data Pointer to the received byte.
 * @param timeout Maximum waiting time in milliseconds.
 * @return BLUETOOTH_OK if data is received.
 * @return BLUETOOTH_TIMEOUT if timeout expires.
 */
Bluetooth_StatusType Bluetooth_ReceiveByte(u8 *data,  u32 timeout);
/**
 * @brief Sends one byte through the HC-05 module.
 * @param data Byte to be transmitted.
 */
void Bluetooth_SendByte(u8 data);

#endif