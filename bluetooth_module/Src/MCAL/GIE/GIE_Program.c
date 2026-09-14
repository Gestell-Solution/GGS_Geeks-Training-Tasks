/**
 * @file      GIE_program.c
 * @author    Beshoy
 * @author    Hesham Ahmed (Reviewer)
 * @brief     Implementation of the GIE (Global Interrupt Enable) Driver.
 * @details   This file contains the implementation of the functions to 
 *            enable and disable the global interrupt flag (I-Bit) in the 
 *            Status Register (SREG), which is the master switch for all interrupts.
 * @version   1.0.0
 * @date      3 August 2026
 * @copyright Copyright (c) 2026, Gestell Company
 */


#include "GIE_Interface.h"


void GIE_Enable()
{
    SetBit(SREG,I_Bit);
}
void GIE_Disable()
{
    ClearBit(SREG,I_Bit);
}
