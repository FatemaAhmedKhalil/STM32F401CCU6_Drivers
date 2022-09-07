/***********************************************************************************************/
/***********************************************************************************************/
/************************************* Author: Fatema Ahmed ************************************/
/***************************************** Layer: MCAL *****************************************/
/****************************************** SWC: PORT ******************************************/
/***************************************** Version: 1.0 ****************************************/
/***********************************************************************************************/
/***********************************************************************************************/

#include "STD_Types.h"
#include "BitOperations.h"

#include "PORT_Config.h"
#include "PORT_Private.h" 
#include "PORT_Register.h"
#include "PORT_Interface.h"

void PORT_Initialliztion (void)
{
	GPIOA->MODER = PORTA_Mode;
	GPIOB->MODER = PORTB_Mode;
	GPIOC->MODER = PORTC_Mode;

	GPIOA->OTYPER = PORTA_OutputType;
	GPIOB->OTYPER = PORTB_OutputType;
	GPIOC->OTYPER = PORTC_OutputType;

	GPIOA->OSPEEDR = PORTA_Speed;
	GPIOB->OSPEEDR = PORTB_Speed;
	GPIOC->OSPEEDR = PORTC_Speed;

	GPIOA->PUPDR = PORTA_PP;
	GPIOB->PUPDR = PORTB_PP;
	GPIOC->PUPDR = PORTC_PP;

	GPIOA->LCKR = PORTA_LOCKER;
	GPIOB->LCKR = PORTB_LOCKER;
	GPIOC->LCKR = PORTC_LOCKER;
	
	GPIOA->AFRH = PORTA_AlternativeHigh;
	GPIOB->AFRH = PORTB_AlternativeHigh;
	GPIOC->AFRH = PORTC_AlternativeHigh;
	
	GPIOA->AFRL = PORTA_AlternativeLow;
	GPIOB->AFRL = PORTB_AlternativeLow;
	GPIOC->AFRL = PORTC_AlternativeLow;
}
