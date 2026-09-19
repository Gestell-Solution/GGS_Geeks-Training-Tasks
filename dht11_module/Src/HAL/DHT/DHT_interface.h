/**
 * @file DHT_interface.h
 * @brief Public interface for the DHT module driver.
 * @author Developer: beshoy esmat
 * @author Reviewer: Eng/Hesham Ahmed
 */

#ifndef _DHT_INTERFACE_H_
#define _DHT_INTERFACE_H_

#include <util/delay.h>

#include "../../LIB/STD_TYPES.h"
#include "DHT_config.h"
#include "DHT_private.h"

#include "../../MCAL/DIO/DIO_interface.h"


/**
 * @brief Initializes the DHT sensor.
 */

void DHT_init();

/**
 * @brief Reads the humidity and temperature values from the DHT sensor.
 *
 * @param[out] humidity Pointer to store the measured humidity value.
 * @param[out] temperature Pointer to store the measured temperature value.
 *
 * @return Dht_state indicating the status of the DHT read operation.
 */

Dht_state DHT_read(u8 * humidity , u8 * temperature);

#endif