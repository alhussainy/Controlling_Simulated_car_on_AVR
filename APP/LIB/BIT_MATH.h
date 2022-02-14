/*
 * BIT_MATH.h
 *
 * Created: 04/01/2022 09:49:43 ص
 *  Author: Alhussainy Khaled Anwar
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(reg,bit)   (reg |= (1<<bit))
#define CLR_BIT(reg,bit)   (reg &= ~(1<<bit))
#define TOG_BIT(reg,bit)   (reg ^= (1<<bit))
#define GET_BIT(REG,BIT)   ((REG >> BIT)&1)

#endif /* BIT_MATH_H_ */