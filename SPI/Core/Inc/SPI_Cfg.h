/*
 * SPI_Cfg.h
 *
 *  Created on: Sep 26, 2023
 *      Author: Mohamed Aboelhassan
 */

#ifndef INC_SPI_CFG_H_
#define INC_SPI_CFG_H_

#include"SPI_Interface.h"

//struct SPI_CFG
//	{
//		//CR1
//		BIDIMODE	SPI_BIDIMODE;
//		BIDIOE		SPI_BIDIOE;
//		CRCEN		SPI_CRCEN;
//		CRCNEXT		SPI_CRCNEXT;
//		DFF			SPI_DFF;
//		RXONLY		SPI_RXONLY;
//		SSM			SPI_SSM;
//		LSBFIRST	SPI_LSBFIRST;
//		SPE			SPI_SPE;
//		uint8_t 	SPI_BRGH;
//		MSTR		SPI_MSTR;
//		CPOL		SPI_CPOL;
//		CPHA		SPI_CPHA;
//		//CR2
//		TXEIE		SPI_TXEIE;
//		RXNEIE		SPI_RXNEIE;
//		ERRIE		SPI_ERRIE;
//		SSOE		SPI_SSOE;
//		TXDMAEN		SPI_TXDMAEN;
//		RXDMAEN		SPI_RXDMAEN;
//
//	};

mcal::SPI_CFG SPI_1_CFG
{
	mcal::UniDirMode,      //
	mcal::SPIBIDIRDisable, //
	mcal::SPICRCDisable,   //
	mcal::noCRCphase,      //
	mcal::Frame16Bit,       //
	mcal::TXRXMode,        //
	mcal::SSMEnable,       //
	mcal::SSIHigh,		   //
	mcal::LSBTXFirst,      //
	mcal::SPI_Enable,      //bit 6
	mcal::fPCLK_4,         //bit 3,4,5
	mcal::SPI_Master,      //
	mcal::CK_0_Idle,       //
	mcal::Cap_1_Edge,      //
	//CR2 CFG
	mcal::TXIE_Disable,    //
	mcal::RXNIE_Disable,   //
	mcal::ERRIE_Disable,   //
	mcal::SSOE_Enable,    //
	mcal::TXDMA_Disable,   //
	mcal::RXDMA_Disable,    //
	mcal::REMAPDisable
};

mcal::SPI_CFG SPI_2_CFG
{
	mcal::UniDirMode,      //
	mcal::SPIBIDIRDisable, //
	mcal::SPICRCDisable,   //
	mcal::noCRCphase,      //
	mcal::Frame16Bit,       //
	mcal::TXRXMode,        //
	mcal::SSMEnable,       //
	mcal::SSIHigh,		   //
	mcal::LSBTXFirst,      //
	mcal::SPI_Enable,      //bit 6
	mcal::fPCLK_4,         //bit 3,4,5
	mcal::SPI_Master,      //
	mcal::CK_0_Idle,       //
	mcal::Cap_1_Edge,      //
	//CR2 CFG
	mcal::TXIE_Disable,    //
	mcal::RXNIE_Disable,   //
	mcal::ERRIE_Disable,   //
	mcal::SSOE_Enable,    //
	mcal::TXDMA_Disable,   //
	mcal::RXDMA_Disable,    //
	mcal::REMAPDisable
};

#endif /* INC_SPI_CFG_H_ */
