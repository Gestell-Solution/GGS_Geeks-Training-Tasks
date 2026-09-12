/**
 * @file      EXTI_Private.h
 * @author    Abdulrahman Ali 
 * @author    ENG/Hesham Ahmed (Reviewer)
 * @brief     Private of the EXTI Driver.
 * @details   This file contains the definition of EXTI Registers and EXTI Modes
 * @version   1.0.0
 * @date      26 August 2026
 * @copyright Copyright (c) 2026, Gestell Company
 */







#ifndef _EXTI_PRIVATE_H
#define _EXTI_PRIVATE_H

// EICRA Register (control on INT0 , INT1 , INT2 , INT3)
#define ISC00   0
#define ISC01   1
#define ISC10   2
#define ISC11   3
#define ISC20   4
#define ISC21   5
#define ISC30   6
#define ISC31   7


// EICRB Register (control on INT4 , INT5 , INT6 , INT7)
#define ISC40   0
#define ISC41   1
#define ISC50   2
#define ISC51   3
#define ISC60   4
#define ISC61   5
#define ISC70   6
#define ISC71   7




// EIMSK Register Mask
#define Exti_INT0   0
#define Exti_INT1   1
#define Exti_INT2   2
#define Exti_INT3   3
#define Exti_INT4   4
#define Exti_INT5   5
#define Exti_INT6   6
#define Exti_INT7   7


// EIFR Register Interrupt Flags
#define Exti_INTF0  0
#define Exti_INTF1  1
#define Exti_INTF2  2
#define Exti_INTF3  3
#define Exti_INTF4  4
#define Exti_INTF5  5
#define Exti_INTF6  6
#define Exti_INTF7  7


// Control Modes
#define Exti_LowLevel    0
#define Exti_AnyChange   1
#define Exti_FallingEdge 2
#define Exti_RisingEdge  3

// Interrupt Identifiers
#define Exti_Interrupt0    0 
#define Exti_Interrupt1    1
#define Exti_Interrupt2    2 
#define Exti_Interrupt3    3
#define Exti_Interrupt4    4
#define Exti_Interrupt5    5
#define Exti_Interrupt6    6
#define Exti_Interrupt7    7


#define Numbers_Interrupts   8


#endif 