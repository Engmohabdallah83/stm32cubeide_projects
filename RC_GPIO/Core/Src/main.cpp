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
  * Press Switch Enable Lamp
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

#define CHECK_BIT(x, pos) (x & (1UL << pos) )
#define GET_BIT(Var,BITNB)      (((Var)>>(BITNB))&0x01)

int main(void)
{
	//Enable Clock gating for GPIOB and GPIOC
	RCC->APB2ENR = (1<<3) | (1<<4);

	//Configure PB4 to be input Floating
	//GPIOB->CRL = 0x00040000;
	GPIOB->CRL = (4<<16);

	//Configure PB9 to be output pin
	GPIOB->CRH = 0x33333333;
	//GPIOB->CRH |= (3<<12); //RELAY


	//Configure PC13 to be output pin
	//GPIOA->CRL = 0x33333333;
	GPIOC->CRH = (3<<20) ;

  while (1)
  {
	  unsigned int PIN_Val = GPIOB->IDR & (1<<4);//(GET_BIT(GPIOB->IDR, 4));

	  if(PIN_Val == 0)
	  {
		 // GPIOC->ODR = (1<<(13));
		  GPIOB->ODR = (1<<9) | (1<<11); //Buzzer PIN | Relay PIN
 //		  //output High to PA1
//		  GPIOA->ODR &=~(1<<(1));
	  }
	  else
	  {
		 // GPIOC->ODR &= (~(1<<13));
		  // GPIOB->ODR &= ~(1<<9); //Buzzer PIN
		  GPIOB->ODR &= ~((1<<11) | (1<<9)); //Relay PIN
//		  //output High to PA1
//		  GPIOA->ODR |= (1<<1);
	  }
  }
}
