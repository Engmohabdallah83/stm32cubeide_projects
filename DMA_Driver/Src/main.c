/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
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

#include "Std_Types.h"

#include "RCC_Interface.h"

#include "NVIC_Interface.h"

#include "DMA_interface.h"

#include "DMA_private.h"

			uint32 arr1[1000] = {0,1,2,3,4,5,6,7,8,9};
			uint32 arr2[1000] = {0};

			uint32 arr3[1000] = {0,1,2,3,4,5,6,7,8,9};
			uint32 arr4[1000] = {0};
			uint32 i = 0 ;
int main(void)
{
	/*	RCC Init						*/
			RCC_voidSysClockInit();

			/*	RCC for Peripheral		DMA1		*/
			RCC_voidEnablePerClk(RCC_AHB, 0);

			/*		NVIC Init			*/
			NVIC_voidInit();



			DMA1_voidInit();
			/*	Enable Interrupt	DMA1 channel	*/
			NVIC_voidEnableInt(11);

			DMA1_voidStart(arr3, arr4, 1000);
			for(i = 0 ; i < 1000 ; i++)
			{
				arr2[i] = arr1[i];
			}


    /* Loop forever */
	for(;;);
}

void	DMA1_Channel1_IRQHandler(void)
{
	if((GET_BIT((DMA1 -> IFCR),0))== 1)
	{
		SET_BIT((DMA1 -> IFCR),1);
		SET_BIT((DMA1 -> IFCR),0);
	}


}
