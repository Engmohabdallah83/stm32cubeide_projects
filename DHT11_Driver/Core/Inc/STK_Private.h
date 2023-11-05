/*
 * STK_Private.h
 *
 *  Created on: Dec 5, 2022
 *      Author: Mohamed Aboelhassan
 */

#ifndef STK_PRIVATE_H_
#define STK_PRIVATE_H_


#define		STK_SINGLE_INTERVAL		0
#define		STK_PERIOD_INTERVAL		1
typedef struct
{
	volatile uint32 CTRL;
	volatile uint32 LOAD;
	volatile uint32 VAL;
	volatile uint32 CALIB;

}STK_Type;

#define STK		((STK_Type *)(0xE000E010))


#endif /* STK_PRIVATE_H_ */
