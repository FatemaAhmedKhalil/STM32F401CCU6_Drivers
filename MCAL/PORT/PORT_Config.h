/***********************************************************************************************/
/***********************************************************************************************/
/************************************* Author: Fatema Ahmed ************************************/
/***************************************** Layer: MCAL *****************************************/
/****************************************** SWC: PORT ******************************************/
/***************************************** Version: 1.0 ****************************************/
/***********************************************************************************************/
/***********************************************************************************************/

#ifndef PORT_Config
#define PORT_Config

/****************************************************************/
/* Define Port Mode	(Bit1,Bit0)									*/
/*			00: Input (Reset State)								*/
/*			01: General Purpose Output Mode						*/
/*			10: Alternate Function Mode							*/
/*			11: Analog Mode										*/
/****************************************************************/
	/** Port A Mode Config **/
#define PORTA_Register0_Mode	00
#define PORTA_Register1_Mode	00
#define PORTA_Register2_Mode	00
#define PORTA_Register3_Mode	00
#define PORTA_Register4_Mode	00
#define PORTA_Register5_Mode	00
#define PORTA_Register6_Mode	00
#define PORTA_Register7_Mode	00
#define PORTA_Register8_Mode	00
#define PORTA_Register9_Mode	00
#define PORTA_Register10_Mode	00
#define PORTA_Register11_Mode	00
#define PORTA_Register12_Mode	00
#define	PORTA_Register15_Mode	00	// JTDI

	/** Port B Mode Config **/
#define PORTB_Register0_Mode	00
#define PORTB_Register1_Mode	00
#define PORTB_Register2_Mode	00	// BOOT1
#define PORTB_Register3_Mode	10	// JTDO
#define PORTB_Register4_Mode	10	// JTRST
#define PORTB_Register5_Mode	00
#define PORTB_Register6_Mode	00
#define PORTB_Register7_Mode	00
#define PORTB_Register8_Mode	00
#define PORTB_Register9_Mode	00
#define PORTB_Register10_Mode	00
#define PORTB_Register11_Mode	00 // Not Exist
#define PORTB_Register12_Mode	00
#define PORTB_Register13_Mode	00
#define PORTB_Register14_Mode	00
#define PORTB_Register15_Mode	00

	/** Port C Mode Config **/
#define PORTC_Register13_Mode	00
#define PORTC_Register14_Mode	00
#define PORTC_Register15_Mode	00

/****************************************************************/
/* Define Port Output Type										*/
/*			0: Output Push-Pull									*/
/*			1: Output Open-Drain								*/
/****************************************************************/
/** Port A Output Type Config **/
#define PORTA_Pin0_OutType	0
#define PORTA_Pin1_OutType	0
#define PORTA_Pin2_OutType	0
#define PORTA_Pin3_OutType	0
#define PORTA_Pin4_OutType	0
#define PORTA_Pin5_OutType	0
#define PORTA_Pin6_OutType	0
#define PORTA_Pin7_OutType	0
#define PORTA_Pin8_OutType	0
#define PORTA_Pin9_OutType	0
#define PORTA_Pin10_OutType	0
#define PORTA_Pin11_OutType	0
#define PORTA_Pin12_OutType	0
#define PORTA_Pin15_OutType	0	// JTDI

/** Port B Output Type Config **/
#define PORTB_Pin0_OutType	0
#define PORTB_Pin1_OutType	0
#define PORTB_Pin2_OutType	0	// BOOT1
#define PORTB_Pin3_OutType	0	// JTDO
#define PORTB_Pin4_OutType	0	// JTRST
#define PORTB_Pin5_OutType	0
#define PORTB_Pin6_OutType	0
#define PORTB_Pin7_OutType	0
#define PORTB_Pin8_OutType	0
#define PORTB_Pin9_OutType	0
#define PORTB_Pin10_OutType	0
#define PORTB_Pin11_OutType	0 // Not Exist
#define PORTB_Pin12_OutType	0
#define PORTB_Pin13_OutType	0
#define PORTB_Pin14_OutType	0
#define PORTB_Pin15_OutType	0

/** Port C Output Type Config **/
#define PORTC_Pin13_OutType	0
#define PORTC_Pin14_OutType	0
#define PORTC_Pin15_OutType	0

/****************************************************************/
/* Define Port Output Speed	(Bit1,Bit0)							*/
/*			00: Low Speed										*/
/*			01: Medium speed									*/
/*			10: High speed										*/
/*			11: Very high speed									*/
/****************************************************************/
/** Port A Speed **/
#define PORTA_Register0_Speed	00
#define PORTA_Register1_Speed	00
#define PORTA_Register2_Speed	00
#define PORTA_Register3_Speed	00
#define PORTA_Register4_Speed	00
#define PORTA_Register5_Speed	00
#define PORTA_Register6_Speed	00
#define PORTA_Register7_Speed	00
#define PORTA_Register8_Speed	00
#define PORTA_Register9_Speed	00
#define PORTA_Register10_Speed	00
#define PORTA_Register11_Speed	00
#define PORTA_Register12_Speed	00
#define PORTA_Register15_Speed	00	// JTDI
					   
/** Port B Speed **/   
#define PORTB_Register0_Speed	00
#define PORTB_Register1_Speed	00
#define PORTB_Register2_Speed	00	// BOOT1
#define PORTB_Register3_Speed	11	// JTDO
#define PORTB_Register4_Speed	00	// JTRST
#define PORTB_Register5_Speed	00
#define PORTB_Register6_Speed	00
#define PORTB_Register7_Speed	00
#define PORTB_Register8_Speed	00
#define PORTB_Register9_Speed	00
#define PORTB_Register10_Speed	00
#define PORTB_Register11_Speed	00 // Not Exist
#define PORTB_Register12_Speed	00
#define PORTB_Register13_Speed	00
#define PORTB_Register14_Speed	00
#define PORTB_Register15_Speed	00

/** Port C Speed **/   
#define PORTC_Register13_Speed	00					   
#define PORTC_Register14_Speed	00
#define PORTC_Register15_Speed	00
					   
/********************************************************/
/* Define Port Pull-up/down	(Bit1,Bit0)					*/
/*			00: No Pull-up/Pull-down					*/
/*			01: Pull-up									*/
/*			10: Pull-down								*/
/*			11: Reversed								*/
/********************************************************/
/** Port A Pull-up/Pull-down **/
#define PORTA_Register0_PP	00
#define PORTA_Register1_PP	00
#define PORTA_Register2_PP	00
#define PORTA_Register3_PP	00
#define PORTA_Register4_PP	00				   
#define PORTA_Register5_PP	00					   
#define PORTA_Register6_PP	00					   
#define PORTA_Register7_PP	00					   
#define PORTA_Register8_PP	00					   
#define PORTA_Register9_PP	00					   
#define PORTA_Register10_PP	00					   
#define PORTA_Register11_PP	00
#define PORTA_Register12_PP	00
#define PORTA_Register15_PP	01	// JTDI
					   
/** Port B Pull-up/Pull-down **/
#define PORTB_Register0_PP	00					   
#define PORTB_Register1_PP	00					   
#define PORTB_Register2_PP	00	// BOOT1
#define PORTB_Register3_PP	00	// JTDO
#define PORTB_Register4_PP	01	// JTRST
#define PORTB_Register5_PP	00					   
#define PORTB_Register6_PP	00					   
#define PORTB_Register7_PP	00					   
#define PORTB_Register8_PP	00					   
#define PORTB_Register9_PP	00					   
#define PORTB_Register10_PP	00					   
#define PORTB_Register11_PP	00 // Not Exist					   
#define PORTB_Register12_PP	00					   
#define PORTB_Register13_PP	00					   
#define PORTB_Register14_PP	00					   
#define PORTB_Register15_PP	00
					   
/** Port C Pull-up/Pull-down **/
#define PORTC_Register13_PP	00					   
#define PORTC_Register14_PP	00					   
#define PORTC_Register15_PP	00

/****************************************************************/
/* Define PINS Lock												*/
/*			0: Port configuration not locked					*/
/*			1: Port configuration locked						*/
/*																*/
/*																*/
/* **Don't Forget to Define Lock Sequence '101' on Bit 16**		*/
/*																*/						
/****************************************************************/
/** Port A Lock Config **/
#define PORTA_Pin0_Lock		0
#define PORTA_Pin1_Lock		0
#define PORTA_Pin2_Lock		0
#define PORTA_Pin3_Lock		0
#define PORTA_Pin4_Lock		0
#define PORTA_Pin5_Lock		0
#define PORTA_Pin6_Lock		0
#define PORTA_Pin7_Lock		0
#define PORTA_Pin8_Lock		0
#define PORTA_Pin9_Lock		0
#define PORTA_Pin10_Lock	0
#define PORTA_Pin11_Lock	0
#define PORTA_Pin12_Lock	0
#define PORTA_Pin15_Lock	0	// JTDI

/** Port B Lock Config **/
#define PORTB_Pin0_Lock		0
#define PORTB_Pin1_Lock		0
#define PORTB_Pin2_Lock		0	// BOOT1
#define PORTB_Pin3_Lock		0	// JTDO
#define PORTB_Pin4_Lock		0	// JTRST
#define PORTB_Pin5_Lock		0
#define PORTB_Pin6_Lock		0
#define PORTB_Pin7_Lock		0
#define PORTB_Pin8_Lock		0
#define PORTB_Pin9_Lock		0
#define PORTB_Pin10_Lock	0
#define PORTB_Pin11_Lock	0 // Not Exist
#define PORTB_Pin12_Lock	0
#define PORTB_Pin13_Lock	0
#define PORTB_Pin14_Lock	0
#define PORTB_Pin15_Lock	0

/** Port C Lock Config **/
#define PORTC_Pin13_Lock	0
#define PORTC_Pin14_Lock	0
#define PORTC_Pin15_Lock	0

/********************************************************************/
/* Select Alternative Function										*/
/*		    SYSTEM: AF0			 USART6: AF8						*/
/*		 TIM1/TIM2: AF1			I2C2..3: AF9						*/
/*		   TIM3..5: AF2			 OTG_FS: AF10						*/
/*	      TIM9..11: AF3				   : AF11						*/
/*		   I2C1..3: AF4			   SDIO: AF12						*/
/*		   SPI1..4: AF5				   : AF13						*/
/*			  SPI3: AF6			       : AF14						*/
/*		 USART1..2: AF7		   EVENYOUT: AF15						*/
/********************************************************************/
#define AF0		0000						
#define AF1		0001						
#define AF2		0010						
#define AF3		0011						
#define AF4		0100						
#define AF5		0101						
#define AF6		0110						
#define AF7		0111
#define	AF8		1000
#define	AF9		1001
#define	AF10	1010
#define	AF11	1011
#define	AF12	1100
#define	AF13	1101
#define	AF14	1110
#define	AF15	1111
/****************************************************************/
/* Define PINS Alternative Function	From pin (0:7)				*/
/****************************************************************/
/** Port A Alternative Function Low Pins Config **/
#define PORTA_Pin0_AFL		AF0
#define PORTA_Pin1_AFL		AF0
#define PORTA_Pin2_AFL		AF0
#define PORTA_Pin3_AFL		AF0
#define PORTA_Pin4_AFL		AF0
#define PORTA_Pin5_AFL		AF0
#define PORTA_Pin6_AFL		AF0
#define PORTA_Pin7_AFL		AF0

/** Port B Alternative Function Low Pins Config **/
#define PORTB_Pin0_AFL		AF0
#define PORTB_Pin1_AFL		AF0
#define PORTB_Pin2_AFL		0000	// BOOT1
#define PORTB_Pin3_AFL		0000	// JTDO
#define PORTB_Pin4_AFL		0000	// JTRST
#define PORTB_Pin5_AFL		AF0
#define PORTB_Pin6_AFL		AF0
#define PORTB_Pin7_AFL		AF0

/****************************************************************/
/* Define PINS Alternative Function	From pin (8:15)				*/
/****************************************************************/
/** Port A Alternative Function High Pins Config **/
#define PORTA_Pin8_AFH		AF0
#define PORTA_Pin9_AFH		AF0
#define PORTA_Pin10_AFH		AF0
#define PORTA_Pin11_AFH		AF0
#define PORTA_Pin12_AFH		AF0
#define PORTA_Pin15_AFH		0000	// JTDI

/** Port B Alternative Function High Pins Config **/
#define PORTB_Pin8_AFH		AF0
#define PORTB_Pin9_AFH		AF0
#define PORTB_Pin10_AFH		AF0
#define PORTB_Pin11_AFH		AF0 // Not Exist
#define PORTB_Pin12_AFH		AF0
#define PORTB_Pin13_AFH		AF0
#define PORTB_Pin14_AFH		AF0
#define PORTB_Pin15_AFH		AF0

/** Port C Alternative Function High Pins Config **/
#define PORTC_Pin13_AFH		AF0
#define PORTC_Pin14_AFH		AF0
#define PORTC_Pin15_AFH		AF0
					   
#endif				   
