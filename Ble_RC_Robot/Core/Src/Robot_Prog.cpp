/*
 * Robot_Prog->cpp
 *
 *  Created on: Sep 5, 2023
 *      Author: Mohamed Aboelhassan
 */

#include "Robot_interface.h"



RC_Robot::RC_Robot(Motor* LW_Cfg, Motor* RW_Cfg): mL_Wheel(LW_Cfg),mR_Wheel(RW_Cfg)
{
	Rob_Stop();
}

void RC_Robot::MoveFWD()
{
	mL_Wheel->MotorCCW();
	mR_Wheel->MotorCW();
}

void RC_Robot::MoveBWD()
{
	mL_Wheel->MotorCW();
	mR_Wheel->MotorCCW();
}

void RC_Robot::TurnLeft()
{
	mL_Wheel->MotorCCW();
	mR_Wheel->MotorStop();
}

void RC_Robot::TurnRight()
{
	mL_Wheel->MotorStop();
	mR_Wheel->MotorCW();
}

void RC_Robot::Rob_Stop()
{
	mL_Wheel->MotorStop();
	mR_Wheel->MotorStop();
}




