/**
 * @file      DIO_Program.c
 * @author    Abdulrahman Ali 
 * @author    ENG/Hesham Ahmed (Reviewer)
 * @brief     Program of the DIO Driver.
 * @details   This file contains the function OF DIO driver 
 * @version   1.0.0
 * @date      26 August 2026
 * @copyright Copyright (c) 2026, Gestell Company
 */





#include "DIO_Interface.h"


// select direction  initpin 
void DIO_InitPin(uint8_t GroupName,uint8_t PinNumber,uint8_t DirState)
{
    if((GroupName>=Dio_GroupA && GroupName<=Dio_GroupG)&& 
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
                    case Dio_GroupE:SET_BIT(DDRE,PinNumber);break;
                    case Dio_GroupF:SET_BIT(DDRF,PinNumber);break;
                    case Dio_GroupG:if(PinNumber<=4) SET_BIT(DDRG,PinNumber);break;
                   
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
                    case Dio_GroupE:CLEAR_BIT(DDRE,PinNumber);break;
                    case Dio_GroupF:CLEAR_BIT(DDRF,PinNumber);break;
                    case Dio_GroupG:if(PinNumber<=4) CLEAR_BIT(DDRG,PinNumber);break;
                }
            }
        }
    
}

// select direction  initDio_Group 
void DIO_InitGroup(uint8_t GroupName,uint8_t DirState)
{
    // if(Dio_GroupName>=Dio_GroupA&&Dio_GroupName<=Dio_GroupG)
    // {
        switch(GroupName)
        {
            case Dio_GroupA: DDRA = DirState;break;
            case Dio_GroupB: DDRB = DirState;break;
            case Dio_GroupC: DDRC = DirState;break;
            case Dio_GroupD: DDRD = DirState;break;
            case Dio_GroupE: DDRE = DirState;break;
            case Dio_GroupF: DDRF = DirState;break;
            case Dio_GroupG: DDRG = DirState&0X1F ;break; //To protect PINS 5,6,7
            default : break;
        }
    // }
}

// outputvalue    writepin  
void DIO_WritePin(uint8_t GroupName,uint8_t PinNumber,uint8_t OutputValue)
{
    if(GroupName<=Dio_GroupG && PinNumber<=Dio_Pin7)
    {
        if(OutputValue==High)
        {
            switch(GroupName)
            {
               case Dio_GroupA:SET_BIT(PORTA,PinNumber);break;                    
               case Dio_GroupB:SET_BIT(PORTB,PinNumber);break;                    
               case Dio_GroupC:SET_BIT(PORTC,PinNumber);break;                    
               case Dio_GroupD:SET_BIT(PORTD,PinNumber);break;
               case Dio_GroupE:SET_BIT(PORTE,PinNumber);break;
               case Dio_GroupF:SET_BIT(PORTF,PinNumber);break;
               case Dio_GroupG:if(PinNumber<=4) SET_BIT(PORTG,PinNumber);break;                        
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
               case Dio_GroupE:CLEAR_BIT(PORTE,PinNumber);break;
               case Dio_GroupF:CLEAR_BIT(PORTF,PinNumber);break;
               case Dio_GroupG:if(PinNumber<=4) CLEAR_BIT(PORTG,PinNumber);break;                        
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
        case Dio_GroupE:PORTE=OutputValue;break;
        case Dio_GroupF:PORTF=OutputValue;break;
        case Dio_GroupG:PORTG=OutputValue&0X1F ;break;  //To protect PINS 5,6,7
        default : break;
    }
}

// read  readpin 
// uint8_t DIO_ReadPin(uint8_t Dio_GroupName,uint8_t PinNumber);
void DIO_ReadPin(uint8_t GroupName,uint8_t PinNumber,uint8_t *PinState)
{
    if (PinState!=Null)
    {
        if (GroupName<=Dio_GroupG && PinNumber<=Dio_Pin7)
        {
            switch(GroupName)
            {
                case Dio_GroupA: *PinState = READ_BIT(PINA,PinNumber);break;
                case Dio_GroupB: *PinState = READ_BIT(PINB,PinNumber);break;
                case Dio_GroupC: *PinState = READ_BIT(PINC,PinNumber);break;
                case Dio_GroupD: *PinState = READ_BIT(PIND,PinNumber);break;
                case Dio_GroupE: *PinState = READ_BIT(PINE,PinNumber);break;
                case Dio_GroupF: *PinState = READ_BIT(PINF,PinNumber);break;
                case Dio_GroupG: if(PinNumber<=4) *PinState = READ_BIT(PING,PinNumber);break;
                
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
                case Dio_GroupE: *InputStates = PINE;break;
                case Dio_GroupF: *InputStates = PINF;break;
                case Dio_GroupG: *InputStates = PING&0X1F ;break; //To protect PINS 5,6,7
                
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

        case Dio_GroupE:
            TOGGLE_BIT(PORTE, PinNumber);
            break;

        case Dio_GroupF:
            TOGGLE_BIT(PORTF, PinNumber);
            break;
            
        case Dio_GroupG:
            TOGGLE_BIT(PORTG, PinNumber);
            break;
    }

}