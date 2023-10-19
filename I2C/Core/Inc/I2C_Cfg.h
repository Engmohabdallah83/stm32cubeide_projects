/*
 * I2C_Cfg.h
 *
 *  Created on: Oct 4, 2023
 *      Author: Mohamed Aboelhassan
 */

#ifndef INC_I2C_CFG_H_
#define INC_I2C_CFG_H_

#include"I2C_interface.h"

I2Cmcal::I2C_CFG I2C_1_CFG
{
    //////////// I2C_CR1 /////
	I2Cmcal::NoRemap,            //I2C_Remap	    Remap;
	I2Cmcal::I2CEnable,          //I2C_PE		    PE;
	I2Cmcal::SMBDevice,          //I2C_SMBTYPE     	SMBTYPE;
	I2Cmcal::ARPenable,          //I2C_ENARP	    ENARP;
	I2Cmcal::PECdisbale,         //I2C_ENPEC	    ENPEC;
	I2Cmcal::GCdisable,	         //I2C_ENGC	    	ENGC;
	I2Cmcal::CkStretch,          //I2C_NOSTRETCH	NOSTRETC
	I2Cmcal::StartGen,           //I2C_START		START;
	I2Cmcal::StopGen,            //I2C_STOP			STOP;
	I2Cmcal::Acknowledge,        //I2C_ACK			ACK;
	I2Cmcal::ACKNext,            //I2C_POS			POS;
	I2Cmcal::NoPECTxfr,          //I2C_PEC			PEC;
	I2Cmcal::SMBAPINHigh,        //I2C_ALERT		ALERT;
	I2Cmcal::I2CReset,           //I2C_SWRST		SWRST;
	////////// I2C_CR2 /////////
	I2Cmcal::I2C8MHZ,            //I2C_Freq	    	Freq;
	I2Cmcal::ErrINTPEnable,   	 //I2C_ITERREN		ITERREN;
	I2Cmcal::EvINTPEnable,       //I2C_ITEVTEN		ITEVTEN;
	I2Cmcal::BfrINTPEnable,      //I2C_ITBUFEN		ITBUFEN;
	I2Cmcal::DMADisable,         //I2C_DMAEN		DMAEN;
	I2Cmcal::DMAEOTNOTLAST,      //I2C_LAST			LAST;
	I2Cmcal::PrCLK8MHZ,          //I2C_PrCLK		PeCLK;
	I2Cmcal::SCL400KHZ           //I2C_SCL			SCLFreq;
};

I2Cmcal::I2C_CFG I2C_2_CFG
{
    //////////// I2C_CR1 /////
	I2Cmcal::NoRemap,            //I2C_Remap	    Remap;
	I2Cmcal::I2CEnable,          //I2C_PE		    PE;
	I2Cmcal::SMBDevice,          //I2C_SMBTYPE     	SMBTYPE;
	I2Cmcal::ARPenable,          //I2C_ENARP	    ENARP;
	I2Cmcal::PECdisbale,         //I2C_ENPEC	    ENPEC;
	I2Cmcal::GCdisable,	         //I2C_ENGC	    	ENGC;
	I2Cmcal::CkStretch,          //I2C_NOSTRETCH	NOSTRETC
	I2Cmcal::StartGen,           //I2C_START		START;
	I2Cmcal::StopGen,            //I2C_STOP			STOP;
	I2Cmcal::Acknowledge,        //I2C_ACK			ACK;
	I2Cmcal::ACKNext,            //I2C_POS			POS;
	I2Cmcal::NoPECTxfr,          //I2C_PEC			PEC;
	I2Cmcal::SMBAPINHigh,        //I2C_ALERT		ALERT;
	I2Cmcal::I2CReset,           //I2C_SWRST		SWRST;
	////////// I2C_CR2 /////////
	I2Cmcal::I2C8MHZ,            //I2C_Freq	    	Freq;
	I2Cmcal::ErrINTPEnable,   	 //I2C_ITERREN		ITERREN;
	I2Cmcal::EvINTPEnable,       //I2C_ITEVTEN		ITEVTEN;
	I2Cmcal::BfrINTPEnable,      //I2C_ITBUFEN		ITBUFEN;
	I2Cmcal::DMADisable,         //I2C_DMAEN		DMAEN;
	I2Cmcal::DMAEOTNOTLAST,      //I2C_LAST			LAST;
	I2Cmcal::PrCLK8MHZ,          //I2C_PrCLK		PeCLK;
	I2Cmcal::SCL400KHZ           //I2C_SCL			SCLFreq;
};


#endif /* INC_I2C_CFG_H_ */
