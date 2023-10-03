/*
 * DMA_interface.h
 *
 *  Created on: Dec 5, 2022
 *      Author: Mohamed Aboelhassan
 */

#ifndef DMA_INTERFACE_H_
#define DMA_INTERFACE_H_

void	DMA1_voidInit(void);
void	DMA1_voidStart(uint32 * Copy_pu32Src ,uint32 * Copy_pu32Des , uint16 Copy_u16Count);

#endif /* DMA_INTERFACE_H_ */
