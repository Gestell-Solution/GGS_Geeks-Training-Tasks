#include"HAL/ADXL335/ADXL335_Interface.h"
#include"HAL/LCD/LCD_Interface.h"
void main(){
    ADXL355_Init();
    while(1){
    ADXL355_PrintData();
    }
}