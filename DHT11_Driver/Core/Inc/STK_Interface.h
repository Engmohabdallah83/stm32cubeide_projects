/*
 * STK_Interface.h
 *
 *  Created on: Dec 5, 2022
 *      Author: Mohamed Aboelhassan
 */

#ifndef STK_INTERFACE_H_
#define STK_INTERFACE_H_

#include "Std_Types.h"

void STK_vidInit();
void STK_voidBusyWait(uint32 Copy_u32Counts);
void Delay_us(uint32 Copy_u32uSec);
void Delay_ms(uint32 Copy_u32mSec);
void STK_voidStartTimer();
void STK_voidStopTimer();
void STK_voidGetRemainigCounts(uint32 * Copy_pu32Counts);
void STK_voidGetElapsedCounts(uint32 * Copy_pu32Counts);
void STK_voidSetSingleInterval(uint32 Copy_u32Counts, void	(*ptr)(void));
void STK_voidSetPeriodicInterval(uint32 Copy_u32Counts, void	(*ptr)(void));



#endif /* STK_INTERFACE_H_ */
