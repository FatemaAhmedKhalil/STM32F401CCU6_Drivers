/***********************************************************************************************/
/***********************************************************************************************/
/************************************* Author: Fatema Ahmed ************************************/
/***************************************** Layer: MCAL *****************************************/
/******************************************* SWC: DAC ******************************************/
/***************************************** Version: 1.0 ****************************************/
/***********************************************************************************************/
/***********************************************************************************************/

#ifndef DAC_Interface
#define DAC_Interface

/*********************************/
/* Define						 */
/*		1) DAC Port				 */
/*		2) DAC Bits' Pins		 */
/*********************************/

#define DAC_GPIOA	1
#define DAC_GPIOB	2
#define DAC_GPIOC	3

#define DAC_PIN0	0
#define DAC_PIN1	1
#define DAC_PIN2	2
#define DAC_PIN3	3
#define DAC_PIN4	4
#define DAC_PIN5	5
#define DAC_PIN6	6
#define DAC_PIN7	7
#define DAC_PIN8	8
#define DAC_PIN9	9
#define DAC_PIN10	10
#define DAC_PIN11	11
#define DAC_PIN12	12
#define DAC_PIN13	13
#define DAC_PIN14	14
#define DAC_PIN15	15

void DAC_voidPlaySong (u8 u8Song[], u32 u32SongLength, u8 u8PortDAC, u8 u8Pin0DAC, u8 u8Pin1DAC, u8 u8Pin2DAC, u8 u8Pin3DAC, u8 u8Pin4DAC, u8 u8Pin5DAC, u8 u8Pin6DAC, u8 u8Pin7DAC, u32 u32SongTickTime);

#endif
