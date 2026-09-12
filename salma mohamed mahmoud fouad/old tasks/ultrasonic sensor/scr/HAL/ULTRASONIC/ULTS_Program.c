#include"ULTS_Interface.h"

static volatile uint32_t timerOverflow =0;
static volatile uint16_t capturedRisingEdge=0;
static volatile uint16_t capturedFallingEdge=0;
static volatile uint8_t measuring=0;
static volatile uint8_t state=0; 


// volatile riseflag=0;
void ULTS_Init(){
    Timer1_config_t timer={
        .Timer_mode=TIMER1_normal,
        .Mode_type=WGM13_is0,
        .noiseEnable=Enable,
        .Edge=rising_edge,
        .preloadvalue=Off,
        .interruptEnable=On,
    };
    TIMER1_Init(timer);
    TIMER1_set_preloadValue(0);
    TIMER1_Start(TIMER1_Precaling_8);
    TIMER1_SETcallBackFunction(TIMER1_CaptureEvent,ULTS_ISR);
    TIMER1_SETcallBackFunction(TIMER1_CaptureEvent,timer1_captureFlag);
    DIO_InitPin(ULTS_GROUP,ULTS_TRIGGER_PIN,Output);
    DIO_InitPin(ULTS_GROUP,ULTS_ECHO_PIN,Input);
    GIE_Enable();
}
void ULTS_ISR(){
    timerOverflow++;
}
uint16_t ULTS_Start(){
    uint16_t distance=0;
    uint32_t totalTicktime=0,
    timout=0; 

    timerOverflow =0;
    capturedRisingEdge=0;
    capturedFallingEdge=0;
    measuring=1;
    state=0; 
    SetBit(TIMSK_Reg,TIMER1_TICIE1);
    DIO_WritePin(ULTS_GROUP,ULTS_TRIGGER_PIN,High);
    _delay_ms(10);
    DIO_WritePin(ULTS_GROUP,ULTS_TRIGGER_PIN,Low);
    while(measuring && timout < 25000){
        timout++;
        _delay_us(1);
    }
    ClearBit(TIMSK_Reg,TIMER1_TICIE1);
    if(capturedFallingEdge>=capturedRisingEdge){
        totalTicktime=capturedFallingEdge-capturedRisingEdge;
    }
    else{
      totalTicktime = capturedFallingEdge + (65536UL - capturedRisingEdge);	
    }
    /* Reject readings that are too far from expected */
    if(totalTicktime < 36 || totalTicktime > 725)  /* Valid range: 5cm to 100cm */
    {
        return 0;  /* Invalid reading */
    }
    totalTicktime=totalTicktime+(timerOverflow*65536UL);
    // LCD_GotoXY(0, 0);
    // LCD_WriteString("T:", Lcd_8bitMode);
    // LCD_Number((uint32_t)totalTicktime, Lcd_8bitMode); // for 20 145 for21 152 for19 138
    // _delay_ms(1000);
	distance = (uint16_t)(((uint32_t)totalTicktime* 4) / 29);
    if(timout>=25000){
        distance=0;
    }
    return distance;
}


void timer1_captureFlag(){
    uint16_t captured=0;
    captured=ICR1L_Reg;
    captured |=(uint16_t)ICR1H_Reg<<8;
    if(state==0){
        capturedRisingEdge=captured;
        timerOverflow=0;
        state=1;
        ClearBit(TCCR1B_Reg,TIMER1_ICES1);
    }
    else{
        capturedFallingEdge=captured;
        measuring=0;
       SetBit(TCCR1B_Reg,TIMER1_ICES1);
       ClearBit(TIMSK_Reg,TIMER1_TICIE1);
    }
}
