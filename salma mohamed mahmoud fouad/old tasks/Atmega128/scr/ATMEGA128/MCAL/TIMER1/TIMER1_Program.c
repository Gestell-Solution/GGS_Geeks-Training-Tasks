//same as timer1 from atmega32 with small modification
#include"TIMER1_Interface.h"

static void (*TIMER1_OverFlow_Callback)(void)=Null;
static void (*TIMER1_CTCA_Callback)(void)=Null;
static void (*TIMER1_CTCB_Callback)(void)=Null;
static void (*TIMER1_CTCC_Callback)(void)=Null;
static void (*TIMER1_CaptureEvent_Callback)(void)=Null;
static uint64_t StaticPWMoutputMode=0;
static uint64_t StaticPWMoutputMax=0;

void TIMER1_Init(Timer1_config_t config){
    if(config.Mode_type==WGM13_is0){
        ClearBit(TCCR1B_Reg,TIMER1_WGM13);
    if(config.Timer_mode==TIMER1_NORMAL_MODE){
        ClearBit(TCCR1B_Reg,TIMER1_WGM12);
        ClearBit(TCCR1A_Reg,TIMER1_WGM11);
        ClearBit(TCCR1A_Reg,TIMER1_WGM10);
        TCNT1H_Reg=(uint8_t)(config.preloadvalue>>8);
        TCNT1L_Reg=(uint8_t)config.preloadvalue;
        SetBit(TIMSK_Reg,TIMER1_TOIE1);
    }
    else if(config.Timer_mode==TIMER1_PWM8_MODE){
        ClearBit(TCCR1B_Reg,TIMER1_WGM12);
        ClearBit(TCCR1A_Reg,TIMER1_WGM11);
        SetBit(TCCR1A_Reg,TIMER1_WGM10);
        if(config.PwmOutputmode==TIMER1_NonIverting){
            SetBit(TCCR1A_Reg,TIMER1_COM1A1);
            ClearBit(TCCR1A_Reg,TIMER1_COM1A0);
            StaticPWMoutputMode=TIMER1_NonIverting;
        }
        else if(config.PwmOutputmode==TIMER1_Iverting){
            SetBit(TCCR1A_Reg,TIMER1_COM1A1);
            SetBit(TCCR1A_Reg,TIMER1_COM1A0);
            StaticPWMoutputMode=TIMER1_Iverting;
        }
        OCR1AH_Reg=ClearRegister;
        OCR1AL_Reg=ClearRegister;
        StaticPWMoutputMax=TIMER1_PWM_8_Max;
    }
    else if(config.Timer_mode==TIMER1_PWM9_MODE){
        ClearBit(TCCR1B_Reg,TIMER1_WGM12);
        SetBit(TCCR1A_Reg,TIMER1_WGM11);
        ClearBit(TCCR1A_Reg,TIMER1_WGM10);
        if(config.PwmOutputmode==TIMER1_NonIverting){
            SetBit(TCCR1A_Reg,TIMER1_COM1A1);
            ClearBit(TCCR1A_Reg,TIMER1_COM1A0);
            StaticPWMoutputMode=TIMER1_NonIverting;
        }
        else if(config.PwmOutputmode==TIMER1_Iverting){
            SetBit(TCCR1A_Reg,TIMER1_COM1A1);
            SetBit(TCCR1A_Reg,TIMER1_COM1A0);
            StaticPWMoutputMax=TIMER1_Iverting;
        }
        OCR1AH_Reg=ClearRegister;
        OCR1AL_Reg=ClearRegister;
        StaticPWMoutputMode=TIMER1_PWM_9_Max;
    }
    else if(config.Timer_mode==TIMER1_PWM10_MODE){
        ClearBit(TCCR1B_Reg,TIMER1_WGM12);
        SetBit(TCCR1A_Reg,TIMER1_WGM11);
        SetBit(TCCR1A_Reg,TIMER1_WGM10);
        if(config.PwmOutputmode==TIMER1_NonIverting){
            SetBit(TCCR1A_Reg,TIMER1_COM1A1);
            ClearBit(TCCR1A_Reg,TIMER1_COM1A0);
            StaticPWMoutputMode=TIMER1_NonIverting;
        }
        else if(config.PwmOutputmode==TIMER1_Iverting){
            SetBit(TCCR1A_Reg,TIMER1_COM1A1);
            SetBit(TCCR1A_Reg,TIMER1_COM1A0);
            StaticPWMoutputMode=TIMER1_Iverting;
        }
        OCR1AH_Reg=ClearRegister;
        OCR1AL_Reg=ClearRegister;
        StaticPWMoutputMax=TIMER1_PWM_10_Max;
    }
    else if(config.Timer_mode==TIMER1_CTC_OCRA_MODE){
        SetBit(TCCR1B_Reg,TIMER1_WGM12);
        ClearBit(TCCR1A_Reg,TIMER1_WGM11);
        ClearBit(TCCR1A_Reg,TIMER1_WGM10);
        OCR1AH_Reg=(uint8_t)(config.comparevalue>>8);
        OCR1AL_Reg=(uint8_t)config.comparevalue;
        SetBit(TIMSK_Reg,TIMER1_OCIE1A);
    }
    else if(config.Timer_mode==TIMER1_FAST_PWM8_MODE){
        SetBit(TCCR1B_Reg,TIMER1_WGM12);
        ClearBit(TCCR1A_Reg,TIMER1_WGM11);
        SetBit(TCCR1A_Reg,TIMER1_WGM10);
        if(config.PwmOutputmode==TIMER1_NonIverting){
            SetBit(TCCR1A_Reg,TIMER1_COM1A1);
            ClearBit(TCCR1A_Reg,TIMER1_COM1A0);
            StaticPWMoutputMode=TIMER1_NonIverting;
        }
        else if(config.PwmOutputmode==TIMER1_Iverting){
            SetBit(TCCR1A_Reg,TIMER1_COM1A1);
            SetBit(TCCR1A_Reg,TIMER1_COM1A0);
            StaticPWMoutputMode=TIMER1_Iverting;
        }
        OCR1AH_Reg=ClearRegister;
        OCR1AL_Reg=ClearRegister;
        StaticPWMoutputMax=TIMER1_FAST_PWM_8_Max;
    }
    else if(config.Timer_mode==TIMER1_FAST_PWM9_MODE){
        SetBit(TCCR1B_Reg,TIMER1_WGM12);
        SetBit(TCCR1A_Reg,TIMER1_WGM11);
        ClearBit(TCCR1A_Reg,TIMER1_WGM10);
        if(config.PwmOutputmode==TIMER1_NonIverting){
            SetBit(TCCR1A_Reg,TIMER1_COM1A1);
            ClearBit(TCCR1A_Reg,TIMER1_COM1A0);
            StaticPWMoutputMode=TIMER1_NonIverting;
        }
        else if(config.PwmOutputmode==TIMER1_Iverting){
            SetBit(TCCR1A_Reg,TIMER1_COM1A1);
            SetBit(TCCR1A_Reg,TIMER1_COM1A0);
            StaticPWMoutputMode=TIMER1_Iverting;
        }
        OCR1AH_Reg=ClearRegister;
        OCR1AL_Reg=ClearRegister;
        StaticPWMoutputMax=TIMER1_FAST_PWM_9_Max;
    }
    else if(config.Timer_mode==TIMER1_FAST_PWM10_MODE){
        SetBit(TCCR1B_Reg,TIMER1_WGM12);
        SetBit(TCCR1A_Reg,TIMER1_WGM11);
        SetBit(TCCR1A_Reg,TIMER1_WGM10);
        if(config.PwmOutputmode==TIMER1_NonIverting){
            SetBit(TCCR1A_Reg,TIMER1_COM1A1);
            ClearBit(TCCR1A_Reg,TIMER1_COM1A0);
            StaticPWMoutputMode=TIMER1_NonIverting;
        }
        else if(config.PwmOutputmode==TIMER1_Iverting){
            SetBit(TCCR1A_Reg,TIMER1_COM1A1);
            SetBit(TCCR1A_Reg,TIMER1_COM1A0);
            StaticPWMoutputMode=TIMER1_Iverting;
        }
        OCR1AH_Reg=ClearRegister;
        OCR1AL_Reg=ClearRegister;
        StaticPWMoutputMax=TIMER1_FAST_PWM_10_Max;
    }
   }
   else if(config.Mode_type==WGM13_is1){
        ClearBit(TCCR1B_Reg,TIMER1_WGM13);
    if(config.Timer_mode==TIMER1_PWM_PHASE_ICR_MODE){
        ClearBit(TCCR1B_Reg,TIMER1_WGM12);
        ClearBit(TCCR1A_Reg,TIMER1_WGM11);
        ClearBit(TCCR1A_Reg,TIMER1_WGM10);
        if(config.PwmOutputmode==TIMER1_NonIverting){
            SetBit(TCCR1A_Reg,TIMER1_COM1A1);
            ClearBit(TCCR1A_Reg,TIMER1_COM1A0);
            StaticPWMoutputMode=TIMER1_NonIverting;
        }
        else if(config.PwmOutputmode==TIMER1_Iverting){
            SetBit(TCCR1A_Reg,TIMER1_COM1A1);
            SetBit(TCCR1A_Reg,TIMER1_COM1A0);
            StaticPWMoutputMode=TIMER1_Iverting;
        }
        OCR1AH_Reg=ClearRegister;
        OCR1AL_Reg=ClearRegister;
        ICR1H_Reg=(uint8_t)(config.capturevalue>>8);
        ICR1L_Reg=(uint8_t)config.capturevalue;
        SetBit(TIMSK_Reg,TIMER1_TICIE1);
    }
    else if(config.Timer_mode==TIMER1_PWM_PHASE_OCRA_MODE){
        ClearBit(TCCR1B_Reg,TIMER1_WGM12);
        ClearBit(TCCR1A_Reg,TIMER1_WGM11);
        SetBit(TCCR1A_Reg,TIMER1_WGM10);
        if(config.PwmOutputmode==TIMER1_NonIverting){
            SetBit(TCCR1A_Reg,TIMER1_COM1A1);
            ClearBit(TCCR1A_Reg,TIMER1_COM1A0);
            StaticPWMoutputMode=TIMER1_NonIverting;
        }
        else if(config.PwmOutputmode==TIMER1_Iverting){
            SetBit(TCCR1A_Reg,TIMER1_COM1A1);
            SetBit(TCCR1A_Reg,TIMER1_COM1A0);
            StaticPWMoutputMode=TIMER1_Iverting;
        }
        OCR1AH_Reg=ClearRegister;
        OCR1AL_Reg=ClearRegister;
        StaticPWMoutputMax=TIMER1_MaxPWM;
    }
    else if(config.Timer_mode==TIMER1_PWM_ICR_MODE ){
        ClearBit(TCCR1B_Reg,TIMER1_WGM12);
        SetBit(TCCR1A_Reg,TIMER1_WGM11);
        ClearBit(TCCR1A_Reg,TIMER1_WGM10);
        if(config.PwmOutputmode==TIMER1_NonIverting){
            SetBit(TCCR1A_Reg,TIMER1_COM1A1);
            ClearBit(TCCR1A_Reg,TIMER1_COM1A0);
            StaticPWMoutputMode=TIMER1_NonIverting;
        }
        else if(config.PwmOutputmode==TIMER1_Iverting){
            SetBit(TCCR1A_Reg,TIMER1_COM1A1);
            SetBit(TCCR1A_Reg,TIMER1_COM1A0);
            StaticPWMoutputMode=TIMER1_Iverting;
        }
        OCR1AH_Reg=ClearRegister;
        OCR1AL_Reg=ClearRegister;
        StaticPWMoutputMax=TIMER1_MaxPWM;
        ICR1H_Reg=(uint8_t)(config.capturevalue>>8);
        ICR1L_Reg=(uint8_t)config.capturevalue;
        SetBit(TIMSK_Reg,TIMER1_TICIE1);
    }
    else if(config.Timer_mode==TIMER1_PWM_OCRA_MODE){
        ClearBit(TCCR1B_Reg,TIMER1_WGM12);
        SetBit(TCCR1A_Reg,TIMER1_WGM11);
        SetBit(TCCR1A_Reg,TIMER1_WGM10);
        if(config.PwmOutputmode==TIMER1_NonIverting){
            SetBit(TCCR1A_Reg,TIMER1_COM1A1);
            ClearBit(TCCR1A_Reg,TIMER1_COM1A0);
            StaticPWMoutputMode=TIMER1_NonIverting;
        }
        else if(config.PwmOutputmode==TIMER1_Iverting){
            SetBit(TCCR1A_Reg,TIMER1_COM1A1);
            SetBit(TCCR1A_Reg,TIMER1_COM1A0);
            StaticPWMoutputMode=TIMER1_Iverting;
        }
        OCR1AH_Reg=ClearRegister;
        OCR1AL_Reg=ClearRegister;
        StaticPWMoutputMax=TIMER1_MaxPWM;
    }
    else if(config.Timer_mode==TIMER1_CTC_ICR_MODE){
        SetBit(TCCR1B_Reg,TIMER1_WGM12);
        ClearBit(TCCR1A_Reg,TIMER1_WGM11);
        ClearBit(TCCR1A_Reg,TIMER1_WGM10);
        ICR1H_Reg=(uint8_t)(config.capturevalue>>8);
        ICR1L_Reg=(uint8_t)config.capturevalue;
        SetBit(TIMSK_Reg,TIMER1_TICIE1);
    }
    else if(config.Timer_mode==TIMER1_FAST_PWM_ICR_MODE){
        SetBit(TCCR1B_Reg,TIMER1_WGM12);
        SetBit(TCCR1A_Reg,TIMER1_WGM11);
        ClearBit(TCCR1A_Reg,TIMER1_WGM10);
        if(config.PwmOutputmode==TIMER1_NonIverting){
            SetBit(TCCR1A_Reg,TIMER1_COM1A1);
            ClearBit(TCCR1A_Reg,TIMER1_COM1A0);
            StaticPWMoutputMode=TIMER1_NonIverting;
        }
        else if(config.PwmOutputmode==TIMER1_Iverting){
            SetBit(TCCR1A_Reg,TIMER1_COM1A1);
            SetBit(TCCR1A_Reg,TIMER1_COM1A0);
            StaticPWMoutputMode=TIMER1_Iverting;
        }
        OCR1AH_Reg=ClearRegister;
        OCR1AL_Reg=ClearRegister;
        StaticPWMoutputMax=TIMER1_MaxPWM;
        ICR1H_Reg=(uint8_t)(config.capturevalue>>8);
        ICR1L_Reg=(uint8_t)config.capturevalue;
        SetBit(TIMSK_Reg,TIMER1_TICIE1);
    }
    else if(config.Timer_mode==TIMER1_FAST_PWM_OCRA_MODE){
        SetBit(TCCR1B_Reg,TIMER1_WGM12);
        SetBit(TCCR1A_Reg,TIMER1_WGM11);
        SetBit(TCCR1A_Reg,TIMER1_WGM10);
        if(config.PwmOutputmode==TIMER1_NonIverting){
            SetBit(TCCR1A_Reg,TIMER1_COM1A1);
            ClearBit(TCCR1A_Reg,TIMER1_COM1A0);
            StaticPWMoutputMode=TIMER1_NonIverting;
        }
        else if(config.PwmOutputmode==TIMER1_Iverting){
            SetBit(TCCR1A_Reg,TIMER1_COM1A1);
            SetBit(TCCR1A_Reg,TIMER1_COM1A0);
            StaticPWMoutputMode=TIMER1_Iverting;
        }
        OCR1AH_Reg=ClearRegister;
        OCR1AL_Reg=ClearRegister;
        StaticPWMoutputMax=TIMER1_MaxPWM;
    }
   }
   if(config.noiseEnable==noise_enable){
    SetBit(TCCR1B_Reg,TIMER1_ICNC1);
   }
   else if(config.noiseEnable==noise_disable){
    ClearBit(TCCR1B_Reg,TIMER1_ICNC1);
   }
   if(config.Edge==rising_edge){
    SetBit(TCCR1B_Reg,TIMER1_ICES1);
   }
   else if(config.Edge==falling_edge){
    ClearBit(TCCR1B_Reg,TIMER1_ICES1);
   }
}
// timer start we use there the precaller 
void TIMER1_Start(uint8_t clockValue){
    if((clockValue!=TIMER1_NO_CLOCK_CLOCK)){
        TCCR1B_Reg=(TCCR1B_Reg&~TIMER1_prescaler_mask)|clockValue;
    }
}

void TIMER1_Stop(void){
    TCCR1B_Reg=(TCCR1B_Reg&~TIMER1_prescaler_mask)|TIMER1_NO_CLOCK_CLOCK;
}

void TIMER1_set_preloadValue(uint16_t preloadvalue){
    TCNT1H_Reg=(uint8_t)(preloadvalue>>8);
    TCNT1L_Reg=(uint8_t)preloadvalue;
}

void TIMER1_comparevalue(uint16_t comparevalue){
OCR1AH_Reg=(uint8_t)(comparevalue>>8);
OCR1AL_Reg=(uint8_t)comparevalue;
}

void TIMER1_SetpwmDutyCycle(uint8_t dutyCycle){
    if(dutyCycle<=TIMER1_MaxDutyCycle){
        uint8_t localCompareValue=0;
        if(StaticPWMoutputMode==TIMER1_NonIverting){
            localCompareValue =(uint16_t)(((uint32_t)dutyCycle*StaticPWMoutputMax)/TIMER1_MaxDutyCycle);
        }
        else if(StaticPWMoutputMode==TIMER1_Iverting){
            localCompareValue=StaticPWMoutputMax-(uint16_t)((StaticPWMoutputMax*(uint32_t)dutyCycle)/TIMER1_MaxDutyCycle);
        }
        OCR1AH_Reg=(uint8_t)(localCompareValue>>8);
        OCR1AL_Reg=(uint8_t)localCompareValue;
    }
}

void TIMER1_captureEvent(uint16_t captureValue){
    ICR1H_Reg=(uint8_t)(captureValue>>8);
    ICR1L_Reg=(uint8_t)captureValue;
}

void TIMER1_SETcallBackFunction(uint8_t timerInterruptType,void (*PF)(void)){
if(timerInterruptType==TIMER1_OverFlow){
    if(PF!=Null){
        TIMER1_OverFlow_Callback=PF;
    }
}
else if(timerInterruptType==TIMER1_CTCA){
    if(PF!=Null){
        TIMER1_CTCA_Callback=PF;
    }
}
else if(timerInterruptType==TIMER1_CTCB){
    if(PF!=Null){
        TIMER1_CTCB_Callback=PF;
    }
}
else if(timerInterruptType==TIMER1_CTCC){
    if(PF!=Null){
        TIMER1_CTCC_Callback=PF;
    }
}
else if(timerInterruptType==TIMER1_CaptureEvent){
    if(PF!=Null){
        TIMER1_CaptureEvent_Callback=PF;
    }
}
}

void __vector_11(void)   __attribute__((signal));
void __vector_11(void){
    if(TIMER1_CaptureEvent_Callback!=Null){
    TIMER1_CaptureEvent_Callback();
    }
}
void __vector_12(void)   __attribute__((signal));
void __vector_12(void){
    if(TIMER1_CTCA_Callback!=Null){
    TIMER1_CTCA_Callback();
    }
}
void __vector_13(void)   __attribute__((signal));
void __vector_13(void){
    if(TIMER1_CTCB_Callback!=Null){
    TIMER1_CTCB_Callback();
    }
}
void __vector_14(void)   __attribute__((signal));
void __vector_14(void){
    if(TIMER1_OverFlow_Callback!=Null){
    TIMER1_OverFlow_Callback();
    }
}
void __vector_24(void)   __attribute__((signal));
void __vector_24(void){
    if(TIMER1_CTCC_Callback!=Null){
    TIMER1_CTCC_Callback();
    }
}