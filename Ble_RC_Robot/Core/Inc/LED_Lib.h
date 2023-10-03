/*
 * LED_Lib.h
 *
 *  Created on: Aug 24, 2023
 *      Author: Mohamed Aboelhassan
 */

#ifndef INC_LED_LIB_H_
#define INC_LED_LIB_H_

#include "Std_Types.h"
#include "stm32f103xb.h"
/*
 * Create an abstract to LED
 * This abstract class Encapsulate every thing
 * about LED PORT attached, Pin attached
 *
 * */

class LED_ABSTRACT
{
public:
	virtual void LED_ON() = 0;
	virtual void LED_OFF() = 0;
};

class LED : public LED_ABSTRACT
{
public:
	LED(GPIO_TypeDef* LED_PORT, uint8_t PIN);
	void LED_ON();

	void LED_OFF();

private:
	GPIO_TypeDef* mLED_PORT;
	uint8 mPIN;
	uint8 mCfg;
};

class RGB_LED : public LED_ABSTRACT
{
public:
	RGB_LED(GPIO_TypeDef* RLED_PORT,GPIO_TypeDef* GLED_PORT ,GPIO_TypeDef* BLED_PORT,
			uint8_t R_PIN,uint8_t G_PIN, uint8_t B_PIN);

	void R_LED_ON();
	void G_LED_ON();
	void B_LED_ON();

//	void R_LED_OFF();
//	void G_LED_OFF();
//	void G_LED_OFF();

private:
	GPIO_TypeDef* mRLED_PORT;
	GPIO_TypeDef* mGLED_PORT;
	GPIO_TypeDef* mBLED_PORT;
	uint8_t mR_PIN;
	uint8_t mG_PIN;
	uint8_t mB_PIN;
};



#endif /* INC_LED_LIB_H_ */
