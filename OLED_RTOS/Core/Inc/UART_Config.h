/*
 * UART_Config.h
 *
 *  Created on: Nov 10, 2023
 *      Author: Mohamed Aboelhassan
 */

#ifndef INC_UART_CONFIG_H_
#define INC_UART_CONFIG_H_

#include "UART_Interface.h"

//#define BAUD 		9600

//typedef enum
//{
//	FrameSizeEight = 0,
//	FrameSizeNine
//}FrameSize;
//
//
//typedef enum
//{
//	ONESTOP = 0,
//	TWOSTOP
//}StopType;
//
//typedef enum
//{
//	NoParity = 0,
//	Parity
//}ParityType;
//
//typedef enum
//{
//	TxRx_Mode,
//	RX_Mode
//}ModeType;
//
//typedef enum
//{
//	NoRemap,
//	Remap
//}RemapType;
//
//
//
//typedef struct
//{
//	//USART_tStruct *USART;        	/*!< UART registers base address        */
//
//	uint32_t BaudRate;                  /*!< This member configures the UART communication baud rate.
//	                                           The baud rate is computed using the following formula:
//	                                           - IntegerDivider = ((PCLKx) / (16 * (huart->Init.BaudRate)))
//	                                           - FractionalDivider = ((IntegerDivider - ((uint32_t) IntegerDivider)) * 16) + 0.5 */
//
//	  FrameSize WordLength;                /*!< Specifies the number of data bits transmitted or received in a frame.
//	                                           This parameter can be a value of @ref UART_Word_Length */
//
//	  StopType StopBits;                  /*!< Specifies the number of stop bits transmitted.
//	                                           This parameter can be a value of @ref UART_Stop_Bits */
//
//	  uint32_t Parity;                    /*!< Specifies the parity mode.
//	                                           This parameter can be a value of @ref UART_Parity
//	                                           @note When parity is enabled, the computed parity is inserted
//	                                                 at the MSB position of the transmitted data (9th bit when
//	                                                 the word length is set to 9 data bits; 8th bit when the
//	                                                 word length is set to 8 data bits). */
//
//	  ModeType Mode;                      /*!< Specifies whether the Receive or Transmit mode is enabled or disabled.
//	                                           This parameter can be a value of @ref UART_Mode */
//
//	  RemapType	UART_Remap;					/* User Enter AFIO PIN Remap Needed or not
//	   	   	   	   	   	   	   	   	   	   	 */
//
//	  uint32_t HwFlowCtl;                 /*!< Specifies whether the hardware flow control mode is enabled or disabled.
//	                                           This parameter can be a value of @ref UART_Hardware_Flow_Control */
//
//	  uint32_t OverSampling;              /*!< Specifies whether the Over sampling 8 is enabled or disabled, to achieve higher speed (up to fPCLK/8).
//	                                           This parameter can be a value of @ref UART_Over_Sampling. This feature is only available
//	                                           on STM32F100xx family, so OverSampling parameter should always be set to 16. */
//
//}UART_InitStruct;

UART_InitStruct USART1Config = {UART1, BAUD, FrameSizeEight, ONESTOP, NoParity,TxRx_Mode, NoRemap, 0 , 0 };

#endif /* INC_UART_CONFIG_H_ */
