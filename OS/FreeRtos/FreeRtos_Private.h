#ifndef __FREERTOS__PRIVATE__H__
#define __FREERTOS__PRIVATE__H__

#include "STD.h"

typedef struct 
{
	u8 Periodicity ; 
	void(*TaskFunc)(void);
}Task_t ;




#endif