/**
 * @file Bitmath.h
 * @brief Bit manipulation macros.
 * @details Provides common macros for setting, clearing, toggling, and reading individual bits and flags.
 * @version 1.0.0
 * @author Yousef Mohamed <email: yousefmohammed867@gmail.com>
 * @date 2026-09-12
 * @copyright Copyright (c) 2026, Embedded Systems Project
 */

#ifndef _BITMATH_H
#define _BITMATH_H

#include <stdint.h>

/**
 * @defgroup BITMATH_H_GROUP Bitmath definitions
 * @brief Related bitmath definitions.
 * @{
 */
/**
 * @def SetBit
 * @brief Sets a selected bit in a register.
 */
#define SetBit(Reg, BitNo) ((Reg) |= (uint8_t)(1U << (BitNo)))

/**
 * @def ClearBit
 * @brief Clears a selected bit in a register.
 */
#define ClearBit(Reg, BitNo) ((Reg) &= (uint8_t)~(uint8_t)(1U << (BitNo)))

/**
 * @def ToggleBit
 * @brief Toggles a selected bit in a register.
 */
#define ToggleBit(Reg, BitNo) ((Reg) ^= (uint8_t)(1U << (BitNo)))

/**
 * @def ReadBit
 * @brief Reads a selected bit from a register.
 */
#define ReadBit(Reg, BitNo) ((uint8_t)(((Reg) >> (BitNo)) & 0x01U))

/**
 * @def ReadFlag
 * @brief Reads a selected flag bit.
 */
#define ReadFlag(Reg, FlagNo) ReadBit((Reg), (FlagNo))

/**
 * @def ClearFlag
 * @brief Clears a write-one-to-clear flag bit.
 * @note The macro sets the selected bit because many MCU status flags are cleared by writing one.
 */
#define ClearFlag(Reg, FlagNo) SetBit((Reg), (FlagNo))

/** @} */

#endif
