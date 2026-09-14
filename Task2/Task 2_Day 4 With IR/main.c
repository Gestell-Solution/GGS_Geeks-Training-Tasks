#include "MCAL/DIO/DIO_Interface.h"

void main()
{
    uint8_t sensor_state=0;
DIO_InitPin(Dio_GroupA,Dio_Pin0,Input);
DIO_InitPin(Dio_GroupB,Dio_Pin2,Output);

DIO_WritePin(Dio_GroupA,Dio_Pin0,High);

while(1)
{
DIO_ReadPin(Dio_GroupA,Dio_Pin0,&sensor_state);

if(sensor_state==High)
{
DIO_WritePin(Dio_GroupB,Dio_Pin2,High);
}

else if(sensor_state==Low)
{
DIO_WritePin(Dio_GroupB,Dio_Pin2,Low);
}

}
}