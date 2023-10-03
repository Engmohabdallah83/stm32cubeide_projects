/*
 * GPIO_Interface.h
 *
 *  Created on: Nov 25, 2022
 *      Author: Mohamed Aboelhassan
 */

#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_


#define		GPIO_PORTA		0
#define		GPIO_PORTB		1
#define		GPIO_PORTC		2

#define		GPIO_PIN0		0
#define		GPIO_PIN1		1
#define		GPIO_PIN2		2
#define		GPIO_PIN3		3
#define		GPIO_PIN4		4
#define		GPIO_PIN5		5
#define		GPIO_PIN6		6
#define		GPIO_PIN7		7
#define		GPIO_PIN8		8
#define		GPIO_PIN9		9
#define		GPIO_PIN10		10
#define		GPIO_PIN11	    11
#define		GPIO_PIN12	    12
#define		GPIO_PIN13	    13
#define		GPIO_PIN14	    14
#define		GPIO_PIN15	    15

#define		GPIO_HIGH		1
#define		GPIO_LOW		0

#define		GPIO_INPUT_AN			0b0000
#define		GPIO_INPUT_FL			0b0100
#define		GPIO_INPUT_PULL			0b1000

#define		GPIO_OUTPUT_10_PP		0b0001
#define		GPIO_OUTPUT_10_OD		0b0101
#define		GPIO_OUTPUT_10_PP_AF	0b1001
#define		GPIO_OUTPUT_10_OD_AF	0b1101

#define		GPIO_OUTPUT_2_PP		0b0010
#define		GPIO_OUTPUT_2_OD		0b0110
#define		GPIO_OUTPUT_2_PP_AF		0b1010
#define		GPIO_OUTPUT_2_OD_AF		0b1110

#define		GPIO_OUTPUT_50_PP		0b0011
#define		GPIO_OUTPUT_50_OD		0b0111
#define		GPIO_OUTPUT_50_PP_AF	0b1011
#define		GPIO_OUTPUT_50_OD_AF	0b1111


void	GPIO_voidSetPinDirection(uint8 Copy_u8PortId,uint8 Copy_u8PinId,uint8 Copy_u8Diretion);
void	GPIO_voidSetPinValue	(uint8 Copy_u8PortId,uint8 Copy_u8PinId,uint8 Copy_u8Value);
void	GPIO_voidGetPinValue(uint8 Copy_u8PortId,uint8 Copy_u8PinId,uint8 * Copy_pu8Value);

#endif /* GPIO_INTERFACE_H_ */
