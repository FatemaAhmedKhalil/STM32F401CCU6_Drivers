/***********************************************************************************************/
/***********************************************************************************************/
/************************************* Author: Fatema Ahmed ************************************/
/***************************************** Layer: HAL ******************************************/
/************************************** Component: Kaypad **************************************/
/***************************************** Version: 1.0 ****************************************/
/***********************************************************************************************/
/***********************************************************************************************/

#include "STD_Types.h"
#include "BitOperations.h"

#include "GPIO_Interface.h"
#include "KPD_Config.h"
#include "KPD_Private.h"
#include "KPD_Interface.h"

u8 KPD_u8GetPressedKey (void)
{
	u8 u8PressedKey = KPD_NoPressedKeys;
	u8 PinState;
	u8 ColumnIndex;
	u8 RowIndex;
	
	static u8 KPD[KPD_ColumnsNumber][KPD_RowsNumber] = KPD_Array;
	
	for (ColumnIndex = 0; ColumnIndex < KPD_ColumnsNumber; ColumnIndex++)
	{
		// Activate Current Column
		GPIO_u8FastControlPinValue (KPD_PORT, KPD_ColumnArray[ColumnIndex], GPIO_LOW);
		
		for (RowIndex = 0; RowIndex < KPD_RowsNumber; RowIndex++)
		{
			// Read the Current Row
			GPIO_u8GetPinValue (KPD_PORT, KPD_RowArray[RowIndex], &PinState);
			
			// Check if the Key is Pressed
			if (PinState == KPD_CheckPreseed)
			{
				u8PressedKey = KPD[ColumnIndex][RowIndex];
				
				// Polling (Busy Waiting) until the key is released
				while(PinState == KPD_CheckPreseed)
						GPIO_u8GetPinValue (KPD_PORT, KPD_RowArray[RowIndex], &PinState);
						
					return u8PressedKey;
			}
		}
		
		// Deactivate Current Column
		GPIO_u8FastControlPinValue (KPD_PORT, KPD_ColumnArray[ColumnIndex], GPIO_HIGH);
	}
	return u8PressedKey;
}
