/*
**********************************
*	Auther  : Mario Refaat 
*	Date    : 23 / 11 / 2020  
*	version : V1	
**********************************
*/

#ifndef __DIO_INTERFACE_H__
#define __DIO_INTERFACE_H__

#include"STD_TYPES.h"

/* Port Defines */
#define PORTA    0
#define PORTB    1
#define PORTC    2
#define PORTD    3

/* PIN Defines */
#define PIN0   0
#define PIN1   1
#define PIN2   2
#define PIN3   3
#define PIN4   4
#define PIN5   5
#define PIN6   6
#define PIN7   7

/* PIN Directions */
#define INPUT  0
#define OUTPUT 1

/**/
#define HIGH 1
#define LOW  0



void DIO_SetPinDirection  (u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8PinDir);
void DIO_SetPinValue	  (u8 u8PortIdCopy , u8 u8PinIdCopy, u8 u8PinValCopy);


void DIO_SetPortDirection (u8 u8PortId, u8 u8PortDir);
void DIO_SetPortValue     (u8 u8PortId, u8 u8PortVal);

u8 DIO_GetPinValue		  (u8 u8PortIdCopy, u8 u8PinIdCopy);

void DIO_TogglePin        (u8 Copy_U8Port , u8 Copy_U8Pin);

#endif
