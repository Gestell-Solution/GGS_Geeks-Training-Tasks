/**
 * @file dht11_Program.c
 * @brief This file contains the implementation of the DHT11 module Functions.
 * @author Developer: Abdulrahman Ali 
 * @author Reviewer : Eng/Hesham Ahmed
 * @date 9/18/2026
 * @copyright Copyright (c) 2026 , Gestell Company. All rights reserved.
 * @version 1.0.0
*/
#include <stdint.h>
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../LIB/Definition.h"
#include "dht11_Interface.h"
#include "dht11_Config.h"
#include "dht11_Private.h"
#include<util/delay.h>

/**
 * @brief Initialize DHT11 sensor.
 *
 * @return void.
 */
void DHT11_Init(void)
{
    DIO_InitPin(DHT11_DATA_PORT, DHT11_DATA_PIN,Output);         
    DIO_WritePin(DHT11_DATA_PORT,  DHT11_DATA_PIN, High);      
}

/**
 * @brief Read temperature and humidity from DHT11.
 *
 * @param Temperature Pointer to temperature value.
 * @param Humidity Pointer to humidity value.
 *
 * @return DHT11 status.
 */

uint8_t DHT11_ReadData(uint8_t *Temperature, uint8_t *Humidity)
{
uint8_t Data[5] = {0U};
uint8_t PinState = High;
uint8_t Index = 0U;
uint8_t BitIndex = 0U;
uint16_t Timeout = 0U;

if ((Temperature == Null) || (Humidity == Null))
{
return DHT11_ERROR;
}
// Start The Signal 
DIO_InitPin(DHT11_DATA_PORT, DHT11_DATA_PIN, Output);
DIO_WritePin(DHT11_DATA_PORT, DHT11_DATA_PIN, Low);
_delay_ms(18U);
DIO_WritePin(DHT11_DATA_PORT, DHT11_DATA_PIN, High);
_delay_us(30U);

//change Data Pin to Input
DIO_InitPin(DHT11_DATA_PORT, DHT11_DATA_PIN, Input);

//Wait for Dht11 Sensor to response Low
Timeout = DHT11_TIMEOUT_US;
do {
DIO_ReadPin(DHT11_DATA_PORT, DHT11_DATA_PIN, &PinState);
Timeout--;
if (Timeout == 0)
{
return DHT11_ERROR;
}
} while (PinState == High);



//Wait for Dht11 Sensor to response High
Timeout = DHT11_TIMEOUT_US;
do {
DIO_ReadPin(DHT11_DATA_PORT, DHT11_DATA_PIN, &PinState);
Timeout--;
if (Timeout == 0)
{
return DHT11_ERROR;
}
} while (PinState == Low);


//Wait for DHT11 to prepare data before transmission
Timeout = DHT11_TIMEOUT_US;
do {
DIO_ReadPin(DHT11_DATA_PORT, DHT11_DATA_PIN, &PinState);
Timeout--;
if (Timeout == 0) 
{
return DHT11_ERROR;
}
} while (PinState == High);

// Read 40 Bits
for (Index = 0; Index < 5; Index++)
{
for (BitIndex = 0; BitIndex < 8; BitIndex++)
{
//Wait for Dht11 Sensor to response Low
Timeout = DHT11_TIMEOUT_US;
do {
DIO_ReadPin(DHT11_DATA_PORT, DHT11_DATA_PIN, &PinState);
Timeout--;
if (Timeout == 0)
{
return DHT11_ERROR;
}
} while (PinState == Low);

//Wait for DHT11 Sensor to be high
Timeout = DHT11_TIMEOUT_US;
do {
DIO_ReadPin(DHT11_DATA_PORT, DHT11_DATA_PIN, &PinState);
Timeout--;
if (Timeout == 0)
{
return DHT11_ERROR;
}
} while (PinState == Low);
_delay_us(30U);

// Read the bit (High=1 , Low=0)
DIO_ReadPin(DHT11_DATA_PORT, DHT11_DATA_PIN, &PinState); 
if (PinState == High)
{
SET_BIT(Data[Index],(7-BitIndex));
}
else{
CLEAR_BIT(Data[Index],(7-BitIndex));
}

//Wait the DHT11 To complete the bit transimission 
Timeout = DHT11_TIMEOUT_US;
do {
DIO_ReadPin(DHT11_DATA_PORT, DHT11_DATA_PIN, &PinState);
Timeout--;
if(Timeout == 0)
{
return  DHT11_ERROR;
}
} while ((PinState == High));
}
}
//Verify checksum
if (Data[4U] == (uint8_t)(Data[0U] + Data[1U] + Data[2U] + Data[3U]))
{
*Humidity    = Data[0U];
*Temperature = Data[2U];
return DHT11_OK;
}
else
{
return DHT11_ERROR;
}
}
