#ifndef ULTRS_PRIVATE_H_
#define ULTRS_PRIVATE_H_

/* HC-SR04 Timing Constants */
#define ULTS_SOUND_SPEED_CM_PER_US    0.0343  /* Speed of sound in cm/us */
#define ULTS_MAX_DISTANCE_CM          400     /* Max measurable distance */
#define ULTS_TIMEOUT_US               25000   /* Timeout for no echo (25ms) */

/* States for Echo pin detection */
#define ULTS_WAIT_FOR_RISING_EDGE     0
#define ULTS_WAIT_FOR_FALLING_EDGE    1

/* Timer1 Prescaler for 1MHz tick (assuming 8MHz CPU, Prescaler=8) */
#define ULTS_TIMER_PRESCALER          TIMER1_8_CLOCK

#endif