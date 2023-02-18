/***********************************************************************************************/
/***********************************************************************************************/
/************************************* Duthor: Fatema Ahmed ************************************/
/***************************************** Layer: MCAL *****************************************/
/****************************************** SWC: PORT ******************************************/
/***************************************** Version: 1.0 ****************************************/
/***********************************************************************************************/
/***********************************************************************************************/

#ifndef PORT_PRIVATE_H_
#define PORT_PRIVATE_H_

#define CONC(b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0)				CONC_HELPER(b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0)	
#define CONC_HELPER(b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0)		0b##b15##b14##b13##b12##b11##b10##b9##b8##b7##b6##b5##b4##b3##b2##b1##b0

#define CONC1(b7,b6,b5,b4,b3,b2,b1,b0)				CONC_HELPER1(b7,b6,b5,b4,b3,b2,b1,b0)
#define CONC_HELPER1(b7,b6,b5,b4,b3,b2,b1,b0)		0b##b7##b6##b5##b4##b3##b2##b1##b0

#define PORTA_Mode		CONC(PORTA_Register15_Mode,10,10,PORTA_Register12_Mode,PORTA_Register11_Mode,PORTA_Register10_Mode,PORTA_Register9_Mode,PORTA_Register8_Mode,PORTA_Register7_Mode,PORTA_Register6_Mode,PORTA_Register5_Mode,PORTA_Register4_Mode,PORTA_Register3_Mode,PORTA_Register2_Mode,PORTA_Register1_Mode,PORTA_Register0_Mode)
#define PORTB_Mode		CONC(PORTB_Register15_Mode,PORTB_Register14_Mode,PORTB_Register13_Mode,PORTB_Register12_Mode,PORTB_Register11_Mode,PORTB_Register10_Mode,PORTB_Register9_Mode,PORTB_Register8_Mode,PORTB_Register7_Mode,PORTB_Register6_Mode,PORTB_Register5_Mode,PORTB_Register4_Mode,PORTB_Register3_Mode,PORTB_Register2_Mode,PORTB_Register1_Mode,PORTB_Register0_Mode)
#define PORTC_Mode		CONC(PORTC_Register15_Mode,PORTC_Register14_Mode,PORTC_Register13_Mode,00,00,00,00,00,00,00,00,00,00,00,00,00)

#define PORTA_OutputType	    CONC(PORTA_Pin15_OutType,0,0,PORTA_Pin12_OutType,PORTA_Pin11_OutType,PORTA_Pin10_OutType,PORTA_Pin9_OutType,PORTA_Pin8_OutType,PORTA_Pin7_OutType,PORTA_Pin6_OutType,PORTA_Pin5_OutType,PORTA_Pin4_OutType,PORTA_Pin3_OutType,PORTA_Pin2_OutType,PORTA_Pin1_OutType,PORTA_Pin0_OutType)
#define PORTB_OutputType		CONC(PORTB_Pin15_OutType,PORTB_Pin14_OutType,PORTB_Pin13_OutType,PORTB_Pin12_OutType,PORTB_Pin11_OutType,PORTB_Pin10_OutType,PORTB_Pin9_OutType,PORTB_Pin8_OutType,PORTB_Pin7_OutType,PORTB_Pin6_OutType,PORTB_Pin5_OutType,PORTB_Pin4_OutType,PORTB_Pin3_OutType,PORTB_Pin2_OutType,PORTB_Pin1_OutType,PORTB_Pin0_OutType)
#define PORTC_OutputType		CONC(PORTC_Pin15_OutType,PORTC_Pin14_OutType,PORTC_Pin13_OutType,0,0,0,0,0,0,0,0,0,0,0,0,0)

#define PORTA_Speed	    CONC(PORTA_Register15_Speed,00,00,PORTA_Register12_Speed,PORTA_Register11_Speed,PORTA_Register10_Speed,PORTA_Register9_Speed,PORTA_Register8_Speed,PORTA_Register7_Speed,PORTA_Register6_Speed,PORTA_Register5_Speed,PORTA_Register4_Speed,PORTA_Register3_Speed,PORTA_Register2_Speed,PORTA_Register1_Speed,PORTA_Register0_Speed)
#define PORTB_Speed		CONC(PORTB_Register15_Speed,PORTB_Register14_Speed,PORTB_Register13_Speed,PORTB_Register12_Speed,PORTB_Register11_Speed,PORTB_Register10_Speed,PORTB_Register9_Speed,PORTB_Register8_Speed,PORTB_Register7_Speed,PORTB_Register6_Speed,PORTB_Register5_Speed,PORTB_Register4_Speed,PORTB_Register3_Speed,PORTB_Register2_Speed,PORTB_Register1_Speed,PORTB_Register0_Speed)
#define PORTC_Speed		CONC(PORTC_Register15_Speed,PORTC_Register14_Speed,PORTC_Register13_Speed,00,00,00,00,00,00,00,00,00,00,00,00,00)

#define PORTA_PP		CONC(PORTA_Register15_PP,10,01,PORTA_Register12_PP,PORTA_Register11_PP,PORTA_Register10_PP,PORTA_Register9_PP,PORTA_Register8_PP,PORTA_Register7_PP,PORTA_Register6_PP,PORTA_Register5_PP,PORTA_Register4_PP,PORTA_Register3_PP,PORTA_Register2_PP,PORTA_Register1_PP,PORTA_Register0_PP)
#define PORTB_PP		CONC(PORTB_Register15_PP,PORTB_Register14_PP,PORTB_Register13_PP,PORTB_Register12_PP,PORTB_Register11_PP,PORTB_Register10_PP,PORTB_Register9_PP,PORTB_Register8_PP,PORTB_Register7_PP,PORTB_Register6_PP,PORTB_Register5_PP,PORTB_Register4_PP,PORTB_Register3_PP,PORTB_Register2_PP,PORTB_Register1_PP,PORTB_Register0_PP)
#define PORTC_PP		CONC(PORTC_Register15_PP,PORTC_Register14_PP,PORTC_Register13_PP,00,00,00,00,00,00,00,00,00,00,00,00,00)

#define PORTA_LOCKER	CONC(PORTA_Pin15_Lock,0,0,PORTA_Pin12_Lock,PORTA_Pin11_Lock,PORTA_Pin10_Lock,PORTA_Pin9_Lock,PORTA_Pin8_Lock,PORTA_Pin7_Lock,PORTA_Pin6_Lock,PORTA_Pin5_Lock,PORTA_Pin4_Lock,PORTA_Pin3_Lock,PORTA_Pin2_Lock,PORTA_Pin1_Lock,PORTA_Pin0_Lock)
#define PORTB_LOCKER	CONC(PORTB_Pin15_Lock,PORTB_Pin14_Lock,PORTB_Pin13_Lock,PORTB_Pin12_Lock,PORTB_Pin11_Lock,PORTB_Pin10_Lock,PORTB_Pin9_Lock,PORTB_Pin8_Lock,PORTB_Pin7_Lock,PORTB_Pin6_Lock,PORTB_Pin5_Lock,PORTB_Pin4_Lock,PORTB_Pin3_Lock,PORTB_Pin2_Lock,PORTB_Pin1_Lock,PORTB_Pin0_Lock)
#define PORTC_LOCKER	CONC(PORTC_Pin15_Lock,PORTC_Pin14_Lock,PORTC_Pin13_Lock,0,0,0,0,0,0,0,0,0,0,0,0,0)

#define PORTA_AlternativeLow	CONC1(PORTA_Pin7_AFL,PORTA_Pin6_AFL,PORTA_Pin5_AFL,PORTA_Pin4_AFL,PORTA_Pin3_AFL,PORTA_Pin2_AFL,PORTA_Pin1_AFL,PORTA_Pin0_AFL)
#define PORTB_AlternativeLow	CONC1(PORTB_Pin7_AFL,PORTB_Pin6_AFL,PORTB_Pin5_AFL,PORTB_Pin4_AFL,PORTB_Pin3_AFL,PORTB_Pin2_AFL,PORTB_Pin1_AFL,PORTB_Pin0_AFL)
#define PORTC_AlternativeLow	CONC1(0000,0000,0000,0000,0000,0000,0000,0000)

#define PORTA_AlternativeHigh	CONC1(PORTA_Pin15_AFH,0000,0000,PORTA_Pin12_AFH,PORTA_Pin11_AFH,PORTA_Pin10_AFH,PORTA_Pin9_AFH,PORTA_Pin8_AFH)
#define PORTB_AlternativeHigh	CONC1(PORTB_Pin15_AFH,PORTB_Pin14_AFH,PORTB_Pin13_AFH,PORTB_Pin12_AFH,PORTB_Pin11_AFH,PORTB_Pin10_AFH,PORTB_Pin9_AFH,PORTB_Pin8_AFH)
#define PORTC_AlternativeHigh	CONC1(PORTC_Pin15_AFH,PORTC_Pin14_AFH,PORTC_Pin13_AFH,0000,0000,0000,0000,0000)

#endif