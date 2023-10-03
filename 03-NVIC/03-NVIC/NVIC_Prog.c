#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_Interface.h"
#include "NVIC_REG.h"

#define OK		0
#define NOK		1
#define NULL	0
#define NULL_POINTER 2

u8 NVIC_u8InterruptEnable(u8 Copy_u8IntID)
{
	u8 Local_u8ErrorState=OK;
	if(Copy_u8IntID<32)
	{
		ISER[0]=1<<Copy_u8IntID;
	}
	else if(Copy_u8IntID<60)
	{
		Copy_u8IntID-=32;
		ISER[1]=1<<Copy_u8IntID;
	}
	else
	{
		Local_u8ErrorState=NOK;
	}
	
	return Local_u8ErrorState;
}

u8 NVIC_u8InterruptDisable(u8 Copy_u8IntID)
{
	u8 Local_u8ErrorState=OK;
	if(Copy_u8IntID<32)
	{
		ICER[0]=1<<Copy_u8IntID;
	}
	else if(Copy_u8IntID<60)
	{
		Copy_u8IntID-=32;
		ICER[1]=1<<Copy_u8IntID;
	}
	else
	{
		Local_u8ErrorState=NOK;
	}
	
	return Local_u8ErrorState;
}

u8 NVIC_u8SetPendingFlag(u8 Copy_u8IntID)
{
	u8 Local_u8ErrorState=OK;
	if(Copy_u8IntID<32)
	{
		ISPR[0]=1<<Copy_u8IntID;
	}
	else if(Copy_u8IntID<60)
	{
		Copy_u8IntID-=32;
		ISPR[1]=1<<Copy_u8IntID;
	}
	else
	{
		Local_u8ErrorState=NOK;
	}
	
	return Local_u8ErrorState;
}

u8 NVIC_u8ClearPendingFlag(u8 Copy_u8IntID)
{
	u8 Local_u8ErrorState=OK;
	if(Copy_u8IntID<32)
	{
		ICPR[0]=1<<Copy_u8IntID;
	}
	else if(Copy_u8IntID<60)
	{
		Copy_u8IntID-=32;
		ICPR[1]=1<<Copy_u8IntID;
	}
	else
	{
		Local_u8ErrorState=NOK;
	}
	
	return Local_u8ErrorState;
}

u8 NVIC_u8GetActiveFlag(u8 Copy_u8IntID,u8* Copy_pu8Flag)
{
	u8 Local_u8ErrorState=OK;
	if (Copy_pu8Flag !=NULL)
	{
		if(Copy_u8IntID<32)
		{
			*Copy_pu8Flag=GET_BIT(IABR[0],Copy_u8IntID);
		}
		else if(Copy_u8IntID<60)
		{
			Copy_u8IntID-=32;
			*Copy_pu8Flag=GET_BIT(IABR[1],Copy_u8IntID);
		}
		else
		{
			Local_u8ErrorState=NOK;
		}
	}
	else
	{
		Local_u8ErrorState=NULL_POINTER;
	}
	
	return Local_u8ErrorState;
}

u8 NVIC_u8SetPriority(u8 Copy_u8IntID,u8 Copy_u8GrpPriority,u8 Copy_u8SubPriority)
{
	u8 Local_u8ErrorState=OK;
	u8 Local_u8Priority;
	if(Copy_u8IntID>59)
	{
		Local_u8ErrorState=NOK;
	}
	else
	{
		Local_u8Priority= ((Copy_u8SubPriority)|(Copy_u8GrpPriority<<2))<<4;
		//Local_u8Priority= ((Copy_u8GrpPriority<<6) | (Copy_u8SubPriority<<4));
		
		IPR[Copy_u8IntID]=Local_u8Priority;
	}
	
	return Local_u8ErrorState;
}

void SCB_u8SetNVICPriority(void)
{
	
	/*
	2 bits Group priority
	2 bits Sub Priority
	*/
	AIRCR= 0x05FA0500;
}