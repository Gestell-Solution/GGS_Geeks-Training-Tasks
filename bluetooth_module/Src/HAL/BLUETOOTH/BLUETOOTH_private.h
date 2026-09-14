/**
 * @file BLUETOOTH_private.h
 * @brief Private types for the BLUETOOTH module driver.
 * @author Developer: beshoy esmat
 * @author Reviewer : Eng/Hesham Ahmed
 */

#ifndef _BLUETOOTH_PRIVATE_H_
#define _BLUETOOTH_PRIVATE_H_

/**
 * @brief Status codes returned by Bluetooth module operations.
 */
typedef enum {
    Bluetooth_OK,               /**< No error; default/idle state. */
    Bluetooth_TIMEOUT,          /**< Operation timed out waiting for data. */
    Bluetooth_NULL,             /**< A NULL pointer was passed as an argument. */
    Bluetooth_recive_complete,  /**< Byte or string received successfully. */
    Bluetooth_send_complete,    /**< Byte or string sent successfully. */
    Bluetooth_not_started,      /**< No operation has been performed yet. */
} bluetooth_status_t;

#endif