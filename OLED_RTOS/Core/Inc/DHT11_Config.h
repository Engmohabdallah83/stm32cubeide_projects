/*
 * DHT11_Config.h
 *
 *  Created on: Nov 2, 2023
 *      Author: Mohamed Aboelhassan
 */

#ifndef INC_DHT11_CONFIG_H_
#define INC_DHT11_CONFIG_H_

/*
 * please select DHT11 GPIO PORT from following List:
 *
 * GPIO_PORTA
 * GPIO_PORTB
 * GPIO_PORTC
 *
 * And Data PIN from the Following:
 *
 * GPIO_PIN0  , GPIO_PIN1
 * GPIO_PIN2  , GPIO_PIN3
 * GPIO_PIN4  , GPIO_PIN5
 * GPIO_PIN6  , GPIO_PIN7
 * GPIO_PIN8  , GPIO_PIN9
 * GPIO_PIN10 , GPIO_PIN11
 * GPIO_PIN12 , GPIO_PIN13
 * GPIO_PIN14 , GPIO_PIN15
 */

#define DHT11_PORT		GPIOA
#define DHT11_PIN		GPIO_PIN_8

GPIO_InitTypeDef DHT11_PIN_OUT = {GPIO_PIN_8, GPIO_MODE_OUTPUT_PP, GPIO_PULLUP, GPIO_SPEED_FREQ_HIGH};

GPIO_InitTypeDef DHT11_PIN_IN = {GPIO_PIN_8, GPIO_MODE_INPUT, GPIO_PULLUP, GPIO_SPEED_FREQ_HIGH};
//typedef struct
//{
//  uint32_t Pin;       /*!< Specifies the GPIO pins to be configured.
//                           This parameter can be any value of @ref GPIO_pins_define */
//
//  uint32_t Mode;      /*!< Specifies the operating mode for the selected pins.
//                           This parameter can be a value of @ref GPIO_mode_define */
//
//  uint32_t Pull;      /*!< Specifies the Pull-up or Pull-Down activation for the selected pins.
//                           This parameter can be a value of @ref GPIO_pull_define */
//
//  uint32_t Speed;     /*!< Specifies the speed for the selected pins.
//                           This parameter can be a value of @ref GPIO_speed_define */
//} GPIO_InitTypeDef;

#endif /* INC_DHT11_CONFIG_H_ */
