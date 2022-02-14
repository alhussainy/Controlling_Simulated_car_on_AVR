/*
 * BUZZER.c
 *
 * Created: 04/01/2022 11:01:06 ص
 *  Author: Alhussainy Khaled Anwar
 */ 
 #include "BUZZER.h"
 #include "BUZZER_CFG.h"


 void BUZZER_INIT(void){
	 PIN_MODE(BUZZER_PIN,OUTPUT);
 }
 void BUZZER_ON(void){
	 PIN_WRITE(BUZZER_PIN,HIGH);
 }
 void BUZZER_OFF(void){
	 PIN_WRITE(BUZZER_PIN,LOW);
 }
 void BUZZER_ONCE(void){
	 BUZZER_ON();
	 _delay_ms(BUZZER_DELAY_SHORT);
	 BUZZER_OFF();
 }
 void BUZZER_TOG(void)
 {
	 PIN_TOG(BUZZER_PIN);
 }
 void BUZZER_TWICE(void){
	 BUZZER_ONCE();
	 _delay_ms(BUZZER_DELAY_SHORT);
	 BUZZER_ONCE();

 }
 void BUZZER_TRIPLE(void){
	 BUZZER_ONCE();
	 _delay_ms(BUZZER_DELAY_SHORT);
	 BUZZER_ONCE();
	 _delay_ms(BUZZER_DELAY_SHORT);
	 BUZZER_ONCE();
 }

 void BUZZER_LONG(void){
	 BUZZER_ON();
	 _delay_ms(BUZZER_DELAY_LONG);
	 BUZZER_OFF();
 }