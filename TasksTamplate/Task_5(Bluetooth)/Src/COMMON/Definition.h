/**
 * @file Definition.h
 * @brief Common project-wide type, boolean, and constant definitions.
 * @details Provides shared symbols (null pointer, logical flag states, CPU
 *          clock frequency) used across every MCAL and HAL module so that
 *          all layers of the driver stack speak the same vocabulary.
 * @note This file was missing from the delivered package (Uart_Interface.h
 *       already included it via "../../LIB/Definition.h") and has been
 *       (re)created here so the UART driver actually compiles.
 * @version 1.0.0
 * @author Yousef Mohamed <email: yousefmohammed867@gmail.com>
 * @date 2026-09-14
 * @copyright Copyright (c) 2026, Gestell Company
 */
#ifndef _DEFINITION_H_
/**
 * @defgroup DEFINITION_H_GROUP Definition.h definitions
 * @brief Project-wide shared symbols.
 * @{
 */
#define _DEFINITION_H_

#include <stdint.h>

/**
 * @def Null
 * @brief Project-wide null pointer constant (used instead of the standard
 *        NULL macro so every module has one explicit, documented source).
 */
#define Null    ((void*)0)

/**
 * @def F_CPU
 * @brief System clock frequency in Hz.
 * @details This is the avr-libc *standard* macro name: <util/delay.h> (used
 *          by the UART timeout driver) reads this exact symbol to calibrate
 *          _delay_ms()/_delay_us(). It must be defined *before* any
 *          <util/delay.h> include, which is guaranteed here because every
 *          module includes this file (directly or transitively) before
 *          including <util/delay.h>.
 * @note Override with a `-DF_CPU=xxxxxxxUL` build flag if the target board
 *       is not clocked at the default 8 MHz internal RC oscillator value;
 *       do NOT edit both this file and the build flag, pick one source.
 */
#ifndef F_CPU
#define F_CPU    8000000UL
#endif

/**
 * @brief Generic logical flag state, used to read single-bit hardware flags
 *        (status/interrupt flags) in a self-documenting, MISRA-friendly way
 *        instead of comparing against raw 0/1 literals (MISRA C:2012 Dir 4.6).
 */
typedef enum
{
    FlagDown = 0U, /**< The queried bit/flag is not set (logic 0). */
    FlagUp   = 1U  /**< The queried bit/flag is set (logic 1).     */
} Flag_t;

/** @} */

#endif /* _DEFINITION_H_ */
