/*
 * RELAY.c
 *
 * Created: 04/01/2022 01:10:27 م
 *  Author: Alhussainy Khaled Anwar
 */ 
#include "RELAY_CFG.h"
#include "RELAY.h"
#include "DIO.h"

void RELAY_INIT(u8 relay)
{
	switch(relay)
	{
		case RELAY_1:
		PIN_MODE(RELAY_1_PIN,OUTPUT);
		break;
		case RELAY_2:
		PIN_MODE(RELAY_2_PIN,OUTPUT);
		break;
		default:
		break;
	}
}
void RELAY_ON(u8 relay)
{
	switch(relay)
	{
		case RELAY_1:
		PIN_WRITE(RELAY_1_PIN,HIGH);
		break;
		case RELAY_2:
		PIN_WRITE(RELAY_2_PIN,HIGH);
		break;
		default:
		break;
	}	
}
void RELAY_OFF(u8 relay)
{
	switch(relay)
	{
		case RELAY_1:
		PIN_WRITE(RELAY_1_PIN,LOW);
		break;
		case RELAY_2:
		PIN_WRITE(RELAY_2_PIN,LOW);
		break;
		default:
		break;
	}	
}

void RELAY_TOG(u8 relay){
	switch(relay)
	{
		case RELAY_1:
		PIN_TOG(RELAY_1_PIN);
		break;
		case RELAY_2:
		PIN_TOG(RELAY_2_PIN);
		break;
		default:
		break;
	}
}