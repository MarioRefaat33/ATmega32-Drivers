/*
**********************************
*	Auther  : Mario Refaat 
*	Date    : 23 / 11 / 2020  
*	version : V1	
**********************************
*/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include"DIO_Private.h"


void DIO_SetPinDirection (u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8PinDir)
{
		if ( Copy_u8PinDir == 1 )
		{
			switch (Copy_u8Port)
			{
				case 0: SET_BIT(DDRA,Copy_u8Pin); break;
				case 1: SET_BIT(DDRB,Copy_u8Pin); break;
				case 2: SET_BIT(DDRC,Copy_u8Pin); break;
				case 3: SET_BIT(DDRD,Copy_u8Pin); break;
			}
		}
		else if ( Copy_u8PinDir == 0 )
		{
			switch (Copy_u8Port)
			{
				case 0: CLR_BIT(DDRA,Copy_u8Pin); break;
				case 1: CLR_BIT(DDRB,Copy_u8Pin); break;
				case 2: CLR_BIT(DDRC,Copy_u8Pin); break;
				case 3: CLR_BIT(DDRD,Copy_u8Pin); break;
			}
		}
		else
		{
			/* Do Nothing */
		}
	}
	
void DIO_SetPinValue(u8 u8PortIdCopy , u8 u8PinIdCopy, u8 u8PinValCopy)
{
		if (u8PinValCopy == 1)
		{
			/* Check on the Required PORT Number */
			switch (u8PortIdCopy)
			{
				case 0: SET_BIT(PORTA,u8PinIdCopy); break;
				case 1: SET_BIT(PORTB,u8PinIdCopy); break;
				case 2: SET_BIT(PORTC,u8PinIdCopy); break;
				case 3: SET_BIT(PORTD,u8PinIdCopy); break;
			}

		}
		else if (u8PinValCopy == 0)
		{
			/* Check on the Required PORT Number */
			switch (u8PortIdCopy)
			{
				case 0: CLR_BIT(PORTA,u8PinIdCopy); break;
				case 1: CLR_BIT(PORTB,u8PinIdCopy); break;
				case 2: CLR_BIT(PORTC,u8PinIdCopy); break;
				case 3: CLR_BIT(PORTD,u8PinIdCopy); break;
			}
		}
		else
		{
			/* Do nothing, Wrong value to set */
		}
	}

/* IO Ports */
void DIO_SetPortDirection (u8 u8PortId, u8 u8PortDir)
{
	/* Check on the Required PORT Number */
	switch (u8PortId)
	{
		case 0: DDRA = u8PortDir; break;
		case 1: DDRB = u8PortDir; break;
		case 2: DDRC = u8PortDir; break;
		case 3: DDRD = u8PortDir; break;
		default: /* Wrong Port ID */       break;
	}
}

void DIO_SetPortValue (u8 u8PortId, u8 u8PortVal)
{
	/* Check on the Required PORT Number */
	switch (u8PortId)
	{
		case 0: PORTA = u8PortVal; break;
		case 1: PORTB = u8PortVal; break;
		case 2: PORTC = u8PortVal; break;
		case 3: PORTD = u8PortVal; break;
		default: /* Wrong Port ID */       break;
	}
}

u8 DIO_GetPinValue(u8 u8PortIdCopy, u8 u8PinIdCopy)
{
	/* Define Local Variable to get the BIT Value */
	u8 u8ResultLocal = 0 ;
		switch (u8PortIdCopy)
		{
			case 0: u8ResultLocal= GET_BIT(PINA,u8PinIdCopy); break;
			case 1: u8ResultLocal= GET_BIT(PINB,u8PinIdCopy); break;
			case 2: u8ResultLocal= GET_BIT(PINC,u8PinIdCopy); break;
			case 3: u8ResultLocal= GET_BIT(PIND,u8PinIdCopy); break;
			default	: 										  break;
		}
		/* return the local variable */
		return u8ResultLocal;
	}

void DIO_TogglePin(u8 Copy_U8Port , u8 Copy_U8Pin)
{
	switch (Copy_U8Port)
	{
		case 0 : TOG_BIT( PORTA , Copy_U8Pin ) ; break;
		case 1 : TOG_BIT( PORTB , Copy_U8Pin ) ; break;
		case 2 : TOG_BIT( PORTC , Copy_U8Pin ) ; break;
		case 3 : TOG_BIT( PORTD , Copy_U8Pin ) ; break;
		default		: 								  break;
	}

}
