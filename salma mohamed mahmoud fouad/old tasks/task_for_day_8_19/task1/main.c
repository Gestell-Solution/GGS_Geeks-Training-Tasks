#include <util/delay.h>
#include"MCAL/DIO/DIO_Interface.h"
void main(){
    DIO_InitPin(Dio_GroupB,Dio_Pin0,Output);
    while (1)
    {
      DIO_TogglePin(Dio_GroupB,Dio_Pin0);
      _delay_ms(500);
    }
    
}

//Configure a DIO pin as an output and toggle it every 500 ms