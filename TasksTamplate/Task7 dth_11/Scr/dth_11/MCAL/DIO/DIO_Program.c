#include"DIO_Interface.h"


//Slect Directioon init Pin
void DIO_InitPin(uint8_t GroupName, uint8_t PinNummber, uint8_t DirState)
{

   if (GroupName<=DIO_GroupD && PinNummber<=DIO_Pin7)
   {
     if(DirState==Output)
     {
       switch (GroupName)
       {
       case DIO_GroupA: SetBit(DDRA_Reg,PinNummber); break;
       case DIO_GroupB: SetBit(DDRB_Reg,PinNummber); break;
       case DIO_GroupC: SetBit(DDRC_Reg,PinNummber); break;
       case DIO_GroupD: SetBit(DDRD_Reg,PinNummber); break;
       }
     }

     else if (DirState== Input)
     {
       switch (GroupName)
       {
       case DIO_GroupA: ClearBit(DDRA_Reg,PinNummber); break;
       case DIO_GroupB: ClearBit(DDRB_Reg,PinNummber); break;
       case DIO_GroupC: ClearBit(DDRC_Reg,PinNummber); break;
       case DIO_GroupD: ClearBit(DDRD_Reg,PinNummber); break;
       }
     }
   }

}

//Slect Directioon init Group
void DIO_InitGroup(uint8_t GroupName ,uint8_t DirState )
{
    switch (GroupName)
    {
    case DIO_GroupA : DDRA_Reg = DirState;  break;
    case DIO_GroupB : DDRB_Reg = DirState;  break;
    case DIO_GroupC : DDRC_Reg = DirState;  break;
    case DIO_GroupD : DDRD_Reg = DirState;  break;
    default: break;
    }
        
}

//outputvalue writepin
void DIO_WritePin(uint8_t GroupName, uint8_t PinNummber ,uint8_t OutputValue)
{
    if(GroupName<=DIO_GroupD && PinNummber<=DIO_Pin7)
    {
        if (OutputValue==High)
        {
        switch (GroupName)
       {
       case DIO_GroupA: SetBit(PORTA_Reg,PinNummber); break;
       case DIO_GroupB: SetBit(PORTB_Reg,PinNummber); break;
       case DIO_GroupC: SetBit(PORTC_Reg,PinNummber); break;
       case DIO_GroupD: SetBit(PORTD_Reg,PinNummber); break;
       }
        }

         if (OutputValue==Low)
        {
        switch (GroupName)
       {
       case DIO_GroupA: ClearBit(PORTA_Reg,PinNummber); break;
       case DIO_GroupB: ClearBit(PORTB_Reg,PinNummber); break;
       case DIO_GroupC: ClearBit(PORTC_Reg,PinNummber); break;
       case DIO_GroupD: ClearBit(PORTD_Reg,PinNummber); break;
       }
        }
    }
}

//outputvalue writeGroup
void DIO_WriteGroup(uint8_t GroupName ,uint8_t OutputValue)
{
   switch (GroupName)
    {
    case DIO_GroupA : PORTA_Reg = OutputValue;  break;
    case DIO_GroupB : PORTB_Reg = OutputValue;  break;
    case DIO_GroupC : PORTC_Reg = OutputValue;  break;
    case DIO_GroupD : PORTD_Reg = OutputValue;  break;
    default: break;
    }
}







//InputValue ReadPin
void DIO_ReadPin(uint8_t GroupName, uint8_t PinNummber ,uint8_t *PinState)
{
    if(PinState!=Null)
    {
        if(GroupName<=DIO_GroupD && PinNummber<=DIO_Pin7)
        {
            switch (GroupName)
            {
            case DIO_GroupA:  *PinState =ReadBit(PINA_Reg,PinNummber);  break;
            case DIO_GroupB:  *PinState =ReadBit(PINB_Reg,PinNummber);  break;
            case DIO_GroupC:  *PinState =ReadBit(PINC_Reg,PinNummber);  break;
            case DIO_GroupD:  *PinState =ReadBit(PIND_Reg,PinNummber);  break;
            default: break;
            }
        }

    }
}







//InputValue ReadGroup
void DIO_ReadGroup(uint8_t GroupName,uint8_t *InputStates)
{
    if(InputStates!=Null)
    {
        switch (GroupName)
            {
            case DIO_GroupA:  *InputStates =PINA_Reg;  break;
            case DIO_GroupB:  *InputStates =PINB_Reg;  break;
            case DIO_GroupC:  *InputStates =PINC_Reg;  break;
            case DIO_GroupD:  *InputStates =PIND_Reg;  break;
            default: break;
            }
    }
}







//Toggle Pin
void DIO_TogglePin(uint8_t GroupName, uint8_t PinNummber)
{
     if(GroupName<=DIO_GroupD && PinNummber<=DIO_Pin7)
    {
        switch (GroupName)
       {
       case DIO_GroupA: ToggleBit(PORTA_Reg,PinNummber); break;
       case DIO_GroupB: ToggleBit(PORTB_Reg,PinNummber); break;
       case DIO_GroupC: ToggleBit(PORTC_Reg,PinNummber); break;
       case DIO_GroupD: ToggleBit(PORTD_Reg,PinNummber); break;
       }
    }
}