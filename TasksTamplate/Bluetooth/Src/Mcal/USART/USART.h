/*
 * @file         USART.h
 * @brief        USART driver interface.
 * @details      Provides basic polling-based USART communication.
 * @copyright    Copyright (c) 2026 Gestell-Co. All rights reserved.
 * @author       Rouaa Ayman (Rouaaayman2602@gmail.com)
 * @version      0.1
 * @date         2026-09-14
 * 
 * @copyright    Copyright (c) 2026
 * 
 */

#ifndef USART_H
#define USART_H

#include "STD_Types.h"

void USART_Init(u32 baudRate);

void USART_SendByte(u8 data);

u8 USART_ReceiveByte(void);

u8 USART_DataAvailable(void);

#endif 
