/**
 * @file ADXL342_Interface.h
 * @brief ADXL342 accelerometer public interface.
 * @details Declares the APIs of the ADXL342 3-axis digital accelerometer
 *          driver. The sensor is used in 4-wire SPI mode 3 with a GPIO
 *          chip-select, in full-resolution mode (3.9 mg/LSB).
 * @version 1.0.0
 * @author Yousef Mohamed
 * @date 2026-09-24
 * @copyright Copyright (c) 2026, Gestell Company. All rights reserved.
 */

#ifndef ADXL342_INTERFACE_H
#define ADXL342_INTERFACE_H

#include <stdint.h>


#define ADXL342_OK          0U  /**< Operation succeeded. */
#define ADXL342_ERROR       1U  /**< Operation failed (sensor not found). */

uint8_t ADXL342_Init(void);

void ADXL342_WriteRegister(uint8_t RegisterAddress, uint8_t Data);

uint8_t ADXL342_ReadRegister(uint8_t RegisterAddress);

uint8_t ADXL342_ReadDeviceID(void);

void ADXL342_StartMeasurement(void);

void ADXL342_Standby(void);

void ADXL342_ReadXYZ(int16_t *X, int16_t *Y, int16_t *Z);

void ADXL342_ReadXYZ_mg(int16_t *X, int16_t *Y, int16_t *Z);

#endif
