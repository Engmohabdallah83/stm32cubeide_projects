/*
 * RCC_Prog.cpp
 *
 *  Created on: Sep 2, 2023
 *      Author: Mohamed Aboelhassan
 */

#include "RCC_Interface.h"
//#include "stm32f1xx.h"


	Clock::Clock(GPIO_TypeDef* port): mPort(port)
	{
		if(port == GPIOA)
		{
			RCC->APB2ENR |= RCC_GPIOA_EN;
		}
		else if(port == GPIOB)
		{
			RCC->APB2ENR |= RCC_GPIOB_EN;
		}
		else if(port == GPIOC)
		{
			RCC->APB2ENR |= RCC_GPIOC_EN;
		}

	}


