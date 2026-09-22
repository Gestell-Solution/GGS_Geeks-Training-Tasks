/**
 * @file    DHT11_Config.h
 * @brief   Configuration file for the DHT11 driver.
 * @author  Yousef Mohamed
 * @date    2026-09-22
 */
#ifndef DHT11_CONFIG_H_
#define DHT11_CONFIG_H_

#include "../../MCAL/DIO/DIO_Interface.h"

/** @brief DHT11 data port. */
#define DHT11_DATA_GROUP              Dio_GroupB

/** @brief DHT11 data pin. */
#define DHT11_DATA_PIN                Dio_Pin0

/* The DATA line needs an external pull-up resistor to VCC. */

/** @brief Host start signal low time in milliseconds. */
#define DHT11_START_LOW_MS            (18U)

/** @brief Host start signal release time in microseconds. */
#define DHT11_START_RELEASE_US        (30U)

/** @brief Sampling time inside the data pulse in microseconds. */
#define DHT11_SAMPLE_TIME_US          (30U)

/** @brief Maximum time used while waiting for a bus transition. */
#define DHT11_WAIT_TIMEOUT_US         (100U)

#endif /* DHT11_CONFIG_H_ */
