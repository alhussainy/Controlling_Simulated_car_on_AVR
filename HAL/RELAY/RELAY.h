/*
 * RELAY.h
 *
 * Created: 04/01/2022 01:10:39 م
 *  Author: Alhussainy Khaled Anwar
 */ 


#ifndef RELAY_H_
#define RELAY_H_

#include "STD_TYPES.h"

void RELAY_INIT(u8);
void RELAY_ON(u8);
void RELAY_OFF(u8);
void RELAY_TOG(u8);
#define RELAY_1       0
#define RELAY_2       1

#endif /* RELAY_H_ */