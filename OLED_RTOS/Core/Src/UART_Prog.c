/*
 * UART_Prog.c
 *
 *  Created on: Nov 9, 2023
 *      Author: Mohamed Aboelhassan
 */

#include "UART_Interface.h"


#define E_OK		1
#define E_NOT_OK	0
const int PIN_CFG= 4;

 Std_typeReturn USART_Initialize(UsartInstance  USART_Inst ,UART_InitStruct *Init)
{
	if(USART_Inst == USART1Instance)
	{
		// Enable AFIO , GPIOA and USART1
		RCC->APB2ENR |= (1<<0) | (1<<2) | (1<<14);
 		//PA9 to be Output alternate function for USART transmition
		GPIOA->CRH = (0x0B<<(1*PIN_CFG)); //1011
		//PA10 to be input floating for USART receive
		GPIOA->CRH |=(4<<(2*PIN_CFG));

		double usart_div = FOSC / (Init->BaudRate);
		 UART1->BRR = usart_div;
		// Enable Transmission and Enable Reception
		 UART1->CR1 = (1<<2) | (1<<3);
		 UART1->CR1 |= (1<<13); // UE
	}
	else if(USART_Inst == USART2Instance)
	{
		// Enable AFIO , GPIOA
		RCC->APB2ENR |= (1<<0) | (1<<2);
		//Enable UART2
		RCC->APB1ENR |= (1<<17);
 		//PA9 to be Output alternate function for USART transmition
		GPIOA->CRL = (0x0B<<(2*PIN_CFG)); //1011
		//PA10 to be input floating for USART receive
		GPIOA->CRL |=(4<<(3*PIN_CFG));

		double usart_div = FOSC / (Init->BaudRate);
		 UART2->BRR = usart_div;
		// Enable Transmission and Enable Reception
		 UART2->CR1 = (1<<2) | (1<<3);
		 UART2->CR1 |= (1<<13); // UE
	}
	else if(USART_Inst == USART3Instance)
	{
		// Enable AFIO , GPIOB
		RCC->APB2ENR |= (1<<0) | (1<<3);
		//Enable UART3
		RCC->APB1ENR |= (1<<18);
 		//PA9 to be Output alternate function for USART transmition
		GPIOB->CRH = (0x0B<<(2*PIN_CFG)); //1011
		//PA10 to be input floating for USART receive
		GPIOB->CRH |=(4<<(3*PIN_CFG));

		double usart_div = FOSC / (Init->BaudRate);
		 UART3->BRR = usart_div;
		// Enable Transmission and Enable Reception
		 UART3->CR1 = (1<<2) | (1<<3);
		 UART3->CR1 |= (1<<13); // UE
	}
	else return E_NOT_OK;

		 return E_OK;
}




void USART_setFrameSize(UART_InitStruct * CFG, FrameSize fsz)
{
	CFG->USART->CR1 = (uint32_t)(fsz);
}

char USART_read(UART_InitStruct * CFG , uint32_t count)
{
	//to stop infinite polling && (count >0
	//static uint64_t count = 1000000;
	while( (!(CFG->USART->SR & (1<<5))) && (count>0))
	{
		count--;
	}
	return CFG->USART->DR & 0x00FF;
}

void USART_sendString(UART_InitStruct * CFG, char *str)
{
	int i =0;
	while(str[i] != '\0')
	{
		USART_sendChar(CFG , str[i++]);
	}
}

void USART_sendChar(UART_InitStruct * CFG, char data)
{
	CFG->USART->DR = data & 0xFF;
	while(!(CFG->USART->SR & (1<<7)));
}



