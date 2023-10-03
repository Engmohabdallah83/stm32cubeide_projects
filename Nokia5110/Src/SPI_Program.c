/*************************************************************************************************************
 *  FILE DESCRIPTION
 *  ---------------------------------------------------------------------------------------------------------*/
/**        \file    SPI_Program.c
 *         \brief	Created on: Jan 24, 2023
 *
 *      	\details Nokia 5110 Driver Functions
 *
 *			Author: Mohamed Aboelhassan
 **************************************************************************************************************/

/**************************************************************************************************************
 *  INCLUDES
 **************************************************************************************************************/
#include "Std_Types.h"
#include "RCC_Interface.h"
#include "SPI_Private.h"
#include "GPIO_Interface.h"

/**********************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
***********************************************************************************************************/

/************************************************************************************************************
 *  LOCAL DATA
 ************************************************************************************************************/

/************************************************************************************************************
 *  GLOBAL DATA
 ***********************************************************************************************************/

/************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 ***********************************************************************************************************/

/*************************************************************************************************************
 *  LOCAL FUNCTIONS
 ************************************************************************************************************/

/*************************************************************************************************************
 *  GLOBAL FUNCTIONS
 ************************************************************************************************************/


/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
void spi_init(unsigned short spi)
{
	//RCC_APB2ENR	|= 1;	//Enable AFIO function
	//RCC->APB2ENR |= 1; //Enable AFIO function
	if(spi ==1)
	{
		// Activate SPI-1 peripheral / AFIO function
		//RCC_APB2ENR |= 0x1000; // Enabling the SPI-1 periph
		RCC_voidEnablePerClk(RCC_APB2, RCC_SPI1);
		// Set up the pin
		//init_GP(PA,4,OUT50,O_GP_PP);NSS_1
		GPIO_voidSetPinDirection(GPIO_PORTA, GPIO_PIN4, GPIO_OUTPUT_50_PP);
		//init_GP(PA,5,OUT50,O_AF_PP);SCK_1
		GPIO_voidSetPinDirection(GPIO_PORTA, GPIO_PIN5, GPIO_OUTPUT_50_PP_AF);
		//init_GP(PA,6,IN,I_PP);MISO_1
		GPIO_voidSetPinDirection(GPIO_PORTA, GPIO_PIN6, GPIO_INPUT_FL);
		//init_GP(PA,7,OUT50,O_AF_PP);MOSI_1
		GPIO_voidSetPinDirection(GPIO_PORTA, GPIO_PIN7, GPIO_OUTPUT_50_PP_AF);

		//*******Setup SPI peripherals*****
		SPI1->CR1 |= (1<<0)|(1<<1);   // CPOL=1, CPHA=1
		SPI1->CR1 |= (1<<2);  // Master Mode
		SPI1->CR1 |= (3<<3);  // BR[2:0] = 011: fPCLK/16, PCLK2 = 80MHz, SPI clk = 5MHz
		//SPI1->CR1 |= 0x0038; // fclk / 265

		SPI1->CR1 &= ~(1<<7);  // LSBFIRST = 0, MSB first

		SPI1->CR1 |= (1<<8) | (1<<9);  // SSM=1, SSi=1 -> Software Slave Management

		SPI1->CR1 &= ~(1<<10);  // RXONLY = 0, full-duplex

		SPI1->CR1 &= ~(1<<11);  // DFF=0, 8 bit data

		//SPI1->CR2 |= 0x0004; // CR2
		SPI1->CR2 = 0;
		//SPI1->CR1 |= 0x0040; // Enabling SPI periph
		SPI1->CR1 |= (1<<6);   // SPE=1, Peripheral enabled

		/*W_GP(PA,4,HIGH);//NSS*/
		GPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN4, GPIO_HIGH);
	}else if(spi == 2){
		//RCC_APB1ENR |= 0x4000; // Enabling the SPI-2 periph
		RCC_voidEnablePerClk(RCC_APB1, RCC_SPI2);

			// Set up the pin
//		init_GP(PB,12,OUT50,O_GP_PP);
		GPIO_voidSetPinDirection(GPIO_PORTB, GPIO_PIN12, GPIO_OUTPUT_50_PP);
//		init_GP(PB,13,OUT50,O_AF_PP);
		GPIO_voidSetPinDirection(GPIO_PORTB, GPIO_PIN13, GPIO_OUTPUT_50_PP_AF);
//		init_GP(PB,14,IN,I_PP);
		GPIO_voidSetPinDirection(GPIO_PORTB, GPIO_PIN14, GPIO_INPUT_FL);
//		init_GP(PB,15,OUT50,O_AF_PP);
		GPIO_voidSetPinDirection(GPIO_PORTB, GPIO_PIN15, GPIO_OUTPUT_50_PP_AF);

		//*******Setup SPI peripherals*****
		SPI2->CR1  = 0x0004; // Master Mode
		SPI2->CR1 |= 0x0038; // fclk / 265
		SPI2->CR2 |= 0x0004;
		SPI2->CR1 |= 0x0040; // Enabling SPI SPI periph
		/*W_GP(PB,12,HIGH);*/
		GPIO_voidSetPinValue(GPIO_PORTB, GPIO_PIN12, GPIO_HIGH);
	}


}

/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
void spi_tx(unsigned short spi, char tx_char)
{
	if (spi ==1 )
	{
		//W_GP(PA,4,LOW); Slave Select SS
		GPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN4, GPIO_LOW);
//		SPI1->DR = tx_char;
//		while(SPI1->SR & 0x80){}

		while (!((SPI1->SR)&(1<<1))) {};  // wait for TXE bit to set -> This will indicate that the buffer is empty
		SPI1->DR = tx_char;  // load the data into the Data Register

		while (!((SPI1->SR)&(1<<1))) {};  // wait for TXE bit to set -> This will indicate that the buffer is empty
		while (((SPI1->SR)&(1<<7))) {};  // wait for BSY bit to Reset -> This will indicate that SPI is not busy in communication

			//  Clear the Overrun flag by reading DR and SR
		uint8 temp = SPI1->DR;
		temp = SPI1->SR;
		//W_GP(PA,4,HIGH);
		GPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN4, GPIO_HIGH);
	}else if (spi ==2 )
	{
		//W_GP(PB,12,LOW);
		GPIO_voidSetPinValue(GPIO_PORTB, GPIO_PIN12, GPIO_LOW);
		SPI2->DR = tx_char;
		while(SPI2->SR & 0x80){}
		//W_GP(PB,12,HIGH);
		GPIO_voidSetPinValue(GPIO_PORTB, GPIO_PIN12, GPIO_HIGH);
	}

}

/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
void spi_msg(unsigned short spi, char str[])
{
	int i =0;
	if (spi==1)
	{
	//W_GP(PA,4,LOW);
	GPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN4, GPIO_LOW);
	while(str[i])
	{
		SPI1->DR = str[i];
		while(SPI1->SR & 0x80){}
		i++;
	}
	//W_GP(PA,4,HIGH);
	GPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN4, GPIO_HIGH);
	}
	else if (spi==2)
	{
	//W_GP(PB,12,LOW);
	GPIO_voidSetPinValue(GPIO_PORTB, GPIO_PIN12, GPIO_LOW);
	while(str[i])
	{
		SPI2->DR = str[i];
		while(SPI2->SR & 0x80){}
		i++;
	}
	//W_GP(PB,12,HIGH);
	GPIO_voidSetPinValue(GPIO_PORTB, GPIO_PIN12, GPIO_HIGH);
	}


}

/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
/*Std_ReturnType FunctionName(AnyType parameterName)
{


}*/




/************************************************************************************************************
 *  END OF FILE: SPI_Program.c
 ************************************************************************************************************/



