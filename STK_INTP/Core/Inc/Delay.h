/*
 * Delay.h
 *
 *  Created on: Sep 12, 2023
 *      Author: Mohamed Aboelhassan
 */

#ifndef INC_DELAY_H_
#define INC_DELAY_H_

#include "stm32f1xx_hal.h"

#define OSC     8000000  //8 Mhz
#define MILLIS_IN_SEC	1000

void SysTick_Handler();

void SystickInitialize();

void DelayInit();

void DelayMs(uint32_t ms);

void RGB_Toggle(uint32_t R_ms, uint32_t G_ms);


#endif /* INC_DELAY_H_ */
