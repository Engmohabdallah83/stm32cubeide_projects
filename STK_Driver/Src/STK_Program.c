/*
 * STK_Program.c
 *
 *  Created on: Dec 5, 2022
 *      Author: Mohamed Aboelhassan
 */

#include	"Std_Types.h"

#include	"STK_Interface.h"
#include 	"STK_Private.h"
#include 	"STK_Cinfig.h"

#ifndef		NULL
#define		NULL		(void *)0
#endif

static	void	(*STK_CallBack)	(void)	=	NULL	;
static	uint8	u8_TypOfInterval	=	5	;

void STK_voidInit()
{
	/*		Disable timer and disable interrupt and Clk Source AHB/8	*/
	STK -> CTRL = 0x00000000;
	//STK -> CTRL = 0x00000004;
}
void STK_voidBusyWait(uint32 Copy_u32Counts)
{
	STK -> VAL 	= 0;
	STK -> LOAD = Copy_u32Counts;

	/*	Enable timer		*/
	SET_BIT((STK -> CTRL),0);

	/*	Wait till the flag rises		*/
	while ((GET_BIT((STK -> CTRL),16))==0)
	{
		asm("NOP");
	}

	/*	Stop Timer 		*/
	CLR_BIT((STK -> CTRL),0);
	STK -> VAL 	= 0;
	STK -> LOAD = 0;
}
void STK_voidStartTimer()
{
	/*	Enable timer		*/
	SET_BIT((STK -> CTRL),0);
}
void STK_voidStopTimer()
{
	/*	Stop Timer 		*/
	CLR_BIT((STK -> CTRL),0);
	STK -> VAL 	= 0;
	STK -> LOAD = 0;
}
void STK_voidGetRemainigCounts(uint32 * Copy_pu32Counts)
{
	* Copy_pu32Counts = STK -> VAL ;
}
void STK_voidGetElapsedCounts(uint32 * Copy_pu32Counts)
{
	* Copy_pu32Counts = STK -> LOAD - STK -> VAL ;
}
void STK_voidSetSingleInterval(uint32 Copy_u32Counts, void	(*ptr)(void))
{
	STK -> VAL 	= 0;
	STK -> LOAD = Copy_u32Counts;

	/*	Assign The Call Back	*/
	STK_CallBack	=	ptr;

	/*	Assign The Typ of Interval is Single	*/
	u8_TypOfInterval	=	STK_SINGLE_INTERVAL;

	/*	Enable Interrupt		*/
	SET_BIT((STK -> CTRL),1);
	/*	Enable timer			*/
	SET_BIT((STK -> CTRL),0);

}
void STK_voidSetPeriodicInterval(uint32 Copy_u32Counts, void	(*ptr)(void))
{
	STK -> VAL 	= 0;
	STK -> LOAD = Copy_u32Counts;

	/*	Assign The Call Back	*/
	STK_CallBack	=	ptr;

	/*	Assign The Typ of Interval is Periodic	*/
	u8_TypOfInterval	=	STK_PERIOD_INTERVAL;

	/*	Enable Interrupt		*/
	SET_BIT((STK -> CTRL),1);
	/*	Enable timer			*/
	SET_BIT((STK -> CTRL),0);
}

void	SysTick_Handler(void)
{
	uint8 Local_u8Dummy = 0;
	if(u8_TypOfInterval == STK_SINGLE_INTERVAL)
	{
		/*	Disable Interrupt		*/
		CLR_BIT((STK -> CTRL),1);

		/*	Stop Timer 				*/
		CLR_BIT((STK -> CTRL),0);
		STK -> VAL 	= 0;
		STK -> LOAD = 0;
	}

	STK_CallBack();

	/*	Clear the interrupt Flag		*/
	Local_u8Dummy = (GET_BIT((STK -> CTRL),16));
}
