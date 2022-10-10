/***********************************************************************************************/
/***********************************************************************************************/
/************************************* Author: Fatema Ahmed ************************************/
/***************************************** Layer: MCAL *****************************************/
/****************************************** SWC: SPI *******************************************/
/***************************************** Version: 1.0 ****************************************/
/***********************************************************************************************/
/***********************************************************************************************/

#ifndef SPI_Private
#define SPI_Private

/** CR1 Register Bits **/
#define CPHA		0	// Clock phase
#define CPOL		1	// Clock polarity
#define MSTR		2	// Master selection
#define SPE			6	// SPI enable
#define LSBFIRST	7	// Frame format
#define SSI			8	// Internal slave select
#define SSM			9	// Software slave management
#define RXONLY		10	// Receive only
#define	DFF			11	// Data frame format

/** SP Register Bits **/
#define TXE		1	//	Transmit buffer empty
#define BSY		7	//  Busy flag

#endif