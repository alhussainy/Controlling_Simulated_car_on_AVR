/*
 * HC05.c
 *
 * Created: 25/01/2022 10:51:02
 *  Author: Alhussainy Khaled Anwar
 */ 
 #include "HC05.h"
 
 void HC05_INIT(void){
	UART_INIT();
 }
 u8	 HC05_REC(void){
	return UART_REC();
 }