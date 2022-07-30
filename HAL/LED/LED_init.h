/*
 * LED_Init.h
 *
 *  Created on: Jul 6, 2022
 *      Author: P4P4
 */

#ifndef LED_LED_INIT_H_
#define LED_LED_INIT_H_

#define RED_LED	0
#define GRN_LED 1
#define BLU_LED 2

void H_Led_void_LedInit(u8 Copy_u8LedID);
void H_Led_void_LedSetOff(u8 Copy_u8LedID);
void H_Led_void_LedSetOn(u8 Copy_u8LedID);
void H_Led_void_LedToggle(u8 Copy_u8LedID);


#endif /* LED_LED_INIT_H_ */
