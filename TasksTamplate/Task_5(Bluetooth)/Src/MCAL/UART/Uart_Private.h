/**
 * @file Uart_Private.h
 * @brief Private (implementation-only) definitions for the UART driver.
 * @details Bit positions, configuration option values, and buffer sizing
 *          that only Uart_Program.c and Uart_Interface.h need to know about.
 * @version 1.1.0
 * @author Yousef Mohamed <email: yousefmohammed867@gmail.com>
 * @date 2026-09-14
 * @copyright Copyright (c) 2026, Gestell Company
 */
#ifndef _UART_PRIVATE_H_
/**
 * @defgroup UART_PRIVATE_H_GROUP Uart_Private.h definitions
 * @brief Private UART driver definitions.
 * @{
 */
#define _UART_PRIVATE_H_

#include <stdint.h>

/* ------------------------------- UCSRA ------------------------------- */
#define Uart_RXC    7U
#define Uart_TXC    6U
#define Uart_UDRE   5U
#define Uart_FE     4U
#define Uart_DOR    3U
#define Uart_PE     2U
#define Uart_U2X    1U
#define Uart_MPCM   0U

#define Uart_NormalSpeed    0U
#define Uart_DoubleSpeed    1U

/* ------------------------------- UCSRB ------------------------------- */
#define Uart_RXCIE  7U
#define Uart_TXCIE  6U
#define Uart_UDRIE  5U
#define Uart_RXEN   4U
#define Uart_TXEN   3U
#define Uart_UCSZ2  2U
#define Uart_RXB8   1U
#define Uart_TXB8   0U

/* ------------------------------- UCSRC ------------------------------- */
#define Uart_URSEL  7U
#define Uart_UMSEL  6U
#define Uart_UPM1   5U
#define Uart_UPM0   4U
#define Uart_USBS   3U
#define Uart_UCSZ1  2U
#define Uart_UCSZ0  1U
#define Uart_UCPOL  0U

/* ----------------------------- Config values -------------------------- */
#define Uart_AsynchronousMode  0U
#define Uart_SynchronousMode   1U

#define Uart_ParityDisabled    0U
#define Uart_ParityEven        1U
#define Uart_ParityOdd         2U

#define Uart_1StopBit          0U
#define Uart_2StopBit          1U

#define Uart_5BitSize          0U
#define Uart_6BitSize          1U
#define Uart_7BitSize          2U
#define Uart_8BitSize          3U
#define Uart_9BitSize          7U

#define Uart_EnableRxOnly      0U
#define Uart_EnableTxOnly      1U
#define Uart_EnableRxAndTx     2U

#define Uart_InterruptDisabled  0U
#define Uart_InterruptRxOnly    1U
#define Uart_InterruptTxOnly    2U
#define Uart_InterruptUdreOnly  3U
#define Uart_InterruptRxTx      4U
#define Uart_InterruptRxUdre    5U
#define Uart_InterruptTxUdre    6U
#define Uart_InterruptAll       7U

/**
 * @brief UART peripheral configuration, supplied to UART_Init().
 */
typedef struct
{
    uint8_t  ModeSelect;          /**< Uart_AsynchronousMode / Uart_SynchronousMode.        */
    uint8_t  StopBitSelect;       /**< Uart_1StopBit / Uart_2StopBit.                        */
    uint8_t  ParitySelect;        /**< Uart_ParityDisabled / Uart_ParityEven / Uart_ParityOdd.*/
    uint8_t  SizeCharacterSelect; /**< Uart_5BitSize ... Uart_9BitSize.                       */
    uint32_t BaudRate;            /**< Desired baud rate in bits/second, e.g. 9600UL.         */
    uint8_t  EnableSelect;        /**< Uart_EnableRxOnly / TxOnly / RxAndTx.                  */
    uint8_t  SpeedMode;           /**< Uart_NormalSpeed / Uart_DoubleSpeed (U2X).             */
    uint8_t  InterruptSelect;     /**< Uart_InterruptDisabled ... Uart_InterruptAll.          */
} Uart_Config_t;

/** @brief Depth of the RX ring buffer used by the interrupt-driven receive API. */
#ifndef UART_RX_BUFFER_SIZE
#define UART_RX_BUFFER_SIZE    64U
#endif

/** @brief Generic UART driver return codes. */
#define UART_OK       0U
#define UART_TIMEOUT  1U

/* ------------------------------- ISR Vectors --------------------------- */
void __vector_13(void) __attribute__((signal, used)); /**< RX Complete   */
void __vector_14(void) __attribute__((signal, used)); /**< UDR Empty     */
void __vector_15(void) __attribute__((signal, used)); /**< TX Complete   */

/** @} */

#endif /* _UART_PRIVATE_H_ */
