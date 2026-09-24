/**
 * @file ADXL335_Interface.h
 * @brief  Interface of ADXL335 driver
 * @details This file contains function prototypes required to interface with ADXL335 driver  
 * @version 0.1
 * @author Malak Mohammed (malak.mohammed.esmail@gmail.com) 
 * @date 24-09-2026
 * @copyright Copyright (c) 2026, Gestell Company
 */

 #ifndef ADXL335_INTERFACE_H
 #define ADXL335_INTERFACE_H

 #include <stdint.h>
 #include "../../MCAL/Atmega32regmap.h"
 #include "../../Common/Bitmath.h"
 #include "../../Common/Definition.h"
 #include "ADXL335_Private.h"
 #include "ADXL335_Config.h"

 /** @brief initializes ADXL335 Sensor 
  */
 void ADXL335_Init(void);

 /** @brief Reads the unprocesses ADC integer values of the 3-axes of ADXL335
  * @param X_Raw The unprocessed ADC integer value for x-axis 
  * @param Y_Raw The unprocessed ADC integer value for y-axis  
  * @param Z_Raw  The unprocessed ADC integer value for z-axis 
  */
 void ADXL335_ReadRaw (uint16_t *X_Raw,uint16_t *Y_Raw,uint16_t *Z_Raw);

  /** @brief Reads the gravity force values of the axes movement 
  * @param X_G  g force value of x-axis
  * @param Y_G g force value of y-axis
  * @param Z_G g force value of z-axis
  */
 void ADXL335_ReadG (float *X_G,float *Y_G, float *Z_G);


#endif