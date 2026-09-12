#include <util/delay.h>
#include"HAL/motor/MOTOR_Interface.h"
void main(){
  MOTOR_Init(Dio_GroupD,Dio_Pin4,Dio_Pin5);
  while(1){
    MOTOR_Mode(MOTOR_Stop);
    _delay_ms(1500);
    MOTOR_Speed(50);
    MOTOR_Mode(MOTOR_Forward);
    _delay_ms(1500);
    MOTOR_Speed(90);
    MOTOR_Mode(MOTOR_Backward);
    _delay_ms(1500);

  }
}

// 5- Create a project to control a DC motor speed using PWM.
