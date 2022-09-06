/***********************************************************************************************/
/***********************************************************************************************/
/************************************* Author: Fatema Ahmed ************************************/
/***************************************** Layer: HAL ******************************************/
/************************************** Component: 7Segment ************************************/
/***********************************************************************************************/
/***********************************************************************************************/


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

#ifndef Seg_Interface
#define Seg_Interface

#define COMAnode	1
#define COMCathode	0

#define SEG_PORTA	 1
#define SEG_PORTB	 2
#define SEG_PORTC	 3

#define SEG_HighValue	1
#define SEG_LowValue	0

void DisplaySevenSegment (u8 Number, u8 PORT, u8 PIN_PORT, u8 COM_PORT, u8 COM_PIN, u8 COM_Connection);

#endif
