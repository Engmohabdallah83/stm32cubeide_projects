/*
 * RCC_Interface.h
 *
 *  Created on: Nov 25, 2022
 *      Author: Mohamed Aboelhassan
 */

#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_

#define		RCC_AHB						0
#define		RCC_APB1					1
#define		RCC_APB2					2


#define		RCC_GPIOA					2
#define		RCC_GPIOB					3
#define		RCC_GPIOC					4



void	RCC_voidSysClockInit(void);
void	RCC_voidEnablePerClk(uint8 BusId , uint8 PerId);
void	RCC_voidDisablePerClk(uint8 BusId , uint8 PerId);


#endif /* RCC_INTERFACE_H_ */
