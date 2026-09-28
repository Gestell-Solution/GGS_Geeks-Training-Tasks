/**
 * @file ADXL_Config.h
 * @brief Configuration definitions for the ADXL Sensor driver 
 * @details This file is supposed to contain the compile-time configuration parameters
 * required to initialize and operate ADXL Sensor driver.
 * @version 1.0.0
 * @author Ali Sotohy (alielsotohy2006@gmail.com) 
 * @date 22-09-2026 
 * @copyright Copyright (c) 2026, Gestell Company
 */



#ifndef ADXL335_CONFIG_H
#define ADXL335_CONFIG_H

/** @brief ADC channel each axis is wired to. */
#define ADXL335_X_CHANNEL   0U
#define ADXL335_Y_CHANNEL   1U
#define ADXL335_Z_CHANNEL   2U

/**
 * @brief The MCU's own ADC reference voltage (AVCC/AREF), in volts.
 * @note  This is NOT the sensor's own supply - see
 *        ADXL335_SUPPLY_VOLTAGE in ADXL335_Private.h for that.
 */
#define ADXL335_ADC_REF_VOLTAGE     5.0f

/** @brief Max raw ADC value for a 10-bit conversion (2^10 - 1). */
#define ADXL335_ADC_MAX_VAL         1023.0f

#endif /* ADXL335_CONFIG_H */

