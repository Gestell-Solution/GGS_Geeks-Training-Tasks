/**
 * @file Uart_Interface.h
 * @brief Public API of the ATmega32 UART driver.
 * @version 1.1.0
 * @author Yousef Mohamed <email: yousefmohammed867@gmail.com>
 * @date 2026-09-14
 * @copyright Copyright (c) 2026, Gestell Company
 */
#ifndef _UART_INTERFACE_H_
/**
 * @defgroup UART_INTERFACE_H_GROUP Uart_Interface.h definitions
 * @brief Public UART driver API.
 * @{
 */
#define _UART_INTERFACE_H_

#include <stdint.h>

#include "../../COMMON/Definition.h"
#include "../../COMMON/Bitmath.h"
#include "../Atmega32regmap.h"

#include "Uart_Config.h"
#include "Uart_Private.h"

/*
    1- Mode Select   -> Asynchronous / Synchronous
    2- Stop Bit      -> 1 Stop / 2 Stop
    3- Parity        -> Even / Odd / Disabled
    4- Character Size -> 5..9 bits
*/

/** @brief Initializes the UART peripheral (mode, parity, stop bits, baud rate, interrupts, RX/TX enable) from a Uart_Config_t. */
void UART_Init(Uart_Config_t Uart_Config);

/* ------------------------- Polling (Blocking) API ------------------------ */
void     UART_SendBytePolling(uint16_t Data);
uint16_t UART_ReceiveBytePolling(void);
void     UART_SendStringPolling(const uint8_t * String);
void     UART_ReceiveStringPolling(uint8_t * Buffer, uint8_t Terminator);
void     UART_SendBufferPolling(const uint8_t * Buffer, uint16_t Length);

/* --------------- Polling with Timeout (Bounded-Blocking) API -------------
 * Prevents the driver from stalling the MCU forever when the remote
 * endpoint (e.g. a Bluetooth module) never responds. The MCU is blocked for
 * at most Timeout_ms milliseconds, never indefinitely.
 * --------------------------------------------------------------------- */
uint8_t UART_ReceiveBytePolling_Timeout(uint16_t * Data, uint32_t Timeout_ms);
uint8_t UART_ReceiveStringPolling_Timeout(uint8_t * Data, uint32_t Timeout_ms);

/* ------------------- Interrupt-Driven Reception (Ring Buffer) ------------ */
uint8_t UART_ReceiveByteInterrupt(uint16_t * Data);
void    UART_SendByteInterrupt(uint16_t Data);

/* --------------------------- Interrupt Control ---------------------------- */
void UART_EnableRXInterrupt(void);
void UART_EnableTXInterrupt(void);
void UART_EnableREInterrupt(void);
void UART_DisableRXInterrupt(void);
void UART_DisableTXInterrupt(void);
void UART_DisableREInterrupt(void);

/* ----------------------------- RX/TX Control ------------------------------ */
void UART_EnableRX(void);
void UART_EnableTX(void);
void UART_DisableRX(void);
void UART_DisableTX(void);

/* --------------------------- Callback Registration ------------------------ */
void UART_SetRXCallback(void (*Callback)(uint16_t));
void UART_SetTXCallback(void (*Callback)(void));
void UART_SetRECallback(void (*Callback)(void));

/** @} */

#endif /* _UART_INTERFACE_H_ */
