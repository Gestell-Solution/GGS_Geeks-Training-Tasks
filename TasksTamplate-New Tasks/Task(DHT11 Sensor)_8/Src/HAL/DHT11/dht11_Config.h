/**
 * @file dht11_Config.h
 * @brief This file contains the configuration settings for the DHT11 module.
 * @author Developer: Abdulrahman Ali 
 * @author Reviewer : Eng/Hesham Ahmed
 * @date 9/18/2026
 * @copyright Copyright (c) 2026 , Gestell Company. All rights reserved.
 * @version 1.0.0
*/
#ifndef DHT11_CONFIG_H
#define DHT11_CONFIG_H
#include <stdint.h>


/**
* @brief DHT11 DATA pin configuration.
*/
#define DHT11_DATA_PORT       Dio_GroupD
#define DHT11_DATA_PIN        Dio_Pin6





/**
* @brief DHT11 Config Setting
*/
#define DHT11_START_LOW_MS       (18U)
#define DHT11_TIMEOUT_US         (100000U)
#define DHT11_DATA_SIZE          (5U)





#endif /* DHT11_CONFIG_H */