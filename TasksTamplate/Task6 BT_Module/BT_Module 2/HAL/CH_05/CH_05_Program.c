/**
 * @file BT_Program.c
 * @brief Bluetooth driver implementation (polling + interrupt) for the ATmega32.
 * @details Configuration (mode, baud rate, parity, ...) is passed to
 *          BT_Init() via U_Config_t.
 *
 * 
 * @version 2.1.0
 * @author Ali Sotohy <email: alielsotohy2006@gmail.com>
 * @date 2026-09-14
 * @copyright Copyright (c) 2026, Gestell Company
 */
#include "CH_05_Interface.h"




/** 
 * @defgroup BTModule_Driver Bluetooth Module Driver
 * @brief Public interface of the Bluetooth Module driver 
 * @{ 
 */

 /** 
  * @brief Initializes the Bluetooth module and its underlying UART communication
  */
void Bluetooth_Init(void)
{
    UART_Config_t Local_UARTConfig;

    Local_UARTConfig.ModeSelect          = Uart_AsyncMode;
    Local_UARTConfig.StopBitSelect       = Uart_OneStopBit;
    Local_UARTConfig.ParitySelect        = Uart_ParityDisabled;
    Local_UARTConfig.SizeCharacterSelect = Uart_8BitData;
    Local_UARTConfig.BaudRate            = BT_Default_BaudRate;
    Local_UARTConfig.EnableSelect        = Uart_EnableRxTx;
    Local_UARTConfig.SpeedMode           = Uart_NormalSpeed;
    Local_UARTConfig.InterruptSelect     = Uart_InterruptDisabled;

    UART_Init(Local_UARTConfig);
}

 /** 
  * @brief sends a single character via Bluetooth
  * @param data the character byte to be sent
  */
void Bluetooth_SendChar(uint8_t data)
{
    UART_SendBytePolling(data);
}

 /** 
  * @brief receives a single character via Bluetooth
  * @return the received characetr byte
  */
uint8_t Bluetooth_ReceiveChar(void)
{
    uint16_t Local_ReceivedByte = 0;
    UART_Status_t Local_Status = UART_ReceiveBytePolling(&Local_ReceivedByte);

    if (Local_Status == UART_OK)
    {
        return (uint8_t)Local_ReceivedByte;
    }
    else
    {
        /* Handle error or timeout as needed */
        return 0; /* Return a default value or handle error appropriately */
    }
}

 /** 
  * @brief sends a string via Bluetooth
  * @param string the string to be sent
  */
void Bluetooth_SendString(uint8_t* string)
{
    UART_SendStringPolling(string);
}

 /** 
  * @brief receives a string via Bluetooth until terminator character is reached
  * @param buffer pointer to the recieved string storage buffer 
  * @param terminator the character that signifies the end of the received string
  */
void Bluetooth_ReceiveString(uint8_t* buffer, uint16_t MaxLength, uint8_t terminator)
{
    UART_ReceiveStringPolling(buffer, MaxLength, terminator);
}

 /** 
  * @brief Registers a callback function for asynchrnous receive events
  * @param callback pointer to the callback function 
  */
void Bluetooth_SetReceiveCallback(void (*callback)(uint16_t))
{
    UART_SetRxCallBack(callback);
}

/** @} */