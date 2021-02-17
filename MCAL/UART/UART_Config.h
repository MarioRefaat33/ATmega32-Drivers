/*
 * UART_Config.h
 *
 *  Created on: Dec 21, 2020
 *      Author: Mario
 */

#ifndef UART_CONFIG_H_
#define UART_CONFIG_H_


#define F_CPU    8000000


#define Asynchronous_Operation 			0
#define synchronous_Operation  		1

#define USART_Mode_Select 			Asynchronous_Operation

#define Disabled_Parity             0
#define Enabled_Even_Parity			1
#define Enabled_Odd_Parity			2

#define Parity_Mode					Disabled_Parity



#define one_bit                     0
#define two_bit						1

#define Stop_Bit_Select   			two_bit



#define bit_5						0
#define bit_6						1
#define bit_7						2
#define bit_8						3
#define bit_9						4

#define Character_Size				bit_8






#endif /* UART_CONFIG_H_ */
