#include<stdio.h>
#include<stdint.h>
#include"HAL/LED/LED_Interface.h"
#include"HAL/LCD/LCD_Interface.h"
#include <util/delay.h>
#include"MCAL/EXIT/EXIT_Interface.h"
#include"MCAL/GIE/GIE_Interface.h"
#include"MCAL/ADC/ADC_Interface.h"
#include"HAL/LM35/LM35_Interface.h"
#include"HAL/ULTRASONIC/ULTS_Interface.h"

/*
void main(){
    Led_Init(Dio_GroupA,Dio_Pin0,SourceConnection);
    Led_Init(Dio_GroupD,Dio_Pin0,SourceConnection);
    EXTI_Init(EXIT_INTERRUPT7_4,EXIT_ISC_anyLogic);
    EXTI_Enable(EXIT_INTERRUPT_Request0);
    DIO_InitPin(Dio_GroupA,Dio_Pin7,Input);
    GIE_Enable();
    while (1)
    {
     Led_on(Dio_GroupA,Dio_Pin0);
    }
}

void __vector_1(void)  __attribute__((signal));
void __vector_1(void){
    static uint8_t button_state=0;
    DIO_ReadPin(Dio_GroupA,Dio_Pin7,&button_state);
   if(button_state==Off){ 
    Led_on(Dio_GroupD,Dio_Pin0);
    _delay_ms(1000);
    button_state=On;
   }
   else if(button_state==On)
   {
    Led_off(Dio_GroupD,Dio_Pin0);
    button_state=Off;
   }
}
   */

// void main(){  
//     uint8_t adc_data=0; 
//     LCD_Init(LCD_8bitMode);
//     LM35_Init();
//     Led_Init(Dio_GroupB,Dio_Pin0,SourceConnection);
//     Led_Init(Dio_GroupB,Dio_Pin1,SourceConnection);
//     Led_Init(Dio_GroupB,Dio_Pin2,SourceConnection);
//     Led_Init(Dio_GroupB,Dio_Pin3,SourceConnection);
//     Led_Init(Dio_GroupB,Dio_Pin4,SourceConnection);
//     LCD_Go_To_XY(0,1);
//     LCD_WriteString("SENSOR",LCD_8bitMode);
//     _delay_ms(1000);
//     LCD_Instruction(LCD_ClearScreen,LCD_8bitMode);
//     while (1)
//     {
//         adc_data=LM35_Read();
//         LCD_Go_To_XY(0,8);
//         if(adc_data==10){
//         LCD_Number(adc_data,LCD_8bitMode);
//         LCD_Number(0,LCD_8bitMode);
//         Led_on(Dio_GroupB,Dio_Pin4);
//         _delay_ms(500);
//         Led_off(Dio_GroupB,Dio_Pin4);
//         }
//         else if(adc_data==20){
//         LCD_Number(adc_data,LCD_8bitMode);
//         LCD_Number(0,LCD_8bitMode);
//         Led_on(Dio_GroupB,Dio_Pin3);
//         _delay_ms(500);
//         Led_off(Dio_GroupB,Dio_Pin3);
//         }
//         else if(adc_data==30){
//         LCD_Number(adc_data,LCD_8bitMode);
//         LCD_Number(0,LCD_8bitMode);
//         Led_on(Dio_GroupB,Dio_Pin2);
//         _delay_ms(500);
//         Led_off(Dio_GroupB,Dio_Pin2);
//         }
//         else if(adc_data==40){
//         LCD_Number(adc_data,LCD_8bitMode);
//         LCD_Number(0,LCD_8bitMode);
//         Led_on(Dio_GroupB,Dio_Pin1);
//         _delay_ms(500);
//         Led_off(Dio_GroupB,Dio_Pin1);
//         }
//         else if(adc_data==50){
//         LCD_Number(adc_data,LCD_8bitMode);
//         LCD_Number(0,LCD_8bitMode);
//         Led_on(Dio_GroupB,Dio_Pin0);
//         _delay_ms(500);
//         Led_off(Dio_GroupB,Dio_Pin0);
//         }
//         else{
//         LCD_Number(adc_data,LCD_8bitMode);
//         }
//         _delay_ms(500);
//         LCD_Instruction(LCD_ClearScreen,LCD_8bitMode);
//     }
// }

void main(){
uint16_t distance = 0;
    
    /* Initialize LCD */
    LCD_Init(LCD_8bitMode);
    
    /* Initialize Ultrasonic */
    ULTS_Init();
    
    /* Enable Global Interrupts */
    GIE_Enable();
    while(1)
    {
        /* Get distance */
        distance = ULTS_GetDistance();
        
        /* Display on LCD */
        LCD_Go_To_XY(0, 0);
        LCD_WriteString("Distance: ", LCD_8bitMode);
        
        /* Display distance value */
        if(distance < 100)
        {
            LCD_Number(distance, LCD_8bitMode);
        }
        else
        {
            /* Handle > 99 cm */
            LCD_Number((distance / 100), LCD_8bitMode);
            LCD_Number(((distance / 10) % 10), LCD_8bitMode);
            LCD_Number((distance % 10), LCD_8bitMode);
        }
        
        /* Display unit */
        LCD_WriteString(" cm", LCD_8bitMode);
        
        _delay_ms(500);
    }
}