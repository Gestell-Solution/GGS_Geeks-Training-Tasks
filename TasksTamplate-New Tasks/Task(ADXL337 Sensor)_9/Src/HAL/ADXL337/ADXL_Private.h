/**
 * @file ADXL_Private.h
 * @brief This file contains The Private Calculation for ADXL337 Sensor.
 * @author Developer: Abdulrahman Ali 
 * @author Reviewer : Eng/Hesham Ahmed
 * @date 9/20/2026
 * @copyright Copyright (c) 2026 , Gestell Company. All rights reserved.
 * @version 1.0.0
*/
#ifndef ADXL_PRIVATE_H
#define ADXL_PRIVATE_H
#include <stdint.h>


/** 
* Mathematical Constants for Calculation 
*/
#define ADXL337_VREF                3.3f      /* Reference Voltage in Volts */
#define ADXL337_ADC_MAX_VALUE       1023.0f   /* ((2^10)-1=1024-1=1032) 10-bit ADC Maximum Reading */
#define ADXL337_ZERO_G_VOLTAGE      1.65f     /* Offset voltage at 0g ((VCC) 3.3 / 2) */
#define ADXL337_SENSITIVITY         0.300f    /* Sensitivity = 300mV/g = 0.3V/g */






#endif /* ADXL_PRIVATE_H */
