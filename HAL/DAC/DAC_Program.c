/***********************************************************************************************/
/***********************************************************************************************/
/************************************* Author: Fatema Ahmed ************************************/
/****************************************** Layer: HAL *****************************************/
/******************************************* SWC: DAC ******************************************/
/***************************************** Version: 1.0 ****************************************/
/***********************************************************************************************/
/***********************************************************************************************/

#include "STD_Types.h"
#include "BitOperations.h"


#include "DAC_Interface.h"
#include "DAC_Private.h"

#include "GPIO_Interface.h"
#include "STK_Interface.h"

u8 Global_DAC_GPIO;

u8 Global_DAC_Bit0;
u8 Global_DAC_Bit1;
u8 Global_DAC_Bit2;
u8 Global_DAC_Bit3;
u8 Global_DAC_Bit4;
u8 Global_DAC_Bit5;
u8 Global_DAC_Bit6;
u8 Global_DAC_Bit7;

u8*Global_SongPointer;
u32 Global_SongLength;

void DAC_voidPlaySong (u8 u8Song[], u32 u32SongLength, u8 u8PortDAC, u8 u8Pin0DAC, u8 u8Pin1DAC, u8 u8Pin2DAC, u8 u8Pin3DAC, u8 u8Pin4DAC, u8 u8Pin5DAC, u8 u8Pin6DAC, u8 u8Pin7DAC, u32 u32SongTickTime)
{
	Global_SongPointer = u8Song;
	Global_SongLength = u32SongLength;
	
	Global_DAC_GPIO = u8PortDAC;
	
	Global_DAC_Bit0 = u8Pin0DAC;
	Global_DAC_Bit1 = u8Pin1DAC;
	Global_DAC_Bit2 = u8Pin2DAC;
	Global_DAC_Bit3 = u8Pin3DAC;
	Global_DAC_Bit4 = u8Pin4DAC;
	Global_DAC_Bit5 = u8Pin5DAC;
	Global_DAC_Bit6 = u8Pin6DAC;
	Global_DAC_Bit7 = u8Pin7DAC;
	
	STK_voidSetInterval_Periodic (u32SongTickTime, DAC_ISR);
}

/** DAC ISR **/
void DAC_ISR(void)
{
	static u32 SongIterator = 0;
	
	GPIO_u8FastControlPinValue (Global_DAC_GPIO, Global_DAC_Bit0, GET_BIT(Global_SongPointer[SongIterator],0) );
	GPIO_u8FastControlPinValue (Global_DAC_GPIO, Global_DAC_Bit1, GET_BIT(Global_SongPointer[SongIterator],1) );
	GPIO_u8FastControlPinValue (Global_DAC_GPIO, Global_DAC_Bit2, GET_BIT(Global_SongPointer[SongIterator],2) );
	GPIO_u8FastControlPinValue (Global_DAC_GPIO, Global_DAC_Bit3, GET_BIT(Global_SongPointer[SongIterator],3) );
	GPIO_u8FastControlPinValue (Global_DAC_GPIO, Global_DAC_Bit4, GET_BIT(Global_SongPointer[SongIterator],4) );
	GPIO_u8FastControlPinValue (Global_DAC_GPIO, Global_DAC_Bit5, GET_BIT(Global_SongPointer[SongIterator],5) );
	GPIO_u8FastControlPinValue (Global_DAC_GPIO, Global_DAC_Bit6, GET_BIT(Global_SongPointer[SongIterator],6) );
	GPIO_u8FastControlPinValue (Global_DAC_GPIO, Global_DAC_Bit7, GET_BIT(Global_SongPointer[SongIterator],7) );

	if ( SongIterator < Global_SongLength )
		SongIterator++;
	else
		SongIterator=0; // Replay the Song
}