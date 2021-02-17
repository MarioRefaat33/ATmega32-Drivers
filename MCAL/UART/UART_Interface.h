/*
 * UART_Interface.h
 *
 *  Created on: Dec 21, 2020
 *      Author: Mario
 */

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_


#include"STD_TYPES.h"

void UART_Init( u32 Copy_U8BoudRate );
void UART_Transmit( u8 Copy_U8Data );
void UART_TransmitString(u8 * Copy_PU8String);
//void UART_Receive(u8 * Copy_U8Data);
void UART_GReceive(u8 * Copy_U8Data);


u8 UART_Receive(void);





#endif /* UART_INTERFACE_H_ */
