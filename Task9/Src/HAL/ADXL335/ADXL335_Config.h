/**
 * @file ADXL335_Config.h
 * @brief Configuration definitions for ADXL335 driver 
 * @details This file contains the compile-time configuration parameters
 * required to initialize and operate ADXL335 driver.
 * @version 0.1
 * @author Malak Mohammed (malak.mohammed.esmail@gmail.com) 
 * @date 24-09-2026 
 * @copyright Copyright (c) 2026, Gestell Company
 */

 #ifndef ADXL335_CONFIG_H
 #define ADXL335_CONFIG_H

 #include "../../MCAL/DIO/DIO_Interface.h"

/** @brief defining x-axis pin as pin 0  */
#define ADXL335_X_CHANNEL 0

/** @brief  defining y-axis pin as pin 1 */
#define ADXL335_Y_CHANNEL 1

/** @brief  defining z-axis pin as pin 2 */
#define ADXL335_Z_CHANNEL 2

/** @brief Voltage supplied to Vs pin */
#define ADXL335_SUPPLY_VOLTAGE  5.0f  

/** @brief  Reference voltage of ATmega32 ADC ( AVCC = 5V)  */
#define ADXL335_ADC_REF_VOLTAGE 5.0f 

 #endif