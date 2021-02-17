#ifndef __EXIT__PRIVATE__H__
#define __EXIT__PRIVATE__H__


#define GICR 		*((volatile u8*) 0x5B)
#define MCUCR  		*((volatile u8*) 0x55)
#define MCUCSR 		*((volatile u8*) 0x54)


void __vector_1(void) __attribute__((signal));  // ISR Code Formal
void __vector_2(void) __attribute__((signal));
void __vector_3(void) __attribute__((signal));



#endif
