/*
 * LED.h
 *
 * Created: 04/01/2022 10:02:03 ص
 *  Author: Alhussainy Khaled Anwar
 */ 


#ifndef LED_H_
#define LED_H_

#include "STD_TYPES.h"

void LED_INIT(u8);
void LED_ON(u8);
void LED_OFF(u8);
void LED_TOG(u8);

#define B_LED      0
#define R_LED      1
#define G_LED      2

#endif /* LED_H_ */