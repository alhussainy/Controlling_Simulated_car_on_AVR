/*
 * HC05.h
 *
 * Created: 25/01/2022 10:51:09
 *  Author: Alhussainy Khaled Anwar
 */ 


#ifndef HC05_H_
#define HC05_H_


#include "HC05_CFG.h"
#include "UART.h"

void HC05_INIT(void);
u8	 HC05_REC(void);

#endif /* HC05_H_ */