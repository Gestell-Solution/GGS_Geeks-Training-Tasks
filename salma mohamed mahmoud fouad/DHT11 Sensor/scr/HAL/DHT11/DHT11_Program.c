/**
 * @file DHT11_Program.c
 * @author salma mohamed mahmoud fouad(salmafouadothman@gmail.com)
 * @brief  this driver is used to initialize the DHT11 sensor and receive data from it
 * @details this driver should intilize the dht11 sensor and get the data find it and send it
 * @version 0.1
 * @date 2026-09-14
 * @copyright Copyright (c) 2026
 */

#include"DHT11_Interface.h"

void DHT11_Init(){
 DIO_InitPin(DHT11_Group,DHT11_Pin,Output);
 DIO_WritePin(DHT11_Group,DHT11_Pin,Low);
 _delay_ms(18);
 DIO_WritePin(DHT11_Group,DHT11_Pin,High);
}

void DHT11_Response(){
    uint8_t pinstate=0;
 DIO_InitPin(DHT11_Group,DHT11_Pin,Input);

 do{
    DIO_ReadPin(DHT11_Group,DHT11_Pin,&pinstate);
 }while(pinstate);
 do{
    DIO_ReadPin(DHT11_Group,DHT11_Pin,&pinstate);
 }while(!pinstate);
 do{
    DIO_ReadPin(DHT11_Group,DHT11_Pin,&pinstate);
 }while(pinstate);
}

uint8_t DHT11_Get_data(){
    uint8_t data=0,
    pinstate=0,
    bit_number=0x01;
    DHT11_Response();
     for(uint8_t loop=0;loop<8;loop++){
        do{
            DIO_ReadPin(DHT11_Group,DHT11_Pin,&pinstate);
        }while(!pinstate);
        _delay_us(50);
       DIO_ReadPin(DHT11_Group,DHT11_Pin,&pinstate);
        if(pinstate){
            data=(data<<1)|bit_number;
        }
        else{
            data=(data<<1);
        }
        do{
            DIO_ReadPin(DHT11_Group,DHT11_Pin,&pinstate);
        }while(pinstate);
     }
    return data;
}

