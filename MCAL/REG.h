/*
 * REG.h
 *
 * Created: 04/01/2022 09:48:51 ص
 *  Author: Alhussainy Khaled Anwar
 */ 


#ifndef REG_H_
#define REG_H_

#include "STD_TYPES.h"

#define PORTA      (*((volatile u8*)0x3B))
#define DDRA       (*((volatile u8*)0x3A))
#define PINA       (*((volatile u8*)0x39))

#define PORTB      (*((volatile u8*)0x38))
#define DDRB       (*((volatile u8*)0x37))
#define PINB       (*((volatile u8*)0x36))

#define PORTC      (*((volatile u8*)0x35))
#define DDRC       (*((volatile u8*)0x34))
#define PINC       (*((volatile u8*)0x33))

#define PORTD      (*((volatile u8*)0x32))
#define DDRD       (*((volatile u8*)0x31))
#define PIND       (*((volatile u8*)0x30))
/******************************************************_ADC_REGISTERS************************/
#define ADCSRA     (*((volatile u8*)0x26))
#define ADMUX      (*((volatile u8*)0x27))
#define ADCL       (*((volatile u8*)0x24))
#define ADCH       (*((volatile u8*)0x25))
#define ADCVALUE   (*((volatile u16*)0x24))

/******************************************************_SREG_REGISTER************************/
#define SREG       (*((volatile u8*)0x5F))

/******************************************************_EXT_INT_REGISTERS************************/
#define GICR       (*((volatile u8*)0x5B))
#define MCUCR      (*((volatile u8*)0x55))

/******************************************************_TIMER_0_REGISTERS************************/
#define TCCR0      (*((volatile u8*)0x53))
#define TIMSK      (*((volatile u8*)0x59))
#define TCNT0      (*((volatile u8*)0x52))
#define OCR0       (*((volatile u8*)0x5C))

/******************************************************_WDT_REGISTERS************************/
#define WDTCR      (*((volatile u8*)0x41))


/*******************************************_TIMER_1_REGISTERS*******************************/


#define TCCR1A     (*((volatile u8*)0x4F))
#define TCCR1B     (*((volatile u8*)0x4E))
#define ICR1       (*((volatile u16*)0x46))
#define OCR1A      (*((volatile u16*)0x4A))

#define TCNT1      (*((volatile u8*)0x4C))
#define TIFR	   (*((volatile u8*)0x58))


/*******************************UART_REGISTERS*************************************************/


#define UCSRA		 (*((volatile u8*)0x2B))
#define UCSRB		 (*((volatile u8*)0x2A))
#define UCSRC		 (*((volatile u8*)0x40))
#define UBBRL		 (*((volatile u8*)0x29))
#define UBBRH		 (*((volatile u8*)0x40))

#define UDR			 (*((volatile u8*)0x2C))


/*******************SPI_REGISTERS***********************************************************/
#define SPDR		 (*((volatile u8*)0x2F))
#define SPSR		 (*((volatile u8*)0x2E))
#define SPCR		 (*((volatile u8*)0x2D))


/********************************I2C_REGISTERS***********************************************/
#define TWAR		(*((volatile u8*)0x22))
#define TWSR		(*((volatile u8*)0x21))
#define TWCR		(*((volatile u8*)0x56))
#define TWBR		(*((volatile u8*)0x20))
#define TWDR		(*((volatile u8*)0x23))
#endif /* REG_H_ */