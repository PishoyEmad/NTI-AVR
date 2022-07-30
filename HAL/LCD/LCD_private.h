/*
 * LCD_private.h
 *
 *  Created on: Jul 17, 2022
 *      Author: P4P4
 */

#ifndef LCD_LCD_PRIVATE_H_
#define LCD_LCD_PRIVATE_H_

#define FOUR_BIT   0
#define EIGHT_BIT  1

#define FUNTION_SET_8BIT_2LINES_5x7DOTS  0x38
#define FUNTION_SET_4BIT_2LINES_5x7DOTS  0x28

#define DISPLAY_ON_CURSOR_ON_BLink_OFF   0x0E
#define DISPLAY_CLEAR                    0x01
#define ENTERY_MODE_SET                  0x06

#define SET_R0_C0    0x80
#define SET_R1_C0    0xC0

#define SET_CGRAM_ADRESS	0b01000000
#define SET_DDRAM_ADRESS	0x80

static void H_LCD_void_writeNlatch(u8 copy_u8Byte);


#endif /* LCD_LCD_PRIVATE_H_ */
