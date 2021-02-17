/*
 * Timer1_Interface.h
 *
 *  Created on: Dec 16, 2020
 *      Author: Mario
 */

#ifndef TIMER1_INTERFACE_H_
#define TIMER1_INTERFACE_H_

#include"STD_TYPES.h"

void Timer1_Init(void);
void Timer1_Load_OCR1A(u8 Copy_U8_OCR1A);
void Timer1_Load_OCR1B(u8 Copy_U8_OCR1B);


void Timer1_CAPT_InterruptEnable(void);
void Timer1_COMPA_InterruptEnable(void);
void Timer1_COMPB_InterruptEnable(void);
void Timer1_OVF_InterruptEnable(void);


void Timer1_CAPT_SetFlag(void);
void Timer1_COMPA_SetFlag(void);
void Timer1_COMPB_SetFlag(void);
void Timer1_OVF_SetFlag(void);



#endif /* TIMER1_INTERFACE_H_ */
