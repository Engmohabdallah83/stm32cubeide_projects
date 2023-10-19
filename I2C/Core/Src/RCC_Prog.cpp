/*
 * RCC_Prog.cpp
 *
 *  Created on: Sep 2, 2023
 *      Author: Mohamed Aboelhassan
 */

#include "RCC_Interface.h"
#include "stm32f1xx.h"
#include 	"RCC_Private.h"
#include 	"RCC_Config.h"

Clock::Clock()
{}

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


void Clock::RCC_voidSysClockInit(void)
{
	#if			RCC_CLK_TYPE	==		RCC_HSI
				RCC_CR			=		0x00000001;
				RCC_CFGR		=		0x00000000;
				while(GET_BIT(RCC_CR,1) == 0);
	#elif		RCC_CLK_TYPE	==		RCC_HSE
				RCC_CR			=		0x00010000;
				RCC_CFGR		=		0x00000001;
				while(GET_BIT(RCC_CR,17) == 0);
	#elif		RCC_CLK_TYPE	==		RCC_PLL
			#if		RCC_PLL_SRC		==		RCC_PLL_HSI
					RCC_CR			=		0x01000001;
					RCC_CFGR		=		0x00000002;
			#elif	RCC_PLL_SRC		==		RCC_PLL_HSE
					RCC_CR			=		0x01010000;
					RCC_CFGR		=		0x00010002;
			#endif
			while(GET_BIT(RCC_CR,25) == 0);
	#else
		#error "Wrong Choice of Clock Type"
	#endif
}
//RCC_voidEnablePerClk(RCC_APB2,RCC_GPIOA);
void Clock::RCC_voidEnablePerClk(uint8 BusId , uint8 PerId)
{
	/*			Range Check				*/
	if((BusId <3)&&(PerId<32))
	{
		switch(BusId)
		{
			case RCC_AHB	:	SET_BIT(RCC_AHBENR,PerId);		break;
			case RCC_APB1	:	SET_BIT(RCC_APB1ENR,PerId);		break;
			case RCC_APB2	:	SET_BIT(RCC_APB2ENR,PerId);		break;
		}
	}
}
void Clock::RCC_voidDisablePerClk(uint8 BusId , uint8 PerId)
{
	/*			Range Check				*/
	if((BusId <3)&&(PerId<32))
	{
		switch(BusId)
		{
			case RCC_AHB	:	CLR_BIT(RCC_AHBENR,PerId);		break;
			case RCC_APB1	:	CLR_BIT(RCC_APB1ENR,PerId);		break;
			case RCC_APB2	:	CLR_BIT(RCC_APB2ENR,PerId);		break;
		}
	}
}

