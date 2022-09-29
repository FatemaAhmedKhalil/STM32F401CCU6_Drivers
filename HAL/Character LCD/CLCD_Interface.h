/***********************************************************************************************/
/***********************************************************************************************/
/************************************* Author: Fatema Ahmed ************************************/
/***************************************** Layer: HAL ******************************************/
/*************************************** Component: CLCD ***************************************/
/***************************************** Version: 1.0 ****************************************/
/***********************************************************************************************/
/***********************************************************************************************/

#ifndef CLCD_Interface
#define CLCD_Interface

void CLCD_voidInitialization (void);

void CLCD_voidSendCommand (u8 u8Command);

void CLCD_voidSendData (u8 u8Data);
void CLCD_voidSendString (const char* charString);
void CLCD_voidSendNumber (u16 u16Number);

void CLCD_voidWriteSpecialChars (u8* u8Pattern, u8 u8OverwriteBlockNumber, u8 u8XPosition, u8 u8YPosition);

void CLCD_voidSetCursor(u8 u8XPosition, u8 u8YPosition);

#endif