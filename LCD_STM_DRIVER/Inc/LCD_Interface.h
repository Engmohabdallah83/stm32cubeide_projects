/*
 * LCD_Interface.h
 *
 *  Created on: Jan 25, 2019
 *      Author: Mohamed AbdALLAh
 *      LCD P/N: LMB161A
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

/*Please Select Control PORT*/
#define LCD_u8CONTROLPORT  GPIO_PORTA

/*Please Select DATA PORT*/
#define LCD_u8DATAPORT 	   GPIO_PORTC

/*Please Select ENABLE PIN IN CONTROL PORT SELECTED*/
#define LCD_u8EN_PIN   GPIO_PIN4

/*Please Select RW PIN IN CONTROL PORT SELECTED*/
#define LCD_u8RW_PIN   GPIO_PIN5

/*Please Select RS PIN IN CONTROL PORT SELECTED*/
#define LCD_u8RS_PIN   GPIO_PIN6

/* If Back Light Needed to be controlled please write 1 else write  0 */

#define 	LCD_Back_LT_EN		0

/*Please Select Back Light Control PIN IN CONTROL PORT SELECTED*/

#define LCD_Back_LT		GPIO_PIN7

/*Please Define MAX String Size for LCD Write String Function*/

#define strMAXSIZE 11

/*AC Address to--> CGRAM Instruction*/

#define SET_AC_TO_CGRAM    0x40

/*AC Address to--> DDRAM Instruction*/

#define SET_AC_TO_DDRAM    0x80

/*Prototypes*/

void LCD_vidWriteCommand(uint8 LOC_u8Command);

void LCD_vidWriteData(uint8 LOC_u8Data);

void LCD_vidInit(void);

/*
 * LCD Write String
 * Input Pointer to Array of String
 * Input MAX Size by define it in interface file
 * Show string by call LCD write data Function
 *
 */

void LCD_vidWriteString(uint8 *LOC_pu8String,uint8 LOC_u8MaxSize);

/*
 * LCD Go to Address
 * Input Row Location
 * Input Column Location
 * Set Address from Row & Column Location
 * Send Command
 *
 */

void vid_GoToAddress(uint8 LOC_u8Column , uint8 LOC_u8Row );

void LCD_vidWriteExtraChar (uint8 Y,uint8 X);

/*
 * Write in CGRAM
 * Input Column
 * Input Row
 * Output void
 *SET AC Address to CGRAM
 *Write Data in CGRAM
 *SET AC Address to DDRAM
 *
 */
void LCD_vidWriteInCGRAM(uint8 LOC_u8Column , uint8 LOC_u8Row);

/*
 * LCD Clear Function
 *
 */
void LCD_vidClear();

void LCD_vidWriteInt(uint16 number);

/*
 *  Until making PORT Function

*/

void GPIO_voidSetPortValue(uint8 COPY_PORT ,uint8  LOC_u8Command);


#endif /* LCD_INTERFACE_H_ */
