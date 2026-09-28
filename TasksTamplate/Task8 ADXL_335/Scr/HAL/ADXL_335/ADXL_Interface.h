/**
 * @file ADXL_Interface.h
 * @brief Interface of DHT11 Sensor driver 
 * @details This file contains function prototypes required to interface with ADXL sensor driver.
 * @version 1.0.0
 * @author Ali Sotohy (alielsotohy2006@gmail.com) 
 * @date 22-09-2026 
 * @copyright Copyright (c) 2026, Gestell Company
 */

#ifndef ADXL_INTERFACE_H
#define ADXL_INTERFACE_H

#include <stdint.h>
#include "../../Common/Defination.h"  /* for Null */
#include "ADXL_Config.h"
#include "ADXL_Private.h"

/**
 * @brief Reserved for future configuration (e.g. controlling the ST pin).
 */
void ADXL335_Init(void);

/**
 * @brief Reads the raw 10-bit ADC value on each axis.
 * @param X_Raw,Y_Raw,Z_Raw Out-parameters; left untouched if any is Null.
 */
void ADXL335_ReadRaw(uint16_t *X_Raw, uint16_t *Y_Raw, uint16_t *Z_Raw);

/**
 * @brief Reads all three axes and converts them to g-force.
 * @param X_G,Y_G,Z_G Out-parameters; left untouched if any is Null.
 */
void ADXL335_ReadG(float *X_G, float *Y_G, float *Z_G);

#endif /* ADXL335_INTERFACE_H */