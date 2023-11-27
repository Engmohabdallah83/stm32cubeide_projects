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
#include "DHT11_Interface.h"
#include "UART_Config.h"
#include "UART_Interface.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

#define Welcome		0u
#define Bluetooth	1u
#define Reading		2u


/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
SemaphoreHandle_t Mutex; 	//define MUTEX of SemaphoreHandle_t
xQueueHandle xQueue;		//define a Queue
xQueueHandle xQFlag;		//define a Queue

I2C_HandleTypeDef hi2c1;	//Create an instance of I2C_1

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */
static void MX_GPIO_Init(void);		//I2C GPIO initialization prototype
static void MX_I2C1_Init(void);		//I2C1 initialization prototype

void CheckReq(void *pvParameter);	//Task welcome prototype
void DHT11Sensor(void *pvParameter); //Task DHT11Sensor prototype
void DisplayScreen(uint8_t u8Switch);
void ActuatorTask(void *pvParameter);//Task Actuator prototype
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
//	RCC->APB2ENR = (1<<2); //Enable GPIOA CLK  Enabled with I2C MX_GPIO_Init Function
//	GPIOA->CRL = (3<<4) | (3<<8); // configure PA1 = blue led as output pin

//	while( HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_5) );
//	GPIOA->ODR |=(1<<1);

	Mutex = xSemaphoreCreateMutex();  //Mutex creation
	xQueue = xQueueCreate(1,sizeof(uint8_t)); //create a Queue of a size one uint8_t for temp
	xQFlag = xQueueCreate (1,sizeof(uint8_t)); //Create another Queue for flag

	MX_GPIO_Init();
	MX_I2C1_Init();
	SSD1306_Init();
	USART_Initialize(USART1Instance, &USART1Config);

//	Test Input
	GPIO_InitTypeDef PB5_IN  = {GPIO_PIN_5, GPIO_MODE_INPUT, GPIO_PULLUP, GPIO_SPEED_FREQ_HIGH};
	GPIO_InitTypeDef PA1_OUT = {GPIO_PIN_1, GPIO_MODE_OUTPUT_PP, GPIO_PULLUP, GPIO_SPEED_FREQ_HIGH};

	__HAL_RCC_GPIOB_CLK_ENABLE(); //ENABLE PORTB CLOCK
	__HAL_RCC_GPIOA_CLK_ENABLE(); //ENABLE PORTA CLOCK

//	RCC->APB2ENR |= (1<<2) ; //Enable GPIOA
	HAL_GPIO_Init(GPIOB, &PB5_IN); //Initialize PORTB pin 5 as input
	HAL_GPIO_Init(GPIOA, &PA1_OUT); //Initialize PORTA pin 1 as output
	//GPIOA->CRL |=  (3<<4); // configure PA1 = blue led as output pin | (3<<8)
  /* USER CODE BEGIN 2 */

//  GPIOA->ODR |=(1<<1);

   DisplayScreen(Welcome);
   //vTaskDelay(4000/portTICK_PERIOD_MS);
   ForDelay_us(2000000);

  if(Mutex != NULL)
  {

//	  xTaskCreate(ClearTask, "Clear_Task", 300, NULL, 3, NULL);
	  xTaskCreate(CheckReq, "CheckReq", 300, NULL, 1, NULL);
	  //xQueueSendToBack(xQueue,&StartFlag,portMAX_DELAY);
	  vTaskStartScheduler();
  }
  else
  {}

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

void DisplayScreen(uint8_t u8Switch)
{
	switch(u8Switch)
	{
	case Welcome:

		SSD1306_Clear();
		SSD1306_GotoXY (15,0);
		SSD1306_Puts ("Robotics", &Font_11x18, 1);
		SSD1306_GotoXY (10, 20);
		SSD1306_Puts ("Corner G7", &Font_11x18, 1);
		SSD1306_GotoXY (25, 40);
		SSD1306_Puts ("Project", &Font_11x18, 1);
		SSD1306_UpdateScreen();

		SSD1306_ScrollRight(0,7);
		//HAL_Delay(2000);
		ForDelay_us(1500000);

		SSD1306_ScrollLeft(0,7);
		//HAL_Delay(3500);
		ForDelay_us(1500000);
		SSD1306_Stopscroll();
		break;

	case Bluetooth:
		SSD1306_Clear();
		SSD1306_GotoXY (10,0);
		SSD1306_Puts ("Press W", &Font_11x18, 1);
		SSD1306_GotoXY (10, 20);
		SSD1306_Puts ("On App", &Font_11x18, 1);
		SSD1306_GotoXY (10, 40);
		SSD1306_Puts ("to Read", &Font_11x18, 1);
		SSD1306_UpdateScreen();
		break;

	case Reading:

		SSD1306_Clear();
		SSD1306_GotoXY (0,0);
		SSD1306_Puts ("Temp: ", &Font_11x18, 1);
		SSD1306_GotoXY (0, 20);
		SSD1306_Puts ("Hum : ", &Font_11x18, 1);
		SSD1306_GotoXY (0, 40);
		SSD1306_Puts ("Act : ", &Font_11x18, 1);
		SSD1306_UpdateScreen();

		break;
	}//Switch
}//Display Fun

void CheckReq(void *pvParameter)
{
//	uint8_t Flag = 0;
	TaskHandle_t xTaskTempHandle = NULL;
	DisplayScreen(Bluetooth);
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
//		GPIOA->ODR |=(1<<1);

//		if( (!(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_5))) )
		//vTaskDelay(3000/portTICK_PERIOD_MS);
		if((USART_read(&USART1Config, 1000)) == 'F' || (USART_read(&USART1Config, 1000)) == 'f')

		{
			DisplayScreen(Reading);
			vTaskDelay(2000/portTICK_PERIOD_MS);
			xTaskCreate(DHT11Sensor, "DHT11SensorTask", 300, NULL, 2, &xTaskTempHandle);
			vTaskDelay(2000/portTICK_PERIOD_MS);
		}

//		HAL_Delay (1000);
//		xSemaphoreGive(Mutex);

//		xQueueSendToBack(xQueue,&Flag,portMAX_DELAY);
	}
}

/*
 * Read DHT11 Sensor
 * Display Reading on OLED
 * Check Temperature threshold
 */
void DHT11Sensor(void *pvParameter)
{
	static float Temp = 0;
	static float Humid = 0;
	char snum[5];

	TaskHandle_t xTaskTempHandle = (TaskHandle_t)pvParameter;
	TaskHandle_t xTaskActHandle = NULL;

	while(1)
	{
//		xSemaphoreTake(Mutex, portMAX_DELAY);
//		if(xQueue != NULL)
//		{
//			xQueueReceive(xQueue, &Temp,portMAX_DELAY);
//		}

		DHT11_ReadData(&Humid, &Temp);
		xQueueSendToBack(xQueue, &Temp, portMAX_DELAY);

		//display Temperature
		itoa( ((int)Temp), snum, 10);//integer to ASCII
//		SSD1306_Clear();
		SSD1306_GotoXY (60 , 0);
		SSD1306_Puts("  ", &Font_11x18, 1);
		SSD1306_GotoXY (60 , 0);
		SSD1306_Puts (snum, &Font_11x18, 1);
		SSD1306_UpdateScreen();

		//Display Humidity
		itoa( ((int)Humid), snum, 10);//integer to ASCII
		SSD1306_GotoXY (60 , 20);
		SSD1306_Puts("  ", &Font_11x18, 1);
		SSD1306_GotoXY (60 , 20);
		SSD1306_Puts (snum, &Font_11x18, 1);
		SSD1306_UpdateScreen();
//		HAL_Delay (1000);
//		xSemaphoreGive(Mutex);
//		vTaskDelay(1000/portTICK_PERIOD_MS);

		vTaskDelay(1000/portTICK_PERIOD_MS);
		xTaskCreate(ActuatorTask, "ActuatorTask", 300, NULL, 3, &xTaskActHandle);
		vTaskDelay(2000/portTICK_PERIOD_MS);

		vTaskDelete( xTaskTempHandle );
	}
}


/*
 * check Temperature degree from Queue
 * Actuate Actuator on/off according to Temperature
 * Display on OLED Actuator status
 */
void ActuatorTask(void *pvParameter)
{
	static uint32_t Temp = 0;
	TaskHandle_t xTaskTempHandle = (TaskHandle_t)pvParameter;

	while(1)
	{
//		TODO Actuator status if reading was not sent to Queue
//		xSemaphoreTake(Mutex, portMAX_DELAY);
		if(xQueue != NULL)
		{
			xQueueReceive(xQueue, &Temp, portMAX_DELAY);

			if( ((uint32_t)Temp) >= 24u)
			{
				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET);

				SSD1306_GotoXY (60,40);
				SSD1306_Puts("  ", &Font_11x18, 1);
				SSD1306_GotoXY (60,40);
				SSD1306_Puts ("ON", &Font_11x18, 1);
				SSD1306_UpdateScreen();
			}
			else
			{
				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_RESET);

				SSD1306_GotoXY (60,40);
				SSD1306_Puts("    ", &Font_11x18, 1);
				SSD1306_GotoXY (60,40);
				SSD1306_Puts ("OFF", &Font_11x18, 1);
				SSD1306_UpdateScreen();
			}
		}

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
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
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
