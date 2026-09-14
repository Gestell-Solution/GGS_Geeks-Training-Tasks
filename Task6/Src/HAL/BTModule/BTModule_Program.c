/**
 * @file BTModule_Program.c
 * @brief Main program implementation 
 * @details This file contains the main program logic of the bluetooth module driver 
 * @version 0.1
 * @author Malak Mohammed (malak.mohammed.esmail@gmail.com) 
 * @date 14-09-2026
 * @copyright Copyright (c) 2026, Gestell Company
 */

#include "BTModule_Interface.h"
#include "BTModule_Config.h"
#include "../../MCAL/UART/UART_Interface.h"

void Bluetooth_Init(void)
  {

    UART_Config_t bt_uart_config = {
        .ModeSelect          = UART_AsynchMode,
        .StopBitSelect       = UART_1StopBit,
        .CharacterSizeSelect = UART_8BitSize,
        .SpeedMode           = UART_NormalSpeed,
        .ParitySelect        = UART_ParityDisabled,
        .BaudRate            = BT_Default_BaudRate,
        .InterruptSelect     = UART_InterrputDisabled,
        .EnableSelect        = UART_EnableRxTx
    } ;
    UART_Init(bt_uart_config);

}

void Bluetooth_SendChar(uint8_t data)
{
    UART_SendBytePolling((uint16_t)data);
}

uint8_t Bluetooth_ReceiveChar(void)
{
    return (uint8_t)UART_ReceiveBytePolling();
}

void Bluetooth_SendString(uint8_t* string)
{
    UART_SendStringPolling(string);
}

void Bluetooth_ReceiveString(uint8_t* buffer, uint8_t terminator)
{
    UART_ReceiveStringPolling(buffer, terminator);
}

void Bluetooth_SetReceiveCallback(void (*callback)(uint16_t))
{
    UART_SetRxCallBack(callback);
    UART_RxInterruptEnable();
}