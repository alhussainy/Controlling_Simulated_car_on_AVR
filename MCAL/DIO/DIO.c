/*
 * DIO.c
 *
 * Created: 03/01/2022 01:01:24 م
 *  Author: Alhussainy Khaled Anwar
 */ 
#include "DIO.h"
#include "BIT_MATH.h"
#include "REG.h"

void PIN_MODE(u8 x,u8 state)   
{
	u8 pin  = x % 10;
	u8 port = x / 10;
	switch(state)
	{
		case INPUT:
		switch(port)
		{
			case A:
			CLR_BIT(DDRA,pin);
			break;
			case B:
			CLR_BIT(DDRB,pin);
			break;
			case C:
			CLR_BIT(DDRC,pin);
			break;
			case D:
			CLR_BIT(DDRD,pin);
			break;
			default:
			break;
		}
		break;
		case OUTPUT:
		switch(port)
		{
			case A:
			SET_BIT(DDRA,pin);
			break;
			case B:
			SET_BIT(DDRB,pin);
			break;
			case C:
			SET_BIT(DDRC,pin);
			break;
			case D:
			SET_BIT(DDRD,pin);
			break;
			default:
			break;
		}
		break;
		default:
		break;
	}
}
void PIN_WRITE(u8 x,u8 state)
{
	u8 pin  = x % 10;
	u8 port = x / 10;
	switch(state)
	{
		case LOW:
		switch(port)
		{
			case A:
			CLR_BIT(PORTA,pin);
			break;
			case B:
			CLR_BIT(PORTB,pin);
			break;
			case C:
			CLR_BIT(PORTC,pin);
			break;
			case D:
			CLR_BIT(PORTD,pin);
			break;
			default:
			break;
		}
		break;
		case HIGH:
		switch(port)
		{
			case A:
			SET_BIT(PORTA,pin);
			break;
			case B:
			SET_BIT(PORTB,pin);
			break;
			case C:
			SET_BIT(PORTC,pin);
			break;
			case D:
			SET_BIT(PORTD,pin);
			break;
			default:
			break;
		}
		break;
		default:
		break;
	}	
}

void PIN_PULL_UP_RES(u8 x,u8 state)
{
	u8 pin  = x % 10;
	u8 port = x / 10;
	switch(state)
	{
		case DISABLE:
		switch(port)
		{
			case A:
			CLR_BIT(PORTA,pin);
			break;
			case B:
			CLR_BIT(PORTB,pin);
			break;
			case C:
			CLR_BIT(PORTC,pin);
			break;
			case D:
			CLR_BIT(PORTD,pin);
			break;
			default:
			break;
		}
		break;
		case ENABLE:
		switch(port)
		{
			case A:
			SET_BIT(PORTA,pin);
			break;
			case B:
			SET_BIT(PORTB,pin);
			break;
			case C:
			SET_BIT(PORTC,pin);
			break;
			case D:
			SET_BIT(PORTD,pin);
			break;
			default:
			break;
		}
		break;
		default:
		break;
	}	
}
u8   PIN_READ(u8 x)
{
	u8 value = 0;
	u8 pin  = x % 10;
	u8 port = x / 10;
	switch(port)
	{
		case A:
		value = GET_BIT(PINA,pin);
		break;
		case B:
		value = GET_BIT(PINB,pin);
		break;
		case C:
		value = GET_BIT(PINC,pin);
		break;
		case D:
		value = GET_BIT(PIND,pin);
		break;
		default:
		break;
	}	
	return value;
}
void PIN_TOG(u8 x)
{
	u8 pin  = x % 10;
	u8 port = x / 10;
		switch(port)
		{
			case A:
			TOG_BIT(PORTA,pin);
			break;
			case B:
			TOG_BIT(PORTB,pin);
			break;
			case C:
			TOG_BIT(PORTC,pin);
			break;
			case D:
			TOG_BIT(PORTD,pin);
			break;
			default:
			break;
		}	
}
void PORT_MODE(u8 port,u8 state)
{
	switch(state)
	{
		case INPUT:
		switch(port)
		{
			case A:
			DDRA = 0;
			break;
			case B:
			DDRB = 0;
			break;
			case C:
			DDRC = 0;
			break;
			case D:
			DDRD = 0;
			break;
			default:
			break;
		}
		break;
		case OUTPUT:
		switch(port)
		{
			case A:
			DDRA = 255;
			break;
			case B:
			DDRB = 255;
			break;
			case C:
			DDRC = 255;
			break;
			case D:
			DDRD = 255;
			break;
			default:
			break;
		}
		break;
		default:
		break;
	}
}
void PORT_WRITE(u8 port,u8 value)
{
	switch(port)
	{
		case A:
		PORTA = value;
		break;
		case B:
		PORTB = value;
		break;
		case C:
		PORTC = value;
		break;
		case D:
		PORTD = value;
		break;
		default:
		break;
	}
}

u8   PORT_READ(u8 port)
{
	u8 value = 0;
	switch(port)
	{
		case A:
		value = PORTA;
		break;
		case B:
		value = PORTB;
		break;
		case C:
		value = PORTC;
		break;
		case D:
		value = PORTD;
		break;
		default:
		break;
	}
	return value;
}