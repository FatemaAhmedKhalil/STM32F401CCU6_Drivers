/***********************************************************************************************/
/***********************************************************************************************/
/************************************* Author: Fatema Ahmed ************************************/
/***************************************** Layer: MCAL *****************************************/
/****************************************** SWC: SPI *******************************************/
/***************************************** Version: 1.0 ****************************************/
/***********************************************************************************************/
/***********************************************************************************************/

#ifndef SPI_Register
#define SPI_Register

#define SPI1_BaseAdress		(u32)(0x40013000)
#define SPI2_BaseAdress		(u32)(0x40003800)
#define SPI3_BaseAdress		(u32)(0x40003C00)

typedef struct
{
	u32	CR1;		// SPI control register 1 (not used in I2S mode)
	u32	CR2;		// SPI control register 2
	u32	SR;			// SPI status register
	u32	DR;			// SPI data register
	u32	CRCPR;		// SPI CRC polynomial register (not used in I2S mode)
	u32	RXCRCR;		// SPI RX CRC register (not used in I2S mode)
	u32 TXCRCR;		// SPI TX CRC register (not used in I2S mode)
	u32 I2SCFGR;	// SPI_I2S configuration register
	u32 I2SPR;		// SPI_I2S PreScaler register
}SPI_MemoryMap;

#define	SPI1		( (volatile SPI_MemoryMap *)(SPI1_BaseAdress) )
#define	SPI2		( (volatile SPI_MemoryMap *)(SPI2_BaseAdress) )
#define	SPI3		( (volatile SPI_MemoryMap *)(SPI3_BaseAdress) )

#endif