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

typedef unsigned char Std_typeReturn;

//#include"Std_Types.h"

//struct USART_Cfg
//{
//	UsartInstance USART_I;
//	GPIO_TypeDef* USART_PORT;
//	FrameSize	FZ;
//	uint64_t BAUD_RATE;
//};

typedef struct
{
	uint32_t SR;
	uint32_t DR;
	uint32_t BRR;
	uint32_t CR1;
	uint32_t CR2;
	uint32_t CR3;
	uint32_t GTPR;
}USART_tStruct;

typedef enum
{
	USART1Instance = USART1_BASE_ADDR,
	USART2Instance = USART2_BASE_ADDR,
	USART3Instance = USART3_BASE_ADDR
}UsartInstance;

#define UART1              ((USART_tStruct *)USART1_BASE_ADDR)
#define UART2              ((USART_tStruct *)USART2_BASE_ADDR)
#define UART3              ((USART_tStruct *)USART3_BASE_ADDR)

typedef enum
{
	FrameSizeEight = 0,
	FrameSizeNine
}FrameSize;


typedef enum
{
	ONESTOP = 0,
	TWOSTOP
}StopType;

typedef enum
{
	NoParity = 0,
	Parity
}ParityType;

typedef enum
{
	TxRx_Mode,
	RX_Mode
}ModeType;

typedef enum
{
	NoRemap,
	Remap
}RemapType;



typedef struct
{
	USART_tStruct * USART;        		/*!< UART registers base address        */

	uint32_t BaudRate;                  /*!< This member configures the UART communication baud rate.
	                                           The baud rate is computed using the following formula:
	                                           - IntegerDivider = ((PCLKx) / (16 * (huart->Init.BaudRate)))
	                                           - FractionalDivider = ((IntegerDivider - ((uint32_t) IntegerDivider)) * 16) + 0.5 */

	  FrameSize WordLength;                /*!< Specifies the number of data bits transmitted or received in a frame.
	                                           This parameter can be a value of @ref UART_Word_Length */

	  StopType StopBits;                  /*!< Specifies the number of stop bits transmitted.
	                                           This parameter can be a value of @ref UART_Stop_Bits */

	  uint32_t Parity;                    /*!< Specifies the parity mode.
	                                           This parameter can be a value of @ref UART_Parity
	                                           @note When parity is enabled, the computed parity is inserted
	                                                 at the MSB position of the transmitted data (9th bit when
	                                                 the word length is set to 9 data bits; 8th bit when the
	                                                 word length is set to 8 data bits). */

	  ModeType Mode;                      /*!< Specifies whether the Receive or Transmit mode is enabled or disabled.
	                                           This parameter can be a value of @ref UART_Mode */

	  RemapType	UART_Remap;					/* User Enter AFIO PIN Remap Needed or not
	   	   	   	   	   	   	   	   	   	   	 */

	  uint32_t HwFlowCtl;                 /*!< Specifies whether the hardware flow control mode is enabled or disabled.
	                                           This parameter can be a value of @ref UART_Hardware_Flow_Control */

	  uint32_t OverSampling;              /*!< Specifies whether the Over sampling 8 is enabled or disabled, to achieve higher speed (up to fPCLK/8).
	                                           This parameter can be a value of @ref UART_Over_Sampling. This feature is only available
	                                           on STM32F100xx family, so OverSampling parameter should always be set to 16. */

}UART_InitStruct;


Std_typeReturn USART_Initialize(UsartInstance  USART ,UART_InitStruct *Init);
void USART_setFrameSize(UART_InitStruct * CFG, FrameSize fsz);
char USART_read(UART_InitStruct * CFG, uint32_t count);
void USART_sendString(UART_InitStruct * CFG, char *str);
void USART_sendChar(UART_InitStruct * CFG, char data);

#endif /* INC_UART_INTERFACE_H_ */
