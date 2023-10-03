/*
 * RCC_Interface.h
 *
 *  Created on: Sep 2, 2023
 *      Author: Mohamed Aboelhassan
 */

#ifndef INC_RCC_INTERFACE_H_
#define INC_RCC_INTERFACE_H_

#include "stm32f103xb.h"
#include "Std_Types.h"

#define		RCC_AHB						0
#define		RCC_APB1					1
#define		RCC_APB2					2


/*
 * APB2 peripheral clock enable register (RCC_APB2ENR)
 * Bits 31:22 Reserved, must be kept at reset value.
 *
 *	Bit 21 TIM11EN: TIM11 timer clock enable
 *	 Set and cleared by software.
 *		0: TIM11 timer clock disabled
 *		1: TIM11 timer clock enabled
 *
 *	Bit 20 TIM10EN: TIM10 timer clock enable
 *	 Set and cleared by software.
 *		0: TIM10 timer clock disabled
 *		1: TIM10 timer clock enabled
 *
 *	Bit 19 TIM9EN: TIM9 timer clock enable
 *	 Set and cleared by software.
 *		0: TIM9 timer clock disabled
 *		1: TIM9 timer clock enabled
 *
 *	Bits 18:16 Reserved, always read as 0.
 *
 *	Bit 15 ADC3EN: ADC3 interface clock enable
 *	 Set and cleared by software.
 *		0: ADC3 interface clock disabled
 *		1: ADC3 interface clock enabled
 *
 *	Bit 14 USART1EN: USART1 clock enable
 *	 Set and cleared by software.
 *		0: USART1 clock disabled
 *		1: USART1 clock enabled
 *
 *	Bit 13 TIM8EN: TIM8 Timer clock enable
 *	 Set and cleared by software.
 *		0: TIM8 timer clock disabled
 *		1: TIM8 timer clock enabled
 *
 *	Bit 12 SPI1EN: SPI1 clock enable
 *	 Set and cleared by software.
 *		0: SPI1 clock disabled
 *		1: SPI1 clock enabled
 *
 *	Bit 11 TIM1EN: TIM1 timer clock enable
 *	 Set and cleared by software.
 *		0: TIM1 timer clock disabled
 *		1: TIM1 timer clock enabled
 *
 *	Bit 10 ADC2EN: ADC 2 interface clock enable
 *	 Set and cleared by software.
 *		0: ADC 2 interface clock disabled
 *		1: ADC 2 interface clock enabled
 *
 *	Bit 9 ADC1EN: ADC 1 interface clock enable
 *	 Set and cleared by software.
 *		0: ADC 1 interface disabled
 *		1: ADC 1 interface clock enabled
 *
 *	Bit 8 IOPGEN: IO port G clock enable
 *	 Set and cleared by software.
 *		0: IO port G clock disabled
 *		1: IO port G clock enabled
 *
 *	Bit 7 IOPFEN: IO port F clock enable
 *	 Set and cleared by software.
 *		0: IO port F clock disabled
 *		1: IO port F clock enabled
 *
 *	Bit 6 IOPEEN: IO port E clock enable
 *	 Set and cleared by software.
 *		0: IO port E clock disabled
 *		1: IO port E clock enabled
 *
 *	Bit 5 IOPDEN: IO port D clock enable
 *	 Set and cleared by software.
 *		0: IO port D clock disabled
 *		1: IO port D clock enabled
 *
 *	Bit 4 IOPCEN: IO port C clock enable
 *	 Set and cleared by software.
 *		0: IO port C clock disabled
 *		1: IO port C clock enabled
 *
 *	Bit 3 IOPBEN: IO port B clock enable
 *	 Set and cleared by software.
 *		0: IO port B clock disabled
 *		1: IO port B clock enabled
 *
 *	Bit 2 IOPAEN: IO port A clock enable
 *	 Set and cleared by software.
 *		0: IO port A clock disabled
 *		1: IO port A clock enabled
 *
 *	Bit 1 Reserved, must be kept at reset value.
 *
 *	Bit 0 AFIOEN: Alternate function IO clock enable
 *	 Set and cleared by software.
 *		0: Alternate Function IO clock disabled
 *		1: Alternate Function IO clock enabled
 * *
*/

/*		Those Peripheral on ABP2		*/
#define		RCC_AFIO					0
#define		RCC_GPIOA					2
#define		RCC_GPIOB					3
#define		RCC_GPIOC					4
#define		RCC_GPIOD					5
#define		RCC_GPIOE					6
#define		RCC_GPIOF					7
#define		RCC_GPIOG					8
#define		RCC_ADC1					9
#define		RCC_ADC2					10
#define		RCC_TIM1					11
#define		RCC_SPI1					12
#define		RCC_TIM8					13
#define		RCC_USART1					14
#define		RCC_ADC3					15
#define		RCC_TIM9					19
#define		RCC_TIM10					20
#define		RCC_TIM11					21

/*
 *
 * 	Bit 29 DACEN: DAC interface clock enable
 *	 Set and cleared by software.
 *		0: DAC interface clock disabled
 *		1: DAC interface clock enable
 *
 *	Bit 28 PWREN: Power interface clock enable
 *	 Set and cleared by software.
 *		0: Power interface clock disabled
 *		1: Power interface clock enable
 *
 *	Bit 27 BKPEN: Backup interface clock enable
 *	 Set and cleared by software.
 *		0: Backup interface clock disabled
 *		1: Backup interface clock enabled
 *
 *	Bit 26 Reserved, must be kept at reset value.
 *
 *	Bit 25 CANEN: CAN clock enable
 *	 Set and cleared by software.
 *		0: CAN clock disabled
 *		1: CAN clock enabled
 *
 *	Bit 24 Reserved, always read as 0.
 *
 *	Bit 23 USBEN: USB clock enable
 *	 Set and cleared by software.
 *		0: USB clock disabled
 *		1: USB clock enabled
 *
 *	Bit 22 I2C2EN: I2C2 clock enable
 *	 Set and cleared by software.
 *		0: I2C2 clock disabled
 *		1: I2C2 clock enabled
 *
 *	Bit 21 I2C1EN: I2C1 clock enable
 *	 Set and cleared by software.
 *		0: I2C1 clock disabled
 *		1: I2C1 clock enabled
 *
 *	Bit 20 UART5EN: USART5 clock enable
 *	 Set and cleared by software.
 *		0: USART5 clock disabled
 *		1: USART5 clock enabled
 *
 *	Bit 19 UART4EN: USART4 clock enable
 *	 Set and cleared by software.
 *		0: USART4 clock disabled
 *		1: USART4 clock enabled
 *
 *	Bit 18 USART3EN: USART3 clock enable
 *	 Set and cleared by software.
 *		0: USART3 clock disabled
 *		1: USART3 clock enabled
 *
 *	Bit 17 USART2EN: USART2 clock enable
 *	 Set and cleared by software.
 *		0: USART2 clock disabled
 *		1: USART2 clock enabled
 *
 *	Bits 16 Reserved, always read as 0.
 *
 *	Bit 15 SPI3EN: SPI 3 clock enable
 *	 Set and cleared by software.
 *		0: SPI 3 clock disabled
 *		1: SPI 3 clock enabled
 *
 *	Bit 14 SPI2EN: SPI2 clock enable
 *		Set and cleared by software.
 *		0: SPI2 clock disabled
 *		1: SPI2 clock enabled
 *
 *	Bits 13:12 Reserved, must be kept at reset value.
 *
 *	Bit 11 WWDGEN: Window watchdog clock enable
 *	 Set and cleared by software.
 *		0: Window watchdog clock disabled
 *		1: Window watchdog clock enabled
 *
 *	Bits 10:9 Reserved, must be kept at reset value.
 *
 *	Bit 8 TIM14EN: TIM14 timer clock enable
 *	 Set and cleared by software.
 *		0: TIM14 clock disabled
 *		1: TIM14 clock enabled
 *
 *	Bit 7 TIM13EN: TIM13 timer clock enable
 *	 Set and cleared by software.
 *		0: TIM13 clock disabled
 *		1: TIM13 clock enabled
 *
 *	Bit 6 TIM12EN: TIM12 timer clock enable
 *	 Set and cleared by software.
 *		0: TIM12 clock disabled
 *		1: TIM12 clock enabled
 *
 *	Bit 5 TIM7EN: TIM7 timer clock enable
 *	 Set and cleared by software.
 *		0: TIM7 clock disabled
 *		1: TIM7 clock enabled
 *
 *	Bit 4 TIM6EN: TIM6 timer clock enable
 *	 Set and cleared by software.
 *		0: TIM6 clock disabled
 *		1: TIM6 clock enabled
 *
 *	Bit 3 TIM5EN: TIM5 timer clock enable
 *	 Set and cleared by software.
 *		0: TIM5 clock disabled
 *		1: TIM5 clock enabled
 *
 *	Bit 2 TIM4EN: TIM4 timer clock enable
 *	 Set and cleared by software.
 *		0: TIM4 clock disabled
 *		1: TIM4 clock enabled
 *
 *	Bit 1 TIM3EN: TIM3 timer clock enable
 *	 Set and cleared by software.
 *		0: TIM3 clock disabled
 *		1: TIM3 clock enabled
 *
 *	Bit 0 TIM2EN: TIM2 timer clock enable
 *	 Set and cleared by software.
 *		0: TIM2 clock disabled
 *		1: TIM2 clock enabled
 * */

/*		Those Peripheral on ABP1		*/
#define		RCC_TIM2					0
#define		RCC_TIM3					1
#define		RCC_TIM4					2
#define		RCC_TIM5					3
#define		RCC_TIM6					4
#define		RCC_TIM7					5
#define		RCC_TIM12					6
#define		RCC_TIM13					7
#define		RCC_TIM14					8

#define		RCC_WWDG					11

#define		RCC_SPI2					14
#define		RCC_SPI3					15

#define		RCC_USART2					17
#define		RCC_USART3					18
#define		RCC_USART4					19
#define		RCC_USART5					20
#define		RCC_I2C1					21
#define		RCC_I2C2					22
#define		RCC_USB						23

#define		RCC_CAN						25

#define		RCC_BKP						27
#define		RCC_PWR						28
#define		RCC_DAC						29

constexpr unsigned int RCC_GPIOA_EN = (1<<2);

constexpr unsigned int RCC_GPIOB_EN = (1<<3);

constexpr unsigned int RCC_GPIOC_EN = (1<<4);

class Clock
{
public:
	Clock();
	Clock(GPIO_TypeDef* port);

	void	RCC_voidSysClockInit(void);
	void	RCC_voidEnablePerClk(uint8 BusId , uint8 PerId);
	void	RCC_voidDisablePerClk(uint8 BusId , uint8 PerId);
private:
	GPIO_TypeDef* mPort;
};


#endif /* INC_RCC_INTERFACE_H_ */
