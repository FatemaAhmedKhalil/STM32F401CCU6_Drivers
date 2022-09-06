/***********************************************************************************************/
/***********************************************************************************************/
/************************************* Author: Fatema Ahmed ************************************/
/***************************************** Layer: HAL ******************************************/
/*************************************** Component: CLCD ***************************************/
/***********************************************************************************************/
/***********************************************************************************************/

/********************************************************************************************************************/
/* Define The Data Port and Pins		-->		GPIO_A or GPIO_B													*/
/* Define The Control Port	-->		GPIO_A or GPIO_B or GPIO_C													    */
/* Define The Rs Pin	-->		PIN0 or PIN1 or PIN2 or PIN3 or .........										    */
/* Define The Rw Pin	-->		PIN0 or PIN1 or PIN2 or PIN3 or .........										    */
/* Define The E pin		-->		PIN0 or PIN1 or PIN2 or PIN3 or .........										    */
/*																													*/
/*				** From GPIO Interface **																			*/
/********************************************************************************************************************/

#ifndef CLCD_Config
#define CLCD_Config

#define DataPort GPIO_A
#define CLCD_D0 PIN0
#define CLCD_D1 PIN1
#define CLCD_D2	PIN2
#define CLCD_D3 PIN3
#define CLCD_D4 PIN4
#define CLCD_D5	PIN5
#define CLCD_D6 PIN6
#define CLCD_D7 PIN7

#define ControlPort GPIO_A
#define CLCD_RS PIN8
#define CLCD_RW PIN9
#define CLCD_E	PIN10

#endif
