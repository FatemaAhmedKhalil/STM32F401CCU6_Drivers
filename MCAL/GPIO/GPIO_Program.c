/***********************************************************************************************/
/***********************************************************************************************/
/************************************* Author: Fatema Ahmed ************************************/
/***************************************** Layer: MCAL *****************************************/
/****************************************** SWC: GPIO ******************************************/
/**************************************** Version: 1.00 ****************************************/
/***********************************************************************************************/
/***********************************************************************************************/

#include "STD_Types.h"
#include "BitOperations.h"

#include "GPIO_Config.h"
#include "GPIO_Private.h"
#include "GPIO_Register.h"
#include "GPIO_Interface.h"

u8 GPIO_SetPinValue (u8 Port, u8 Pin, u8 Value)
{
	u8 ErrorState = 0;
	
	if ( (Port == PORT_A && Pin <= PIN_15 ) || (Port == PORT_B && Pin <= PIN_15 ) || ( Port == PORT_C && ( Pin >= PIN_13 ||  Pin <= PIN_15 ) ) ) // Check Ranges
	{
		if (Value == PIN_LOW) // Low Value means 0 (Clear)
		{
			switch (Port)
			{
				case PORT_A: CLR_BIT(GPIOA->ODR, Pin); break;
				case PORT_B: CLR_BIT(GPIOB->ODR, Pin); break;
				case PORT_C: CLR_BIT(GPIOC->ODR, Pin); break;
				default: ErrorState = 1; break;
			}
		}
		
		else if (Value == PIN_HIGH)	// High Value means 1 (Set)
		{
			switch (Port)
			{
				case PORT_A: SET_BIT(GPIOA->ODR, Pin); break;
				case PORT_B: SET_BIT(GPIOB->ODR, Pin); break;
				case PORT_C: SET_BIT(GPIOC->ODR, Pin); break;
				default: ErrorState = 1; break;
			}
		}
		
		else
		ErrorState = 1;
	}
	
	else
	ErrorState = 1;
	
	return ErrorState;
}

u8 GPIO_FastControlPinValue (u8 Port, u8 Pin, u8 Status)
{
	u8 ErrorState = 0;
	
	if ( (Port == PORT_A && Pin <= PIN_15 ) || (Port == PORT_B && Pin <= PIN_15 ) || ( Port == PORT_C && ( Pin >= PIN_13 ||  Pin <= PIN_15 ) ) ) // Check Ranges
	{
		if (Status == Reset)
		{
			switch (Port)
			{
				case PORT_A: GPIOA->BRR = 1 << Pin; break;
				case PORT_B: GPIOB->BRR = 1 << Pin; break;
				case PORT_C: GPIOC->BRR = 1 << Pin; break;
				default: ErrorState = 1; break;
			}
		}
		
		else if (Status == Set)
		{
			switch (Port)
			{
				case PORT_A: GPIOA->BSR = 1 << Pin; break;
				case PORT_B: GPIOB->BSR = 1 << Pin; break;
				case PORT_C: GPIOC->BSR = 1 << Pin; break;
				default: ErrorState = 1; break;
			}
		}
		
		else
		ErrorState = 1;
	}
	
	else
	ErrorState = 1;
	
	return ErrorState;
}

u8 GPIO_SetPortValue (u8 Port, u8 Value)
{
	u8 ErrorState = 0;
	
	switch (Port)
	{
		case PORT_A: GPIOA->ODR = Value; break;
		case PORT_B: GPIOB->ODR = Value; break;
		case PORT_C: GPIOC->ODR = Value; break;
		default: ErrorState = 1; break;
	}
	
	return ErrorState;
}

u8 GPIO_GetPinValue (u8 Port, u8 Pin, u8* Value)
{
	u8 ErrorState = 0;
	if ( ( (Port == PORT_A && Pin <= PIN_15 ) || (Port == PORT_B && Pin <= PIN_15 ) || ( Port == PORT_C && ( Pin >= PIN_13 ||  Pin <= PIN_15 ) ) ) && Value != 0 ) // Check Ranges
	{
		switch (Port)
		{
			case PORT_A: *Value = GET_BIT(GPIOA->IDR, Pin); break;
			case PORT_B: *Value = GET_BIT(GPIOB->IDR, Pin); break;
			case PORT_C: *Value = GET_BIT(GPIOC->IDR, Pin); break;
			default: ErrorState = 1; break;
		}
	}
	else
	ErrorState = 1;
	
	return ErrorState;
}