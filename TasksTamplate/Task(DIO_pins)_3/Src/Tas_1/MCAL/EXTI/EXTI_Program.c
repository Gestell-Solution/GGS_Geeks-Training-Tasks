#include "EXTI_Interface.h"
#include "EXTI_Private.h"
#include"../../LIB/Definition.h"
#include"../../LIB/Bitmath.h"
#include"../Atmega32regmap.h"



void EXTI_Init(uint8_t InterruptName, uint8_t InterruptSense)
{
    if(InterruptName==Exti_INT0)
    {
        if(InterruptSense==Exti_LowLevel)
        {
            CLEAR_BIT(MCUCR , ISC00);
            CLEAR_BIT(MCUCR , ISC01);
        }
        else if(InterruptSense==Exti_AnyChange)
        {
            SET_BIT(MCUCR, ISC00);
            CLEAR_BIT(MCUCR, ISC01);
        }
        else if(InterruptSense==Exti_FallingEdge)
        {
            CLEAR_BIT(MCUCR, ISC00);
            SET_BIT(MCUCR, ISC01);
        }
        else if(InterruptSense==Exti_RisingEdge)
        {
            SET_BIT(MCUCR, ISC00);
            SET_BIT(MCUCR, ISC01);
        }
    }
    else if(InterruptName==Exti_INT1)
    {
        if(InterruptSense==Exti_LowLevel)
        {
            CLEAR_BIT(MCUCR, ISC10);
            CLEAR_BIT(MCUCR, ISC11);
        }
        else if(InterruptSense==Exti_AnyChange)
        {
            SET_BIT(MCUCR, ISC10);
            CLEAR_BIT(MCUCR, ISC11);
        }
        else if(InterruptSense==Exti_FallingEdge)
        {
            CLEAR_BIT(MCUCR, ISC10);
            SET_BIT(MCUCR, ISC11);
        }
        else if(InterruptSense==Exti_RisingEdge)
        {
            SET_BIT(MCUCR, ISC10);
            SET_BIT(MCUCR, ISC11);
        }
    }
    else if(InterruptName==Exti_INT2)
    {
        if(InterruptSense==Exti_FallingEdge)
        {
            CLEAR_BIT(MCUCSR, ISC2);
        }
        else if(InterruptSense==Exti_RisingEdge)
        {
            SET_BIT(MCUCSR, ISC2);
        }
    }
}

void EXTI_Enable(uint8_t InterruptName)
{
    if(InterruptName == Exti_INT0)
    {
        SET_BIT(GICR, Exti_INT0);
    }
    else if(InterruptName == Exti_INT1)
    {
        SET_BIT(GICR, Exti_INT1);
    }
    else if(InterruptName == Exti_INT2)
    {
        SET_BIT(GICR, Exti_INT2);
    }
}

void EXTI_Disable(uint8_t InterruptName)
{
    if(InterruptName == Exti_INT0)
    {
        CLEAR_BIT(GICR, Exti_INT0);
    }
    else if(InterruptName == Exti_INT1)
    {
        CLEAR_BIT(GICR, Exti_INT1);
    }
    else if(InterruptName == Exti_INT2)
    {
        CLEAR_BIT(GICR, Exti_INT2);
    }
}

static void (*Ptr[Numbers_Interrupts])(void)={0};

void EXTI_CallBack(uint8_t InterruptName, void (*Func)(void))
{
    if((InterruptName <= Exti_Interrupt2) && (Func != 0))
    {
     Ptr[InterruptName]=Func;
    }
}

void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
    if (Ptr[Exti_Interrupt0]!=Null)
    {
     Ptr[Exti_Interrupt0]();
    }
}

void __vector_2(void) __attribute__((signal));
void __vector_2(void)
{
    if (Ptr[Exti_Interrupt1]!=Null)
    {
     Ptr[Exti_Interrupt1]();
    }
}

void __vector_3(void) __attribute__((signal));
void __vector_3(void)
{
    if (Ptr[Exti_Interrupt2]!=Null)
    {
     Ptr[Exti_Interrupt2]();
    }
}
