/***********************************************************************************************/
/***********************************************************************************************/
/************************************* Author: Fatema Ahmed ************************************/
/***************************************** Layer: HAL ******************************************/
/**************************************** Component: LED ***************************************/
/***************************************** Version: 1.0 ****************************************/
/***********************************************************************************************/
/***********************************************************************************************/


/*************************************************************************************************************************/
/** Define The Port used in the Hardware  -->  GPIO_A or GPIO_B or GPIO_C												**/
/**                                                                                                                     **/
/**	Define The Pin used in the Hardware   -->  PIN0 or PIN1 or PIN2 or PIN3 or .......								    **/
/**                                                                                                                     **/
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

#define LED_PORTA	1
#define LED_PORTB	2
#define LED_PORTC	3

#define LED_PIN0	0
#define LED_PIN1	1
#define LED_PIN2	2
#define LED_PIN3	3
#define LED_PIN4	4
#define LED_PIN5	5
#define LED_PIN6	6
#define LED_PIN7	7
#define LED_PIN8	8
#define LED_PIN9	9
#define LED_PIN10	10
#define LED_PIN11	11
#define LED_PIN12	12
#define LED_PIN13	13
#define LED_PIN14	14
#define LED_PIN15	15

#define LED_Source	1
#define LED_Sink	0

void LED_voidTurnON(LED LEDs);
void LED_voidTurnOFF(LED LEDs);

#endif
