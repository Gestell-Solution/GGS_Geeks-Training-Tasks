#ifndef _ADC_INTERFACE_H_
#define _ADC_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/COMMON_MACROS.h"
#include "../REG_MAP.h"

#include "ADC_config.h"
#include "ADC_private.h"

// Adc_voltage_reference_t refrence ;
// Adc_channel_t channel;
// Adc_interput_source_t soruce;

void ADC_init(Adc_config_t config);
// fucntiosn inside the init

// only fucntion neded to start the adc after init
void ADC_start_conversion();

// void ADC_is_busy();

void ADC_enable();
void ADC_disable();



u16 ADC_read_result();

// extern Adc_config_t config_defualt_ADC;

/*  functions i dont need only for adc not whole app
void ADC_auto_trigger_enable();
void ADC_auto_trigger_disable();

void ADC_interrupt_enable();
void ADC_interrupt_disable();

void ADC_adjust_direction(Adc_adjust_t direction);
void ADC_channel(Adc_channel_t channel);
void ADC_Prescaler(Adc_prescaler_t Prescaler);
void ADC_source_selection(Adc_interput_source_t source);
void ADC_volt_reference (Adc_voltage_reference_t reference);
*/
#endif
