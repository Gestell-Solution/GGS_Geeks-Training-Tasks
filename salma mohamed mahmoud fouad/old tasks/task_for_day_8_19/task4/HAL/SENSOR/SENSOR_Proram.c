#include"SENSOR_Interface.h"
void SENSOR_Init(uint8_t group ,uint8_t pin){
    DIO_InitPin(group,pin,Input);
}
void SENSOR_GetReading(uint8_t group ,uint8_t pin,uint8_t *sensorState){
    DIO_ReadPin(group,pin,&sensorState);
}