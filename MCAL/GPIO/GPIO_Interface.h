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

/********************************************************/
/* Define												*/
/*		1) For Port A Pins = (0 : 15)				    */
/*		1) For Port B Pins = (1 : 15)			   	    */
/*		1) For Port C Pins = (13 : 15)				    */
/********************************************************/

#define PIN_HIGH  1
#define PIN_LOW   0

#define Reset	0
#define Set		1

#define PORT_A 1
#define PORT_B 2
#define PORT_C 3

#define PIN_0 0
#define PIN_1 1
#define PIN_2 2
#define PIN_3 3
#define PIN_4 4
#define PIN_5 5
#define PIN_6 6
#define PIN_7 7
#define PIN_8 8
#define PIN_9 9
#define PIN_10 10
#define PIN_11 11
#define PIN_12 12
#define PIN_13 13
#define PIN_14 14
#define PIN_15 15

u8 GPIO_SetPinValue (u8 Port, u8 Pin, u8 Value);

u8 GPIO_FastControlPinValue (u8 Port, u8 Pin, u8 Status);

u8 GPIO_SetPortValue (u8 Port, u8 Value);

u8 GPIO_GetPinValue (u8 Port, u8 Pin, u8* Value);

#endif
