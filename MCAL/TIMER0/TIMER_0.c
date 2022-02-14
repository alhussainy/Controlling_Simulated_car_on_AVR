/*
 * TIMER_0.c
 *
 * Created: 12/01/2022 11:35:04 ص
 *  Author: Alhussainy Khaled Anwar
 */ 
#include "TIMER_0_CFG.h"
#include "TIMER_0.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "REG.h"

u32 num_of_ov;
u32 rem_ticks;
u32 num_of_cm;
void TIMER_0_INIT(void)
{
	#if   TIMER_0_MODE    ==   NORMAL_MODE
	CLR_BIT(TCCR0,3);
	CLR_BIT(TCCR0,6);
	/*to enable timer0 overflow interrupt*/
	SET_BIT(TIMSK,0);
	#elif TIMER_0_MODE    ==   CTC_MODE
	SET_BIT(TCCR0,3);
	CLR_BIT(TCCR0,6);
	/*to enable timer0 compare match interrupt*/
	SET_BIT(TIMSK,1);
	#endif
	/*to enable global interrupt*/
	SET_BIT(SREG,7);
}
void TIMER_0_SET_TIME(u32 desired_time)
{
	#if   TIMER_0_MODE    ==   NORMAL_MODE
	#if   PRESCALER    ==   _1024
    u32 tick_time   = 1024 / CRYSTAL_FREQ;   // result will be in micro second
	#elif PRESCALER   ==   _256
    u32 tick_time   = 256  / CRYSTAL_FREQ;
	#endif                        
	u32 total_ticks = (desired_time * 1000) / tick_time;
	    num_of_ov   = total_ticks / 256;
		rem_ticks   = total_ticks % 256;
		if(rem_ticks != 0)
		{
			TCNT0       = 256 - rem_ticks;
			num_of_ov++;
		}
	#elif   TIMER_0_MODE    ==   CTC_MODE
	#if   PRESCALER    ==   _1024
	u32 tick_time   = 1024 / CRYSTAL_FREQ;   // result will be in micro second
	#elif PRESCALER   ==   _256
	u32 tick_time   = 256  / CRYSTAL_FREQ;
	#endif
	u32 total_ticks = (desired_time * 1000) / tick_time;
	u8 division_factor = 255;
	for(;division_factor > 0;division_factor--)
	{
		if((total_ticks % division_factor) == 0)
		{
			break;
		}
	}
	OCR0 = division_factor - 1;
	num_of_cm = total_ticks / division_factor;
	#endif
}
void TIMER_0_START(void)
{
	#if PRESCALER    ==   _1024
	SET_BIT(TCCR0,0);
	CLR_BIT(TCCR0,1);
	SET_BIT(TCCR0,2);
	#elif PRESCALER   ==   _256
	CLR_BIT(TCCR0,0);
	CLR_BIT(TCCR0,1);
	SET_BIT(TCCR0,2);
	#endif	
}
void TIMER_0_STOP(void)
{
	CLR_BIT(TCCR0,0);
	CLR_BIT(TCCR0,1);
	CLR_BIT(TCCR0,2);
}
void PWM_0_INIT(void)
{
	#if   PWM_0_MODE      ==   FAST
	/*to select fast pwm mode*/
	SET_BIT(TCCR0,3);
	SET_BIT(TCCR0,6);
	/*to enable output circuit*/
	SET_BIT(DDRB,3);
	#if   FAST_PWM_0_MODE     ==   NON_INVERTED
	CLR_BIT(TCCR0,4);
	SET_BIT(TCCR0,5);
	#elif FAST_PWM_0_MODE     ==   INVERTED
	SET_BIT(TCCR0,4);
	SET_BIT(TCCR0,5);
	#endif
	
	#elif  PWM_0_MODE     ==   PHASE_CORRECT
	/*to select phase_correct_pwm mode*/
	CLR_BIT(TCCR0,3);
	SET_BIT(TCCR0,6);
	/*to enable output circuit*/
	SET_BIT(DDRB,3);
	#if   PHASE_CORRECT_PWM_0_MODE     ==   NON_INVERTED
	CLR_BIT(TCCR0,4);
	SET_BIT(TCCR0,5);
	#elif PHASE_CORRECT_PWM_0_MODE     ==   INVERTED
	SET_BIT(TCCR0,4);
	SET_BIT(TCCR0,5);
	#endif
	#endif
}
void PWM_0_SET_DUTY_CYCLE(u8 duty_cycle)
{
	#if   PWM_0_MODE      ==   FAST
	#if   FAST_PWM_0_MODE     ==   NON_INVERTED
	OCR0 = ((((u32)duty_cycle * 256) / 100) - 1);
	#elif FAST_PWM_0_MODE     ==   INVERTED
	OCR0 = 255;
	#endif
	#elif PWM_0_MODE      ==   PHASE_CORRECT
	#if   PHASE_CORRECT_PWM_0_MODE     ==   NON_INVERTED
	OCR0 = (((u32)duty_cycle * 255) / 100);
	#elif PHASE_CORRECT_PWM_0_MODE     ==   INVERTED
	OCR0 = 255;
	#endif
	#endif
}
void PWM_0_START(void)
{
	TIMER_0_START();
}
void PWM_0_STOP(void)
{
	TIMER_0_STOP();	
}