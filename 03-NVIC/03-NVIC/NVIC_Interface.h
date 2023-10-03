/***********************************************************************/
/************			Author: Amgad Samir					************/
/************			Layed: MCAL							************/
/************			Component: NVIC						************/
/************			Version:1.00						************/
/***********************************************************************/

/*Preprocessor File Guard*/
#ifndef NVIC_INTERFACE_H_
#define NVIC_INTERFACE_H_

u8 NVIC_u8InterruptEnable(u8 Copy_u8IntID);

u8 NVIC_u8InterruptDisable(u8 Copy_u8IntID);

u8 NVIC_u8SetPendingFlag(u8 Copy_u8IntID);

u8 NVIC_u8ClearPendingFlag(u8 Copy_u8IntID);

u8 NVIC_u8GetActiveFlag(u8 Copy_u8IntID,u8* Copy_pu8Flag);

u8 NVIC_u8SetPriority(u8 Copy_u8IntID,u8 Copy_u8GrpPriority,u8 Copy_u8SubPriority);

void SCB_u8SetNVICPriority(void);


#endif