/***********************************************************************************************/
/***********************************************************************************************/
/************************************* Author: Fatema Ahmed ************************************/
/***************************************** Layer: MCAL *****************************************/
/***************************************** SWC: SYSCFG *****************************************/
/***************************************** Version: 1.0 ****************************************/
/***********************************************************************************************/
/***********************************************************************************************/

#ifndef SPI_Interface
#define SPI_Interface

/** Error States **/
#define SPI1_ErrorClkPhase					13
#define SPI1_ErrorClkPolarity				14
#define SPI1_ErrorBaudRate					15
#define SPI1_ErrorFormatTrans				16
#define SPI1_ErrorSlaveSoftwareSelection	17
#define SPI1_ErrorDataFormat				18
#define SPI1_ErrorEnable					19

#define SPI2_ErrorClkPhase					20
#define SPI2_ErrorClkPolarity				21
#define SPI2_ErrorBaudRate					22
#define SPI2_ErrorFormatTrans				23
#define SPI2_ErrorSlaveSoftwareSelection	24
#define SPI2_ErrorDataFormat				25
#define SPI2_ErrorEnable					26

#define SPI3_ErrorClkPhase					27
#define SPI3_ErrorClkPolarity				28
#define SPI3_ErrorBaudRate					29
#define SPI3_ErrorFormatTrans				30
#define SPI3_ErrorSlaveSoftwareSelection	31
#define SPI3_ErrorDataFormat				32
#define SPI3_ErrorEnable					33

/************************************************************/
/* FIRST: Define: Master Mode								*/
/*															*/
/* OR: Define: Slave Mode									*/
/*			1- En/Dis able Slave SoftWare Selection			*/
/*			2- Select/UnSelect The Slave					*/
/* THEN: Initialize:										*/
/*		1- Clock Phase										*/
/*		2- Clock Polarity									*/
/*		3- Clock BaudRate									*/
/*		4- Frame Format										*/
/*		5- Data Format										*/
/*		6- Enable or Disable SPI							*/
/*															*/
/*															*/
/************************************************************/

#define SPI_LeadingEdge    0
#define SPI_TrailingEdge   1

#define SPI_LowIDLE    0
#define SPI_HighIDLE   1

#define SPI_SlaveConfig    0
#define SPI_MasterConfig   1

#define SPI_fPCLK2		0
#define SPI_fPCLK4		1
#define SPI_fPCLK8		2
#define SPI_fPCLK16		3
#define SPI_fPCLK32		4
#define SPI_fPCLK64		5
#define SPI_fPCLK128	6
#define SPI_fPCLK256	7

#define SPI_MSBTrans    0
#define SPI_LSBTrans	1

#define SPI_DisSoftSlaveManag		0
#define SPI_EnSoftSlaveManag		1

#define SPI_UnSelectSlave	0
#define SPI_SelectSlave		1

#define SPI_Data8Bits		0
#define SPI_Data16Bits		1

#define SPI_Disable		0
#define SPI_Enable		1

void SPI1_u8MasterMode (void);
u8 SPI1_u8SlaveMode (u8 u8SoftSlavManag, u8 u8SlavSelect);
u8 SPI1_u8Initialization(u8 u8ClkPhase, u8 u8ClkPolarity, u8 u8BaudRate, u8 u8FrameFormat, u8 u8DataFormat , u8 u8Enable);
u16 SPI1_u16Transceive(u16 u16Data);

void SPI2_u8MasterMode (void);
u8 SPI2_u8SlaveMode (u8 u8SoftSlavManag, u8 u8SlavSelect);
u8 SPI2_u8Initialization(u8 u8ClkPhase, u8 u8ClkPolarity, u8 u8BaudRate, u8 u8FrameFormat, u8 u8DataFormat , u8 u8Enable);
u16 SPI2_u16Transceive(u16 u16Data);

void SPI3_u8MasterMode (void);
u8 SPI3_u8SlaveMode (u8 u8SoftSlavManag, u8 u8SlavSelect);
u8 SPI3_u8Initialization(u8 u8ClkPhase, u8 u8ClkPolarity, u8 u8BaudRate, u8 u8FrameFormat, u8 u8DataFormat , u8 u8Enable);
u16 SPI3_u16Transceive(u16 u16Data);

#endif