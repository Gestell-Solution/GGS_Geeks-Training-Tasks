/**
 * @file Bitmath.h
 * @author salma mohamed mahmoud fouad(salmafouadothman@gmail.com)
 * @brief these are used for bitwise operation
 * @details we can use the bit wise operation here by just writting the name like setbit for setting a bit to one
 * clearbit for clearing a bit to zero ,togglebit it to make zero one and one zero ,
 * readbit to read if the bit is one or zero,readfalg to read the flag,clearflag is to set the flage
 * @version 0.1
 * @date 2026-09-16
 * @copyright Copyright (c) 2026
 */
#ifndef _BITMATH_H
#define _BITMATH_H 
/**
 * @def SetBit
 * @brief  setbit for setting a bit to one
 * @param Reg  the register that you are going to use
 * @param BitNo the bit number
 */
#define SetBit(Reg,BitNo)      Reg|=(1<<BitNo)
/**
 * @def ClearBit
 * @brief  clearbit for clearing a bit to zero 
 * @param Reg  the register that you are going to use
 * @param BitNo the bit number
 */
#define ClearBit(Reg,BitNo)    Reg&=~(1<<BitNo)
/**
 * @def ToggleBit
 * @brief  togglebit it to make zero one and one zero 
 * @param Reg  the register that you are going to use
 * @param BitNo the bit number
 */
#define ToggleBit(Reg,BitNo)   Reg^=(1<<BitNo)
/**
 * @def ReadBit
 * @brief  readbit to read if the bit is one or zero
 * @param Reg  the register that you are going to use
 * @param BitNo the bit number
 */
#define ReadBit(Reg,BitNo)     ((Reg>>BitNo)&0x01)

/**
 * @def ReadFlag
 * @brief  readfalg to read the flag,clearflag
 * @param Reg  the register that you are going to use
 * @param BitNo the bit number
 */
#define ReadFlag(Reg,FlagNo)   ReadBit(Reg,FlagNo)
/**
 * @def ClearFlag
 * @brief  clearflag is to set the flage
 * @param Reg  the register that you are going to use
 * @param BitNo the bit number
 */
#define ClearFlag(Reg,FlagNo)  SetBit(Reg,FlagNo)

#endif