#include "ULTS_Interface.h"

/* Global variables */
static volatile uint32_t timerOverflowCount = 0;
static volatile uint16_t risingEdgeCapture = 0;
static volatile uint16_t fallingEdgeCapture = 0;
static volatile uint8_t isMeasuring = 0;
static volatile uint8_t state = ULTS_WAIT_FOR_RISING_EDGE;

void ULTS_Init(void)
{
    /* Initialize Timer1 in Normal Mode */
    Timer1_config_t timer = {
        .Timer_mode      = TIMER1_NORMAL_MODE,
        .Mode_type       = WGM13_is0,
        .noiseEnable     = noise_enable,
        .Edge            = rising_edge,
        .preloadvalue    = 0,
        .interruptEnable = 1
    };
    
    TIMER1_Init(timer);
    TIMER1_set_preloadValue(0);
    
    /* Set callbacks */
    TIMER1_SETcallBackFunction(TIMER1_CaptureEvent, ULTS_CaptureISR);
    TIMER1_SETcallBackFunction(TIMER1_OverFlow, ULTS_OverflowISR);
    
    /* Configure Pins */
    DIO_InitPin(ULTS_GROUP, ULTS_TRIGGER_PIN, Output);
    DIO_InitPin(ULTS_GROUP, ULTS_ECHO_PIN, Input);
    
    /* Start Timer */
    TIMER1_Start(ULTS_TIMER_PRESCALER);
}

void ULTS_OverflowISR(void)
{
    timerOverflowCount++;
}

void ULTS_CaptureISR(void)
{
    uint16_t currentCapture = 0;
    
    /* Read 16-bit ICR1 value */
    currentCapture = ICR1L_Reg;
    currentCapture |= (uint16_t)ICR1H_Reg << 8;
    
    if(state == ULTS_WAIT_FOR_RISING_EDGE)
    {
        risingEdgeCapture = currentCapture;
        timerOverflowCount = 0;
        state = ULTS_WAIT_FOR_FALLING_EDGE;
        
        /* Switch to falling edge */
        ClearBit(TCCR1B_Reg, TIMER1_ICES1);
    }
    else
    {
        fallingEdgeCapture = currentCapture;
        isMeasuring = 0;
        state = ULTS_WAIT_FOR_RISING_EDGE;
        
        /* Switch back to rising edge */
        SetBit(TCCR1B_Reg, TIMER1_ICES1);
        
        /* Disable capture interrupt until next measurement */
        ClearBit(TIMSK_Reg, TIMER1_TICIE1);
    }
}

uint16_t ULTS_GetDistance(void)
{
    uint32_t totalTicks = 0;
    uint16_t distance_cm = 0;
    uint32_t timeout = 0;

    /* Reset variables */
    state = 0;
    risingEdgeCapture = 0;
    fallingEdgeCapture = 0;
    timerOverflowCount = 0;
    isMeasuring = 1;

    /* Enable capture interrupt */
    SetBit(TIMSK_Reg, TIMER1_TICIE1);

    /* Send 10us trigger pulse */
    DIO_WritePin(ULTS_GROUP, ULTS_TRIGGER_PIN, High);
    _delay_us(10);
    DIO_WritePin(ULTS_GROUP, ULTS_TRIGGER_PIN, Low);

    /* Wait for measurement with timeout (25ms max) */
    while(isMeasuring && timeout < 25000)
    {
        timeout++;
        _delay_us(1);
    }

    /* Disable capture interrupt */
    ClearBit(TIMSK_Reg, TIMER1_TICIE1);

    /* Calculate elapsed ticks */
    if(fallingEdgeCapture >= risingEdgeCapture)
    {
        totalTicks = fallingEdgeCapture - risingEdgeCapture;
    }
    else
    {
        totalTicks = (65536UL - risingEdgeCapture) + fallingEdgeCapture;
    }

    /* Add overflow ticks */
    totalTicks += (timerOverflowCount * 65536UL);

    /* === THE EXACT FORMULA === */
    /* CPU=8MHz, Prescaler=8, 1 tick = 1us */
    distance_cm = (uint16_t)(((uint32_t)totalTicks * 343) / 2450);

    /* Safety: If timeout occurred, return 0 */
    if(timeout >= 25000)
    {
        distance_cm = 0;
    }

    return distance_cm;
}