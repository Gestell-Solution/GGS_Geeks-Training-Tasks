/**
 * @file ADXL_Config.h
 * @brief This file contains the configuration Setting for ADXL337 Sensor.
 * @author Developer: Abdulrahman Ali 
 * @author Reviewer : Eng/Hesham Ahmed
 * @date 9/20/2026
 * @copyright Copyright (c) 2026 , Gestell Company. All rights reserved.
 * @version 1.0.0
*/
#ifndef ADXL_CONFIG_H
#define ADXL_CONFIG_H
#include <stdint.h>

/** 
* ADC Voltage Mode Selection (ADC_AVCC, ADC_AREF, or ADC_Internal) 
*/
#define ADXL337_VOLTAGE_REF_MODE    ADC_AVCC

/** 
*ADC Channels Selection for X, Y, Z axes 
*/
#define ADXL337_X_CHANNEL           ADC_CHANNEL0
#define ADXL337_Y_CHANNEL           ADC_CHANNEL1
#define ADXL337_Z_CHANNEL           ADC_CHANNEL2






#endif /* ADXL_CONFIG_H */
