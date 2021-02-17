/*
 * Timer_0Register.h
 *
 *  Created on: Dec 15, 2020
 *      Author: Mario
 */

#ifndef TIMER0_REGISTER_H_
#define TIMER0_REGISTER_H_

#define TCCR0 *((volatile u8*)0x53)
#define TCNT0 *((volatile u8*)0x52)
#define TIMSK *((volatile u8*)0x59)
#define OCR0  *((volatile u8*)0x5C)


void __vector_10(void) __attribute__((signal));
void __vector_11(void) __attribute__((signal));



#endif /* TIMER0_REGISTER_H_ */
