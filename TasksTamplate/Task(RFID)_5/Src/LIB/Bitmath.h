#ifndef _BITMATH_H
#define _BITMATH_H 

#define SET_BIT(Reg,BitNo)      Reg|=(1<<BitNo)
#define CLEAR_BIT(Reg,BitNo)    Reg&=~(1<<BitNo)
#define TOGGLE_BIT(Reg,BitNo)   Reg^=(1<<BitNo)
#define READ_BIT(Reg,BitNo)     (((Reg)>>(BitNo)) & 0x01)


#define ReadFlag(Reg,FlagNo)   READ_BIT(Reg,FlagNo)
#define ClearFlag(Reg,FlagNo)  SET_BIT(Reg,FlagNo)

#endif