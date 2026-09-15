```c
/*
 * @file         Timer.c
 * @brief        Timer driver implementation.
 * @details      Provides a 1 ms time base for timeout handling.
 * @copyright    Copyright (c) 2026 Gestell-Co. All rights reserved.
 * @author       Rouaa Ayman (Rouaaayman2602@gmail.com)
 * @version      0.1
 * @date         2026-09-14
 *
 * @copyright    Copyright (c) 2026
 *
 */

#include <avr/io.h>
#include <avr/interrupt.h>

#include "STD_Types.h"
#include "Timer.h"

static volatile u32 timer_milliseconds = 0U;

/**
 * @brief Initializes Timer0 to generate a 1 ms time base.
 * @details Configures Timer0 in CTC mode with a 64 prescaler
 *          and a compare value of 124 at 8 MHz.
 */
void Timer_Init(void)
{
    /* Configure Timer0 in CTC mode. */
    TCCR0 = (1U << WGM01);

    /*
     * F_CPU = 8 MHz
     * Prescaler = 64
     * Compare value = 124
     * Interrupt frequency = 1 kHz = 1 ms
     */
    OCR0 = 124U;

    /* Enable Timer0 Compare Match interrupt. */
    TIMSK |= (1U << OCIE0);

    /* Start Timer0 with a prescaler of 64. */
    TCCR0 |= (1U << CS01) | (1U << CS00);

    /* Enable global interrupts. */
    sei();
}

/**
 * @brief Returns the elapsed time in milliseconds.
 * @return Number of elapsed milliseconds.
 */
u32 Timer_GetMilliseconds(void)
{
    u32 milliseconds;
    u8 interrupt_state;

    interrupt_state = SREG;

    cli();

    milliseconds = timer_milliseconds;

    SREG = interrupt_state;

    return milliseconds;
}

/**
 * @brief Timer0 Compare Match interrupt service routine.
 * @details Increments the millisecond counter every 1 ms.
 */
ISR(TIMER0_COMP_vect)
{
    timer_milliseconds++;
}
```
