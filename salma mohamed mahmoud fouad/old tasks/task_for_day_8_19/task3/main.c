#include <util/delay.h>
#include"HAL/BUZZER/BUZZER_Interface.h"
void main(){
  Buzzer_Init(Dio_GroupB,Dio_Pin3);
  while(1){
    Buzzer_toggle(Dio_GroupB,Dio_Pin3);
    _delay_ms(1000);
  }
}
//Configure a DIO pin to control a buzzer with a 1-second pulse.
