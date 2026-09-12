#include "DIO_Interface.h"


// select direction  initpin 
void DIO_InitPin(uint8_t GroupName,uint8_t PinNumber,uint8_t DirState)
{
    if((GroupName>=Dio_GroupA && GroupName<=Dio_GroupD)&& 
      (PinNumber>=Dio_Pin0 && PinNumber<=Dio_Pin7))
        {
            if(DirState==Output)
            {
                switch(GroupName)
                {
                    case Dio_GroupA:SET_BIT(DDRA,PinNumber);break;
                    case Dio_GroupB:SET_BIT(DDRB,PinNumber);break;
                    case Dio_GroupC:SET_BIT(DDRC,PinNumber);break;
                    case Dio_GroupD:SET_BIT(DDRD,PinNumber);break;
                }
            }
            else if (DirState==Input)
            {
                switch(GroupName)
                {
                    case Dio_GroupA:CLEAR_BIT(DDRA,PinNumber);break;
                    case Dio_GroupB:CLEAR_BIT(DDRB,PinNumber);break;
                    case Dio_GroupC:CLEAR_BIT(DDRC,PinNumber);break;
                    case Dio_GroupD:CLEAR_BIT(DDRD,PinNumber);break;
                }
            }
        }
    
}

// select direction  initDio_Group 
void DIO_InitGroup(uint8_t GroupName,uint8_t DirState)
{
    // if(Dio_GroupName>=Dio_GroupA&&Dio_GroupName<=Dio_GroupD)
    // {
        switch(GroupName)
        {
            case Dio_GroupA: DDRA = DirState;break;
            case Dio_GroupB: DDRB = DirState;break;
            case Dio_GroupC: DDRC = DirState;break;
            case Dio_GroupD: DDRD = DirState;break;
            default : break;
        }
    // }
}

// outputvalue    writepin  
void DIO_WritePin(uint8_t GroupName,uint8_t PinNumber,uint8_t OutputValue)
{
    if(GroupName<=Dio_GroupD && PinNumber<=Dio_Pin7)
    {
        if(OutputValue==High)
        {
            switch(GroupName)
            {
               case Dio_GroupA:SET_BIT(PORTA,PinNumber);break;                    
               case Dio_GroupB:SET_BIT(PORTB,PinNumber);break;                    
               case Dio_GroupC:SET_BIT(PORTC,PinNumber);break;                    
               case Dio_GroupD:SET_BIT(PORTD,PinNumber);break;                        
            }
        }
        else if (OutputValue==Low)
        {
            switch(GroupName)
            {
               case Dio_GroupA:CLEAR_BIT(PORTA,PinNumber);break;                    
               case Dio_GroupB:CLEAR_BIT(PORTB,PinNumber);break;                    
               case Dio_GroupC:CLEAR_BIT(PORTC,PinNumber);break;                    
               case Dio_GroupD:CLEAR_BIT(PORTD,PinNumber);break;                        
            }
        }
    }
}

// outputvalue    writeDio_Group   
void DIO_WriteGroup(uint8_t GroupName,uint8_t OutputValue)
{
    switch(GroupName)
    {
        case Dio_GroupA:PORTA=OutputValue;break;                    
        case Dio_GroupB:PORTB=OutputValue;break;                    
        case Dio_GroupC:PORTC=OutputValue;break;                    
        case Dio_GroupD:PORTD=OutputValue;break;  
        default : break;
    }
}

// read  readpin 
// uint8_t DIO_ReadPin(uint8_t Dio_GroupName,uint8_t PinNumber);
void DIO_ReadPin(uint8_t GroupName,uint8_t PinNumber,uint8_t *PinState)
{
    if (PinState!=Null)
    {
        if (GroupName<=Dio_GroupD && PinNumber<=Dio_Pin7)
        {
            switch(GroupName)
            {
                case Dio_GroupA: *PinState = READ_BIT(PINA,PinNumber);break;
                case Dio_GroupB: *PinState = READ_BIT(PINB,PinNumber);break;
                case Dio_GroupC: *PinState = READ_BIT(PINC,PinNumber);break;
                case Dio_GroupD: *PinState = READ_BIT(PIND,PinNumber);break;
                
            }
        }
    }
}
// read  readDio_Group  
void DIO_ReadGroup(uint8_t GroupName,uint8_t * InputStates)
{
    if(InputStates!=Null)
    {
        switch(GroupName)
        {
                case Dio_GroupA: *InputStates = PINA;break;
                case Dio_GroupB: *InputStates = PINB;break;
                case Dio_GroupC: *InputStates = PINC;break;
                case Dio_GroupD: *InputStates = PIND;break;
                
        }
    }
}

void DIO_Toggle(uint8_t GroupName , uint8_t PinNumber){
switch(GroupName)
    {
        case Dio_GroupA:
            TOGGLE_BIT(PORTA, PinNumber);
            break;

        case Dio_GroupB:
            TOGGLE_BIT(PORTB, PinNumber);
            break;

        case Dio_GroupC:
            TOGGLE_BIT(PORTC, PinNumber);
            break;

        case Dio_GroupD:
            TOGGLE_BIT(PORTD, PinNumber);
            break;
    }

}