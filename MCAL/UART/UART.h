/*
 * UART.h
 *
 * Created: 18/01/2022 13:22:15
 *  Author: Alhussainy Khaled Anwar
 */ 


#ifndef UART_H_
#define UART_H_

#include "UART_CFG.h"
#include "STD_TYPES.h"
#include "REG.h"
#include "BIT_MATH.h"

#define _8		8
#define _16		16
#define ENABLE	1
#define DISABLE	0

void UART_INIT(void);
void UART_SEND(u8);
u8	 UART_REC(void);


#endif /* UART_H_ */