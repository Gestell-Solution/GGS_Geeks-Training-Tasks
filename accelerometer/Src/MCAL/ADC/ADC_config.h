#ifndef _ADC_CONFIG_H_
#define _ADC_CONFIG_H_

#include "ADC_private.h"
// adc defualt
#define Adc_defualt_VOLT_REF        AVCC
#define Adc_defualt_ADJUST          Adc_right_adjust
#define Adc_defualt_CHANNEL         Adc_channel_0
#define Adc_defualt_PRESCALER       Adc_prescaler_64
#define Adc_defualt_TRIGGER_SOURCE  Adc_free_running

/* copy for fast usage
Adc_config_t config_ADC = 
{
    .volt_reference = Adc_defualt_VOLT_REF,
    .adjust_direction = Adc_defualt_ADJUST,
    .channel = Adc_defualt_CHANNEL,
    .source = Adc_defualt_TRIGGER_SOURCE,
    .prescaler = Adc_defualt_PRESCALER,
};
*/

#endif
