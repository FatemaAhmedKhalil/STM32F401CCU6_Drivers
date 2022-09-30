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

void LED_voidTurnON(LED LEDs)
{
	if (LEDs.Connection == LED_Source)
		GPIO_u8FastControlPinValue (LEDs.PORT, LEDs.PIN, GPIO_HIGH);
		
	else if (LEDs.Connection == LED_Sink)
		GPIO_u8FastControlPinValue (LEDs.PORT, LEDs.PIN, GPIO_LOW);
}

void LED_voidTurnOFF(LED LEDs)
{
	if (LEDs.Connection == LED_Source)
		GPIO_u8FastControlPinValue (LEDs.PORT, LEDs.PIN, GPIO_LOW);
	
	else if (LEDs.Connection == LED_Sink)
		GPIO_u8FastControlPinValue (LEDs.PORT, LEDs.PIN, GPIO_HIGH);
}
