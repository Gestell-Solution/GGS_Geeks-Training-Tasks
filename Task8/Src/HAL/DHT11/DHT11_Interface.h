/**
 * @file DHT11_Interface.h
 * @brief  Interface of DHT11 Sensor driver
 * @details This file contains function prototypes required to interface with DHT11 sensor driver  
 * @version 0.1
 * @author Malak Mohammed (malak.mohammed.esmail@gmail.com) 
 * @date 17-09-2026
 * @copyright Copyright (c) 2026, Gestell Company
 */

#ifndef DHT11_INTERFACE_H 
#define DHT11_INTERFACE_H

#include <stdint.h>
#include "DHT11_Private.h"

/**
 * @brief initializes DHT11 pin configuration 
 */
void DHT11_Init(void);

/**
 * @brief Read humidity 
 * @param Humidity pointer to humidity reading value 
 * @param Temperature pointer to temperature reading value
 * @return humidity and temperature readings
 */
uint8_t DHT11_ReadData(uint8_t* Humidity, uint8_t* Temperature);




#endif