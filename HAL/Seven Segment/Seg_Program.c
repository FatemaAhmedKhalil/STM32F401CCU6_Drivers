/***********************************************************************************************/
/***********************************************************************************************/
/************************************* Author: Fatema Ahmed ************************************/
/***************************************** Layer: HAL ******************************************/
/************************************** Component: 7Segment ************************************/
/***********************************************************************************************/
/***********************************************************************************************/
#include "STD_Types.h"
#include "BitOperations.h"

#include "GPIO_Interface.h"
#include "Seg_Config.h"
#include "Seg_Private.h"
#include "Seg_Interface.h"

void DisplaySevenSegment (u8 Number, u8 PORT, u8 PIN_PORT, u8 COM_PORT, u8 COM_PIN, u8 COM_Connection)
{
	static u8 Seg[SegmentNumbers] = Seg_Array;

	if ( (PORT == SEG_PORTA && PIN_PORT <= 6) || (PORT == SEG_PORTB && PIN_PORT <= 8) )
	{
		if (COM_Connection == COMAnode)	// Common Anode
		{
			GPIO_SetPinValue(COM_PORT, COM_PIN, SEG_HighValue);

			// 8 Pins are ONLY used of the Port
			GPIO_SetPinValue( PORT, PIN_PORT  , !GET_BIT(Seg[Number],0) ); // a
			GPIO_SetPinValue( PORT, PIN_PORT+1, !GET_BIT(Seg[Number],1) ); // b
			GPIO_SetPinValue( PORT, PIN_PORT+2, !GET_BIT(Seg[Number],2) ); // c
			GPIO_SetPinValue( PORT, PIN_PORT+3, !GET_BIT(Seg[Number],3) ); // d
			GPIO_SetPinValue( PORT, PIN_PORT+4, !GET_BIT(Seg[Number],4) ); // e
			GPIO_SetPinValue( PORT, PIN_PORT+5, !GET_BIT(Seg[Number],5) ); // f
			GPIO_SetPinValue( PORT, PIN_PORT+6, !GET_BIT(Seg[Number],6) ); // g
			GPIO_SetPinValue( PORT, PIN_PORT+7, !GET_BIT(Seg[Number],7) ); // .dot
		}

		else if (COM_Connection == COMCathode)	// Common Cathode
		{
			GPIO_SetPinValue(COM_PORT, COM_PIN, SEG_LowValue);

			// 8 Pins are ONLY used of the Port
			GPIO_SetPinValue( PORT, PIN_PORT  , GET_BIT(Seg[Number],0) ); // a
			GPIO_SetPinValue( PORT, PIN_PORT+1, GET_BIT(Seg[Number],1) ); // b
			GPIO_SetPinValue( PORT, PIN_PORT+2, GET_BIT(Seg[Number],2) ); // c
			GPIO_SetPinValue( PORT, PIN_PORT+3, GET_BIT(Seg[Number],3) ); // d
			GPIO_SetPinValue( PORT, PIN_PORT+4, GET_BIT(Seg[Number],4) ); // e
			GPIO_SetPinValue( PORT, PIN_PORT+5, GET_BIT(Seg[Number],5) ); // f
			GPIO_SetPinValue( PORT, PIN_PORT+6, GET_BIT(Seg[Number],6) ); // g
			GPIO_SetPinValue( PORT, PIN_PORT+7, GET_BIT(Seg[Number],7) ); // .dot
		}
	}
}
