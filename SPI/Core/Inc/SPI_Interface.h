/*
 * SPI_Interface.h
 *
 *  Created on: Sep 25, 2023
 *      Author: Mohamed Aboelhassan
 */

#ifndef INC_SPI_INTERFACE_H_
#define INC_SPI_INTERFACE_H_

#include "main.h"
#include "RCC_Interface.h"

namespace mcal
{
	constexpr uint32_t SPI1_BASE_ADDRESS = 0x40013000;
	constexpr uint32_t SPI2_BASE_ADDRESS = 0x40003800;
	constexpr uint32_t SPI3_BASE_ADDRESS = 0x40003C00;

	enum SPIInstance
	{
		SPI1Instance = SPI1_BASE_ADDRESS,
		SPI2Instance = SPI2_BASE_ADDRESS,
		SPI3Instance = SPI3_BASE_ADDRESS
	};

	enum BIDIMODE       //BIDIMODE: Bidirectional data mode enable
	{
		UniDirMode,     //0: 2-line unidirectional data mode selected
		BiDirMode 		//1: 1-line bidirectional data mode selected
	};                  //Note: This bit is not used in I2S mode

	enum BIDIOE          // BIDIOE: Output enable in bidirectional mode
	{                    // This bit combined with the BIDImode bit selects the dir. of transfer in bidir. mode
		SPIBIDIRDisable, // 0: Output disabled (receive-only mode)
		SPIBIDIREnable   // 1: Output enabled (transmit-only mode)
	};
	enum CRCEN
	{
		SPICRCDisable,
		SPICRCEnable
	};
	enum CRCNEXT
	{
		noCRCphase,
		CRCphase
	};
	enum DFF
	{
		Frame8Bit,
		Frame16Bit
	};
	enum RXONLY
	{
		TXRXMode,
		RXONLYMode
	};
	/*
	 *  SSM: Software slave management
	 * When the SSM bit is set, the NSS pin input is replaced with the value from the SSI bit.
	 * Note: This bit is not used in I2S mode
	 */
	enum SSM
	{
		SSMDisable,		//0: Software slave management disabled
		SSMEnable		//1: Software slave management enabled
	};
	enum SSI
	{
		SSILow,
		SSIHigh
	};

	enum LSBFIRST
	{
		MSBTXFirst,		//0: MSB transmitted first
		LSBTXFirst		//1: LSB transmitted first
	};
	enum SPE
	{
		SPI_Disable,
		SPI_Enable
	};
	/*
	 * Note: These bits should not be changed when communication is ongoing.
	 *	They are not used in I2S mode
	 *
	 * BR[2:0]: Baud rate control*/
		constexpr uint8_t  fPCLK_2		= 00000000;				//000: fPCLK/2
		constexpr uint8_t  fPCLK_4		= 00000001;				//001: fPCLK/4
		constexpr uint8_t  fPCLK_8		= 00000010;				//010: fPCLK/8
		constexpr uint8_t  fPCLK_16		= 00000011;				//011: fPCLK/16
		constexpr uint8_t  fPCLK_32		= 00000100;				//100: fPCLK/32
		constexpr uint8_t  fPCLK_64		= 00000101;				//101: fPCLK/64
		constexpr uint8_t  fPCLK_128	= 00000110;			    //110: fPCLK/128
		constexpr uint8_t  fPCLK_256	= 00000111;			    //111: fPCLK/256


	enum MSTR
	{
		SPI_Slave,
		SPI_Master
	};
	enum CPOL
	{
		CK_0_Idle,       //0: CK to 0 when idle
		CK_1_Idle        //1: CK to 1 when idle
	};
	enum CPHA
	{
		Cap_1_Edge,     //0: The first clock transition is the first data capture edge
		Cap_2_Edge      //1: The second clock transition is the first data capture edge
	};

	/**************************************************************
	 * ******************* CR2 Configuration  *********************
	 **************************************************************/
	enum TXEIE
	{                   //Bit 7 TXEIE: Tx buffer empty interrupt enable
		TXIE_Disable,    //0: TXE interrupt masked
		TXIE_Enable      //1: TXE interrupt not masked. Used to generate an
	};					//interrupt request when the TXE flag is set.

	enum RXNEIE			//RX buffer not empty interrupt enable
	{
		RXNIE_Disable,
		RXNIE_ENable
	};

	enum ERRIE			//Error interrupt enable
	{
		ERRIE_Disable,
		ERRIE_Enable
	};

	enum SSOE			//Bit 2 SSOE: SS output enable
	{
		SSOE_Disable,	//SS output is disabled in master mode and the cell can work in multi-master config.
		SSOE_Enable		//SS output is enabled in master mode and when the cell is enabled.
						//The cell cannot work in a multi-master environment.
	};

	enum TXDMAEN		//Bit 1 TXDMAEN: Tx buffer DMA enable
	{
		TXDMA_Disable,
		TXDMA_Enable
	};

	enum RXDMAEN         //RXDMAEN: Rx buffer DMA enable
	{                    //When this bit is set, the DMA request is made whenever the RXNE flag is set.
		RXDMA_Disable,   //0: Rx buffer DMA disabled
		RXDMA_Enable	 //1: Rx buffer DMA enabled
	};

	enum REMAP
	{
		REMAPDisable,
		REMAPEnable
	};

	typedef struct
	{
		//CR1
		BIDIMODE	SPI_BIDIMODE;
		BIDIOE		SPI_BIDIOE;
		CRCEN		SPI_CRCEN;
		CRCNEXT		SPI_CRCNEXT;
		DFF			SPI_DFF;
		RXONLY		SPI_RXONLY;
		SSM			SPI_SSM;
		SSI			SPI_SSI;
		LSBFIRST	SPI_LSBFIRST;
		SPE			SPI_SPE;
		uint8_t 	SPI_BRGH;
		MSTR		SPI_MSTR;
		CPOL		SPI_CPOL;
		CPHA		SPI_CPHA;
		//CR2
		TXEIE		SPI_TXEIE;
		RXNEIE		SPI_RXNEIE;
		ERRIE		SPI_ERRIE;
		SSOE		SPI_SSOE;
		TXDMAEN		SPI_TXDMAEN;
		RXDMAEN		SPI_RXDMAEN;
		REMAP		SPI_REMAP;
	}SPI_CFG;


	class SPI
	{
	public:
		SPI();
		~SPI();
	void SPI_Initialize(mcal::SPI_CFG &spi1CFG);
	void SPI1_Initialize(SPI_CFG spi1CFG);
	void SPI2_Initialize(SPI_CFG spi2CFG);

	void SPI_SendData(uint8_t u8Data);
	void SPI_SendData(uint16_t u16Data);

	void SPI_SendString(uint8_t* u8String);
	void SPI_SendString(uint16_t* u8String);

	void SPI_ReceiveData(uint8_t* u8Data);
	void SPI_ReceiveData(uint16_t* u16Data);

	void * operator new(unsigned int, SPIInstance spi);
	private:
		//registers
	  volatile uint32_t CR1;
	  volatile uint32_t CR2;
	  volatile uint32_t SR;
	  volatile uint32_t DR;
	  volatile uint32_t CRCPR;
	  volatile uint32_t RXCRCR;
	  volatile uint32_t TXCRCR;
	  volatile uint32_t I2SCFGR;

	};
} //namespace mcal


#endif /* INC_SPI_INTERFACE_H_ */
