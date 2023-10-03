/*
 * GPIO_Interface.h
 *
 *  Created on: Aug 27, 2023
 *      Author: Mohamed Aboelhassan
 */

#ifndef INC_GPIO_INTERFACE_H_
#define INC_GPIO_INTERFACE_H_

#include "Std_Types.h"
#include "stm32f103xb.h"

//please use this constant expression in case of request pin direction
constexpr uint8 GPIO_OUT = 1;
constexpr uint8 GPIO_IN  = 0;

constexpr uint8		GPIO_INPUT_AN		 =	0b0000;
constexpr uint8		GPIO_INPUT_FL		 =	0b0100;
constexpr uint8		GPIO_INPUT_PULL		 =	0b1000;

constexpr uint8		GPIO_OUTPUT_10_PP	 =	0b0001;
constexpr uint8		GPIO_OUTPUT_10_OD	 =	0b0101;
constexpr uint8		GPIO_OUTPUT_10_PP_AF =	0b1001;
constexpr uint8		GPIO_OUTPUT_10_OD_AF =	0b1101;

constexpr uint8		GPIO_OUTPUT_2_PP	 =	0b0010;
constexpr uint8		GPIO_OUTPUT_2_OD	 =	0b0110;
constexpr uint8		GPIO_OUTPUT_2_PP_AF	 =	0b1010;
constexpr uint8		GPIO_OUTPUT_2_OD_AF	 =	0b1110;

constexpr uint8		GPIO_OUTPUT_50_PP	 =	0b0011;
constexpr uint8		GPIO_OUTPUT_50_OD	 =	0b0111;
constexpr uint8		GPIO_OUTPUT_50_PP_AF =	0b1011;
constexpr uint8		GPIO_OUTPUT_50_OD_AF =	0b1111;

//please use this constant expression in case of setting pin values
constexpr uint8 GPIO_HIGH = 1;
constexpr uint8 GPIO_LOW  = 0;

class GPIO_ABSTRACT
{
public:

	virtual bool GPIO_SetPinDir( uint8 PIN_Dir) = 0;
	virtual bool GPIO_SetPinVal( uint8 PIN_VAL) = 0;
	virtual bool GPIO_GetPinVal( uint8 PIN_VAL) = 0;

};


class GPIO : public GPIO_ABSTRACT
{
public:
	GPIO(GPIO_TypeDef* PORT, uint8 PIN_ID);

	bool GPIO_SetPinDir(uint8 PIN_Dir )override;

	bool GPIO_SetPinVal(uint8 PIN_VAL) override;

	bool GPIO_GetPinVal(uint8 PIN_VAL) override;


private:
	GPIO_TypeDef* mPORT;
	uint8_t mPIN_ID;
};



#endif /* INC_GPIO_INTERFACE_H_ */
