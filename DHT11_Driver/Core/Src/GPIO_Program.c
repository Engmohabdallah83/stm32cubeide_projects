/*
 * GPIO_Program.c
 *
 *  Created on: Nov 30, 2022
 *      Author: Mohamed Aboelhassan
 */

#include 	"Std_Types.h"
#include	"GPIO_Interface.h"
#include 	"GPIO_Private.h"
#include 	"RCC_Interface.h"


Std_ReturnType GPIO_PDir(uint8 Copy_u8PortId,uint8 Copy_u8PinId,uint8 Copy_u8Diretion)
{
	/*		Range Check				*/
		if( (Copy_u8PinId < 8) && (Copy_u8PortId < 3))			/*	LOW Port */
		{
			switch(Copy_u8PortId)
			{
			case GPIO_PORTA:
				RCC_voidEnablePerClk(RCC_APB2 , RCC_GPIOA);
				/*		Clear the Specific for bits for the pin		*/
				mGPIOA->CRL	&=	~(0b1111<<(Copy_u8PinId*4));
				/*		Set the Specific for bits for the pin		*/
				mGPIOA->CRL	|=	 (Copy_u8Diretion<<(Copy_u8PinId*4));
				break;

			case GPIO_PORTB:
				RCC_voidEnablePerClk(RCC_APB2 , RCC_GPIOB);
				/*		Clear the Specific for bits for the pin		*/
				mGPIOB->CRL	&=	~(0b1111<<(Copy_u8PinId*4));
				/*		Set the Specific for bits for the pin		*/
				mGPIOB->CRL	|=	 (Copy_u8Diretion<<(Copy_u8PinId*4));
				break;

			case GPIO_PORTC:
				RCC_voidEnablePerClk(RCC_APB2 , RCC_GPIOC);
				/*		Clear the Specific for bits for the pin		*/
				mGPIOC->CRL	&=	~(0b1111<<(Copy_u8PinId*4));
				/*		Set the Specific for bits for the pin		*/
				mGPIOC->CRL	|=	 (Copy_u8Diretion<<(Copy_u8PinId*4));
				break;
			}
			return E_OK;
		}
		else if( (Copy_u8PinId < 16) && (Copy_u8PortId < 3))	/*	HIGH Port */
		{
			Copy_u8PinId -= 8 ; /* Subtract 8 from pin value in order to access CRH */
			switch(Copy_u8PortId)
			{
			case GPIO_PORTA:
				RCC_voidEnablePerClk(RCC_APB2 , RCC_GPIOA);
				/*		Clear the Specific for bits for the pin		*/
				mGPIOA->CRH	&=	~(0b1111<<(Copy_u8PinId*4));
				/*		Set the Specific for bits for the pin		*/
				mGPIOA->CRH	|=	 (Copy_u8Diretion<<(Copy_u8PinId*4));
				break;
			case GPIO_PORTB:
				RCC_voidEnablePerClk(RCC_APB2 , RCC_GPIOB);
				/*		Clear the Specific for bits for the pin		*/
				mGPIOB->CRH	&=	~(0b1111<<(Copy_u8PinId*4));
				/*		Set the Specific for bits for the pin		*/
				mGPIOB->CRH	|=	 (Copy_u8Diretion<<(Copy_u8PinId*4));
				break;
			case GPIO_PORTC:
				RCC_voidEnablePerClk(RCC_APB2 , RCC_GPIOC);
				/*		Clear the Specific for bits for the pin		*/
				mGPIOC->CRH	&=	~(0b1111<<(Copy_u8PinId*4));
				/*		Set the Specific for bits for the pin		*/
				mGPIOC->CRH	|=	 (Copy_u8Diretion<<(Copy_u8PinId*4));
				break;
			}
			return E_OK;
		}
		else
		{
			/* 		Return error		*/
			return E_NOT_OK;
		}
}

Std_ReturnType GPIO_IN_PULLUP(uint8 Copy_u8PortId , uint8 Copy_u8PinId)
{
	uint8 PinNum = Copy_u8PinId;
	/*		Range Check				*/
	if( (Copy_u8PinId < 8) && (Copy_u8PortId < 3))			/*	LOW Port */
	{
		switch(Copy_u8PortId)
		{
		case GPIO_PORTA:
			RCC_voidEnablePerClk(RCC_APB2 , RCC_GPIOA);
			/*		Clear the Specific for bits for the pin		*/
			mGPIOA->CRL	&=	~(0b1111<<(Copy_u8PinId*4));
			/*		Set the Specific for bits for the pin		*/
			mGPIOA->CRL	|=	 (GPIO_INPUT_PULL<<PinNum);
			//Set PIN PULLUP
			mGPIOA->ODR |= (1<<PinNum);
			break;

		case GPIO_PORTB:
			RCC_voidEnablePerClk(RCC_APB2 , RCC_GPIOB);
			/*		Clear the Specific for bits for the pin		*/
			mGPIOB->CRL	&=	~(0b1111<<(Copy_u8PinId*4));
			/*		Set the Specific for bits for the pin		*/
			mGPIOB->CRL	|=	 (GPIO_INPUT_PULL<<PinNum);
			//Set PIN PULLUP
			mGPIOB->ODR |= (1<<PinNum);
			break;

		case GPIO_PORTC:
			RCC_voidEnablePerClk(RCC_APB2 , RCC_GPIOC);
			/*		Clear the Specific for bits for the pin		*/
			mGPIOC->CRL	&=	~(0b1111<<(Copy_u8PinId*4));
			/*		Set the Specific for bits for the pin		*/
			mGPIOC->CRL	|=	 (GPIO_INPUT_PULL<<PinNum);
			//Set PIN PULLUP
			mGPIOC->ODR |= (1<<PinNum);
			break;
		}
		return E_OK;
	}
	else if( (Copy_u8PinId < 16) && (Copy_u8PortId < 3))	/*	HIGH Port */
	{
		Copy_u8PinId -= 8 ; /* Subtract 8 from pin value in order to access CRH */
		switch(Copy_u8PortId)
		{
		case GPIO_PORTA:
			RCC_voidEnablePerClk(RCC_APB2 , RCC_GPIOA);
			/*		Clear the Specific for bits for the pin		*/
			mGPIOA->CRH	&=	~(0b1111<<(Copy_u8PinId*4));
			/*		Set the Specific for bits for the pin		*/
			mGPIOA->CRH	|=	 (GPIO_INPUT_PULL<<(Copy_u8PinId*4));
				//Set the specified PIN to be pulled up
			mGPIOA->ODR |= (1<<PinNum);
			break;
		case GPIO_PORTB:
			RCC_voidEnablePerClk(RCC_APB2 , RCC_GPIOB);
			/*		Clear the Specific for bits for the pin		*/
			mGPIOB->CRH	&=	~(0b1111<<(Copy_u8PinId*4));
			/*		Set the Specific for bits for the pin		*/
			mGPIOB->CRH	|=	 (GPIO_INPUT_PULL<<(Copy_u8PinId*4));
			//Set the specified PIN to be pulled up
			mGPIOB->ODR |= (1<<PinNum);
			break;
		case GPIO_PORTC:
			RCC_voidEnablePerClk(RCC_APB2 , RCC_GPIOC);
			/*		Clear the Specific for bits for the pin		*/
			mGPIOC->CRH	&=	~(0b1111<<(Copy_u8PinId*4));
			/*		Set the Specific for bits for the pin		*/
			mGPIOC->CRH	|=	 (GPIO_INPUT_PULL<<(Copy_u8PinId*4));
			//Set the specified PIN to be pulled up
			mGPIOC->ODR |= (1<<PinNum);
			break;
		}
		return E_OK;
	}
	else
	{
		/* 		Return error		*/
		return E_NOT_OK;
	}
}


Std_ReturnType GPIO_IN_PULLDN(uint8 Copy_u8PortId , uint8 Copy_u8PinId)
{
	uint8 PinNum = Copy_u8PinId;
	/*		Range Check				*/
	if( (Copy_u8PinId < 8) && (Copy_u8PortId < 3))			/*	LOW Port */
		{
			switch(Copy_u8PortId)
			{
			case GPIO_PORTA:
				RCC_voidEnablePerClk(RCC_APB2 , RCC_GPIOA);
				/*		Clear the Specific for bits for the pin		*/
				mGPIOA->CRL	&=	~(0b1111<<(Copy_u8PinId*4));
				/*		Set the Specific for bits for the pin		*/
				mGPIOA->CRL	|=	 (GPIO_INPUT_PULL<<(Copy_u8PinId*4));
				//Set the specified PIN to be pulled up
				mGPIOA->ODR &= ~(1<<PinNum);
				break;

			case GPIO_PORTB:
				RCC_voidEnablePerClk(RCC_APB2 , RCC_GPIOB);
				/*		Clear the Specific for bits for the pin		*/
				mGPIOB->CRL	&=	~(0b1111<<(Copy_u8PinId*4));
				/*		Set the Specific for bits for the pin		*/
				mGPIOB->CRL	|=	 (GPIO_INPUT_PULL<<(Copy_u8PinId*4));
				mGPIOB->ODR &= ~(1<<PinNum);
				break;

			case GPIO_PORTC:
				RCC_voidEnablePerClk(RCC_APB2 , RCC_GPIOC);
				/*		Clear the Specific for bits for the pin		*/
				mGPIOC->CRL	&=	~(0b1111<<(Copy_u8PinId*4));
				/*		Set the Specific for bits for the pin		*/
				mGPIOC->CRL	|=	 (GPIO_INPUT_PULL<<(Copy_u8PinId*4));
				mGPIOC->ODR &= ~(1<<PinNum);
				break;
			}
			return E_OK;
		}
		else if( (Copy_u8PinId < 16) && (Copy_u8PortId < 3))	/*	HIGH Port */
		{
			Copy_u8PinId -= 8 ; /* Subtract 8 from pin value in order to access CRH */
			switch(Copy_u8PortId)
			{
			case GPIO_PORTA:
				RCC_voidEnablePerClk(RCC_APB2 , RCC_GPIOA);
				/*		Clear the Specific for bits for the pin		*/
				mGPIOA->CRH	&=	~(0b1111<<(Copy_u8PinId*4));
				/*		Set the Specific for bits for the pin		*/
				mGPIOA->CRH	|=	 (GPIO_INPUT_PULL<<(Copy_u8PinId*4));
				mGPIOA->ODR &= ~(1<<PinNum);
				break;
			case GPIO_PORTB:
				RCC_voidEnablePerClk(RCC_APB2 , RCC_GPIOB);
				/*		Clear the Specific for bits for the pin		*/
				mGPIOB->CRH	&=	~(0b1111<<(Copy_u8PinId*4));
				/*		Set the Specific for bits for the pin		*/
				mGPIOB->CRH	|=	 (GPIO_INPUT_PULL<<(Copy_u8PinId*4));
				mGPIOB->ODR &= ~(1<<PinNum);
				break;
			case GPIO_PORTC:
				RCC_voidEnablePerClk(RCC_APB2 , RCC_GPIOC);
				/*		Clear the Specific for bits for the pin		*/
				mGPIOC->CRH	&=	~(0b1111<<(Copy_u8PinId*4));
				/*		Set the Specific for bits for the pin		*/
				mGPIOC->CRH	|=	 (GPIO_INPUT_PULL<<(Copy_u8PinId*4));
				mGPIOA->ODR &= ~(1<<(Copy_u8PinId * 4));
				mGPIOC->ODR &= ~(1<<PinNum);
				break;
			}
			return E_OK;
		}
		else
		{
			/* 		Return error		*/
			return E_NOT_OK;

		}
}




Std_ReturnType GPIO_PW(uint8 Copy_u8PortId,uint8 Copy_u8PinId,uint8 Copy_u8Value)
{
	/*		Range Check				*/
	if( (Copy_u8PinId < 16) && (Copy_u8PortId < 3))
	{
		switch (Copy_u8Value)
		{
		case GPIO_HIGH:
			switch(Copy_u8PortId)
			{
				case GPIO_PORTA:
					/*SET_BIT(GPIOA_ODR,Copy_u8PinId);*/
					mGPIOA->BSRR = (1<<Copy_u8PinId);
					break;
				case GPIO_PORTB:
					/*SET_BIT(GPIOB_ODR,Copy_u8PinId);*/
					mGPIOB->BSRR = (1<<Copy_u8PinId);
					break;
				case GPIO_PORTC:
					/*SET_BIT(GPIOC_ODR,Copy_u8PinId);*/
					mGPIOC->BSRR = (1<<Copy_u8PinId);
					break;
			}
			break;

		case GPIO_LOW:
			switch(Copy_u8PortId)
				{
					case GPIO_PORTA:
						/*CLR_BIT(GPIOA_ODR,Copy_u8PinId);*/
						mGPIOA->BRR = (1<<Copy_u8PinId);
						break;
					case GPIO_PORTB:
						/*CLR_BIT(GPIOB_ODR,Copy_u8PinId);*/
						mGPIOB->BRR = (1<<Copy_u8PinId);
						break;
					case GPIO_PORTC:
						/*CLR_BIT(GPIOC_ODR,Copy_u8PinId);*/
						mGPIOC->BRR = (1<<Copy_u8PinId);
						break;
				}
			break;
		}
		return E_OK;
	}
	else
	{
		/*
		 * Return error
		 * */
		return E_NOT_OK;
	}
}


Std_ReturnType	GPIO_PR(uint8 Copy_u8PortId, uint8 Copy_u8PinId, uint8 * Copy_pu8Value)
{
	/*		Range Check				*/
	if( (Copy_u8PinId < 16) && (Copy_u8PortId < 3))
	{
			switch(Copy_u8PortId)
			{
				case GPIO_PORTA:
					* Copy_pu8Value = GET_BIT(mGPIOA->IDR,Copy_u8PinId);
					break;
				case GPIO_PORTB:
					* Copy_pu8Value = GET_BIT(mGPIOB->IDR,Copy_u8PinId);
					break;
				case GPIO_PORTC:
					* Copy_pu8Value = GET_BIT(mGPIOC->IDR,Copy_u8PinId);
					break;
			}
			return E_OK;
	}
	else
	{
		/*
		 * Return error
		 * */
		return E_NOT_OK;
	}

}
