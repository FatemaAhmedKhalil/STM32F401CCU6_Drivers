/***********************************************************************************************/
/***********************************************************************************************/
/************************************* Author: Fatema Ahmed ************************************/
/***************************************** Layer: HAL ******************************************/
/**************************************** Component: S2P ***************************************/
/***************************************** Version: 1.0 ****************************************/
/***********************************************************************************************/
/***********************************************************************************************/

#include "STD_Types.h"
#include "BitOperations.h"

#include "GPIO_Interface.h"

#include "S2P_Private.h"
#include "S2P_Config.h"
#include "S2P_Interface.h"


void S2P_voidSendData (u32 u32Data, u8 u8PortS2P, u8 u8SerialInPut, u8 u8LatchClk, u8 u8ShiftClk)
{

	GPIO_u8FastControlPinValue (u8PortS2P, u8LatchClk, GPIO_LOW);

	int i=0;
	for (i=0; i<8*S2P_NumberofS2Ps ; i++)
	{
		GPIO_u8FastControlPinValue (u8PortS2P, u8ShiftClk, GPIO_LOW);
		GPIO_u8FastControlPinValue ( u8PortS2P, u8ShiftClk, GET_BIT(u32Data,i) );
		GPIO_u8FastControlPinValue (u8PortS2P, u8ShiftClk, GPIO_HIGH);
	}

	GPIO_u8FastControlPinValue (u8PortS2P, u8LatchClk, GPIO_HIGH);
}
