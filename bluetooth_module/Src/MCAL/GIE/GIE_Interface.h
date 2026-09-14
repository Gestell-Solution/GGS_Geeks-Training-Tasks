/**
 * @file      GIE_Interface.h
 * @author    Beshoy
 * @author    Hesham Ahmed (Reviewer)
 * @brief     Interface of the GIE (Global Interrupt Enable) Driver.
 * @details   This file contains the function prototypes and public APIs used by 
 *            upper layers to enable or disable global interrupts in the system.
 * @version   1.0.0
 * @date      3 August 2026
 * @copyright Copyright (c) 2026, Gestell Company
 */


#ifndef _GIE_INTERFACE_H
#define _GIE_INTERFACE_H

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/COMMON_MACROS.h"
#include "../REG_MAP.h"
#include "GIE_Private.h"

void GIE_Enable();
void GIE_Disable();


#endif 
