/*
 * GPIO_Program.c
 *
 *  Created on: Nov 30, 2022
 *      Author: Mohamed Aboelhassan
 */

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include 	"Std_Types.h"
#include	"GPIO_Interface.h"
#include 	"GPIO_Private.h"
#include 	"GPIO_Config.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : void GPIO_voidSetPinDirection(uint8 Copy_u8PortId,uint8 Copy_u8PinId,uint8 Copy_u8Diretion)
* \Description     : This function Set Stms2f103 PIN Direction
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : Copy_u8PortId   Port Identification
* \				   : Copy_u8PinId	 Pin Identification
* \				   : Copy_u8Diretion Direction Desired
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/

void GPIO_voidSetPinDirection(uint8 Copy_u8PortId,uint8 Copy_u8PinId,uint8 Copy_u8Diretion)
{
	/*		Range Check				*/
		if( (Copy_u8PinId < 8) && (Copy_u8PortId < 3))			/*	LOW Port */
		{
			switch(Copy_u8PortId)
			{
			case GPIO_PORTA:
				/*		Clear the Specific for bits for the pin		*/
				GPIOA_CRL	&=	~(0b1111<<(Copy_u8PinId*4));
				/*		Set the Specific for bits for the pin		*/
				GPIOA_CRL	|=	 (Copy_u8Diretion<<(Copy_u8PinId*4));
				break;
			case GPIO_PORTB:
				/*		Clear the Specific for bits for the pin		*/
				GPIOB_CRL	&=	~(0b1111<<(Copy_u8PinId*4));
				/*		Set the Specific for bits for the pin		*/
				GPIOB_CRL	|=	 (Copy_u8Diretion<<(Copy_u8PinId*4));
				break;
			case GPIO_PORTC:
				/*		Clear the Specific for bits for the pin		*/
				GPIOC_CRL	&=	~(0b1111<<(Copy_u8PinId*4));
				/*		Set the Specific for bits for the pin		*/
				GPIOC_CRL	|=	 (Copy_u8Diretion<<(Copy_u8PinId*4));
				break;
			}
		}
		else if( (Copy_u8PinId < 16) && (Copy_u8PortId < 3))	/*	HIGH Port */
		{
			Copy_u8PinId -= 8 ; /* Subtract 8 from pin value in order to access CRH */
			switch(Copy_u8PortId)
			{
			case GPIO_PORTA:
				/*		Clear the Specific for bits for the pin		*/
				GPIOA_CRH	&=	~(0b1111<<(Copy_u8PinId*4));
				/*		Set the Specific for bits for the pin		*/
				GPIOA_CRH	|=	 (Copy_u8Diretion<<(Copy_u8PinId*4));
				break;
			case GPIO_PORTB:
				/*		Clear the Specific for bits for the pin		*/
				GPIOB_CRH	&=	~(0b1111<<(Copy_u8PinId*4));
				/*		Set the Specific for bits for the pin		*/
				GPIOB_CRH	|=	 (Copy_u8Diretion<<(Copy_u8PinId*4));
				break;
			case GPIO_PORTC:
				/*		Clear the Specific for bits for the pin		*/
				GPIOC_CRH	&=	~(0b1111<<(Copy_u8PinId*4));
				/*		Set the Specific for bits for the pin		*/
				GPIOC_CRH	|=	 (Copy_u8Diretion<<(Copy_u8PinId*4));
				break;
			}
		}
		else
		{
			/* 		Return error		*/
		}
}

/********************************************************************************************************
* \Syntax          : void GPIO_voidSetPinValue(uint8 Copy_u8PortId,uint8 Copy_u8PinId,uint8 Copy_u8Value)
* \Description     : This Function Set PIN value as user needs
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : Copy_u8PortId	Port Identification
* \Parameters (in) : Copy_u8PinId	PIN Number Identification
* \Parameters (in) : Copy_u8Value   PIN value needed
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*********************************************************************************************************/

void GPIO_voidSetPinValue(uint8 Copy_u8PortId,uint8 Copy_u8PinId,uint8 Copy_u8Value)
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
					GPIOA_BSRR = (1<<Copy_u8PinId);
					break;
				case GPIO_PORTB:
					/*SET_BIT(GPIOB_ODR,Copy_u8PinId);*/
					GPIOB_BSRR = (1<<Copy_u8PinId);
					break;
				case GPIO_PORTC:
					/*SET_BIT(GPIOC_ODR,Copy_u8PinId);*/
					GPIOC_BSRR = (1<<Copy_u8PinId);
					break;
			}
			break;
		case GPIO_LOW:
			switch(Copy_u8PortId)
				{
					case GPIO_PORTA:
						/*CLR_BIT(GPIOA_ODR,Copy_u8PinId);*/
						GPIOA_BRR = (1<<Copy_u8PinId);
						break;
					case GPIO_PORTB:
						/*CLR_BIT(GPIOB_ODR,Copy_u8PinId);*/
						GPIOB_BRR = (1<<Copy_u8PinId);
						break;
					case GPIO_PORTC:
						/*CLR_BIT(GPIOC_ODR,Copy_u8PinId);*/
						GPIOC_BRR = (1<<Copy_u8PinId);
						break;
				}
			break;
		}
	}
	else
	{
		/*
		 * Return error
		 * */
	}
}

/***********************************************************************************************************
* \Syntax          : void GPIO_voidGetPinValue(uint8 Copy_u8PortId,uint8 Copy_u8PinId,uint8 * Copy_pu8Value)
* \Description     : This Function Set PIN value as user needs
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : Copy_u8PortId	Port Identification
* \Parameters (in) : Copy_u8PinId	PIN Number Identification
* \Parameters (in) : Copy_pu8Value   Pointer carry PIN value
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
***********************************************************************************************************/

void GPIO_voidGetPinValue(uint8 Copy_u8PortId,uint8 Copy_u8PinId,uint8 * Copy_pu8Value)
{
	/*		Range Check				*/
	if( (Copy_u8PinId < 16) && (Copy_u8PortId < 3))
	{
			switch(Copy_u8PortId)
			{
				case GPIO_PORTA:
					* Copy_pu8Value = GET_BIT(GPIOA_IDR,Copy_u8PinId);
					break;
				case GPIO_PORTB:
					* Copy_pu8Value = GET_BIT(GPIOB_IDR,Copy_u8PinId);
					break;
				case GPIO_PORTC:
					* Copy_pu8Value = GET_BIT(GPIOC_IDR,Copy_u8PinId);
					break;
			}
	}
	else
	{
		/*
		 * Return error
		 * */
	}

}

/***************************************************************************************************************
 *  END OF FILE: GPIO_Program.c
 **************************************************************************************************************/

/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Description
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
