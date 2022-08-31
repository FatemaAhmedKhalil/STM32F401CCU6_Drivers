/***********************************************************************************************/
/***********************************************************************************************/
/************************************* Author: Fatema Ahmed ************************************/
/***************************************** Layer: HAL ******************************************/
/*************************************** Component: Switch *************************************/
/***********************************************************************************************/
/***********************************************************************************************/


/*******************************************************************************************************************************/
/** Define The Switch Type		-->		PushButton or ToggleButton or DIPSwitch or LimitSwitch or ReedSwitch or RotarySwitch  **/
/*******************************************************************************************************************************/

#ifndef Switch_Interface
#define Switch_Interface

typedef struct _Switch_ SWITCH;
struct _Switch_
{
	u8 PORT:2;
	u8 PIN:4;
	u8 Type:3;
};


#define PushButton		0
#define ToggleButton	1
#define DIPSwitch		2
#define LimitSwitch		3
#define ReedSwitch		4
#define RotarySwitch	5

u8 PressedButton(SWITCH Switch);

#endif