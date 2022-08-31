/***********************************************************************************************/
/***********************************************************************************************/
/************************************* Author: Fatema Ahmed ************************************/
/***************************************** Layer: HAL ******************************************/
/*************************************** Component: CLCD ***************************************/
/***********************************************************************************************/
/***********************************************************************************************/

/************************************************************************************************************************/
/* Define The Data Port and Pins		-->		PORT_A or PORT_B													    */
/* Define The Control Port	-->		PORT_A or PORT_B or PORT_C or PORT_D											    */
/* Define The Rs Pin	-->		PIN_0 or PIN_1 or PIN_2 or PIN_3 or .........										    */
/* Define The Rw Pin	-->		PIN_0 or PIN_1 or PIN_2 or PIN_3 or .........										    */
/* Define The E pin		-->		PIN_0 or PIN_1 or PIN_2 or PIN_3 or .........										    */
/************************************************************************************************************************/

#ifndef CLCD_Config
#define CLCD_Config

#define DataPort PORT_A
#define CLCD_D0 PIN_0
#define CLCD_D1 PIN_1
#define CLCD_D2	PIN_2
#define CLCD_D3 PIN_3
#define CLCD_D4 PIN_4
#define CLCD_D5	PIN_5
#define CLCD_D6 PIN_6
#define CLCD_D7 PIN_7

#define ControlPort PORT_A
#define CLCD_RS PIN_8
#define CLCD_RW PIN_9
#define CLCD_E	PIN_10

#endif
