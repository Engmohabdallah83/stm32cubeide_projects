/*
 * Button_Interface.h
 *
 *  Created on: Sep 5, 2023
 *      Author: Mohamed Aboelhassan
 */

#ifndef INC_BUTTON_INTERFACE_H_
#define INC_BUTTON_INTERFACE_H_



class Button
{
public:
	Button(GPIO_TypeDef * port, uint16_t pin);
	uint32_t GetButtonStatus();
private:
	GPIO_TypeDef * button_port;
	uint16_t btn_pin{0};
};


#endif /* INC_BUTTON_INTERFACE_H_ */
