/*
 * GPIO_Program.c
 *
 *  Created on: Nov 30, 2022
 *      Author: Mohamed Aboelhassan
 */

#include 	"Std_Types.h"
#include	"NVIC_Interface.h"
#include 	"NVIC_Private.h"
#include 	"NVIC_Config.h"

void	NVIC_voidInit(void)
{
	/*	To apply Group and sub group priorities			*/
#ifndef		SCB_AIRCR
	#define			SCB_AIRCR			*((volatile uint32 *)(0xE000ED00+0x0C))
#endif
	SCB_AIRCR = NUM_GROUP_SUB;
}
void	NVIC_voidEnableInt(uint8 Copy_u8InterruptNum)
{
	/*		Range check				*/
	if(Copy_u8InterruptNum<32)
	{
		//SET_BIT(NVIC_ISER0,Copy_u8InterruptNum);
		NVIC_ISER0 = (1<<Copy_u8InterruptNum);
	}else if(Copy_u8InterruptNum<64)
	{
		Copy_u8InterruptNum -= 32;
		//SET_BIT(NVIC_ISER1,Copy_u8InterruptNum);
		NVIC_ISER1 = (1<<Copy_u8InterruptNum);
	}else if(Copy_u8InterruptNum<82)
	{
		Copy_u8InterruptNum -= 64;
//		SET_BIT(NVIC_ISER2,Copy_u8InterruptNum);
		NVIC_ISER2 = (1<<Copy_u8InterruptNum);
	}else
	{		/*			Report Error 		*/			}
}
void	NVIC_voidDisableInt(uint8 Copy_u8InterruptNum)
{
	/*		Range check				*/
	if(Copy_u8InterruptNum<32)
	{
//		SET_BIT(NVIC_ICER0,Copy_u8InterruptNum);
		NVIC_ICER0 = (1<<Copy_u8InterruptNum);
	}else if(Copy_u8InterruptNum<64)
	{
		Copy_u8InterruptNum -= 32;
		//SET_BIT(NVIC_ICER1,Copy_u8InterruptNum);
		NVIC_ICER1 = (1<<Copy_u8InterruptNum);
	}else if(Copy_u8InterruptNum<82)
	{
		Copy_u8InterruptNum -= 64;
		//SET_BIT(NVIC_ICER2,Copy_u8InterruptNum);
		NVIC_ICER2 = (1<<Copy_u8InterruptNum);
	}else
	{		/*			Report Error 		*/			}
}
void	NVIC_voidSetPendingFlag(uint8 Copy_u8InterruptNum)
{
	/*		Range check				*/
	if(Copy_u8InterruptNum<32)
	{
		//SET_BIT(NVIC_ISPR0,Copy_u8InterruptNum);
		NVIC_ISPR0 = (1<<Copy_u8InterruptNum);
	}else if(Copy_u8InterruptNum<64)
	{
		Copy_u8InterruptNum -= 32;
		//SET_BIT(NVIC_ISPR1,Copy_u8InterruptNum);
		NVIC_ISPR1 = (1<<Copy_u8InterruptNum);
	}else if(Copy_u8InterruptNum<82)
	{
		Copy_u8InterruptNum -= 64;
		//SET_BIT(NVIC_ISPR2,Copy_u8InterruptNum);
		NVIC_ISPR2 = (1<<Copy_u8InterruptNum);
	}else
	{		/*			Report Error 		*/			}
}

void	NVIC_voidClrPendingFlag(uint8 Copy_u8InterruptNum)
{
	/*		Range check				*/
	if(Copy_u8InterruptNum<32)
	{
		//SET_BIT(NVIC_ICPR0,Copy_u8InterruptNum);
		NVIC_ICPR0 = (1<<Copy_u8InterruptNum);
	}else if(Copy_u8InterruptNum<64)
	{
		Copy_u8InterruptNum -= 32;
		//SET_BIT(NVIC_ICPR1,Copy_u8InterruptNum);
		NVIC_ICPR1 = (1<<Copy_u8InterruptNum);

	}else if(Copy_u8InterruptNum<82)
	{
		Copy_u8InterruptNum -= 64;
		//SET_BIT(NVIC_ICPR2,Copy_u8InterruptNum);
		NVIC_ICPR2 = (1<<Copy_u8InterruptNum);

	}else
	{		/*			Report Error 		*/			}
}

void	NVIC_voidGetActiveFlag(uint8 Copy_u8InterruptNum , uint8 * Copy_pu8ActiveBit)
{
	/*		Range check				*/
	if(Copy_u8InterruptNum<32)
	{
		* Copy_pu8ActiveBit = GET_BIT(NVIC_IAPR0,Copy_u8InterruptNum);
	}else if(Copy_u8InterruptNum<64)
	{
		Copy_u8InterruptNum -= 32;
		* Copy_pu8ActiveBit = GET_BIT(NVIC_IAPR1,Copy_u8InterruptNum);
	}else if(Copy_u8InterruptNum<82)
	{
		Copy_u8InterruptNum -= 64;
		* Copy_pu8ActiveBit = GET_BIT(NVIC_IAPR2,Copy_u8InterruptNum);
	}else
	{		/*			Report Error 		*/			}
}
//	NVIC_voidSetIntPriority(30 , (0b1110) )
void	NVIC_voidSetIntPriority(uint8 Copy_u8InterruptNum , uint8 Copy_u8GrpSub )
{
	/*		Range check				*/
	if(Copy_u8InterruptNum<82)
	{
		NVIC_IPR[Copy_u8InterruptNum] = (Copy_u8GrpSub<<4);
	}else
	{		/*			Report Error 		*/			}
}

/*
 * 	IPR[2]
 *
 */



