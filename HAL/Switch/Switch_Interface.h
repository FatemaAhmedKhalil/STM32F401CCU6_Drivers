/***********************************************************************************************/
/***********************************************************************************************/
/************************************* Author: Fatema Ahmed ************************************/
/***************************************** Layer: HAL ******************************************/
/*************************************** Component: Switch *************************************/
/***************************************** Version: 1.0 ****************************************/
/***********************************************************************************************/
/***********************************************************************************************/


/*********************************************************************************************************************************/
/** Define The Port used in the Hardware  -->  GPIO_A or GPIO_B or GPIO_C														**/
/**																																**/
/**	Define The Pin used in the Hardware   -->  PIN0 or PIN1 or PIN2 or PIN3 or .......											**/
/**																																**/
/** Define The Switch Type		-->		PushButton or ToggleButton or DIPSwitch or LimitSwitch or ReedSwitch or RotarySwitch	**/
/*********************************************************************************************************************************/
#ifndef Switch_INTERFACE_H_
#define Switch_INTERFACE_H_

typedef struct _Switch_ SWITCH;
struct _Switch_
{
	u8 PORT:2;
	u8 PIN:4;
	u8 Type:3;
};

#define Switch_PORTA	1
#define Switch_PORTB	2
#define Switch_PORTC	3

#define Switch_PIN0		0
#define Switch_PIN1		1
#define Switch_PIN2		2
#define Switch_PIN3		3
#define Switch_PIN4		4
#define Switch_PIN5		5
#define Switch_PIN6		6
#define Switch_PIN7		7
#define Switch_PIN8		8
#define Switch_PIN9		9
#define Switch_PIN10	10
#define Switch_PIN11	11
#define Switch_PIN12	12
#define Switch_PIN13	13
#define Switch_PIN14	14
#define Switch_PIN15	15

#define PushButton		0
#define ToggleButton	1
#define DIPSwitch		2
#define LimitSwitch		3
#define ReedSwitch		4
#define RotarySwitch	5

u8 Switch_u8PressedButton(SWITCH Switch);
#endif
