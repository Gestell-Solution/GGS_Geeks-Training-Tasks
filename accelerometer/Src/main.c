#include "MCAL/DIO/DIO_interface.h"
#include "HAL/DHT/DHT_interface.h"
#include "HAL/LCD/LCD_interface.h"
#include <util/delay.h>

void main(void)
{
    u8 humidity    = 0;
    u8 temperature = 0;
    Dht_state result;

    LCD_init(Lcd_4bitMode);
    DHT_init();

    LCD_go_to_XY(Lcd_first_row, Lcd_column0);
    LCD_write_string("Humidity:");
    LCD_go_to_XY(Lcd_secound_row,Lcd_column0);
    LCD_write_string("Temp:");

    while(1)
    {
        result = DHT_read(&humidity, &temperature);

        if (result == Dht_success)
        {
            LCD_go_to_XY(Lcd_first_row, Lcd_column10);
            LCD_write_number(humidity);
            LCD_write_string(" % ");

            LCD_go_to_XY(Lcd_secound_row, Lcd_column6);
            LCD_write_number(temperature);
            LCD_write_string(" C ");
        }
        else if (result == Dht_ERROR_checksum)
        {
            LCD_go_to_XY(0, 0);
            LCD_write_string("Checksum Error   ");
        }

        _delay_ms(2000);
    }


}