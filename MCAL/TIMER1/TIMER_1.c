/*
 * TIMER_1.c
 *
 * Created: 1/17/2022 1:27:53 PM
 *  Author: Legion
 */
#include "TIMER_1.h"
#include "REG.h"
#include "BIT_MATH.h"
#include "DIO.h"
#include "LED.h"
#include "LED_CFG.h"
#include <avr/io.h>
#define F_CPU    16000000UL
#include <util/delay.h>

#include <avr/interrupt.h>

void PWM_1_INIT(void)
{	//To select fast pwm mode with ICR1 Top
	CLR_BIT(TCCR1A,0);
	SET_BIT(TCCR1A,1);
	SET_BIT(TCCR1B,3);
	SET_BIT(TCCR1B,4);

	//To Select Non-Inverted Mode
	SET_BIT(TCCR1A,7);
	CLR_BIT(TCCR1A,6);

	//To Generate PWM with Freq 50 Hz
	ICR1=1250;
	//To activate output circuit on PD5 pin
	SET_BIT(DDRD,PD5);

}
void PWM_1_SET_DUTY_CYCLE(u8 duty_cycle)
{
	#if   PWM_0_MODE      ==   FAST
	#if   FAST_PWM_0_MODE     ==   NON_INVERTED
	OCR1A = ((((u32)duty_cycle * ICR1) / 100) - 1);
	#elif FAST_PWM_0_MODE     ==   INVERTED

	#endif
	#elif PWM_0_MODE      ==   PHASE_CORRECT
	#if   PHASE_CORRECT_PWM_0_MODE     ==   NON_INVERTED
	OCR0 = (((u32)duty_cycle * 255) / 100);
	#elif PHASE_CORRECT_PWM_0_MODE     ==   INVERTED

	#endif
	#endif
}

void PWM_1_START()
{
	//To select 256 division factor
	CLR_BIT(TCCR1B,0);
	CLR_BIT(TCCR1B,1);
	SET_BIT(TCCR1B,2);
}

void PWM_1_STOP()
{
	//To select 256 division factor
	CLR_BIT(TCCR1B,0);
	CLR_BIT(TCCR1B,1);
	CLR_BIT(TCCR1B,2);
}

u32 TIMER_1_CALC_TIME(void)
{
	
	SET_BIT(DDRD,7);

	 long long a,b,high,distance;
	TCCR1A = 0;
	TIFR = (1<<5);  	/* Clear ICF (Input Capture flag)  */
	SET_BIT(PORTD,7);
	_delay_ms(100);
	//PIN_WRITE(PD7,LOW);
	CLR_BIT(PORTD,7);
	TCCR1B = 0xc1;  	/* Rising edge, no prescaler , noise canceler*/
	while ((TIFR&(1<<5)) == 0);
	a = ICR1;  		/* Take value of capture register */
	TIFR = (1<<5);  	/* Clear ICF flag */
	TCCR1B = 0x81;  	/* Falling edge, no prescaler ,noise canceler*/
	while ((TIFR&(1<<5)) == 0);
	b = ICR1;  		/* Take value of capture register */
	TIFR = (1<<5);  	/* Clear ICF flag */
	TCNT1=0;
	TCCR1B = 0;  		/* Stop the timer */
	high=b-a;
	distance=((high*34600)/(F_CPU/8))/10 ;
	return distance;

}

