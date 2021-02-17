#ifndef __GIE_INTERFACE__H
#define __GIE_INTERFACE__H

#define SREG 		*((volatile u8*) 0x5F)

void GIE_Enable(void);

void GIE_Disable(void);

#endif
