#include"DIO_Interface.h"

void DIO_InitPin(uint8_t GroupName,uint8_t PinNumber,uint8_t DirState){ 
    if(DirState==Output){
        switch (GroupName)
        {
        case Dio_GroupA:
            SetBit(DDRA_Reg,PinNumber);
            break;
        case Dio_GroupB:
            SetBit(DDRB_Reg,PinNumber);
            break;
        case Dio_GroupC:
            SetBit(DDRC_Reg,PinNumber);
            break;
        case Dio_GroupD:
            SetBit(DDRD_Reg,PinNumber);
            break;
        case Dio_GroupE:
            SetBit(DDRE_Reg,PinNumber);
            break;
        case Dio_GroupF:
            SetBit(DDRF_Reg,PinNumber);
            break;
        case Dio_GroupG:
            SetBit(DDRG_Reg,PinNumber);
            break;            
        }
    }
    else if(DirState==Input){
        switch (GroupName)
        {
        case Dio_GroupA:
            ClearBit(DDRA_Reg,PinNumber);
            break;
        case Dio_GroupB:
            ClearBit(DDRB_Reg,PinNumber);
            break;
        case Dio_GroupC:
            ClearBit(DDRC_Reg,PinNumber);
            break;
        case Dio_GroupD:
            ClearBit(DDRD_Reg,PinNumber);
            break;
        case Dio_GroupE:
            ClearBit(DDRE_Reg,PinNumber);
            break;
        case Dio_GroupF:
            ClearBit(DDRF_Reg,PinNumber);
            break;
        case Dio_GroupG:
            ClearBit(DDRG_Reg,PinNumber);
            break;            
        }    
   }
}

void DIO_InitGroup(uint8_t GroupName,uint8_t DirState){
  switch (GroupName)
      {
      case Dio_GroupA:
          DDRA_Reg=DirState;
          break;
      case Dio_GroupB:
          DDRB_Reg=DirState;
          break;
      case Dio_GroupC:
          DDRC_Reg=DirState;
          break;
      case Dio_GroupD:
          DDRD_Reg=DirState;
          break;
      case Dio_GroupE:
          DDRE_Reg=DirState;
          break;
      case Dio_GroupF:
          DDRF_Reg=DirState;
          break;
      case Dio_GroupG:
          DDRG_Reg=DirState;
          break;            
      }
}

void DIO_WritePin(uint8_t GroupName,uint8_t PinNumber,uint8_t OutputValue){
    if(OutputValue==High){
        switch (GroupName)
        {
        case Dio_GroupA:
            SetBit(PORTA_Reg,PinNumber);
            break;
        case Dio_GroupB:
            SetBit(PORTB_Reg,PinNumber);
            break;
        case Dio_GroupC:
            SetBit(PORTC_Reg,PinNumber);
            break;
        case Dio_GroupD:
            SetBit(PORTD_Reg,PinNumber);
            break;
        case Dio_GroupE:
            SetBit(PORTE_Reg,PinNumber);
            break;
        case Dio_GroupF:
            SetBit(PORTF_Reg,PinNumber);
            break;
        case Dio_GroupG:
            SetBit(PORTG_Reg,PinNumber);
            break;            
        }
    }
    else if(OutputValue==Low){
        switch (GroupName)
        {
        case Dio_GroupA:
            ClearBit(PORTA_Reg,PinNumber);
            break;
        case Dio_GroupB:
            ClearBit(PORTB_Reg,PinNumber);
            break;
        case Dio_GroupC:
            ClearBit(PORTC_Reg,PinNumber);
            break;
        case Dio_GroupD:
            ClearBit(PORTD_Reg,PinNumber);
            break;
        case Dio_GroupE:
            ClearBit(PORTE_Reg,PinNumber);
            break;
        case Dio_GroupF:
            ClearBit(PORTF_Reg,PinNumber);
            break;
        case Dio_GroupG:
            ClearBit(PORTG_Reg,PinNumber);
            break;            
        }    
   }
}

void DIO_WriteGroup(uint8_t GroupName,uint8_t OutputValue){
switch (GroupName)
        {
        case Dio_GroupA:
            PORTA_Reg=OutputValue;
            break;
        case Dio_GroupB:
            PORTB_Reg=OutputValue;
            break;
        case Dio_GroupC:
            PORTC_Reg=OutputValue;
            break;
        case Dio_GroupD:
            PORTD_Reg=OutputValue;
            break;
        case Dio_GroupE:
            PORTE_Reg=OutputValue;
            break;
        case Dio_GroupF:
            PORTF_Reg=OutputValue;
            break;
        case Dio_GroupG:
            PORTG_Reg=OutputValue;
            break;            
        }
}

void DIO_ReadPin(uint8_t GroupName,uint8_t PinNumber,uint8_t *PinState){
 if(PinState!=Null){
     if((GroupName<=Dio_GroupG)&&(PinNumber<=Dio_Pin7)){
      switch (GroupName)
         {
         case Dio_GroupA:
             *PinState=ReadBit(PINA_Reg,PinNumber);
             break;
         case Dio_GroupB:
             *PinState=ReadBit(PINB_Reg,PinNumber);
             break;
         case Dio_GroupC:
             *PinState=ReadBit(PINC_Reg,PinNumber);
             break;
         case Dio_GroupD:
             *PinState=ReadBit(PIND_Reg,PinNumber);
             break;
         case Dio_GroupE:
             *PinState=ReadBit(PINE_Reg,PinNumber);
             break;
         case Dio_GroupF:
             *PinState=ReadBit(PINF_Reg,PinNumber);
             break;
         case Dio_GroupG:
             *PinState=ReadBit(PING_Reg,PinNumber);
             break;            
         }
     }
  }
}

void DIO_ReadGroup(uint8_t GroupName,uint8_t * InputStates){
 if(InputStates!=Null){
    if(GroupName<=Dio_GroupG){
        switch (GroupName)
        {
        case Dio_GroupA:
            *InputStates=PINA_Reg;
            break;
        case Dio_GroupB:
            *InputStates=PINB_Reg;
            break;
        case Dio_GroupC:
            *InputStates=PINC_Reg;
            break;
        case Dio_GroupD:
            *InputStates=PIND_Reg;
            break;
        case Dio_GroupE:
            *InputStates=PINE_Reg;
            break;
        case Dio_GroupF:
            *InputStates=PINF_Reg;
            break;
        case Dio_GroupG:
            *InputStates=PING_Reg;
            break;            
        }
    }
 }
}

void DIO_TogglePin(uint8_t GroupName,uint8_t PinNumber){
    if (GroupName<=Dio_GroupG)
    {
        switch (GroupName)
        {
        case Dio_GroupA:
            ToggleBit(DDRA_Reg,PinNumber);
            break;
        case Dio_GroupB:
            ToggleBit(DDRB_Reg,PinNumber);
            break;
        case Dio_GroupC:
            ToggleBit(DDRC_Reg,PinNumber);
            break;
        case Dio_GroupD:
            ToggleBit(DDRD_Reg,PinNumber);
            break;
        case Dio_GroupE:
            ToggleBit(DDRE_Reg,PinNumber);
            break;
        case Dio_GroupF:
            ToggleBit(DDRF_Reg,PinNumber);
            break;
        case Dio_GroupG:
            ToggleBit(DDRG_Reg,PinNumber);
            break;            
        }
    }
    
}





