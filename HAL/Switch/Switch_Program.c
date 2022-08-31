/***********************************************************************************************/
/***********************************************************************************************/
/************************************* Author: Fatema Ahmed ************************************/
/***************************************** Layer: HAL ******************************************/
/*************************************** Component: Switch *************************************/
/***********************************************************************************************/
/***********************************************************************************************/

#include "STD_Types.h"
#include "BitOperations.h"

#include "GPIO_Interface.h"
#include "Switch_Config.h"
#include "Switch_Private.h"
#include "Switch_Interface.h"

u8 PressedButton(SWITCH Switch)
{
	u8 SwitchState = 0;
	
	if (Switch.Type == PushButton)
		GPIO_GetPinValue (Switch.PORT, Switch.PIN, &SwitchState);
	
	return SwitchState;
}

 u8 Debounce(void)
 {
	 u8 Pressed = 0;
	 static u8 count = 0;
	 static u8 LastState = 1;
	 
	 u8 CurrentState = GET_BIT(PINB,0);
	 
	 if (CurrentState != LastState)
	 {
		 count++;
		 if (count >= 4)
		 {
			 LastState = CurrentState;
			 
			 if (CurrentState != 0)
			 Pressed = 1;

			 count = 0;
		 }
	 }
	 
	 else
	 count = 0;  // Reset counter
	 
	 return Pressed;
 }
