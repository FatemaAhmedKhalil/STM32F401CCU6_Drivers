/***********************************************************************************************/
/***********************************************************************************************/
/************************************* Author: Fatema Ahmed ************************************/
/***************************************** Layer: HAL ******************************************/
/*************************************** SWC: Stepper Motor ************************************/
/***************************************** Version: 1.0 ****************************************/
/***********************************************************************************************/
/***********************************************************************************************/

#ifndef Stepper_Interface
#define Stepper_Interface

#define StepperMotor_PORTA	1
#define StepperMotor_PORTB	2
#define StepperMotor_PORTC	3

#define StepperMotor_PIN0	0
#define StepperMotor_PIN1	1
#define StepperMotor_PIN2	2
#define StepperMotor_PIN3	3
#define StepperMotor_PIN4	4
#define StepperMotor_PIN5	5
#define StepperMotor_PIN6	6
#define StepperMotor_PIN7	7
#define StepperMotor_PIN8	8
#define StepperMotor_PIN9	9
#define StepperMotor_PIN10	10
#define StepperMotor_PIN11	11
#define StepperMotor_PIN12	12
#define StepperMotor_PIN13	13
#define StepperMotor_PIN14	14
#define StepperMotor_PIN15	15

/****************************************************/
/* Define											*/
/*		1) Motor Port				    			*/
/*		2) Motor Pins			   	    			*/
/*		3) Required Angle							*/
/*		3) Time Speed 								*/
/*			Note:									*/
/*				Optimum Frequency = 100 step/sec	*/
/*				Speed = 10 msec						*/
/****************************************************/

/** Counter-ClockWise Direction **/
void StepperMotor_voidUniPolar_CCW_WaveDrive (u8 u8PORT, u8 BluePin, u8 PinkPin, u8 YellowPin, u8 OrangePin, u32 Angle, u32 SpeedTime);
void StepperMotor_voidUniPolar_CCW_FullStepDrive (u8 u8PORT, u8 BluePin, u8 PinkPin, u8 YellowPin, u8 OrangePin, u32 Angle, u32 SpeedTime);
void StepperMotor_voidUniPolar_CCW_HalfStepDrive (u8 u8PORT, u8 BluePin, u8 PinkPin, u8 YellowPin, u8 OrangePin, u32 Angle, u32 SpeedTime);

/** ClockWise Direction **/
void StepperMotor_voidUniPolar_CW_WaveDrive (u8 u8PORT, u8 BluePin, u8 PinkPin, u8 YellowPin, u8 OrangePin, u32 Angle, u32 SpeedTime);
void StepperMotor_voidUniPolar_CW_FullStepDrive (u8 u8PORT, u8 BluePin, u8 PinkPin, u8 YellowPin, u8 OrangePin, u32 Angle, u32 SpeedTime);
void StepperMotor_voidUniPolar_CW_HalfStepDrive (u8 u8PORT, u8 BluePin, u8 PinkPin, u8 YellowPin, u8 OrangePin, u32 Angle, u32 SpeedTime);

#endif
