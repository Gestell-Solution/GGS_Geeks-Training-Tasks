/**
 * @file BLUETOOTH_interface.h
 * @brief Public interface for the BLUETOOTH module driver.
 * @author Developer: beshoy esmat
 * @author Reviewer : Eng/Hesham Ahmed
 */

#ifndef _DHT_INTERFACE_H_
#define _DHT_INTERFACE_H_

#include <util/delay.h>

#include "../../LIB/STD_TYPES.h"
#include "DHT_config.h"
#include "DHT_private.h"

#include "../../MCAL/DIO/DIO_interface.h"

void DHT_init();

Dht_state DHT_read(u8 * humidity , u8 * temperature);

#endif