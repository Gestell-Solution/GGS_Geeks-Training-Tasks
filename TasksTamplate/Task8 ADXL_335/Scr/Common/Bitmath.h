#ifndef _BITMATH_H
#define _BITMATH_H

#define SetBit(Reg,BitNo)      ((Reg) |=  (1U << (BitNo)))
#define ClearBit(Reg,BitNo)    ((Reg) &= ~(1U << (BitNo)))
#define ToggleBit(Reg,BitNo)   ((Reg) ^=  (1U << (BitNo)))

/* Fully parenthesized: the old version expanded to (Reg>>BitNo)&0x01,
 * so "ReadBit(x,n) == 0" became "(x>>n) & (0x01 == 0)" = always 0. */
#define ReadBit(Reg,BitNo)     (((Reg) >> (BitNo)) & 0x01U)

#define ReadFlag(Reg,FlagNo)   ReadBit(Reg,FlagNo)
#define ClearFlag(Reg,FlagNo)  SetBit(Reg,FlagNo)

#endif