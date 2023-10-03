/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
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
#include "mcal.h"

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


//#define GET_BIT(reg,bit)	(reg>>bit&1)
//#define SET_BIT(reg,bit)	reg |= (1<<bit)
//#define CLEAR_BIT(reg,bit)	reg &=~ (1<<bit)
//#define TOGGLE_BIT(reg,bit) reg ^= (1<<bit) //XOR
//
//class Button
//{
//public:
//	Button(GPIO_TypeDef * port, uint16_t pin):button_port(port),btn_pin(pin)
//	{
//		RCC->APB2ENR |= (1<<3); //Enable Clock for GPIOB
//		button_port->CRL = (4<<16); //configure PB4 as input pin
//	}
//	uint32_t GetButtonStatus()
//	{
//		return GET_BIT(button_port->IDR ,btn_pin);
//	}
//private:
//	GPIO_TypeDef * button_port;
//	uint16_t btn_pin{0};
//
//};
//
//class LED
//{
//public:
//	LED()
//	{
//		RCC->APB2ENR = (1<<2);
//		GPIOA->CRL = (3<<4); //PA1 as an output PIN
//	}
//	void LED_ON()
//	{
//		GPIOA->ODR = (1<<1); // Blue Led
//	}
//	void LED_OFF()
//	{
//		GPIOA->ODR &= ~(1<<1);
//	}
//};
//struct MotorType
//{
//	GPIO_TypeDef * motor_pin1_port;
//	GPIO_TypeDef * motor_pin2_port;
//	GPIO_TypeDef * enable_port;
//	uint8_t input_1{0};
//	uint8_t input_2{0};
//	uint8_t enable{0};
//};
//class Motor
//{
//public:
//	Motor( MotorType *motor) : m_motor(motor)
//	{
//		Motor_Stop();
//	}
//
//	void Motor_CW()
//	{
//		SET_BIT(m_motor->motor_pin1_port->ODR, m_motor->input_1);
//		CLEAR_BIT(m_motor->motor_pin1_port->ODR ,m_motor->input_2);
//		SET_BIT(m_motor->enable_port->ODR, m_motor->enable);
//
//	}
//	void Motor_CCW()
//	{
//
//		CLEAR_BIT(m_motor->motor_pin1_port->ODR, m_motor->input_1);
//		SET_BIT(m_motor->motor_pin1_port->ODR ,m_motor->input_2);
//		SET_BIT(m_motor->enable_port->ODR, m_motor->enable);
//
//	}
//	void Motor_Stop()
//	{
//		CLEAR_BIT(m_motor->motor_pin1_port->ODR, m_motor->input_1);
//		CLEAR_BIT(m_motor->motor_pin1_port->ODR ,m_motor->input_2);
//		CLEAR_BIT(m_motor->enable_port->ODR, m_motor->enable);
//	}
//private:
//	 MotorType *m_motor; //pimpl idiom
//};
//
//class Robot{
//public:
//	Robot(Motor m1, Motor m2) : motor1(m1), motor2(m2)
//	{
//		motor1.Motor_Stop();
//		motor2.Motor_Stop();
//	}
//	void Forward()
//	{
//		motor1.Motor_CW();
//		motor2.Motor_CCW();
//	}
//	void Backward()
//	{
//		motor1.Motor_CCW();
//		motor2.Motor_CW();
//	}
//	void Right()
//	{
//		motor1.Motor_CW();
//		motor2.Motor_Stop();
//	}
//	void Left()
//	{
//		motor1.Motor_Stop();
//		motor2.Motor_CW();
//	}
//private:
//	Motor motor1;
//	Motor motor2;
//};
//
//MotorType motor_config
//{
//GPIOC
//,
//	GPIOC,
//	GPIOC,
//	13,
//	14,
//	15
//};
//
//int main(void)
//{
//
//	LED blue_led;
//	Button button(GPIOB,4);
//
//	RCC->APB2ENR = (1<<4) | (1<<3); //Enable Clock for GPIOC and GPIOB
//	GPIOC->CRH = 0x33333333;
//	//GPIOB->CRL = (3<<4);
//
//	Motor motor1(&motor_config);
//
//
//  while (1)
//  {
//	  if(button.GetButtonStatus()==0)
//	  {
//		  motor1.Motor_CW();
//	  }
//	  else{
//		  motor1.Motor_CCW();
//
//	  }
//
//  }
//}

//int main(void)
//{
//	//enable gating for GPIOB & GPIOC
//
//	RCC->APB2ENR = RCC_GPIOB_EN | RCC_GPIOC_EN;
//
//	//pin B4 as input floating pin
//
//	GPIOB->CRL = (INPUT_FLOATING << PIN_B4 * BITS_REPRESENTS_PIN_CR); // ( 4 <<4*4 )
//
//	GPIOC->CRH = (OUTPUT_MAX_SPEED_50 << PIN_C13 * BITS_REPRESENTS_PIN_CR );
//
//	while(1)
//	{
//		uint32_t value = GPIOB->IDR & (1<<4);// button.getStatus()
//
//		if(value == 0) // pressed
//		 {
//			GPIOC->ODR |= (1<<13); // set (1)
//
//		    for(int i = 0;i<100000;i++);
//		 }
//		 else
//		 {
//			 GPIOC->ODR &= ~(1<<13); // reset (0)
//		 }
//	}
//}
 typedef enum
{
	PRESSED,
	NOT_PRESSED,
    INVALID_STATE
}status;

/************************** BUTTON CLASS **********************/
class Button
{
public:
//	Button(GPIO_TypeDef* port, uint8_t pin, uint8_t inMode) : mPort(port), mPin(pin), mMode(inMode)
//	{
//		if(mPin < 8)
//		{
//			mPort->CRL = (mMode << mPin * BITS_REPRESENTS_PIN_CR);
//		}
//		else
//		{
//			mPort->CRH = (mMode << mPin * BITS_REPRESENTS_PIN_CR);
//		}
//	}
	Button(GPIO_TypeDef* port, uint8_t pin) : mPort(port), mPin(pin)
	{
		if(mPin < 8)
		{
			mPort->CRL = (INPUT_FLOATING << mPin * BITS_REPRESENTS_PIN_CR);
		}
		else
		{
			mPort->CRH = (INPUT_FLOATING << (mPin%8) * BITS_REPRESENTS_PIN_CR);
		}
	}
	status getBtnStatus()
	{

		status value = static_cast<status>(mPort->IDR & (1<<mPin)); // read pin 4
		return value == PRESSED ? PRESSED : NOT_PRESSED;
	}
private:
	GPIO_TypeDef* mPort;
	uint8_t mPin;
//	uint8_t mMode;

};

/************************** LED CLASS ********************************/
class Led
{
public:

	Led(GPIO_TypeDef* port, uint8_t pin) : mPort(port), mPin(pin)
	{
		if(pin < 8)
		{
	      mPort->CRL = (OUTPUT_MAX_SPEED_50 << mPin * BITS_REPRESENTS_PIN_CR );
		}
		else
		{
			mPort->CRH = (OUTPUT_MAX_SPEED_50 << (mPin%8) * BITS_REPRESENTS_PIN_CR );
		}
	}
	void switchOff()
	{
		mPort->ODR &= ~(1<<mPin); // reset (0)
	}

	void switchOn()
	{
		mPort->ODR |= (1<<mPin); // set (1)
	}
private:
	GPIO_TypeDef* mPort;
	uint8_t mPin;
};

/****************** CLOCK CLASS *****************************/
class Clock
{
public:
	Clock(GPIO_TypeDef* port): mPort(port)
	{
		if(port == GPIOB)
		{
			RCC->APB2ENR |= RCC_GPIOB_EN;
		}
		else if(port == GPIOC)
		{
			RCC->APB2ENR |= RCC_GPIOC_EN;
		}

	}
private:
	GPIO_TypeDef* mPort;
};
void Delay()
{
	for(int i=0;i<10000;i++);
}
int main(void)
{
	Clock clock1(GPIOC);
	Clock clock2(GPIOB);

	Button button(GPIOB, PIN_B4); // port pin 4
	Led    led(GPIOC, PIN_C13);
	while(1)
	{
		status btnStatus = button.getBtnStatus();
		if(btnStatus == PRESSED)
		{
			led.switchOn();
			Delay();
		}
		else if(btnStatus == NOT_PRESSED)
		{
			led.switchOff();
		}
		else
		{
			/* NOT VALID STATUS */
		}
	}
}
