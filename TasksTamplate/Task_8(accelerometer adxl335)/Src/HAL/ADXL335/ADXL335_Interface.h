/**
 * @file ADXL335_Interface.h
 * @brief ADXL335 accelerometer public interface.
 * @details Declares the public APIs of the analog 3-axis ADXL335 driver.
 *          The driver uses the MCAL ADC module to convert XOUT, YOUT and
 *          ZOUT voltages into raw ADC values or acceleration in milli-g.
 * @version 1.1.0
 * @author Yousef Mohamed
 * @date 2026-09-25
 * @copyright Copyright (c) 2026, Gestell Company. All rights reserved.
 */

#ifndef ADXL335_INTERFACE_H
#define ADXL335_INTERFACE_H

#include <stdint.h>

/** Operation completed successfully. */
#define ADXL335_OK             0U

/** Invalid parameter or ADC read error. */
#define ADXL335_ERROR          1U

/** X-axis selector. */
#define ADXL335_AXIS_X         0U

/** Y-axis selector. */
#define ADXL335_AXIS_Y         1U

/** Z-axis selector. */
#define ADXL335_AXIS_Z         2U

/**
 * @brief Initialize the ADXL335 driver.
 * @return ADXL335_OK after configuring the ADC.
 */
uint8_t ADXL335_Init(void);

/**
 * @brief Read the raw ADC value of one ADXL335 axis.
 * @param[in] Axis Axis selector: ADXL335_AXIS_X, ADXL335_AXIS_Y or
 *                 ADXL335_AXIS_Z.
 * @param[out] RawValue Pointer to receive the 10-bit ADC result.
 * @return ADXL335_OK on success; ADXL335_ERROR on invalid input or ADC error.
 */
uint8_t ADXL335_ReadRaw(uint8_t Axis, uint16_t *RawValue);

/**
 * @brief Read acceleration of one axis in milli-g.
 * @param[in] Axis Axis selector: ADXL335_AXIS_X, ADXL335_AXIS_Y or
 *                 ADXL335_AXIS_Z.
 * @param[out] Acceleration Pointer to receive the signed acceleration.
 * @return ADXL335_OK on success; ADXL335_ERROR on invalid input or ADC error.
 */
uint8_t ADXL335_ReadAxis_mg(uint8_t Axis, int16_t *Acceleration);

/**
 * @brief Read X, Y and Z acceleration in milli-g.
 * @param[out] X Pointer to receive X-axis acceleration.
 * @param[out] Y Pointer to receive Y-axis acceleration.
 * @param[out] Z Pointer to receive Z-axis acceleration.
 * @return ADXL335_OK on success; ADXL335_ERROR if any pointer is invalid or
 *         an ADC read fails.
 */
uint8_t ADXL335_ReadXYZ_mg(int16_t *X, int16_t *Y, int16_t *Z);

#endif
