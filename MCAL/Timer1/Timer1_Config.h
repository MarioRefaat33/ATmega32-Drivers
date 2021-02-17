/*
 * Timer1_Config.h
 *
 *  Created on: Dec 16, 2020
 *      Author: Mario
 */

#ifndef TIMER1_CONFIG_H_
#define TIMER1_CONFIG_H_

#define Normal                 				    0
#define	Phase_Correct_8_bit    		     		1
#define	Phase_Correct_9_bit   				    2
#define	Phase_Correct_10_bit  				    3
#define	CTC_OCR1A                   			4
#define Fast_PWM_8_bit		  				 	5
#define	Fast_PWM_9_bit		  			 		6
#define	Fast_PWM_10_bit		  				 	7
#define	Phase_and_Frequency_Correct_ICR1	 	8
#define	Phase_and_Frequency_Correct_OCR1A  		9
#define	Phase_Correct_ICR1                    	10
#define	Phase_Correct_OCR1A                		11
#define	CTC_ICR1						 		12
#define	Reserved						 		13
#define	Fast_PWM_ICR1					 		14
#define	Fast_PWM_OCR1A					 		15

#define	Waveform_Generation_Mode  				Fast_PWM_ICR1


#define NO_CLOCK_SOURCE				0
#define PRESCALER_NO				1
#define PRESCALER_8					2
#define PRESCALER_64				3
#define PRESCALER_256				4
#define PRESCALER_1024				5

#define Clock_Select   				PRESCALER_256


#define NON_INVERTING        	 0
#define INVERTING              	 1
#define COMPARE_Mode				INVERTING

#define Channel_A                0
#define Channel_B                1

#define Channe_Mood              	Channel_B


#define ICR1_Value           		 625















#endif /* TIMER1_CONFIG_H_ */
