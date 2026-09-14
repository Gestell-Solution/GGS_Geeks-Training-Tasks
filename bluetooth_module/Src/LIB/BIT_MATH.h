#ifndef _BIT_MATH_H_
#define _BIT_MATH_H_

#define SetBit(reg, bitno)         ((reg) |=  (1 << (bitno)))   // to make it 1
#define ClearBit(reg, bitno)       ((reg) &= ~(1 << (bitno)))   // to make it 0
#define ToggleBit(reg, bitno)      ((reg) ^=  (1 << (bitno)))   // to inverse it
#define ReadBit(reg, bitno)        (((reg) >> (bitno)) & 1)     // read the bit

#define ReadFlag(reg , flagno)     ReadBit(reg , flagno)
#define ClearFlag(reg , flagno)    ClearBit(reg , flagno)

#endif