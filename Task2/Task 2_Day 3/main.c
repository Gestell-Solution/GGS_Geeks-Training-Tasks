#include "util/delay.h"
#include "MCAL/DIO/DIO_Interface.h"
void main()
{
DIO_InitPin(Dio_GroupA,Dio_Pin0,Output);

while (1)
{
DIO_WritePin(Dio_GroupA,Dio_Pin0,High);
_delay_ms(1000);
DIO_WritePin(Dio_GroupA,Dio_Pin0,Low);
}

}