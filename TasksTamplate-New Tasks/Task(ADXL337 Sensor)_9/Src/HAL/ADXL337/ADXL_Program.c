/**
 * @file ADXL_Program.c
 * @brief This file contains the Implementation of Function ADXL337 Sensor.
 * @author Developer: Abdulrahman Ali 
 * @author Reviewer : Eng/Hesham Ahmed
 * @date 9/20/2026
 * @copyright Copyright (c) 2026 , Gestell Company. All rights reserved.
 * @version 1.0.0
*/
#include "../../MCAL/ADC/ADC_Interface.h"
#include <stdint.h>
#include "ADXL_Config.h"
#include "ADXL_Interface.h"
#include "ADXL_Private.h"


/**
* Initialize ADXL337 driver 
*/
void ADXL_Init(void)
{
/* Initialize ADC with selected reference voltage and right adjustment */
ADC_Init(ADXL337_VOLTAGE_REF_MODE);
ADC_Adjust(ADC_RIGHT_ADJUST);
}


/** 
* Read X-axis acceleration 
*/
float16_t ADXL337_GetX(void)
{
uint16_t Result = 0;
float16_t Voltage = 0.0f;
float16_t AccelG = 0.0f;

/* Select X Channel & Read Digital Result */
ADC_Channel(ADXL337_X_CHANNEL);
Result = ADC_ReadResult();

/* Direct Conversion: Digital -> Voltage -> Acceleration (g) */
Voltage = ((float16_t)Result * ADXL337_VREF) / ADXL337_ADC_MAX_VALUE;
AccelG  = (Voltage - ADXL337_ZERO_G_VOLTAGE) / ADXL337_SENSITIVITY;

return AccelG;
}


/** 
* Read Y-axis acceleration 
*/
float16_t ADXL337_GetY(void)
{
uint16_t Result = 0;
float16_t Voltage = 0.0f;
float16_t AccelG = 0.0f;

/* Select Y Channel & Read Digital Result */
ADC_Channel(ADXL337_Y_CHANNEL);
Result = ADC_ReadResult();

/* Direct Conversion: Digital -> Voltage -> Acceleration (g) */
Voltage = ((float16_t)Result * ADXL337_VREF) / ADXL337_ADC_MAX_VALUE;
AccelG  = (Voltage - ADXL337_ZERO_G_VOLTAGE) / ADXL337_SENSITIVITY;

return AccelG;
}

/**
*  Read Z-axis acceleration
*/
float16_t ADXL337_GetZ(void)
{
uint16_t Result = 0;
float16_t Voltage = 0.0f;
float16_t AccelG = 0.0f;

/* Select Z Channel & Read Digital Result */
ADC_Channel(ADXL337_Z_CHANNEL);
Result = ADC_ReadResult();
/* Direct Conversion: Digital -> Voltage -> Acceleration (g) */
Voltage = ((float16_t)Result * ADXL337_VREF) / ADXL337_ADC_MAX_VALUE;
AccelG  = (Voltage - ADXL337_ZERO_G_VOLTAGE) / ADXL337_SENSITIVITY;
return AccelG;
}


/** 
* Read all three axes 
*/
void ADXL337_GetAcceleration(float16_t *X, float16_t *Y, float16_t *Z)
{

if ((X != Null) && (Y != Null) && (Z != Null))
{
    *X = ADXL337_GetX();
    *Y = ADXL337_GetY();
    *Z = ADXL337_GetZ();
}
}

