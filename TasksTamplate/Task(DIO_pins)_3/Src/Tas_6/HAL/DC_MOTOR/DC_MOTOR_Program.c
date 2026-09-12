
#include <util/delay.h>

#include "DC_MOTOR_Interface.h"
#include "DC_MOTOR_Config.h"
#include "../../LIB/Definition.h"
#include "../../MCAL/DIO/DIO_Interface.h"

void DCM_Init(void)
{
    DIO_InitPin(DCM_PORT, DCM_IN1, Output);
    DIO_InitPin(DCM_PORT, DCM_IN2, Output);
    DCM_Stop();
}

void DCM_OpenGate(void)
{
    DIO_WritePin(DCM_PORT, DCM_IN1, High);
    DIO_WritePin(DCM_PORT, DCM_IN2, Low);
    _delay_ms(300);

    DCM_Stop();
}

void DCM_CloseGate(void)
{
    DIO_WritePin(DCM_PORT, DCM_IN1, Low);
    DIO_WritePin(DCM_PORT, DCM_IN2, High);
    _delay_ms(300);

    DCM_Stop();
}

void DCM_Stop(void)
{
    DIO_WritePin(DCM_PORT, DCM_IN1, Low);
     DIO_WritePin(DCM_PORT, DCM_IN2, Low);
}