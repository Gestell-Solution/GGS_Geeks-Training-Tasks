#include "Timer0_Interface.h"
#include <stddef.h>

static uint8_t StaticPWMOutputMode = 0;

static void (*Timer0_OVFCallBack)(void) = NULL;
static void (*Timer0_CTCCallBack)(void) = NULL;


void TIMER0_Init(Timer0_Config_t Config)
{
    TCCR0 = ClearRegister;

    if(Config.TimerMode == Timer0_NormalMode)
    {
        /* Select Normal Mode */
        CLEAR_BIT(TCCR0, Timer0_WGM00);
        CLEAR_BIT(TCCR0, Timer0_WGM01);

        /* Update Preload Value */
        TCNT0 = Config.PreloadValue;

        /* Enable Overflow Interrupt */
        SET_BIT(TIMSK, Timer0_TOIE0);
    }

    else if(Config.TimerMode == Timer0_CTCMode)
    {
        /* Select CTC Mode */
        SET_BIT(TCCR0, Timer0_WGM01);
        CLEAR_BIT(TCCR0, Timer0_WGM00);

        /* Update Compare Match Value */
        OCR0 = Config.CompareMatchValue;

        /* Enable Compare Match Interrupt */
        // SET_BIT(TIMSK, Timer0_OCIE0);
    }

    else if(Config.TimerMode == Timer0_FastPWM)
    {
        /* Select Fast PWM Mode */
        SET_BIT(TCCR0, Timer0_WGM00);
        SET_BIT(TCCR0, Timer0_WGM01);

        if(Config.PWMOutputMode == Timer0_OC0NinInverting)
        {
            CLEAR_BIT(TCCR0, Timer0_COM00);
            SET_BIT(TCCR0, Timer0_COM01);

            StaticPWMOutputMode = Timer0_OC0NinInverting;
        }

        else if(Config.PWMOutputMode == Timer0_OC0Inverting)
        {
            SET_BIT(TCCR0, Timer0_COM00);
            SET_BIT(TCCR0, Timer0_COM01);

            StaticPWMOutputMode = Timer0_OC0Inverting;
        }

        TIMER0_SetPWMDutyCycle(Config.DutyCycleInitValue);
    }

    else if(Config.TimerMode == Timer0_PhaseCorrectPWM)
    {
        /* Select Phase Correct PWM Mode */
        SET_BIT(TCCR0, Timer0_WGM00);
        CLEAR_BIT(TCCR0, Timer0_WGM01);

        if(Config.PWMOutputMode == Timer0_OC0NinInverting)
        {
            CLEAR_BIT(TCCR0, Timer0_COM00);
            SET_BIT(TCCR0, Timer0_COM01);

            StaticPWMOutputMode = Timer0_OC0NinInverting;
        }

        else if(Config.PWMOutputMode == Timer0_OC0Inverting)
        {
            SET_BIT(TCCR0, Timer0_COM00);
            SET_BIT(TCCR0, Timer0_COM01);

            StaticPWMOutputMode = Timer0_OC0Inverting;
        }

        TIMER0_SetPWMDutyCycle(Config.DutyCycleInitValue);
    }
}

void TIMER0_Start(uint8_t ClockSelectValue)
{
    if(ClockSelectValue != Timer0_Disable)
    {
        TCCR0 = (TCCR0 & ~ClockSelectMask) | ClockSelectValue;
    }
}
void TIMER0_Stop(void)
{
    TCCR0 = (TCCR0 & ~ClockSelectMask) | Timer0_Disable;
}
void TIMER0_SetPreload(uint8_t PreloadValue)
{
    TCNT0 = PreloadValue;
}
void TIMER0_SetCompare(uint8_t CompareValue)
{
    OCR0 = CompareValue;
}

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

        OCR0 = LocalCompareValue;
    }
}

/* Timer0 Compare Match Interrupt */
void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{
    if(Timer0_CTCCallBack != Null)
    {
        Timer0_CTCCallBack();
    }
}

/* Timer0 Overflow Interrupt */
void __vector_11(void) __attribute__((signal));
void __vector_11(void)
{
    if(Timer0_OVFCallBack != Null)
    {
        Timer0_OVFCallBack();
    }
}