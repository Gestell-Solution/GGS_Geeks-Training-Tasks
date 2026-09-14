#include "MCAL/DIO/DIO_Interface.h"


/*As IR sensor isn't supported directly by our simulators,it's modeled here by push-button circuit 
with a pull-down resistor*/

void main()
{
    uint8_t sensor_state=0;
DIO_InitPin(Dio_GroupD,Dio_Pin1,Input);
DIO_InitPin(Dio_GroupB,Dio_Pin2,Output);

DIO_WritePin(Dio_GroupD,Dio_Pin1,High);

while(1)
{
DIO_ReadPin(Dio_GroupD,Dio_Pin1,&sensor_state);

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