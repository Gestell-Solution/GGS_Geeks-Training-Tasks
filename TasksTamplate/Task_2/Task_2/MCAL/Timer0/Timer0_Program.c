/**
 * @file Timer0_Program.c
 * @brief Timer0 Program driver implementation.
 * @details Contains the implementation of the module APIs and internal helper functions.
 * @version 1.0.0
 * @author Yousef
 * @date 2026-09-12
 * @copyright Copyright (c) 2026, Embedded Systems Project
 */

#include "Timer0_Interface.h"

static uint8_t StaticPWMOutputMode = 0;

static void (*Timer0_OVFCallBack)(void) = Null;
static void (*Timer0_CTCCallBack)(void) = Null;


/**
 * @fn TIMER0_Init
 * @brief Executes the init operation for Timer0.
 * @details Performs the operation required by the module while preserving the module interface.
 * @param Config Module configuration structure.
 * @return void
 * @note Ensure module initialization is completed before calling dependent APIs.
 */
void TIMER0_Init(Timer0_Config_t Config)
{
    TCCR0_Reg = ClearRegister;

    if(Config.TimerMode == Timer0_NormalMode)
    {
        /* Select Normal Mode */
        ClearBit(TCCR0_Reg, Timer0_WGM00);
        ClearBit(TCCR0_Reg, Timer0_WGM01);

        /* Update Preload Value */
        TCNT0_Reg = Config.PreloadValue;

        /* Enable Overflow Interrupt */
        SetBit(TIMSK_Reg, Timer0_TOIE0);
    }

    else if(Config.TimerMode == Timer0_CTCMode)
    {
        /* Select CTC Mode */
        ClearBit(TCCR0_Reg, Timer0_WGM00);
        SetBit(TCCR0_Reg, Timer0_WGM01);

        /* Update Compare Match Value */
        OCR0_Reg = Config.CompareMatchValue;

        /* Enable Compare Match Interrupt */
        SetBit(TIMSK_Reg, Timer0_OCIE0);
    }

    else if(Config.TimerMode == Timer0_FastPWM)
    {
        /* Select Fast PWM Mode */
        SetBit(TCCR0_Reg, Timer0_WGM00);
        SetBit(TCCR0_Reg, Timer0_WGM01);

        if(Config.PWMOutputMode == Timer0_OC0NinInverting)
        {
            ClearBit(TCCR0_Reg, Timer0_COM00);
            SetBit(TCCR0_Reg, Timer0_COM01);

            StaticPWMOutputMode = Timer0_OC0NinInverting;
        }

        else if(Config.PWMOutputMode == Timer0_OC0Inverting)
        {
            SetBit(TCCR0_Reg, Timer0_COM00);
            SetBit(TCCR0_Reg, Timer0_COM01);

            StaticPWMOutputMode = Timer0_OC0Inverting;
        }

        TIMER0_SetPWMDutyCycle(Config.DutyCycleInitValue);
    }

    else if(Config.TimerMode == Timer0_PhaseCorrectPWM)
    {
        /* Select Phase Correct PWM Mode */
        SetBit(TCCR0_Reg, Timer0_WGM00);
        ClearBit(TCCR0_Reg, Timer0_WGM01);

        if(Config.PWMOutputMode == Timer0_OC0NinInverting)
        {
            ClearBit(TCCR0_Reg, Timer0_COM00);
            SetBit(TCCR0_Reg, Timer0_COM01);

            StaticPWMOutputMode = Timer0_OC0NinInverting;
        }

        else if(Config.PWMOutputMode == Timer0_OC0Inverting)
        {
            SetBit(TCCR0_Reg, Timer0_COM00);
            SetBit(TCCR0_Reg, Timer0_COM01);

            StaticPWMOutputMode = Timer0_OC0Inverting;
        }

        TIMER0_SetPWMDutyCycle(Config.DutyCycleInitValue);
    }
}

/**
 * @fn TIMER0_Start
 * @brief Executes the start operation for Timer0.
 * @details Performs the operation required by the module while preserving the module interface.
 * @param ClockSelectValue Value to be written or configured.
 * @return void
 * @note Ensure module initialization is completed before calling dependent APIs.
 */
void TIMER0_Start(uint8_t ClockSelectValue)
{
    if(ClockSelectValue != Timer0_Disable)
    {
        TCCR0_Reg = (TCCR0_Reg & ~ClockSelectMask) | ClockSelectValue;
    }
}
/**
 * @fn TIMER0_Stop
 * @brief Executes the stop operation for Timer0.
 * @details Performs the operation required by the module while preserving the module interface.
 * @return void
 * @note Ensure module initialization is completed before calling dependent APIs.
 */
void TIMER0_Stop(void)
{
    TCCR0_Reg = (TCCR0_Reg & ~ClockSelectMask) | Timer0_Disable;
}
/**
 * @fn TIMER0_SetPreload
 * @brief Executes the setpreload operation for Timer0.
 * @details Performs the operation required by the module while preserving the module interface.
 * @param PreloadValue Value to be written or configured.
 * @return void
 * @note Ensure module initialization is completed before calling dependent APIs.
 */
void TIMER0_SetPreload(uint8_t PreloadValue)
{
    TCNT0_Reg = PreloadValue;
}
/**
 * @fn TIMER0_SetCompare
 * @brief Executes the setcompare operation for Timer0.
 * @details Performs the operation required by the module while preserving the module interface.
 * @param CompareValue Value to be written or configured.
 * @return void
 * @note Ensure module initialization is completed before calling dependent APIs.
 */
void TIMER0_SetCompare(uint8_t CompareValue)
{
    OCR0_Reg = CompareValue;
}

/**
 * @fn TIMER0_SetCallBackFunction
 * @brief Executes the setcallbackfunction operation for Timer0.
 * @details Performs the operation required by the module while preserving the module interface.
 * @param TimerInterruptType Input parameter.
 * @param CopyFunc Callback function invoked by the module.
 * @return void
 * @note Ensure module initialization is completed before calling dependent APIs.
 */
void TIMER0_SetCallBackFunction(uint8_t TimerInterruptType,void (*PF)(void))
{
    if(TimerInterruptType == Timer0_OverFlowInterrupt)
    {
        if(PF != Null)
        {
            Timer0_OVFCallBack = PF;
        }
    }

    else if(TimerInterruptType == Timer0_CompareMatchInterrupt)
    {
        if(PF != Null)
        {
            Timer0_CTCCallBack = PF;
        }
    }
}


/**
 * @fn TIMER0_SetPWMDutyCycle
 * @brief Executes the setpwmdutycycle operation for Timer0.
 * @details Performs the operation required by the module while preserving the module interface.
 * @param DutyCyclePercentage Input parameter.
 * @return void
 * @note Ensure module initialization is completed before calling dependent APIs.
 */
void TIMER0_SetPWMDutyCycle(uint8_t DutyCyclePercentage)
{
    if(DutyCyclePercentage <= Timer0_MaxDutyCycle)
    {
        uint8_t LocalCompareValue = 0;

        if(StaticPWMOutputMode == Timer0_OC0NinInverting)
        {
            LocalCompareValue =
            (uint8_t)(((uint32_t)DutyCyclePercentage *
            Timer0_MaxPWM) / Timer0_MaxDutyCycle);
        }

        else if(StaticPWMOutputMode == Timer0_OC0Inverting)
        {
            LocalCompareValue =
            Timer0_MaxPWM -
            (uint8_t)((Timer0_MaxPWM *
            (uint32_t)DutyCyclePercentage) /
            Timer0_MaxDutyCycle);
        }

        OCR0_Reg = LocalCompareValue;
    }
}

/* Timer0 Compare Match Interrupt */
/**
 * @fn __vector_10
 * @brief Handles the interrupt service routine for __vector_10.
 * @details Performs the operation required by the module while preserving the module interface.
 * @param CopyFunc Callback function invoked by the module.
 * @return void
 * @note Ensure module initialization is completed before calling dependent APIs.
 */
void __vector_10(void) __attribute__((signal));
/**
 * @fn __vector_10
 * @brief Handles the interrupt service routine for __vector_10.
 * @details Performs the operation required by the module while preserving the module interface.
 * @return void
 * @note Ensure module initialization is completed before calling dependent APIs.
 */
void __vector_10(void)
{
    if(Timer0_CTCCallBack != Null)
    {
        Timer0_CTCCallBack();
    }
}

/* Timer0 Overflow Interrupt */
/**
 * @fn __vector_11
 * @brief Handles the interrupt service routine for __vector_11.
 * @details Performs the operation required by the module while preserving the module interface.
 * @param CopyFunc Callback function invoked by the module.
 * @return void
 * @note Ensure module initialization is completed before calling dependent APIs.
 */
void __vector_11(void) __attribute__((signal));
/**
 * @fn __vector_11
 * @brief Handles the interrupt service routine for __vector_11.
 * @details Performs the operation required by the module while preserving the module interface.
 * @return void
 * @note Ensure module initialization is completed before calling dependent APIs.
 */
void __vector_11(void)
{
    if(Timer0_OVFCallBack != Null)
    {
        Timer0_OVFCallBack();
    }
}
