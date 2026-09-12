#include <util/delay.h>
#include"HAL/SENSOR/SENSOR_Interface.h"
#include"MCAL/DIO/DIO_Interface.h"
void main(){
  uint8_t sensor_reading=0;
  SENSOR_Init(Dio_GroupA,Dio_Pin0);
  DIO_InitPin(Dio_GroupB,Dio_Pin0,Output);
  while(1){
  SENSOR_GetReading(Dio_GroupA,Dio_Pin0,&sensor_reading);
  if (sensor_reading==High){
    DIO_WritePin(Dio_GroupB,Dio_Pin0,High);
  }
  else if(sensor_reading==Low){
    DIO_WritePin(Dio_GroupB,Dio_Pin0,Low);
  }
  }
}

//4- Configure a DIO pin to interface with a simple IR sensor.
