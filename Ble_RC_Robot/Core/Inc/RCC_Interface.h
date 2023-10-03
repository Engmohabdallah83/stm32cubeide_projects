/*
 * RCC_Interface.h
 *
 *  Created on: Sep 2, 2023
 *      Author: Mohamed Aboelhassan
 */

#ifndef INC_RCC_INTERFACE_H_
#define INC_RCC_INTERFACE_H_

#include "stm32f103xb.h"

constexpr unsigned int RCC_GPIOA_EN = (1<<2);

constexpr unsigned int RCC_GPIOB_EN = (1<<3);

constexpr unsigned int RCC_GPIOC_EN = (1<<4);

class Clock
{
public:
	Clock(GPIO_TypeDef* port);
private:
	GPIO_TypeDef* mPort;
};


#endif /* INC_RCC_INTERFACE_H_ */
