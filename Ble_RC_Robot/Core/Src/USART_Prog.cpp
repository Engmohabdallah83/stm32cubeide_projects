/*
 * USART_Prog.cpp
 *
 *  Created on: Sep 10, 2023
 *      Author: Mohamed Aboelhassan
 */

#include "UART_Interface.h"


	USART::USART(UsartInstance usart)
	{

		if(this == reinterpret_cast<USART*>(USART1Instance) )
		{

			//RCC enable clock gating for USART1
			Usart1Initialize();
		}
		else if(this == reinterpret_cast<USART*>(USART2Instance))
		{
			Usart2Initialize();
		}
		else if(this == reinterpret_cast<USART*>(USART3Instance))
		{
			Usart3Initialize();
		}
	}

	void USART::Usart1Initialize()
	{
		// Enable AFIO , GPIOA and USART1
		RCC->APB2ENR = (1<<0) | (1<<2) | (1<<14);
 		//PA9 to be Output alternate function for USART transmition
		GPIOA->CRH = (0x0B<<4); //1011
		//PA10 to be input floating for USART receive
		GPIOA->CRH |=(4<<8);
		double usart_div = FOSC / (BAUD);
		 BRR = usart_div;
		// Enable Transmission and Enable Reception
		 CR1 = (1<<2) | (1<<3);
		 CR1 |= (1<<13); // UE
	}

	void USART::Usart2Initialize()
	{
//		// Enable AFIO , GPIOA and USART1
//		RCC->APB2ENR = (1<<0) | (1<<2) | (1<<14);
//		//PA9 to be Output alternate function for USART transmition
//		GPIOA->CRH = (0x0B<<4); //1011
//		//PA10 to be input floating for USART receive
//		GPIOA->CRH |=(4<<8);
//		double usart_div = FOSC / (BAUD);
//		 BRR = usart_div;
//		// Enable Transmission and Enable Reception
//		 CR1 = (1<<2) | (1<<3);
//		 CR1 |= (1<<13); // UE
	}

	void USART::Usart3Initialize()
	{
//		// Enable AFIO , GPIOA and USART1
//		RCC->APB2ENR = (1<<0) | (1<<2) | (1<<14);
//		//PA9 to be Output alternate function for USART transmition
//		GPIOA->CRH = (0x0B<<4); //1011
//		//PA10 to be input floating for USART receive
//		GPIOA->CRH |=(4<<8);
//		double usart_div = FOSC / (BAUD);
//		 BRR = usart_div;
//		// Enable Transmission and Enable Reception
//		 CR1 = (1<<2) | (1<<3);
//		 CR1 |= (1<<13); // UE
	}

	void USART::setFrameSize(FrameSize fsz)
	{
		CR1 = static_cast<uint32_t>(fsz);
	}

	char USART::read()
	{
		//to stop infinite polling && (count >0
		//static uint64_t count = 1000000;
		while((! (SR & (1<<5))));
//		{
//			count--;
//		}
		return DR & 0x00FF;
	}

	void USART::sendString(char *str)
	{
		int i =0;
		while(str[i] != '\0')
		{
			sendChar(str[i++]);
		}
	}

	void USART::sendChar(char data)
	{
		DR = data & 0xFF;
		while(!(SR & (1<<7)));
	}

	void* USART::operator new(size_t, UsartInstance usart)
	{
		return reinterpret_cast<void*>(usart); //0x40013800
	}
