#include "Timer0_Interface.h"



static uint8_t StaticPWMOutputMode = 0;
static void (*Timer0_OVFCallBack)(void)=Null;
static void (*Timer0_CTCCallBack)(void)=Null;



void TIMER0_Init(Timer0_Config_t Config)
{
    TCCR0 = ClearRegister ; 
    if(Config.TimerMode==Timer0_NormalMode)
    {
        // Select the Normal Mode from TCCR0 
        CLEAR_BIT(TCCR0,Timer0_WGM00);
         CLEAR_BIT(TCCR0,Timer0_WGM01);
        //Update the Preload value 
        TCNT0=Config.PreloadValue;
        // Enable the Interrupt for OverFlow 
        SET_BIT(TIMSK,Timer0_TOIE0);
        
    }
    else if (Config.TimerMode==Timer0_CTCMode)
    {
        // Select the CTC Mode from TCCR0 
         CLEAR_BIT(TCCR0,Timer0_WGM00);
        SET_BIT(TCCR0,Timer0_WGM01);
        // Update the Compare  value 
        OCR0=Config.CompareMatchValue;
        // Enable the Interrupt for CompareMatch 
        SET_BIT(TIMSK,Timer0_OCIE0);
    }
    else if (Config.TimerMode==Timer0_FastPWM)
    { 
        SET_BIT(TCCR0,Timer0_COM01);
        CLEAR_BIT(TCCR0,Timer0_COM00);
        SET_BIT(TCCR0,Timer0_WGM00);
        SET_BIT(TCCR0,Timer0_WGM01);
        OCR0 = Config.CompareMatchValue ; 
        // if(Config.PWMOutputMode==Timer0_OC0NinInverting)
        // {
        // SET_BIT(TCCR0,Timer0_COM01);
        // CLEAR_BIT(TCCR0,Timer0_COM00);
        // StaticPWMOutputMode = Timer0_OC0NinInverting ;
        // }
        // else if (Config.PWMOutputMode==Timer0_OC0Inverting)
        // {
        //     SET_BIT(TCCR0,Timer0_COM00);
        //     SET_BIT(TCCR0,Timer0_COM01);
        //     StaticPWMOutputMode = Timer0_OC0Inverting ;
        // }
        //  OCR0 = Config.CompareMatchValue ; 
         
    }
    else if (Config.TimerMode==Timer0_PhaseCorrectPWM)
    {
        SET_BIT(TCCR0,Timer0_WGM00);
         CLEAR_BIT(TCCR0,Timer0_WGM01);
        if(Config.PWMOutputMode==Timer0_OC0NinInverting)
        {
             CLEAR_BIT(TCCR0,Timer0_COM00);
            SET_BIT(TCCR0,Timer0_COM01);
            StaticPWMOutputMode = Timer0_OC0NinInverting ;
        }
        else if(Config.PWMOutputMode==Timer0_OC0Inverting)
        {
            SET_BIT(TCCR0,Timer0_COM00);
            SET_BIT(TCCR0,Timer0_COM01);
            StaticPWMOutputMode = Timer0_OC0Inverting ;
        }
        OCR0 = ClearRegister;
    }

}

void TIMER0_Start(uint8_t ClockSelectValue)
{
    if (ClockSelectValue!=Timer0_Disable)
    {
      TCCR0 = (TCCR0 &~ClockSelectMask)|ClockSelectValue;
    }
}
void TIMER0_Stop(void)
{   
    TCCR0 = (TCCR0 &~ClockSelectMask)|Timer0_Disable;
}

void TIMER0_SetPreload(uint8_t PreloadValue)
{
    TCNT0=PreloadValue;
}
void TIMER0_SetCompare(uint8_t CompareValue)
{
    OCR0=CompareValue;
}

void TIMER0_SetCallBackFunction(uint8_t TimerInterruptType, void (*PF)(void))
{
    if(TimerInterruptType==Timer0_OverFlowInterrupt)
    {
      if(PF!=Null)
      {
        Timer0_OVFCallBack=PF;
      }  
    }
    else if (TimerInterruptType==Timer0_CompareMatchInterrupt)
    {
        if(PF!=Null)
        {
            Timer0_CTCCallBack=PF;
        }
    }
}


void TIMER0_SetPWMDutyCycle(uint8_t DutyCyclePercentage )
{
   if(DutyCyclePercentage<=Timer0_MaxDutyCycle)
{
uint8_t LocalCompareValue=0;

if(StaticPWMOutputMode==Timer0_OC0NinInverting)
{
LocalCompareValue=(uint8_t)(((uint32_t)DutyCyclePercentage*Timer0_MaxPWM)/Timer0_MaxDutyCycle) ;
}

else if(StaticPWMOutputMode==Timer0_OC0Inverting)
{
LocalCompareValue = Timer0_MaxPWM - (uint8_t)((Timer0_MaxPWM*(uint32_t)DutyCyclePercentage)/Timer0_MaxDutyCycle) ; 
}
OCR0 = LocalCompareValue ;
    }
}

//Compare Match 
void __vector_10(void)   __attribute__((signal));
void __vector_10(void)
{
    Timer0_CTCCallBack();
}
//OverFlow 
void __vector_11(void)   __attribute__((signal));
void __vector_11(void)
{
    Timer0_OVFCallBack();
}

