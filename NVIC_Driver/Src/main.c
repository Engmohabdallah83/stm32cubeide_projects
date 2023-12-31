/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include "Std_Types.h"
#include "RCC_Interface.h"
#include "GPIO_Interface.h"
#include "NVIC_Interface.h"

void Delay_1Sec()
{
	for(int i = 0 ; i < 100000 ; i++)
	{
		asm("NOP");
	}
}
void EXTI0_IRQHandler (void);
void EXTI1_IRQHandler (void);

int main(void)
{
	/*	RCC Init						*/
	RCC_voidSysClockInit();

	/*	RCC for Peripheral		GPIOA		*/
	RCC_voidEnablePerClk(RCC_APB2, 2);

	/*	RCC for Peripheral		GPIOB		*/
	RCC_voidEnablePerClk(RCC_APB2, 3);

	/*	RCC for Peripheral		GPIOC		*/
	RCC_voidEnablePerClk(RCC_APB2, 4);

	/*	GPIO Direction						*/
	GPIO_voidSetPinDirection(GPIO_PORTA, GPIO_PIN0, GPIO_INPUT_PULL);
	GPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN0 , GPIO_HIGH);
	GPIO_voidSetPinDirection(GPIO_PORTB, GPIO_PIN0, GPIO_OUTPUT_10_PP);
	GPIO_voidSetPinDirection(GPIO_PORTC, GPIO_PIN13, GPIO_OUTPUT_50_PP);

	/*		NVIC Init			*/
	NVIC_voidInit();

	/*	Enable Interrupt		*/
	NVIC_voidEnableInt(7);
	NVIC_voidEnableInt(6);


	/*	Assign Priority 		*/
	/*		EXTI0   ==> Group 1 and Sub 1  */
	NVIC_voidSetIntPriority(6, (0b0101));
	/*		EXTI1   ==> Group 0 and Sub 1  */
	NVIC_voidSetIntPriority(7, (0b0001));

	/*	Enable Interrupt		*/

//	NVIC_voidSetPendingFlag(7);
	NVIC_voidSetPendingFlag(6);

    /* Loop forever */
	for(;;)
	{
		GPIO_voidSetPinValue(GPIO_PORTB, GPIO_PIN0, GPIO_HIGH);
		Delay_1Sec();
		GPIO_voidSetPinValue(GPIO_PORTB, GPIO_PIN0, GPIO_LOW);
		Delay_1Sec();

	}
}

void EXTI0_IRQHandler(void)
{
	Delay_1Sec();
	GPIO_voidSetPinValue(GPIO_PORTC, GPIO_PIN13, GPIO_HIGH);
	Delay_1Sec();
	NVIC_voidSetPendingFlag(7);
	GPIO_voidSetPinValue(GPIO_PORTC, GPIO_PIN13, GPIO_LOW);
	while(1);
}

void EXTI1_IRQHandler (void)
{
	Delay_1Sec();
	GPIO_voidSetPinValue(GPIO_PORTC, GPIO_PIN13, GPIO_HIGH);
	NVIC_voidSetIntPriority(6, (0b0001));
	NVIC_voidSetPendingFlag(6);
	Delay_1Sec();
	GPIO_voidSetPinValue(GPIO_PORTC, GPIO_PIN13, GPIO_LOW);
	while(1);
}
