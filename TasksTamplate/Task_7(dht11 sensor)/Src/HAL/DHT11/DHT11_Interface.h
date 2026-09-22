/**
 * @file    DHT11_Interface.h
 * @brief   Interface file for the DHT11 driver.
 * @author  Yousef Mohamed
 * @date    2026-09-22
 */
#ifndef DHT11_INTERFACE_H_
#define DHT11_INTERFACE_H_

#include <stdint.h>

/**
 * @brief DHT11 driver return status.
 */
typedef enum
{
    DHT11_OK = 0U,
    DHT11_ERROR_NULL_PTR,
    DHT11_ERROR_TIMEOUT,
    DHT11_ERROR_CHECKSUM
} DHT11_Status_t;

/**
 * @brief Initialize the DHT11 data pin.
 * @return void.
 */
void DHT11_Init(void);

/**
 * @brief Read humidity and temperature from the DHT11 sensor.
 * @param[out] Humidity Relative humidity value.
 * @param[out] Temperature Temperature value in degree Celsius.
 * @return DHT11_Status_t Driver status.
 */
DHT11_Status_t DHT11_ReadData(uint8_t *Humidity, uint8_t *Temperature);

#endif /* DHT11_INTERFACE_H_ */
