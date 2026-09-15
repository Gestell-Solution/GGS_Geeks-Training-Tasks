/**
 * \@file DHT11_Interface
 * @author salma mohamed mahmoud fouad(salmafouadothman@gmail.com)
 * @brief  this driver is used to initialize the DHT11 sensor and receive data from it
 * @details 
 * @version 0.1
 * @date 2026-09-14
 * @copyright Copyright (c) 2026
 */
#ifndef  DHT11_INTERFACE_H_
#define  DHT11_INTERFACE_H_

#include"DHT11_Config.h"
#include"../../MCAL/DIO/DIO_Interface.h"
#include <util/delay.h>

void DHT11_Init();
void DHT11_Response();
uint8_t DHT11_Get_data();

#endif