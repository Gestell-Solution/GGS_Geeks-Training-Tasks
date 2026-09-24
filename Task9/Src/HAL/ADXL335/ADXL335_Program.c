/**
 * @file ADXL335_Program.c
 * @brief Implementation of ADXL335 driver
 * @details This file contains the implementation of ADXL335 driver APIs 
 * @version 0.1
 * @author Malak Mohammed (malak.mohammed.esmail@gmail.com) 
 * @date 22-09-2026
 * @copyright Copyright (c) 2026, Gestell Company
 */
   
  #include "ADXL335_Interface.h"
  #include "../../MCAL/ADC/ADC_Interface.h"


  void ADXL335_Init(void)
  {
  /** Reserved for future configurations (e,g controlling Self-Test pin 'ST' ) */
  }



   void ADXL335_ReadRaw (uint16_t *X_Raw,uint16_t *Y_Raw,uint16_t *Z_Raw)
   {
    if(X_Raw!=Null&&Y_Raw!=Null&&Z_Raw!=Null)
    {
      *X_Raw=ADC_ReadChannelPolling(ADXL335_X_CHANNEL);
      *Y_Raw=ADC_ReadChannelPolling(ADXL335_Y_CHANNEL);
      *Z_Raw=ADC_ReadChannelPolling(ADXL335_Z_CHANNEL);

    }
   
   }

    void ADXL335_ReadG (float *X_G,float *Y_G, float *Z_G)
    {
      uint16_t X_Raw = 0, Y_Raw = 0, Z_Raw = 0;
      if((X_G!=Null)&&(Y_G!=Null)&&(Z_G!=Null))
      {
        ADXL335_ReadRaw (&X_Raw,&Y_Raw,&Z_Raw);

        /* Converting raw ADC bits to actual voltage that was measured at microcontroller ADC pins */
        float X_Volt = ((float)X_Raw / ADXL335_ADC_MAX_VAL) * ADXL335_ADC_REF_VOLTAGE;
        float Y_Volt = ((float)Y_Raw / ADXL335_ADC_MAX_VAL) * ADXL335_ADC_REF_VOLTAGE;
        float Z_Volt = ((float)Z_Raw / ADXL335_ADC_MAX_VAL) * ADXL335_ADC_REF_VOLTAGE;


        float Sensitivity = ADXL335_NOMINAL_SENSITIVITY * (ADXL335_SUPPLY_VOLTAGE / ADXL335_NOMINAL_SUPPLY_V);
        float Resting_Volt = ADXL335_SUPPLY_VOLTAGE / 2.0;

        /* Calculate g-forces */
        *X_G = (X_Volt - Resting_Volt) / Sensitivity;
        *Y_G = (Y_Volt - Resting_Volt) / Sensitivity;
        *Z_G = (Z_Volt - Resting_Volt) / Sensitivity;

      }
    
    }


