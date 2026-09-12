/**
 * @file EXTI_Program.c
 * @brief EXTI Program driver implementation.
 * @details Contains the implementation of the module APIs and internal helper functions.
 * @version 1.0.0
 * @author Yousef
 * @date 2026-09-12
 * @copyright Copyright (c) 2026, Embedded Systems Project
 */


#include "EXTI_Interface.h"

/**
 * @fn EXTI_Init
 * @brief Executes the exti init operation.
 * @details Performs the operation required by the module while preserving the module interface.
 * @param InterruptName Input parameter.
 * @param SensConfig Module configuration structure.
 * @return void
 * @note Ensure module initialization is completed before calling dependent APIs.
 */
void EXTI_Init(uint8_t InterruptName,uint8_t SensConfig)
{
    if(InterruptName==Exti_Interrupt0)
    {
        if(SensConfig==Exti_LowLevel)
        {
            ClearBit(MCUCR_Reg,Exti_ISC00);
            ClearBit(MCUCR_Reg,Exti_ISC01);
        }
        else if (SensConfig==Exti_AnyChange)
        {
            SetBit(MCUCR_Reg,Exti_ISC00);
            ClearBit(MCUCR_Reg,Exti_ISC01);
        }
        else if (SensConfig==Exti_FallingEdge)
        {
            ClearBit(MCUCR_Reg,Exti_ISC00);
            SetBit(MCUCR_Reg,Exti_ISC01);
        }
        else if (SensConfig==Exti_RisingEdge)
        {
            SetBit(MCUCR_Reg,Exti_ISC00);
            SetBit(MCUCR_Reg,Exti_ISC01);
        }
    }
    else if (InterruptName==Exti_Interrupt1)
    {
        if(SensConfig==Exti_LowLevel)
        {
            ClearBit(MCUCR_Reg,Exti_ISC10);
            ClearBit(MCUCR_Reg,Exti_ISC11);
        }
        else if (SensConfig==Exti_AnyChange)
        {
            SetBit(MCUCR_Reg,Exti_ISC10);
            ClearBit(MCUCR_Reg,Exti_ISC11);
        }
        else if (SensConfig==Exti_FallingEdge)
        {
            ClearBit(MCUCR_Reg,Exti_ISC10);
            SetBit(MCUCR_Reg,Exti_ISC11);
        }
        else if (SensConfig==Exti_RisingEdge)
        {
            SetBit(MCUCR_Reg,Exti_ISC10);
            SetBit(MCUCR_Reg,Exti_ISC11);
        }
    }
    else if (InterruptName==Exti_Interrupt2)
    {
        if(SensConfig==Exti_FallingEdge)
        {
            ClearBit(MCUCSR_Reg,Exti_ISC2);
        }
        else if (SensConfig==Exti_RisingEdge)
        {
            SetBit(MCUCSR_Reg,Exti_ISC2);
        }
    }
}

/**
 * @fn EXTI_Enable
 * @brief Executes the exti enable operation.
 * @details Performs the operation required by the module while preserving the module interface.
 * @param InterruptName Input parameter.
 * @return void
 * @note Ensure module initialization is completed before calling dependent APIs.
 */
void EXTI_Enable(uint8_t InterruptName)
{
    if(InterruptName==Exti_Interrupt0)
    {
        SetBit(GICR_Reg,Exti_INT0);
    }
    else if(InterruptName==Exti_Interrupt1)
    {
        SetBit(GICR_Reg,Exti_INT1);
    }
    else if(InterruptName==Exti_Interrupt2)
    {
        SetBit(GICR_Reg,Exti_INT2);
    }
}


/**
 * @fn EXTI_Disable
 * @brief Executes the exti disable operation.
 * @details Performs the operation required by the module while preserving the module interface.
 * @param InterruptName Input parameter.
 * @return void
 * @note Ensure module initialization is completed before calling dependent APIs.
 */
void EXTI_Disable(uint8_t InterruptName)
{
    if(InterruptName==Exti_Interrupt0)
    {
        ClearBit(GICR_Reg,Exti_INT0);
    }
    else if(InterruptName==Exti_Interrupt1)
    {
        ClearBit(GICR_Reg,Exti_INT1);
    }
    else if(InterruptName==Exti_Interrupt2)
    {
        ClearBit(GICR_Reg,Exti_INT2);
    }
}
