#include"MOTOR_Interface.h"
void MOTOR_Init(uint8_t GROUP ,uint8_t PIN1,uint8_t PIN2){
    DIO_InitPin(GROUP,PIN1,Output);
    DIO_InitPin(GROUP,PIN2,Output);
    DIO_InitPin(MOTOR_ENABLE_Group,MOTOR_ENABLE,Output);
    Timer0_Config_t pwm={
     .TimerMode=Timer0_FastPWM,
     .PWMOutputMode=Timer0_OC0NinInverting,
    };
    TIMER0_Init(pwm);
    TIMER0_Start(Timer0_Prescaller64);
}
void MOTOR_Mode(uint8_t motor_mode){
    if(motor_mode==MOTOR_Forward){
     DIO_WritePin(MOTOR_Group,MOTOR_Pin1,High);
     DIO_WritePin(MOTOR_Group,MOTOR_Pin2,Low);
    }
    if(motor_mode==MOTOR_Backward){
     DIO_WritePin(MOTOR_Group,MOTOR_Pin1,Low);
     DIO_WritePin(MOTOR_Group,MOTOR_Pin2,High);
    }
    if(motor_mode==MOTOR_Stop){
     DIO_WritePin(MOTOR_Group,MOTOR_Pin1,Low);
     DIO_WritePin(MOTOR_Group,MOTOR_Pin2,Low);
    }
    if(motor_mode==MOTOR_Toggle){
     DIO_TogglePin(MOTOR_Group,MOTOR_Pin1);
     DIO_TogglePin(MOTOR_Group,MOTOR_Pin2);
    }
}
void MOTOR_Speed(uint8_t motor_speed){
    TIMER0_SetPWMDutyCycle(motor_speed);
}
