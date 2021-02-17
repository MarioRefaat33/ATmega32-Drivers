/*
 * Timer_0.c
 *
 *  Created on: Dec 15, 2020
 *      Author: Mario
 */

#include"DIO_Interface.h"
#include"BIT_MATH.h"
#include "Timer0_Config.h"
#include "Timer0_Register.h"

static u32 counter = 0 ;

void Timer0_Init(void)
{

	/*  Select the Operation_Mode  */
#if Operation_Mode == Normal_Mode
	CLR_BIT(TCCR0,6);
	CLR_BIT(TCCR0,3);
	// Overflow Interrupt
	// enable over flow Interrupt mode for timer 0
	// while using this mode don't forget the global Interrupt GIE
	SET_BIT(TIMSK,0);

#elif Operation_Mode == Phase_Correct_Mode
	SET_BIT(TCCR0,6); // WGM00
	CLR_BIT(TCCR0,3); // WGM01

	/* Compare Output Mode ( Set )*/
	SET_BIT(TCCR0,4); // COM00
	SET_BIT(TCCR0,5); // COM01

#elif Operation_Mode == CTC_Mode

	CLR_BIT(TCCR0,6); // WGM00
	SET_BIT(TCCR0,3); // WGM01
	// Output Compare Match Interrupt Enable
	// while using this mode don't forget the global Interrupt GIE
	SET_BIT(TIMSK,1);
	/* CTC value*/
	OCR0 = OCR_VALUE ;

#elif Operation_Mode ==	Fast_PWM_Mode
	/* Waveform Generation Mode ( Fast PWM Mode ) */
	SET_BIT(TCCR0,6); // WGM00
	SET_BIT(TCCR0,3); // WGM01

#if COMPARE_Mode == NON_INVERTING
	/* Compare Output Mode non-inverting mode */

	CLR_BIT(TCCR0,4); // COM00
	SET_BIT(TCCR0,5); // COM01
#elif COMPARE_Mode == INVERTING
	/* Compare Output Mode inverting mode  ( Set )*/
	SET_BIT(TCCR0,4); // COM00
	SET_BIT(TCCR0,5); // COM01
#endif

#endif



	/*   Select the clock source    */
#if Clock_Select ==   NO_CLOCK_SOURCE

	CLR_BIT(TCCR0,0); // CS00
	CLR_BIT(TCCR0,1); // CS01
	CLR_BIT(TCCR0,2); // CS02

#elif Clock_Select ==   PRESCALER_NO
	SET_BIT(TCCR0,0); // CS00
	CLR_BIT(TCCR0,1); // CS01
	CLR_BIT(TCCR0,2); // CS02

#elif Clock_Select ==   PRESCALER_8
	CLR_BIT(TCCR0,0); // CS00
	SET_BIT(TCCR0,1); // CS01
	CLR_BIT(TCCR0,2); // CS02

#elif Clock_Select ==   PRESCALER_64
	SET_BIT(TCCR0,0); // CS00
	SET_BIT(TCCR0,1); // CS01
	CLR_BIT(TCCR0,2); // CS02

#elif Clock_Select ==   PRESCALER_265
	CLR_BIT(TCCR0,0); // CS00
	CLR_BIT(TCCR0,1); // CS01
	SET_BIT(TCCR0,2); // CS02

#elif Clock_Select ==   PRESCALER_1024
	SET_BIT(TCCR0,0); // CS00
	CLR_BIT(TCCR0,1); // CS01
	SET_BIT(TCCR0,2); // CS02
#endif


}

void Timer0_DutyCycle(u8 Copy_U8_OCR0)
{
	/* Set OC0 Direction As OUTPUT */
	DIO_SetPinDirection(PORTB , PIN3 , OUTPUT);
	/* Load OCR0 Value ( From 0 to 255 ) */
	OCR0 = Copy_U8_OCR0;
}


void __vector_11(void)
{
	counter++ ;
	if (counter == 244)//for 2 sec
	{
		//	TCNT0=PRELOAD_VALUE;
		counter = 0 ;
		DIO_TogglePin(PORTC , PIN0);
	}
}


void __vector_10(void)
{
	counter++;
	if (counter == 5000)//for 2 sec
	{
		counter = 0 ;
		DIO_TogglePin(PORTC , PIN0);
	}
}
/*
void Timer0_CTC_Init(void)
{
	//Waveform Generation Mode ( CTC Mode )
	CLR_BIT(TCCR0,6); // WGM00
	SET_BIT(TCCR0,3); // WGM01
}
 */

/*void Timer0_VidPrescaler(u16 Copy_U8Prescaler)
{
	switch(Copy_U8Prescaler)
	{

	case 1 :
		SET_BIT(TCCR0,0); // CS00
		CLR_BIT(TCCR0,1); // CS01
		CLR_BIT(TCCR0,2); // CS02
		break;

	case 8 :
		CLR_BIT(TCCR0,0); // CS00
		SET_BIT(TCCR0,1); // CS01
		CLR_BIT(TCCR0,2); // CS02
		break;

	case 64 :
		SET_BIT(TCCR0,0); // CS00
		SET_BIT(TCCR0,1); // CS01
		CLR_BIT(TCCR0,2); // CS02
		break;

	case 256 :
		CLR_BIT(TCCR0,0); // CS00
		CLR_BIT(TCCR0,1); // CS01
		SET_BIT(TCCR0,2); // CS02
		break;

	case 1024 :
		SET_BIT(TCCR0,0); // CS00
		CLR_BIT(TCCR0,1); // CS01
		SET_BIT(TCCR0,2); // CS02
		break;

	default :
		break;

	}

}*/

