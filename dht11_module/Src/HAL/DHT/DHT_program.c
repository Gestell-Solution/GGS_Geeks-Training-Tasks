#include "DHT_interface.h"

void DHT_start();
void DHT_wait();
void DHT_resest();


void DHT_init()
{
    DIO_set_pin_direction(Dht_port , Dht_pin , output);

    DIO_set_pin_value(Dht_port , Dht_pin , high);
}

Dht_state DHT_read(u8 * humidity , u8 * temperature)
{
    u8 data[Dht_size_array] = {0};
    u8 outer_counter = 0 ;
    u8 inner_counter = 0 ;
    DHT_start();

    DIO_set_pin_direction(Dht_port , Dht_pin , input);

    DHT_wait();

    for (outer_counter = 0 ; outer_counter < Dht_size_array ; outer_counter++)
    {
        for(inner_counter = 0 ; inner_counter < char_size ; inner_counter++)
        {
            while(Dht_read == low);

            _delay_us(40);
            
            data[outer_counter] <<= shift_left_by_1;

            if (Dht_read == high)
            {
                data[outer_counter] |= shift_left_by_1;
                while(Dht_read == high);
            }
        }
    }
    
    DHT_resest();

    if (data[checksum_data] != (u8)(data[intergral_RH_data] + data[decimal_RH_data] + data[intergral_T_data] + data[decimal_T_data]))
    {
        return Dht_ERROR_checksum;
    }

    *humidity    = data[intergral_RH_data];
    *temperature = data[intergral_T_data];

    return Dht_success;
    
}

void DHT_start()
{
    DIO_set_pin_direction(Dht_port , Dht_pin , output);
    DIO_set_pin_value(Dht_port , Dht_pin , low);
    _delay_ms(18);
    DIO_set_pin_value(Dht_port , Dht_pin , high);
    _delay_us(30);
}

void DHT_wait()
{
    while(Dht_read == high);
    while(Dht_read == low);
    while(Dht_read == high);
}

void DHT_resest()
{
    DIO_set_pin_direction(Dht_port , Dht_pin , output);
    DIO_set_pin_value(Dht_port , Dht_pin , high);

}



// the data pin must be set high
// a complete trasmisson is 40 bit 
// 8bit integral RH data + 8bit decimal RH data + 8bit integral T data + 8bit decimal T data and the 8 bit of the checksum
// when nobody is using it must be set at high
// to start it we set it to low and wait 18ms
// then the mcu set it back to high and wait 40 us 
// then we change it back to input
// then we wait for low then we wait for high then low (low->high->low) so the last low is hey the data is coming

// so the steps 
// 1. send start signal
// 2. switch to input
// 3. wait for response from the sensor 
// 4. read the 40 bits
// 5. resest the pin back to high
// 6. verify checksum