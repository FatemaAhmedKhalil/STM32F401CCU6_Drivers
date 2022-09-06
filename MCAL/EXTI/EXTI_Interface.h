/***********************************************************************************************/
/***********************************************************************************************/
/************************************* Author: Fatema Ahmed ************************************/
/***************************************** Layer: MCAL *****************************************/
/*********************************** SWC: External Interrupt ***********************************/
/***********************************************************************************************/
/***********************************************************************************************/

#ifndef EXTI_Interface
#define EXTI_Interface

/** Error States **/
#define ErrorLineRange	7
#define ErrorTriggerSelection	8
#define ErrorEXTI_ID	9
#define ErrorEXTI_Function	10

/****************************************************************************/
/* Define: Selected Line from 1 : 16										*/
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
#define EXTILine0	0
#define EXTILine1	1
#define EXTILine2	2
#define EXTILine3	3
#define EXTILine4	4
#define EXTILine5	5
#define EXTILine6	6
#define EXTILine7	7
#define EXTILine8	8
#define EXTILine9	9
#define EXTILine10	10
#define EXTILine11	11
#define EXTILine12	12
#define EXTILine13	13
#define EXTILine14	14
#define EXTILine15	15

#define EXTI_RisingEdge		1
#define EXTI_FallingEdge	2
#define EXTI_OnChange		3

u8 EXTI_EnableTriggerLine (u8 LineID, u8 Trigger);
u8 EXTI_DisableLine (u8 LineID);
/**********************/
/* For Software Tests */
/**********************/
u8 EXTI_SoftWareTrigger (u8 LineID);

/** ********** Call Back Function ********** **/
u8 EXTI_CallBack (u8 EXTIn, void (*EXTInFunction)(void));
#endif
