/**
 * @file    DHT11_Private.h
 * @brief   Private definitions used by the DHT11 driver.
 * @author  Yousef Mohamed
 * @date    2026-09-22
 */
#ifndef DHT11_PRIVATE_H_
#define DHT11_PRIVATE_H_

/** @brief Number of bytes in one DHT11 frame. */
#define DHT11_FRAME_SIZE              (5U)

/** @brief Number of bits in one byte. */
#define DHT11_BITS_PER_BYTE           (8U)

/** @brief Humidity integer byte index. */
#define DHT11_HUMIDITY_INT_INDEX      (0U)

/** @brief Humidity decimal byte index. */
#define DHT11_HUMIDITY_DEC_INDEX      (1U)

/** @brief Temperature integer byte index. */
#define DHT11_TEMPERATURE_INT_INDEX   (2U)

/** @brief Temperature decimal byte index. */
#define DHT11_TEMPERATURE_DEC_INDEX   (3U)

/** @brief Checksum byte index. */
#define DHT11_CHECKSUM_INDEX          (4U)

#endif /* DHT11_PRIVATE_H_ */
