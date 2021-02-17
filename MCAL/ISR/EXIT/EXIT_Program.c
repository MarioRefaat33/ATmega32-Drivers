#include"BIT_MATH.h"
#include"DIO_Interface.h"
#include "EXIT_Private.h"
#include"EXIT_Config.h"


void EXIT_Init(void)
{
	#if ISC0== FALLING
	SET_BIT(MCUCR, 1);
	CLR_BIT(MCUCR, 0);
	
	#elif ISC0== RISING
	SET_BIT(MCUCR,1);
	SET_BIT(MCUCR,0);

	#elif ISC0== OCH
	 SET_BIT(MCUCR,1);
	SET_BIT(MCUCR,0);

	#elif ISC0== LOW_LEVEL
	 SET_BIT(MCUCR,1);
	 SET_BIT(MCUCR,0);
	#endif

	#if ISC1== FALLING
	SET_BIT(MCUCR, 1);
	CLR_BIT(MCUCR, 0);

	#elif ISC1== RISING
	SET_BIT(MCUCR,1);
	SET_BIT(MCUCR,0);

	#elif ISC1== OCH
	 SET_BIT(MCUCR,1);
	SET_BIT(MCUCR,0);

	#elif ISC1== LOW_LEVEL
	 SET_BIT(MCUCR,1);
	 SET_BIT(MCUCR,0);
    #endif

	#if ISC2== FALLING
	SET_BIT(MCUCSR, 1);

	#elif ISC2== RISING
	SET_BIT(MCUCSR,1);
	#endif*/
}

void EXIT0_Enable(void)
{
	SET_BIT(GICR, 6);
}

void EXIT0_Disable(void)
{
	CLR_BIT(GICR, 6);
}

void EXIT1_Enable(void)
{
	SET_BIT(GICR, 7);
}

void EXIT1_Disable(void)
{
	CLR_BIT(GICR, 7);
}

void EXIT2_Enable(void)
{
	SET_BIT(GICR, 5);
}

void EXIT2_Disable(void)
{
	CLR_BIT(GICR, 5);
}

void __vector_1(void)
{
	DIO_TogglePin(PORTC,PIN0);
}
