/**
 * @file main.c
 * @brief Main application file for testing Bluetooth communication via polling
 * @details Demonstrates initializing the Bluetooth module, sending a welcome message, 
 *          and continuously polling for incoming characters to echo back.
 * @version 0.1
 * @author Malak Mohammed (malak.mohammed.esmail@gmail.com) 
 * @date 14-09-2026
 * @copyright Copyright (c) 2026, Gestell Company
 */


#include "HAL/BTModule/BTModule_Interface.h"
void main()
{
    uint8_t received_data = 0;


    Bluetooth_Init();
    Bluetooth_SendString((uint8_t*)"Hello via Bluetooth Polling!\r\n");

    while(1)
    {
    uint16_t received_data = Bluetooth_ReceiveChar();
    
    // Ensure it is neither the 16-bit timeout error (0xFFFF) nor a squeezed 8-bit version 
    if((received_data != BT_TimeOut_Error) && (received_data != 0x00FFU))
    {
        Bluetooth_SendChar((uint8_t)received_data);
    }

    }
}