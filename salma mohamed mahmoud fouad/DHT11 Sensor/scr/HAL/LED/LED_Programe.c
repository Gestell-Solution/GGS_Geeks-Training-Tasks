/**
 * @file LED_Programe.c
 * @author salma mohamed mahmoud fouad(salmafouadothman@gmail.com)
 * @brief used to initialization the led using dio driver
 * @version 0.1
 * @date 2026-09-12
 * @copyright Copyright (c) 2026
 */
#include"LED_Interface.h"
/**
 * @var StaticConnectionType
 * @brief to save the led connection type either source or sink connection 
 */
static uint8_t StaticConnectionType = 0 ; 
/**
 * @brief 
 * @fn    Led_Init
 * @param GroupName choose group from group A,B,C,D
 * @param PinNumber choose pin from 0,1,2,3,4,5,6,7
 * @param ConnectionType either source or sink connection
 * @note  should be intialized for the led to work 
 */
void Led_Init(uint8_t GroupName , uint8_t PinNumber,uint8_t ConnectionType)
{
    DIO_InitPin(GroupName,PinNumber,Output);
    StaticConnectionType=ConnectionType;
}
/**
 * @brief it turn the led on 
 * @fn Led_on
 * @param GroupName choose group from group A,B,C,D
 * @param PinNumber choose pin from 0,1,2,3,4,5,6,7
 */
void Led_on(uint8_t GroupName , uint8_t PinNumber )
{
    if(StaticConnectionType==SourceConnection)
        {
            DIO_WritePin(GroupName,PinNumber,High);
        }
        else if (StaticConnectionType==SinkConnection)
        {
            DIO_WritePin(GroupName,PinNumber,Low);
 
        }

}
/**
 * @brief it turn the led off 
 * @fn Led_off
 * @param GroupName choose group from group A,B,C,D
 * @param PinNumber choose pin from 0,1,2,3,4,5,6,7
 */
void Led_off(uint8_t GroupName , uint8_t PinNumber)
{

    if(StaticConnectionType==SourceConnection)
        {
            DIO_WritePin(GroupName,PinNumber,Low);
        }
        else if (StaticConnectionType==SinkConnection)
        {
            DIO_WritePin(GroupName,PinNumber,High);
        }

}
/**
 * @brief it toggle the led 
 * @fn Led_Toggle
 * @param GroupName choose group from group A,B,C,D
 * @param PinNumber choose pin from 0,1,2,3,4,5,6,7
 */
void Led_Toggle(uint8_t GroupName , uint8_t PinNumber)
{

    DIO_TogglePin(GroupName,PinNumber);

}
