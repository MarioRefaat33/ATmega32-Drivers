/*
 * Timer0_Private.h
 *
 *  Created on: Dec 15, 2020
 *      Author: Mario
 */

#ifndef TIMER0_CONFIG_H_
#define TIMER0_CONFIG_H_





#define Normal_Mode    		 		0
#define Phase_Correct_Mode    		1
#define CTC_Mode  					2
#define Fast_PWM_Mode   		 	3


#define Operation_Mode 			Fast_PWM_Mode


#if Operation_Mode == Normal_Mode
#define PRELOAD_VALUE				 220
#endif

#if Operation_Mode == CTC_Mode
#define OCR_VALUE     				200
#endif


#define NON_INVERTING              0
#define INVERTING                  1

#define COMPARE_Mode				NON_INVERTING


#define NO_CLOCK_SOURCE			0
#define PRESCALER_NO			1
#define PRESCALER_8				2
#define PRESCALER_64			3
#define PRESCALER_256			4
#define PRESCALER_1024			5


#define Clock_Select   PRESCALER_8





#endif /* TIMER0_CONFIG_H_ */
