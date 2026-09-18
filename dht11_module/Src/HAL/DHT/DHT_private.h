/**
 * @file BLUETOOTH_private.h
 * @brief Private types for the BLUETOOTH module driver.
 * @author Developer: beshoy esmat
 * @author Reviewer : Eng/Hesham Ahmed
 */

#ifndef _DHT_PRIVATE_H_
#define _DHT_PRIVATE_H_


#define Dht_port Dio_groupA
#define Dht_pin  Dio_pin0

#define Dht_size_array 5
#define char_size 8
#define shift_left_by_1 1

#define Dht_read DIO_get_pin_value(Dht_port , Dht_pin)
typedef enum 
{
    Dht_OK,
    Dht_ERROR_checksum,
    Dht_ERROR_no_response,
    Dht_success,
}Dht_state;

typedef enum 
{
    intergral_RH_data,
    decimal_RH_data,
    intergral_T_data,
    decimal_T_data,
    checksum_data,
}Dht_checksum;

#endif