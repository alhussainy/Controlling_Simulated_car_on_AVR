/*
* CAR.c
*
* Created: 25/01/2022 13:52:07
*  Author: Alhussainy Khaled Anwar
*/
#include "CAR.h"
#include "TIMER_0.h"

extern u32 num_of_ov;
extern u32 rem_ticks;
u8 WAITING_MODE_ACTIVE;
u8 driveMode;
u8 CM;
void CAR_INIT(){
	RELAY_INIT(RELAY_1);
	RELAY_INIT(RELAY_2);
	LED_INIT(B_LED);
	LED_INIT(G_LED);
	LED_INIT(R_LED);
	BUZZER_INIT();
	LCD_INIT();
	TIMER_0_INIT();
	TIMER_0_SET_TIME(1000);
	HC05_INIT();
	WAITING_MODE_ACTIVE=0;
	driveMode='D';
	CM=0;
}
void LCD_DISPLAY(){
	LCD_GO_TO(0,0);
	LCD_WRITE_CHR('D');
	LCD_WRITE_CHR('M');
	LCD_WRITE_CHR(' ');
	LCD_WRITE_CHR(':');
	LCD_WRITE_CHR(' ');
	LCD_WRITE_CHR(driveMode);

	LCD_GO_TO(0,8);
	LCD_WRITE_CHR('C');
	LCD_WRITE_CHR('M');
	LCD_WRITE_CHR(' ');
	LCD_WRITE_CHR(':');
	LCD_WRITE_CHR(' ');
	if(CM == 1){
		LCD_WRITE_CHR('O');
		LCD_WRITE_CHR('N');
		LCD_WRITE_CHR(' ');
		}else if(CM==0){
		LCD_WRITE_CHR('O');
		LCD_WRITE_CHR('F');
		LCD_WRITE_CHR('F');
	}

}
void HEAD_LIGHT_TOGGLE(){
	RELAY_TOG(RELAY_1);
}
void ALERT_ON(){
	BUZZER_ON();
}
void ALERT_OFF(){
	BUZZER_OFF();
}
void WAITING_MODE_TOGGLE(){
	
	if(WAITING_MODE_ACTIVE==0){
		WAITING_MODE_ACTIVE=1;
		RELAY_ON(RELAY_2);
		TIMER_0_START();
	}else{
		WAITING_MODE_ACTIVE=0;
		TIMER_0_STOP();
		RELAY_OFF(RELAY_2);
	}
}
void ACCELERATE(){
	LED_ON(G_LED);
}
void STOP(){
	LED_OFF(G_LED);
}
void DRIVE_MODE_D(){
	driveMode='D';
	
}
void DRIVE_MODE_R(){
	driveMode='R';
	CRUZE_MODE_OFF();
}
void TURN_LEFT_ON(){
	LED_ON(B_LED);
}
void TURN_LEFT_OFF(){
	LED_OFF(B_LED);
}
void TURN_RIGHT_ON(){
	LED_ON(R_LED);
}
void TURN_RIGHT_OFF(){
	LED_OFF(R_LED);
}
void CRUZE_MODE_ON(){
	if(driveMode=='D')
	CM=1;
}
void CRUZE_MODE_OFF(){
	CM=0;
}
