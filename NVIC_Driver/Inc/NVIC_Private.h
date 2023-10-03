/*
 * GPIO_Private.h
 *
 *  Created on: Nov 25, 2022
 *      Author: Mohamed Aboelhassan
 */

#ifndef NVIC_PRIVATE_H_
#define NVIC_PRIVATE_H_

/*
 * NVIC system Registers addresses Defines
*/

#define		NVIC_BASE_ADD			(0xE000E100)

#define		NVIC_ISER0				*((volatile uint32 *)(NVIC_BASE_ADD+0x000))
#define		NVIC_ISER1				*((volatile uint32 *)(NVIC_BASE_ADD+0x004))
#define		NVIC_ISER2				*((volatile uint32 *)(NVIC_BASE_ADD+0x008))

#define     NVIC_ICER0              *((volatile uint32 *)(NVIC_BASE_ADD+0x080))
#define     NVIC_ICER1              *((volatile uint32 *)(NVIC_BASE_ADD+0x084))
#define     NVIC_ICER2              *((volatile uint32 *)(NVIC_BASE_ADD+0x088))

#define     NVIC_ISPR0              *((volatile uint32 *)(NVIC_BASE_ADD+0x100))
#define     NVIC_ISPR1              *((volatile uint32 *)(NVIC_BASE_ADD+0x104))
#define     NVIC_ISPR2              *((volatile uint32 *)(NVIC_BASE_ADD+0x108))

#define     NVIC_ICPR0              *((volatile uint32 *)(NVIC_BASE_ADD+0x180))
#define     NVIC_ICPR1              *((volatile uint32 *)(NVIC_BASE_ADD+0x184))
#define     NVIC_ICPR2              *((volatile uint32 *)(NVIC_BASE_ADD+0x188))

#define     NVIC_IAPR0              *((volatile uint32 *)(NVIC_BASE_ADD+0x200))
#define     NVIC_IAPR1              *((volatile uint32 *)(NVIC_BASE_ADD+0x204))
#define     NVIC_IAPR2              *((volatile uint32 *)(NVIC_BASE_ADD+0x208))

/*	Byte Access Registers	*/

#define     NVIC_IPR	             ((volatile uint8 *)(NVIC_BASE_ADD+0x300))


#endif /* NVIC_PRIVATE_H_ */
