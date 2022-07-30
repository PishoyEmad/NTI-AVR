/*
 * KeyPad_init.h
 *
 *  Created on: Jul 17, 2022
 *      Author: P4P4
 */

#ifndef KEYPAD_KEYPAD_INIT_H_
#define KEYPAD_KEYPAD_INIT_H_

#define NO_PRESSED_KEY	0xff

void H_KeyPad_void_init(void);
u8 H_KeyPad_u8_GetPressedKey(void);

#endif /* KEYPAD_KEYPAD_INIT_H_ */
