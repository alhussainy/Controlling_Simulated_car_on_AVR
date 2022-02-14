/*
* main.c
*
* Created: 1/25/2022 10:44:35 AM
*  Author: Alhussainy Khaled Anwar
*/
#include "LED.h"
#include "LCD.h"
#include "UART.h"
#include "BUZZER.h"
#include "HC05.h"
#define F_CPU    16000000UL
#include <util/delay.h>
#include "avr/interrupt.h"
extern u32 num_of_ov;
extern u32 rem_ticks;
#include "CAR.h"
u8 rec_data = 0;

u8 data_used=0;

extern u8 CM;
int main(void)
{
	CAR_INIT();
	u32 distance=0;
	while(1)
	{
		LCD_DISPLAY();

		if(CM == 1){
			distance=ULTRA_SONIC_READ();
			LCD_GO_TO(1,0);
			LCD_WRITE_CHR('D');
			LCD_WRITE_CHR('I');
			LCD_WRITE_CHR('S');
			LCD_WRITE_CHR(':');
			LCD_WRITE_CHR(distance/10+'0');
			LCD_WRITE_CHR(distance%10+'0');
			while(distance > 20 && CM == 1 ){
				ACCELERATE();
				distance=ULTRA_SONIC_READ();
				if(rec_data == ACC || rec_data == REVERSE || rec_data == CM_MODE){
					break;
				}
			}
			STOP();
			
		}else{
			LCD_GO_TO(1,0);
			LCD_WRITE_CHR('D');
			LCD_WRITE_CHR('I');
			LCD_WRITE_CHR('S');
			LCD_WRITE_CHR(':');
			LCD_WRITE_CHR('-');
			LCD_WRITE_CHR('-');
		}
		switch(rec_data){
			case WANTING_LIGHTS:
			while(rec_data==WANTING_LIGHTS && data_used==NOT_USED){
				data_used=USED;
				_delay_ms(DELAY_TIME);
			}
			WAITING_MODE_TOGGLE();
			break;
			case ALERT:
			while(rec_data==ALERT && data_used==NOT_USED){
				data_used=USED;
				ALERT_ON();
				_delay_ms(DELAY_TIME);
			}
			ALERT_OFF();
			break;
			case ACC:
			while(rec_data==ACC && data_used==NOT_USED){
				ACCELERATE();
				data_used=USED;
				_delay_ms(DELAY_TIME);
				CRUZE_MODE_OFF();
			}
		    
			STOP();
			break;
			case HEAD_LIGHTS:
			while(rec_data==HEAD_LIGHTS && data_used==NOT_USED){
				data_used=USED;
				_delay_ms(DELAY_TIME);
			}
			HEAD_LIGHT_TOGGLE();
			break;
			case DRIVE:
			while(rec_data==DRIVE && data_used==NOT_USED){
				data_used=USED;
				_delay_ms(DELAY_TIME);
			}
			DRIVE_MODE_D();
			break;
			case REVERSE:
			while(rec_data==REVERSE && data_used==NOT_USED){
				data_used=USED;
				_delay_ms(DELAY_TIME);
			}
			DRIVE_MODE_R();
			break;
			case TURNRIGHT:
			while(rec_data==TURNRIGHT && data_used==NOT_USED){
				data_used=USED;
				TURN_RIGHT_ON();
				_delay_ms(DELAY_TIME);
			}
			TURN_RIGHT_OFF();
			break;
			case TURNLEFT:
			while(rec_data==TURNLEFT && data_used==NOT_USED){
				data_used=USED;
				TURN_LEFT_ON();
				_delay_ms(DELAY_TIME);
			}
			TURN_LEFT_OFF();
			break;
			case CM_MODE:
			while(rec_data==CM_MODE && data_used==NOT_USED){
				data_used=USED;
				_delay_ms(DELAY_TIME);
			}
			if(CM==0){
				CRUZE_MODE_ON();
			}
			else{
				CRUZE_MODE_OFF();
			}
			
			break;
			default:
			
			break;
		}
		rec_data=0;
	}
}

ISR(TIMER0_OVF_vect)
{
	static u8 counter = 0;
	counter++;
	if(counter == num_of_ov)
	{
		RELAY_TOG(RELAY_2);
		counter = 0;
		TCNT0 = 256 - rem_ticks;
	}
}


ISR(USART_RXC_vect){
	rec_data= HC05_REC();
	data_used=NOT_USED;
}
