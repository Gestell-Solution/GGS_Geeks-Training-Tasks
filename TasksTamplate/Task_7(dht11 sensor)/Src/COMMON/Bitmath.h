#ifndef BITMATH_H_
#define BITMATH_H_

#include <stdint.h>

#define SET_BIT(Reg, BitNo)     ((Reg) |= (uint8_t)(1U << (BitNo)))
#define CLEAR_BIT(Reg, BitNo)   ((Reg) &= (uint8_t)~(uint8_t)(1U << (BitNo)))
#define TOGGLE_BIT(Reg, BitNo)  ((Reg) ^= (uint8_t)(1U << (BitNo)))
#define READ_BIT(Reg, BitNo)    ((uint8_t)(((Reg) >> (BitNo)) & 1U))

#define ReadFlag(Reg, FlagNo)   READ_BIT((Reg), (FlagNo))
#define ClearFlag(Reg, FlagNo)  SET_BIT((Reg), (FlagNo))

#endif /* BITMATH_H_ */
