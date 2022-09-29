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
#define GPIO_ErrorCheckPerphiralRange	4
#define GPIO_ErrorPinsOutPut		5

/********************************************************/
/* Define												*/
/*		1) For Port A Pins = (0 : 15)				    */
/*		2) For Port B Pins = (1 : 15)			   	    */
/*		3) For Port C Pins = (13 : 15)				    */
/********************************************************/
#define GPIO_HIGH  1
#define GPIO_LOW   0

#define GPIO_PORTA	1
#define GPIO_PORTB	2
#define GPIO_PORTC	3

#define GPIO_PIN0	0
#define GPIO_PIN1	1
#define GPIO_PIN2	2
#define GPIO_PIN3	3
#define GPIO_PIN4	4
#define GPIO_PIN5	5
#define GPIO_PIN6	6
#define GPIO_PIN7	7
#define GPIO_PIN8	8
#define GPIO_PIN9	9
#define GPIO_PIN10	10
#define GPIO_PIN11	11
#define GPIO_PIN12	12
#define GPIO_PIN13	13
#define GPIO_PIN14	14
#define GPIO_PIN15	15

u8 GPIO_u8SetPinValue (u8 u8Port, u8 u8Pin, u8 u8Value);

u8 GPIO_u8FastControlPinValue (u8 u8Port, u8 u8Pin, u8 u8Status);

u8 GPIO_u8SetPortValue (u8 u8Port, u8 u8Value);

u8 GPIO_u8GetPinValue (u8 u8Port, u8 u8Pin, u8* pu8Value);

u8 GPIO_u8TogglePinValue(u8 u8Port, u8 u8Pin);

#endif
