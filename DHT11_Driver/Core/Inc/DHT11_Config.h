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

#define DHT11_PORT		GPIO_PORTA
#define DHT11_PIN		GPIO_PIN8

#endif /* INC_DHT11_CONFIG_H_ */
