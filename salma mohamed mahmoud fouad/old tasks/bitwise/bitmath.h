#ifndef _BITMATH_H
#define _BITMATH_H

#define setbit(reg,bit_num) (reg|=(1<<bit_num))
#define clearbit(reg,bit_num) (reg&=~(1<<bit_num))//1's complement
#define readbit(reg,bit_num) ((reg>>bit_num)&1)
#define togglebit(reg,bit_num) (reg^=(1<<bit_num))
#endif
