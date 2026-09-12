#ifndef TIMER1_PRIVATE_H_
#define TIMER1_PRIVATE_H_

#include"TIMER1_Interface.h"

//TCCR1A_REG
#define TIMER1_COM1A1 7
#define TIMER1_COM1A0 6
#define TIMER1_COM1B1 5
#define TIMER1_COM1B0 4
#define TIMER1_COM1C1 3
#define TIMER1_COM1C0 2
#define TIMER1_WGM11  1
#define TIMER1_WGM10  0
//TCCR3A_REG
#define TIMER1_COM3A1 7
#define TIMER1_COM3A0 6
#define TIMER1_COM3B1 5
#define TIMER1_COM3B0 4
#define TIMER1_COM3C1 3
#define TIMER1_COM3C0 2
#define TIMER1_WGM31  1
#define TIMER1_WGM30  0
 //NON-PWM ,FAST PWM ,phase correct PWM 
 #define TIMER1_Normal 0
 #define TIMER1_toggle 1
 #define TIMER1_clear  2
 #define TIMER1_set    3
//WAVE FORM GENERATOIN
 #define WGM13_is0                  1
 #define TIMER1_NORMAL_MODE         0
 #define TIMER1_PWM8_MODE           1
 #define TIMER1_PWM9_MODE           2
 #define TIMER1_PWM10_MODE          3
 #define TIMER1_CTC_OCRA_MODE       4 
 #define TIMER1_FAST_PWM8_MODE      5
 #define TIMER1_FAST_PWM9_MODE      6
 #define TIMER1_FAST_PWM10_MODE     7
 //WGM3IS 1 FROM HERE TO DOWN
 #define WGM13_is1                  2
 #define TIMER1_PWM_PHASE_ICR_MODE  8
 #define TIMER1_PWM_PHASE_OCRA_MODE 9 
 #define TIMER1_PWM_ICR_MODE        10
 #define TIMER1_PWM_OCRA_MODE       11
 #define TIMER1_CTC_ICR_MODE        12
 #define TIMER1_FAST_PWM_ICR_MODE   14 
 #define TIMER1_FAST_PWM_OCRA_MODE  15 
//TCCR1B_REG
#define TIMER1_ICNC1 7
#define TIMER1_ICES1 6
#define TIMER1_WGM13 4
#define TIMER1_WGM12 3
#define TIMER1_CS12  2
#define TIMER1_CS11  1
#define TIMER1_CS10  0
//TCCR3B_REG
#define TIMER1_ICNC3 7
#define TIMER1_ICES3 6
#define TIMER1_WGM33 4
#define TIMER1_WGM32 3
#define TIMER1_CS32  2
#define TIMER1_CS31  1
#define TIMER1_CS30  0
 //CLOCK SELECT
 #define TIMER1_NO_CLOCK_CLOCK              0
 #define TIMER1_1_CLOCK                     1
 #define TIMER1_8_CLOCK                     2
 #define TIMER1_64_CLOCK                    3
 #define TIMER1_256_CLOCK                   4
 #define TIMER1_1024_CLOCK                  5
 #define TIMER1_EXTERNAL_FALLING_EDGE_CLOCK 6
 #define TIMER1_EXTERNAL_RISING_EDGE_CLOCK  7 
 #define TIMER1_prescaler_mask              0x07
 //TCCR1C_REG
#define TIMER1_FOC1A 7
#define TIMER1_FOC1B 6
#define TIMER1_FOC1C 5
//TCCR3C
#define TIMER1_FOC3A 7
#define TIMER1_FOC3B 6
#define TIMER1_FOC3C 5
//TIMSK_REG
#define TIMER1_TICIE1 5
#define TIMER1_OCIE1A 4
#define TIMER1_OCIE1B 3
#define TIMER1_TOIE1  2
//ETIMSK_REG
#define TIMER1_TICIE3 5
#define TIMER1_OCIE3A 4
#define TIMER1_OCIE3B 3
#define TIMER1_TOIE3  2
#define TIMER1_OCIE3C 1
#define TIMER1_OCIE1C 0
//TIFR_REG
#define TIMER1_ICF1  5
#define TIMER1_OCF1A 4
#define TIMER1_OCF1B 3
#define TIMER1_TOV1  2
//ETIFR_REG
#define TIMER1_ISF3  5
#define TIMER1_OCF3A 4
#define TIMER1_OCF3B 3
#define TIMER1_TOV3  2
#define TIMER1_OCF3C 1
#define TIMER1_OCF1C 0 

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

#define falling_edge 0
#define rising_edge  1

#define noise_enable 1
#define noise_disable 0

#define TIMER1_OverFlow     0
#define TIMER1_CTCA         1
#define TIMER1_CTCB         2
#define TIMER1_CaptureEvent 3
#define TIMER1_CTCC         4


#endif