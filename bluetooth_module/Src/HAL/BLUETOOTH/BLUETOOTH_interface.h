/**
 * @file BLUETOOTH_interface.h
 * @brief Public interface for the BLUETOOTH module driver.
 * @author Developer: beshoy esmat
 * @author Reviewer : Eng/Hesham Ahmed
 */

#ifndef _BLUETOOTH_INTERFACE_H_
#define _BLUETOOTH_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"
#include "BLUETOOTH_config.h"
#include "BLUETOOTH_private.h"

#include "../../MCAl/UART/UART_interface.h"
#include "../../MCAL/DIO/DIO_interface.h"

/**
 * @brief Initializes the Bluetooth module.
 *
 * Configures the underlying UART peripheral (9600 baud, 8N1, async mode)
 * and sets the RX/TX DIO pin directions as defined in BLUETOOTH_config.h.
 * Must be called once before any other Bluetooth function is used.
 */
void BLUETOOTH_init();

/**
 * @brief Sends a single byte over Bluetooth.
 *
 * This is a blocking call: it waits until the UART transmit register
 * is empty before returning.
 *
 * @param[in] data Byte to send.
 */
void BLUETOOTH_send_byte(u8 data);

/**
 * @brief Receives a single byte over Bluetooth, with a timeout.
 *
 * Waits for a byte to arrive on UART RX. If no byte arrives before
 * the timeout expires
 *
 * @param[out] data    Pointer to store the received byte. Must not be NULL.
 * @param[in]  Timeout Maximum time to wait for a byte to arrive.
 *
 * @return bluetooth_status_t for all the states to the bluetooth
 */
bluetooth_status_t BLUETOOTH_receive_byte(u8 *data, u32 Timeout);

/**
 * @brief Sends a null-terminated string over Bluetooth.
 *
 * Sends each byte of @p str in sequence until the null terminator is
 * reached. This call has no timeout, since transmission is paced by
 * the MCU itself.
 *
 * @param[in] str Null-terminated string to send. Must not be NULL.
 * @return void function does not return anything
 */
void BLUETOOTH_send_string(u8 *str);

/**
 * @brief Receives a string over Bluetooth until a terminator byte or timeout.
 *
 * Reads bytes one at a time into @p str until @p terminator is received
 * or the per-byte @p timeout expires. The received string is null-terminated
 * on success.
 *
 * @param[out] str        Buffer to store the received string. Must not be NULL.
 * @param[in]  terminator Byte value that marks the end of the string.
 * @param[in]  timeout    Maximum time to wait for each byte.
 *
 * @return bluetooth_status_t for all the states to the bluetooth
 *
 */
bluetooth_status_t BLUETOOTH_receive_string(u8 *str, u8 terminator, u32 timeout);

/**
 * @brief Returns the status of the last Bluetooth operation.
 * @return Current bluetooth_status_t value.
 */
bluetooth_status_t BLUETOOTH_check_status();

/**
 * @brief Returns the status of the last Bluetooth operation as a readable string.
 * @return Pointer to a constant string describing the current status
 *         (e.x. "Bluetooth_OK", "Bluetooth_TIMEOUT").
 */
const u8* BLUETOOTH_check_string();

#endif