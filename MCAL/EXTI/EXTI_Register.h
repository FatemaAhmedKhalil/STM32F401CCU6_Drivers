/***********************************************************************************************/
/***********************************************************************************************/
/************************************* Author: Fatema Ahmed ************************************/
/***************************************** Layer: MCAL *****************************************/
/*********************************** SWC: External Interrupt ***********************************/
/***************************************** Version: 1.0 ****************************************/
/***********************************************************************************************/
/***********************************************************************************************/

#ifndef EXTI_Register
#define EXTI_Register

#define EXTI_BaseAdress			(u32)(0x40013C00)

typedef struct
{
	u32	IMR;		// Interrupt mask register
	u32	EMR;		// Event mask register
	u32	RTSR;		// Rising trigger selection register
	u32	FTSR;		// Falling trigger selection register
	u32	SWIER;		// Software interrupt event register
	u32	PR;			// Pending register
}EXTI_MemoryMap;

#define	EXTI			( (volatile EXTI_MemoryMap *)(EXTI_BaseAdress) )


#endif