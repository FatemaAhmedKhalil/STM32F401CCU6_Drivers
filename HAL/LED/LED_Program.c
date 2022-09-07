/***********************************************************************************************/
/***********************************************************************************************/
/************************************* Author: Fatema Ahmed ************************************/
/***************************************** Layer: HAL ******************************************/
/**************************************** Component: LED ***************************************/
/***************************************** Version: 1.0 ****************************************/
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
	if (Led.Connection == LED_Source)
		GPIO_FastControlPinValue (Led.PORT, Led.PIN, Set);
		
	else if (Led.Connection == LED_Sink)
		GPIO_FastControlPinValue (Led.PORT, Led.PIN, Reset);
}

void TurnLEDOFF(LED Led)
{
	if (Led.Connection == LED_Source)
		GPIO_FastControlPinValue (Led.PORT, Led.PIN, Reset);
	
	else if (Led.Connection == LED_Sink)
		GPIO_FastControlPinValue (Led.PORT, Led.PIN, Set);
}
