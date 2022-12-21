/***********************************************************************************************/
/***********************************************************************************************/
/************************************* Author: Fatema Ahmed ************************************/
/***************************************** Layer: HAL ******************************************/
/*************************************** SWC: Stepper Motor ************************************/
/***************************************** Version: 1.0 ****************************************/
/***********************************************************************************************/
/***********************************************************************************************/


#include "STD_Types.h"
#include "BitOperations.h"

#include "GPIO_Interface.h"
#include "STK_Interface.h"

#include "Stepper_Config.h"
#include "Stepper_Private.h"
#include "Stepper_Interface.h"


void StepperMotor_voidUniPolar_CCW_WaveDrive (u8 u8PORT, u8 BluePin, u8 PinkPin, u8 YellowPin, u8 OrangePin, u32 Angle, u32 SpeedTime)
{
	u32 counter = 0;
	//Calculate The Number of Iteration to Obtain the Required Angle
	u32 Steps = 0;
	u32 Iterations = 0;
	Steps = (Angle/11.2)*64; // With Respect of the Big Axis and Small Axis
	Iterations = Steps/4; // Number of Steps is 4
	for (counter=0; counter<Iterations; counter++)
	{
		// First Step
		GPIO_u8SetPinValue (u8PORT, OrangePin, GPIO_LOW);
		GPIO_u8SetPinValue (u8PORT, BluePin, GPIO_HIGH);
		GPIO_u8SetPinValue (u8PORT, PinkPin, GPIO_LOW);
		GPIO_u8SetPinValue (u8PORT, YellowPin, GPIO_LOW);

		STK_voidSetBusyWait (SpeedTime);

		// Second Step
		GPIO_u8SetPinValue (u8PORT, BluePin, GPIO_LOW);
		GPIO_u8SetPinValue (u8PORT, PinkPin, GPIO_HIGH);
		GPIO_u8SetPinValue (u8PORT, YellowPin, GPIO_LOW);
		GPIO_u8SetPinValue (u8PORT, OrangePin, GPIO_LOW);

		STK_voidSetBusyWait (SpeedTime);

		// Third Step
		GPIO_u8SetPinValue (u8PORT, PinkPin, GPIO_LOW);
		GPIO_u8SetPinValue (u8PORT, BluePin, GPIO_LOW);
		GPIO_u8SetPinValue (u8PORT, YellowPin, GPIO_HIGH);
		GPIO_u8SetPinValue (u8PORT, OrangePin, GPIO_LOW);

		STK_voidSetBusyWait (SpeedTime);

		// Fourth Step
		GPIO_u8SetPinValue (u8PORT, YellowPin, GPIO_LOW);
		GPIO_u8SetPinValue (u8PORT, BluePin, GPIO_LOW);
		GPIO_u8SetPinValue (u8PORT, PinkPin, GPIO_LOW);
		GPIO_u8SetPinValue (u8PORT, OrangePin, GPIO_HIGH);

		STK_voidSetBusyWait (SpeedTime);
	}
}

void StepperMotor_voidUniPolar_CCW_FullStepDrive (u8 u8PORT, u8 BluePin, u8 PinkPin, u8 YellowPin, u8 OrangePin, u32 Angle, u32 SpeedTime)
{
	u32 counter = 0;
	//Calculate The Number of Iteration to Obtain the Required Angle
	u32 Steps = 0;
	u32 Iterations = 0;
	Steps = (Angle/11.2)*64; // With Respect of the Big Axis and Small Axis
	Iterations = Steps/4; // Number of Steps is 4
	for (counter=0; counter<Iterations; counter++)
	{
		// First Step
		GPIO_u8SetPinValue (u8PORT, OrangePin, GPIO_LOW);
		GPIO_u8SetPinValue (u8PORT, BluePin, GPIO_HIGH);
		GPIO_u8SetPinValue (u8PORT, PinkPin, GPIO_HIGH);
		GPIO_u8SetPinValue (u8PORT, YellowPin, GPIO_LOW);

		STK_voidSetBusyWait (SpeedTime);

		// Second Step
		GPIO_u8SetPinValue (u8PORT, BluePin, GPIO_LOW);
		GPIO_u8SetPinValue (u8PORT, PinkPin, GPIO_HIGH);
		GPIO_u8SetPinValue (u8PORT, YellowPin, GPIO_HIGH);
		GPIO_u8SetPinValue (u8PORT, OrangePin, GPIO_LOW);

		STK_voidSetBusyWait (SpeedTime);

		// Third Step
		GPIO_u8SetPinValue (u8PORT, PinkPin, GPIO_LOW);
		GPIO_u8SetPinValue (u8PORT, BluePin, GPIO_LOW);
		GPIO_u8SetPinValue (u8PORT, YellowPin, GPIO_HIGH);
		GPIO_u8SetPinValue (u8PORT, OrangePin, GPIO_HIGH);

		STK_voidSetBusyWait (SpeedTime);

		// Fourth Step
		GPIO_u8SetPinValue (u8PORT, YellowPin, GPIO_LOW);
		GPIO_u8SetPinValue (u8PORT, BluePin, GPIO_HIGH);
		GPIO_u8SetPinValue (u8PORT, PinkPin, GPIO_LOW);
		GPIO_u8SetPinValue (u8PORT, OrangePin, GPIO_HIGH);

		STK_voidSetBusyWait (SpeedTime);
	}
}

void StepperMotor_voidUniPolar_CCW_HalfStepDrive (u8 u8PORT, u8 BluePin, u8 PinkPin, u8 YellowPin, u8 OrangePin, u32 Angle, u32 SpeedTime)
{
	u32 counter = 0;
	//Calculate The Number of Iteration to Obtain the Required Angle
	u32 Steps = 0;
	u32 Iterations = 0;
	Steps = (Angle/11.2)*64; // With Respect of the Big Axis and Small Axis
	Iterations = Steps/8; // Number of Steps is 8
	for (counter=0; counter<Iterations; counter++)
	{
		// First Step
		GPIO_u8SetPinValue (u8PORT, OrangePin, GPIO_LOW);
		GPIO_u8SetPinValue (u8PORT, BluePin, GPIO_HIGH);
		GPIO_u8SetPinValue (u8PORT, PinkPin, GPIO_LOW);
		GPIO_u8SetPinValue (u8PORT, YellowPin, GPIO_LOW);

		STK_voidSetBusyWait (SpeedTime);

		// Second Step
		GPIO_u8SetPinValue (u8PORT, BluePin, GPIO_HIGH);
		GPIO_u8SetPinValue (u8PORT, PinkPin, GPIO_HIGH);
		GPIO_u8SetPinValue (u8PORT, YellowPin, GPIO_LOW);
		GPIO_u8SetPinValue (u8PORT, OrangePin, GPIO_LOW);

		STK_voidSetBusyWait (SpeedTime);

		// Third Step
		GPIO_u8SetPinValue (u8PORT, BluePin, GPIO_LOW);
		GPIO_u8SetPinValue (u8PORT, PinkPin, GPIO_HIGH);
		GPIO_u8SetPinValue (u8PORT, YellowPin, GPIO_LOW);
		GPIO_u8SetPinValue (u8PORT, OrangePin, GPIO_LOW);

		STK_voidSetBusyWait (SpeedTime);

		// Fourth Step
		GPIO_u8SetPinValue (u8PORT, BluePin, GPIO_LOW);
		GPIO_u8SetPinValue (u8PORT, PinkPin, GPIO_HIGH);
		GPIO_u8SetPinValue (u8PORT, YellowPin, GPIO_HIGH);
		GPIO_u8SetPinValue (u8PORT, OrangePin, GPIO_LOW);

		STK_voidSetBusyWait (SpeedTime);

		// Fifth Step
		GPIO_u8SetPinValue (u8PORT, BluePin, GPIO_LOW);
		GPIO_u8SetPinValue (u8PORT, PinkPin, GPIO_LOW);
		GPIO_u8SetPinValue (u8PORT, YellowPin, GPIO_HIGH);
		GPIO_u8SetPinValue (u8PORT, OrangePin, GPIO_LOW);

		STK_voidSetBusyWait (SpeedTime);

		// Sixth Step
		GPIO_u8SetPinValue (u8PORT, PinkPin, GPIO_LOW);
		GPIO_u8SetPinValue (u8PORT, BluePin, GPIO_LOW);
		GPIO_u8SetPinValue (u8PORT, YellowPin, GPIO_HIGH);
		GPIO_u8SetPinValue (u8PORT, OrangePin, GPIO_HIGH);

		STK_voidSetBusyWait (SpeedTime);

		// Seventh Step
		GPIO_u8SetPinValue (u8PORT, BluePin, GPIO_LOW);
		GPIO_u8SetPinValue (u8PORT, PinkPin, GPIO_LOW);
		GPIO_u8SetPinValue (u8PORT, YellowPin, GPIO_LOW);
		GPIO_u8SetPinValue (u8PORT, OrangePin, GPIO_HIGH);

		STK_voidSetBusyWait (SpeedTime);

		// Eighth Step
		GPIO_u8SetPinValue (u8PORT, BluePin, GPIO_HIGH);
		GPIO_u8SetPinValue (u8PORT, YellowPin, GPIO_LOW);
		GPIO_u8SetPinValue (u8PORT, PinkPin, GPIO_LOW);
		GPIO_u8SetPinValue (u8PORT, OrangePin, GPIO_HIGH);

		STK_voidSetBusyWait (SpeedTime);
	}
}

void StepperMotor_voidUniPolar_CW_WaveDrive (u8 u8PORT, u8 BluePin, u8 PinkPin, u8 YellowPin, u8 OrangePin, u32 Angle, u32 SpeedTime)
{
	u32 counter = 0;
	//Calculate The Number of Iteration to Obtain the Required Angle
	u32 Steps = 0;
	u32 Iterations = 0;
	Steps = (Angle/11.2)*64; // With Respect of the Big Axis and Small Axis
	Iterations = Steps/4; // Number of Steps is 4

	/** Reverse the Sequence to Reverse the Direction **/
	for (counter=0; counter<Iterations; counter++)
	{
		// Fourth Step
		GPIO_u8SetPinValue (u8PORT, YellowPin, GPIO_LOW);
		GPIO_u8SetPinValue (u8PORT, BluePin, GPIO_LOW);
		GPIO_u8SetPinValue (u8PORT, PinkPin, GPIO_LOW);
		GPIO_u8SetPinValue (u8PORT, OrangePin, GPIO_HIGH);

		STK_voidSetBusyWait (SpeedTime);

		// Third Step
		GPIO_u8SetPinValue (u8PORT, PinkPin, GPIO_LOW);
		GPIO_u8SetPinValue (u8PORT, BluePin, GPIO_LOW);
		GPIO_u8SetPinValue (u8PORT, YellowPin, GPIO_HIGH);
		GPIO_u8SetPinValue (u8PORT, OrangePin, GPIO_LOW);

		STK_voidSetBusyWait (SpeedTime);

		// Second Step
		GPIO_u8SetPinValue (u8PORT, BluePin, GPIO_LOW);
		GPIO_u8SetPinValue (u8PORT, PinkPin, GPIO_HIGH);
		GPIO_u8SetPinValue (u8PORT, YellowPin, GPIO_LOW);
		GPIO_u8SetPinValue (u8PORT, OrangePin, GPIO_LOW);

		STK_voidSetBusyWait (SpeedTime);

		// First Step
		GPIO_u8SetPinValue (u8PORT, OrangePin, GPIO_LOW);
		GPIO_u8SetPinValue (u8PORT, BluePin, GPIO_HIGH);
		GPIO_u8SetPinValue (u8PORT, PinkPin, GPIO_LOW);
		GPIO_u8SetPinValue (u8PORT, YellowPin, GPIO_LOW);

		STK_voidSetBusyWait (SpeedTime);
	}
}

void StepperMotor_voidUniPolar_CW_FullStepDrive (u8 u8PORT, u8 BluePin, u8 PinkPin, u8 YellowPin, u8 OrangePin, u32 Angle, u32 SpeedTime)
{
	u32 counter = 0;
	//Calculate The Number of Iteration to Obtain the Required Angle
	u32 Steps = 0;
	u32 Iterations = 0;
	Steps = (Angle/11.2)*64; // With Respect of the Big Axis and Small Axis
	Iterations = Steps/4; // Number of Steps is 4

	/** Reverse the Sequence to Reverse the Direction **/
	for (counter=0; counter<Iterations; counter++)
	{
		// Fourth Step
		GPIO_u8SetPinValue (u8PORT, YellowPin, GPIO_LOW);
		GPIO_u8SetPinValue (u8PORT, BluePin, GPIO_HIGH);
		GPIO_u8SetPinValue (u8PORT, PinkPin, GPIO_LOW);
		GPIO_u8SetPinValue (u8PORT, OrangePin, GPIO_HIGH);

		STK_voidSetBusyWait (SpeedTime);

		// Third Step
		GPIO_u8SetPinValue (u8PORT, PinkPin, GPIO_LOW);
		GPIO_u8SetPinValue (u8PORT, BluePin, GPIO_LOW);
		GPIO_u8SetPinValue (u8PORT, YellowPin, GPIO_HIGH);
		GPIO_u8SetPinValue (u8PORT, OrangePin, GPIO_HIGH);

		STK_voidSetBusyWait (SpeedTime);

		// Second Step
		GPIO_u8SetPinValue (u8PORT, BluePin, GPIO_LOW);
		GPIO_u8SetPinValue (u8PORT, PinkPin, GPIO_HIGH);
		GPIO_u8SetPinValue (u8PORT, YellowPin, GPIO_HIGH);
		GPIO_u8SetPinValue (u8PORT, OrangePin, GPIO_LOW);

		STK_voidSetBusyWait (SpeedTime);

		// First Step
		GPIO_u8SetPinValue (u8PORT, OrangePin, GPIO_LOW);
		GPIO_u8SetPinValue (u8PORT, BluePin, GPIO_HIGH);
		GPIO_u8SetPinValue (u8PORT, PinkPin, GPIO_HIGH);
		GPIO_u8SetPinValue (u8PORT, YellowPin, GPIO_LOW);

		STK_voidSetBusyWait (SpeedTime);
	}
}

void StepperMotor_voidUniPolar_CW_HalfStepDrive (u8 u8PORT, u8 BluePin, u8 PinkPin, u8 YellowPin, u8 OrangePin, u32 Angle, u32 SpeedTime)
{
	u32 counter = 0;
	//Calculate The Number of Iteration to Obtain the Required Angle
	u32 Steps = 0;
	u32 Iterations = 0;
	Steps = (Angle/11.2)*64; // With Respect of the Big Axis and Small Axis
	Iterations = Steps/8; // Number of Steps is 8

	/** Reverse the Sequence to Reverse the Direction **/
	for (counter=0; counter<Iterations; counter++)
	{
		// Eighth Step
		GPIO_u8SetPinValue (u8PORT, BluePin, GPIO_HIGH);
		GPIO_u8SetPinValue (u8PORT, YellowPin, GPIO_LOW);
		GPIO_u8SetPinValue (u8PORT, PinkPin, GPIO_LOW);
		GPIO_u8SetPinValue (u8PORT, OrangePin, GPIO_HIGH);

		STK_voidSetBusyWait (SpeedTime);

		// Seventh Step
		GPIO_u8SetPinValue (u8PORT, BluePin, GPIO_LOW);
		GPIO_u8SetPinValue (u8PORT, PinkPin, GPIO_LOW);
		GPIO_u8SetPinValue (u8PORT, YellowPin, GPIO_LOW);
		GPIO_u8SetPinValue (u8PORT, OrangePin, GPIO_HIGH);

		STK_voidSetBusyWait (SpeedTime);

		// Sixth Step
		GPIO_u8SetPinValue (u8PORT, PinkPin, GPIO_LOW);
		GPIO_u8SetPinValue (u8PORT, BluePin, GPIO_LOW);
		GPIO_u8SetPinValue (u8PORT, YellowPin, GPIO_HIGH);
		GPIO_u8SetPinValue (u8PORT, OrangePin, GPIO_HIGH);

		STK_voidSetBusyWait (SpeedTime);

		// Fifth Step
		GPIO_u8SetPinValue (u8PORT, BluePin, GPIO_LOW);
		GPIO_u8SetPinValue (u8PORT, PinkPin, GPIO_LOW);
		GPIO_u8SetPinValue (u8PORT, YellowPin, GPIO_HIGH);
		GPIO_u8SetPinValue (u8PORT, OrangePin, GPIO_LOW);

		STK_voidSetBusyWait (SpeedTime);

		// Fourth Step
		GPIO_u8SetPinValue (u8PORT, BluePin, GPIO_LOW);
		GPIO_u8SetPinValue (u8PORT, PinkPin, GPIO_HIGH);
		GPIO_u8SetPinValue (u8PORT, YellowPin, GPIO_HIGH);
		GPIO_u8SetPinValue (u8PORT, OrangePin, GPIO_LOW);

		STK_voidSetBusyWait (SpeedTime);

		// Third Step
		GPIO_u8SetPinValue (u8PORT, BluePin, GPIO_LOW);
		GPIO_u8SetPinValue (u8PORT, PinkPin, GPIO_HIGH);
		GPIO_u8SetPinValue (u8PORT, YellowPin, GPIO_LOW);
		GPIO_u8SetPinValue (u8PORT, OrangePin, GPIO_LOW);

		STK_voidSetBusyWait (SpeedTime);

		// Second Step
		GPIO_u8SetPinValue (u8PORT, BluePin, GPIO_HIGH);
		GPIO_u8SetPinValue (u8PORT, PinkPin, GPIO_HIGH);
		GPIO_u8SetPinValue (u8PORT, YellowPin, GPIO_LOW);
		GPIO_u8SetPinValue (u8PORT, OrangePin, GPIO_LOW);

		STK_voidSetBusyWait (SpeedTime);

		// First Step
		GPIO_u8SetPinValue (u8PORT, OrangePin, GPIO_LOW);
		GPIO_u8SetPinValue (u8PORT, BluePin, GPIO_HIGH);
		GPIO_u8SetPinValue (u8PORT, PinkPin, GPIO_LOW);
		GPIO_u8SetPinValue (u8PORT, YellowPin, GPIO_LOW);

		STK_voidSetBusyWait (SpeedTime);
	}
}
