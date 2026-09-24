/**
 * @file ADXL342_Config.h
 * @brief ADXL342 accelerometer configuration.
 * @details Selects the chip-select pin, the SPI clock and the sensor
 *          settings (output data rate and measurement range) used by
 *          ADXL342_Init(). Change these values to match the hardware.
 * @version 1.0.0
 * @author Yousef Mohamed
 * @date 2026-09-24
 * @copyright Copyright (c) 2026, Gestell Company. All rights reserved.
 */

#ifndef ADXL342_CONFIG_H
#define ADXL342_CONFIG_H

#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/SPI/SPI_Interface.h"
#include "ADXL342_Private.h"


/** DIO port of the chip-select (CS) pin. */
#define ADXL342_CS_GROUP            Dio_GroupB

/** DIO pin of the chip-select (CS) pin (PB4 is also the hardware SS pin). */
#define ADXL342_CS_PIN              Dio_Pin4


#define ADXL342_SPI_CLOCK_RATE      SPI_Prescaller4_NormalSpeed

/** Output data rate written to BW_RATE (one of ADXL342_ODR_VALUES). */
#define ADXL342_DATA_RATE           ADXL342_ODR_100HZ

/** Measurement range written to DATA_FORMAT (one of ADXL342_RANGE_VALUES). */
#define ADXL342_RANGE               ADXL342_RANGE_2G

/**
 * Device ID expected in the DEVID register.
 * ADXL_34x family value; change it if the connected part reports another ID.
 */
#define ADXL342_EXPECTED_DEVICE_ID  0xE5U

#endif 
