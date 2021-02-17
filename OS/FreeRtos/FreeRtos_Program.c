
#include"FreeRtos_Config.h"
#include"FreeRtos_Private.h"





Task_t SysTask[Task_Number]={{NULL}};




void RTOS_CreatTask(u8 Coppy_Periodicity , void(*pfun)(void),u8 Priority)
{
	
	SysTask[Priority].Periodicity=Coppy_Periodicity;
	SysTask[Priority].TaskFunc=pfun;
}