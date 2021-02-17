/*********************************************************************************/
/* Author    : Mario Refaat	                                                         */
/* Version   : V02                                                               */
/* Date      : 8 DEC 2020                                                       */
/*********************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Interface.h"
#include "SSD_Config.h"



void SEV_SEGDisplay(u8 Coppy_Port , u8 Coppy_Input)
{
	u8 NUMBER[10] = {_0,_1,_2,_3,_4,_5,_6,_7,_8,_9};
	DIO_SetPortValue(Coppy_Port , NUMBER[Coppy_Input]);

}




/*static u8 Disp_Port = 0 ;

void SSD_voidInit( u8 Copy_Port )
{
	DIO_SetPortDirection(Copy_Port , OUTPUT_PORT);
	#if SEVEN_SEG_TYPE == COMMON_CAHODE
	DIO_SetPortValue(Copy_Port ,LOW_PORT);
	#elif SEVEN_SEG_TYPE == COMMON_ANODE
	DIO_SetPortValue(Copy_Port ,HIGH_PORT);
	#endif
}

void SSD_DisplayNumber (u8 Copy_U8Numer)
{
	u8 number[10]={SEG_0, SEG_1, SEG_2, SEG_3, SEG_4, SEG_5, SEG_6, SEG_7, SEG_8, SEG_9};
	DIO_SetPortValue(Disp_Port,number[Copy_U8Numer]);
}*/



/*void SSD_SetDisplayPort (u8 Copy_Port)
{
	Disp_Port =  Copy_Port;
	DIO_SetPortDirection(Copy_Port, OUTPUT);
#if SEVEN_SEG_TYPE == COMMON_CAHODE
	 DIO_SetPortValue(Copy_Port, LOW);
#elif SEVEN_SEG_TYPE == COMMON_ANODE

	 DIO_SetPortValue(Copy_Port, HIGH);
#endif
}*/



// /* Global variables */
// u8 SSD[10]		= {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
//u8 SSD_Pins[7]  = {SSD_A, SSD_B, SSD_C, SSD_D, SSD_E, SSD_F, SSD_G};
// u8 i = 0;

// /* initializing the SSD as output */
// void SSD_voidInit()
// {
	// /* setting the SSD pins as output, and setting the initial value as low */
	// for(i = 0; i<8; i++)
	// {
		// GPIO_voidSetPortDir(SSD_PORT,  OUTPUT);
		// GPIO_voidSetPortVal(SSD_PORT, SSD_COM);
	// }
// }

/* displaying a number on an SSD */
/* void SSD_voidDisplay(u8 Copy_u8Num)
{
	#if (SSD_COM == COM_CATHOD)
		GPIO_voidSetPortVal(SSD_PORT,  SSD[Copy_u8Num]);

	#elif (SSD_COM == COM_ANOD)
		GPIO_voidSetPortVal(SSD_PORT,~(SSD[Copy_u8Num]));

	#endif
} */
