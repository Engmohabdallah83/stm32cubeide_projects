/*
 * GPIO_Prog.cpp
 *
 *  Created on: Aug 27, 2023
 *      Author: Mohamed Aboelhassan
 */
#include "GPIO_Interface.h"

#include "RCC_Interface.h"

#include "stm32f103xb.h"


constexpr unsigned char PIN_CFN_MODE_WIDTH = 4;
constexpr unsigned char RegWidth = 32;
constexpr unsigned char PORT_LOW_NIBBLE = 7;
constexpr unsigned char PORT_NIBBLE = 8;

/*
 * Set pin direction
 * get pin value
 * set pin value
 */

	GPIO::GPIO(GPIO_TypeDef* PORT, uint8_t PIN_ID): mPORT(PORT), mPIN_ID(PIN_ID)
	{
		Clock clock1(mPORT);

	}

	bool GPIO::GPIO_SetPinDir(uint8_t PIN_Dir )
	{
		if(mPIN_ID < 0 && mPIN_ID >15)
			return false;
		else
		{
			if(mPIN_ID > PORT_LOW_NIBBLE)
			{
				/* Subtract 8 from pin value in order to access CRH */
				mPIN_ID -= PORT_NIBBLE;
				/*		Clear the Specific for bits for the pin		*/
				mPORT->CRH	&=	~(0b1111<<(mPIN_ID*4));
				/*		Set the Specific for bits for the pin		*/
				mPORT->CRH	|=	 (PIN_Dir<<(mPIN_ID*4));
			}
			else
			{
				/*		Clear the Specific for bits for the pin		*/
				mPORT->CRL	&=	~(0b1111<<(mPIN_ID*4));

				/*		Set the Specific bits for the pin		*/
				mPORT->CRL	|=	 (PIN_Dir<<(mPIN_ID*4));
			}
			return true;
		}
	}

	bool GPIO::GPIO_SetPinVal(uint8_t PIN_VAL)
	{
		if(mPIN_ID < 0 && mPIN_ID >15)
			return false;
		else
		{
			switch(PIN_VAL)
			{
			case GPIO_HIGH:
				/*SET_BIT(GPIOA_ODR,Copy_u8PinId);*/
				mPORT->BSRR = (1<<mPIN_ID);
				break;
			case GPIO_LOW:
				/*CLR_BIT(GPIOA_ODR,Copy_u8PinId);*/
				mPORT->BRR = (1<<mPIN_ID);
			default:
				return false;
			}
			return true;
		}
	 }

	bool GPIO::GPIO_GetPinVal(uint8_t PIN_VAL)
	{
		if(mPIN_ID < 0 && mPIN_ID >15)
			return false;
		else
		{
			PIN_VAL = GET_BIT(mPORT->IDR,mPIN_ID);
			return true;
		}
	}
