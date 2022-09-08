/***********************************************************************************************/
/***********************************************************************************************/
/************************************* Author: Fatema Ahmed ************************************/
/***************************************** Layer: MCAL *****************************************/
/***************************************** SWC: SysTick ****************************************/
/***************************************** Version: 1.0 ****************************************/
/***********************************************************************************************/
/***********************************************************************************************/

#include "STD_Types.h"
#include "BitOperations.h"

#include "SysTick_Config.h"
#include "SysTick_Private.h"
#include "SysTick_Register.h"
#include "SysTick_Interface.h"

// Global Pointer to Function to Hold SysTick ISR Address
void (*SysTick_CallBackFunction)(void) = NULL;

static u8 Global_SingleFlag; // Single Interval Flag

void SysTick_Initialization (void)
{
	// Initialize Clock Source
	#if SysTick_ClkSource == 1
		SET_BIT(STK->CTRL, CLKSOURCE);
	#elif SysTick_ClkSource == 0
		CLR_BIT(STK->CTRL, CLKSOURCE);
	#endif
	
	// Counter Enable or Disable
	#if SysTick_Counter == 1
		SET_BIT(STK->CTRL, TICKINT);
	#elif SysTick_ClkSource == 0
		CLR_BIT(STK->CTRL, TICKINT);
	#endif
}

void SysTick_SetBusyWait (u32 Ticks)
{
	// Reset Timer value
	STK->VAL = 0 ;
	// Load Timer with value
	STK->LOAD = Ticks;
	// Start the Timer
	SET_BIT(STK->CTRL, ENABLE);
	
	//  Wait for Timer flag to be Raised
	while( GET_BIT(STK->CTRL, COUNTFLAG) != 1 ) {}
	
	//  Stop the Timer
	CLR_BIT(STK->CTRL, ENABLE);
}

void SysTick_SetInterval_Single (u32 Ticks, void (*SysTickFunction)(void))
{
	// Callback function
	SysTick_CallBackFunction = SysTickFunction;
	Global_SingleFlag = 1; // Single Flag is Set
	
	// Reset Timer value
	STK->VAL = 0;
	
	// Load Timer with value
	STK->LOAD = Ticks;
	
	// Start the Timer
	SET_BIT(STK->CTRL, ENABLE);
}

void SysTick_SetInterval_Periodic (u32 Ticks, void (*SysTickFunction)(void))
{
	// Callback function
	SysTick_CallBackFunction = SysTickFunction;
	Global_SingleFlag = 0; // Single Flag is Cleared
	
	// Reset Timer value
	STK->VAL = 0;
	
	// Load Timer with value
	STK->LOAD = Ticks;
	
	// Start the Timer
	SET_BIT(STK->CTRL, ENABLE);
}

u32  SysTick_GetElapsedTime (void)
{
	return ( (STK->LOAD) - (STK->VAL) );
}

u32  SysTick_GetRemainingTime (void)
{
	return (STK->VAL);
}

/** ISR of SysTick **/
void SysTick_Handler(void)
{
	if(SysTick_CallBackFunction != NULL)
		SysTick_CallBackFunction();
	else
	{
		/* Do Nothing */
	}
		
	if(Global_SingleFlag) // Check if Single Interval
	{
		Global_SingleFlag = 0;
		// Stop the Timer
		CLR_BIT(STK->CTRL, ENABLE);
	}
}