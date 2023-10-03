/*
 * DMA_prog.c
 *
 *  Created on: Dec 5, 2022
 *      Author: Mohamed Aboelhassan
 */

#include "Std_Types.h"

#include "DMA_interface.h"
#include "DMA_private.h"
#include "DMA_Config.h"


void	DMA1_voidInit(void)
{
	/*
	 *	1- Mem to Mem
	 *	2- Enable Transfere complete interrupt
	 *	3- MINC and PINC Enable
	 *	4- Disable Circular
	 *	5- Low priority
	 *	6- MemSize and PerSize = u32
	 *	7- Dir Read from memory
	 *	8- TCIE enable
	 *	9- Disable the Channel
	 *
	 */
	DMA1 -> Ch[0].CCR = 0x00004AD2;
}
void	DMA1_voidStart(uint32 * Copy_pu32Src ,uint32 * Copy_pu32Des , uint16 Copy_u16Count)
{
	/*		Disable Channel		*/
	CLR_BIT((DMA1 -> Ch[0].CCR),0);

	DMA1 -> Ch[0].CMAR = Copy_pu32Src;
	DMA1 -> Ch[0].CPAR = Copy_pu32Des;
	DMA1 -> Ch[0].CNDTR = Copy_u16Count;

	/*		Enable Channel		*/
	SET_BIT((DMA1 -> Ch[0].CCR),0);
}
