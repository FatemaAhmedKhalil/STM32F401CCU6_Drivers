/***********************************************************************************************/
/***********************************************************************************************/
/************************************* Author: Fatema Ahmed ************************************/
/***************************************** Layer: MCAL *****************************************/
/***************************************** SWC: SYSCFG *****************************************/
/***********************************************************************************************/
/***********************************************************************************************/

#ifndef SYSCFG_Interface
#define SYSCFG_Interface
/****************************************************************/
/* Define: Selected Line from 0 : 15 for EXTI					*/
/*																*/
/* Define: The Port ID											*/
/*		� PORTA		0000										*/
/*		� PORTB		0001										*/
/*		� PORTC		0010										*/
/****************************************************************/

#define SYSCFG_EXTILine0	0
#define SYSCFG_EXTILine1	1
#define SYSCFG_EXTILine2	2
#define SYSCFG_EXTILine3	3
#define SYSCFG_EXTILine4	4
#define SYSCFG_EXTILine5	5
#define SYSCFG_EXTILine6	6
#define SYSCFG_EXTILine7	7
#define SYSCFG_EXTILine8	8
#define SYSCFG_EXTILine9	9
#define SYSCFG_EXTILine10	10
#define SYSCFG_EXTILine11	11
#define SYSCFG_EXTILine12	12
#define SYSCFG_EXTILine13	13
#define SYSCFG_EXTILine14	14
#define SYSCFG_EXTILine15	15

#define SYSCFG_PORTA	0000
#define SYSCFG_PORTB	0001
#define SYSCFG_PORTC	0010

void SYSCFG_SetPortEXTI(u8 LineID, u8 PortID);

#endif
