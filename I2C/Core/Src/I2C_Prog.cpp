/*
 * I2C_Prog.cpp
 *
 *  Created on: Oct 4, 2023
 *      Author: Mohamed Aboelhassan
 */
#include "I2C_interface.h"
#include "GPIO_Interface.h"

I2Cmcal::I2C::I2C()
{}
I2Cmcal::I2C::~I2C()
{}

void I2Cmcal::I2C::I2C_Initialize(I2Cmcal::I2C_CFG& I2C_cfg)
{
	if(this == reinterpret_cast<I2C*>(I2C1Instance))
	{
		//Enable I2C1 Peripheral Bus clock
		RCC->APB1ENR |= (1<<21);
		RCC->APB2ENR|=(1<<0)|(1<<3);	//Enable AF & GPOPB work on I2C1 in both cases	 and I2C2

		I2C1_Initialize(I2C_cfg);
	}
	else if(this == reinterpret_cast<I2C*>(I2C2Instance))
	{
		// Enable I2C2 Peripheral Bus clock
		RCC->APB1ENR = (1<<22);

		I2C2_Initialize(I2C_cfg);
	}
}

void I2Cmcal::I2C::I2C1_Initialize(I2Cmcal::I2C_CFG I2C1CFG)
{
	if(I2C1CFG.Remap)
	{
		AFIO->MAPR   |= 1<<1;          // set I2C1 remap
		GPIOB->CRH |= 0x000000FF;	   // PB9,8 Open drain
	}
	else
	{	GPIOB->CRL |= 0xFF000000;}			//PB7,6 Open drain

	CR1 = 0; //Disable PE and all controls
	CR2 |= (I2C1CFG.Freq << 0); //Program the peripheral input clock in I2C_CR2
	CCR |= (3<<14);	//F/S: I2C master FM mode and Fm mode tlow/thigh = 16/9 (see CCR)Bits
	//(40)40*125n=5000 ns *2(High & Low) =10,000 ns 1/10,000 = 100 KHzI2C Freq
	//I2C_clock = Thigh + Tlow
	//CCR = Peripheral Clock/(I2C_Clock * 25) see Ahmed Eldeeb lec43
	CCR |= (uint16_t)(I2C1CFG.PeCLK/(9 * I2C1CFG.SCLFreq) );
	TRISE = 11u;//Max allowed rise time 300 nS equiv. to (14in TRISE counter) * (22nS of step)
	CR1 |= (I2C1CFG.PE<<0) ;	//enable I2C peripheral
}

void I2Cmcal::I2C::I2C2_Initialize(I2Cmcal::I2C_CFG I2C2CFG)
{
	// PB11,10 Open drain no REMAP
	GPIOB->CRH |= 0x0000FF00;

	CR1 = 0; //Disable PE and all controls
	CR2 |= (I2C2CFG.Freq << 0); //Program the peripheral input clock in I2C_CR2
	CCR |= (0xC<<15);	//F/S: I2C master FM mode and Fm mode tlow/thigh = 16/9 (see CCR)Bits
	//(40)40*125n=5000 ns *2(High & Low) =10,000 ns 1/10,000 = 100 KHzI2C Freq
	//I2C_clock = Thigh + Tlow
	//CCR = Peripheral Clock/(I2C_Clock * 25) see Ahmed Eldeeb lec43
	CCR |= (uint16_t)(I2C2CFG.PeCLK/(25 * I2C2CFG.SCLFreq) );
	TRISE = 11u; //Max allowed rise time 300 nSec equiv. to (14in TRISE counter) * (22nS of step)
	CR1 |= (I2C2CFG.PE<<0) ;	//enable I2C peripheral
}

bool I2Cmcal::I2C::I2C_Start()
{
	//while(!(I2C_BusBusy)); //wait until bus is idle
	CR1 |= I2Cstart;	   // Send start condition
	while (!(I2C_Master)); //wait to confirm that Target become master
	SR1; 		   		   //read SR1 to clear SB flag
	return true;
}

bool I2Cmcal::I2C::I2C_Stop()
{
	while(!(EV_TXE));   //wait until data sent and DR clear mean TXE = 1 or BTF = 1
	CR1 |= I2Cstop;	    // send stop condition
	while (I2C_Master); //wait to confirm that Target goes back to Slave mode
						//EV8_2:TxE=1,BTF = 1, Program Stop request.
						//TxE and BTF are cleared by HARDWARE by the Stop condition
	return true;
}

bool I2Cmcal::I2C::I2C_Address(uint8_t Addr)
{
	DR = Addr;			//Send Address to I2C network
	while(!(EV_ADDR));  //wait until address match bit set
	SR1;	//clear ADDR flag by dummy read SR1
	SR2;	//Followed by reading SR2
	return true;
}

void I2Cmcal::I2C::I2C_SendData(uint8_t u8Data)
{
	while(!(EV_TXE)); //data register empty shift register empty/not empty
	DR = u8Data; 	  //cleared by writing DR register
}

void I2Cmcal::I2C::I2C_SendString(uint8_t* u8String)
{
	uint16_t i = 0;
	do
	{
		I2C_SendData(u8String[i]);
		i++;
	}while(u8String[i] != '\0');
}

void I2Cmcal::I2C::I2C_ReceiveData(uint8_t* u8Data, uint8_t Ack)
{
	if(Ack)
	{
		I2C_Set_Ack;
	}
	while (!(EV_RXNE)); //while it do not received data stay here
	* u8Data = DR;

}

void* I2Cmcal::I2C::operator new(unsigned int, I2Cmcal::I2CInstance I2C)
{
	return reinterpret_cast<void*>(I2C);
}

