#ifndef _ADC_PRIVATE_H_
#define _ADC_PRIVATE_H_

// first the ADMUX 

// the bits for selection

#define Adc_REFS0   6  
#define Adc_REFS1   7 

// the selection modes
/* not used
    #define Adc_mode_voltage_reference_selection_INTERAL_OFF    0 
    #define Adc_mode_voltage_reference_selection_AVCC_with_CAP  1 
    #define Adc_mode_voltage_reference_selection_INTERNAL_2_56V 2 

*/
typedef enum  // to chose the voltage refernce what to use
{
    AREF = 0, 
    AVCC,  // 1
    INTERNAL, // 2
}Adc_voltage_reference_t;
// adc left adjust result
// if its 1 then it left adjuct , otherwise it its right adjucsted

#define Adc_ADlAR   5  

typedef enum 
{
Adc_right_adjust,
Adc_left_adjust, 
}Adc_adjust_t ;

// the MUX4:0  Analog Channel and Gain Selection Bits
/*  not used
    #define Adc_MUX0  0  
    #define Adc_MUX1  1  
    #define Adc_MUX2  2  
    #define Adc_MUX3  3  
    #define Adc_MUX4  4  

*/

// channel selection 
typedef enum
{
    // SINGLE ENDED
    Adc_channel_0 = 0 , 
    Adc_channel_1,
    Adc_channel_2,
    Adc_channel_3,
    Adc_channel_4,
    Adc_channel_5,
    Adc_channel_6,
    Adc_channel_7,
    // differtial first 10x
    Adc_channel_0_0_10x, //8
    Adc_channel_1_0_10x, //9
    // differtntail first 200x
    Adc_channel_0_0_200x, // 10
    Adc_channel_1_0_200x, // 11
    // differntail 2nd 10x
    Adc_channel_2_2_10x, // 12
    Adc_channel_3_2_10x, // 13
    // differntail 2nx 200x
    Adc_channel_2_2_200x, // 14 
    Adc_channel_3_2_200x, //15
    // differntail rest 1x
    //differntail against first adc
    Adc_channel_0_1_1x,  // 16
    Adc_channel_1_1_1x,  // 17
    Adc_channel_2_1_1x,  // 18
    Adc_channel_3_1_1x,  // 19
    Adc_channel_4_1_1x,  // 20
    Adc_channel_5_1_1x,  // 21
    Adc_channel_6_1_1x,  // 22
    Adc_channel_7_1_1x,  // 23
    //differntail against 2nd adc
    Adc_channel_0_2_1x,  // 24  
    Adc_channel_1_2_1x,  // 25  
    Adc_channel_2_2_1x,  // 26  
    Adc_channel_3_2_1x,  // 27  
    Adc_channel_4_2_1x,  // 28  
    Adc_channel_5_2_1x,  // 29  

    // last single ended
    Adc_1_22V,  // 30
    Adc_0V_GND, // 31

}Adc_channel_t;

//ADCSRA 

#define Adc_ADEN    7 // enbale
#define Adc_ADSC    6 // start conversion
#define Adc_ADATE   5 // auto trigger enable
#define Adc_ADIF    4 // interput flag
#define Adc_ADIE    3 // interput enable

// prescaller bits
/* not used
    #define Adc_ADPS2   2   
    #define Adc_ADPS1   1
    #define Adc_ADPS0   0

*/

// prescaler modes              
typedef enum 
{
    Adc_prescaler_2 = 1 ,   //1
    Adc_prescaler_4,        //2
    Adc_prescaler_8,        //3
    Adc_prescaler_16,       //4
    Adc_prescaler_32,       //5
    Adc_prescaler_64,       //6
    Adc_prescaler_128,      //7
    
}Adc_prescaler_t;
// SFIOR 
// ADC autotrigger source bits
/* not used
    #define Adc_ADTS0   5
    #define Adc_ADTS1   6
    #define Adc_ADTS2   7

*/

// adc autotrigger sources modes

typedef enum
{
    Adc_free_running = 0 ,  
    Adc_analog_compartor,
    Adc_external_interupt_requeset_0,
    Adc_timer0_CTC,
    Adc_timer0_OVF,
    Adc_timer1_CTCB,
    Adc_timer1_OVF,
    Adc_timer1_capture_event,

}Adc_interput_source_t;

typedef struct adc_confgiurations
{
    Adc_voltage_reference_t volt_reference ;
    Adc_adjust_t            adjust_direction;
    Adc_channel_t           channel;
    Adc_prescaler_t         prescaler;
    Adc_interput_source_t   source;
}Adc_config_t;


#define Adc_mask_channel   0x1F        // 0 0 0 1 1 1 1 1
#define Adc_mask_prescaler 0x07        // 0 0 0 0 0 1 1 1
#define Adc_mask_interput_sources 0xE0 // 1 1 1 0 0 0 0 0
#define Adc_mask_result 0x03FF // 16 bits we need 10 only  left adjsut

#endif 