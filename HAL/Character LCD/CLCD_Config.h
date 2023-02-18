/***********************************************************************************************/
/***********************************************************************************************/
/************************************* Author: Fatema Ahmed ************************************/
/***************************************** Layer: HAL ******************************************/
/*************************************** Component: CLCD ***************************************/
/***************************************** Version: 1.0 ****************************************/
/***********************************************************************************************/
/***********************************************************************************************/

#ifndef CLCD_CONFIG_H_
#define CLCD_CONFIG_H_

/********************************************************************************************************************/
/* Define The Data Port and Pins		-->		GPIO_A or GPIO_B													*/
/* Define The Control Port	-->		GPIO_A or GPIO_B or GPIO_C													    */
/* Define The Rs Pin	-->		PIN0 or PIN1 or PIN2 or PIN3 or .........										    */
/* Define The Rw Pin	-->		PIN0 or PIN1 or PIN2 or PIN3 or .........										    */
/* Define The E pin		-->		PIN0 or PIN1 or PIN2 or PIN3 or .........										    */
/*																													*/
/********************************************************************************************************************/
#define CLCD_PORTA	1
#define CLCD_PORTB	2
#define CLCD_PORTC	3

#define CLCD_PIN0	0
#define CLCD_PIN1	1
#define CLCD_PIN2	2
#define CLCD_PIN3	3
#define CLCD_PIN4	4
#define CLCD_PIN5	5
#define CLCD_PIN6	6
#define CLCD_PIN7	7
#define CLCD_PIN8	8
#define CLCD_PIN9	9
#define CLCD_PIN10	10
#define CLCD_PIN11	11
#define CLCD_PIN12	12
#define CLCD_PIN13	13
#define CLCD_PIN14	14
#define CLCD_PIN15	15

/********************************************************/
/* LCD Sending Command Delay must be 2 ms				*/
/*														*/
/* LCD Initialization Delay must be more than 30 ms		*/
/*														*/
/*	**	After Initialize SysTick Driver in ms	**		*/
/********************************************************/
#define LCD_InitializationDelay	40000 
#define LCD_CommandDelay	2000

#define CLCD_DataPort	CLCD_PORTA
#define CLCD_D0			CLCD_PIN0
#define CLCD_D1			CLCD_PIN1
#define CLCD_D2			CLCD_PIN2
#define CLCD_D3			CLCD_PIN3
#define CLCD_D4			CLCD_PIN4
#define CLCD_D5			CLCD_PIN5
#define CLCD_D6			CLCD_PIN6
#define CLCD_D7			CLCD_PIN7

#define CLCD_ControlPort	CLCD_PORTA
#define CLCD_RS				CLCD_PIN8
#define CLCD_RW				CLCD_PIN9
#define CLCD_E				CLCD_PIN10

#endif
