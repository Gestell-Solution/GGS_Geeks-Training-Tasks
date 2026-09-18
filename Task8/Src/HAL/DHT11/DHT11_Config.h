/**
 * @file DHT11_Config.h
 * @brief Configuration definitions for the DHT11 Sensor driver 
 * @details This file is supposed to contain the compile-time configuration parameters
 * required to initialize and operate DHT11 Sensor driver.
 * @version 0.1
 * @author Malak Mohammed (malak.mohammed.esmail@gmail.com) 
 * @date 17-09-2026 
 * @copyright Copyright (c) 2026, Gestell Company
 */

 
#ifndef DHT11_CONFIG_H 
#define DHT11_CONFIG_H

#include "../../MCAL/DIO/DIO_Interface.h"

/** @brief  defines the group of DHT11 pin  */
#define DHT11_Group Dio_GroupA

/** @brief  defines the pin of DHT11 connection */
#define DHT11_Pin   Dio_Pin4

/** @brief a timeout value preventing MCU from blocking waiting for a response  */
#define DHT11_Timeout_Value 1000U 



#endif