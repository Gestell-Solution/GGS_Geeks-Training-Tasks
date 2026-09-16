/**
 * @file BT_Config.h
 * @brief Bluetooth driver configuration for the ATmega32.
 * @details Configuration (mode, baud rate, parity, ...) is passed to
 *          BT_Init() via U_Config_t.
 *
 * 
 * @version 2.1.0
 * @author Ali Sotohy <email: alielsotohy2006@gmail.com>
 * @date 2026-09-14
 * @copyright Copyright (c) 2026, Gestell Company
 */

 #ifndef BT_CONFIG_H
 #define BT_CONFIG_H


/** @brief Default baud rate for Bluetooth communication */
#define BT_Default_BaudRate      9600UL

/** @brief Default timeout threshold for blocking operations to prevent MCU lock */
#define BT_TimeOut_Threshold     50000UL

/** @brief Timeout error indicator for Bluetooth operations */
#define BT_TimeOut_Error      0xFFFFU

/** @brief Null string terminator definition */
#define BT_Null_Terminator        ('\0')

 #endif /* BT_CONFIG_H */