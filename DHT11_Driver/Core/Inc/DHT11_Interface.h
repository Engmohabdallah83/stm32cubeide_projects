/*
 * DHT11_Interface.h
 *
 *  Created on: Oct 31, 2023
 *      Author: Mohamed Aboelhassan
 */

#ifndef INC_DHT11_INTERFACE_H_
#define INC_DHT11_INTERFACE_H_

typedef unsigned char PIN_Val	;


PIN_Val DHT11_ReadPin(void);



/*
 * INITIALIZATION
 * Set the pin (data) as output
 * Pull the pin low and wait for 18ms
 * set the pin as input for receiving the data
 */
void DHT11_Start (void);

/*
 * RESPONSE
 * wait for 40 us
 * check if the pin is low, than wait for 80 us. This will totally be a delay of 120 us and the pin should be high now
 * Check if the pin is high. If it is, than the response is OK
 */
uint8 Check_Response (void);

/*
 * READ DATA
 * Wait for the pin to go high
 * Wait for 40 us. This is because the length of “0” bit is 26-28 us  and if the pin is high after 40 us, it indicates that the bit is “1”
 * write the respective values to the variable
 */
uint8 DHT11_Read (void);

/*
 * Name: Read Humidity
 * create Array of 5 for uint8
 * call Read All
 * return Humidity Data
 */

/*
 * Call DHT11_Start
 * Call DHT11_Response
 * check on response and send start again if no response
 * Loop on Call DHT11_Read for 5 Times
 * Fill Data Array
 */

void DHT11_ReadAll(uint8 * pu8Data);


/*
 * Name: Read Data
 * create an uint8 Array of size 5
 * call Read All function
 * Assign by value Humidity Data int data[0] + decimal data[1]
 * Assign by value Humidity Data int data[2] + decimal data[3]
 */
void DHT11_ReadData(float * Cpy_f32Hum , float * Cpy_f32Temp);



#endif /* INC_DHT11_INTERFACE_H_ */
