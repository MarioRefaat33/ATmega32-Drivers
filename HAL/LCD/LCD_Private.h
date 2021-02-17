
/**
* Auther : Mario Refaat 
* Date   : 30 / 11 / 2020
*
**/

#ifndef  __LCD_PRIVATE__H
#define __LCD_PRIVATE__H



#define EIGHT_BIT_MODE  0
#define FOUR_BIT_MODE   1
#define LCD_MODE EIGHT_BIT_MODE


#define LCD_RS_PORT		PORTA
#define LCD_RS_PIN		PIN2

#define LCD_RW_PORT		PORTA
#define LCD_RW_PIN		PIN1

#define LCD_E_PORT		PORTA
#define LCD_E_PIN		PIN0

#define LCD_DATA_PORT	PORTC
#define LCD_DATA_VALUE  0xff






#endif
