/***********************************************************************************************/
/***********************************************************************************************/
/************************************* Author: Fatema Ahmed ************************************/
/***************************************** Layer: HAL ******************************************/
/************************************** Component: 7Segment ************************************/
/***************************************** Version: 1.0 ****************************************/
/***********************************************************************************************/
/***********************************************************************************************/

#ifndef Seg_Interface
#define Seg_Interface

/*************************************************************************************************************************************/
/** Define the Number to Display																									**/
/**																																	**/
/** Define the beginning Pin used in the Port   -->  0 or 1 .... or 6 for Port A || 0 or 1 ..... or 5 or 6 or 7 or 8 for Port B		**/
/**																																	**/
/**	Define The COM Port and Pin used in the Hardware   -->  0 or 2 or 3 or 4 or ........ 14 or 15							  	 	**/
/**																																	**/
/**	Define The Connection Type            -->  COMAnode  or COMCathod																**/
/**																																	**/
/**	1) Common Cathode Connection  --> Connect the COM of the 7 Segment with the Ground	( Signal to Light the LEDs is HIGH )	    **/
/**																																	**/
/**	2) Common Anode Connection   --> Connect the COM of the 7 Segment with the 5 volt		( Signal to Light the LEDs is LOW )		**/
/**																																	**/
/*************************************************************************************************************************************/


/************************************************************************/
/* For Multiplexing 7 Segments:											*/
/*		 Best Presence of Vision POV = 50Hz : 70Hz = 15ms : 20ms		*/
/*					70Hz --> Ghosting									*/
/*					50Hz --> Flickering									*/
/************************************************************************/

#define Seg_PORTA	1
#define Seg_PORTB	2
#define Seg_PORTC	3

#define Seg_PIN0	0
#define Seg_PIN1	1
#define Seg_PIN2	2
#define Seg_PIN3	3
#define Seg_PIN4	4
#define Seg_PIN5	5
#define Seg_PIN6	6
#define Seg_PIN7	7
#define Seg_PIN8	8
#define Seg_PIN9	9
#define Seg_PIN10	10
#define Seg_PIN11	11
#define Seg_PIN12	12
#define Seg_PIN13	13
#define Seg_PIN14	14
#define Seg_PIN15	15

#define Seg_COMAnode	1
#define Seg_COMCathode	0

void Seg_voidDisplaySevenSegment (u8 u8Number, u8 u8PORT, u8 u8PIN_PORT, u8 u8COM_PORT, u8 u8COM_PIN, u8 u8COM_Connection);

#endif
