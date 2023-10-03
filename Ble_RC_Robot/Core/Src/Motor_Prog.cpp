/*
 * Motor_Prog.cpp
 *
 *  Created on: Sep 3, 2023
 *      Author: Mohamed Aboelhassan
 */

#include "stm32f103xb.h"
#include "Motor_Interface.h"
#include "GPIO_Interface.h"
#include "Std_Types.h"

Motor::Motor(MotorType *Cfg):m_cfg(Cfg)
{
	//Configure PINS and its port
	GPIO Motor_ENA(m_cfg->Motor_ENA_PORT,m_cfg->ENA_PIN);
	Motor_ENA.GPIO_SetPinDir(GPIO_OUT);

	GPIO Motor_IN1(m_cfg->Motor_IN1_PORT,m_cfg->In1_PIN);
	Motor_IN1.GPIO_SetPinDir(GPIO_OUT);

	GPIO Motor_IN2(m_cfg->Motor_IN2_PORT,m_cfg->In2_PIN);
	Motor_IN2.GPIO_SetPinDir(GPIO_OUT);

	//Stop Motor Initially;
	MotorStop();
}

void Motor::MotorStop()
{
	SET_Bit(m_cfg->Motor_ENA_PORT->BRR, m_cfg->ENA_PIN);
	SET_Bit(m_cfg->Motor_IN1_PORT->BRR, m_cfg->In1_PIN);
	SET_Bit(m_cfg->Motor_IN2_PORT->BRR, m_cfg->In2_PIN);
}

void Motor::MotorCW()
{
	SET_Bit(m_cfg->Motor_ENA_PORT->BSRR, m_cfg->ENA_PIN);
	SET_Bit(m_cfg->Motor_IN1_PORT->BRR, m_cfg->In1_PIN);
	SET_Bit(m_cfg->Motor_IN2_PORT->BSRR, m_cfg->In2_PIN);
}

void Motor::MotorCCW()
{
	SET_Bit(m_cfg->Motor_ENA_PORT->BSRR, m_cfg->ENA_PIN);
	SET_Bit(m_cfg->Motor_IN1_PORT->BSRR, m_cfg->In1_PIN);
	SET_Bit(m_cfg->Motor_IN2_PORT->BRR, m_cfg->In2_PIN);
}

