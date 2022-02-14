/*
 * BUZZER.h
 *
 * Created: 04/01/2022 11:01:17 ص
 *  Author: Alhussainy Khaled Anwar
 */ 


#ifndef BUZZER_H_
#define BUZZER_H_



#include "DIO.h"

#define  F_CPU 16000000UL
#include <util/delay.h>

void BUZZER_INIT(void);
void BUZZER_ON(void);
void BUZZER_OFF(void);
void BUZZER_ONCE(void);
void BUZZER_TWICE(void);
void BUZZER_TRIPLE(void);
void BUZZER_LONG(void);
void BUZZER_TOG(void);


#endif /* BUZZER_H_ */