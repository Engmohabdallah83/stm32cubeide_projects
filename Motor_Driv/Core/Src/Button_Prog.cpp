/*
 * Button_Prog.cpp
 *
 *  Created on: Sep 5, 2023
 *      Author: Mohamed Aboelhassan
 */

#include "Std_Types.h"
#include "GPIO_Interface.h"
#include "Button_Interface.h"


Button::Button(GPIO_TypeDef * port, uint16_t pin):button_port(port),btn_pin(pin)
{
	GPIO mButton(button_port, btn_pin);
	mButton.GPIO_SetPinDir(GPIO_INPUT_PULL);
}

uint32_t Button::GetButtonStatus()
{
	return GET_BIT(button_port->IDR ,btn_pin);
}


