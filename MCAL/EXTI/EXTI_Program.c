/***********************************************************************************************/
/***********************************************************************************************/
/************************************* Author: Fatema Ahmed ************************************/
/***************************************** Layer: MCAL *****************************************/
/*********************************** SWC: External Interrupt ***********************************/
/***************************************** Version: 1.0 ****************************************/
/***********************************************************************************************/
/***********************************************************************************************/

#include "STD_Types.h"
#include "BitOperations.h"

#include "EXTI_Config.h"
#include "EXTI_Private.h"
#include "EXTI_Register.h"
#include "EXTI_Interface.h"

// Global Pointer to Function to Hold EXTI ISR Address
void (*EXTI_EXTI0Function)(void) = NULL;
void (*EXTI_EXTI1Function)(void) = NULL;
void (*EXTI_EXTI2Function)(void) = NULL;
void (*EXTI_EXTI3Function)(void) = NULL;
void (*EXTI_EXTI4Function)(void) = NULL;
void (*EXTI_EXTI9_5Function)(void) = NULL;
void (*EXTI_EXTI15_10Function)(void) = NULL;

u8 EXTI_u8EnableTriggerLine (u8 u8LineID, u8 u8Trigger)
{
	u8 u8ErrorState = 0;
	if ( u8LineID < 16)
	{
		SET_BIT(EXTI->IMR , u8LineID);
		
		switch (u8Trigger)
		{
			case EXTI_RisingEdge: SET_BIT(EXTI->RTSR, u8LineID); CLR_BIT(EXTI->FTSR, u8LineID); break;
			case EXTI_FallingEdge: CLR_BIT(EXTI->RTSR, u8LineID); SET_BIT(EXTI->FTSR, u8LineID); break;
			case EXTI_OnChange: SET_BIT(EXTI->RTSR, u8LineID); SET_BIT(EXTI->FTSR, u8LineID); break;
			default: u8ErrorState = EXTI_ErrorTriggerSelection;
		}
	}
	else 
		u8ErrorState = EXTI_ErrorLineRange;
	
	return u8ErrorState;
}

u8 EXTI_u8DisableLine (u8 u8LineID)
{
	u8 u8ErrorState = 0;
	if ( u8LineID < 16)
		CLR_BIT(EXTI->IMR , u8LineID);
	
	else
		u8ErrorState = EXTI_ErrorLineRange;
	
	return u8ErrorState;
}

u8 EXTI_u8SoftWareTrigger (u8 u8LineID)
{
	u8 u8ErrorState = 0;
	if ( u8LineID < 16)
		SET_BIT(EXTI->SWIER , u8LineID);
	
	else
		u8ErrorState = EXTI_ErrorLineRange;
	
	return u8ErrorState;
}

/** Call Back **/
u8 EXTI_u8CallBack (u8 u8EXTIn, void (*pvvEXTInFunction)(void))
{
	u8 u8ErrorState = 0;
	
	if (pvvEXTInFunction != NULL)
	{
		if (u8EXTIn == EXTI_Line0)  // Call Back for EXTI0
			EXTI_EXTI0Function = pvvEXTInFunction;
			
		else if (u8EXTIn == EXTI_Line1)  // Call Back for EXTI1
			EXTI_EXTI1Function = pvvEXTInFunction;
		
		else if (u8EXTIn == EXTI_Line2)  // Call Back for EXTI2
			EXTI_EXTI2Function = pvvEXTInFunction;
			
		else if (u8EXTIn == EXTI_Line3)  // Call Back for EXTI3
			EXTI_EXTI3Function = pvvEXTInFunction;
		
		else if (u8EXTIn == EXTI_Line4)  // Call Back for EXTI4
			EXTI_EXTI4Function = pvvEXTInFunction;
		
		else if (u8EXTIn <= EXTI_Line9)  // Call Back for EXTI5 : EXTI9
			EXTI_EXTI9_5Function = pvvEXTInFunction;
		
		else if (u8EXTIn <= EXTI_Line15)  // Call Back for EXTI10 : EXTI15
			EXTI_EXTI15_10Function = pvvEXTInFunction;
		
		else
			u8ErrorState = EXTI_ErrorEXTI_ID;
	}
	else
		u8ErrorState = EXTI_ErrorEXTI_Function;
	
	return u8ErrorState;
}

/** ************************************************************************************************ **/
/** ISR of EXTI0 **/
void EXTI0_IRQHandler(void)
{
	if (EXTI_EXTI0Function != NULL)
		EXTI_EXTI0Function();
	
	else
	{
		/* Do Nothing */
	}
	SET_BIT(EXTI->PR, EXTI_Line0); // Clear Flag
}

/** ISR of EXTI1 **/
void EXTI1_IRQHandler(void)
{
	if (EXTI_EXTI1Function != NULL)
		EXTI_EXTI1Function();
	
	else
	{
		/* Do Nothing */
	}
	SET_BIT(EXTI->PR, EXTI_Line1); // Clear Flag
}

/** ISR of EXTI2 **/
void EXTI2_IRQHandler(void)
{
	if (EXTI_EXTI2Function != NULL)
		EXTI_EXTI2Function();
	
	else
	{
		/* Do Nothing */
	}
	SET_BIT(EXTI->PR, EXTI_Line2); // Clear Flag
}

/** ISR of EXTI3 **/
void EXTI3_IRQHandler(void)
{
	if (EXTI_EXTI3Function != NULL)
		EXTI_EXTI3Function();
	
	else
	{
		/* Do Nothing */
	}
	SET_BIT(EXTI->PR, EXTI_Line3); // Clear Flag
}

/** ISR of EXTI4 **/
void EXTI4_IRQHandler(void)
{
	if (EXTI_EXTI4Function != NULL)
		EXTI_EXTI4Function();
	
	else
	{
		/* Do Nothing */
	}
	SET_BIT(EXTI->PR, EXTI_Line4); // Clear Flag
}

/** ISR of EXTI5:9 **/
void EXTI9_5_IRQHandler(void)
{
	if (EXTI_EXTI9_5Function != NULL)
	EXTI_EXTI9_5Function();
	
	else
	{
		/* Do Nothing */
	}
	SET_BIT(EXTI->PR, EXTI_Line5); // Clear Flag
	SET_BIT(EXTI->PR, EXTI_Line6);
	SET_BIT(EXTI->PR, EXTI_Line7);
	SET_BIT(EXTI->PR, EXTI_Line8);
	SET_BIT(EXTI->PR, EXTI_Line9);
}

/** ISR of EXTI10:15 **/
void EXTI15_10_IRQHandler(void)
{
	if (EXTI_EXTI15_10Function != NULL)
	EXTI_EXTI15_10Function();
	
	else
	{
		/* Do Nothing */
	}
	SET_BIT(EXTI->PR, EXTI_Line10); // Clear Flag
	SET_BIT(EXTI->PR, EXTI_Line11);
	SET_BIT(EXTI->PR, EXTI_Line12);
	SET_BIT(EXTI->PR, EXTI_Line13);
	SET_BIT(EXTI->PR, EXTI_Line14);
	SET_BIT(EXTI->PR, EXTI_Line15);
}
