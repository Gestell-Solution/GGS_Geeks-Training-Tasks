#include "ADXL_interface.h"

/*
    its a 3-axis sensing sensor 
    its an electromechainal device that uses force of gravity
    it uses springs that move and touch that plates at diffenent postions
    to give differnt signals
    rule to caluatate with adc
        Aout = (((adc value * vref ) / 1024) - voltage at 0 g) / senstivy scale factor 
        the voltage at 0g : 1.65v 
        senstivy scale factor : 330mV/g
        we do that for all 3 x , y , z
    
*/

void ADXL_uart_send_x_pos();
void ADXL_uart_send_y_pos();
void ADXL_uart_send_z_pos();


void ADXL_init()
{

    Adc_config_t Adc_config =
    {
        .volt_reference = AVCC,
        .adjust_direction = Adc_right_adjust,
        .source = Adc_free_running,
        .channel= Adc_channel_0,
        .prescaler = Adc_prescaler_64,
    };

    Uart_config_t Uart_config =
    {
        .baud_rate = 9600,
        .character_size = Uart_character_size_8,
        .clock_polarity = Uart_clock_polarity_fallingTX_risingRX,
        .enable_select = Uart_EnableRxAndTx,
        .mode_select = Uart_mode_async,
        .parity_mode = Uart_parity_mode_disabled,
        .speed_mode = Uart_speed_mode_normal,
        .stop_bit_select = Uart_stop_bit_1,
    };
    ADC_init(Adc_config);
    UART_init(Uart_config);


    DIO_set_pin_direction(ADXL_x_pos_group , ADXL_x_pos_pin , input);
  
    DIO_set_pin_direction(ADXL_y_pos_group , ADXL_y_pos_pin , input);
    
    DIO_set_pin_direction(ADXL_z_pos_group , ADXL_z_pos_pin , input);
    
}

f32 ADXL_get_x_pos()
{
    u16 result = 0 ;
    f32 voltage = 0.0f;
    f32 accel_g = 0.0f;
    ADC_read_specific_channel(ADXL_x_channel);    
    result = ADC_read_specific_channel(ADXL_x_channel);

    voltage = ((f32)result * ADXL_vref) / ADXL_adc_max;
    accel_g = (voltage - ADXL_zero_g_volt) / ADXL_senstivity;

    return accel_g;
}

f32 ADXL_get_y_pos()
{
    u16 result = 0 ;
    f32 voltage = 0.0f;
    f32 accel_g = 0.0f;
    ADC_read_specific_channel(ADXL_y_channel);    
    result = ADC_read_specific_channel(ADXL_y_channel);

    voltage = ((f32)result * ADXL_vref) / ADXL_adc_max;
    accel_g = (voltage - ADXL_zero_g_volt) / ADXL_senstivity;

    return accel_g;
}

f32 ADXL_get_z_pos()
{
    u16 result = 0 ;
    f32 voltage = 0.0f;
    f32 accel_g = 0.0f;
    ADC_read_specific_channel(ADXL_z_channel);    
    result = ADC_read_specific_channel(ADXL_z_channel);

    voltage = ((f32)result * ADXL_vref) / ADXL_adc_max;
    accel_g = (voltage - ADXL_zero_g_volt) / ADXL_senstivity;

    return accel_g;
}

void ADXL_uart_send_x_pos()
{
    f32 result = 0.0 ;
    UART_send_string_polling("x_pos : ");
    result = ADXL_get_x_pos();
    UART_send_number_polling(result);
    UART_send_string_polling("  ");
}

void ADXL_uart_send_y_pos()
{
    f32 result = 0.0 ;
    UART_send_string_polling("y_pos : ");
    result = ADXL_get_y_pos();
    UART_send_number_polling(result);
    UART_send_string_polling("  ");

}

void ADXL_uart_send_z_pos()
{
    f32 result = 0.0 ;
    UART_send_string_polling("z_pos : ");
    result = ADXL_get_z_pos();
    UART_send_number_polling(result);
    UART_send_string_polling("  ");
}

void ADXL_uart_send_accel()
{
    ADXL_uart_send_x_pos();
    ADXL_uart_send_y_pos();
    ADXL_uart_send_z_pos();
}