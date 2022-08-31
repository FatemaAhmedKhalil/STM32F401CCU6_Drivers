/***********************************************************************************************/
/***********************************************************************************************/
/************************************* Author: Fatema Ahmed ************************************/
/***************************************** Layer: HAL ******************************************/
/************************************** Component: Kaypad **************************************/
/***********************************************************************************************/
/***********************************************************************************************/

/****************************************************************/
/* Define The KPD Port		-->		PORT_A or PORT_B		    */
/* Define The KPD Pins for Columns and Rows					    */
/* Define The KPD Values Array					   			    */
/* Define The Initial Value of Keys ( No Press State)		    */
/****************************************************************/

#ifndef KPD_Config
#define KPD_Config

#define KPD_PORT	 PORT_B

#define NoPressedKeys	0xff

#define KPD_Array		 {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}}

#define KPD_Column0PIN	PIN_5
#define KPD_Column1PIN	PIN_2
#define KPD_Column2PIN	PIN_1
#define KPD_Column3PIN	PIN_0

#define KPD_Row0PIN		PIN_6
#define KPD_Row1PIN		PIN_7
#define KPD_Row2PIN		PIN_8
#define KPD_Row3PIN		PIN_9

#endif
