/***********************************************************************************************/
/***********************************************************************************************/
/************************************* Author: Fatema Ahmed ************************************/
/****************************************** OS Module ******************************************/
/****************************************** SWC: RTOS ******************************************/
/***************************************** Version: 1.0 ****************************************/
/***********************************************************************************************/
/***********************************************************************************************/

#include "STD_Types.h"
#include "BitOperations.h"

#include "STK_Interface.h"

#include "RTOS_Config.h"
#include "RTOS_Private.h"
#include "RTOS_Interface.h"

Task Global_TaskSystemTasks[RTOS_NumberOfTasks] = {0};
u8 Global_u8TaskTiming [RTOS_NumberOfTasks];
Task Global_TaskEmpty = {0};

void RTOS_voidStartOS(u32 u32TasksTickTime)
{
	STK_voidSetInterval_Periodic(u32TasksTickTime, RTOS_voidScheduler);
}

u8 RTOS_u8CreateTask (void(*pvvTaskFunction)(void), u8 u8TaskPeriodicity, u8 u8TaskPriority, u8 u8TaskFirstDelay)
{
	u8 u8ErrorState = 0;
	
	if (u8TaskPriority < RTOS_NumberOfTasks) // Check Priority Range
	{
		if (Global_TaskSystemTasks[u8TaskPriority].TaskHandler == 0)
		{
			Global_TaskSystemTasks[u8TaskPriority].TaskHandler  = pvvTaskFunction;
			Global_TaskSystemTasks[u8TaskPriority].Periodicity  = u8TaskPeriodicity;
			Global_u8TaskTiming [u8TaskPriority] = u8TaskFirstDelay;
			Global_TaskSystemTasks[u8TaskPriority].TaskState = Running;
		}
		
		else
		u8ErrorState = RTOS_ErrorReservedPriority; // The required priority is already reserved
	}
	
	else
	u8ErrorState = RTOS_ErrorPriorityRange; // Wrong priority
	
	return u8ErrorState;
}

void RTOS_voidScheduler(void)
{
	u8 Counter = 0;
	
	for (Counter=0; Counter<RTOS_NumberOfTasks; Counter++) // Loop on all Tasks
	{
		/* Is there a registered task ... ? */
		if (Global_TaskSystemTasks[Counter].TaskHandler != 0)
		{
			if (Global_TaskSystemTasks[Counter].TaskState == Running )
			{
				if (Global_u8TaskTiming[Counter] == 0)
				{
					Global_TaskSystemTasks[Counter].TaskHandler(); // Run the task
					
					Global_u8TaskTiming[Counter] = Global_TaskSystemTasks[Counter].Periodicity; // Reload the Periodicity
				}
				
				else
				Global_u8TaskTiming[Counter]--;
			}
		}
	}
}

u8 RTOS_u8DeleteTask(u8 u8TaskPriority)
{
	u8 u8ErrorState = 0;
	
	if (Global_TaskSystemTasks[u8TaskPriority].TaskHandler != 0) // Check is the Task exists
	Global_TaskSystemTasks[u8TaskPriority] = Global_TaskEmpty; //Execute the Removal
	
	else
	u8ErrorState = RTOS_ErrorTasknotExist; // Task is not exist
	
	return u8ErrorState;
}

u8 RTOS_u8SuspendTask(u8 u8TaskPriority)
{
	u8 u8ErrorState = 0;
	
	if (Global_TaskSystemTasks[u8TaskPriority].TaskHandler != 0) // Check is the Task exists
	Global_TaskSystemTasks[u8TaskPriority].TaskState = Suspended; //Put it in Suspended State
	
	else
	u8ErrorState = RTOS_ErrorTasknotExist; // Task is not exist
	
	return u8ErrorState;
}

u8 RTOS_u8ResumeTask(u8 u8TaskPriority)
{
	u8 u8ErrorState = 0;
	
	if (Global_TaskSystemTasks[u8TaskPriority].TaskHandler != 0) // Check is the Task exists
	Global_TaskSystemTasks[u8TaskPriority].TaskState = Running; //Put it in Running State
	
	else
	u8ErrorState = RTOS_ErrorTasknotExist; // Task is not exist
	
	return u8ErrorState;
}