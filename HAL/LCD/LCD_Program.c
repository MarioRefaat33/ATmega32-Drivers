
/**
* Auther : Mario Refaat 
* Date   : 30 / 11 / 2020
*
**/

/**
 *
 *
 *  RS  ( 1 -> data , 0 -> Command )
 *
 *  RW  ( 0 -> write , 1 -> read )
 *
 *  E  ( H -> delay(1) -> L -> delay(1)  )
 *
 * */

#include <util/delay.h>
#include "STD_TYPES.h"
#include "DIO_Interface.h"
#include "LCD_Private.h"

void LCD_SendCommand (u8  Coppy_U8Comand)
{
	DIO_SetPinValue(LCD_RS_PORT , LCD_RS_PIN ,LOW) ; 	// Rs = 0  
	DIO_SetPinValue(LCD_RW_PORT , LCD_RW_PIN ,LOW) ; 	// Rw = 0  
	DIO_SetPortValue(LCD_DATA_PORT, Coppy_U8Comand);  	// port
	DIO_SetPinValue(LCD_E_PORT,LCD_E_PIN,HIGH);			// Enable pin 
	_delay_ms(1);
	DIO_SetPinValue(LCD_E_PORT,LCD_E_PIN,LOW);
	_delay_ms(1);
}

void LCD_Init(void)
{
	DIO_SetPinDirection( LCD_RS_PORT , LCD_RS_PIN , OUTPUT ); 		// RS
	DIO_SetPinDirection( LCD_RW_PORT , LCD_RW_PIN , OUTPUT ); 		// RW
	DIO_SetPinDirection( LCD_E_PORT , LCD_E_PIN , OUTPUT );   		// E
	DIO_SetPinValue( LCD_E_PORT , LCD_E_PIN , LOW ); 		 		// sitting
	_delay_ms(50); 											 		// more than 30 ms
	DIO_SetPortDirection(LCD_DATA_PORT,LCD_DATA_VALUE);

	#if LCD_MODE == EIGHT_BIT_MODE

	// Data Sheet Page 16 ; 0 , 0 , 1 , DL=data length , N=data lines , F=char font , X , X (0b00111000)
	LCD_SendCommand(0x38);
	_delay_ms(1);  				// more than 39 macro second ;
	// Data Sheet Page 16 ; 0 , 0 , 0 , 0 , 1 , D=display , C=cursor , B=blinking ( 0b00001101 )
	LCD_SendCommand(0x0f);
	_delay_ms(1);  				// more than 39 macro second ;
	LCD_SendCommand(0x01); 		// To Clear Screen
	_delay_ms(10);

	#elif LCD_MODE == FOUR_BIT_MODE

	DIO_SetPortDirection( LCD_DATA_PORT , LCD_DATA_VALUE ); // Data output

	LCD_SendCommand(0b00100000);
	LCD_SendCommand(0b00100000);
	LCD_SendCommand(0b11000000);9
	_delay_ms(1);
	LCD_SendCommand(0b00000000);
	LCD_SendCommand(0b11110000);
	_delay_ms(1);
	LCD_SendCommand(0b00000000);
	LCD_SendCommand(0b00010000);
	_delay_ms(2);
	LCD_SendCommand(0b00000000);
	LCD_SendCommand(0b01110000);

#else
#error "Error you must be FOUR_BIT_MODE or EIGHT_BIT_MODE "
#endif

}

void LCD_SendData(u8 Coppy_U8Data)
{
	DIO_SetPinValue(LCD_RS_PORT , LCD_RS_PIN ,HIGH) ; 	// Rs = 1  
	DIO_SetPinValue(LCD_RW_PORT , LCD_RW_PIN ,LOW) ; 	// Rw = 0  
	DIO_SetPortValue(LCD_DATA_PORT, Coppy_U8Data ) ;  	// port
	DIO_SetPinValue(LCD_E_PORT,LCD_E_PIN,HIGH);			// Enable pin 
	_delay_ms(1);
	DIO_SetPinValue(LCD_E_PORT,LCD_E_PIN,LOW);
	_delay_ms(1);
}


void LCD_SendString(const u8 *str)
{
	u8 i = 0;
	while(str[i] != '\0')
	{
		LCD_SendData(str[i]);
		i++;
	}
}



void LCD_SetPosition(u8 Row , u8 Col)
{
	if ( 0 == Row){
		LCD_SendCommand(128+Col);
	}else if ( 1 == Row ){
		LCD_SendCommand(128+64+Col);
	}
}

void LCD_ClearScreen (void)
{
	/*send CLear screen command */
	LCD_SendCommand(0x01);
	_delay_ms(10);
}

void LCD_DrowChar( u8 POS, u8* Copy_PU8SpecialChar)
{
	LCD_SendCommand(0x40 + (POS*8)); // 0b01000000; //64 /*0x40 GOTO CGRAM */
	for(u8 i=0 ; i<8 ; i++)
	{
		LCD_SendData(Copy_PU8SpecialChar[i]);
	}
	LCD_SendCommand(0x80);
}


void LCD_DrowSpecial( u8 Length,u8* Copy_PU8SpecialChar , u8 ROW , u8 COL)
{
	LCD_SendCommand(0x40); // 0b01000000; //64
	for(u8 i=0 ; i<(Length*8); i++)
	{
		LCD_SendData(Copy_PU8SpecialChar[i]);
	}
	LCD_SendCommand(0x80);
	LCD_SetPosition(ROW,COL);

	for( s8 j = Length-1  ; j >= 0   ; j-- )
	{
		LCD_SendData(j);
	}
}


void LCD_displayStringRowColumn(u8 row,u8 col,const s8 *str)
{
	/* go to to the required LCD position */
	LCD_SetPosition(row,col);
	/* display the string */
	LCD_SendString(str);
}

void LCD_1ByteToString(u8 copy_u8num){
	  int i, rem, len = 0, n;
	  u8 str[11]={0};
	    n = copy_u8num;
	    while (n != 0)
	    {
	        len++;
	        n /= 10;
	    }
	    for (i = 0; i < len; i++)
	    {
	        rem = copy_u8num % 10;
	        copy_u8num = copy_u8num / 10;
	        str[len - (i + 1)] = rem + '0';
	    }
	    str[len] = '\0';
	    LCD_SendString(str);

}

void LCD_4ByteToString(u32 copy_u8num){
	  u32 i, rem, len = 0, n;
	  u8 str[11]={0};
	    n = copy_u8num;
	    while (n != 0)
	    {
	        len++;
	        n /= 10;
	    }
	    for (i = 0; i < len; i++)
	    {
	        rem = copy_u8num % 10;
	        copy_u8num = copy_u8num / 10;
	        str[len - (i + 1)] = rem + '0';
	    }
	    str[len] = '\0';
	    LCD_SendString(str);

}
/*
void LCD_SendSpecialNumber(s32 Copy_S32Number) //
{
	s32 n=1000000000;
	while(n>=1)
	{
		if(Copy_S32Number>=n)
		{
			LCD_SendData(((Copy_S32Number/n)%10)+'0');
		}
		n=n/10;
	}
}*/

/*void LCD_displayStringRowColum(u8 copy_u8row, u8 copy_u8colum, u32 *string){
	LCD_gotorowcolum(copy_u8row, copy_u8colum);
	LCD_SendString(string);

}*/


/*void LCD_Log_PrintNumber(u16 Copy_u16Val)
{
	u8 Local_u8Factor;

	if (Copy_u16Val >= (u16)10000)
	{
		Local_u8Factor = (u8)(Copy_u16Val / (u16) 10000);
		LCD_SendData(Local_u8Factor+48);
		Copy_u16Val = Copy_u16Val - (u16)(Local_u8Factor * (u16)10000);

		Local_u8Factor = (u8)(Copy_u16Val / (u16) 1000);
		LCD_SendData(Local_u8Factor+48);
		Copy_u16Val = Copy_u16Val - (u16)(Local_u8Factor * (u16)1000);

		Local_u8Factor = (u8)(Copy_u16Val / (u16) 100);
		LCD_SendData(Local_u8Factor+48);
		Copy_u16Val = Copy_u16Val - (u16)(Local_u8Factor * (u8)100);

		Local_u8Factor = (u8)(Copy_u16Val / (u16) 10);
		LCD_SendData(Local_u8Factor+48);
		Local_u8Factor = Copy_u16Val - (u16)(Local_u8Factor * (u8)10);
		LCD_SendData(Local_u8Factor+48);

	}

	else if (Copy_u16Val >= (u16) 1000 )
	{
		Local_u8Factor = (u8)(Copy_u16Val / (u16) 1000);
		LCD_SendData(Local_u8Factor+48);
		Copy_u16Val = Copy_u16Val - (u16)(Local_u8Factor * (u16)1000);

		Local_u8Factor = (u8)(Copy_u16Val / (u16) 100);
		LCD_SendData(Local_u8Factor+48);
		Copy_u16Val = Copy_u16Val - (u16)(Local_u8Factor * (u8)100);

		Local_u8Factor = (u8)(Copy_u16Val / (u16) 10);
		LCD_SendData(Local_u8Factor+48);
		Local_u8Factor = Copy_u16Val - (u16)(Local_u8Factor * (u8)10);
		LCD_SendData(Local_u8Factor+48);
	}

	else if (Copy_u16Val >= (u8)100 )
	{
		Local_u8Factor = (u8)(Copy_u16Val / (u16) 100);
		LCD_SendData(Local_u8Factor+48);
		Copy_u16Val = Copy_u16Val - (u16)(Local_u8Factor * (u8)100);

		Local_u8Factor = (u8)(Copy_u16Val / (u16) 10);
		LCD_SendData(Local_u8Factor+48);
		Local_u8Factor = Copy_u16Val - (u16)(Local_u8Factor * (u8)10);
		LCD_SendData(Local_u8Factor+48);
	}

	else if (Copy_u16Val >= (u8) 10 )
	{
		Local_u8Factor = (u8)((u8)Copy_u16Val / (u8) 10);
		LCD_SendData(Local_u8Factor+48);
		Local_u8Factor = Copy_u16Val - (u16)(Local_u8Factor * (u8)10);
		LCD_SendData(Local_u8Factor+48);
	}

	else
	{
		LCD_SendData(Copy_u16Val+48);
	}
}*/
/*
 * void LCD_VidWriteNum(u32 Copy_u8Num)
{
	if(Copy_u8Num <=9 &&Copy_u8Num >=0)
	{
		LCD_VidSendData(Copy_u8Num + 48);
	}

	else
	{ u16 i=0;

	  while(Copy_u8Num%10==0)
	  {
		i++;
		Copy_u8Num=Copy_u8Num/10;
	  }

		u32 Local_u16rev=0;
		while(Copy_u8Num>0)
		{
			Local_u16rev=Local_u16rev*10+Copy_u8Num %10;
			Copy_u8Num=Copy_u8Num/10;

		}
		while(Local_u16rev>0)
		{
			LCD_VidSendData(48+(Local_u16rev % 10));
			Local_u16rev=Local_u16rev/10;

		}
		while(i>0)
		{
			LCD_VidSendData('0');
			i--;
		}


	}
}
 *
 *
 * */
/*void LCD_gotorowcolum(u8 copy_u8row, u8 copy_u8colum){

	u8 Address = 0 ;
	switch(copy_u8row)
	{
		case 0:	 Address = copy_u8colum;  break;
		case 1:  Address = copy_u8colum + 0x40;  break;

	}

		LCD_SendCommand(Address |0x80);

}*/



/*
 void LCD_SendString(u8 * Copy_PU8String , u8 Index )
{

u8 iteration = 0 ;
	for (iteration=0; iteration< Index ; iteration++)
		{
		LCD_SendData(Copy_PU8String[iteration]);
		}
	_delay_ms(5);
}*/

/*void LCD_SendString(u8 * Copy_PU8String )
{


	while(*Copy_PU8String!='\0')
		{
		LCD_SendData(*Copy_PU8String);
			Copy_PU8String++;
		}
}*/

/*void LCD_IntegerToString(s32 copy_u8num){
	u32 i, rem, len = 0, n;
	    u8 str[20]={0};

	    n = copy_u8num;
	    while (n != 0)
	    {
	        len++;
	        n /= 10;
	    }
	    for (i = 0; i < len; i++)
	    {
	        rem = copy_u8num % 10;
	        copy_u8num = copy_u8num / 10;
	        str[len - (i + 1)] = rem + '0';
	    }
	    str[len] = '\0';
	    LCD_SendString(str);
}*/
