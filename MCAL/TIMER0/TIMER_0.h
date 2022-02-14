/*
 * TIMER_0.h
 *
 * Created: 12/01/2022 11:35:14 ص
 *  Author: Alhussainy Khaled Anwar
 */ 


#ifndef TIMER_0_H_
#define TIMER_0_H_

#include "STD_TYPES.h"

void TIMER_0_INIT(void);
void TIMER_0_SET_TIME(u32);
void TIMER_0_START(void);
void TIMER_0_STOP(void);

void PWM_0_INIT(void);
void PWM_0_SET_DUTY_CYCLE(u8);
void PWM_0_START(void);
void PWM_0_STOP(void);

#define _1024        1
#define _256         2

#define NORMAL_MODE    1
#define CTC_MODE       2

#define FAST           1
#define PHASE_CORRECT  2

#define NON_INVERTED   1
#define INVERTED       2

#endif /* TIMER_0_H_ */