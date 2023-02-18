/***********************************************************************************************/
/***********************************************************************************************/
/************************************* Author: Fatema Ahmed ************************************/
/***************************************** Layer: HAL ******************************************/
/**************************************** Component: LEDMTX ************************************/
/***************************************** Version: 1.0 ****************************************/
/***********************************************************************************************/
/***********************************************************************************************/

#ifndef LEDMTX_INTERFACE_H_
#define LEDMTX_INTERFACE_H_

/************************************************************/
/*	** Define The Frame of the Matrix **					*/
/*	** Define The Columns Number of the Matrix **			*/
/*	** Define The Rows Number of the Matrix **				*/
/*	** Define The Columns Pins in Array of the Matrix **	*/
/*	** Define The Rows Pins in Array of the Matrix **		*/
/************************************************************/
void LEDMTX_voidDisplayFrame(u8 u8ColumnsNumber, u8 u8RowsNumber , u8 u8ColumnsPINs[], u8 u8RowsPINs[], u8 u8RowsPORT, u8 u8ColumnsPORT, u8 u8Frame[]);

/************************************************************/
/* IF the Method of Connection is S2P Register:				*/
/*	** Define The Columns Number of the Matrix **			*/
/*	** Define The Rows Number of the Matrix **				*/
/*	** Define The S2P Port **								*/
/*	** Define The Serial InPut of S2P Pin **				*/
/*	** Define The Latch Clock of S2P Pin **					*/
/*	** Define The Shift InPuClockt of S2P Pin **			*/
/*	** Define The MSB of the Matrix **						*/
/*	** Define The Frame of the Matrix **					*/
/************************************************************/
#define	LEDMTX_Columns	1
#define	LEDMTX_Rows		2

void LEDMTX_voidDisplayFrame_S2P(u8 u8ColumnsNumber, u8 u8PortS2P, u8 u8SerialInPut, u8 u8LatchClk, u8 u8ShiftClk, u8 u8S2PMSB, u8 u8Frame[]);

//void LEDMTX_DisplayMatrix(u8 Matrix[][ColumnsNumber], u32 MatrixDelay);
void LEDMTX_voidDisableAllColumns(u8 u8ColumnsPORT, u8 u8ColumnsNumber, u8 u8MTXColumns[]);
void LEDMTX_voidSetRowValues(u8 u8RowsPORT, u8 u8RowsNumber, u8 u8MTXRows[], u8 u8RowValue);
void LEDMTX_voidSetCurrentColumn(u8 u8ColumnsPORT, u8 u8CurrentColumns);


#endif
