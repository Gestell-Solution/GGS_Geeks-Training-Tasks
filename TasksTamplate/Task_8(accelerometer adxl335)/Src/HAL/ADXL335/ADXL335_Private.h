/**
 * @file ADXL335_Private.h
 * @brief ADXL335 private definitions.
 * @details Contains private constants used for ADC-to-acceleration conversion.
 * @version 1.1.0
 * @author Yousef Mohamed
 * @date 2026-09-25
 * @copyright Copyright (c) 2026, Gestell Company. All rights reserved.
 */

#ifndef ADXL335_PRIVATE_H
#define ADXL335_PRIVATE_H

#include <stdint.h>

/** Maximum ADC result for a 10-bit ADC. */
#define ADXL335_ADC_MAX_VALUE         1023UL

/** Number of millivolts in one volt. */
#define ADXL335_MV_PER_V              1000L

/** Nominal zero-g output is VS/2. */
#define ADXL335_ZERO_G_DIVISOR        2UL

/** Valid axis count. */
#define ADXL335_AXIS_COUNT            3U

/** Validates an ADXL335 axis selector. */
#define ADXL335_IS_AXIS_VALID(Axis) \
    ((uint8_t)((Axis) < ADXL335_AXIS_COUNT))

#endif
