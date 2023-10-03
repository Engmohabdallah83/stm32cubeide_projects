/*
 * RCC_Config.h
 *
 *  Created on: Nov 25, 2022
 *      Author: Mohamed Aboelhassan
 */

/*
RCC_HSI
RCC_HSE
RCC_PLL
*/

#ifndef RCC_CONGIG_H_
#define RCC_CONGIG_H_
/*
 * Please define RCC clock
 *  RCC_HSI
 *  RCC_HSE
 *  RCC_PLL
 *  to define RCC_CLK_TYPE as a clock source
*/

#define RCC_CLK_TYPE			RCC_HSI

/*
 * Check on Clock source --> if PLL
 * then determine clock source of PLL
 *
*/


#if RCC_CLK_TYPE		==		RCC_PLL
/*
RCC_PLL_HSI
RCC_PLL_HSE
*/
#define	RCC_PLL_SRC		==		RCC_PLL_HSI
#endif

/*
 * AHB prescaler
	Set and cleared by software to control the division factor of the AHB clock.
	0xxx: SYSCLK not divided		Select 0x0000
	1000: SYSCLK divided by 2		Select 0x0008
	1001: SYSCLK divided by 4		Select 0x0009
	1010: SYSCLK divided by 8		Select 0x000A
	1011: SYSCLK divided by 16		Select 0x000B
	1100: SYSCLK divided by 64		Select 0x000C
	1101: SYSCLK divided by 128		Select 0x000D
	1110: SYSCLK divided by 256		Select 0x000E
	1111: SYSCLK divided by 512		Select 0x000F
 *
*/

#endif /* RCC_CONFIG_H_ */
