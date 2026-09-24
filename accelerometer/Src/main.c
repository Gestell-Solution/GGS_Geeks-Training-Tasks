#include "MCAL/DIO/DIO_interface.h"
#include "HAL/ADXL/ADXL_interface.h"
// #include "HAL/LCD/LCD_interface.h"
#include "MCAL/UART/UART_interface.h"
#include <util/delay.h>

void main(void)
{
    ADXL_init();

    while(1)
    {
        ADXL_uart_send_accel();
        UART_send_string_polling("\r\n");
        _delay_ms(500);
    }

}