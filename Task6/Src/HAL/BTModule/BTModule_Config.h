/**
 * @file BTModule_Config.h
 * @brief Configuration definitions for the Bluetooth module driver 
 * @details This file is supposed to contain the compile-time configuration parameters
 * required to initialize and operate the Bluetooth module.
 * @version 0.1
 * @author Malak Mohammed (malak.mohammed.esmail@gmail.com) 
 * @date 14-09-2026
 * @copyright Copyright (c) 2026, Gestell Company
 */


#ifndef _BTMODULE_CONFIG_H
#define _BTMODULE_CONFIG_H 

/** @brief Default baud rate for Bluetooth communication */
#define BT_Default_BaudRate      9600UL

/** @brief Default timeout threshold for blocking operations to prevent MCU lock */
#define BT_TimeOut_Threshold     50000UL

/** @brief Timeout error indicator for Bluetooth operations */
#define BT_TimeOut_Error      0xFFFFU


#endif