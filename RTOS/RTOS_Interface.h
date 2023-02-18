/***********************************************************************************************/
/***********************************************************************************************/
/************************************* Author: Fatema Ahmed ************************************/
/****************************************** OS Module ******************************************/
/****************************************** SWC: RTOS ******************************************/
/***************************************** Version: 1.0 ****************************************/
/***********************************************************************************************/
/***********************************************************************************************/

#ifndef RTOS_INTERFACE_H_
#define RTOS_INTERFACE_H_

/** Error States **/
#define RTOS_ErrorReservedPriority	12
#define RTOS_ErrorPriorityRange	13
#define RTOS_ErrorTasknotExist	14


void RTOS_voidStartOS(u32 u32TasksTickTime);
u8 RTOS_u8CreateTask (void(*pvvTaskFunction)(void), u8 u8TaskPeriodicity, u8 u8TaskPriority, u8 u8TaskFirstDelay);
void RTOS_voidScheduler(void);
u8 RTOS_u8DeleteTask(u8 u8TaskPriority);
u8 RTOS_u8SuspendTask(u8 u8TaskPriority);
u8 RTOS_u8ResumeTask(u8 u8TaskPriority);


#endif