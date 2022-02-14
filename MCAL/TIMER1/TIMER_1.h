/*
 * TIMER_1.h
 *
 * Created: 17/01/2022 01:28:00 ?
 *  Author: dell
 */
#include "STD_TYPES.h"

#ifndef TIMER_1_H_
#define TIMER_1_H_


void TIMER_1_INIT(void);
void TIMER_1_SET_TIME(u32);
void TIMER_1_START(void);
void TIMER_1_STOP(void);
u32 TIMER_1_CALC_TIME(void);
void PWM_1_INIT(void);
void PWM_1_SET_DUTY_CYCLE(u8);
void PWM_1_START(void);
void PWM_1_STOP(void);




#endif /* TIMER_1_H_ */