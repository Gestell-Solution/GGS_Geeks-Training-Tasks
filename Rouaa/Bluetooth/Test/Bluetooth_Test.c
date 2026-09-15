/*
 * @file         Bluetooth_Test.c
 * @brief        Test cases for the Bluetooth driver.
 * @details      Tests Bluetooth reception with timeout and successful data reception.
 * @copyright    Copyright (c) 2026 Gestell-Co. All rights reserved.
 * @author       Rouaa Ayman (Rouaaayman2602@gmail.com)
 * @version      0.1
 * @date         2026-09-14
 *
 * @copyright    Copyright (c) 2026
 *
 */

#include "Bluetooth.h"

/**
 * @brief Tests Bluetooth reception with timeout.
 * @details Waits for one byte for 1000 ms. If no data is received,
 *          a timeout indication is sent.
 */
void Bluetooth_Test(void)
{
    u8 received_data;
    Bluetooth_StatusType status;

    status = Bluetooth_ReceiveByte(&received_data, 1000U);

    if (status == BLUETOOTH_OK)
    {
        Bluetooth_SendByte(received_data);
    }
    else
    {
        Bluetooth_SendByte('T');
    }

    while (1)
    {
        status = Bluetooth_ReceiveByte(&received_data, 1000U);

        if (status == BLUETOOTH_OK)
        {
            Bluetooth_SendByte(received_data);
        }
        else
        {
            Bluetooth_SendByte('T');
        }
    }
}