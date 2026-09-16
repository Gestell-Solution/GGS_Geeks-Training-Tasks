/**
 * \@file DHT11_Interface
 * @author salma mohamed mahmoud fouad(salmafouadothman@gmail.com)
 * @brief  this driver is used to initialize the DHT11 sensor and receive data from it
 * @details this driver should intilize the dht11 sensor and get the data find it and send it
 * @version 0.1
 * @date 2026-09-14
 * @copyright Copyright (c) 2026
 */
#ifndef  DHT11_INTERFACE_H_
#define  DHT11_INTERFACE_H_

#include"DHT11_Config.h"
#include"../../MCAL/DIO/DIO_Interface.h"
#include <util/delay.h>

/**
 * @brief to initalize the dht11 sensor
 * @fn DHT11_Init
 */
void DHT11_Init();
/**
 * @brief to wait for some time before getting data
 * @fn DHT11_Response
 */
void DHT11_Response();
/**
 * @brief get all the data and return it
 * @fn DHT11_Get_data
 * @return data the dht11 data
 */
uint8_t DHT11_Get_data();

#endif