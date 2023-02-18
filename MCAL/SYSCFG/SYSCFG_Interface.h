/***********************************************************************************************/
/***********************************************************************************************/
/************************************* Author: Fatema Ahmed ************************************/
/***************************************** Layer: MCAL *****************************************/
/***************************************** SWC: SYSCFG *****************************************/
/***************************************** Version: 1.0 ****************************************/
/***********************************************************************************************/
/***********************************************************************************************/

#ifndef SYSCFG_INTERFACE_H_
#define SYSCFG_INTERFACE_H_

/** Error States **/
#define SYSCFG_ErrorSYSCFGLineRange	11

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

u8 SYSCFG_u8SetPortEXTI(u8 u8LineID, u8 u8PortID);

#endif
