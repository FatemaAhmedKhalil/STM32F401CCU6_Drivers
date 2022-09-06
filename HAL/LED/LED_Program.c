/***********************************************************************************************/
/***********************************************************************************************/
/************************************* Author: Fatema Ahmed ************************************/
/***************************************** Layer: HAL ******************************************/
/**************************************** Component: LED ***************************************/
/***********************************************************************************************/
/***********************************************************************************************/

#include "STD_Types.h"
#include "BitOperations.h"

#include "GPIO_Interface.h"
#include "LED_Config.h"
#include "LED_Private.h"
#include "LED_Interface.h"

void TurnLEDON(LED Led)
{
	if (Led.Connection == Source)
		GPIO_SetPinValue (Led.PORT, Led.PIN, LED_High);
		
	else if (Led.Connection == Sink)
		GPIO_SetPinValue (Led.PORT, Led.PIN, LED_Low);
}

void TurnLEDOFF(LED Led)
{
	if (Led.Connection == Source)
		GPIO_SetPinValue (Led.PORT, Led.PIN, LED_Low);
	
	else if (Led.Connection == Sink)
		GPIO_SetPinValue (Led.PORT, Led.PIN, LED_High);
}
