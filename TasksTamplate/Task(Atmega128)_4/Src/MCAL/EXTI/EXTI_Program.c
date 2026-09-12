/**
 * @file      EXTI_Program.c
 * @author    Abdulrahman Ali 
 * @author    ENG/Hesham Ahmed (Reviewer)
 * @brief     Program of the EXTI Driver.
 * @details    This file contains the function Of EXTI driver
 * @version   1.0.0
 * @date      26 August 2026
 * @copyright Copyright (c) 2026, Gestell Company
 */



#include "EXTI_Interface.h"
#include "EXTI_Private.h"
#include "../../LIB/Definition.h"
#include "../../LIB/Bitmath.h"
#include "../Atmega128regmap.h"

void EXTI_Init(uint8_t InterruptName, uint8_t InterruptSense)
{
    
    if(InterruptName == Exti_INT0)
    {
        if(InterruptSense == Exti_LowLevel)  
        {
            CLEAR_BIT(EICRA, ISC00); 
            CLEAR_BIT(EICRA, ISC01);
        }
        else if(InterruptSense == Exti_AnyChange)
        { 
            SET_BIT(EICRA, ISC00);  
            CLEAR_BIT(EICRA, ISC01);
        }
        else if(InterruptSense == Exti_FallingEdge)
        { 
            CLEAR_BIT(EICRA, ISC00); 
            SET_BIT(EICRA, ISC01); 
        }
        else if(InterruptSense == Exti_RisingEdge)
        { 
            SET_BIT(EICRA, ISC00);
            SET_BIT(EICRA, ISC01); 
        }
    }
    else if(InterruptName == Exti_INT1)
    {
        if(InterruptSense == Exti_LowLevel)
        {
            CLEAR_BIT(EICRA, ISC10);
            CLEAR_BIT(EICRA, ISC11); 
        }
        else if(InterruptSense == Exti_AnyChange)
        { 
            SET_BIT(EICRA, ISC10);
            CLEAR_BIT(EICRA, ISC11);
        }
        else if(InterruptSense == Exti_FallingEdge)
        {
            CLEAR_BIT(EICRA, ISC10);
            SET_BIT(EICRA, ISC11); 
        }
        else if(InterruptSense == Exti_RisingEdge)
        { 
            SET_BIT(EICRA, ISC10);  
            SET_BIT(EICRA, ISC11); 
        }
    }
    else if(InterruptName == Exti_INT2)
    {
        if(InterruptSense == Exti_LowLevel)   
        { 
            CLEAR_BIT(EICRA, ISC20); 
            CLEAR_BIT(EICRA, ISC21);
        }
        else if(InterruptSense == Exti_AnyChange)
        {
            SET_BIT(EICRA, ISC20);  
            CLEAR_BIT(EICRA, ISC21);
        }
        else if(InterruptSense == Exti_FallingEdge)
        { 
            CLEAR_BIT(EICRA, ISC20);
            SET_BIT(EICRA, ISC21); 
        }
        else if(InterruptSense == Exti_RisingEdge) 
        {
            SET_BIT(EICRA, ISC20);
            SET_BIT(EICRA, ISC21);  
        }
    }
    else if(InterruptName == Exti_INT3)
    {
        if(InterruptSense == Exti_LowLevel) 
        {
             CLEAR_BIT(EICRA, ISC30);
            CLEAR_BIT(EICRA, ISC31);
        }
        else if(InterruptSense == Exti_AnyChange)
        { 
            SET_BIT(EICRA, ISC30); 
            CLEAR_BIT(EICRA, ISC31);
        }
        else if(InterruptSense == Exti_FallingEdge)
        {
            CLEAR_BIT(EICRA, ISC30); 
            SET_BIT(EICRA, ISC31);  
        }
        else if(InterruptSense == Exti_RisingEdge) 
        { 
            SET_BIT(EICRA, ISC30);  
            SET_BIT(EICRA, ISC31); 
        }
    }

    else if(InterruptName == Exti_INT4)
    {
        if(InterruptSense == Exti_LowLevel)  
        {
            CLEAR_BIT(EICRB, ISC40);
            CLEAR_BIT(EICRB, ISC41);
        }
        else if(InterruptSense == Exti_AnyChange) 
        { 
            SET_BIT(EICRB, ISC40); 
            CLEAR_BIT(EICRB, ISC41);
        }
        else if(InterruptSense == Exti_FallingEdge)
        { 
            CLEAR_BIT(EICRB, ISC40);
            SET_BIT(EICRB, ISC41); 
        }
        else if(InterruptSense == Exti_RisingEdge)
        {
            SET_BIT(EICRB, ISC40); 
            SET_BIT(EICRB, ISC41); 
        }
    }
    else if(InterruptName == Exti_INT5)
    {
        if(InterruptSense == Exti_LowLevel) 
        {
            CLEAR_BIT(EICRB, ISC50);
            CLEAR_BIT(EICRB, ISC51); 
        }
        else if(InterruptSense == Exti_AnyChange)
        { 
            SET_BIT(EICRB, ISC50);  
            CLEAR_BIT(EICRB, ISC51);
        }
        else if(InterruptSense == Exti_FallingEdge)
        { 
            CLEAR_BIT(EICRB, ISC50); 
            SET_BIT(EICRB, ISC51); 
        }
        else if(InterruptSense == Exti_RisingEdge)
        { 
            SET_BIT(EICRB, ISC50); 
            SET_BIT(EICRB, ISC51); 
        }
    }
    else if(InterruptName == Exti_INT6)
    {
        if(InterruptSense == Exti_LowLevel) 
        {
            CLEAR_BIT(EICRB, ISC60);
            CLEAR_BIT(EICRB, ISC61);
        }
        else if(InterruptSense == Exti_AnyChange)
        { 
            SET_BIT(EICRB, ISC60);
            CLEAR_BIT(EICRB, ISC61);
        }
        else if(InterruptSense == Exti_FallingEdge)
        { 
            CLEAR_BIT(EICRB, ISC60);
            SET_BIT(EICRB, ISC61); 
        }
        else if(InterruptSense == Exti_RisingEdge)
        { 
            SET_BIT(EICRB, ISC60); 
            SET_BIT(EICRB, ISC61); 
        }
    }
    else if(InterruptName == Exti_INT7)
    {
        if(InterruptSense == Exti_LowLevel)  
        { 
            CLEAR_BIT(EICRB, ISC70); 
            CLEAR_BIT(EICRB, ISC71); 
        }
        else if(InterruptSense == Exti_AnyChange) 
        {
            SET_BIT(EICRB, ISC70); 
            CLEAR_BIT(EICRB, ISC71);
        }
        else if(InterruptSense == Exti_FallingEdge)
        { 
            CLEAR_BIT(EICRB, ISC70);
            SET_BIT(EICRB, ISC71); 
        }
        else if(InterruptSense == Exti_RisingEdge)
        { 
            SET_BIT(EICRB, ISC70); 
            SET_BIT(EICRB, ISC71);  
        }
    }
}


void EXTI_Enable(uint8_t InterruptName)
{
    if(InterruptName <= Exti_INT7)
    {
        SET_BIT(EIMSK, InterruptName);
    }
}



void EXTI_Disable(uint8_t InterruptName)
{
    if(InterruptName <= Exti_INT7)
    {
        CLEAR_BIT(EIMSK, InterruptName);
    }
}

static void (*Ptr[Numbers_Interrupts])(void) = {0};

void EXTI_CallBack(uint8_t InterruptName, void (*Func)(void))
{
    if((InterruptName < Numbers_Interrupts) && (Func != 0))
    {
        Ptr[InterruptName] = Func;
    }
}



void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
    if (Ptr[Exti_Interrupt0] != Null)
    {
        Ptr[Exti_Interrupt0]();
    }
}

void __vector_2(void) __attribute__((signal));
void __vector_2(void)
{
    if (Ptr[Exti_Interrupt1] != Null)
    {
        Ptr[Exti_Interrupt1]();
    }
}

void __vector_3(void) __attribute__((signal));
void __vector_3(void)
{
    if (Ptr[Exti_Interrupt2] != Null)
    {
        Ptr[Exti_Interrupt2]();
    }
}

void __vector_4(void) __attribute__((signal));
void __vector_4(void)
{
    if (Ptr[Exti_Interrupt3] != Null)
    {
        Ptr[Exti_Interrupt3]();
    }
}

void __vector_5(void) __attribute__((signal));
void __vector_5(void)
{
    if (Ptr[Exti_Interrupt4] != Null)
    {
        Ptr[Exti_Interrupt4]();
    }
}

void __vector_6(void) __attribute__((signal));
void __vector_6(void)
{
    if (Ptr[Exti_Interrupt5] != Null)
    {
        Ptr[Exti_Interrupt5]();
    }
}

void __vector_7(void) __attribute__((signal));
void __vector_7(void)
{
    if (Ptr[Exti_Interrupt6] != Null)
    {
        Ptr[Exti_Interrupt6]();
    }
}

void __vector_8(void) __attribute__((signal));
void __vector_8(void)
{
    if (Ptr[Exti_Interrupt7] != Null)
    {
        Ptr[Exti_Interrupt7]();
    }
}