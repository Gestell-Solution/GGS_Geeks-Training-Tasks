/**
 * @file ADC_Config.h
 * @brief Configuration definitions for the Analog-Digital Converter peripheral driver 
 * @details This file contains the compile-time configuration parameters
 * required to initialize and operate ADC Peripheral driver.
 * @version 0.1
 * @author Malak Mohammed (malak.mohammed.esmail@gmail.com) 
 * @date 21-09-2026 
 * @copyright Copyright (c) 2026, Gestell Company
 */


#ifndef ADC_CONFIG_H 
#define ADC_CONFIG_H 

/** @brief reading timeout value to prevent MCU blocking  */
#define ADC_TIMEOUT 50000UL

/** @brief Error to return when communication fails */
#define ADC_TIMEOUT_ERROR 0xFFFF


#endif