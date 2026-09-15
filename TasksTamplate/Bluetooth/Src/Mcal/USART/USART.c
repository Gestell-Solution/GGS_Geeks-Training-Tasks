
/*
 * @file         USART.c
 * @brief        USART driver implementation.
 * @details      Provides basic polling-based USART communication.
 * @copyright    Copyright (c) 2026 Gestell-Co. All rights reserved.
 * @author       Rouaa Ayman (Rouaaayman2602@gmail.com)
 * @version      0.1
 * @date         2026-09-14
 *
 * @copyright    Copyright (c) 2026
 *
 */

#include <avr/io.h>

#include "STD_Types.h"
#include "USART.h"

/**
 * @brief Initializes the USART peripheral.
 * @param baudRate USART communication baud rate.
 */
void USART_Init(u32 baudRate)
{
    u16 ubrr_value;

    ubrr_value = (u16)((8000000UL / (16UL * baudRate)) - 1UL);

    UBRRH = (u8)(ubrr_value >> 8U);
    UBRRL = (u8)ubrr_value;

    UCSRB = (1U << RXEN) | (1U << TXEN);

    /* Configure 8-bit data, 1 stop bit, no parity. */
    UCSRC = (1U << URSEL) | (1U << UCSZ1) | (1U << UCSZ0);
}

/**
 * @brief Sends one byte through USART.
 * @param data Byte to be transmitted.
 */
void USART_SendByte(u8 data)
{
    while ((UCSRA & (1U << UDRE)) == 0U)
    {
        /* Wait until transmit buffer is empty. */
    }

    UDR = data;
}

/**
 * @brief Receives one byte through USART.
 * @details This function waits until a byte is received.
 * @return The received byte.
 */
u8 USART_ReceiveByte(void)
{
    while ((UCSRA & (1U << RXC)) == 0U)
    {
        /* Wait until data is received. */
    }

    return UDR;
}

/**
 * @brief Checks whether USART data is available.
 * @return 1U if data is available, otherwise 0U.
 */
u8 USART_DataAvailable(void)
{
    return (u8)((UCSRA & (1U << RXC)) != 0U);
}
