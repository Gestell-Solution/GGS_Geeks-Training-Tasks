/**
 * @file Uart_Config.h
 * @brief Compile-time configuration hooks for the UART driver.
 * @details Runtime settings (mode, baud rate, parity, ...) are passed to
 *          UART_Init() via Uart_Config_t. This file is reserved for
 *          *compile-time* overrides that don't belong in that struct, such
 *          as sizing the RX ring buffer differently per project.
 * @version 1.0.0
 * @author Yousef Mohamed <email: yousefmohammed867@gmail.com>
 * @date 2026-09-24
 * @copyright Copyright (c) 2026, Gestell Company
 */
#ifndef _UART_CONFIG_H_
/**
 * @defgroup UART_CONFIG_H_GROUP Uart_Config.h definitions
 * @brief Compile-time UART driver configuration.
 * @{
 */
#define _UART_CONFIG_H_

/*
 * No project-specific overrides required yet. Example of how a future
 * override would look (must be defined here BEFORE Uart_Private.h is
 * included, since that is where UART_RX_BUFFER_SIZE's default lives):
 *
 *     #define UART_RX_BUFFER_SIZE    128U
 */

/** @} */

#endif /* _UART_CONFIG_H_ */
