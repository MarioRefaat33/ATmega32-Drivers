/*
 * UART_Program.c
 *
 *  Created on: Dec 21, 2020
 *      Author: Mario
 */

#include"BIT_MATH.h"
#include"STD_TYPES.h"
#include"UART_Config.h"
#include"DIO_Interface.h"
#include"UART_Private.h"





void UART_Init( u32 Copy_U8BoudRate )
{

	DIO_SetPinDirection( PORTD , PIN1 , OUTPUT ) ;//TX
	DIO_SetPinDirection( PORTD , PIN0 , INPUT  ) ;//RX

	u16 UBRR ;

	UBRR = ( F_CPU / ( 16 * Copy_U8BoudRate ) ) -1 ;

	UBRRH = (u8)( UBRR >> 8 ) ;
	UBRRL = (u8)( UBRR ) ;

	SET_BIT( UCSRB , 3 );
	SET_BIT( UCSRB , 4 );

	//UCSRC = (1<<7) | (1<<2) | (1<<1) ;




#if USART_Mode_Select == Asynchronous_Operation
	CLR_BIT(UCSRC,6);
#elif USART_Mode_Select == synchronous_Operation
	SET_BIT(UCSRC,6);
#endif

#if Parity_Mode == Disabled_Parity
	CLR_BIT(UCSRC,4);
	CLR_BIT(UCSRC,5);
#elif 	Parity_Mode == Enabled_Even_Parity
	CLR_BIT(UCSRC,4);
	SET_BIT(UCSRC,5);
#elif  	Parity_Mode == Enabled_Odd_Parity
	SET_BIT(UCSRC,4);
	SET_BIT(UCSRC,5);
#endif


#if Stop_Bit_Select == one_bit
	CLR_BIT(UCSRC,3);
#elif Stop_Bit_Select == two_bit
	SET_BIT(UCSRC,3);

#endif


#if Character_Size == bit_5
	CLR_BIT(UCSRC,1);
	CLR_BIT(UCSRC,2);
	CLR_BIT(UCSRC,3);
#elif	Character_Size == bit_6
	SET_BIT(UCSRC,1);
	CLR_BIT(UCSRC,2);
	CLR_BIT(UCSRC,3);
#elif	Character_Size == bit_7
	CLR_BIT(UCSRC,1);
	SET_BIT(UCSRC,2);
	CLR_BIT(UCSRC,3);

#elif	Character_Size == bit_8
	SET_BIT(UCSRC,1);
	SET_BIT(UCSRC,2);
	CLR_BIT(UCSRC,3);
#elif	Character_Size == bit_9
	SET_BIT(UCSRC,1);
	SET_BIT(UCSRC,2);
	SET_BIT(UCSRC,3);

#endif




}



void UART_Transmit( u8 Copy_U8Data )
{
	while(!GET_BIT(UCSRA,5)); // flags of intruupt

	UDR = Copy_U8Data ;
}

void UART_TransmitString(u8 * Copy_PU8String)
{
	for ( u8 Counter=0  ;  Copy_PU8String[Counter]!='\0'  ;  Counter++ )
	{
		UART_Transmit( Copy_PU8String[Counter] );
	}

}


u8 UART_Receive(void)
{
	u8 Copy_U8Data = 0 ;
	while(!GET_BIT(UCSRA,7)); // flags of intruupt

	Copy_U8Data = UDR ;

	return Copy_U8Data;

}

/*****************/
void UART_GReceive(u8 * Copy_U8Data)
{
	u8 i = 0 ;
	Copy_U8Data[i]=UART_Receive();
	while(Copy_U8Data[i]!='#') // flags of intruupt
	{
		i++;
		Copy_U8Data[i]=UART_Receive();

	}
	Copy_U8Data[i] = '\0' ;

}

