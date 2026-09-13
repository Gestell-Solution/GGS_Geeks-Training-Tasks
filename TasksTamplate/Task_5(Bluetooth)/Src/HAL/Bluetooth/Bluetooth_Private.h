/**
 * @file Bluetooth_Private.h
 * @brief Private (implementation-only) definitions for the Bluetooth driver.
 * @version 1.0.0
 * @author Yousef Mohamed <email: yousefmohammed867@gmail.com>
 * @date 2026-09-14
 * @copyright Copyright (c) 2026, Gestell Company
 */
#ifndef _BLUETOOTH_PRIVATE_H_
/**
 * @defgroup BLUETOOTH_PRIVATE_H_GROUP Bluetooth_Private.h definitions
 * @brief Private Bluetooth driver definitions.
 * @{
 */
#define _BLUETOOTH_PRIVATE_H_

#include <stdint.h>

/** @brief Longest AT command/response line the driver will buffer, terminator included. Bounded by the UART RX ring-buffer size. */
#define BLUETOOTH_MAX_LINE_LENGTH   UART_RX_BUFFER_SIZE

/** @brief Line terminator most classic-Bluetooth (HC-05/HC-06 style) modules expect after an AT command. */
#define BLUETOOTH_AT_TERMINATOR     "\r\n"

/** @brief Substring the module echoes back on a successful AT command. */
#define BLUETOOTH_AT_OK_RESPONSE    "OK"

/**
 * @brief Bluetooth driver return/status codes.
 */
typedef enum
{
    BLUETOOTH_STATUS_OK      = 0U, /**< Data/acknowledgement received as expected.         */
    BLUETOOTH_STATUS_TIMEOUT = 1U, /**< Nothing arrived within the configured timeout.     */
    BLUETOOTH_STATUS_ERROR   = 2U  /**< A response arrived, but not the one expected, or
                                          an invalid argument (e.g. a null pointer) was
                                          passed in. */
} Bluetooth_Status_t;

/** @} */

#endif /* _BLUETOOTH_PRIVATE_H_ */
