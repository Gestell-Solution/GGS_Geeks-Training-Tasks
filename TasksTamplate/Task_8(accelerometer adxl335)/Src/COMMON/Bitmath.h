/**
 * @file Bitmath.h
 * @brief Bit manipulation macros.
 * @details Provides common macros for setting, clearing, toggling, and reading
 *          individual bits and flags of 8-bit registers.
 * @version 1.1.0
 * @author Yousef Mohamed
 * @date 2026-09-24
 * @copyright Copyright (c) 2026, Gestell Company. All rights reserved.
 */

#ifndef BITMATH_H
#define BITMATH_H

#include <stdint.h>

#define SetBit(Reg, BitNo)       ((Reg) |= (uint8_t)(1U << (BitNo)))

#define ClearBit(Reg, BitNo)     ((Reg) &= (uint8_t) ~(1U << (BitNo)))

#define ToggleBit(Reg, BitNo)    ((Reg) ^= (uint8_t)(1U << (BitNo)))

#define ReadBit(Reg, BitNo)      ((uint8_t)(((Reg) >> (BitNo)) & 1U))

#define ReadFlag(Reg, FlagNo)   ReadBit((Reg), (FlagNo))

#define ClearFlag(Reg, FlagNo)  ((Reg) |= (uint8_t)(1U << (FlagNo)))


#endif 
