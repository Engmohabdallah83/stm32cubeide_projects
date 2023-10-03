/*
 * Motor_Interface.h
 *
 *  Created on: Sep 3, 2023
 *      Author: Mohamed Aboelhassan
 */

#ifndef INC_MOTOR_INTERFACE_H_
#define INC_MOTOR_INTERFACE_H_

#include "Std_Types.h"
//#include "RCC_Interface.h"
#include "GPIO_Interface.h"

typedef struct
{
	GPIO_TypeDef* Motor_IN1_PORT;
	GPIO_TypeDef* Motor_IN2_PORT;
	GPIO_TypeDef* Motor_ENA_PORT;

	uint8 In1_PIN;
	uint8 In2_PIN;
	uint8 ENA_PIN;
}MotorType;


class Motor
{
public:
	Motor(MotorType *Cfg);
	void MotorStop();
	void MotorCW();
	void MotorCCW();


private:
	MotorType *m_cfg;
};


#endif /* INC_MOTOR_INTERFACE_H_ */
