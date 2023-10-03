/*
 * Motor_User_Cfg.h
 *
 *  Created on: Sep 3, 2023
 *      Author: Mohamed Aboelhassan
 */

#ifndef INC_MOTOR_USER_CFG_H_
#define INC_MOTOR_USER_CFG_H_
#include "Motor_Interface.h"

/**
 * please Select Motor Ports from the specified List
 */

MotorType DC_M_CFG
{
	//Motor_IN1_PORT Select-> GPIOA,GPIOB,GPIOC
	GPIOC,
	//Motor_IN2_PORT Select-> GPIOA,GPIOB,GPIOC
	GPIOC,
	//Motor_ENA_PORT Select-> GPIOA,GPIOB,GPIOC
	GPIOC,
	//In1_PIN Select PIN number -> from (0 to 15)
	13,
	//In2_PIN Select PIN number -> from (0 to 15)
	14,
	//ENA_PIN Select PIN number -> from (0 to 15)
	15
};



#endif /* INC_MOTOR_USER_CFG_H_ */
