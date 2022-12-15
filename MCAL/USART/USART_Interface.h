/***********************************************************************************************/
/***********************************************************************************************/
/************************************* Author: Fatema Ahmed ************************************/
/***************************************** Layer: MCAL *****************************************/
/***************************************** SWC: USART ******************************************/
/***************************************** Version: 1.0 ****************************************/
/***********************************************************************************************/
/***********************************************************************************************/

#ifndef USART_Interface
#define USART_Interface

typedef struct
{
	volatile u32 SR;	// Status register
	volatile u32 DR;	// Data register
	volatile u32 BRR;	// Baud rate register
	volatile u32 CR1;	// Control register 1
	volatile u32 CR2;	// Control register 2
	volatile u32 CR3;	// Control register 3
	volatile u32 GTPR;	// Guard time and PreScaler register
}USART_MemoryMap;

#define	USART1		( ( USART_MemoryMap *)(0x40011000) )
#define	USART2		( ( USART_MemoryMap *)(0x40014400) )
#define	USART6		( ( USART_MemoryMap *)(0x40011400) )
/****************************************************/
/* Define Which USART you will Use:					*/
/*          -> USART1								*/
/*          -> USART2								*/
/*          -> USART6								*/
/****************************************************/

/** Error States **/
#define USART_TimeOut	225

typedef struct
{
	u32 BaudRate;
	u8 DataWidth;
	u8 StopBits;
	u8 Parity_Enable;
	u8 Parity_Selection;
	u8 TransferDirection; // Only Transmitter Or Only Receiver Or Both
	u8 HardwareFlowControl;
	u8 Oversampling;
}USART_Initialization;

typedef struct
{
	u8 ClockEnable;
	u8 ClockPolarity;
	u8 ClockPhase;
	u8 LastBitClockPulse;
}USART_ClockInitialization;


#define USART_OVER_SAMPLING_16	0
#define USART_OVER_SAMPLING_8 	1

#define USART_TX_ONLY		0
#define USART_RX_ONLY		1
#define USART_TX_RX			2

#define USART_EVEN_PARITY         0
#define USART_ODD_PARITY          1

#define USART_MODE_8BIT			0
#define USART_MODE_9BIT			1

#define USART_STOP_BIT_1		0
#define USART_STOP_BIT_0_5		1
#define USART_STOP_BIT_2		2
#define USART_STOP_BIT_1_5		3

#define USART_ClockPolarity_Outside_SteadyLow		0
#define USART_ClockPolarity_Outside_SteadyHigh		1

#define USART_ClockPhase_FirstTransition	0
#define USART_ClockPhase_SecondTransition	1

#define USART_LastBitClkPulse_LastDataNotOutput		0
#define USART_LastBitClkPulse_LastDataIsOutput		1

#define USART_ENABLE		1
#define USART_DISABLE		0

void USART_voidInitialization(USART_Initialization *InitializatioStruct, USART_ClockInitialization *ClockInitializatioStruct, USART_MemoryMap *USARTx);
void USART_Enable(USART_MemoryMap *USARTx);
void USART_Disable(USART_MemoryMap *USARTx);
void USART_voidTransmitByte (USART_MemoryMap *USARTx, u8 u8Byte);
void USART_voidTransmitString (USART_MemoryMap *USARTx, u8 *ptru8String);
u8 USART_u8ReceiveByteSynchNonBlocking (USART_MemoryMap *USARTx);
u8 USART_u8ReceiveByteSynchBlocking ( USART_MemoryMap *USARTx );
void USART_RxInterruptStatus(USART_MemoryMap *USARTx, u8 u8Status);
void USART_voidClearFlags(USART_MemoryMap *USARTx);
u8 USART_u8ReadDataRegister(USART_MemoryMap *USARTx);

/** ********** Call Back Functions ********** **/
void USART1_voidSetCallBack( void (*pvvUSART1Function) (void) );
void USART2_voidSetCallBack( void (*pvvUSART2Function) (void) );
void USART6_voidSetCallBack( void (*pvvUSART6Function) (void) );


#endif
