/***********************************************************************/
/************			Author: Amgad Samir					************/
/************			Layed: MCAL							************/
/************			Component: NVIC						************/
/************			Version:1.00						************/
/***********************************************************************/

/*Preprocessor File Guard*/
#ifndef NVIC_REG_H_
#define NVIC_REG_H_

#define NVIC_BASE_ADDRESS   0xE000E100

/*Set Enable registers*/
#define ISER	((volatile u32*)NVIC_BASE_ADDRESS)

/*Clear Enable registers*/
#define ICER	((volatile u32*)(NVIC_BASE_ADDRESS+0x80))

/*Set Pending flag registers*/
#define ISPR	((volatile u32*)(NVIC_BASE_ADDRESS+0x100))

/*Clear Pending flag registers*/
#define ICPR	((volatile u32*)(NVIC_BASE_ADDRESS+0x180))

/*Active bit register*/
#define IABR	((volatile u32*)(NVIC_BASE_ADDRESS+0x200))

/*Interrupt priority registers*/
#define IPR		((volatile u8*)(NVIC_BASE_ADDRESS+0x300))

#define SCB_BASE_ADDRESS		0xE000ED00
#define AIRCR	*((volatile u32*)(SCB_BASE_ADDRESS+0x0c))

#endif