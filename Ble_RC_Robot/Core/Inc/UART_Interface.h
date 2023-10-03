/*
 * UART_Interface.h
 *
 *  Created on: Sep 5, 2023
 *      Author: Mohamed Aboelhassan
 */

#ifndef INC_UART_INTERFACE_H_
#define INC_UART_INTERFACE_H_

#include "main.h"

#define USART1_BASE_ADDR 	0x40013800
#define USART2_BASE_ADDR 	0x40004400
#define USART3_BASE_ADDR 	0x40004800
#define FOSC       8000000
#define BAUD 		9600

//#include"Std_Types.h"

//struct USART_Cfg
//{
//	UsartInstance USART_I;
//	GPIO_TypeDef* USART_PORT;
//	FrameSize	FZ;
//	uint64_t BAUD_RATE;
//};

enum UsartInstance
{
	USART1Instance = USART1_BASE_ADDR,
	USART2Instance = USART2_BASE_ADDR,
	USART3Instance = USART3_BASE_ADDR
};

enum FrameSize
{
	FrameSizeEight = 0,
	FrameSizeNine
};

class USART
{
public:
	USART(UsartInstance usart);
	void Usart1Initialize();
	void Usart2Initialize();
	void Usart3Initialize();
	void setFrameSize(FrameSize fsz);
	char read();
	void sendChar(char data);
	void sendString(char *str);
	void* operator new(size_t, UsartInstance usart);
private:
	uint32_t SR;
	uint32_t DR;
	uint32_t BRR;
	uint32_t CR1;
	uint32_t CR2;
	uint32_t CR3;
	uint32_t GTPR;

};


#endif /* INC_UART_INTERFACE_H_ */
