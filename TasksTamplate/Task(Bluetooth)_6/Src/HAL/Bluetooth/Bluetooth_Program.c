/**
 * @file Bluetooth_Program.c
 * @brief This file contains the implementation of the BLUETOOTH module Functions.
 * @author Developer: Abdulrahman Ali 
 * @author Reviewer : Eng/Hesham Ahmed
 * @date 9/13/2026
 * @copyright Copyright (c) 2026 , Gestell Company. All rights reserved.
 * @version 1.0.0
 */
#include <stdint.h>
#include "Bluetooth_Interface.h"
#include "Bluetooth_Private.h"
#include "Bluetooth_Config.h"
#include "../../MCAL/UART/UART_Interface.h"


/**
 * @brief Initializes the Bluetooth module interface.
 *
 * @return void
 */
void Bluetooth_Init(void)
{
    /*
     * The HC-05 communicates with the ATmega32
     * through the UART peripheral.
     *
     * UART configuration:
     * Baud Rate : 9600
     * Data Bits : 8
     * Stop Bits : 1
     * Parity    : None
     */
    Uart_Config_t Config_t = {
        .ModeSelect = Uart_AsynchronousMode,
        .StopBitSelect = Uart_1StopBit,
        .ParitySelect = Uart_ParityDisabled,
        .SizeCharacterSelect = Uart_8BitSize,
        .EnableSelect = Uart_EnableRxAndTx,
        .BaudRate = 9600,
        .InterruptSelect = Uart_InterruptDisabled
    };
    UART_Init(Config_t);
}

/**
 * @brief Sends one byte through the HC-05 module.
 *
 * @param Data Byte to be transmitted.
 *
 * @return void
 */
void Bluetooth_SendByte(uint8_t Data)
{
    UART_SendBytePolling(Data);
}

/**
 * @brief Receives one byte from the HC-05 using polling with timeout.
 *
 * @param Data Pointer to store the received byte.
 * @param Timeout Maximum polling count.
 *
 * @return UART_OK if data is received, otherwise UART_TIMEOUT.
 */
uint8_t Bluetooth_ReceiveByte(uint8_t *Data, uint32_t Timeout)
{
    if(Data == BLUETOOTH_NULL)
    {
        return BLUETOOTH_TIMEOUT;
    }
    return UART_ReceiveBytePolling_Timeout(Data, Timeout);
}

/**
 * @brief Sends a string through the HC-05 module.
 *
 * @param String Pointer to the string to be transmitted.
 *
 * @return void
 */
void Bluetooth_SendString(uint8_t *String)
{
    if(String != BLUETOOTH_NULL)
    {
    UART_SendStringPolling(String);
    }
}

/**
 * @brief Receive a string through the HC-05 module.
 *
 * @param String Pointer to the string to be Receiver.
 *
 * @return void
 */
void Bluetooth_ReceiveString(uint8_t *String ,uint8_t Terminator) {
    if (String != BLUETOOTH_NULL)
    {
     UART_ReceiveStringPolling((uint16_t*)String, Terminator);
    }
}
