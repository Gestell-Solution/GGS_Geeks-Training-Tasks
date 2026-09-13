/**
 * @file Bitmath.h
 * @brief Bit manipulation primitives for memory-mapped hardware registers.
 * @details Implemented as `static inline` functions (rather than
 *          function-like macros) per MISRA C:2012 Dir 4.9, which gives the
 *          compiler real argument type-checking and avoids classic macro
 *          side-effect bugs (e.g. `SET_BIT(x++, 3)` double-evaluating `x`).
 * @note This file was missing from the delivered package (Uart_Interface.h
 *       already included it via "../../LIB/Bitmath.h") and has been
 *       (re)created here so the UART driver actually compiles.
 * @version 1.0.0
 * @author Yousef Mohamed <email: yousefmohammed867@gmail.com>
 * @date 2026-09-14
 * @copyright Copyright (c) 2026, Gestell Company
 */
#ifndef _BITMATH_H_
/**
 * @defgroup BITMATH_H_GROUP Bitmath.h definitions
 * @brief Register/variable bit-level helper functions.
 * @{
 */
#define _BITMATH_H_

#include <stdint.h>
#include "Definition.h"

/**
 * @brief Sets (writes 1 to) a single bit of a register or variable.
 * @param Register  Address of the target byte. Pass a memory-mapped
 *                   register with `&SOME_Reg` (SOME_Reg already expands to
 *                   a dereferenced `volatile uint8_t*`, so `&SOME_Reg`
 *                   recovers the register address without losing the
 *                   `volatile` qualifier, per MISRA C:2012 Rule 11.8), or
 *                   `&LocalVariable` for a plain local byte.
 * @param BitNumber Bit position to set (0-7).
 */
static inline void SET_BIT(volatile uint8_t * const Register, const uint8_t BitNumber)
{
    *Register |= (uint8_t)(1U << BitNumber);
}

/**
 * @brief Clears (writes 0 to) a single bit of a register or variable.
 * @param Register  Address of the target byte (see SET_BIT() for usage).
 * @param BitNumber Bit position to clear (0-7).
 */
static inline void CLEAR_BIT(volatile uint8_t * const Register, const uint8_t BitNumber)
{
    *Register &= (uint8_t)(~(uint8_t)(1U << BitNumber));
}

/**
 * @brief Toggles (inverts) a single bit of a register or variable.
 * @param Register  Address of the target byte (see SET_BIT() for usage).
 * @param BitNumber Bit position to toggle (0-7).
 */
static inline void TOGGLE_BIT(volatile uint8_t * const Register, const uint8_t BitNumber)
{
    *Register ^= (uint8_t)(1U << BitNumber);
}

/**
 * @brief Reads a single bit out of an 8-bit value.
 * @param RegisterValue Byte to read from (passed by value: reading never
 *                       needs to mutate the caller, so no pointer/volatile
 *                       is required here).
 * @param BitNumber     Bit position to read (0-7).
 * @return 1U if the bit is set, 0U otherwise.
 */
static inline uint8_t READ_BIT(const uint8_t RegisterValue, const uint8_t BitNumber)
{
    const uint8_t Local_Shifted = (uint8_t)(RegisterValue >> BitNumber);

    return (uint8_t)(Local_Shifted & 0x01U);
}

/**
 * @brief Reads a single bit and returns it as a self-documenting Flag_t
 *        instead of a raw 0/1 integer.
 * @param RegisterValue Byte to read from.
 * @param BitNumber     Bit position to read (0-7).
 * @return FlagUp if the bit is set, FlagDown otherwise.
 */
static inline Flag_t ReadFlag(const uint8_t RegisterValue, const uint8_t BitNumber)
{
    Flag_t Local_Flag;

    if (READ_BIT(RegisterValue, BitNumber) == 1U)
    {
        Local_Flag = FlagUp;
    }
    else
    {
        Local_Flag = FlagDown;
    }

    return Local_Flag;
}

/** @} */

#endif /* _BITMATH_H_ */
