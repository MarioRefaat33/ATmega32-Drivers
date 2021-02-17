/**
* Auther : Mario Refaat 
* Date   : 30 / 11 / 2020
*
**/

#ifndef __LCD__INTERFACE__H
#define	__LCD__INTERFACE__H


void LCD_Init(void);

void LCD_SendData(u8 Coppy_U8Data);

void LCD_SendCommand(u8 Coppy_U8Comand);

void LCD_SendString(u8 * Copy_PU8String  );

void LCD_SetPosition(u8 Row , u8 Col);

void LCD_DrowChar( u8 Copy_U8ArrLength, u8* Copy_PU8SpecialChar);

void LCD_ClearScreen (void);

void LCD_DrowSpecial( u8 Length,u8* Copy_PU8SpecialChar , u8 ROW , u8 COL);

void LCD_displayStringRowColumn(u8 row,u8 col,const u8 *str) ;

void LCD_1ByteToString(u8 copy_u8num);

void LCD_4ByteToString(u32 copy_u8num);

//void LCD_SendSpecialNumber(s32 Copy_S32Number) ;

//void LCD_Log_PrintNumber(u16 Copy_u16Val);

//void LCD_IntegerToString(s32 copy_u8num) ;

//void LCD_displayStringRowColum(u8 copy_u8row, u8 copy_u8colum, u32 *string);

//void LCD_gotorowcolum(u8 copy_u8row, u8 copy_u8colum);



#define		CLEAR_DISPLAY									0x01

#define 	RETURN_HOME										0x02

#define 	DECREMENT_CURSOR_TO_LEFT						0x04
#define 	INCREMENT_CURSOR_TO_RIGHT						0x06

#define 	SHIFT_DISPLAY_TO_RIGHT							0x05
#define 	SHIFT_DISPLAY_TO_LEFT							0x07


#define 	DISPLAY_OFF_CURSOR_OFF							0x08
#define 	DISPLAY_OFF_CURSOR_ON							0x0A
#define 	DISPLAY_ON_CURSOR_OFF							0x0C
#define 	DISPLAY_ON_CURSOR_BLINK							0x0E


#define 	SHIFT_CURSOR_POSITION_TO_LEFT					0x10
#define 	SHIFT_CURSOR_POSITION_TO_RIGHT					0x14

#define 	SHIFT_ENTRIE_DISPLAY_TO_LEFT					0x18
#define 	SHIFT_ENTRIE_DISPLAY_TO_RIGHT					0x1C

#define 	FORCE_CURSOR_START_FIRST_LINE					0x80
#define 	FORCE_CURSOR_START_SECOND_LINE					0xC0

#define     GO_TO_CGRAM										0x40



#endif
