#include "DIO_interface.h"

void DIO_set_pin_direction(u8 group_name , u8 pin_number , u8 direction) // use to set direction of a single pin
{
    if (group_name <= Dio_groupD && pin_number <= Dio_pin7 && direction < 2) // check if its sent correctly
    {
        if (direction == output)    // output is 1 
        {
            switch(group_name)  // cant do helper fucntion
            {
                case Dio_groupA :
                    SetBit(DDRA , pin_number);
                    break;
                case Dio_groupB :
                    SetBit(DDRB , pin_number);
                    break;
                case Dio_groupC :
                    SetBit(DDRC , pin_number);
                    break;
                case Dio_groupD :
                    SetBit(DDRD , pin_number);
                    break;
                default : 
                    break;
            }
        }
        else if (direction == input)  // input is low
        {
            switch(group_name) 
            {
                case Dio_groupA :
                    ClearBit(DDRA , pin_number);
                    break;
                case Dio_groupB :
                    ClearBit(DDRB , pin_number);
                    break;
                case Dio_groupC :
                    ClearBit(DDRC , pin_number);
                    break;
                case Dio_groupD :
                    ClearBit(DDRD , pin_number);
                    break;
                default :
                    break;
            }
        }
    }
}

void DIO_set_pin_value(u8 group_name , u8 pin_number , u8 value) // to set the value on the port 1 or 0 
{
    if (group_name <= Dio_groupD && pin_number <= Dio_pin7 && value < 2) // check if its sent correctly
    {
        if (value == high)    // high is 1 
        {
            switch(group_name)  // cant do helper fucntion
            {
                case Dio_groupA :
                    SetBit(PORTA , pin_number);
                    break;
                case Dio_groupB :
                    SetBit(PORTB , pin_number);
                    break;
                case Dio_groupC :
                    SetBit(PORTC , pin_number);
                    break;
                case Dio_groupD :
                    SetBit(PORTD , pin_number);
                    break;
                default : 
                    break;
            }
        }
        else if (value == low)  // input is low
        {
            switch(group_name) 
            {
                case Dio_groupA :
                    ClearBit(PORTA , pin_number);
                    break;
                case Dio_groupB :
                    ClearBit(PORTB , pin_number);
                    break;
                case Dio_groupC :
                    ClearBit(PORTC , pin_number);
                    break;
                case Dio_groupD :
                    ClearBit(PORTD , pin_number);
                    break;
                default :
                    break;
            }
        }
    }
}

u8 DIO_get_pin_value(u8 group_name , u8 pin_number) // to read the value directily 
{
    if (group_name <= Dio_groupD && pin_number <= Dio_pin7)
    {
        switch(group_name)
        {
            case Dio_groupA :
                return ReadBit(PINA , pin_number);
                break;
            case Dio_groupB :
                return ReadBit(PINB , pin_number);
                break;
            case Dio_groupC :
                return ReadBit(PINC , pin_number);
                break;
            case Dio_groupD :
                return ReadBit(PIND , pin_number);
                break;
            default :
                return 0 ;
                break; 
        }
    }
    else 
    {
        return 0 ;
    }
}

void DIO_tog_pin(u8 group_name , u8 pin_number)
{
    if (group_name <= Dio_groupD && pin_number <= Dio_pin7)
    {
        switch(group_name)
        {
            case Dio_groupA :
                ToggleBit(PORTA , pin_number);
                break;
            case Dio_groupB :
                ToggleBit(PORTB , pin_number);
                break;
            case Dio_groupC :
                ToggleBit(PORTC , pin_number);
                break;
            case Dio_groupD :
                ToggleBit(PORTD , pin_number);
                break;
            default : 
                break;
        }
    }
}


void DIO_set_group_direction(u8 group_name , u8 direction)// to set the whole group_name at once by setting direction so 0xFF or 0xF0 anything
{
    if (group_name <= Dio_groupD)
    {
        switch(group_name) // to check on each group_name 
        {
            case Dio_groupA :
                DDRA = direction;
                break;
            case Dio_groupB :
                DDRB = direction;
                break;
            case Dio_groupC :
                DDRC = direction;
                break;
            case Dio_groupD :
                DDRD = direction;
                break;
            default :
                break;
        }
    }
}

void DIO_set_group_value(u8 group_name , u8 value) // to set a whole group to be on or off and inbetween
{
    if (group_name <= Dio_groupD)
    {
        switch(group_name) // to check on each group_name 
        {
            case Dio_groupA :
                PORTA = value;
                break;
            case Dio_groupB :
                PORTB = value;
                break;
            case Dio_groupC :
                PORTC = value;
                break;
            case Dio_groupD :
                PORTD = value;
                break;
            default :
                break;
        }
    }
}

u8 DIO_get_group_value(u8 group_name) // to read a whole group at once
{
    if (group_name <= Dio_groupD)
    {
        switch(group_name)
        {
            case Dio_groupA :
                return PINA;
                break;
            case Dio_groupB :
                return PINB;
                break;
            case Dio_groupC :
                return PINC;
                break;
            case Dio_groupD :
                return PIND;
                break;
            default :
                return 0 ;
                break; 
        }
    }
    else 
    {
        return 0 ;
    }
}
