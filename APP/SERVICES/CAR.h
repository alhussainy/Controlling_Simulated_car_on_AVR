/*
 * CAR.h
 *
 * Created: 25/01/2022 13:52:17
 *  Author: Alhussainy Khaled Anwar
 */ 


#ifndef CAR_H_
#define CAR_H_
#include "LED.h"
#include "HC05.h"
#include "RELAY.h"
#include "LCD.h"
#include "BUZZER.h"
#include "ULTRASONIC.h"
#define DELAY_TIME 80
void CAR_INIT();
void HEAD_LIGHT_TOGGLE();
void ALERT_ON();
void ALERT_OFF();
void WAITING_MODE_TOGGLE();
void ACCELERATE();
void DRIVE_MODE_D();
void DRIVE_MODE_R();
void TURN_LEFT_ON();
void TURN_LEFT_OFF();
void TURN_RIGHT_ON();
void TURN_RIGHT_OFF();
void CRUZE_MODE_ON();
void CRUZE_MODE_OFF();
void LCD_DISPLAY();
 void STOP();
#define DRIVE			'0'
#define TURNLEFT		'1'
#define	TURNRIGHT		'2'
#define REVERSE			'3'
#define ALERT			'4'
#define	HEAD_LIGHTS		'6'
#define WANTING_LIGHTS	'5'
#define CM_MODE			'7'
#define	ACC				'8'

#define NOT_USED		 0
#define USED			 1

#endif /* CAR_H_ */