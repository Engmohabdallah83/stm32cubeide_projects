/*
 * STK_Interface.h
 *
 *  Created on: Dec 5, 2022
 *      Author: Mohamed Aboelhassan
 */

#ifndef STK_INTERFACE_H_
#define STK_INTERFACE_H_

void STK_voidInit();
void STK_voidBusyWait(uint32 Copy_u32Counts);
void STK_voidStartTimer();
void STK_voidStopTimer();
void STK_voidGetRemainigCounts(uint32 * Copy_pu32Counts);
void STK_voidGetElapsedCounts(uint32 * Copy_pu32Counts);
void STK_voidSetSingleInterval(uint32 Copy_u32Counts, void	(*ptr)(void));
void STK_voidSetPeriodicInterval(uint32 Copy_u32Counts, void	(*ptr)(void));



#endif /* STK_INTERFACE_H_ */
