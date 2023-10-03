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
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "SPI_Interface.h"
#include "SPI_Cfg.h"


int main(void)
{

  /* USER CODE BEGIN Init */
	mcal::SPI *mySPI1 = new(mcal::SPI1Instance)  mcal::SPI();
	mySPI1->SPI_Initialize(SPI_1_CFG);
  /* USER CODE END Init */
	uint8_t x = 'A';

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  mySPI1->SPI_SendData(x);
  }/* END while */
}/* MAIN END */
