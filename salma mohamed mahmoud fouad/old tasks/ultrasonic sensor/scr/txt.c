// #include "Ultrasonic_Interface.h"
// #include "TIMER1_Interface.h"  /* Your Timer1 driver */
// #include <avr/io.h>
// #include <util/delay.h>
// #include <stdlib.h>

// /*============== Static Variables ==============*/
// static uint8_t Ultrasonic_TriggerPin = ULTRASONIC_TRIGGER_PIN;
// static uint8_t Ultrasonic_EchoPin = ULTRASONIC_ECHO_PIN;
// static uint16_t Ultrasonic_TimeoutMs = ULTRASONIC_TIMEOUT_MS;
// static uint16_t Ultrasonic_MaxDistanceCm = ULTRASONIC_MAX_DISTANCE_CM;
// static uint8_t Ultrasonic_Prescaler = TIMER1_Precaling_noPrecaling;

// static volatile uint32_t Ultrasonic_RawCount = 0;
// static volatile uint16_t Ultrasonic_LastDistance = 0;
// static volatile uint8_t Ultrasonic_MeasurementComplete = 0;
// static volatile uint8_t Ultrasonic_MeasurementStarted = 0;
// static volatile uint16_t Ultrasonic_OverflowCount = 0;

// static void (*Ultrasonic_Callback)(uint16_t) = NULL;

// /*============== Private Function Prototypes ==============*/
// static void Ultrasonic_StartCapture(void);
// static uint32_t Ultrasonic_ReadCapture(void);
// static uint16_t Ultrasonic_ConvertToCm(uint32_t rawCount);

// /*============== Timer1 Callback Functions ==============*/
// static void Ultrasonic_TimerOverflowCallback(void)
// {
//     Ultrasonic_OverflowCount++;
    
//     /* Timeout protection */
//     if (Ultrasonic_OverflowCount > 500) {
//         Ultrasonic_MeasurementComplete = 1;
//         Ultrasonic_RawCount = 0;
//         Ultrasonic_LastDistance = 0;
//     }
// }

// static void Ultrasonic_CaptureEventCallback(void)
// {
//     static uint8_t state = 0;  /* 0 = waiting for rising edge, 1 = waiting for falling edge */
//     static uint32_t startCount = 0;
    
//     if (state == 0) {
//         /* Rising edge detected - start timing */
//         startCount = TIMER1_GetTimerValue();
//         Ultrasonic_OverflowCount = 0;
        
//         /* Setup for falling edge capture */
//         TIMER1_SetCaptureValue(0);  /* Not used, but required */
//         Timer1_config_t config = {
//             .Timer_mode = TIMER1_NORMAL_MODE,
//             .Mode_type = WGM13_is0,
//             .prescaler_value = Ultrasonic_Prescaler,
//             .Edge = falling_edge,  /* Capture on falling edge */
//             .noiseEnable = noise_enable,
//             .PwmOutputmode = TIMER1_NonInverting
//         };
//         TIMER1_Init(config);
//         TIMER1_SetPreloadValue(0);
//         TIMER1_Start(Ultrasonic_Prescaler);
        
//         state = 1;
//     } else {
//         /* Falling edge detected - stop timing */
//         uint32_t endCount = TIMER1_GetTimerValue();
//         uint32_t overflowCount = Ultrasonic_OverflowCount;
        
//         /* Calculate total count (handle overflow) */
//         Ultrasonic_RawCount = endCount + (65535UL * overflowCount);
        
//         /* Convert to distance */
//         Ultrasonic_LastDistance = Ultrasonic_ConvertToCm(Ultrasonic_RawCount);
//         Ultrasonic_MeasurementComplete = 1;
//         Ultrasonic_MeasurementStarted = 0;
        
//         /* Stop timer */
//         TIMER1_Stop();
        
//         /* Call user callback if set */
//         if (Ultrasonic_Callback != NULL) {
//             Ultrasonic_Callback(Ultrasonic_LastDistance);
//         }
        
//         state = 0;
//     }
// }

// /*============== Public Functions ==============*/

// void Ultrasonic_Init(Ultrasonic_Config_t config)
// {
//     /* Save configuration */
//     Ultrasonic_TriggerPin = config.triggerPin;
//     Ultrasonic_EchoPin = config.echoPin;
//     Ultrasonic_TimeoutMs = config.timeoutMs;
//     Ultrasonic_MaxDistanceCm = config.maxDistanceCm;
//     Ultrasonic_Prescaler = config.prescaler;
    
//     /* Initialize Timer1 for capture mode */
//     Timer1_config_t timerConfig = {
//         .Timer_mode = TIMER1_NORMAL_MODE,
//         .Mode_type = WGM13_is0,
//         .prescaler_value = Ultrasonic_Prescaler,
//         .Edge = rising_edge,
//         .noiseEnable = noise_enable,
//         .PwmOutputmode = TIMER1_NonInverting,
//         .preloadvalue = 0,
//         .comparevalue = 0,
//         .capturevalue = 0
//     };
//     TIMER1_Init(timerConfig);
    
//     /* Set callbacks for Timer1 interrupts */
//     TIMER1_SetCallback(TIMER1_OverFlow, Ultrasonic_TimerOverflowCallback);
//     TIMER1_SetCallback(TIMER1_CaptureEvent, Ultrasonic_CaptureEventCallback);
    
//     /* Configure trigger pin as output */
//     DDR_A |= (1 << Ultrasonic_TriggerPin);
    
//     /* Configure echo pin as input (ICP1 is automatically input) */
//     DDR_D &= ~(1 << Ultrasonic_EchoPin);
    
//     /* Enable global interrupts */
//     sei();
// }

// void Ultrasonic_TriggerMeasurement(void)
// {
//     /* Reset measurement flags */
//     Ultrasonic_MeasurementComplete = 0;
//     Ultrasonic_MeasurementStarted = 1;
//     Ultrasonic_OverflowCount = 0;
//     Ultrasonic_RawCount = 0;
    
//     /* Generate 10us trigger pulse */
//     PORTA |= (1 << Ultrasonic_TriggerPin);
//     _delay_us(10);
//     PORTA &= ~(1 << Ultrasonic_TriggerPin);
    
//     /* Setup Timer1 for rising edge capture */
//     Timer1_config_t config = {
//         .Timer_mode = TIMER1_NORMAL_MODE,
//         .Mode_type = WGM13_is0,
//         .prescaler_value = Ultrasonic_Prescaler,
//         .Edge = rising_edge,
//         .noiseEnable = noise_enable,
//         .PwmOutputmode = TIMER1_NonInverting,
//         .preloadvalue = 0,
//         .comparevalue = 0,
//         .capturevalue = 0
//     };
//     TIMER1_Init(config);
    
//     /* Start timer with prescaler */
//     TIMER1_SetPreloadValue(0);
//     TIMER1_Start(Ultrasonic_Prescaler);
// }

// uint8_t Ultrasonic_IsMeasurementComplete(Ultrasonic_Result_t* result)
// {
//     if (Ultrasonic_MeasurementComplete) {
//         if (result != NULL) {
//             result->distanceCm = Ultrasonic_LastDistance;
//             result->distanceMm = Ultrasonic_LastDistance * 10;
//             result->rawCount = Ultrasonic_RawCount;
            
//             if (Ultrasonic_LastDistance > Ultrasonic_MaxDistanceCm) {
//                 result->error = ULTRASONIC_OUT_OF_RANGE;
//             } else if (Ultrasonic_RawCount == 0) {
//                 result->error = ULTRASONIC_TIMEOUT;
//             } else {
//                 result->error = ULTRASONIC_OK;
//             }
//         }
//         return 1;
//     }
//     return 0;
// }

// uint16_t Ultrasonic_GetDistanceCm(void)
// {
//     Ultrasonic_Result_t result;
    
//     /* Start measurement */
//     Ultrasonic_TriggerMeasurement();
    
//     /* Wait for completion or timeout */
//     uint16_t timeout = Ultrasonic_TimeoutMs * 10;  /* Approximate loop count */
//     while (!Ultrasonic_IsMeasurementComplete(&result) && timeout > 0) {
//         _delay_ms(1);
//         timeout--;
//     }
    
//     if (timeout == 0 || result.error != ULTRASONIC_OK) {
//         return 0;
//     }
    
//     return result.distanceCm;
// }

// Ultrasonic_Error_t Ultrasonic_GetDistanceEx(Ultrasonic_Result_t* result)
// {
//     if (result == NULL) {
//         return ULTRASONIC_ERROR;
//     }
    
//     /* Start measurement */
//     Ultrasonic_TriggerMeasurement();
    
//     /* Wait for completion or timeout */
//     uint16_t timeout = Ultrasonic_TimeoutMs;
//     while (!Ultrasonic_IsMeasurementComplete(result) && timeout > 0) {
//         _delay_ms(1);
//         timeout--;
//     }
    
//     if (timeout == 0) {
//         result->error = ULTRASONIC_TIMEOUT;
//         return ULTRASONIC_TIMEOUT;
//     }
    
//     return result->error;
// }

// uint32_t Ultrasonic_GetRawCount(void)
// {
//     return Ultrasonic_RawCount;
// }

// uint16_t Ultrasonic_CalculateDistance(uint32_t rawCount)
// {
//     /* Distance = (time * speed) / 2
//      * time = rawCount / (F_CPU / prescaler)
//      * speed = 343 m/s = 0.0343 cm/us
//      * 
//      * For 8MHz, prescaler=1:
//      * time_us = rawCount / 8
//      * distance_cm = (time_us * 0.0343) / 2
//      * distance_cm = rawCount * 0.0343 / 16
//      * distance_cm = rawCount / 466.47
//      */
//     return (uint16_t)((rawCount * 343UL) / (2 * 8000UL));  /* Simplified for 8MHz, no prescaler */
// }

// static uint16_t Ultrasonic_ConvertToCm(uint32_t rawCount)
// {
//     /* For 8MHz clock, no prescaler:
//      * 1 count = 0.125 us
//      * Round trip time = rawCount * 0.125 us
//      * Distance = (time * 34300 cm/s) / 2
//      * Distance = rawCount * 0.125e-6 * 34300 / 2
//      * Distance = rawCount / 466.47
//      */
//     return (uint16_t)((rawCount * 343UL) / (2 * 8000UL));
// }

// void Ultrasonic_SetCallback(void (*callback)(uint16_t distanceCm))
// {
//     Ultrasonic_Callback = callback;
// }





// *
//  * Ultrasonic sensor HC-05 interfacing with AVR ATmega16
//  * http://www.electronicwings.com
//  */ 

// #define F_CPU 8000000UL
// #include <avr/io.h>
// #include <avr/interrupt.h>
// #include <util/delay.h>
// #include <string.h>
// #include <stdlib.h>
// #include "LCD_16x2_H_file.h"	/* Include LCD header file */

// #define  Trigger_pin	PA0	/* Trigger pin */

// int TimerOverflow = 0;

// ISR(TIMER1_OVF_vect)
// {
// 	TimerOverflow++;	/* Increment Timer Overflow count */
// }

// int main(void)
// {
// 	char string[10];
// 	long count;
// 	double distance;
	
// 	DDRA = 0x01;		/* Make trigger pin as output */
// 	PORTD = 0xFF;		/* Turn on Pull-up */
	
// 	LCD_Init();
// 	LCD_String_xy(1, 0, "Ultrasonic");
	
// 	sei();			/* Enable global interrupt */
// 	TIMSK = (1 << TOIE1);	/* Enable Timer1 overflow interrupts */
// 	TCCR1A = 0;		/* Set all bit to zero Normal operation */

// 	while(1)
// 	{
// 		/* Give 10us trigger pulse on trig. pin to HC-SR04 */
// 		PORTA |= (1 << Trigger_pin);
// 		_delay_us(10);
// 		PORTA &= (~(1 << Trigger_pin));
		
// 		TCNT1 = 0;	/* Clear Timer counter */
// 		TCCR1B = 0x41;	/* Capture on rising edge, No prescaler*/
// 		TIFR = 1<<ICF1;	/* Clear ICP flag (Input Capture flag) */
// 		TIFR = 1<<TOV1;	/* Clear Timer Overflow flag */

// 		/*Calculate width of Echo by Input Capture (ICP) */
		
// 		while ((TIFR & (1 << ICF1)) == 0);/* Wait for rising edge */
// 		TCNT1 = 0;	/* Clear Timer counter */
// 		TCCR1B = 0x01;	/* Capture on falling edge, No prescaler */
// 		TIFR = 1<<ICF1;	/* Clear ICP flag (Input Capture flag) */
// 		TIFR = 1<<TOV1;	/* Clear Timer Overflow flag */
// 		TimerOverflow = 0;/* Clear Timer overflow count */

// 		while ((TIFR & (1 << ICF1)) == 0);/* Wait for falling edge */
// 		count = ICR1 + (65535 * TimerOverflow);	/* Take count */
// 		/* 8MHz Timer freq, sound speed =343 m/s */
// 		distance = (double)count / 466.47;

// 		dtostrf(distance, 2, 2, string);/* distance to string */
// 		strcat(string, " cm   ");	/* Concat unit i.e.cm */
// 		LCD_String_xy(2, 0, "Dist = ");
// 		LCD_String_xy(2, 7, string);	/* Print distance */
// 		_delay_ms(200);
// 	}
// }