/*
 * Timer1_Program.c
 *
 *  Created on: Dec 16, 2020
 *      Author: Mario
 */


#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"DIO_Interface.h"
#include"Timer1_Config.h"
#include"Timer1_Private.h"



void Timer1_Init(void)
{

#if Waveform_Generation_Mode == Normal
	CLR_BIT(TCCR1A,0); // WGM10
	CLR_BIT(TCCR1A,1); // WGM11
	CLR_BIT(TCCR1B,3); // WGM12
	CLR_BIT(TCCR1B,4); // WGM13


#elif  Waveform_Generation_Mode == Phase_Correct_8_bit
	SET_BIT(TCCR1A,0); // WGM10
	CLR_BIT(TCCR1A,1); // WGM11
	CLR_BIT(TCCR1B,3); // WGM12
	CLR_BIT(TCCR1B,4); // WGM13


#elif  Waveform_Generation_Mode == Phase_Correct_9_bit
	CLR_BIT(TCCR1A,0); // WGM10
	SET_BIT(TCCR1A,1); // WGM11
	CLR_BIT(TCCR1B,3); // WGM12
	CLR_BIT(TCCR1B,4); // WGM13


#elif  Waveform_Generation_Mode == Phase_Correct_10_bit
	SET_BIT(TCCR1A,0); // WGM10
	SET_BIT(TCCR1A,1); // WGM11
	CLR_BIT(TCCR1B,3); // WGM12
	CLR_BIT(TCCR1B,4); // WGM13


#elif  Waveform_Generation_Mode == CTC_OCR1A
	CLR_BIT(TCCR1A,0); // WGM10
	CLR_BIT(TCCR1A,1); // WGM11
	SET_BIT(TCCR1B,3); // WGM12
	CLR_BIT(TCCR1B,4); // WGM13


#elif  Waveform_Generation_Mode == Fast_PWM_8_bit
	SET_BIT(TCCR1A,0); // WGM10
	CLR_BIT(TCCR1A,1); // WGM11
	SET_BIT(TCCR1B,3); // WGM12
	CLR_BIT(TCCR1B,4); // WGM13


#elif  Waveform_Generation_Mode == Fast_PWM_9_bit
	CLR_BIT(TCCR1A,0); // WGM10
	SET_BIT(TCCR1A,1); // WGM11
	SET_BIT(TCCR1B,3); // WGM12
	CLR_BIT(TCCR1B,4); // WGM13


#elif  Waveform_Generation_Mode == Fast_PWM_10_bit
	SET_BIT(TCCR1A,0); // WGM10
	SET_BIT(TCCR1A,1); // WGM11
	SET_BIT(TCCR1B,3); // WGM12
	CLR_BIT(TCCR1B,4); // WGM13


#elif  Waveform_Generation_Mode == Phase_and_Frequency_Correct_ICR1
	CLR_BIT(TCCR1A,0); // WGM10
	CLR_BIT(TCCR1A,1); // WGM11
	CLR_BIT(TCCR1B,3); // WGM12
	SET_BIT(TCCR1B,4); // WGM13


#elif  Waveform_Generation_Mode == Phase_and_Frequency_Correct_OCR1A
	SET_BIT(TCCR1A,0); // WGM10
	CLR_BIT(TCCR1A,1); // WGM11
	CLR_BIT(TCCR1B,3); // WGM12
	SET_BIT(TCCR1B,4); // WGM13


#elif  Waveform_Generation_Mode == Phase_Correct_ICR1
	CLR_BIT(TCCR1A,0); // WGM10
	SET_BIT(TCCR1A,1); // WGM11
	CLR_BIT(TCCR1B,3); // WGM12
	SET_BIT(TCCR1B,4); // WGM13


#elif  Waveform_Generation_Mode == Phase_Correct_OCR1A
	SET_BIT(TCCR1A,0); // WGM10
	SET_BIT(TCCR1A,1); // WGM11
	CLR_BIT(TCCR1B,3); // WGM12
	SET_BIT(TCCR1B,4); // WGM13


#elif  Waveform_Generation_Mode == CTC_ICR1
	CLR_BIT(TCCR1A,0); // WGM10
	CLR_BIT(TCCR1A,1); // WGM11
	SET_BIT(TCCR1B,3); // WGM12
	SET_BIT(TCCR1B,4); // WGM13


#elif  Waveform_Generation_Mode == Reserved
	SET_BIT(TCCR1A,0); // WGM10
	CLR_BIT(TCCR1A,1); // WGM11
	SET_BIT(TCCR1B,3); // WGM12
	SET_BIT(TCCR1B,4); // WGM13


#elif  Waveform_Generation_Mode == Fast_PWM_ICR1
	CLR_BIT(TCCR1A,0); // WGM10
	SET_BIT(TCCR1A,1); // WGM11
	SET_BIT(TCCR1B,3); // WGM12
	SET_BIT(TCCR1B,4); // WGM13

	ICR1 = ICR1_Value;


#elif  Waveform_Generation_Mode == Fast_PWM_OCR1A
	SET_BIT(TCCR1A,0); // WGM10
	SET_BIT(TCCR1A,1); // WGM11
	SET_BIT(TCCR1B,3); // WGM12
	SET_BIT(TCCR1B,4); // WGM13

#endif



#if Clock_Select == NO_CLOCK_SOURCE

	CLR_BIT(TCCR1B,0); // CS00
	CLR_BIT(TCCR1B,1); // CS01
	CLR_BIT(TCCR1B,2); // CS02


#elif Clock_Select == PRESCALER_NO
	SET_BIT(TCCR1B,0); // CS00
	CLR_BIT(TCCR1B,1); // CS01
	CLR_BIT(TCCR1B,2); // CS02

#elif Clock_Select == PRESCALER_8
	CLR_BIT(TCCR1B,0); // CS00
	SET_BIT(TCCR1B,1); // CS01
	CLR_BIT(TCCR1B,2); // CS02

#elif Clock_Select == PRESCALER_64
	SET_BIT(TCCR1B,0); // CS00
	SET_BIT(TCCR1B,1); // CS01
	CLR_BIT(TCCR1B,2); // CS02


#elif Clock_Select == PRESCALER_256
	CLR_BIT(TCCR1B,0); // CS00
	CLR_BIT(TCCR1B,1); // CS01
	SET_BIT(TCCR1B,2); // CS02


#elif Clock_Select == PRESCALER_1024
	SET_BIT(TCCR1B,0); // CS00
	CLR_BIT(TCCR1B,1); // CS01
	SET_BIT(TCCR1B,2); // CS02
#endif


#if Channe_Mood == Channel_A

#if COMPARE_Mode == NON_INVERTING
	CLR_BIT(TCCR1A,6);
	SET_BIT(TCCR1A,7);
#elif COMPARE_Mode == INVERTING
	SET_BIT(TCCR1A,6);
	SET_BIT(TCCR1A,7);
#endif
#endif

#if 	Channe_Mood == Channel_B

#if COMPARE_Mode == NON_INVERTING
	CLR_BIT(TCCR1A,4);
	SET_BIT(TCCR1A,5);

#elif COMPARE_Mode == INVERTING
	SET_BIT(TCCR1A,4);
	SET_BIT(TCCR1A,5);

#endif
#endif


}




void Timer1_Load_OCR1A(u8 Copy_U8_OCR1A)
{
	DIO_SetPinDirection(PORTD , PIN5 , OUTPUT);

	OCR1A = Copy_U8_OCR1A ;
}


void Timer1_Load_OCR1B(u8 Copy_U8_OCR1B)
{
	DIO_SetPinDirection(PORTD , PIN4 , OUTPUT);

	OCR1B = Copy_U8_OCR1B ;
}



/*   when using the Interrupt don't forget the GIE   */
void Timer1_CAPT_InterruptEnable(void)
{
	/* Interrupt On Input Capture Enable ( last operation ) */
	SET_BIT(TIMSK,5); // TICIE1
}

void Timer1_COMPA_InterruptEnable(void)
{
	/* Interrupt On Compare Match A Enable ( last operation ) */
	SET_BIT(TIMSK,4); // OCIEIA
}

void Timer1_COMPB_InterruptEnable(void)
{
	/* Interrupt On Compare Match B Enable ( last operation ) */
	SET_BIT(TIMSK,3); // OCIEIB
}

void Timer1_OVF_InterruptEnable(void)
{
	/* Interrupt On Over Flow  Enable ( last operation ) */
	SET_BIT(TIMSK,2); // TOIE1
}


void Timer1_CAPT_SetFlag(void)
{
	/* Interrupt On Input Capture Enable ( last operation ) */
	SET_BIT(TIFR,5); // ICF1
}

void Timer1_COMPA_SetFlag(void)
{
	/* Interrupt On Compare Match A Enable ( last operation ) */
	SET_BIT(TIFR,4); // OCIE1A
}

void Timer1_COMPB_SetFlag(void)
{
	/* Interrupt On Compare Match B Enable ( last operation ) */
	SET_BIT(TIFR,3); // OCIE1B
}

void Timer1_OVF_SetFlag(void)
{
	/* Interrupt On Over Flow  Enable ( last operation ) */
	SET_BIT(TIFR,2); // TOV1
}

