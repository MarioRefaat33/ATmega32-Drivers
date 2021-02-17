#include"STD_TYPES.h"
#include"GIE_Interface.h"
#include"BIT_MATH.h"

void GIE_Enable(void)
{
	SET_BIT(SREG,7);
}

void GIE_Disable(void)
{
	CLR_BIT(SREG,7);
}
