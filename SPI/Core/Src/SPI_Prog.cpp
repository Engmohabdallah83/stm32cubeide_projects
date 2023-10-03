/*
 * SPI_Prog.cpp
 *
 *  Created on: Sep 25, 2023
 *      Author: Mohamed Aboelhassan
 */

#include "SPI_Interface.h"
#include "GPIO_Interface.h"



mcal::SPI::SPI()
{

}
void mcal::SPI::SPI_Initialize(mcal::SPI_CFG& spiCFG)
{
	if(this == reinterpret_cast<SPI*>(SPI1Instance))
	{
		//Enable SPI1 Peripheral clock
		RCC->APB2ENR |= (1<<12);

		SPI1_Initialize(spiCFG);
	}
	else if(this == reinterpret_cast<SPI*>(SPI2Instance))
	{
		//Enable SPI2 Peripheral clock
		RCC->APB1ENR = (1<<14);

		SPI2_Initialize(spiCFG);
	}
}

void mcal::SPI::SPI1_Initialize(mcal::SPI_CFG spi1CFG)
{

	if(spi1CFG.SPI_REMAP)
	{
		//Enable AFIO, GPIOA and GPIOB
		RCC->APB2ENR |=(1<<0)| (1<<2)| (1<<3);
		AFIO->MAPR |= (0X00000001);		// Reset and mask
		//REMAP MOSI1 PB5 Alternate Fun PP, MISO1 PB4 Input Pull UP/DN, SCK1  PB3 Alternate Fun PP
		GPIOB->CRL &= 0x11000111;
		GPIOB->CRL |= (0xB << 20) | (0x8 << 16) | (0xB << 12);
	}
	else
	{
		//Enable AFIO and GPIOA
		RCC->APB2ENR |=(1<<0)| (1<<2);
		//MOSI1 PA7 Alternate Fun PP, MISO1 PA6 Input Pull UP/DN, SCK1  PA5 Alternate Fun PP
		GPIOA->CRL &= 0x00011111;		// Reset and mask
		GPIOA->CRL |= (0xB << 28) | (0x8 << 24) | (0xB << 20);
		//AFIO re-map = 0
		AFIO->MAPR &= ~(0X00000001);
	}

//	myCR1CFG = (spi1CFG.SPI_CPHA<<0)|(spi1CFG.SPI_CPOL<<1)|(spi1CFG.SPI_MSTR<<2)|
//			(spi1CFG.SPI_BRGH<<3)|(spi1CFG.SPI_SPE<<6) |(spi1CFG.SPI_LSBFIRST<<7)|
//			(spi1CFG.SPI_SSM <<9)|(spi1CFG.SPI_RXONLY <<10)|(spi1CFG.SPI_DFF<<11)|
//			(spi1CFG.SPI_CRCNEXT<<12)|(spi1CFG.SPI_CRCEN<<13)|(spi1CFG.SPI_BIDIOE<<14)|
//			(spi1CFG.SPI_BIDIMODE<<15);

	CR1 |= (uint16)((spi1CFG.SPI_CRCEN<<13) | (spi1CFG.SPI_CRCNEXT<<12));

	CR1 |= (spi1CFG.SPI_BRGH<<3);		//Set Pre-scaler for BAUD RATE
	CR1 |= (spi1CFG.SPI_CPHA<<0);		//Set Clock phase the 1st or 2nd Transition
	CR1 |= (spi1CFG.SPI_CPOL<<1);		//Set Clock polarity
	CR1 |= (spi1CFG.SPI_DFF<<11);		//Set Date width 8 or 16 bit
	CR1 |= (spi1CFG.SPI_LSBFIRST<<7);	//Set Shift LSB first or MSB
	CR1 |= (spi1CFG.SPI_SSI<<8);		//Set Slave Select by SW or HW
	CR1 |= (spi1CFG.SPI_MSTR<<2);		//Set Master or Slave Mode
	//MSTR and SPE remain set only if the NSS pin is connected to a high-level signal
	CR2 |= (spi1CFG.SPI_SSOE <<2);		//SET NSS to High level in CR2
	CR1 |= (spi1CFG.SPI_SPE<<6);		//Enable SPI

	//CR1 |= myCR1CFG;

	CR2 |= (spi1CFG.SPI_RXDMAEN <<0) | (spi1CFG.SPI_TXDMAEN<<1)
		| (spi1CFG.SPI_ERRIE<<5)| (spi1CFG.SPI_RXNEIE<<6)|(spi1CFG.SPI_TXEIE<<7);
}
void mcal::SPI::SPI2_Initialize(mcal::SPI_CFG spi2CFG)
{
	//Enable AFIO and GPIOB
	RCC->APB2ENR =(1<<0)| (1<<3);
	//MOSI2 PB15 Alternate Fun PP, MISO2 PB14 Input Pull UP/DN, SCK2  PB13 Alternate Fun PP
	GPIOB->CRH &= 0x00011111;		//Reset and mask
	GPIOB->CRH |= (0xB << 28) | (0x8 << 24) | (0xB << 20);


//		myCR1CFG =(spi2CFG.SPI_CPHA<<0)|(spi2CFG.SPI_CPOL<<1)|(spi2CFG.SPI_MSTR<<2)|
//				(spi2CFG.SPI_BRGH<<3)|(spi2CFG.SPI_SPE<<6) |(spi2CFG.SPI_LSBFIRST<<7)|
//				(spi2CFG.SPI_SSM <<9)|(spi2CFG.SPI_RXONLY <<10)|(spi2CFG.SPI_DFF<<11)|
//				(spi2CFG.SPI_CRCNEXT<<12)|(spi2CFG.SPI_CRCEN<<13)|(spi2CFG.SPI_BIDIOE<<14)|
//				(spi2CFG.SPI_BIDIMODE<<15);
//		CR1 = myCR1CFG;
	CR1 |= (uint16)((spi2CFG.SPI_CRCEN<<13) | (spi2CFG.SPI_CRCNEXT<<12));

	CR1 |= (spi2CFG.SPI_BRGH<<3);		//Set Pre-scaler for BAUD RATE
	CR1 |= (spi2CFG.SPI_CPHA<<0);		//Set Clock phase the 1st or 2nd Transition
	CR1 |= (spi2CFG.SPI_CPOL<<1);		//Set Clock polarity
	CR1 |= (spi2CFG.SPI_DFF<<11);		//Set Date width 8 or 16 bit
	CR1 |= (spi2CFG.SPI_LSBFIRST<<7);	//Set Shift LSB first or MSB
	CR1 |= (spi2CFG.SPI_SSI<<8);		//Set Slave Select by SW or HW
	CR1 |= (spi2CFG.SPI_MSTR<<2);		//Set Master or Slave Mode
	//MSTR and SPE remain set only if the NSS pin is connected to a high-level signal
	CR2 |= (spi2CFG.SPI_SSOE <<2);		//SET NSS to High level in CR2
	CR1 |= (spi2CFG.SPI_SPE<<6);		//Enable SPI

	//CR1 |= myCR1CFG;

	CR2 |= (spi2CFG.SPI_RXDMAEN <<0) | (spi2CFG.SPI_TXDMAEN<<1)
		| (spi2CFG.SPI_ERRIE<<5)| (spi2CFG.SPI_RXNEIE<<6)|(spi2CFG.SPI_TXEIE<<7);
}

void mcal::SPI::SPI_SendData(uint8_t u8Data)
{
	DR = u8Data;
	while( !(SR & (1<<1)) );
}

void mcal::SPI::SPI_SendString(uint8_t* u8String)
{
	uint16_t i = 0;
	while(u8String[i] != '\0')
	{
		SPI_SendData(u8String[i++]);
	}
}

void mcal::SPI::SPI_SendData(uint16_t u16Data)
{
	DR = u16Data;
	while( !(SR & (1<<1)) );
	/* Wait for transfer finished. */
	//while (!(SR  & SPI_SR_TXE));
}

void mcal::SPI::SPI_SendString(uint16_t* u16String)
{
	uint16_t i = 0;
	while(u16String[i] != '\0')
	{
		SPI_SendData(u16String[i++]);
	}
}

void mcal::SPI::SPI_ReceiveData(uint8_t* u8Data)
{
	while(! (SR & (1<<0)));
	* u8Data = DR;
}

void mcal::SPI::SPI_ReceiveData(uint16_t* u16Data)
{
	while(! (SR & (1<<0)));
	* u16Data = DR;
}

void* mcal::SPI::operator new(unsigned int, mcal::SPIInstance spi)
{
	return reinterpret_cast<void*>(spi);
}


