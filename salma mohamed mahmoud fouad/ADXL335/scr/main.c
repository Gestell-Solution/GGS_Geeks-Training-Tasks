#include"HAL/ADXL335/ADXL335_Interface.h"
void main(){
    ADXL335_Init();
    while(1){
    ADXL335_PrintData();
    }
}