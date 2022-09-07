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

u8 EXTI_EnableTriggerLine (u8 LineID, u8 Trigger)
{
	u8 ErrorState = 0;
	if ( LineID < 16)
	{
		SET_BIT(EXTI->IMR , LineID);
		
		switch (Trigger)
		{
			case EXTI_RisingEdge: SET_BIT(EXTI->RTSR, LineID); CLR_BIT(EXTI->FTSR, LineID); break;
			case EXTI_FallingEdge: CLR_BIT(EXTI->RTSR, LineID); SET_BIT(EXTI->FTSR, LineID); break;
			case EXTI_OnChange: SET_BIT(EXTI->RTSR, LineID); SET_BIT(EXTI->FTSR, LineID); break;
			default: ErrorState = ErrorTriggerSelection;
		}
	}
	else 
		ErrorState = ErrorLineRange;
	
	return ErrorState;
}

u8 EXTI_DisableLine (u8 LineID)
{
	u8 ErrorState = 0;
	if ( LineID < 16)
		CLR_BIT(EXTI->IMR , LineID);
	
	else
		ErrorState = ErrorLineRange;
	
	return ErrorState;
}

u8 EXTI_SoftWareTrigger (u8 LineID)
{
	u8 ErrorState = 0;
	if ( LineID < 16)
		SET_BIT(EXTI->SWIER , LineID);
	
	else
		ErrorState = ErrorLineRange;
	
	return ErrorState;
}

/** Call Back **/
u8 EXTI_CallBack (u8 EXTIn, void (*EXTInFunction)(void))
{
	u8 ErrorSate = 0;
	
	if (EXTInFunction != NULL)
	{
		if (EXTIn == EXTILine0)  // Call Back for EXTI0
			EXTI_EXTI0Function = EXTInFunction;
			
		else if (EXTIn == EXTILine1)  // Call Back for EXTI1
			EXTI_EXTI1Function = EXTInFunction;
		
		else if (EXTIn == EXTILine2)  // Call Back for EXTI2
			EXTI_EXTI2Function = EXTInFunction;
			
		else if (EXTIn == EXTILine3)  // Call Back for EXTI3
			EXTI_EXTI3Function = EXTInFunction;
		
		else if (EXTIn == EXTILine4)  // Call Back for EXTI4
			EXTI_EXTI4Function = EXTInFunction;
		
		else if (EXTIn <= EXTILine9)  // Call Back for EXTI5 : EXTI9
			EXTI_EXTI9_5Function = EXTInFunction;
		
		else if (EXTIn <= EXTILine15)  // Call Back for EXTI10 : EXTI15
			EXTI_EXTI15_10Function = EXTInFunction;
		
		else
			ErrorSate = ErrorEXTI_ID;
	}
	else
		ErrorSate = ErrorEXTI_Function;
	
	return ErrorSate;
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
	SET_BIT(EXTI->PR, EXTILine0); // Clear Flag
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
	SET_BIT(EXTI->PR, EXTILine1); // Clear Flag
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
	SET_BIT(EXTI->PR, EXTILine2); // Clear Flag
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
	SET_BIT(EXTI->PR, EXTILine3); // Clear Flag
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
	SET_BIT(EXTI->PR, EXTILine4); // Clear Flag
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
	SET_BIT(EXTI->PR, EXTILine5); // Clear Flag
	SET_BIT(EXTI->PR, EXTILine6);
	SET_BIT(EXTI->PR, EXTILine7);
	SET_BIT(EXTI->PR, EXTILine8);
	SET_BIT(EXTI->PR, EXTILine9);
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
	SET_BIT(EXTI->PR, EXTILine10); // Clear Flag
	SET_BIT(EXTI->PR, EXTILine11);
	SET_BIT(EXTI->PR, EXTILine12);
	SET_BIT(EXTI->PR, EXTILine13);
	SET_BIT(EXTI->PR, EXTILine14);
	SET_BIT(EXTI->PR, EXTILine15);
}
