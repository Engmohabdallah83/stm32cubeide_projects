/*
 * LCD_Program.c
 *
 *  Created on: Jan 25, 2019
 *      Author: abido
 */

//#define F_CPU 8000000UL
#include "Std_Types.h"
#include "GPIO_Interface.h"
#include "GPIO_Private.h"
#include "GPIO_Config.h"
#include "STK_Interface.h"
#include "LCD_Interface.h"
#include "LCD_Extra.h"

#define En_SET()      GPIO_voidSetPinValue(LCD_u8CONTROLPORT ,LCD_u8EN_PIN ,GPIO_HIGH)
#define En_CLR()      GPIO_voidSetPinValue(LCD_u8CONTROLPORT ,LCD_u8EN_PIN ,GPIO_LOW)
#define RW_WRITE()    GPIO_voidSetPinValue(LCD_u8CONTROLPORT ,LCD_u8RW_PIN ,GPIO_LOW)
#define RW_READ()     GPIO_voidSetPinValue(LCD_u8CONTROLPORT ,LCD_u8RW_PIN ,GPIO_HIGH)
#define RS_COMMAND()  GPIO_voidSetPinValue(LCD_u8CONTROLPORT ,LCD_u8RS_PIN ,GPIO_LOW)
#define RS_DATA()     GPIO_voidSetPinValue(LCD_u8CONTROLPORT ,LCD_u8RS_PIN ,GPIO_HIGH)

#define LCD_FUNCTION_SET 0b00111000

#define LCD_DISPLAY_ON_CONTROL 0b00001100

#define LCD_DISPLAY_OFF_CONTROL 0b00001000

#define LCD_DISPLAY_CLEAR 0b00000001

void GPIO_voidSetPortValue(uint8 COPY_PORT ,uint8 LOC_u8Command)
{
	for(uint8 PIN ; PIN < 8 ; PIN++)
	{
		GPIO_voidSetPinValue(COPY_PORT , PIN , GET_BIT(LOC_u8Command,PIN) );

	}
}

void LCD_vidWriteCommand(uint8 LOC_u8Command)
{
	En_CLR();
	RW_WRITE();
	RS_COMMAND();
	GPIO_voidSetPortValue(LCD_u8DATAPORT , LOC_u8Command);
	En_SET();
	STK_voidBusyWait(2);  /* _delay_ms(2) */
	En_CLR();
}


void LCD_vidWriteData(uint8 LOC_u8Data)
{
	En_CLR();
	RW_WRITE();
	RS_DATA();
	GPIO_voidSetPortValue(LCD_u8DATAPORT , LOC_u8Data);
	En_SET();
	STK_voidBusyWait(2);  /* _delay_ms(2) */
	En_CLR();
}

/*
 * Set Port Direction
 * write function set command
 * wait 39 us
 * write Display on or off control
 * wait 39 us
 * write Display Clear
 *
 */

void LCD_vidInit(void)
{

	/*Set Control / Data Port Direction*/

	STK_voidBusyWait(100);  /* _delay_ms(100) */

	/*DIO_u8SetPortDirection(LCD_u8DATAPORT,Output);*/
	GPIO_voidSetPinDirection(LCD_u8DATAPORT, GPIO_PIN0 , GPIO_OUTPUT_50_PP);
	GPIO_voidSetPinDirection(LCD_u8DATAPORT, GPIO_PIN1 , GPIO_OUTPUT_50_PP);
	GPIO_voidSetPinDirection(LCD_u8DATAPORT, GPIO_PIN2 , GPIO_OUTPUT_50_PP);
	GPIO_voidSetPinDirection(LCD_u8DATAPORT, GPIO_PIN3 , GPIO_OUTPUT_50_PP);
	GPIO_voidSetPinDirection(LCD_u8DATAPORT, GPIO_PIN4 , GPIO_OUTPUT_50_PP);
	GPIO_voidSetPinDirection(LCD_u8DATAPORT, GPIO_PIN5 , GPIO_OUTPUT_50_PP);
	GPIO_voidSetPinDirection(LCD_u8DATAPORT, GPIO_PIN6 , GPIO_OUTPUT_50_PP);
	GPIO_voidSetPinDirection(LCD_u8DATAPORT, GPIO_PIN7 , GPIO_OUTPUT_50_PP);

	/*DIO_u8SetPortDirection(LCD_u8CONTROLPORT,Output);*/

	/*Set Enable PIN in Control PORT*/
	GPIO_voidSetPinDirection(LCD_u8CONTROLPORT, LCD_u8EN_PIN, GPIO_OUTPUT_50_PP);
	/*Set RW(Read/Write) PIN in Control PORT*/
	GPIO_voidSetPinDirection(LCD_u8CONTROLPORT,LCD_u8RW_PIN,GPIO_OUTPUT_50_PP);
	/*Set RS(Read Select) PIN in Control PORT*/
	GPIO_voidSetPinDirection(LCD_u8CONTROLPORT,LCD_u8RS_PIN,GPIO_OUTPUT_50_PP);

	/* Check if Back light Needed to be controlled */
	if(LCD_Back_LT_EN)
	{
		/*Set Back Light PIN direction in Control PORT if Needed*/
		GPIO_voidSetPinDirection(LCD_u8CONTROLPORT, LCD_Back_LT, GPIO_OUTPUT_50_PP);
	}

	 /* write function set command*/

	STK_voidBusyWait(100);  /* _delay_ms(100) */
	LCD_vidWriteCommand(LCD_FUNCTION_SET);
	STK_voidBusyWait(50);  /* _delay_ms(50) */

	/*Write Display ON Control Command*/
	LCD_vidWriteCommand(LCD_DISPLAY_ON_CONTROL);
	STK_voidBusyWait(50);  /* _delay_ms(50) */

	/*Display Clear Command*/
	LCD_vidWriteCommand(LCD_DISPLAY_CLEAR);
	STK_voidBusyWait(3);  /* _delay_ms(3) */



}//End Initialization

/*
 * LCD Write String
 * Input Pointer to Array of String
 * Input MAX Size by define it in interface file
 * Show string by call LCD write data Function
 *
 */


/*
 * LCD Clear Function
 *
 */
void LCD_vidClear()
{
	LCD_vidWriteCommand(LCD_DISPLAY_CLEAR);
}



/*write a string on LCD screen
 * Input address of string
 * Input Max Size of String
 * Output void
 * */

void LCD_vidWriteString(uint8 *LOC_pu8String,uint8 LOC_u8MaxSize)
{
	uint8 LOC_u8ArrCounter=0;

	while(LOC_pu8String[LOC_u8ArrCounter]!='\0' && LOC_u8ArrCounter <= LOC_u8MaxSize)
	{
		LCD_vidWriteData(LOC_pu8String[LOC_u8ArrCounter]);
		LOC_u8ArrCounter++;
	}
}

/*
 * LCD Go to Address
 * Input Row Location
 * Input Column Location
 * Set Address from Row & Column Location
 * Send Command
 *
 */

void vid_GoToAddress(uint8 LOC_u8Column , uint8 LOC_u8Row )
{
	uint8 LOC_u8AddrLOC = (0x40 * LOC_u8Row) + LOC_u8Column;
	SET_BIT(LOC_u8AddrLOC,7);
	LCD_vidWriteCommand(LOC_u8AddrLOC);
}


/*
 * LCD Arabic Name
 * void Input
 * void Output
 * Send CGROM Command
 * Then Send Data to write in CGROM
 * Then send put AC back on CGRAM
 * after that send AC to addresses of CGRAM
 */
/***************************************************************************************/
/* Description! Interface to write extra characters saved in the CGRAM                 */
/* Input      ! Y = Row position , X = Column position                                 */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void LCD_vidWriteExtraChar (uint8 X , uint8 Y)
{
    uint8 iteration1,iteration2;

    /*DDRAM-->CGRAM*/
    LCD_vidWriteCommand(64);
	for(iteration1=0 ; iteration1<64 ; iteration1++)
	{
		LCD_vidWriteData(ExtraChar[iteration1]);
	}
	/*CGRAM-->DDRAM*/
	LCD_vidWriteCommand(128);
	vid_GoToAddress(X,Y);
	/*First eight character which saved at CGRAM*/
	for (iteration2=0; iteration2<=7 ; iteration2++)
	{
		/* Write bytes of DDRAM */
		LCD_vidWriteData(iteration2);

		STK_voidBusyWait(5);  /* _delay_ms(5) */
	}
}

/*
 * Write in CGRAM
 * Input Column
 * Input Row
 * Output void
 *SET AC Address to CGRAM
 *Write Data in CGRAM
 *SET AC Address to DDRAM
 *
 */
void LCD_vidWriteInCGRAM(uint8 LOC_u8Col , uint8 LOC_u8Ro)
{
	/*Counters to write data in CGRAM and to retrieve data from DDRAM*/
	uint8 LOC_u8WriteCtr, LOC_u8ReadCtr;
	/*Write CGRAM Address in AC*/
	LCD_vidWriteCommand(SET_AC_TO_CGRAM);

	/*Write My Data in CGRAM*/
	for(LOC_u8WriteCtr=0;LOC_u8WriteCtr<64;LOC_u8WriteCtr++)
	{

		LCD_vidWriteData( ExtraChar[LOC_u8WriteCtr]);

	}

	/*Set AC to DDRAM*/
	LCD_vidWriteCommand(SET_AC_TO_DDRAM);

	/*Display My Data in Specific Location on LCD*/
	vid_GoToAddress(LOC_u8Col , LOC_u8Ro);

	/*Retrieve Data from CGRAM By give AC Address of CGRAM while it Pointing to DDRAM*/
	for(LOC_u8ReadCtr=0;LOC_u8ReadCtr<7;LOC_u8ReadCtr++)
	{

		/*Write Address to DDRAM which contain CGRAM Data*/
		LCD_vidWriteData(LOC_u8ReadCtr);
	}
}

void LCD_vidWriteInt(uint16 number)
{
		uint8 c[5];
		itoa (number, c, 10);
		LCD_vidWriteString ((uint8 *)c ,5);

}
