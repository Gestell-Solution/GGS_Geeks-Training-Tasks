/**
 * @file ADXL335_Config.h
 * @brief ADXL335 accelerometer configuration.
 * @details Contains the ADC channels and electrical parameters used by the
 *          ADXL335 driver. The sensor outputs are analog voltages.
 * @version 1.1.0
 * @author Yousef Mohamed
 * @date 2026-09-25
 * @copyright Copyright (c) 2026, Gestell Company. All rights reserved.
 */

#ifndef ADXL335_CONFIG_H
#define ADXL335_CONFIG_H

#include "../../MCAL/ADC/ADC_Interface.h"

/** ADC channel connected to the ADXL335 XOUT pin. */
#define ADXL335_X_CHANNEL             Adc_SingleEndedChannel0

/** ADC channel connected to the ADXL335 YOUT pin. */
#define ADXL335_Y_CHANNEL             Adc_SingleEndedChannel1

/** ADC channel connected to the ADXL335 ZOUT pin. */
#define ADXL335_Z_CHANNEL             Adc_SingleEndedChannel2

/** ADC voltage reference selected by the ADC driver. */
#define ADXL335_ADC_REFERENCE         Adc_AVCC

/** ADC prescaler used with the project CPU clock. */
#define ADXL335_ADC_PRESCALER         Adc_Prescaler_64

/**
 * ADC polling timeout.
 * This value is a loop-count limit, not a time value in seconds.
 */
#define ADXL335_ADC_TIMEOUT           100000UL

/**
 * Actual ADC reference voltage in millivolts.
 * With Adc_AVCC on the current ATmega32 setup, this is normally 5000 mV.
 * Change this value if the actual AVCC/reference voltage is different.
 */
#define ADXL335_ADC_VREF_MV           5000UL

/**
 * ADXL335 sensor supply voltage in millivolts.
 * The sensor must be powered within its 1.8 V to 3.6 V operating range.
 * The default assumes VS = 3.0 V.
 */
#define ADXL335_SENSOR_VS_MV          3000UL

/**
 * Typical ADXL335 sensitivity at VS = 3 V.
 * Datasheet values at VS = 3 V are 270 mV/g minimum,
 * 300 mV/g typical and 330 mV/g maximum.
 */
#define ADXL335_SENSITIVITY_MV_PER_G  300UL

#endif
