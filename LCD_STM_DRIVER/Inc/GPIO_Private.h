/*
 * GPIO_Private.h
 *
 *  Created on: Nov 25, 2022
 *      Author: Mohamed Aboelhassan
 */

#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_

/*
 * GPIO system Registers addresses Defines
*/

#define		GPIOA_BASE_ADD			(0x40010800)

#define		GPIOA_CRL				*((volatile uint32 *)(GPIOA_BASE_ADD+0x00))
#define		GPIOA_CRH				*((volatile uint32 *)(GPIOA_BASE_ADD+0x04))
#define		GPIOA_IDR				*((volatile uint32 *)(GPIOA_BASE_ADD+0x08))
#define		GPIOA_ODR				*((volatile uint32 *)(GPIOA_BASE_ADD+0x0C))
#define		GPIOA_BSRR				*((volatile uint32 *)(GPIOA_BASE_ADD+0x10))
#define		GPIOA_BRR				*((volatile uint32 *)(GPIOA_BASE_ADD+0x14))
#define		GPIOA_LCKR				*((volatile uint32 *)(GPIOA_BASE_ADD+0x18))

#define		GPIOB_BASE_ADD			(0x40010C00)

#define		GPIOB_CRL				*((volatile uint32 *)(GPIOB_BASE_ADD+0x00))
#define		GPIOB_CRH				*((volatile uint32 *)(GPIOB_BASE_ADD+0x04))
#define		GPIOB_IDR				*((volatile uint32 *)(GPIOB_BASE_ADD+0x08))
#define		GPIOB_ODR				*((volatile uint32 *)(GPIOB_BASE_ADD+0x0C))
#define		GPIOB_BSRR				*((volatile uint32 *)(GPIOB_BASE_ADD+0x10))
#define		GPIOB_BRR				*((volatile uint32 *)(GPIOB_BASE_ADD+0x14))
#define		GPIOB_LCKR				*((volatile uint32 *)(GPIOB_BASE_ADD+0x18))

#define		GPIOC_BASE_ADD			(0x40011000)

#define		GPIOC_CRL				*((volatile uint32 *)(GPIOC_BASE_ADD+0x00))
#define		GPIOC_CRH				*((volatile uint32 *)(GPIOC_BASE_ADD+0x04))
#define		GPIOC_IDR				*((volatile uint32 *)(GPIOC_BASE_ADD+0x08))
#define		GPIOC_ODR				*((volatile uint32 *)(GPIOC_BASE_ADD+0x0C))
#define		GPIOC_BSRR				*((volatile uint32 *)(GPIOC_BASE_ADD+0x10))
#define		GPIOC_BRR				*((volatile uint32 *)(GPIOC_BASE_ADD+0x14))
#define		GPIOC_LCKR				*((volatile uint32 *)(GPIOC_BASE_ADD+0x18))


#endif /* GPIO_PRIVATE_H_ */
