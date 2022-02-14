/*
 * UART.c
 *
 * Created: 18/01/2022 13:22:07
 *  Author: Alhussainy Khaled Anwar
 */ 
 #include "UART.h"
 
 void UART_INIT(void){
	 CLR_BIT(DDRD,0);
	 SET_BIT(DDRD,1);
	 /*to enable transimitting*/
	 SET_BIT(UCSRB,3);
	 /*to enable receiving*/
	 SET_BIT(UCSRB,4);
	 /*to define character size*/
	 CLR_BIT(UCSRB,2);
	 //SET_BIT(UCSRC,7);/*select UCSRC*/
	 //SET_BIT(UCSRC,1);
	 //SET_BIT(UCSRC,7);/*select UCSRC*/
	 //SET_BIT(UCSRC,2);
	 UCSRC = 0b10000110;
	 #if INT_AVAILABE	== ENABLE
	 SET_BIT(UCSRB,7); //enable Receive complete Interrupt
	 SET_BIT(UCSRB,6); //enable Transmit complete Interrupt
	  //SET_BIT(UCSRB,5); //enable Empty Buffer Interrupt
	 SET_BIT(SREG,7);
	 #endif
	 /***to generate 9600 for 16M crystal*/
	 
	 UBBRL = 103;
	 
	 
 }
 void UART_SEND(u8 data){
	 UDR = data;
	 #if INT_AVAILABE ==	DISABLE
	 while(GET_BIT(UCSRA,6)==0);
	 #endif

 }
 u8	 UART_REC(void){
	 #if INT_AVAILABE==	DISABLE
	 while(GET_BIT(UCSRA,7)==0);
	 #endif
	 
	 return UDR;
 }

