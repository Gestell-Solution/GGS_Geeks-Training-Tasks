/**
 * @file Uart_Private.h
 * @brief Compile-time private definitions for the UART driver.
 * @details Runtime settings (mode, baud rate, parity, ...) are passed to
 *          UART_Init() via UART_Config_t. This file is reserved for
 *          *compile-time* overrides that don't belong in that struct, such
 *          as sizing the RX ring buffer differently per project.
 * @version 1.1.0
 * @author Ali Sotohy <email: alielsotohy2006@gmail.com>
 * @date 2026-09-14
 * @copyright Copyright (c) 2026, Gestell Company
 */

#ifndef UART_PRIVATE_H
#define UART_PRIVATE_H

/**
 * @defgroup UART_PRIVATE_H_GROUP Uart_Private.h definitions
 * @brief Compile-time UART driver private definitions.
 */
#include <stdint.h>

/**
 * @defgroup UCSRA
 * @brief  UCSRA - USART Control and Status Register A
 */
#define Uart_RXC              7U   /*-----------USART Receive Complete------------------ */
#define Uart_TXC              6U   /*----------USART Transmit Complete------------------ */
#define Uart_UDRE             5U   /*----------USART Data Register Empty---------------- */
#define Uart_FE               4U   /*---------------USART Frame Error------------------- */
#define Uart_DOR              3U   /*---------------USART Data OverRun------------------ */
#define Uart_PE               2U   /*---------------USART Parity Error------------------ */
#define Uart_U2X              1U   /*----------------- Double the USART Transmission Speed---------------- */
#define Uart_MPCM             0U   /*--------------- Multi-processor Communication Mode------------------ */

#define Uart_NormalSpeed      0U
#define Uart_DoubleSpeed      1U

/**
 * @defgroup UCSRB
 * @brief  UCSRB - USART Control and Status Register B
 */
#define Uart_RXCIE         7U  /*-----------RX Complete Interrupt Enable------------------ */
#define Uart_TXCIE         6U  /*-----------TX Complete Interrupt Enable------------------ */
#define Uart_UDRIE         5U  /*-----------USART Data Register Empty Interrupt Enable------------------ */
#define Uart_RXEN          4U  /*-----------Receiver Enable------------------ */
#define Uart_TXEN          3U  /*-----------Transmitter Enable------------------ */
#define Uart_UCSZ2         2U  /*-----------Character Size------------------ */
#define Uart_RXB8          1U  /*-----------Receive Data Bit 8------------------ */
#define Uart_TXB8          0U  /*-----------Transmit Data Bit 8------------------ */

/**
 * @defgroup UCSRC
 * @brief  UCSRC - USART Control and Status Register C
 */
#define Uart_URSEL         7U  /*-----------Register Select------------------ */
#define Uart_UMSEL         6U  /*-----------USART Mode Select------------------ */
#define Uart_UPM1          5U  /*-----------Parity Mode Bit 1------------------ */
#define Uart_UPM0          4U  /*-----------Parity Mode Bit 0------------------ */
#define Uart_USBS          3U  /*-----------Stop Bit Select------------------ */
#define Uart_UCSZ1         2U  /*-----------Character Size Bit 1------------------ */
#define Uart_UCSZ0         1U  /*-----------Character Size Bit 0------------------ */
#define Uart_UCPOL         0U  /*-----------Clock Polarity------------------ */

#define Uart_AsyncMode             0U
#define Uart_SyncMode              1U

#define Uart_ParityDisabled        0U
#define Uart_ParityEven            2U
#define Uart_ParityOdd             3U

#define Uart_OneStopBit            0U
#define Uart_TwoStopBits           1U

/* IMPORTANT: these are small sequential codes (0..4), NOT literal bit
 * counts. Uart_Program.c must compare SizeCharacterSelect against
 * Uart_9BitData (4U) - NOT against the literal 9U - or the 9-bit branch
 * can never be reached and 9-bit configs get silently mis-encoded. */
#define Uart_5BitData              0U
#define Uart_6BitData              1U
#define Uart_7BitData              2U
#define Uart_8BitData              3U
#define Uart_9BitData              4U

#define Uart_EnableRxOnly   0U
#define Uart_EnableTxOnly   1U
#define Uart_EnableRxTx     2U

#define Uart_InterruptDisabled       0U
#define Uart_InterruptRxOnly         1U
#define Uart_InterruptTxOnly         2U
#define Uart_InterruptREOnly         3U
#define Uart_InterruptRxTx           4U
#define Uart_InterruptRxRE           5U
#define Uart_InterruptTxRE           6U
#define Uart_InterruptAll            7U

#define CharacterSelectMask 0x06U

/** @brief Default timeout threshold (loop iterations) to prevent MCU blocking on a single byte. */
#define Uart_MaxTimeOut 50000UL

/*
 * DEPRECATED - no longer used by Uart_Program.c since v2.0.0.
 * UART_ReceiveBytePolling() now reports timeouts through the separate
 * UART_Status_t return value (see below) instead of overloading the
 * data channel with a sentinel value, so this can never collide with
 * a real received byte again. Kept only so old code referencing it
 * still compiles; do not use it in new code.
 */
#define Uart_TimeOut_Error 0xFFFFU

/*
 * DEPRECATED - no longer used by Uart_Program.c since v2.0.0.
 * UART_ReceiveStringPolling() now bounds itself using the caller's
 * actual buffer size (MaxLength parameter), which both prevents
 * buffer overflow and makes this generic iteration-count timeout
 * unnecessary. Kept only for backward compatibility.
 */
#define Uart_Max_StringTimeout  100000UL

/**
 * @brief Status codes returned by the polling send/receive/init functions.
 * @note  Conceptually this belongs in the public Uart_Interface.h rather
 *        than this private header - move it there once that file is
 *        available for editing.
 */
typedef enum
{
    UART_OK = 0,
    UART_NOK,
    UART_TIMEOUT
} UART_Status_t;

/**
 * @defgroup UART initialization structure
 * @brief Structure for initializing the UART module
 */
typedef struct
{
    uint8_t  ModeSelect;          /*------------ Uart_AsyncMode or Uart_SyncMode--------------------*/
    uint8_t  StopBitSelect;       /*------------ Uart_OneStopBit or Uart_TwoStopBits-----------------------*/
    uint8_t  ParitySelect;        /*------------ Uart_ParityDisabled or Uart_ParityEven or Uart_ParityOdd.-------------------*/
    uint8_t  SizeCharacterSelect; /*------------ Uart_5BitData to Uart_9BitData (0..4, NOT a bit count).----------------*/
    uint32_t BaudRate;            /*------------ Desired baud rate in bits/second, e.g. 9600UL.-----------------*/
    uint8_t  EnableSelect;        /*------------ Uart_EnableRxOnly / Uart_EnableTxOnly / Uart_EnableRxTx------------------*/
    uint8_t  SpeedMode;           /*------------ Uart_NormalSpeed / Uart_DoubleSpeed (U2X).----------------*/
    uint8_t  InterruptSelect;     /*------------ Uart_InterruptDisabled TO Uart_InterruptAll--------------------*/
} UART_Config_t;

/*------------------------------------ISR VECTORS------------------------------------*/
/* Rx complete */
void __vector_13(void) __attribute__((signal));
/* Data Register Empty */
void __vector_14(void) __attribute__((signal));
/* Tx complete */
void __vector_15(void) __attribute__((signal));

#endif /* UART_PRIVATE_H */