#include <util/delay.h>
#include"MCAL/TIMER0/TIMER0_Interface.h"
#include"MCAL/DIO/DIO_Interface.h"
void timer();
void main(){
  DIO_InitPin(Dio_GroupB,Dio_Pin0,Output);
  Timer0_Config_t ctc_time={
    .TimerMode=Timer0_CTCMode,
    .CompareMatchValue=255,
  };
  TIMER0_Init(ctc_time);
  TIMER0_Start(Timer0_Prescaller8);
  TIMER0_SetCallBackFunction(Timer0_CompareMatchInterrupt,timer);
  while(1){
  DIO_TogglePin(Dio_GroupB,Dio_Pin0); 
  }
}
void timer(){
  static uint16_t timerCounter=0;
  timerCounter++;
  if(timerCounter>=3922){
    timerCounter=0;
  }
}
// 6- Implement a project to use a timer to create a 1-second delay.