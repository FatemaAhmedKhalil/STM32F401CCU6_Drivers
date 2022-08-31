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
	
	if ( (Port == PORTA && Pin <= PIN15 ) || (Port == PORTB && Pin <= PIN15 ) || ( Port == PORTC && ( Pin >= PIN13 ||  Pin <= PIN15 ) ) ) // Check Ranges
	{
		if (Value == LOW) // Low Value means 0 (Clear)
		{
			switch (Port)
			{
				case PORTA: CLR_BIT(GPIOA->ODR, Pin); break;
				case PORTB: CLR_BIT(GPIOB->ODR, Pin); break;
				case PORTC: CLR_BIT(GPIOC->ODR, Pin); break;
				default: ErrorState = ErrorCheckPerphiralRange; break;
			}
		}
		
		else if (Value == HIGH)	// High Value means 1 (Set)
		{
			switch (Port)
			{
				case PORTA: SET_BIT(GPIOA->ODR, Pin); break;
				case PORTB: SET_BIT(GPIOB->ODR, Pin); break;
				case PORTC: SET_BIT(GPIOC->ODR, Pin); break;
				default: ErrorState = ErrorCheckPerphiralRange; break;
			}
		}
		
		else
		ErrorState = ErrorPinsOutPut;
	}
	
	else
	ErrorState = ErrorCheckPerphiralRange;
	
	return ErrorState;
}

u8 GPIO_FastControlPinValue (u8 Port, u8 Pin, u8 Status)
{
	u8 ErrorState = 0;
	
	if ( (Port == PORTA && Pin <= PIN15 ) || (Port == PORTB && Pin <= PIN15 ) || ( Port == PORTC && ( Pin >= PIN13 ||  Pin <= PIN15 ) ) ) // Check Ranges
	{
		if (Status == Reset)
		{
			switch (Port)
			{
				case PORTA: GPIOA->BRR = 1 << Pin; break;
				case PORTB: GPIOB->BRR = 1 << Pin; break;
				case PORTC: GPIOC->BRR = 1 << Pin; break;
				default: ErrorState = ErrorCheckPerphiralRange; break;
			}
		}
		
		else if (Status == Set)
		{
			switch (Port)
			{
				case PORTA: GPIOA->BSR = 1 << Pin; break;
				case PORTB: GPIOB->BSR = 1 << Pin; break;
				case PORTC: GPIOC->BSR = 1 << Pin; break;
				default: ErrorState = ErrorCheckPerphiralRange; break;
			}
		}
		
		else
		ErrorState = ErrorPinsOutPut;
	}
	
	else
	ErrorState = ErrorCheckPerphiralRange;
	
	return ErrorState;
}

u8 GPIO_SetPortValue (u8 Port, u8 Value)
{
	u8 ErrorState = 0;
	
	switch (Port)
	{
		case PORTA: GPIOA->ODR = Value; break;
		case PORTB: GPIOB->ODR = Value; break;
		case PORTC: GPIOC->ODR = Value; break;
		default: ErrorState = ErrorCheckPerphiralRange; break;
	}
	
	return ErrorState;
}

u8 GPIO_GetPinValue (u8 Port, u8 Pin, u8* Value)
{
	u8 ErrorState = 0;
	if ( ( (Port == PORTA && Pin <= PIN15 ) || (Port == PORTB && Pin <= PIN15 ) || ( Port == PORTC && ( Pin >= PIN13 ||  Pin <= PIN15 ) ) ) && Value != 0 ) // Check Ranges
	{
		switch (Port)
		{
			case PORTA: *Value = GET_BIT(GPIOA->IDR, Pin); break;
			case PORTB: *Value = GET_BIT(GPIOB->IDR, Pin); break;
			case PORTC: *Value = GET_BIT(GPIOC->IDR, Pin); break;
			default: ErrorState = ErrorCheckPerphiralRange; break;
		}
	}
	else
	ErrorState = ErrorCheckPerphiralRange;
	
	return ErrorState;
}