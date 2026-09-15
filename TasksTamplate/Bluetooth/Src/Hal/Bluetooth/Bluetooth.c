
/*
 * @file         Bluetooth.c
 * @brief        Bluetooth driver implementation for HC-05 module.
 * @details      Provides Bluetooth communication using USART with polling and timeout.
 * @copyright    Copyright (c) 2026 Gestell-Co. All rights reserved.
 * @author       Rouaa Ayman (Rouaaayman2602@gmail.com)
 * @version      0.1
 * @date         2026-09-14
 *
 * @copyright    Copyright (c) 2026
 *
 */

#include "Bluetooth.h"
#include "USART.h"
#include "Timer.h"

/**
 * @brief Initializes the HC-05 Bluetooth module.
 * @details Configures the USART interface with a baud rate of 9600 bps.
 */
void Bluetooth_Init(void)
{
    USART_Init(9600U);
}

/**
 * @brief Sends one byte through the HC-05 module.
 * @param data Byte to be transmitted.
 */
void Bluetooth_SendByte(u8 data)
{
    USART_SendByte(data);
}

/**
 * @brief Receives one byte from the HC-05 with a timeout.
 * @param data Pointer to the variable that stores the received byte.
 * @param timeout Maximum waiting time in milliseconds.
 * @return BLUETOOTH_OK if data is received successfully.
 * @return BLUETOOTH_TIMEOUT if timeout expires before receiving data.
 */
Bluetooth_StatusType Bluetooth_ReceiveByte(u8 *data, u32 timeout)
{
    u32 start_time;

    start_time = Timer_GetMilliseconds();

    while (USART_DataAvailable() == 0U)
    {
        if ((Timer_GetMilliseconds() - start_time) >= timeout)
        {
            return BLUETOOTH_TIMEOUT;
        }
    }

    *data = USART_ReceiveByte();

    return BLUETOOTH_OK;
}

