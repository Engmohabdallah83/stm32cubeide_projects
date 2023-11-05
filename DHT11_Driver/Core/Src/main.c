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
//#include "main.h"
#include "GPIO_Interface.h"
#include "STK_Interface.h"
#include "RCC_Interface.h"
#include "DHT11_Interface.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
//void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */





/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

	float f32Humid=0 , f32Temp = 0;

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  //HAL_Init();

	/*	RCC Init						*/
	RCC_voidSysClockInit();

	/* USER CODE BEGIN Init */
//	GPIO_PDir(GPIO_PORTC, GPIO_PIN13, GPIO_OUTPUT_50_PP);
//	GPIO_PDir(GPIO_PORTB, GPIO_PIN4, GPIO_INPUT_PULL);
	STK_vidInit();

	/* USER CODE END Init */



  /* Initialize all configured peripherals */
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */
  //uint8 u8SwVal = 0;


  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
//	  GPIO_PR(GPIO_PORTB, GPIO_PIN4, &u8SwVal);
//
//	  if(u8SwVal == 0)
//	  {
//		  GPIO_PW(GPIO_PORTC, GPIO_PIN13, GPIO_LOW);
//		  Delay_ms(1000);
////		  for(uint32 i=0; i<10000; i++)
////		  {
////			//  asm("NOP");
////		  }
//	  }
//	  else
//	  {
//		  GPIO_PW(GPIO_PORTC, GPIO_PIN13, GPIO_HIGH);
//		  Delay_ms(980);
//		  GPIO_PW(GPIO_PORTC, GPIO_PIN13, GPIO_LOW);
//		  Delay_ms(980);
////		  for(uint32 i=0; i<10000; i++)
////		  {
////			//  asm("NOP");
////		  }
//	  }

	  DHT11_ReadData(&f32Humid, &f32Temp);

	  Delay_ms(3000);

	  /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}
