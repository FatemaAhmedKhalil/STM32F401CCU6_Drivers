/***********************************************************************************************/
/***********************************************************************************************/
/************************************* Author: Fatema Ahmed ************************************/
/***************************************** Layer: MCAL *****************************************/
/****************************************** SWC: SPI *******************************************/
/***************************************** Version: 1.0 ****************************************/
/***********************************************************************************************/
/***********************************************************************************************/

#include "STD_Types.h"
#include "BitOperations.h"

#include "SPI_Config.h"
#include "SPI_Private.h"
#include "SPI_Register.h"
#include "SPI_Interface.h"

/**     SPI 1    **/
u8 SPI1_u8Initialization(u8 u8ClkPhase, u8 u8ClkPolarity, u8 u8BaudRate, u8 u8FrameFormat, u8 u8DataFormat , u8 u8Enable)
{
	u8 ErrorState = 0;
	
	// Initialize Baud Rate PreScaler
	SPI1->CR1 |= (u8BaudRate << 3);

	// Initialize SPI Clock Polarity
	if (u8ClkPolarity == SPI_LowIDLE)
	CLR_BIT(SPI1->CR1, CPOL);
	else if (u8ClkPolarity == SPI_HighIDLE)
	SET_BIT(SPI1->CR1, CPOL);
	else
	{
		ErrorState = SPI1_ErrorClkPolarity;
		return ErrorState;
	}

	// Initialize SPI Clock Phase
	if (u8ClkPhase == SPI_LeadingEdge)
	CLR_BIT(SPI1->CR1, CPHA);
	else if (u8ClkPhase == SPI_TrailingEdge)
	SET_BIT(SPI1->CR1, CPHA);
	else
	{
		ErrorState = SPI1_ErrorClkPhase;
		return ErrorState;
	}
	
	// Data Format
	if (u8DataFormat == SPI_Data8Bits)
	CLR_BIT(SPI1->CR1, DFF);
	else if (u8DataFormat == SPI_Data16Bits)
	SET_BIT(SPI1->CR1, DFF);
	else
	{
		ErrorState = SPI1_ErrorDataFormat;
		return ErrorState;
	}
	
	// Initialize Frame Format MSB/LSB first
	if (u8FrameFormat == SPI_MSBTrans)
	CLR_BIT(SPI1->CR1, LSBFIRST);
	else if (u8FrameFormat == SPI_LSBTrans)
	SET_BIT(SPI1->CR1, LSBFIRST);
	else
	{
		ErrorState = SPI1_ErrorFormatTrans;
		return ErrorState;
	}
	
	// Enable/Disable SPI Peripheral
	if (u8Enable == SPI_Disable)
	CLR_BIT(SPI1->CR1, SPE);
	else if (u8Enable == SPI_Enable)
	SET_BIT(SPI1->CR1, SPE);
	else
	{
		ErrorState = SPI1_ErrorEnable;
		return ErrorState;
	}

	return ErrorState;
}

void SPI1_u8MasterMode (void)
{
	SET_BIT(SPI1->CR1, MSTR);
	SET_BIT(SPI1->CR1, SSM);
	SET_BIT(SPI1->CR1, SSI);
}

u8 SPI1_u8SlaveMode (u8 u8SoftSlavManag, u8 u8SlavSelect)
{
	u8 ErrorState = 0;

	// Select Slave Config
	CLR_BIT(SPI1->CR1, MSTR);

	// Software Slave Management
	if (u8SoftSlavManag == SPI_DisSoftSlaveManag)
	CLR_BIT(SPI1->CR1, SSM);
	else if (u8SoftSlavManag == SPI_EnSoftSlaveManag)
	SET_BIT(SPI1->CR1, SSM);
	else
	{
		ErrorState = SPI1_ErrorSlaveSoftwareSelection;
		return ErrorState;
	}

	// Select Slave By Software
	if (u8SlavSelect == SPI_UnSelectSlave)
	CLR_BIT(SPI1->CR1, SSI);
	else if (u8SlavSelect == SPI_SelectSlave)
	SET_BIT(SPI1->CR1, SSI);
	else
	{
		ErrorState = SPI1_ErrorSlaveSoftwareSelection;
		return ErrorState;
	}

	return ErrorState;
}

u16 SPI1_u16Transceive(u16 u16Data)
{
	SPI1->DR = u16Data ;

	while(GET_BIT(SPI1->SR, TXE) == 0) {} // SPI1 is not empty
	while(GET_BIT(SPI1->SR, BSY) == 1) {} // SPI1 is busy in communication or Tx buffer is not empty

	return SPI1->DR ;
}

/**     SPI 2    **/
u8 SPI2_u8Initialization(u8 u8ClkPhase, u8 u8ClkPolarity, u8 u8BaudRate, u8 u8FrameFormat, u8 u8DataFormat , u8 u8Enable)
{
	u8 ErrorState = 0;

	// Initialize Baud Rate PreScaler
	SPI2->CR1 |= (u8BaudRate << 3);

	// Initialize SPI Clock Polarity
	if (u8ClkPolarity == SPI_LowIDLE)
	CLR_BIT(SPI2->CR1, CPOL);
	else if (u8ClkPolarity == SPI_HighIDLE)
	SET_BIT(SPI2->CR1, CPOL);
	else
	{
		ErrorState = SPI2_ErrorClkPolarity;
		return ErrorState;
	}

	// Initialize SPI Clock Phase
	if (u8ClkPhase == SPI_LeadingEdge)
	CLR_BIT(SPI2->CR1, CPHA);
	else if (u8ClkPhase == SPI_TrailingEdge)
	SET_BIT(SPI2->CR1, CPHA);
	else
	{
		ErrorState = SPI2_ErrorClkPhase;
		return ErrorState;
	}

	// Data Format
	if (u8DataFormat == SPI_Data8Bits)
	CLR_BIT(SPI2->CR1, DFF);
	else if (u8DataFormat == SPI_Data16Bits)
	SET_BIT(SPI2->CR1, DFF);
	else
	{
		ErrorState = SPI2_ErrorDataFormat;
		return ErrorState;
	}

	// Initialize Frame Format MSB/LSB first
	if (u8FrameFormat == SPI_MSBTrans)
	CLR_BIT(SPI2->CR1, LSBFIRST);
	else if (u8FrameFormat == SPI_LSBTrans)
	SET_BIT(SPI2->CR1, LSBFIRST);
	else
	{
		ErrorState = SPI2_ErrorFormatTrans;
		return ErrorState;
	}

	// Enable/Disable SPI Peripheral
	if (u8Enable == SPI_Disable)
	CLR_BIT(SPI2->CR1, SPE);
	else if (u8Enable == SPI_Enable)
	SET_BIT(SPI2->CR1, SPE);
	else
	{
		ErrorState = SPI2_ErrorEnable;
		return ErrorState;
	}

	return ErrorState;
}

void SPI2_u8MasterMode (void)
{
	SET_BIT(SPI2->CR1, MSTR);
	SET_BIT(SPI2->CR1, SSM);
	SET_BIT(SPI2->CR1, SSI);
}

u8 SPI2_u8SlaveMode (u8 u8SoftSlavManag, u8 u8SlavSelect)
{
	u8 ErrorState = 0;

	// Select Slave Config
	CLR_BIT(SPI2->CR1, MSTR);

	// Software Slave Management
	if (u8SoftSlavManag == SPI_DisSoftSlaveManag)
	CLR_BIT(SPI2->CR1, SSM);
	else if (u8SoftSlavManag == SPI_EnSoftSlaveManag)
	SET_BIT(SPI2->CR1, SSM);
	else
	{
		ErrorState = SPI2_ErrorSlaveSoftwareSelection;
		return ErrorState;
	}

	// Select Slave By Software
	if (u8SlavSelect == SPI_UnSelectSlave)
	CLR_BIT(SPI2->CR1, SSI);
	else if (u8SlavSelect == SPI_SelectSlave)
	SET_BIT(SPI2->CR1, SSI);
	else
	{
		ErrorState = SPI2_ErrorSlaveSoftwareSelection;
		return ErrorState;
	}

	return ErrorState;
}

u16 SPI2_u16Transceive(u16 u16Data)
{
	SPI2->DR = u16Data ;

	while(GET_BIT(SPI2->SR, TXE) == 0) {} // SPI2 is not empty
	while(GET_BIT(SPI2->SR, BSY) == 1) {} // SPI2 is busy in communication or Tx buffer is not empty

	return SPI2->DR ;
}

/**     SPI 3    **/
u8 SPI3_u8Initialization(u8 u8ClkPhase, u8 u8ClkPolarity, u8 u8BaudRate, u8 u8FrameFormat, u8 u8DataFormat , u8 u8Enable)
{
	u8 ErrorState = 0;

	// Initialize Baud Rate PreScaler
	SPI3->CR1 |= (u8BaudRate << 3);

	// Initialize SPI Clock Polarity
	if (u8ClkPolarity == SPI_LowIDLE)
	CLR_BIT(SPI3->CR1, CPOL);
	else if (u8ClkPolarity == SPI_HighIDLE)
	SET_BIT(SPI3->CR1, CPOL);
	else
	{
		ErrorState = SPI3_ErrorClkPolarity;
		return ErrorState;
	}

	// Initialize SPI Clock Phase
	if (u8ClkPhase == SPI_LeadingEdge)
	CLR_BIT(SPI3->CR1, CPHA);
	else if (u8ClkPhase == SPI_TrailingEdge)
	SET_BIT(SPI3->CR1, CPHA);
	else
	{
		ErrorState = SPI3_ErrorClkPhase;
		return ErrorState;
	}

	// Data Format
	if (u8DataFormat == SPI_Data8Bits)
	CLR_BIT(SPI3->CR1, DFF);
	else if (u8DataFormat == SPI_Data16Bits)
	SET_BIT(SPI3->CR1, DFF);
	else
	{
		ErrorState = SPI3_ErrorDataFormat;
		return ErrorState;
	}

	// Initialize Frame Format MSB/LSB first
	if (u8FrameFormat == SPI_MSBTrans)
	CLR_BIT(SPI3->CR1, LSBFIRST);
	else if (u8FrameFormat == SPI_LSBTrans)
	SET_BIT(SPI3->CR1, LSBFIRST);
	else
	{
		ErrorState = SPI3_ErrorFormatTrans;
		return ErrorState;
	}
	
	// Enable/Disable SPI Peripheral
	if (u8Enable == SPI_Disable)
	CLR_BIT(SPI3->CR1, SPE);
	else if (u8Enable == SPI_Enable)
	SET_BIT(SPI3->CR1, SPE);
	else
	{
		ErrorState = SPI3_ErrorEnable;
		return ErrorState;
	}

	return ErrorState;
}

void SPI3_u8MasterMode (void)
{
	SET_BIT(SPI3->CR1, MSTR);
	SET_BIT(SPI3->CR1, SSM);
	SET_BIT(SPI3->CR1, SSI);
}

u8 SPI3_u8SlaveMode (u8 u8SoftSlavManag, u8 u8SlavSelect)
{
	u8 ErrorState = 0;

	// Select Slave Config
	CLR_BIT(SPI3->CR1, MSTR);

	// Software Slave Management
	if (u8SoftSlavManag == SPI_DisSoftSlaveManag)
	CLR_BIT(SPI3->CR1, SSM);
	else if (u8SoftSlavManag == SPI_EnSoftSlaveManag)
	SET_BIT(SPI3->CR1, SSM);
	else
	{
		ErrorState = SPI3_ErrorSlaveSoftwareSelection;
		return ErrorState;
	}

	// Select Slave By Software
	if (u8SlavSelect == SPI_UnSelectSlave)
	CLR_BIT(SPI3->CR1, SSI);
	else if (u8SlavSelect == SPI_SelectSlave)
	SET_BIT(SPI3->CR1, SSI);
	else
	{
		ErrorState = SPI3_ErrorSlaveSoftwareSelection;
		return ErrorState;
	}

	return ErrorState;
}

u16 SPI3_u16Transceive(u16 u16Data)
{
	SPI3->DR = u16Data ;

	while(GET_BIT(SPI3->SR, TXE) == 0) {} // SPI3 is not empty
	while(GET_BIT(SPI3->SR, BSY) == 1) {} // SPI3 is busy in communication or Tx buffer is not empty

	return SPI3->DR ;
}
