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

u8 GPIO_u8SetPinValue (u8 u8Port, u8 u8Pin, u8 u8Value)
{
	u8 u8ErrorState = 0;
	
	if ( (u8Port == GPIO_PORTA && u8Pin <= GPIO_PIN15 ) || (u8Port == GPIO_PORTB && u8Pin <= GPIO_PIN15 ) || ( u8Port == GPIO_PORTC && ( u8Pin >= GPIO_PIN13 ||  u8Pin <= GPIO_PIN15 ) ) ) // Check Ranges
	{
		if (u8Value == GPIO_LOW) // Low Value means 0 (Clear)
		{
			switch (u8Port)
			{
				case GPIO_PORTA: CLR_BIT(GPIOA->ODR, u8Pin); break;
				case GPIO_PORTB: CLR_BIT(GPIOB->ODR, u8Pin); break;
				case GPIO_PORTC: CLR_BIT(GPIOC->ODR, u8Pin); break;
				default: u8ErrorState = GPIO_ErrorCheckPerphiralRange; break;
			}
		}
		
		else if (u8Value == GPIO_HIGH)	// High Value means 1 (Set)
		{
			switch (u8Port)
			{
				case GPIO_PORTA: SET_BIT(GPIOA->ODR, u8Pin); break;
				case GPIO_PORTB: SET_BIT(GPIOB->ODR, u8Pin); break;
				case GPIO_PORTC: SET_BIT(GPIOC->ODR, u8Pin); break;
				default: u8ErrorState = GPIO_ErrorCheckPerphiralRange; break;
			}
		}
		
		else
		u8ErrorState = GPIO_ErrorPinsOutPut;
	}
	
	else
	u8ErrorState = GPIO_ErrorCheckPerphiralRange;
	
	return u8ErrorState;
}

u8 GPIO_u8FastControlPinValue (u8 u8Port, u8 u8Pin, u8 u8Status)
{
	u8 u8ErrorState = 0;
	
	if ( (u8Port == GPIO_PORTA && u8Pin <= GPIO_PIN15 ) || (u8Port == GPIO_PORTB && u8Pin <= GPIO_PIN15 ) || ( u8Port == GPIO_PORTC && ( u8Pin >= GPIO_PIN13 ||  u8Pin <= GPIO_PIN15 ) ) ) // Check Ranges
	{
		if (u8Status == GPIO_LOW)
		{
			switch (u8Port)
			{
				case GPIO_PORTA: GPIOA->BRR = 1 << u8Pin; break;
				case GPIO_PORTB: GPIOB->BRR = 1 << u8Pin; break;
				case GPIO_PORTC: GPIOC->BRR = 1 << u8Pin; break;
				default: u8ErrorState = GPIO_ErrorCheckPerphiralRange; break;
			}
		}
		
		else if (u8Status == GPIO_HIGH)
		{
			switch (u8Port)
			{
				case GPIO_PORTA: GPIOA->BSR = 1 << u8Pin; break;
				case GPIO_PORTB: GPIOB->BSR = 1 << u8Pin; break;
				case GPIO_PORTC: GPIOC->BSR = 1 << u8Pin; break;
				default: u8ErrorState = GPIO_ErrorCheckPerphiralRange; break;
			}
		}
		
		else
		u8ErrorState = GPIO_ErrorPinsOutPut;
	}
	
	else
	u8ErrorState = GPIO_ErrorCheckPerphiralRange;
	
	return u8ErrorState;
}

u8 GPIO_u8SetPortValue (u8 u8Port, u8 u8Value)
{
	u8 u8ErrorState = 0;
	
	switch (u8Port)
	{
		case GPIO_PORTA: GPIOA->ODR = u8Value; break;
		case GPIO_PORTB: GPIOB->ODR = u8Value; break;
		case GPIO_PORTC: GPIOC->ODR = u8Value; break;
		default: u8ErrorState = GPIO_ErrorCheckPerphiralRange; break;
	}
	
	return u8ErrorState;
}

u8 GPIO_u8GetPinValue (u8 u8Port, u8 u8Pin, u8* pu8Value)
{
	u8 u8ErrorState = 0;
	if ( ( (u8Port == GPIO_PORTA && u8Pin <= GPIO_PIN15 ) || (u8Port == GPIO_PORTB && u8Pin <= GPIO_PIN15 ) || ( u8Port == GPIO_PORTC && ( u8Pin >= GPIO_PIN13 ||  u8Pin <= GPIO_PIN15 ) ) ) && pu8Value != 0 ) // Check Ranges
	{
		switch (u8Port)
		{
			case GPIO_PORTA: *pu8Value = GET_BIT(GPIOA->IDR, u8Pin); break;
			case GPIO_PORTB: *pu8Value = GET_BIT(GPIOB->IDR, u8Pin); break;
			case GPIO_PORTC: *pu8Value = GET_BIT(GPIOC->IDR, u8Pin); break;
			default: u8ErrorState = GPIO_ErrorCheckPerphiralRange; break;
		}
	}
	else
	u8ErrorState = GPIO_ErrorCheckPerphiralRange;
	
	return u8ErrorState;
}

u8 GPIO_u8TogglePinValue(u8 u8Port, u8 u8Pin)
{
	u8 u8ErrorState = 0;
	if ( (u8Port == GPIO_PORTA && u8Pin <= GPIO_PIN15 ) || (u8Port == GPIO_PORTB && u8Pin <= GPIO_PIN15 ) || ( u8Port == GPIO_PORTC && ( u8Pin >= GPIO_PIN13 ||  u8Pin <= GPIO_PIN15 ) ) ) // Check Ranges
	{
		switch(u8Port)
		{
			case GPIO_PORTA : TOG_BIT(GPIOA->ODR,u8Pin); break;
			case GPIO_PORTB : TOG_BIT(GPIOB->ODR,u8Pin); break;
			case GPIO_PORTC : TOG_BIT(GPIOC->ODR,u8Pin); break;
			default: u8ErrorState = GPIO_ErrorCheckPerphiralRange; break;
		}
	}
	else
	u8ErrorState = GPIO_ErrorCheckPerphiralRange;

	return u8ErrorState;
}
