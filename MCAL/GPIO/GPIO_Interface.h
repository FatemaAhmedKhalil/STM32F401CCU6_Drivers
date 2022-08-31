/***********************************************************************************************/
/***********************************************************************************************/
/************************************* Author: Fatema Ahmed ************************************/
/***************************************** Layer: MCAL *****************************************/
/****************************************** SWC: GPIO ******************************************/
/**************************************** Version: 1.00 ****************************************/
/***********************************************************************************************/
/***********************************************************************************************/

#ifndef GPIO_Interface
#define GPIO_Interface

/** Error States **/
#define ErrorCheckPerphiralRange	4
#define ErrorPinsOutPut		5



/********************************************************/
/* Define												*/
/*		1) For Port A Pins = (0 : 15)				    */
/*		1) For Port B Pins = (1 : 15)			   	    */
/*		1) For Port C Pins = (13 : 15)				    */
/********************************************************/
#define HIGH  1
#define LOW   0

#define Reset	0
#define Set		1

#define PORTA	1
#define PORTB	2
#define PORTC	3

#define PIN0	0
#define PIN1	1
#define PIN2	2
#define PIN3	3
#define PIN4	4
#define PIN5	5
#define PIN6	6
#define PIN7	7
#define PIN8	8
#define PIN9	9
#define PIN10	10
#define PIN11	11
#define PIN12	12
#define PIN13	13
#define PIN14	14
#define PIN15	15

u8 GPIO_SetPinValue (u8 Port, u8 Pin, u8 Value);

u8 GPIO_FastControlPinValue (u8 Port, u8 Pin, u8 Status);

u8 GPIO_SetPortValue (u8 Port, u8 Value);

u8 GPIO_GetPinValue (u8 Port, u8 Pin, u8* Value);

#endif
