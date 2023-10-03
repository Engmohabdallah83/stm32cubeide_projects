/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file    N5110_Program.c
 *        \brief	Created on: Jan 24, 2023
 *
 *      	\details Nokia 5110 Driver Functions
 *
 *			Author: Mohamed Aboelhassan
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "GPIO_Interface.h"
#include "STK_Interface.h"
#include "SPI_Interface.h"
#include "N5110_private.h"
#include "N5110_Interface.h"

/**********************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/



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
void n5110_init(unsigned short spi)
{
	// Setup RST pin
	//init_GP(PA,0,OUT50,O_GP_PP);
	GPIO_voidSetPinDirection(GPIO_PORTA, GPIO_PIN0, GPIO_OUTPUT_50_PP);
	// Set RST High & Wait 10 ms set low & Wait 10 ms and set high
	//W_GP(PA,0,HIGH);
	GPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN0, GPIO_HIGH);
	//DelayMs(10);
	STK_DelayMs(10000);
	//W_GP(PA,0,LOW); //Reset of screen
	GPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN0, GPIO_LOW);
	//DelayMs(10);
	STK_DelayMs(10000);
	//W_GP(PA,0,HIGH);
	GPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN0, GPIO_HIGH);

	// Setup DC pin & set low
	//init_GP(PA,1,OUT50,O_GP_PP);
 	GPIO_voidSetPinDirection(GPIO_PORTA, GPIO_PIN1, GPIO_OUTPUT_50_PP);
	//W_GP(PA,1,LOW);
	GPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN1, GPIO_LOW);
	//Setup screenlight pin & test ligh with 1 sec high
	//init_GP(PA,2,OUT50,O_GP_PP);
	GPIO_voidSetPinDirection(GPIO_PORTA, GPIO_PIN2, GPIO_OUTPUT_50_PP);
	//W_GP(PA,2,HIGH);
	GPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN2, GPIO_HIGH);
	//DelayMs(1000);
	STK_DelayMs(1000000);
	//W_GP(PA,2,LOW);
	GPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN2, GPIO_LOW);


	spi_init(spi);


	//extended instruction set & set voltage
	spi_tx(1,0x21);
	spi_tx(1,0xE0);

	//function set & display control set normal mode
	spi_tx(1,0x20);
	spi_tx(1,0x0C);

	 // set LCD open command
//	  LcdWriteCmd(0x21);  // LCD extended commands
//	  LcdWriteCmd(0xbf);  // set LCD Vop (contrast)
//	  LcdWriteCmd(0x04);  // set temp coefficent
//	  LcdWriteCmd(0x14);  // LCD bias mode 1:48
//	  LcdWriteCmd(0x20);  // LCD basic commands
//	  LcdWriteCmd(0x0C);  // LCD normal video
	//  LcdWriteCmd(0x0D);  // LCD inverse video


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
void n5110_print(short Ypos, short Xpos, char str[])
{
	int i,j;
	i = 0;
	//Cleaning the String
	n5110_pos(0,0);
	//W_GP(PA,1,HIGH);
	GPIO_voidSetPinDirection(GPIO_PORTA, GPIO_PIN1, GPIO_HIGH);
	for(j=0;j<504;j++)
		{
			spi_tx(1,0x00);

		}

	//W_GP(PA,1,LOW);
	GPIO_voidSetPinDirection(GPIO_PORTA, GPIO_PIN1, GPIO_LOW);
	//Writre String into n5110
	n5110_pos(Ypos,Xpos);
	//W_GP(PA,1,HIGH);
	GPIO_voidSetPinDirection(GPIO_PORTA, GPIO_PIN1, GPIO_HIGH);
	while(str[i])
	{
		for(j=0;j<5;j++)
		{

			spi_tx(1,ASCII[str[i]-32][j]);

		}

	i++;
	}
	//W_GP(PA,1,LOW);
	GPIO_voidSetPinDirection(GPIO_PORTA, GPIO_PIN1, GPIO_LOW);
	//sring position
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
void n5110_pos(short Ypos,short Xpos)
{
	//W_GP(PA,1,LOW);
	GPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN1, GPIO_LOW);
	spi_tx(1,0x20);
	spi_tx(1,((0x40 | Ypos)));
	spi_tx(1,(0x80 | Xpos));
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
void n5110_clear(void)
{
	int j;
	n5110_pos(0,0);
	//W_GP(PA,1,HIGH);
	GPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN1, GPIO_HIGH);
	for(j=0;j<504;j++)
	{
		spi_tx(1,0x00);
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
//print buffer
void print_buffer(unsigned char screen_buffer[][84])
{
	n5110_clear();
	n5110_pos(0,0);
	int i,j;
	//W_GP(PA,1,HIGH);
	GPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN1, GPIO_HIGH);
	for (i=0;i<6;i++)
	{
		for(j=0;j<84;j++)
		{
			 spi_tx(1,screen_buffer[i][j]);
		}
	}
	//W_GP(PA,1,LOW);
	GPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN1, GPIO_LOW);
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
void n5110_light(unsigned char HIGH_LOW)
{
	//W_GP(PA,2,HIGH_LOW);
	GPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN2, HIGH_LOW);
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
/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/



