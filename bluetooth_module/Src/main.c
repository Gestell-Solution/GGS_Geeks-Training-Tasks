#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/GIE/GIE_interface.h"
#include "HAL/Bluetooth/Bluetooth_Interface.h"
#include <util/delay.h>

void main()
{
    BLUETOOTH_init();
    BLUETOOTH_send_string("Welcome to Bluetooth ! \r\n");
    _delay_ms(500);
    BLUETOOTH_send_string("Bluetooth Ready for Action\r\n");
    while (1)
    {
   
    BLUETOOTH_send_string("\r\ntest?\r\n");
    BLUETOOTH_send_string((u8*)BLUETOOTH_check_string());
    BLUETOOTH_send_string("\r\ni guess i work now\r\n");
    BLUETOOTH_send_string("\r\nprogram took 2 hours to make\r\n");

    
    BLUETOOTH_send_string("\r\n\r\n");

    _delay_ms(500);
    }
}
