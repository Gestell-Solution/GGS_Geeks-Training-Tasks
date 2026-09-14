/**
 * @file UART_Config.h
 * @brief Configuration definitions for the UART driver 
 * @details This file is supposed to contain the compile-time configuration parameters
 * required to initialize and operate the UART driver.
 * @version 0.1
 * @author Malak Mohammed (malak.mohammed.esmail@gmail.com) 
 * @date 14-09-2026
 * @copyright Copyright (c) 2026, Gestell Company
 */

#ifndef _UART_CONFIG_H
#define _UART_CONFIG_H

/** @brief Default timeout threshold to prevent MCU Blocking */
#define UART_MaxTimeOut 50000UL

/** @brief to be returned when the program fails to receive via UART after MAXTIMEOUT is reached */
#define UART_TimeOut_Error 0xFFFF

/** @brief Default timeout threshold to prevent MCU Blocking while transmitting strings  */
#define UART_Max_StringTimeout  100000UL

#endif