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
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include "fonts.h"
#include "ssd1306.h"

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
SemaphoreHandle_t Mutex; 	//define MUTEX of SemaphoreHandle_t
xQueueHandle xQueue;		//define a Queue

I2C_HandleTypeDef hi2c1;	//Create an instance of I2C_1

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */
static void MX_GPIO_Init(void);		//I2C GPIO initialization prototype
static void MX_I2C1_Init(void);		//I2C1 initialization prototype

void Welcome(void *pvParameter);	//Task welcome prototype
void TempSensor(void *pvParameter); //Task Tempsensor prototype
//void ClearTask(void *pvParameter);

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
//	uint8_t StartFlag = 0;

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  /* USER CODE BEGIN 2 */
  RCC->APB2ENR = (1<<2); //Enable GPIOA
  GPIOA->CRL = (3<<4) | (3<<8); // configure PA1 = blue led as output pin

  Mutex = xSemaphoreCreateMutex();  //Mutex creation
  xQueue = xQueueCreate(1,sizeof(char)); //create a Queue

  MX_GPIO_Init();
  MX_I2C1_Init();
  /* USER CODE BEGIN 2 */
  SSD1306_Init();



  GPIOA->ODR |=(1<<1);

  SSD1306_GotoXY (0,0);
  SSD1306_Puts ("Robotics", &Font_11x18, 1);
  SSD1306_GotoXY (0, 30);
  SSD1306_Puts ("Corner", &Font_11x18, 1);
  SSD1306_UpdateScreen();
//  HAL_Delay (1000);
  for(double i=0;i<100000;i++);
  SSD1306_Clear();


  if(Mutex != NULL)
  {
	  RCC->APB2ENR = (1<<2); //Enable GPIOA
	  GPIOA->CRL = (3<<4) | (3<<8); // configure PA1 = blue led as output pin
	  GPIOA->ODR |=(1<<1);

//	  xTaskCreate(ClearTask, "Clear_Task", 300, NULL, 3, NULL);
	  xTaskCreate(Welcome, "WelcomeTask", 300, NULL, 1, NULL);

	  //xQueueSendToBack(xQueue,&StartFlag,portMAX_DELAY);

	  vTaskStartScheduler();
  }
  else
  {

  }

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
  return 0;
}

//void ClearTask(void *pvParameter)
//{
//	SSD1306_Clear();
////	vTaskDelay(200/portTICK_PERIOD_MS);
//}

void Welcome(void *pvParameter)
{
//	uint8_t Flag = 0;
	TaskHandle_t xTaskTempHandle = NULL;

	while(1)
	{
//		xSemaphoreTake(Mutex, portMAX_DELAY);

//		if(xQueue != NULL)
//				xQueueReceive(xQueue, &Flag,portMAX_DELAY);
//		if(Flag == 0)
//		{
//			Flag =1;
//			SSD1306_Clear();
//		}

			SSD1306_Clear();
		GPIOA->ODR |=(1<<1);

		SSD1306_GotoXY (0,0);
		SSD1306_Puts ("WELCOME", &Font_11x18, 1);
		SSD1306_GotoXY (0, 30);
		SSD1306_Puts ("TASK:", &Font_11x18, 1);
		SSD1306_UpdateScreen();
//		HAL_Delay (1000);
//		xSemaphoreGive(Mutex);
		vTaskDelay(2000/portTICK_PERIOD_MS);
		xTaskCreate(TempSensor, "TempSensorTask", 300, NULL, 2, &xTaskTempHandle);
		vTaskDelay(2000/portTICK_PERIOD_MS);
//		xQueueSendToBack(xQueue,&Flag,portMAX_DELAY);

	}
}

void TempSensor(void *pvParameter)
{
//	uint8_t Flag = 1;
	TaskHandle_t xTaskTempHandle = (TaskHandle_t)pvParameter;

	while(1)
	{

//		xSemaphoreTake(Mutex, portMAX_DELAY);
//		if(xQueue != NULL)
//		{
//			xQueueReceive(xQueue, &Flag,portMAX_DELAY);
//		}
//		if(Flag != 0)
//		{
//			Flag = 0;
//			SSD1306_Clear();
//		}
			SSD1306_Clear();
		GPIOA->ODR &=~(1<<1);
		SSD1306_GotoXY (0,0);
		SSD1306_Puts ("TEMP", &Font_11x18, 1);
		SSD1306_GotoXY (0, 30);
		SSD1306_Puts ("TASK : ", &Font_11x18, 1);
		SSD1306_UpdateScreen();
//		HAL_Delay (1000);
//		xSemaphoreGive(Mutex);
//		vTaskDelay(1000/portTICK_PERIOD_MS);

		vTaskDelete( xTaskTempHandle );
		//		xQueueSendToBack(xQueue,&Flag,portMAX_DELAY);

	}
}


static void MX_I2C1_Init(void)
{

  /* USER CODE BEGIN I2C1_Init 0 */

  /* USER CODE END I2C1_Init 0 */

  /* USER CODE BEGIN I2C1_Init 1 */

  /* USER CODE END I2C1_Init 1 */
  hi2c1.Instance = I2C1;
  hi2c1.Init.ClockSpeed = 400000;
  hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c1.Init.OwnAddress1 = 0;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C1_Init 2 */

  /* USER CODE END I2C1_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

}





















/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
