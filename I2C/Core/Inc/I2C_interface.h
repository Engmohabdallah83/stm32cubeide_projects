/*
 * I2C_interface.h
 *
 *  Created on: Oct 4, 2023
 *      Author: Mohamed Aboelhassan
 */

#ifndef INC_I2C_INTERFACE_H_
#define INC_I2C_INTERFACE_H_

#include "main.h"
#include "RCC_Interface.h"

namespace I2Cmcal
{

	/**********************************************************************************
	 * 						USER DEFINED MACROS										  *
	 **********************************************************************************/
//ADDR=1, cleared by reading SR1 followed by reading SR2
#define EV_ADDR GET_BIT(SR1,ADDR_1)
//RxNE=1 cleared by reading DR register.
#define EV_RXNE  GET_BIT(SR1,RXNE_1)
//TxE=1, shift register not empty , data register empty, cleared by writing DR
#define EV_TXE GET_BIT(SR1,TXE_1)
//TxE=1, shift register empty, data register empty, write Data1 in DR.
#define EV3_1_TXE GET_BIT(SR1,TXE_1)
//AF=1; ACK Fail is cleared by writing ‘0’ in AF bit of SR1 register.
#define EV_AF GET_BIT(SR1,AF)
//STOPF=1, cleared by reading SR1 register followed by writing to the CR1 register
#define EV_STOPF GET_BIT(SR1,STOPF_1)
//Start by Enable Bit 8 start
#define I2Cstart (1<<8)
#define I2Cstop  (1<<9)
//Bit 1 BUSY: Bus busy(0: No comm. on the bus),(1: Comm. ongoing on the bus)
#define I2C_BusBusy		GET_BIT(SR2,1)
#define I2C_Master 		GET_BIT(SR2,0)
#define I2C_Set_Ack			SET_Bit(CR1,ACK_1)

	/**********************************************************************************
	 * 						USER DEFINED Constant Expression						  *
	 **********************************************************************************/
constexpr uint16_t SB_1     = 0UL ; //SB=1,
constexpr uint16_t ADDR_1   = 1UL ; //ADDR=1, cleared by reading SR1 followed by reading SR2
constexpr uint16_t BTF_1    = 2UL ; //BTF=1,
constexpr uint16_t STOPF_1  = 4UL ; // STOPF=1, cleared by reading SR1 reg
							  //followed by writing to the CR1 register
constexpr uint16_t RXNE_1   = 6UL ; //RxNE=1 cleared by reading DR register.
constexpr uint16_t TXE_1    = 7UL ; //TxE=1,shift Reg empty, data Reg empty, write Data1 in DR
constexpr uint16_t TXEBTF_1 = 7UL ; //shift Reg not empty , data Reg empty, cleared by writing DR
constexpr uint16_t AF       = 15UL; //AF is cleared by writing ‘0’ in AF bit of SR1 register
constexpr uint16_t ACK_1	= 10UL; //Acknowledge returned after a byte is received (matched address or data)


constexpr uint32_t I2C1_BASE_ADDRESS = 0x40005400;
constexpr uint32_t I2C2_BASE_ADDRESS = 0x40005800;

	enum I2CInstance
	{
		I2C1Instance = I2C1_BASE_ADDRESS,
		I2C2Instance = I2C2_BASE_ADDRESS
	};

	enum I2C_Remap
	{
		NoRemap,
		Remap
	};

	enum I2C_PE
	{
		I2CDisable,
		I2CEnable
	};

	enum I2C_SMBUS
	{
		I2CMode,
		SMB_Mode
	};

	enum I2C_SMBTYPE
	{
		SMBDevice,
		SMBHost
	};

	enum I2C_ENARP
	{
		ARPdisable,
		ARPenable
	};

	enum I2C_ENPEC
	{
		PECdisbale,
		PECenable
	};

	enum I2C_ENGC
	{
		GCdisable,
		GCenable
	};

	enum I2C_NOSTRETCH
	{
		CkStretch,
		NoCkStretch
	};

	enum I2C_START
	{
		NoStartGen,
		StartGen
	};

	enum I2C_STOP
	{
		NoStopGen,
		StopGen
	};

	enum I2C_ACK
	{
		NoAcknowledge,
		Acknowledge
	};

	enum I2C_POS
	{
		ACKCurrent,
		ACKNext
	};

	enum I2C_PEC
	{
		NoPECTxfr,
		PECTxfr
	};

	enum I2C_ALERT
	{
		SMBAPINHigh,
		SMBAPINLow
	};

	enum I2C_SWRST
	{
		I2CNoReset,
		I2CReset
	};

	/*
	 * ********* I2C_CR2 ******************
	 */
	enum I2C_Freq
	{
		I2C2MHZ  =  0b000010,
		I2C3MHZ  =  0b000011,
		I2C4MHZ  =  0b000100,
		I2C5MHZ  =  0b000101,
		I2C6MHZ  =  0b000110,
		I2C7MHZ  =  0b000111,
		I2C8MHZ  =  0b001000,
		I2C9MHZ  =  0b001001,
		I2C10MHZ =  0b001010,
		I2C50MHZ =  0b110010
	};

	enum I2C_ITERREN
	{
		ErrINTPDisable,
		ErrINTPEnable
	};

	enum I2C_ITEVTEN
	{
		EvINTPDisable,
		EvINTPEnable
	};

	enum I2C_ITBUFEN
	{
		BfrINTPDisable,
		BfrINTPEnable
	};

	enum I2C_DMAEN
	{
		DMADisable,
		DMAEnable
	};

	enum I2C_LAST
	{
		DMAEOTNOTLAST,
		DMAEOTLAST
	};

//	If DUTY = 1: (to reach 400 kHz)
//	Thigh = 9 * CCR * TPCLK1
//	Tlow = 16 * CCR * TPCLK1
//	CCR = Per Freq/9 * SCLfreq
	enum I2C_PrCLK
	{
		PrCLK2MHZ  = 2000000,
		PrCLK4MHZ  = 4000000,
		PrCLK8MHZ  = 8000000,
		PrCLK10MHZ = 10000000
	};
//Thigh = Tlow = 2.5 uS
//	2.5 uS = 16 * CCR * 1us
//	CCR = 2.5/16
	enum I2C_SCL
	{
		SCL100KHZ = 100000,
		SCL400KHZ = 400000
	};

	typedef struct
	{
		////////// I2C_CR1 /////////
		I2C_Remap	    Remap;
		I2C_PE		    PE;
		I2C_SMBTYPE     SMBTYPE;
		I2C_ENARP	    ENARP;
		I2C_ENPEC	    ENPEC;
		I2C_ENGC	    ENGC;
		I2C_NOSTRETCH	NOSTRETCH;
		I2C_START		START;
		I2C_STOP		STOP;
		I2C_ACK			ACK;
		I2C_POS			POS;
		I2C_PEC			PEC;
		I2C_ALERT		ALERT;
		I2C_SWRST		SWRST;

		////////// I2C_CR2 /////////
		I2C_Freq	    Freq;
		I2C_ITERREN		ITERREN;
		I2C_ITEVTEN		ITEVTEN;
		I2C_ITBUFEN		ITBUFEN;
		I2C_DMAEN		DMAEN;
		I2C_LAST		LAST;
		I2C_PrCLK		PeCLK;
		I2C_SCL			SCLFreq;

		///////// I2C CCR //////////


	}I2C_CFG;


	class I2C
	{
	public:
		I2C();
		~I2C();
	void I2C_Initialize(I2Cmcal::I2C_CFG &I2C1CFG);
	void I2C1_Initialize(I2C_CFG I2C1CFG);
	void I2C2_Initialize(I2C_CFG I2C2CFG);

	bool I2C_Start();
	bool I2C_Stop();

	bool I2C_Address(uint8_t Addr);

	void I2C_SendData(uint8_t u8Data);

	void I2C_SendString(uint8_t* u8String);

	void I2C_ReceiveData(uint8_t* u8Data, uint8_t Ack);

	void * operator new(unsigned int, I2CInstance I2C);
	private:
		//registers
	  volatile uint32_t CR1;
	  volatile uint32_t CR2;
	  volatile uint32_t OAR1;
	  volatile uint32_t OAR2;
	  volatile uint32_t DR;
	  volatile uint32_t SR1;
	  volatile uint32_t SR2;
	  volatile uint32_t CCR;
	  volatile uint32_t TRISE;
	};
} //namespace I2Cmcal


#endif /* INC_I2C_INTERFACE_H_ */
