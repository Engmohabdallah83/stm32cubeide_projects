#include "STD_TYPES.h"
#include "NVIC_Interface.h"
#include "RCC_Interface.h"
#include "GPIO_Interface.h"

void main(void)
{
	/*Enable Clock of GPIOA*/
	RCC_voidEnablePeripheralClock(APB2,4);
	
	/*Set pin 0 as output push pull 2 MHz*/
	GPIO_voidSetPinMode(0,OUTPUT_SPEED_2MHZ_PP);
	
	/*Set pin 1 as output push pull 2 MHz*/
	GPIO_voidSetPinMode(1,OUTPUT_SPEED_2MHZ_PP);
	
	/*Enable NVIC EXTI0*/
	NVIC_u8InterruptEnable(6);
	
	/*Enable NVIC EXTI1*/
	NVIC_u8InterruptEnable(7);
	
	/*Initialize 2 bits for froup , 2 bits for sub*/
	SCB_u8SetNVICPriority();
	
	/*Set EXTI0 priority*/
	NVIC_u8SetPriority(6,0,0);
	
	/*Set EXTI1 priority*/
	NVIC_u8SetPriority(7,1,1);
	
	/*Set Pending flag of EXTI0*/
	NVIC_u8SetPendingFlag(6);
	while(1)
	{
		
	}
}

void EXTI0_IRQHandler(void)
{
	/*High on Pin A.0*/
	GPIO_voidSetPinValue(0,1);
	
	/*Set Pending flag of EXTI1*/
	NVIC_u8SetPendingFlag(7);
	
	while(1);
}
void EXTI1_IRQHandler(void)
{
	/*High on Pin A.1*/
	GPIO_voidSetPinValue(1,1);
	
	while(1);
}
