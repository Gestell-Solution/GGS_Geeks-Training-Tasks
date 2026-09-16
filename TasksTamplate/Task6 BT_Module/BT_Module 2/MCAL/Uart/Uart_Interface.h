/**
 * @file Uart_Interface.h
 * @brief Public interface for the UART driver.
 * @details This file declares every function other modules are allowed to
 *          call on the UART driver (function prototypes only). It is the
 *          contract between this driver and the rest of the system -
 *          implementation details live in Uart_Program.c, and compile-time
 *          register/bit definitions live in Uart_Private.h.
 * @version 2.0.0
 * @author Ali Sotohy <email: alielsotohy2006@gmail.com>
 * @date 2026-09-14
 * @copyright Copyright (c) 2026, Gestell Company
 */

#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H

/**
 * @defgroup UART_INTERFACE_H_GROUP Uart_Interface.h definitions
 * @brief Public UART driver interface.
 */

#include "Uart_Private.h"
#include <stdint.h>
#include "../Atmega32RegMap.h"
#include "../../Common/Bitmath.h"
#include "../../Common/Defination.h"

/**
 * @brief Initializes the UART module with the specified configuration.
 * @param UART_Config A structure containing the desired UART configuration settings.
 * @return UART_OK if every field was valid, UART_NOK if one or more
 *         fields held an invalid enum value.
 */
UART_Status_t UART_Init(UART_Config_t UART_Config);

/**
 * @brief Sends a single byte of data over UART using polling.
 * @param Data The byte of data to be sent (bit 8 used only in 9-bit mode).
 * @return UART_OK on success, UART_TIMEOUT if the data register never
 *         became empty.
 */
UART_Status_t UART_SendBytePolling(uint16_t Data);

/**
 * @brief Receives a single byte of data over UART using polling.
 * @param Data Out-parameter that receives the byte on success. Left
 *             untouched on failure - check the return status first.
 * @return UART_OK on success, UART_NOK if Data is Null, UART_TIMEOUT
 *         if no byte arrived in time.
 */
UART_Status_t UART_ReceiveBytePolling(uint16_t* Data);

/**
 * @brief Sends a null-terminated string over UART using polling.
 * @param String Pointer to the null-terminated string to send.
 * @return UART_OK if every byte was sent, UART_NOK if String is Null,
 *         or the first non-OK status hit while sending.
 */
UART_Status_t UART_SendStringPolling(uint8_t* String);

/**
 * @brief Receives a string over UART using polling, stopping at
 *        TerminationChar or when the buffer is full, whichever comes
 *        first. Buffer is always left null-terminated within bounds.
 * @param Buffer          Destination buffer, capacity MaxLength bytes.
 * @param MaxLength       Total capacity of Buffer, including the final '\0'.
 * @param TerminationChar Byte value marking the end of the string.
 * @return UART_OK if TerminationChar was received in time, UART_NOK
 *         if Buffer is Null or MaxLength is 0, UART_TIMEOUT if a byte
 *         never arrived in time.
 */
UART_Status_t UART_ReceiveStringPolling(uint8_t* Buffer, uint16_t MaxLength, uint8_t TerminationChar);

/**
 * @brief Sends a buffer of raw bytes (not null-terminated) over UART using polling.
 * @param Buffer Pointer to the data to send.
 * @param Length Number of bytes to send.
 * @return UART_OK if every byte was sent, UART_NOK if Buffer is Null,
 *         or the first non-OK status hit while sending.
 */
UART_Status_t UART_SendBufferPolling(uint8_t* Buffer, uint16_t Length);

/**
 * @brief Loads a byte into the UDR register for interrupt-driven
 *        transmission. Must only be called from Tx/UDRE ISR context
 *        (or to prime the first byte right after enabling the Tx
 *        interrupt) - it does not wait for UDRE like the polling version.
 * @param Data The byte of data to be sent.
 */
void UART_SendByteInterrupt(uint16_t Data);

/*--------------------------------------------------control rx/tx--------------------------------------------------------*/

/** @brief Enables the UART receiver to start receiving data. */
void UART_RxEnable(void);

/** @brief Enables the UART transmission line. */
void UART_TxEnable(void);

/** @brief Disables the UART receive line. */
void UART_RxDisable(void);

/** @brief Disables the UART transmission line. */
void UART_TxDisable(void);

/** @brief Enables the UART receive interrupt. */
void UART_RxInterruptEnable(void);

/** @brief Enables the UART transmission-complete interrupt. */
void UART_TxInterruptEnable(void);

/** @brief Enables the UART Data-Register-Empty interrupt. */
void UART_REInterruptEnable(void);

/** @brief Disables the UART receive interrupt. */
void UART_RxInterruptDisable(void);

/** @brief Disables the UART transmission-complete interrupt. */
void UART_TxInterruptDisable(void);

/** @brief Disables the UART Data-Register-Empty interrupt. */
void UART_REInterruptDisable(void);

/*--------------------------------------------------------Set Callbacks--------------------------------------------------------*/

/**
 * @brief Registers a callback for the UART receive-complete interrupt.
 * @param PF Pointer to the callback to run when data is received.
 */
void UART_SetRxCallBack(void (*PF)(uint16_t));

/**
 * @brief Registers a callback for the UART transmission-complete interrupt.
 * @param PF Pointer to the callback to run when data is transmitted.
 */
void UART_SetTxCallBack(void (*PF)(void));

/**
 * @brief Registers a callback for the UART Data-Register-Empty interrupt.
 * @param PF Pointer to the callback to run when the data register is empty.
 */
void UART_SetRECallBack(void (*PF)(void));

#endif /* UART_INTERFACE_H */