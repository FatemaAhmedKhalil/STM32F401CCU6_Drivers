/***********************************************************************************************/
/***********************************************************************************************/
/************************************* Author: Fatema Ahmed ************************************/
/***************************************** Layer: MCAL *****************************************/
/***************************************** SWC: SYSCFG *****************************************/
/***************************************** Version: 1.0 ****************************************/
/***********************************************************************************************/
/***********************************************************************************************/

#ifndef SYSCFG_Register
#define SYSCFG_Register

#define SYSCFG_BaseAdress		(u32)(0x40013800)

typedef struct
{
	u32	MEMRMP;		// SYSCFG memory remap register
	u32	PMC;		// SYSCFG peripheral mode configuration register
	u32	EXTICR[4];	// SYSCFG external interrupt configuration registers
	u32	Reserved1;
	u32	Reserved2;
	u32	CMPCR;		// Compensation cell control register
}SYSCFG_MemoryMap;

#define	SYSCFG		( (volatile SYSCFG_MemoryMap *)(SYSCFG_BaseAdress) )


#endif