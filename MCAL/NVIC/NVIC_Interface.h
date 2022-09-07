/***********************************************************************************************/
/***********************************************************************************************/
/************************************* Author: Fatema Ahmed ************************************/
/***************************************** Layer: MCAL *****************************************/
/****************************************** SWC: NVIC ******************************************/
/***************************************** Version: 1.0 ****************************************/
/***********************************************************************************************/
/***********************************************************************************************/

#ifndef NVIC_Interface
#define NVIC_Interface

/** Error States **/
#define ErrorGroupsORSubsRange	6

/******************************************/
/* Define: Interrupt ID from Vector Table */
/******************************************/
#define NVIC_PendSV		-6
#define NVIC_SysTick	-5
#define NVIC_SVCall		-4
#define NVIC_MemoryManagementFault	-3
#define NVIC_BusFault	-2
#define NVIC_UsageFault	-1
#define NVIC_WWDG		0
#define NVIC_EXTI16		1
#define NVIC_EXTI21		2
#define NVIC_EXTI22		3
#define NVIC_FLASH		4
#define NVIC_RCC		5
#define NVIC_EXTI0		6
#define NVIC_EXTI1		7
#define NVIC_EXTI2		8
#define NVIC_EXTI3		9
#define NVIC_EXTI4		10
#define NVIC_DMA1_STREAM0	11
#define NVIC_DMA1_STREAM1	12
#define NVIC_DMA1_STREAM2	13
#define NVIC_DMA1_STREAM3	14
#define NVIC_DMA1_STREAM4	15
#define NVIC_DMA1_STREAM5	16
#define NVIC_DMA1_STREAM6	17
#define NVIC_ADC			18
#define NVIC_EXTI9			23
#define NVIC_TIM1_BRK_TIM9	24
#define NVIC_TIM1_UP_TIM10	25
#define NVIC_TIM1_TRG_COM_TIM11	26
#define NVIC_TIM1_CC	27
#define NVIC_TIM2		28
#define NVIC_TIM3		29
#define NVIC_TIM4		30
#define NVIC_I2C1_EV	31
#define NVIC_I2C1_ER	32
#define NVIC_I2C2_EV	33
#define NVIC_I2C2_ER	34
#define NVIC_SPI1		35
#define NVIC_SPI2		36
#define NVIC_USART1		37
#define NVIC_USART2		38
#define NVIC_EXTI15_10	30
#define NVIC_EXTI17		41
#define NVIC_EXTI18		42
#define NVIC_DMA1_STREAM7	47
#define NVIC_SDIO		49
#define NVIC_TIM5		50
#define NVIC_SPI3		51
#define NVIC_DMA2_STREAM0	56
#define NVIC_DMA2_STREAM1	57
#define NVIC_DMA2_STREAM2	58
#define NVIC_DMA2_STREAM3	59
#define NVIC_DMA2_STREAM4	60
#define NVIC_OTG_FS			67
#define NVIC_DMA2_STREAM5	68
#define NVIC_DMA2_STREAM6	69
#define NVIC_DMA2_STREAM7	70
#define NVIC_USART6			71
#define NVIC_I2C3_EV		72
#define NVIC_I2C3_ER		73
#define NVIC_FPU			81
#define NVIC_SPI4			84

void NVIC_EnableInterrupt (u8 InterruptID);
void NVIC_DisableInterrupt (u8 InterruptID);

void NVIC_SetPendingFlag (u8 InterruptID);
void NVIC_ClearPendingFlag (u8 InterruptID);

u8 NVIC_GetActiveFlag (u8 InterruptID);

/****************************************************************************/
/* Define: Priority option													*/
/*			1) Groups16_Subs0												*/
/*			2) Groups8_Subs2												*/
/*			3) Groups4_Subs4												*/
/*			4) Groups2_Subs8												*/
/*			5) Groups0_Subs16												*/
/* Define:																	*/
/*			1) Interrupt Position in Vector Table							*/
/*			2) Group Priority												*/
/*			3) Sub Priority													*/
/*																			*/
/* NOTE : Select Groups and Subs priority which suitable for PRIGROUP		*/
/****************************************************************************/
#define Groups16_Subs0	0b011	// 0b0xx (4 Group Bits + , 0 Sub Bits -) ++++
#define Groups8_Subs2	0b100	// (3 Group Bits + , 1 Sub Bits -) +++-
#define Groups4_Subs4	0b101	// (2 Group Bits + , 2 Sub Bits -) ++--
#define Groups2_Subs8	0b110	// (1 Group Bits + , 3 Sub Bits -) +---
#define	Groups0_Subs16	0b111	// (0 Group Bits + , 4 Sub Bits -) ----

#define GroupPriority0		0
#define GroupPriority1		1
#define GroupPriority2		2
#define GroupPriority3		3
#define GroupPriority4		4
#define GroupPriority5		5
#define GroupPriority6		6
#define GroupPriority7		7
#define GroupPriority8		8
#define GroupPriority9		9
#define GroupPriority10		10
#define GroupPriority11		11
#define GroupPriority12		12
#define GroupPriority13		13
#define GroupPriority14		14
#define GroupPriority15		15

#define SubPriority0		0
#define SubPriority1		1
#define SubPriority2		2
#define SubPriority3		3
#define SubPriority4		4
#define SubPriority5		5
#define SubPriority6		6
#define SubPriority7		7
#define SubPriority8		8
#define SubPriority9		9
#define SubPriority10		10
#define SubPriority11		11
#define SubPriority12		12
#define SubPriority13		13
#define SubPriority14		14
#define SubPriority15		15

u8 NVIC_SetPriority(u8 PRIGROUP, s8 InterruptVectorPosition, u8 GroupPriority, u8 SubPriority);

#endif
