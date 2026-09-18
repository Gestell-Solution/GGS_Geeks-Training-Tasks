/**
 * @file dht11_Interface.h
 * @brief This file contains the interface functions for for the DHT11 module.
 * @author Developer: Abdulrahman Ali 
 * @author Reviewer : Eng/Hesham Ahmed
 * @date 9/18/2026
 * @copyright Copyright (c) 2026 , Gestell Company. All rights reserved.
 * @version 1.0.0
*/

#ifndef DHT11_INTERFACE_H
#define DHT11_INTERFACE_H
#include <stdint.h>
#include "dht11_Config.h"
#include "dht11_Private.h"


/**
 * @brief Initialize DHT11 driver.
 *
 * @return void.
 */
void DHT11_Init(void);


/**
 * @brief Read temperature & Humidity from DHT11.
 *
 * @param Temperature Pointer to temperature value.
 * @param Humidity Pointer to humidity value.
 * @return DHT11 status.
 */
uint8_t DHT11_ReadData(uint8_t *Temperature,uint8_t *Humidity);




#endif /* DHT11_INTERFACE_H */