#include "DHT_interface.h"

/**
 * @brief Sends the start signal to the DHT sensor.
 */
void DHT_start();

/**
 * @brief Waits for the DHT sensor response signal.
 */
void DHT_wait();

/**
 * @brief Resets the DHT data pin to its idle high state.
 */
void DHT_resest();

/**
 * @brief Initializes the DHT sensor data pin.
 *
 * @details
 * Configures the DHT data pin as an output and sets it to its
 * default idle high state.
 */
void DHT_init()
{
    DIO_set_pin_direction(Dht_port, Dht_pin, output);
    DIO_set_pin_value(Dht_port, Dht_pin, high);
}

/**
 * @brief Reads humidity and temperature data from the DHT sensor.
 *
 * @details
 * The DHT sensor transmits a complete data frame of 40 bits:
 * - 8 bits for integral relative humidity.
 * - 8 bits for decimal relative humidity.
 * - 8 bits for integral temperature.
 * - 8 bits for decimal temperature.
 * - 8 bits for checksum.
 *
 * The function sends the start signal, waits for the sensor response,
 * reads the complete 40-bit data frame, verifies the checksum, and
 * stores the measured humidity and temperature values.
 *
 * @param[out] humidity Pointer to store the integral humidity value.
 * @param[out] temperature Pointer to store the integral temperature value.
 *
 * @return Dht_state
 *         - Dht_ERROR_checksum if the received checksum is invalid.
 *         - Dht_success if the data is received and verified successfully.
 */
Dht_state DHT_read(u8 * humidity, u8 * temperature)
{
    u8 data[Dht_size_array] = {0};
    u8 outer_counter = 0;
    u8 inner_counter = 0;

    DHT_start();

    DIO_set_pin_direction(Dht_port, Dht_pin, input);

    DHT_wait();

    for (outer_counter = 0; outer_counter < Dht_size_array; outer_counter++)
    {
        for(inner_counter = 0; inner_counter < char_size; inner_counter++)
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

/**
 * @brief Sends the start signal required to initiate DHT communication.
 *
 * @details
 * The MCU drives the data pin low for at least 18 ms, then drives it
 * high for approximately 30 us before releasing the line for input.
 */
void DHT_start()
{
    DIO_set_pin_direction(Dht_port, Dht_pin, output);
    DIO_set_pin_value(Dht_port, Dht_pin, low);
    _delay_ms(18);
    DIO_set_pin_value(Dht_port, Dht_pin, high);
    _delay_us(30);
}

/**
 * @brief Waits for the DHT sensor response sequence.
 *
 * @details
 * The function waits for the sensor response sequence:
 * high -> low -> high.
 * The final transition indicates that the sensor is ready to transmit data.
 */
void DHT_wait()
{
    while(Dht_read == high);
    while(Dht_read == low);
    while(Dht_read == high);
}

/**
 * @brief Resets the DHT data pin to its idle state.
 *
 * @details
 * After completing the data transmission, the MCU configures the
 * DHT data pin as an output and drives it high.
 */
void DHT_resest()
{
    DIO_set_pin_direction(Dht_port, Dht_pin, output);
    DIO_set_pin_value(Dht_port, Dht_pin, high);
}

/**
 * @brief DHT communication sequence.
 *
 * @details
 * The DHT communication process consists of the following steps:
 * 1. Send the start signal.
 * 2. Switch the data pin to input mode.
 * 3. Wait for the response from the sensor.
 * 4. Read the complete 40-bit data frame.
 * 5. Reset the data pin to its idle high state.
 * 6. Verify the received checksum.
 *
 * The data frame consists of 40 bits:
 * 8-bit integral relative humidity,
 * 8-bit decimal relative humidity,
 * 8-bit integral temperature,
 * 8-bit decimal temperature,
 * and 8-bit checksum.
 */