/*
 * DMA_private.h
 *
 *  Created on: Dec 5, 2022
 *      Author: Mohamed Aboelhassan
 */

#ifndef DMA_PRIVATE_H_
#define DMA_PRIVATE_H_


typedef	struct
{
	uint32	CCR;
	uint32	CNDTR;
	uint32	CPAR;
	uint32	CMAR;
}Channel_t;

typedef struct
{
	uint32	ISR;
	uint32	IFCR;
	Channel_t Ch[7];
}DMA1_type;

#define		DMA1			((volatile DMA1_type *)(0x40020000))

#endif /* DMA_PRIVATE_H_ */
