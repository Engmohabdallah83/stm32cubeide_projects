/*
 * Delay.cpp
 *
 *  Created on: Sep 12, 2023
 *      Author: Mohamed Aboelhassan
 */

#include "Delay.h"

// For store tick counts in ms
static volatile uint32_t  Ticks;


void SysTick_Handler()
{
   if(Ticks !=0)
   {
	   Ticks--;
   }

}

void SystickInitialize()
{
	  // Update SystemCoreClock value
		SysTick->LOAD = (OSC / MILLIS_IN_SEC) -1;
	    // Configure the SysTick timer to overflow every 1 us
		//SysTick->CTRL = (1<<0) | (1<<1) | (1<<2);
		SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_TICKINT_Msk | SysTick_CTRL_ENABLE_Msk;
}

void DelayInit()
{
	SystickInitialize();
}

void DelayMs(uint32_t ms)
{
    // Wait until ms reach zero
	Ticks = ms;
    while(Ticks);
}

void RGB_Toggle(uint32_t RED_Delay, uint32_t Grn_Delay)
{
	Ticks = RED_Delay;

	while(Ticks)
	{
		if(Ticks == RED_Delay)
		{
		 GPIOA->ODR ^=  (1 << 2);
		 //One_Toggle--;
		}
		else if(Ticks == Grn_Delay)
		 GPIOA->ODR ^=  (1 << 3);

	}

}

