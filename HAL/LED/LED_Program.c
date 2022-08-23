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
		GPIO_SetPinValue (Led.PORT, Led.PIN, PIN_HIGH);
		
	else if (Led.Connection == Sink)
		GPIO_SetPinValue (Led.PORT, Led.PIN, PIN_LOW);
}

void TurnLEDOFF(LED Led)
{
	if (Led.Connection == Source)
		GPIO_SetPinValue (Led.PORT, Led.PIN, PIN_LOW);
	
	else if (Led.Connection == Sink)
		GPIO_SetPinValue (Led.PORT, Led.PIN, PIN_HIGH);
}
