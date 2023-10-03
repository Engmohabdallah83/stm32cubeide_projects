/*
 * LED_Lib_Src.cpp
 *
 *  Created on: August 24, 2023
 *      Author: Mohamed Aboelhassan
 */


#include "LED_Lib.h"
#include "GPIO_Interface.h"


constexpr unsigned char PIN_CFN_MODE_WIDTH = 4;
constexpr unsigned char RegWidth = 32;
constexpr unsigned char PORT_LOW_NIBBLE = 7;


LED::LED(GPIO_TypeDef* LED_PORT, uint8_t PIN): mLED_PORT(LED_PORT),mPIN(PIN)
{
	GPIO GPIO_GLED(mLED_PORT, mPIN);
	GPIO_GLED.GPIO_SetPinDir(GPIO_OUT);

}
void LED::LED_ON()
{
	mLED_PORT->ODR |= 1<<mPIN;
}

void LED::LED_OFF()
{
	mLED_PORT->ODR &= ~(1<<mPIN);
}

RGB_LED::RGB_LED(GPIO_TypeDef* RLED_PORT,GPIO_TypeDef* GLED_PORT ,GPIO_TypeDef* BLED_PORT,
		uint8_t R_PIN,uint8_t G_PIN, uint8_t B_PIN):mRLED_PORT(RLED_PORT),mGLED_PORT(GLED_PORT),
		mBLED_PORT(BLED_PORT),mR_PIN(R_PIN),mG_PIN(G_PIN),mB_PIN(B_PIN)
{
	GPIO GPIO_R_LED(mRLED_PORT,mR_PIN);
	GPIO_R_LED.GPIO_SetPinDir(GPIO_OUT);
	GPIO GPIO_G_LED(mGLED_PORT,mG_PIN);
	GPIO_G_LED.GPIO_SetPinDir(GPIO_OUT);
	GPIO GPIO_B_LED(mBLED_PORT,mB_PIN);
	GPIO_B_LED.GPIO_SetPinDir(GPIO_OUT);
}



void RGB_LED::R_LED_ON()
{}
void RGB_LED::G_LED_ON()
{}
void RGB_LED::B_LED_ON()
{}

//void RGB_LED::R_LED_OFF()
//{}
//void RGB_LED::G_LED_OFF()
//{}
//void RGB_LED::G_LED_OFF()
//{}


