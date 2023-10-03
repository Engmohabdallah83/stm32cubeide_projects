/*
 * RCC_Private.h
 *
 *  Created on: Nov 25, 2022
 *      Author: Mohamed Aboelhassan
 */

#ifndef RCC_PRIVATE_H_
#define RCC_PRIVATE_H_
/*
 * Clock Source selections in Config file
 *
*/

#define RCC_HSI		0
#define RCC_HSE		1
#define RCC_PLL		2
/************************************************/
/*
 * PLL clock source in case RCC_PLL selected as RCC_CLK_Type
 *
*/
#define	RCC_PLL_HSI	3
#define	RCC_PLL_HSE	4

/*
 * RCC system Registers addresses Defines
*/

#define		RCC_BASE_ADD			(0x40021000)

#define		RCC_CR					*((volatile uint32 *)(RCC_BASE_ADD+0x00))
#define		RCC_CFGR				*((volatile uint32 *)(RCC_BASE_ADD+0x04))
#define		RCC_AHBENR				*((volatile uint32 *)(RCC_BASE_ADD+0x14))
#define		RCC_APB2ENR				*((volatile uint32 *)(RCC_BASE_ADD+0x18))
#define		RCC_APB1ENR				*((volatile uint32 *)(RCC_BASE_ADD+0x1c))


#endif /* RCC_PRIVATE_H_ */
