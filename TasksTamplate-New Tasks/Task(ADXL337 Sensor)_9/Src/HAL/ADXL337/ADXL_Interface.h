/**
 * @file ADXL_Interface.h
 * @brief This file contains the Function Prototype for ADXL337 Sensor.
 * @author Developer: Abdulrahman Ali 
 * @author Reviewer : Eng/Hesham Ahmed
 * @date 9/20/2026
 * @copyright Copyright (c) 2026 , Gestell Company. All rights reserved.
 * @version 1.0.0
*/
#ifndef ADXL_INTERFACE_H
#define ADXL_INTERFACE_H
#include "ADXL_Private.h"
#include "ADXL_Config.h"
#include <stdint.h>

#ifndef __FLOAT16_T_DEFINED
#define __FLOAT16_T_DEFINED
typedef float float16_t;
#endif

/**
* Initialize ADXL337 driver 
*/
void ADXL337_Init(void);

/** 
* Read X-axis acceleration 
*/
float16_t ADXL337_GetX(void);

/** 
* Read Y-axis acceleration 
*/
float16_t ADXL337_GetY(void);

/**
*  Read Z-axis acceleration
*/
float16_t ADXL337_GetZ(void);

/** 
* Read all three axes 
*/
void ADXL337_GetAcceleration(float16_t *X, float16_t *Y, float16_t *Z);







#endif /* ADXL_INTERFACE_H */
