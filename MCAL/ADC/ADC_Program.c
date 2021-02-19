

#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"DIO_Interface.h"
#include"ADC_Private.h"
#include"ADC_Interface.h"
#include"ADC_Config.h"




void ADC_Init(void)
{


#if ADC_VREF == INTERNAL_OFF
	CLR_BIT( ADMUX , 6 ) ; // REFS0
	CLR_BIT( ADMUX , 7 ) ; // REFS1

#elif ADC_VREF == EXTERNAL_AVCC
	SET_BIT( ADMUX , 6 ) ; // REFS0
	CLR_BIT( ADMUX , 7 ) ; // REFS1

#elif ADC_VREF == RESERVED
	CLR_BIT( ADMUX , 6 ) ; // REFS0
	SET_BIT( ADMUX , 7 ) ; // REFS1

#elif ADC_VREF == INTERNAL_VOLTAGE
	SET_BIT( ADMUX , 6 ) ; // REFS0
	SET_BIT( ADMUX , 7 ) ; // REFS1

#endif


#if ADC_ADJ	== RIGHT_ADJ
	CLR_BIT( ADMUX , 5 ) ; // ADLAR

#elif ADC_ADJ == LEFT_ADJ
	SET_BIT( ADMUX , 5 ) ;

#endif


#if ADC_PRESCALER == PRESCALER_2
	SET_BIT( ADCSRA , 0 ) ;
	CLR_BIT( ADCSRA , 1 ) ;
	CLR_BIT( ADCSRA , 2 ) ;

#elif ADC_PRESCALER == PRESCALER_4
	CLR_BIT( ADCSRA , 0 ) ;
	SET_BIT( ADCSRA , 1 ) ;
	CLR_BIT( ADCSRA , 2 ) ;

#elif ADC_PRESCALER == PRESCALER_8
	SET_BIT( ADCSRA , 0 ) ;
	SET_BIT( ADCSRA , 1 ) ;
	CLR_BIT( ADCSRA , 2 ) ;

#elif ADC_PRESCALER == PRESCALER_16
	CLR_BIT( ADCSRA , 0 ) ;
	CLR_BIT( ADCSRA , 1 ) ;
	SET_BIT( ADCSRA , 2 ) ;

#elif ADC_PRESCALER == PRESCALER_32
	SET_BIT( ADCSRA , 0 ) ;
	CLR_BIT( ADCSRA , 1 ) ;
	SET_BIT( ADCSRA , 2 ) ;

#elif ADC_PRESCALER == PRESCALER_64
	CLR_BIT( ADCSRA , 0 ) ;
	SET_BIT( ADCSRA , 1 ) ;
	SET_BIT( ADCSRA , 2 ) ;

#elif ADC_PRESCALER == PRESCALER_128
	SET_BIT( ADCSRA , 0 ) ;
	SET_BIT( ADCSRA , 1 ) ;
	SET_BIT( ADCSRA , 2 ) ;

#endif


	// Enable ADC
	SET_BIT( ADCSRA , 7 ) ;

}


u16 ADC_GetChannelReading(u8 Channel)
{
	u16 Relult = 0 ;
	ADMUX&= 0XE0 ; //0b11100000

	ADMUX |= Channel ;

	// Start Conversion
	SET_BIT(ADCSRA,6);

	//polling on the conversion complete flag
	while((GET_BIT(ADCSRA,4))==0);
	//CLEAR THE FLAG
	SET_BIT(ADCSRA,4);

	//get the result
	Relult = ADC;
	return Relult;


}



