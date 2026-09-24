/**
 * @file SPI_Private.h
 * @brief SPI private definitions.
 * @details Contains the SPI register bit positions, the fixed SPI pin
 *          numbers of PORTB and the values accepted by ::SPI_Config_t.
 *          The file is included by SPI_Interface.h.
 * @version 1.1.0
 * @author Yousef Mohamed
 * @date 2026-09-24
 * @copyright Copyright (c) 2026, Gestell Company. All rights reserved.
 */

#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

#include <stdint.h>

#define SPI_SPIE        7U      /**< SPI Interrupt Enable. */
#define SPI_SPE         6U      /**< SPI Enable. */
#define SPI_DORD        5U      /**< Data Order (1 = LSB first). */
#define SPI_MSTR        4U      /**< Master/Slave Select (1 = master). */
#define SPI_CPOL        3U      /**< Clock Polarity. */
#define SPI_CPHA        2U      /**< Clock Phase. */
#define SPI_SPR1        1U      /**< SPI Clock Rate Select bit 1. */
#define SPI_SPR0        0U      /**< SPI Clock Rate Select bit 0. */

#define SPI_SPIF        7U      /**< SPI Interrupt Flag (transfer complete). */
#define SPI_WCOL        6U      /**< Write Collision Flag. */
#define SPI_SPI2X       0U      /**< Double SPI Speed bit. */

#define SPI_SS_PIN      4U      /**< PB4: Slave Select. */
#define SPI_MOSI_PIN    5U      /**< PB5: Master Out Slave In. */
#define SPI_MISO_PIN    6U      /**< PB6: Master In Slave Out. */
#define SPI_SCK_PIN     7U      /**< PB7: Serial Clock. */

#define SPI_Prescaller4_NormalSpeed         0U  /**< fosc/4   (SPI2X=0, SPR=00). */
#define SPI_Prescaller16_NormalSpeed        1U  /**< fosc/16  (SPI2X=0, SPR=01). */
#define SPI_Prescaller64_NormalSpeed        2U  /**< fosc/64  (SPI2X=0, SPR=10). */
#define SPI_Prescaller128_NormalSpeed       3U  /**< fosc/128 (SPI2X=0, SPR=11). */
#define SPI_Prescaller2_DoubleSpeed         4U  /**< fosc/2   (SPI2X=1, SPR=00). */
#define SPI_Prescaller8_DoubleSpeed         5U  /**< fosc/8   (SPI2X=1, SPR=01). */
#define SPI_Prescaller32_DoubleSpeed        6U  /**< fosc/32  (SPI2X=1, SPR=10). */
#define SPI_Prescaller64_DoubleSpeed        7U  /**< fosc/64  (SPI2X=1, SPR=11). */

#define LSB_First       0U      /**< Least significant bit is transmitted first. */
#define MSB_First       1U      /**< Most significant bit is transmitted first. */

#define Slave_mode      0U      /**< The device operates as SPI slave. */
#define Master_mode     1U      /**< The device operates as SPI master. */

#define SPI_CPOL_LOW    0U      /**< SCK is low when idle. */
#define SPI_CPOL_HIGH   1U      /**< SCK is high when idle. */

#define SPI_SAMPLE_LEADING      0U  /**< Data sampled on the leading clock edge. */
#define SPI_SAMPLE_TRAILING     1U  /**< Data sampled on the trailing clock edge. */

#endif 
