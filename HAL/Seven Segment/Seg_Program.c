/***********************************************************************************************/
/***********************************************************************************************/
/************************************* Author: Fatema Ahmed ************************************/
/***************************************** Layer: HAL ******************************************/
/************************************** Component: 7Segment ************************************/
/***************************************** Version: 1.0 ****************************************/
/***********************************************************************************************/
/***********************************************************************************************/
#include "STD_Types.h"
#include "BitOperations.h"

#include "GPIO_Interface.h"
#include "Seg_Config.h"
#include "Seg_Private.h"
#include "Seg_Interface.h"

void Seg_voidDisplaySevenSegment (u8 u8Number, u8 u8PORT, u8 u8PIN_PORT, u8 u8COM_PORT, u8 u8COM_PIN, u8 u8COM_Connection)
{
	static u8 Seg[Seg_SegmentNumbers] = Seg_Array;

	if ( (u8PORT == Seg_PORTA && u8PIN_PORT <= 6) || (u8PORT == Seg_PORTB && u8PIN_PORT <= 8) )
	{
		if (u8COM_Connection == Seg_COMAnode)	// Common Anode
		{
			GPIO_u8SetPinValue(u8COM_PORT, u8COM_PIN, GPIO_HIGH);

			// 8 Pins are ONLY used of the Port
			GPIO_u8SetPinValue( u8PORT, u8PIN_PORT  , !GET_BIT(Seg[u8Number],0) ); // a
			GPIO_u8SetPinValue( u8PORT, u8PIN_PORT+1, !GET_BIT(Seg[u8Number],1) ); // b
			GPIO_u8SetPinValue( u8PORT, u8PIN_PORT+2, !GET_BIT(Seg[u8Number],2) ); // c
			GPIO_u8SetPinValue( u8PORT, u8PIN_PORT+3, !GET_BIT(Seg[u8Number],3) ); // d
			GPIO_u8SetPinValue( u8PORT, u8PIN_PORT+4, !GET_BIT(Seg[u8Number],4) ); // e
			GPIO_u8SetPinValue( u8PORT, u8PIN_PORT+5, !GET_BIT(Seg[u8Number],5) ); // f
			GPIO_u8SetPinValue( u8PORT, u8PIN_PORT+6, !GET_BIT(Seg[u8Number],6) ); // g
			GPIO_u8SetPinValue( u8PORT, u8PIN_PORT+7, !GET_BIT(Seg[u8Number],7) ); // .dot
		}

		else if (u8COM_Connection == Seg_COMCathode)	// Common Cathode
		{
			GPIO_u8SetPinValue(u8COM_PORT, u8COM_PIN, GPIO_LOW);

			// 8 Pins are ONLY used of the Port
			GPIO_u8SetPinValue( u8PORT, u8PIN_PORT  , GET_BIT(Seg[u8Number],0) ); // a
			GPIO_u8SetPinValue( u8PORT, u8PIN_PORT+1, GET_BIT(Seg[u8Number],1) ); // b
			GPIO_u8SetPinValue( u8PORT, u8PIN_PORT+2, GET_BIT(Seg[u8Number],2) ); // c
			GPIO_u8SetPinValue( u8PORT, u8PIN_PORT+3, GET_BIT(Seg[u8Number],3) ); // d
			GPIO_u8SetPinValue( u8PORT, u8PIN_PORT+4, GET_BIT(Seg[u8Number],4) ); // e
			GPIO_u8SetPinValue( u8PORT, u8PIN_PORT+5, GET_BIT(Seg[u8Number],5) ); // f
			GPIO_u8SetPinValue( u8PORT, u8PIN_PORT+6, GET_BIT(Seg[u8Number],6) ); // g
			GPIO_u8SetPinValue( u8PORT, u8PIN_PORT+7, GET_BIT(Seg[u8Number],7) ); // .dot
		}
	}
}
