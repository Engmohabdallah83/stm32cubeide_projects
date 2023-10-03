/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
extern "C"
{
#include "main.h"
}
#include "UART_Interface.h"
#include "LED_Lib.h"
#include "Motor_Interface.h"
#include "Robot_Cfg.h"
#include "Robot_interface.h"


int main()
{
	USART* ble = new(USART1Instance)USART(USART1Instance);

	Motor LW_Motor(&LWM_Cfg);
	Motor RW_Motor(&RWM_Cfg);

	RC_Robot My_Robot(&LW_Motor,&RW_Motor);

	GPIO HORN(GPIOB,9);

//	LED LED_G13(GPIOC , 13);
//	LED LED_G14(GPIOC, 14);
//
//	LED_G13.LED_ON();
//	LED_G14.LED_ON();

	//delay.Ms(3000);
	for(uint64_t i; i<1000000;i++);


	uint8_t control = 'N';

	//super loop
	while(true)
	{
		control =	ble->read(); //USART read from ble module

		if(control == 'F')
		{
//			LED_G13.LED_ON();
//			LED_G14.LED_OFF();
			My_Robot.MoveFWD();
		}
		else if(control == 'B')
		{
//			LED_G13.LED_OFF();
//			LED_G14.LED_ON();
			My_Robot.MoveBWD();
		}
		else if(control == 'R')
		{
			My_Robot.TurnRight();
		}
		else if(control == 'L')
		{
			My_Robot.TurnLeft();
		}
		else if(control == 'V')
		{
			HORN.GPIO_SetPinVal(GPIO_HIGH);
		}
		else
		{
			//stop
			My_Robot.Rob_Stop();
			HORN.GPIO_SetPinVal(GPIO_LOW);
//			LED_G13.LED_OFF();
//			LED_G14.LED_OFF();
		}
		//for(uint64_t i; i<10000000;i++);
	}//End Infinite while loop
	return 0;
}
