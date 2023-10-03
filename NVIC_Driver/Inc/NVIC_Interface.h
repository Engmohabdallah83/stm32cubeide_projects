/*
 * GPIO_Interface.h
 *
 *  Created on: Nov 25, 2022
 *      Author: Mohamed Aboelhassan
 */

#ifndef NVIC_INTERFACE_H_
#define NVIC_INTERFACE_H_

void	NVIC_voidInit(void);
void	NVIC_voidEnableInt(uint8 Copy_u8InterruptNum);
void	NVIC_voidDisableInt(uint8 Copy_u8InterruptNum);
void	NVIC_voidSetPendingFlag(uint8 Copy_u8InterruptNum);
void	NVIC_voidClrPendingFlag(uint8 Copy_u8InterruptNum);
void	NVIC_voidGetActiveFlag(uint8 Copy_u8InterruptNum , uint8 * Copy_pu8ActiveBit);
void	NVIC_voidSetIntPriority(uint8 Copy_u8InterruptNum , uint8 Copy_u8GrpSub );


#endif /* NVIC_INTERFACE_H_ */
