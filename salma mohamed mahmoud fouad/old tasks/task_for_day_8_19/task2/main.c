#include"HAL/LED/LED_Interface.h"
#include"MCAL/TIMER0/TIMER0_Interface.h"
#include <util/delay.h>

void main(){
  Led_Init(Dio_GroupB,Dio_Pin3);
  Timer0_Config_t pwm ={
    .TimerMode=Timer0_FastPWM,
    .PWMOutputMode=Timer0_OC0NinInverting,
  };
  TIMER0_Init(pwm);
  TIMER0_Start(Timer0_Prescaller64);
  while(1){
    TIMER0_SetPWMDutyCycle(10);
    _delay_ms(1000);
    TIMER0_SetPWMDutyCycle(20);
    _delay_ms(1000);
    TIMER0_SetPWMDutyCycle(35);
    _delay_ms(1000);
    TIMER0_SetPWMDutyCycle(50);
    _delay_ms(1000);
    TIMER0_SetPWMDutyCycle(70);
    _delay_ms(1000);
    TIMER0_SetPWMDutyCycle(88);
    _delay_ms(1000);
    TIMER0_SetPWMDutyCycle(0);
    _delay_ms(1000);
  }
}

//2- Create a project to control an LED brightness using PWM on a DIO pin.
