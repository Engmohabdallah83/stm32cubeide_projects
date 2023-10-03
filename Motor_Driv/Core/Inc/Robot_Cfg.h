/*
 * Robot_Cfg.h
 *
 *  Created on: Sep 9, 2023
 *      Author: Mohamed Aboelhassan
 */

#ifndef INC_ROBOT_CFG_H_
#define INC_ROBOT_CFG_H_

#include "Motor_Interface.h"

MotorType LWM_Cfg
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

MotorType RWM_Cfg
{
	//Motor_IN1_PORT Select-> GPIOA,GPIOB,GPIOC
	GPIOA,
	//Motor_IN2_PORT Select-> GPIOA,GPIOB,GPIOC
	GPIOA,
	//Motor_ENA_PORT Select-> GPIOA,GPIOB,GPIOC
	GPIOA,
	//In1_PIN Select PIN number -> from (0 to 15)
	8,
	//In2_PIN Select PIN number -> from (0 to 15)
	9,
	//ENA_PIN Select PIN number -> from (0 to 15)
	10
};
/* Please use the following Motor instances in Robot instance constructor initialization */
Motor LW_Motor(&LWM_Cfg);	//use it as a left wheel Motor config I/p to Robot constructor
Motor RW_Motor(&RWM_Cfg);	//use it as a Right wheel motor config I/p to Robot constructor


#endif /* INC_ROBOT_CFG_H_ */
