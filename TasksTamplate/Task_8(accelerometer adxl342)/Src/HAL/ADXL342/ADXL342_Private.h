/**
 * @file ADXL342_Private.h
 * @brief ADXL342 private definitions.
 * @details Contains the register map, bit positions, SPI command bits and
 *          conversion constants of the ADXL342 driver. The register map
 *          follows the ADXL34x family (ADXL343/ADXL345).
 * @version 1.0.0
 * @author Yousef Mohamed
 * @date 2026-09-24
 * @copyright Copyright (c) 2026, Gestell Company. All rights reserved.
 */

#ifndef ADXL342_PRIVATE_H
#define ADXL342_PRIVATE_H

#include <stdint.h>


#define ADXL342_DEVID_REG           0x00U   /**< Device ID (read only). */
#define ADXL342_BW_RATE_REG         0x2CU   /**< Data rate and power mode control. */
#define ADXL342_POWER_CTL_REG       0x2DU   /**< Power-saving features control. */
#define ADXL342_DATA_FORMAT_REG     0x31U   /**< Data format control. */
#define ADXL342_DATAX0_REG          0x32U   /**< X-axis data 0 (low byte). */
#define ADXL342_DATAX1_REG          0x33U   /**< X-axis data 1 (high byte). */
#define ADXL342_DATAY0_REG          0x34U   /**< Y-axis data 0 (low byte). */
#define ADXL342_DATAY1_REG          0x35U   /**< Y-axis data 1 (high byte). */
#define ADXL342_DATAZ0_REG          0x36U   /**< Z-axis data 0 (low byte). */
#define ADXL342_DATAZ1_REG          0x37U   /**< Z-axis data 1 (high byte). */

#define ADXL342_MEASURE_BIT         3U      /**< POWER_CTL: measurement mode bit. */
#define ADXL342_FULL_RES_BIT        3U      /**< DATA_FORMAT: full-resolution bit. */

#define ADXL342_POWER_STANDBY       0x00U   /**< POWER_CTL value: standby mode. */
#define ADXL342_POWER_MEASURE       ((uint8_t)(1U << ADXL342_MEASURE_BIT)) /**< POWER_CTL value: measurement mode. */

/** DATA_FORMAT value: full resolution (3.9 mg/LSB) with the configured range. */
#define ADXL342_DATA_FORMAT_VALUE   ((uint8_t)((1U << ADXL342_FULL_RES_BIT) | ADXL342_RANGE))

#define ADXL342_RANGE_2G            0x00U   /**< +/- 2 g. */
#define ADXL342_RANGE_4G            0x01U   /**< +/- 4 g. */
#define ADXL342_RANGE_8G            0x02U   /**< +/- 8 g. */
#define ADXL342_RANGE_16G           0x03U   /**< +/- 16 g. */

#define ADXL342_ODR_6_25HZ          0x06U   /**< 6.25 Hz. */
#define ADXL342_ODR_12_5HZ          0x07U   /**< 12.5 Hz. */
#define ADXL342_ODR_25HZ            0x08U   /**< 25 Hz. */
#define ADXL342_ODR_50HZ            0x09U   /**< 50 Hz. */
#define ADXL342_ODR_100HZ           0x0AU   /**< 100 Hz (default). */
#define ADXL342_ODR_200HZ           0x0BU   /**< 200 Hz. */
#define ADXL342_ODR_400HZ           0x0CU   /**< 400 Hz. */
#define ADXL342_ODR_800HZ           0x0DU   /**< 800 Hz. */
#define ADXL342_ODR_1600HZ          0x0EU   /**< 1600 Hz. */
#define ADXL342_ODR_3200HZ          0x0FU   /**< 3200 Hz. */

#define ADXL342_READ_COMMAND        0x80U   /**< Bit 7 (R/W): 1 = read, 0 = write. */
#define ADXL342_MULTI_BYTE          0x40U   /**< Bit 6 (MB): 1 = multiple-byte transfer. */
#define ADXL342_ADDRESS_MASK        0x3FU   /**< Bits 5:0: register address. */
#define ADXL342_DUMMY_BYTE          0x00U   /**< Byte sent only to generate the SPI clock. */

#define ADXL342_DATA_LENGTH         6U      /**< Number of bytes of the X, Y and Z data. */
#define ADXL342_SCALE_NUMERATOR     39L     /**< Scale factor numerator: 3.9 mg/LSB = 39/10. */
#define ADXL342_SCALE_DENOMINATOR   10L     /**< Scale factor denominator. */
#define ADXL342_SIGN_LIMIT          0x8000U /**< First 16-bit value that is negative. */
#define ADXL342_WORD_RANGE          65536L  /**< Number of values of a 16-bit word. */


#endif
