/*
 * DHT11_Prog.c
 *
 *  Created on: Oct 31, 2023
 *      Author: Mohamed Aboelhassan
 */

#include"Std_Types.h"
#include "DHT11_Config.h"
#include "DHT11_Interface.h"
#include "GPIO_Interface.h"
#include"STK_Interface.h"



/*
 * DHT11 Data PIN Read
 * READ GPIO PIN of DHT11 PIN of DHT11 PORT
 * Return the PIN value
 */
PIN_Val DHT11_ReadPin(void)
{
	PIN_Val u8ReadPin;
	GPIO_PR(DHT11_PORT, DHT11_PIN, &u8ReadPin);
	return u8ReadPin;
}

/*
 * INITIALIZATION
 * Set the pin (data) as output
 * Pull the pin low and wait for 18ms
 * set the pin as input for receiving the data
 */
void DHT11_Start (void)
{
//	Set_Pin_Output (DHT11_PORT, DHT11_PIN);  // set the pin as output
	GPIO_PDir(DHT11_PORT, DHT11_PIN, GPIO_OUTPUT_50_PP);
//	HAL_GPIO_WritePin (DHT11_PORT, DHT11_PIN, 0);   // pull the pin low
	GPIO_PW(DHT11_PORT, DHT11_PIN, GPIO_LOW);
	Delay_ms(15);   // wait for 18ms
//	Set_Pin_Input(DHT11_PORT, DHT11_PIN);    // set as input
	GPIO_IN_PULLUP(DHT11_PORT, DHT11_PIN);

}

/*
 * RESPONSE
 * wait for 40 us
 * check if the pin is low, than wait for 80 us. This will totally be a delay of 120 us and the pin should be high now
 * Check if the pin is high. If it is, than the response is OK
 */
uint8 Check_Response (void)
{
	uint8 Response = 0;
	Delay_us(32);
//	HAL_GPIO_ReadPin (DHT11_PORT, DHT11_PIN);
	if (!( DHT11_ReadPin() ))
	{
		Delay_us(72);
//		HAL_GPIO_ReadPin (DHT11_PORT, DHT11_PIN);
		if ( DHT11_ReadPin() ) Response = 1;
		else Response = 0;
	}
	while ( DHT11_ReadPin() );   // wait for the pin to go low

	return Response;
}


/*
 * READ DATA
 * Wait for the pin to go high
 * Wait for 40 us. This is because the length of “0” bit is 26-28 us  and if the pin is high after 40 us, it indicates that the bit is “1”
 * write the respective values to the variable
 */
uint8 DHT11_Read (void)
{
	uint8 i=0,j;
	for (j=0;j<8;j++)
	{
		while (!( DHT11_ReadPin() ));   // wait for the pin to go high
		Delay_us(30) ;   // wait for 40 us
		if (!( DHT11_ReadPin() ))   // if the pin is low
		{
			i&= ~(1<<(7-j));   // write 0
		}
		else i|= (1<<(7-j));  // if the pin is high, write 1
		while ( DHT11_ReadPin() );  // wait for the pin to go low
	}
	return i;
}


/*
 * Call DHT11_Start
 * Call DHT11_Response
 * check on response and send start again if no response
 * Loop on Call DHT11_Read for 5 Times
 * Fill Data Array
 */

void DHT11_ReadAll(uint8 * pu8Data)
{
	do{
		DHT11_Start();

	}while( !(Check_Response()) );

	for(uint8 i = 0; i<5; i++)
	{
		pu8Data[i] = DHT11_Read();
	}
}


/*
 * Name: Read Data
 * create an uint8 Array of size 5
 * call Read All function
 * Assign by value Humidity Data int data[0] + decimal data[1]
 * Assign by value Humidity Data int data[2] + decimal data[3]
 */
void DHT11_ReadData(float * Cpy_f32Hum , float * Cpy_f32Temp)
{
	uint8 u8AllData[5];
	DHT11_ReadAll(u8AllData);
	* Cpy_f32Hum  = (u8AllData[0]+ u8AllData[1] * 0.1);
	* Cpy_f32Temp = (u8AllData[2]+ u8AllData[3] * 0.1);
}
