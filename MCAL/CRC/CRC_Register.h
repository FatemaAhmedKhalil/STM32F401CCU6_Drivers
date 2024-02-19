/*********************************** Author: Fatema Ahmed **************************************/
/***************************************** Layer: MCAL *****************************************/
/******************************************* SWC: CRC ******************************************/
/**************************************** Version: 1.00 ****************************************/
/*************************************** Date: 29/01/2024 **************************************/
/***********************************************************************************************/
/***********************************************************************************************/

#ifndef CRC_REGISTER_H_
#define CRC_REGISTER_H_

typedef struct
{
	volatile u32 DR;	// Data register
	volatile u32 IDR;	// Independent data register
	volatile u32 CR;	// Control register
}CRC_MemoryMap;

#define	CRC			( (volatile CRC_MemoryMap *)(0x40023000) )

#endif
