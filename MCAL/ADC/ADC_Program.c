

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


/*void adc_init(void)
{
	SET_BIT( ADMUX , 6 ) ; // REFS0
	CLR_BIT( ADMUX , 7 ) ; // REFS1

	SET_BIT( ADMUX , 5 ) ;
	SET_BIT( ADCSRA , 0 ) ;
	SET_BIT( ADCSRA , 1 ) ;
	SET_BIT( ADCSRA , 2 ) ;

	SET_BIT( ADCSRA , 7 ) ;
}*/
/*
void ADC_voidInit(void)
{
	// 8 bits mode , a vcc ref voltage, polling(not interrupt)

	//avcc reference voltage
	clear_bit(ADMUX,7);
	set_bit(ADMUX,6);

	//activate left adjust mode
	clear_bit(ADMUX,5);



	//prescaller division by 128
	set_bit(ADCSRA,2);
	set_bit(ADCSRA,1);
	set_bit(ADCSRA,0);

	//ADC enable
	 set_bit(ADCSRA,7);
}*/
/*
u16 ADC_u8GetChannelReading(u8 Channel)
{

	ADMUX&=0b11100000;   				//awl 7aga an ana a5od el value of channel de w a7otaha fe 5 bits bto3 ADMUX
	ADMUX|=Channel;

	set_bit(ADCSRA,6);      			//Start Conversion

	while(IS_bit_clear(ADCSRA,4) ); 		//polling on the conversion complete flag

	set_bit(ADCSRA,4);   				//CLEAR THE FLAG

	return 	 ADC;			      //get the result


}*/


/*
void ADC_SelectChannel(u8 Copy_Channel)
{
	//Take the value of the channel
	ADMUX&= 0XE0; //0b1110000

	if ( Copy_Channel >= 0    &&    Copy_Channel <= 31 )
	{
		ADMUX|= Copy_Channel ;
	}
	else
	{
		//Do Nothing
	}
}*/
/*
void ADC_Read(u16 * Copy_ReadValue)
{


	SET_BIT( ADCSRA , 6 ) ; // ( ADSC ) Start Converting

	//polling on the conversion complete flag
	while(GET_BIT(ADCSRA,6) == 1); // because this bit become equal zero after finishing converting

	*Copy_ReadValue = ADCH ; // read value ( We Are Reading The Low First Then The High

}*/
/*
u16 ADC_Read (u8 channel)
{
	// ADC Channel Selection
	channel &= 0x07;
	ADMUX &= 0xE0;
	ADMUX |= channel;

	// Start Single Convertion
	SET_BIT(ADCSRA,6);

	//wait for the conversion
	while(!(ADCSRA & (1<<4)));

	//ADC Flag Clear
	SET_BIT(ADCSRA,4);

	return ADCH;
}*/


/*
void ADC_Enable(void)
{
	// Enable ADC
	SET_BIT( ADCSRA , 7 ) ;
}

void ADC_Disable(void)
{
	// Enable ADC
	CLR_BIT( ADCSRA , 7 ) ;
}*/

