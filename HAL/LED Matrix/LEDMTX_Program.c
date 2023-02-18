/***********************************************************************************************/
/***********************************************************************************************/
/************************************* Author: Fatema Ahmed ************************************/
/***************************************** Layer: HAL ******************************************/
/**************************************** Component: LEDMTX ************************************/
/***************************************** Version: 1.0 ****************************************/
/***********************************************************************************************/
/***********************************************************************************************/

#include "STD_Types.h"
#include "BitOperations.h"

#include "GPIO_Interface.h"
#include "STK_Interface.h"

#include "S2P_Interface.h"

#include "LEDMTX_Private.h"
#include "LEDMTX_Config.h"
#include "LEDMTX_Interface.h"

void LEDMTX_voidDisplayFrame(u8 u8ColumnsNumber, u8 u8RowsNumber , u8 u8ColumnsPINs[], u8 u8RowsPINs[], u8 u8RowsPORT, u8 u8ColumnsPORT, u8 u8Frame[])
{
	int i;
	for(i=0; i<u8ColumnsNumber; i++)
	{
		LEDMTX_voidDisableAllColumns(u8ColumnsPORT, u8ColumnsNumber, u8ColumnsPINs); // Disable all Columns
		LEDMTX_voidSetRowValues(u8RowsPORT, u8RowsNumber, u8RowsPINs, u8Frame[i]); // Set Row values
		LEDMTX_voidSetCurrentColumn(u8ColumnsPORT, u8ColumnsPINs[i]); // Set current Column
		STK_voidSetBusyWait(LEDMTX_OneLEDTicks); // Delay for suitable FPS
	}
}

void LEDMTX_voidDisplayFrame_S2P(u8 u8ColumnsNumber, u8 u8PortS2P, u8 u8SerialInPut, u8 u8LatchClk, u8 u8ShiftClk, u8 u8S2PMSB, u8 u8Frame[])
{
	int i;
	for(i=0; i<u8ColumnsNumber; i++)
	{
		if (u8S2PMSB == LEDMTX_Rows)
		{
			u32 Data = 0x00ff ; // Disable all Columns
			S2P_voidSendData (Data, u8PortS2P, u8SerialInPut, u8LatchClk, u8ShiftClk);
			Data =  ( (u8) ~u8Frame[i] ) | ( (1<<i) << 8 ) ; // Set Row values
			S2P_voidSendData (Data, u8PortS2P, u8SerialInPut, u8LatchClk, u8ShiftClk); // Set current Column
		}
		else if (u8S2PMSB == LEDMTX_Columns)
		{
			u32 Data = 0xff00 ; // Disable all Columns
			S2P_voidSendData (Data, u8PortS2P, u8SerialInPut, u8LatchClk, u8ShiftClk);
			Data = ( (u16) ~u8Frame[i] << 8) | (1<<i) ; // Set Row values
			S2P_voidSendData (Data, u8PortS2P, u8SerialInPut, u8LatchClk, u8ShiftClk); // Set current Column
		}

		STK_voidSetBusyWait(LEDMTX_OneLEDTicks); // Delay for suitable FPS
	}
}

void LEDMTX_voidDisableAllColumns(u8 u8ColumnsPORT, u8 u8ColumnsNumber, u8 u8MTXColumns[])
{
	int i = 0;
	for(i=0; i<u8ColumnsNumber; i++)
	GPIO_u8FastControlPinValue (u8ColumnsPORT, u8MTXColumns[i], GPIO_HIGH); // High at Column and Low at Row
}

void LEDMTX_voidSetRowValues(u8 u8RowsPORT, u8 u8RowsNumber, u8 u8MTXRows[], u8 u8RowValue)
{
	int i = 0;
	for(i=0; i<u8RowsNumber; i++)
	GPIO_u8FastControlPinValue ( u8RowsPORT, u8MTXRows[i], GET_BIT(u8RowValue,i) );
}

void LEDMTX_voidSetCurrentColumn(u8 u8ColumnsPORT, u8 u8CurrentColumns)
{
	GPIO_u8FastControlPinValue(u8ColumnsPORT, u8CurrentColumns, GPIO_LOW); // Low at Column and High at Row
}