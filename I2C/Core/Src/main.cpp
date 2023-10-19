/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.cpp
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
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "I2C_Cfg.h"
#include "I2C_interface.h"
/* USER CODE END Includes */



/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
	/* USER CODE BEGIN Init */
	uint8_t u8RecData = 0 , u8SendData = 'A';
	uint8_t u8AddWrt = 0x78, u8AddRd = 0b11011001;

	I2Cmcal::I2C *myI2C1 = new(I2Cmcal::I2C1Instance)  I2Cmcal::I2C();
	myI2C1->I2C_Initialize(I2C_1_CFG);
	myI2C1->I2C_Start();
	myI2C1->I2C_Address(u8AddWrt);
	myI2C1->I2C_SendData(u8SendData);
	myI2C1->I2C_Start();
	myI2C1->I2C_Address(u8AddRd);
	myI2C1->I2C_ReceiveData(&u8RecData, ENABLE);
	myI2C1->I2C_Stop();

  while (1)
  {
  }/* USER CODE END WHILE */
}

