/**
 * @file Bluetooth_Config.h
 * @brief Compile-time configuration for the Bluetooth driver.
 * @version 1.0.0
 * @author Yousef Mohamed <email: yousefmohammed867@gmail.com>
 * @date 2026-09-14
 * @copyright Copyright (c) 2026, Gestell Company
 */
#ifndef _BLUETOOTH_CONFIG_H_
/**
 * @defgroup BLUETOOTH_CONFIG_H_GROUP Bluetooth_Config.h definitions
 * @brief Compile-time Bluetooth driver configuration.
 * @{
 */
#define _BLUETOOTH_CONFIG_H_

/**
 * @brief Default baud rate for Bluetooth_Config_t.BaudRate.
 * @note Matches the HC-05/HC-06 factory default in *data* mode (9600 8N1).
 *       Most HC-05 modules switch to 38400 in AT-command mode - override
 *       per-application if your module/firmware differs.
 */
#ifndef BLUETOOTH_DEFAULT_BAUDRATE
#define BLUETOOTH_DEFAULT_BAUDRATE  9600UL
#endif

/** @brief Default bounded-poll timeout (ms) used by Bluetooth_ReceiveLine() and other timeout-less convenience wrappers. */
#ifndef BLUETOOTH_TIMEOUT_MS
#define BLUETOOTH_TIMEOUT_MS        500UL
#endif

/** @} */

#endif /* _BLUETOOTH_CONFIG_H_ */
