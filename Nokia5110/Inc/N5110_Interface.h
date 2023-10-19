/******************************************************************************************************
 *  FILE DESCRIPTION
 *  --------------------------------------------------------------------------------------------------
 *         File:  <N5110_Interface.h>
 *       Module:  -N5110
 *			Created on: Jan 24, 2023
 *  Description:  <Write File DESCRIPTION here>
 *			Author: Mohamed Aboelhassan
 ******************************************************************************************************/

#ifndef N5110_INTERFACE_H_
#define N5110_INTERFACE_H_
/*************************************************************************************************************
 * INCLUDES
 ************************************************************************************************************/


/************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 ************************************************************************************************************/

/**************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **************************************************************************************************************/


/**************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **************************************************************************************************************/


/***************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **************************************************************************************************************/


/***************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **************************************************************************************************************/

void n5110_init(unsigned short spi);

void n5110_print(short Ypos, short Xpos, char str[]);

void n5110_pos(short Ypos,short Xpos);


void n5110_clear(void);

void print_buffer(unsigned char screen_buffer[][84]);

void n5110_light(unsigned char HIGH_LOW);

#endif /* N5110_INTERFACE_H_ */