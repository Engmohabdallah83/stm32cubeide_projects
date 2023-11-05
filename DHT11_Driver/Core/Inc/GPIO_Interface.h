/*
 * GPIO_Interface.h
 *
 *  Created on: Nov 25, 2022
 *      Author: Mohamed Aboelhassan
 */

#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_

#include"Std_Types.h"


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

#define		GPIO_INPUT_AN			0b00000000
#define		GPIO_INPUT_FL			0b00000100
#define		GPIO_INPUT_PULL			0b00001000

#define		GPIO_OUTPUT_10_PP		0b00000001
#define		GPIO_OUTPUT_10_OD		0b00000101
#define		GPIO_OUTPUT_10_PP_AF	0b00001001
#define		GPIO_OUTPUT_10_OD_AF	0b00001101

#define		GPIO_OUTPUT_2_PP		0b00000010
#define		GPIO_OUTPUT_2_OD		0b00000110
#define		GPIO_OUTPUT_2_PP_AF		0b00001010
#define		GPIO_OUTPUT_2_OD_AF		0b00001110

#define		GPIO_OUTPUT_50_PP		0b00000011
#define		GPIO_OUTPUT_50_OD		0b00000111
#define		GPIO_OUTPUT_50_PP_AF	0b00001011
#define		GPIO_OUTPUT_50_OD_AF	0b00001111


Std_ReturnType GPIO_PDir(uint8 Copy_u8PortId,uint8 Copy_u8PinId,uint8 Copy_u8Diretion);
Std_ReturnType GPIO_IN_PULLUP(uint8 Copy_u8PortId , uint8 Copy_u8PinId);
Std_ReturnType GPIO_IN_PULLDN(uint8 Copy_u8PortId , uint8 Copy_u8PinId);
Std_ReturnType GPIO_PW(uint8 Copy_u8PortId,uint8 Copy_u8PinId,uint8 Copy_u8Value);
Std_ReturnType GPIO_PR(uint8 Copy_u8PortId, uint8 Copy_u8PinId, uint8 * Copy_pu8Value);

#endif /* GPIO_INTERFACE_H_ */
