#include "DIO_Interface.h"

void DIO_InitPin(uint8_t GroupName, uint8_t PinNumber, uint8_t DirState)
{
    if ((GroupName <= Dio_GroupD) && (PinNumber <= Dio_Pin7))
    {
        if (DirState == Output)
        {
            switch (GroupName)
            {
                case Dio_GroupA: SET_BIT(DDRA_Reg, PinNumber); break;
                case Dio_GroupB: SET_BIT(DDRB_Reg, PinNumber); break;
                case Dio_GroupC: SET_BIT(DDRC_Reg, PinNumber); break;
                case Dio_GroupD: SET_BIT(DDRD_Reg, PinNumber); break;
                default: break;
            }
        }
        else if (DirState == Input)
        {
            switch (GroupName)
            {
                case Dio_GroupA: CLEAR_BIT(DDRA_Reg, PinNumber); break;
                case Dio_GroupB: CLEAR_BIT(DDRB_Reg, PinNumber); break;
                case Dio_GroupC: CLEAR_BIT(DDRC_Reg, PinNumber); break;
                case Dio_GroupD: CLEAR_BIT(DDRD_Reg, PinNumber); break;
                default: break;
            }
        }
        else
        {
            /* Invalid direction. */
        }
    }
}

void DIO_WritePin(uint8_t GroupName, uint8_t PinNumber, uint8_t OutputValue)
{
    if ((GroupName <= Dio_GroupD) && (PinNumber <= Dio_Pin7))
    {
        if (OutputValue == High)
        {
            switch (GroupName)
            {
                case Dio_GroupA: SET_BIT(PORTA_Reg, PinNumber); break;
                case Dio_GroupB: SET_BIT(PORTB_Reg, PinNumber); break;
                case Dio_GroupC: SET_BIT(PORTC_Reg, PinNumber); break;
                case Dio_GroupD: SET_BIT(PORTD_Reg, PinNumber); break;
                default: break;
            }
        }
        else if (OutputValue == Low)
        {
            switch (GroupName)
            {
                case Dio_GroupA: CLEAR_BIT(PORTA_Reg, PinNumber); break;
                case Dio_GroupB: CLEAR_BIT(PORTB_Reg, PinNumber); break;
                case Dio_GroupC: CLEAR_BIT(PORTC_Reg, PinNumber); break;
                case Dio_GroupD: CLEAR_BIT(PORTD_Reg, PinNumber); break;
                default: break;
            }
        }
        else
        {
            /* Invalid output value. */
        }
    }
}

void DIO_InitGroup(uint8_t GroupName, uint8_t DirState)
{
    switch (GroupName)
    {
        case Dio_GroupA: DDRA_Reg = DirState; break;
        case Dio_GroupB: DDRB_Reg = DirState; break;
        case Dio_GroupC: DDRC_Reg = DirState; break;
        case Dio_GroupD: DDRD_Reg = DirState; break;
        default: break;
    }
}

void DIO_WriteGroup(uint8_t GroupName, uint8_t OutputValue)
{
    switch (GroupName)
    {
        case Dio_GroupA: PORTA_Reg = OutputValue; break;
        case Dio_GroupB: PORTB_Reg = OutputValue; break;
        case Dio_GroupC: PORTC_Reg = OutputValue; break;
        case Dio_GroupD: PORTD_Reg = OutputValue; break;
        default: break;
    }
}

void DIO_ReadPin(uint8_t GroupName, uint8_t PinNumber, uint8_t *PinState)
{
    if (PinState != Null)
    {
        if ((GroupName <= Dio_GroupD) && (PinNumber <= Dio_Pin7))
        {
            switch (GroupName)
            {
                case Dio_GroupA: *PinState = READ_BIT(PINA_Reg, PinNumber); break;
                case Dio_GroupB: *PinState = READ_BIT(PINB_Reg, PinNumber); break;
                case Dio_GroupC: *PinState = READ_BIT(PINC_Reg, PinNumber); break;
                case Dio_GroupD: *PinState = READ_BIT(PIND_Reg, PinNumber); break;
                default: break;
            }
        }
    }
}

void DIO_ReadGroup(uint8_t GroupName, uint8_t *InputStates)
{
    if (InputStates != Null)
    {
        switch (GroupName)
        {
            case Dio_GroupA: *InputStates = PINA_Reg; break;
            case Dio_GroupB: *InputStates = PINB_Reg; break;
            case Dio_GroupC: *InputStates = PINC_Reg; break;
            case Dio_GroupD: *InputStates = PIND_Reg; break;
            default: break;
        }
    }
}

void DIO_Toggle(uint8_t GroupName, uint8_t PinNumber)
{
    if ((GroupName <= Dio_GroupD) && (PinNumber <= Dio_Pin7))
    {
        switch (GroupName)
        {
            case Dio_GroupA: TOGGLE_BIT(PORTA_Reg, PinNumber); break;
            case Dio_GroupB: TOGGLE_BIT(PORTB_Reg, PinNumber); break;
            case Dio_GroupC: TOGGLE_BIT(PORTC_Reg, PinNumber); break;
            case Dio_GroupD: TOGGLE_BIT(PORTD_Reg, PinNumber); break;
            default: break;
        }
    }
}
