#ifndef _TIMER1_PRIVATE_H
#define _TIMER1_PRIVATE_H
//111 page
//tccr1a reg 
#define TIMER1_COM1A1 7
#define TIMER1_COM1A0 6
#define TIMER1_COM1B1 5
#define TIMER1_COM1B0 4
//these are afected by yhe com1a and com1b this is for non pwm
//you get the same out put for if you choosed fast pwm or
//Compare Output Mode, Phase Correct and Phase and Frequency Correct PWM 
 #define TIMER1_normal 0
 #define TIMER1_toggle 1
 #define TIMER1_clear  2
 #define TIMER1_set    3
//force compare 
#define TIMER1_FOC1A  3
#define TIMER1_FOC1B  2
//wavefrom generation to selcet the mode
#define TIMER1_WGM11  1
#define TIMER1_WGM10  0
//dont forget to add wgm12
//WGM13:2 bits found in the TCCR1B Register, 
//here wgm13 is set to 0
 #define WGM13_is0                        1
  #define TIMER1_NORMAL_MODE              0
  #define TIMER1_PWM_8_MODE               1
  #define TIMER1_PWM_9_MODE               2
  #define TIMER1_PWM_10_MODE              3
  #define TIMER1_CTC_MODEforOCR1A         4
  #define TIMER1_FAST_PWM_8_MODE          5
  #define TIMER1_FAST_PWM_9_MODE          6
  #define TIMER1_FAST_PWM_10_MODE         7
  //here wgm13 is set to 1   
 #define WGM13_is1                        2
  #define TIMER1_PWM_MODEforICR1          8
  #define TIMER1_PWM_MODEforOCR1A         9
  #define TIMER1_PWM_PHASE_MODEforICR1    10
  #define TIMER1_PWM_PHASE_MODEforOCR1A   11
  #define TIMER1_CTC_MODEforICR1          12
  #define TIMER1_FAST_PWM_MODEforICR1     14
  #define TIMER1_FAST_PWM_MODEforOCR1A    15
 
// tccr1b REG 
#define TIMER1_ICNC1 7//noise
 #define noise_enable 1
 #define noise_disable 0
#define TIMER1_ICES1 6//EDGE SELECT
 #define falling_edge 0
 #define rising_edge  1
#define TIMER1_WGM13 4
#define TIMER1_WGM12 3
//PRESCALING
#define CS12         2
#define CS11         1
#define CS10         0
 #define TIMER1_Precaling_noClockSource       0
 #define TIMER1_Precaling_noPrecaling         1
 #define TIMER1_Precaling_8                   2 
 #define TIMER1_Precaling_64                  3
 #define TIMER1_Precaling_256                 4
 #define TIMER1_Precaling_1024                5
 #define TIMER1_Precaling_externalFallingEdge 6
 #define TIMER1_Precaling_externalrisingEdge  7
 #define TIMER1_prescaler_mask                0x07

//tcnt1hand tcnt1l
//for reading and writing
#define TCNT1L 0
#define TCNT1H 1
//OUTPUT COMPAREREG A
#define OCR1AL 0
#define OCR1AH 1
//OUTPUT COMPAREREG B
#define OCR1BL 0
#define OCR1BH 1

//timsk reg
#define TIMER1_TICIE1 5 //Input Capture Interrupt Enable
#define TIMER1_OCIE1A 4//Output Compare A Match Interrupt Enable
#define TIMER1_OCIE1B 3//Output Compare B Match Interrupt Enable
#define TIMER1_TOIE1  2//Overflow Interrupt Enable
//TIFR REG
#define TIMER1_ICF1  5//Input Capture Flag
#define TIMER1_OCF1A 4//Output Compare A Match Flag
#define TIMER1_OCF1B 3//Output Compare B Match Flag
#define TIMER1_TOV1  2//Overflow Flag
//the tirf work with icp1 and i need this for the ultrasonic it is pin6 groupd
typedef struct 
{
    uint8_t Timer_mode;
    uint8_t noiseEnable;
    uint8_t Edge;
    uint8_t interruptEnable;
    uint8_t Mode_type;     //WGM13
    uint8_t PwmOutputmode; //for inverting and non inverting
    uint16_t comparevalue; //ctc
    uint16_t preloadvalue; //normal
    uint16_t capturevalue; //icr1
}Timer1_config_t;

/*
timer1 interrupt
7 TIMER1 CAPT Timer/Counter1 Capture Event
8 TIMER1 COMPA Timer/Counter1 Compare Match A 
9 TIMER1 COMPB Timer/Counter1 Compare Match B
10 TIMER1 OVF Timer/Counter1 Overflow

they will be 6,7,8,9
*/
#define TIMER1_OverFlow     0
#define TIMER1_CTCA         1
#define TIMER1_CTCB         2
#define TIMER1_CaptureEvent 3

#define TIMER1_NonIverting 0
#define TIMER1_Iverting    1

#define TIMER1_MaxPWM       65535UL
#define TIMER1_MaxDutyCycle 100

#define TIMER1_FAST_PWM_8_Max  0x00FF
#define TIMER1_FAST_PWM_9_Max  0x01FF 
#define TIMER1_FAST_PWM_10_Max 0x03FF
#define TIMER1_PWM_8_Max       0x00FF
#define TIMER1_PWM_9_Max       0x01FF 
#define TIMER1_PWM_10_Max      0x03FF

#endif