/***********************************************************************************************/
/***********************************************************************************************/
/************************************* Author: Fatema Ahmed ************************************/
/***************************************** Layer: MCAL *****************************************/
/*********************************** SWC: External Interrupt ***********************************/
/***************************************** Version: 1.0 ****************************************/
/***********************************************************************************************/
/***********************************************************************************************/

#ifndef EXTI_Interface
#define EXTI_Interface

/** Error States **/
#define EXTI_ErrorLineRange	7
#define EXTI_ErrorTriggerSelection	8
#define EXTI_ErrorEXTI_ID	9
#define EXTI_ErrorEXTI_Function	10

/****************************************************************************/
/*			** Lines Configuration from SYSCFG Driver **					*/
/*																			*/
/* Define: Selected Line from 0 : 15										*/
/*	The five other EXTI lines are connected as follows:						*/
/*		� EXTI line 16 is connected to the PVD output						*/
/*		� EXTI line 17 is connected to the RTC Alarm event					*/
/*		� EXTI line 18 is connected to the USB OTG FS Wakeup event			*/
/*		� EXTI line 21 is connected to the RTC Tamper and TimeStamp events	*/
/*		� EXTI line 22 is connected to the RTC Wakeup event					*/
/*																			*/
/* Define: Interrupt Trigger												*/
/*		� Rising Edge														*/
/*		� Falling Edge														*/
/*		� Any Change														*/
/****************************************************************************/
#define EXTI_Line0	0
#define EXTI_Line1	1
#define EXTI_Line2	2
#define EXTI_Line3	3
#define EXTI_Line4	4
#define EXTI_Line5	5
#define EXTI_Line6	6
#define EXTI_Line7	7
#define EXTI_Line8	8
#define EXTI_Line9	9
#define EXTI_Line10	10
#define EXTI_Line11	11
#define EXTI_Line12	12
#define EXTI_Line13	13
#define EXTI_Line14	14
#define EXTI_Line15	15

#define EXTI_RisingEdge		1
#define EXTI_FallingEdge	2
#define EXTI_OnChange		3

u8 EXTI_u8EnableTriggerLine (u8 u8LineID, u8 u8Trigger);
u8 EXTI_u8DisableLine (u8 u8LineID);
/**********************/
/* For Software Tests */
/**********************/
u8 EXTI_u8SoftWareTrigger (u8 u8LineID);

/** ********** Call Back Function ********** **/
u8 EXTI_u8CallBack (u8 u8EXTIn, void (*pvvEXTInFunction)(void));
#endif
