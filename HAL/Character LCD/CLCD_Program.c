/***********************************************************************************************/
/***********************************************************************************************/
/************************************* Author: Fatema Ahmed ************************************/
/***************************************** Layer: HAL ******************************************/
/*************************************** Component: CLCD ***************************************/
/***************************************** Version: 1.0 ****************************************/
/***********************************************************************************************/
/***********************************************************************************************/

#include "STD_Types.h"
#include "BitOperations.h"

#include "GPIO_Interface.h"
#include "STK_Interface.h"

#include "CLCD_Interface.h"
#include "CLCD_Private.h"
#include "CLCD_Config.h"

u8 u8Global_Counter; // to Count the Number of Characters in the line

void CLCD_voidInitialization (void)
{
	// Wait for more than 30ms
	STK_voidSetBusyWait (LCD_InitializationDelay);
	
	// Function Set Command: 2 Lines(bit 3), 5*7 Font Size(bit 2)
	CLCD_voidSendCommand (0b00111100);
	
	// Display On/Off Control: Display Enable(bit 2), Display Cursor(bit 1), Blink Cursor(bit 0)
	CLCD_voidSendCommand (0b00001111);
	
	// Clear Display
	CLCD_voidSendCommand (0b00000001);
}

void CLCD_voidSendCommand (u8 u8Command)
{
	GPIO_u8FastControlPinValue (CLCD_ControlPort, CLCD_RS, GPIO_LOW);	// Set RS to Low for Command
	GPIO_u8FastControlPinValue (CLCD_ControlPort, CLCD_RW, GPIO_LOW); // Set RS to Low for Write

	// Set Command to Data Pins
	GPIO_u8FastControlPinValue( CLCD_DataPort, CLCD_D0 , GET_BIT(u8Command,0) );
	GPIO_u8FastControlPinValue( CLCD_DataPort, CLCD_D1 , GET_BIT(u8Command,1) );
	GPIO_u8FastControlPinValue( CLCD_DataPort, CLCD_D2 , GET_BIT(u8Command,2) );
	GPIO_u8FastControlPinValue( CLCD_DataPort, CLCD_D3 , GET_BIT(u8Command,3) );
	GPIO_u8FastControlPinValue( CLCD_DataPort, CLCD_D4 , GET_BIT(u8Command,4) );
	GPIO_u8FastControlPinValue( CLCD_DataPort, CLCD_D5 , GET_BIT(u8Command,5) );
	GPIO_u8FastControlPinValue( CLCD_DataPort, CLCD_D6 , GET_BIT(u8Command,6) );
	GPIO_u8FastControlPinValue( CLCD_DataPort, CLCD_D7 , GET_BIT(u8Command,7) );
	
	// Send Enable Pulse
	GPIO_u8FastControlPinValue (CLCD_ControlPort, CLCD_E, GPIO_HIGH);
	
	STK_voidSetBusyWait (LCD_CommandDelay);
	
	GPIO_u8FastControlPinValue (CLCD_ControlPort, CLCD_E, GPIO_LOW);
}

void CLCD_voidSendData (u8 u8Data)
{
	u8Global_Counter = 0;
	GPIO_u8FastControlPinValue (CLCD_ControlPort, CLCD_RS, GPIO_HIGH); // Set RS to High for Data
	GPIO_u8FastControlPinValue (CLCD_ControlPort, CLCD_RW, GPIO_LOW); // Set RS to Low for Write

	// Set Data to Data Pins
	GPIO_u8FastControlPinValue( CLCD_DataPort, CLCD_D0 , GET_BIT(u8Data,0) );
	GPIO_u8FastControlPinValue( CLCD_DataPort, CLCD_D1 , GET_BIT(u8Data,1) );
	GPIO_u8FastControlPinValue( CLCD_DataPort, CLCD_D2 , GET_BIT(u8Data,2) );
	GPIO_u8FastControlPinValue( CLCD_DataPort, CLCD_D3 , GET_BIT(u8Data,3) );
	GPIO_u8FastControlPinValue( CLCD_DataPort, CLCD_D4 , GET_BIT(u8Data,4) );
	GPIO_u8FastControlPinValue( CLCD_DataPort, CLCD_D5 , GET_BIT(u8Data,5) );
	GPIO_u8FastControlPinValue( CLCD_DataPort, CLCD_D6 , GET_BIT(u8Data,6) );
	GPIO_u8FastControlPinValue( CLCD_DataPort, CLCD_D7 , GET_BIT(u8Data,7) );
	
	// Send Enable Pulse
	GPIO_u8FastControlPinValue (CLCD_ControlPort, CLCD_E, GPIO_HIGH);
	
	STK_voidSetBusyWait (LCD_CommandDelay);

	GPIO_u8FastControlPinValue (CLCD_ControlPort, CLCD_E, GPIO_LOW);
	
	u8Global_Counter++;
	if (u8Global_Counter == 16)  // Go to the Second Line
		CLCD_voidSetCursor(1,0);

	if (u8Global_Counter == 32)  // Go Back to the First Line
	{
		CLCD_voidSetCursor(0,0);
		u8Global_Counter = 0;
	}

}

void CLCD_voidSendString (const char* charString)
{
	// Set The Array of String to Data Pins
	int i = 0;
	while (charString[i] != '\0')
	{
		CLCD_voidSendData (charString[i]);
		i++;
	}
}

void CLCD_voidSendNumber (u16 u16Number)
{
	
	u16 ReversedNumber = 0;
	u16 Temp = u16Number;
	u8 digit;

	u8 Counter1 = 0;
	u8 Counter2 = 0;
	
	while (u16Number > 0)
	{
		// Count the Number's Digits
		digit = u16Number % 10;
		u16Number = u16Number/10;
		
		Counter1++;
	}

	Counter2 = Counter1;
	
	while (Counter1 > 0)
	{
		// Reverse the Number
		ReversedNumber = ReversedNumber*10 + Temp%10;

		if (ReversedNumber == 0)
			ReversedNumber =+ 10;  // to count the Zeros (will create a little bit different number but we will solve it)

		Temp = Temp/10;

		Counter1--;
	}

	while (Counter2 > 0)
	{
		// Split the Number into its Digits
		digit = ReversedNumber % 10;
		
		// Add 48 into the digit so the LCD can read its ASCII and send it
		CLCD_voidSendData (digit+48);
		
		ReversedNumber = ReversedNumber/10;

		Counter2--;
	}
}

void CLCD_voidWriteSpecialChars (u8* u8Pattern, u8 u8OverwriteBlockNumber, u8 u8XPosition, u8 u8YPosition)
{
	u8 Address = 0;
	Address = u8OverwriteBlockNumber*8; // Get CGRAM Address
	
	// Set bit 6 for CGRAM Address Command then send the Command
	CLCD_voidSendCommand (Address + 64);
	
	// Write the Pattern into CGRAM
	int i = 0;
	for(i=0; i<8; i++)
		CLCD_voidSendData (u8Pattern[i]);
	
	// Go Back to DDRAM to Display the Pattern
	CLCD_voidSetCursor (u8XPosition, u8YPosition);
	
	// Display the Pattern written in the CGRAM
	CLCD_voidSendData (u8OverwriteBlockNumber);
}

void CLCD_voidSetCursor(u8 u8XPosition, u8 u8YPosition)
{
	u8 Address = 0;
	
	if (u8XPosition == 0)  // Location at First Line
		Address = u8YPosition;
		
	else if (u8XPosition == 1)  // Location at Second Line
		Address = 0x40 + u8YPosition;
	
	// Set bit 7 for DDRAM Address Command then send the Command
	CLCD_voidSendCommand(Address + 128);
}
