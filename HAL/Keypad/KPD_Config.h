/***********************************************************************************************/
/***********************************************************************************************/
/************************************* Author: Fatema Ahmed ************************************/
/***************************************** Layer: HAL ******************************************/
/************************************** Component: Kaypad **************************************/
/***************************************** Version: 1.0 ****************************************/
/***********************************************************************************************/
/***********************************************************************************************/

/****************************************************************/
/* Define The KPD Port		-->		PORT_A or PORT_B		    */
/*																*/
/* Define The KPD Pins for Columns and Rows					    */
/* Define The KPD Values Array					   			    */
/* Define The Initial Value of Keys ( No Press State)		    */
/****************************************************************/

#ifndef KPD_Config
#define KPD_Config

#define KPD_PORTA	1
#define KPD_PORTB	2
#define KPD_PORTC	3

#define KPD_PIN0	0
#define KPD_PIN1	1
#define KPD_PIN2	2
#define KPD_PIN3	3
#define KPD_PIN4	4
#define KPD_PIN5	5
#define KPD_PIN6	6
#define KPD_PIN7	7
#define KPD_PIN8	8
#define KPD_PIN9	9
#define KPD_PIN10	10
#define KPD_PIN11	11
#define KPD_PIN12	12
#define KPD_PIN13	13
#define KPD_PIN14	14
#define KPD_PIN15	15


#define KPD_Array	{{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}}
	
#define KPD_PORT	 KPD_PORTB

#define KPD_Column0PIN	KPD_PIN5
#define KPD_Column1PIN	KPD_PIN2
#define KPD_Column2PIN	KPD_PIN1
#define KPD_Column3PIN	KPD_PIN0

#define KPD_Row0PIN		KPD_PIN6
#define KPD_Row1PIN		KPD_PIN7
#define KPD_Row2PIN		KPD_PIN8
#define KPD_Row3PIN		KPD_PIN9

#endif
