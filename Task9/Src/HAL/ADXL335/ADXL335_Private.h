/**
 * @file ADXL335_Private.h
 * @brief Private definitions for ADXL335 driver
 * @details This file contains the internal definitions required by ADXL335 driver implementation.
 * @version 0.1
 * @author Malak Mohammed (malak.mohammed.esmail@gmail.com) 
 * @date 24-09-2026
 * @copyright Copyright (c) 2026, Gestell Company
 */
#ifndef ADXL335_PRIVATE_H
#define ADXL335_PRIVATE_H

/** @brief defining axis X of ADXL335 */
#define ADXL335_Axis_X 0
/** @brief defining axis Y of ADXL335 */
#define ADXL335_Axis_Y 1
/** @brief defining axis Z of ADXL335 */
#define ADXL335_Axis_Z 2

/** @brief the specified nominal volatge  */
#define ADXL335_NOMINAL_SUPPLY_V    3.0f   

/** @brief 300 mV/g at 3V supply  */
#define ADXL335_NOMINAL_SENSITIVITY 0.3f   

/** @brief Max digital value of a 10-bit ADC   */
#define ADXL335_ADC_MAX_VAL    1023.0f


#endif


