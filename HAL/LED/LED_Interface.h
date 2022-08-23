/***********************************************************************************************/
/***********************************************************************************************/
/************************************* Author: Fatema Ahmed ************************************/
/***************************************** Layer: HAL ******************************************/
/**************************************** Component: LED ***************************************/
/***********************************************************************************************/
/***********************************************************************************************/


/*************************************************************************************************************************/
/** Define The Port used in the Hardware  -->  PORTA or PORTB or PORTC													**/
/**																														**/
/**	Define The Pin used in the Hardware   -->  PIN0 or PIN1 or PIN2 or PIN3 or .......								    **/
/**																														**/
/**	Define The Connection Type            -->  Source  or Sink								                            **/
/**                                                                                                                     **/
/**	1) Source Connection --> Connect the +ve of the led with the MicroController Pin and the -ve of the led to ground   **/
/**																														**/
/**	2) Sink Connection   --> Connect the -ve of the led with the MicroController Pin and the +ve of the led to 5 volt   **/
/**																														**/
/*************************************************************************************************************************/

#ifndef LED_Interface
#define LED_Interface

typedef struct _LED_ LED;
struct _LED_
{
	u8 PORT:2;
	u8 PIN:4;
	u8 Connection:1;
};

#define Source	1
#define Sink	0

void TurnLEDON(LED Led);
void TurnLEDOFF(LED Led);

#endif
