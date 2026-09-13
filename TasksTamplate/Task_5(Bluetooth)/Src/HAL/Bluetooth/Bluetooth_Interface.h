/**
 * @file Bluetooth_Interface.h
 * @brief Public API of the Bluetooth (HC-05/HC-06-style, UART-based) module driver.
 * @details Built entirely on top of MCAL/UART - this module owns no
 *          registers of its own and talks to the Bluetooth module purely
 *          through the UART peripheral it is wired to.
 * @version 1.0.0
 * @author Yousef Mohamed <email: yousefmohammed867@gmail.com>
 * @date 2026-09-14
 * @copyright Copyright (c) 2026, Gestell Company
 */
#ifndef _BLUETOOTH_INTERFACE_H_
/**
 * @defgroup BLUETOOTH_INTERFACE_H_GROUP Bluetooth_Interface.h definitions
 * @brief Public Bluetooth driver API.
 * @{
 */
#define _BLUETOOTH_INTERFACE_H_

#include <stdint.h>

#include "../../COMMON/Definition.h"
#include "../../MCAL/UART/Uart_Interface.h"

#include "Bluetooth_Config.h"
#include "Bluetooth_Private.h"

/**
 * @brief Bluetooth module configuration, applied to the underlying UART
 *        peripheral the module is wired to.
 */
typedef struct
{
    uint32_t BaudRate;  /**< UART baud rate the module is set to, e.g. BLUETOOTH_DEFAULT_BAUDRATE. */
} Bluetooth_Config_t;

/**
 * @brief Initializes the UART peripheral with the settings a classic
 *        Bluetooth module expects: Asynchronous, 8 data bits, no parity,
 *        1 stop bit, RX+TX enabled, interrupts disabled (polling-driven).
 */
void Bluetooth_Init(Bluetooth_Config_t Bluetooth_Config);

/** @brief Sends a null-terminated string as-is (no terminator appended). */
void Bluetooth_SendString(const uint8_t * String);

/** @brief Sends an AT command, automatically appending the "\r\n" terminator most modules expect. */
void Bluetooth_SendCommand(const uint8_t * Command);

/**
 * @brief Bounded-poll receive of a single byte: waits up to Timeout_ms for
 *        one byte to arrive. Prevents the driver from blocking the MCU
 *        indefinitely if the module never sends data (disconnected,
 *        powered off, out of range, ...).
 * @param Data       Out-parameter, filled in on BLUETOOTH_STATUS_OK.
 * @param Timeout_ms Maximum time to wait, in milliseconds.
 * @return BLUETOOTH_STATUS_OK, BLUETOOTH_STATUS_TIMEOUT, or
 *         BLUETOOTH_STATUS_ERROR (Data was Null).
 */
Bluetooth_Status_t Bluetooth_ReceiveByte_Timeout(uint8_t * Data, uint32_t Timeout_ms);

/**
 * @brief Bounded-poll receive of a full line (terminated by \\r or \\n) or
 *        a timeout, whichever happens first. Suitable for AT command
 *        responses or newline-delimited data payloads.
 * @param Buffer     Destination buffer, at least BLUETOOTH_MAX_LINE_LENGTH bytes.
 * @param Timeout_ms Maximum time to wait per byte, in milliseconds.
 */
Bluetooth_Status_t Bluetooth_ReceiveLine_Timeout(uint8_t * Buffer, uint32_t Timeout_ms);

/** @brief Bluetooth_ReceiveLine_Timeout() using the project-wide default timeout (BLUETOOTH_TIMEOUT_MS). */
Bluetooth_Status_t Bluetooth_ReceiveLine(uint8_t * Buffer);

/**
 * @brief Sends an AT command and checks whether the response received
 *        within Timeout_ms contains "OK".
 * @return BLUETOOTH_STATUS_OK  - module answered "OK" in time.
 *         BLUETOOTH_STATUS_TIMEOUT - no response arrived in time.
 *         BLUETOOTH_STATUS_ERROR   - a response arrived but was not "OK".
 */
Bluetooth_Status_t Bluetooth_SendCommand_CheckAck(const uint8_t * Command, uint32_t Timeout_ms);

/** @} */

#endif /* _BLUETOOTH_INTERFACE_H_ */
