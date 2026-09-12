#include"EXIT_Interface.h"

void EXTI_Init(uint8_t InterruptName,uint8_t SensConfig){
    if(InterruptName==EXIT_INTERRUPT3_3){
        if(SensConfig==EXIT_lowLevel){
            ClearBit(EICRA_Reg,EXIT_ISC31);
            ClearBit(EICRA_Reg,EXIT_ISC30);
        }
        else if(SensConfig==EXIT_fallingEdge){
            SetBit(EICRA_Reg,EXIT_ISC31);
            ClearBit(EICRA_Reg,EXIT_ISC30);
        }
        else if(SensConfig==EXIT_risingEdge){
            SetBit(EICRA_Reg,EXIT_ISC31);
            SetBit(EICRA_Reg,EXIT_ISC30);
        }
    }
    else if(InterruptName==EXIT_INTERRUPT3_2){
        if(SensConfig==EXIT_lowLevel){
            ClearBit(EICRA_Reg,EXIT_ISC21);
            ClearBit(EICRA_Reg,EXIT_ISC20);
        }
        else if(SensConfig==EXIT_fallingEdge){
            SetBit(EICRA_Reg,EXIT_ISC21);
            ClearBit(EICRA_Reg,EXIT_ISC20);
        }
        else if(SensConfig==EXIT_risingEdge){
            SetBit(EICRA_Reg,EXIT_ISC21);
            SetBit(EICRA_Reg,EXIT_ISC20);
        }
    }
    else if(InterruptName==EXIT_INTERRUPT3_1){
        if(SensConfig==EXIT_lowLevel){
            ClearBit(EICRA_Reg,EXIT_ISC11);
            ClearBit(EICRA_Reg,EXIT_ISC10);
        }
        else if(SensConfig==EXIT_fallingEdge){
            SetBit(EICRA_Reg,EXIT_ISC11);
            ClearBit(EICRA_Reg,EXIT_ISC10);
        }
        if(SensConfig==EXIT_risingEdge){
            SetBit(EICRA_Reg,EXIT_ISC11);
            SetBit(EICRA_Reg,EXIT_ISC10);
        }
    }
    else if(InterruptName==EXIT_INTERRUPT3_0){
        if(SensConfig==EXIT_lowLevel){
            ClearBit(EICRA_Reg,EXIT_ISC01);
            ClearBit(EICRA_Reg,EXIT_ISC00);
        }
        else if(SensConfig==EXIT_fallingEdge){
            SetBit(EICRA_Reg,EXIT_ISC01);
            ClearBit(EICRA_Reg,EXIT_ISC00);
        }
        if(SensConfig==EXIT_risingEdge){
            SetBit(EICRA_Reg,EXIT_ISC01);
            SetBit(EICRA_Reg,EXIT_ISC00);
        }
    }
    else if(InterruptName==EXIT_INTERRUPT7_7){
        if(SensConfig==EXIT_lowLevel){
            ClearBit(EICRB_Reg,EXIT_ISC71);
            ClearBit(EICRB_Reg,EXIT_ISC70);
        }
        else if(SensConfig==EXIT_ISC_anyLogic){
            ClearBit(EICRB_Reg,EXIT_ISC71);
            SetBit(EICRB_Reg,EXIT_ISC70);
        }
        else if(SensConfig==EXIT_fallingEdge){
            SetBit(EICRB_Reg,EXIT_ISC71);
            ClearBit(EICRB_Reg,EXIT_ISC70);
        }
        if(SensConfig==EXIT_risingEdge){
            SetBit(EICRB_Reg,EXIT_ISC71);
            SetBit(EICRB_Reg,EXIT_ISC70);
        }
    }
    else if(InterruptName==EXIT_INTERRUPT7_6){
        if(SensConfig==EXIT_lowLevel){
            ClearBit(EICRB_Reg,EXIT_ISC61);
            ClearBit(EICRB_Reg,EXIT_ISC60);
        }
        else if(SensConfig==EXIT_ISC_anyLogic){
            ClearBit(EICRB_Reg,EXIT_ISC61);
            SetBit(EICRB_Reg,EXIT_ISC60);
        }
        else if(SensConfig==EXIT_fallingEdge){
            SetBit(EICRB_Reg,EXIT_ISC61);
            ClearBit(EICRB_Reg,EXIT_ISC60);
        }
        if(SensConfig==EXIT_risingEdge){
            SetBit(EICRB_Reg,EXIT_ISC61);
            SetBit(EICRB_Reg,EXIT_ISC60);
        }
    }
    else if(InterruptName==EXIT_INTERRUPT7_5){
        if(SensConfig==EXIT_lowLevel){
            ClearBit(EICRB_Reg,EXIT_ISC51);
            ClearBit(EICRB_Reg,EXIT_ISC50);
        }
        else if(SensConfig==EXIT_ISC_anyLogic){
            ClearBit(EICRB_Reg,EXIT_ISC51);
            SetBit(EICRB_Reg,EXIT_ISC50);
        }
        else if(SensConfig==EXIT_fallingEdge){
            SetBit(EICRB_Reg,EXIT_ISC51);
            ClearBit(EICRB_Reg,EXIT_ISC50);
        }
        if(SensConfig==EXIT_risingEdge){
            SetBit(EICRB_Reg,EXIT_ISC51);
            SetBit(EICRB_Reg,EXIT_ISC50);
        }
    }
    else if(InterruptName==EXIT_INTERRUPT7_4){
        if(SensConfig==EXIT_lowLevel){
            ClearBit(EICRB_Reg,EXIT_ISC41);
            ClearBit(EICRB_Reg,EXIT_ISC40);
        }
        else if(SensConfig==EXIT_ISC_anyLogic){
            ClearBit(EICRB_Reg,EXIT_ISC41);
            SetBit(EICRB_Reg,EXIT_ISC40);
        }
        else if(SensConfig==EXIT_fallingEdge){
            SetBit(EICRB_Reg,EXIT_ISC41);
            ClearBit(EICRB_Reg,EXIT_ISC40);
        }
        if(SensConfig==EXIT_risingEdge){
            SetBit(EICRB_Reg,EXIT_ISC41);
            SetBit(EICRB_Reg,EXIT_ISC40);
        }
    }
}
void EXTI_Enable(uint8_t InterruptName){
    if(InterruptName==EXIT_INTERRUPT_Request0){
        SetBit(EIMSK_Reg,EXIT_INT0);
    }
    else if(InterruptName==EXIT_INTERRUPT_Request1){
        SetBit(EIMSK_Reg,EXIT_INT1);
    }
    else if(InterruptName==EXIT_INTERRUPT_Request2){
        SetBit(EIMSK_Reg,EXIT_INT2);
    }
    else if(InterruptName==EXIT_INTERRUPT_Request3){
        SetBit(EIMSK_Reg,EXIT_INT3);
    }
    else if(InterruptName==EXIT_INTERRUPT_Request4){
        SetBit(EIMSK_Reg,EXIT_INT4);
    }
    else if(InterruptName==EXIT_INTERRUPT_Request5){
        SetBit(EIMSK_Reg,EXIT_INT5);
    }
    else if(InterruptName==EXIT_INTERRUPT_Request6){
        SetBit(EIMSK_Reg,EXIT_INT6);
    }
    else if(InterruptName==EXIT_INTERRUPT_Request7){
        SetBit(EIMSK_Reg,EXIT_INT7);
    }
}
void EXTI_Disable(uint8_t InterruptName){
    if(InterruptName==EXIT_INTERRUPT_Request0){
        ClearBit(EIMSK_Reg,EXIT_INT0);
    }
    else if(InterruptName==EXIT_INTERRUPT_Request1){
        ClearBit(EIMSK_Reg,EXIT_INT1);
    }
    else if(InterruptName==EXIT_INTERRUPT_Request2){
        ClearBit(EIMSK_Reg,EXIT_INT2);
    }
    else if(InterruptName==EXIT_INTERRUPT_Request3){
        ClearBit(EIMSK_Reg,EXIT_INT3);
    }
    else if(InterruptName==EXIT_INTERRUPT_Request4){
        ClearBit(EIMSK_Reg,EXIT_INT4);
    }
    else if(InterruptName==EXIT_INTERRUPT_Request5){
        ClearBit(EIMSK_Reg,EXIT_INT5);
    }
    else if(InterruptName==EXIT_INTERRUPT_Request6){
        ClearBit(EIMSK_Reg,EXIT_INT6);
    }
    else if(InterruptName==EXIT_INTERRUPT_Request7){
        ClearBit(EIMSK_Reg,EXIT_INT7);
    }
}

