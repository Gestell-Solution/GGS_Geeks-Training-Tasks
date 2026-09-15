/*
 * @file         Timer.h
 * @brief        Timer driver interface.
 * @details      Provides a millisecond time base for timeout handling.
 * @copyright    Copyright (c) 2026 Gestell-Co. All rights reserved.
 * @author       Rouaa Ayman (Rouaaayman2602@gmail.com)
 * @version      0.1
 * @date         2026-09-14
 *
 * @copyright    Copyright (c) 2026
 *
 */

#ifndef TIMER_H
#define TIMER_H

#include "STD_Types.h"

/**
 * @brief Initializes the timer and starts the millisecond time base.
 */
void Timer_Init(void);

/**
 * @brief Returns the elapsed time in milliseconds.
 * @return Number of elapsed milliseconds.
 */
u32 Timer_GetMilliseconds(void);

#endif /* TIMER_H */