/***********************************************************************************************/
/***********************************************************************************************/
/************************************* Author: Fatema Ahmed ************************************/
/***************************************** Layer: MCAL *****************************************/
/****************************************** SWC: NVIC ******************************************/
/***********************************************************************************************/
/***********************************************************************************************/

#include "STD_Types.h"
#include "BitOperations.h"

#include "NVIC_Config.h"
#include "NVIC_Private.h"
#include "NVIC_Register.h"
#include "NVIC_Interface.h"

static u32 GLOBAL_PriorityOption;

void NVIC_EnableInterrupt (u8 InterruptID)
{
	NVIC->ISER[InterruptID/32] = 1 << InterruptID%32;
}
void NVIC_DisableInterrupt (u8 InterruptID)
{
	NVIC->ICER[InterruptID/32] = 1 << InterruptID%32;
}

void NVIC_SetPendingFlag (u8 InterruptID)
{
	NVIC->ISPR[InterruptID/32] = 1 << InterruptID%32;
}

void NVIC_ClearPendingFlag (u8 InterruptID)
{
	NVIC->ICPR[InterruptID/32] = 1 << InterruptID%32;
}

u8 NVIC_GetActiveFlag (u8 InterruptID)
{
	u8 Result = 0;
	Result = GET_BIT( NVIC->IABR[InterruptID/32], InterruptID%32 );
	return Result;
}

u8 NVIC_SetPriority(u8 PRIGROUP, s8 InterruptVectorPosition, u8 GroupPriority, u8 SubPriority)
{
	u8 ErrorState = 0;
	
	/** Check Ranges **/
	if ( PRIGROUP == 0b011 && (GroupPriority > 15 || SubPriority > 0) )
		ErrorState = ErrorGroupsORSubsRange;
		
	else if ( PRIGROUP == 0b100 && (GroupPriority > 7 || SubPriority > 1) )
		ErrorState = ErrorGroupsORSubsRange;
		
	else if ( PRIGROUP == 0b101 && (GroupPriority > 3 || SubPriority > 3) )
		ErrorState = ErrorGroupsORSubsRange;
		
	else if ( PRIGROUP == 0b110 && (GroupPriority > 1 || SubPriority > 7) )
		ErrorState = ErrorGroupsORSubsRange;
		
	else if ( PRIGROUP == 0b111 && (GroupPriority > 0 || SubPriority > 15) )
		ErrorState = ErrorGroupsORSubsRange;
	
	else 
	{
		GLOBAL_PriorityOption = 0x05FA0000 | ( PRIGROUP << 8);
		SCB->AIRCR = GLOBAL_PriorityOption;
		
		u8 Priority = SubPriority | ( GroupPriority << ((GLOBAL_PriorityOption - 0x05FA0300) / 256) );
		
		if (InterruptVectorPosition < 0)	// Core Peripheral
		{
			if (InterruptVectorPosition == NVIC_MemoryManagementFault || InterruptVectorPosition == NVIC_BusFault || InterruptVectorPosition == NVIC_UsageFault)
			{
				InterruptVectorPosition += 3;
				SCB->SHPR1 = (Priority) << ((8 * InterruptVectorPosition) + 4);
			}
			else if (InterruptVectorPosition == NVIC_SVCall)
			{
				InterruptVectorPosition += 7;
				SCB->SHPR2 = (Priority) << ((8 * InterruptVectorPosition) + 4);
			}
			else if (InterruptVectorPosition == NVIC_PendSV || InterruptVectorPosition == NVIC_SysTick)
			{
				InterruptVectorPosition += 8;
				SCB->SHPR3 = (Priority) << ((8 * InterruptVectorPosition) + 4);
			}
		}
	
		else if (InterruptVectorPosition >= 0)	// External Peripheral
		{
			NVIC->IPR[InterruptVectorPosition] = Priority << 4;
		}
	}
	return ErrorState;
}
