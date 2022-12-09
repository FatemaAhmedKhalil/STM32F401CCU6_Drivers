/***********************************************************************************************/
/***********************************************************************************************/
/************************************* Author: Fatema Ahmed ************************************/
/***************************************** Layer: MCAL *****************************************/
/***************************************** SWC: USART ******************************************/
/***************************************** Version: 1.0 ****************************************/
/***********************************************************************************************/
/***********************************************************************************************/

#ifndef USART_Private
#define USART_Private

/* Equation to Get Baud Rate */
#define GetBaudRate(Fpclk, Over8, BaudRate) \
	((Fpclk) / ((8 * (2 - Over8)) * (BaudRate)))

/** SR Register Bits **/
#define PE		0	// Parity error
#define FE		1	// Framing error
#define NE		2	// Noise error flag
#define ORE		3	// Overrun error
#define IDLE	4	// IDLE line detected
#define RXNE	5	// Read data register not empty
#define TC		6	// Transmission complete
#define TXE		7	// Transmit data register empty
#define LBD		8	// LIN break detection flag
#define CTS		9	// CTS flag	


/** CR1 Register Bits **/
#define SBK		0	// Send break	bit
#define RWU		1	// Receiver Wake up	bit
#define RE		2	// Receiver Enable bit
#define TE		3	// Transmitter Enable bit
#define IDLEIE		4	// IDLE interrupt enable bit
#define RXNEIE		5	// RXNEIE interrupt enable bit
#define TCIE		6	// Transmission complete interrupt enable bit
#define TXEIE		7	// TXE interrupt enable bit
#define PEIE		8	// PE interrupt enable bit
#define PS			9	// Parity selection bit
#define PCE			10	// Parity control enable bit
#define WAKE		11	// Wake up method bit
#define M			12	// Word length bit
#define UE			13	// USART enable bit
#define OVER8	    15	// USART Over sampling bit

/** CR2 Register Bits **/
// Address of the USART node bits
#define ADD0		0
#define ADD1		1
#define ADD2		2
#define ADD3		3
	    
#define LBDL		5	// LIN break detection length bit
#define LBDIE		6	// LIN break detection interrupt enable bit
#define LBCL		8	// Last bit clock pulse bit
#define CPHA		9	// Clock phase bit
#define CPOL		10	// Clock polarity bit
#define CLKEN		11	// Clock enable bit
#define STOP		12	// STOP bit start

// STOP bits
#define STOP0	12
#define STOP1	13

#define LINEN	14	// LIN mode enable bit



/** CR3 Register Bits **/
#define CTSIE		10	// CTS interrupt enable bit
#define CTSE		9	// CTS enable bit
#define RTSE		8	// RTS enable bit
#define DMAT		7	// DMA enable transmitter bit
#define DMAR		6	// DMA enable receiver bit
#define SCEN		5	// Smart card mode enable bit
#define NACK		4	// Smart card NACK enable bit
#define HDSEL		3	// Half-duplex selection bit
#define IRLP		2	// IrDA low-power bit
#define IREN		1	// IrDA mode enable bit
#define EIE			0	// Error interrupt enable bit

#endif
