#include <stdint.h>
#include<util\delay.h>
#include "MCAL/UART/UART_Interface.h"
#include "HAL/Bluetooth/Bluetooth_Interface.h"

int main(void)
{
    uint8_t ReceivedString[100] = {0};
    Bluetooth_Init();
    Bluetooth_SendString("Welcome to Bluetooth ! \r\n");
    Bluetooth_SendString("Bluetooth Ready for Action\r\n");
    while (1)
    {
   
    Bluetooth_SendString("\r\nEnter text: ");
    Bluetooth_ReceiveString(ReceivedString, '\r');
    Bluetooth_SendString("You sent: ");
    Bluetooth_SendString(ReceivedString);
    Bluetooth_SendString("\r\n");
    _delay_ms(500);
    }

    return 0;
}