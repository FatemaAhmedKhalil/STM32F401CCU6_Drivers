/***********************************************************************************************/
/***********************************************************************************************/
/************************************* Author: Fatema Ahmed ************************************/
/***************************************** Layer: HAL ******************************************/
/************************************** Component: Kaypad **************************************/
/***************************************** Version: 1.0 ****************************************/
/***********************************************************************************************/
/***********************************************************************************************/

#ifndef KPD_PRIVATE_H_
#define KPD_PRIVATE_H_

#define KPD_ColumnsNumber	4
#define KPD_RowsNumber		4

#define KPD_CheckPreseed	0

static u8 KPD_ColumnArray[KPD_ColumnsNumber] = {KPD_Column0PIN, KPD_Column1PIN, KPD_Column2PIN, KPD_Column3PIN};
static u8 KPD_RowArray[KPD_RowsNumber] = {KPD_Row0PIN, KPD_Row1PIN, KPD_Row2PIN, KPD_Row3PIN};

#endif