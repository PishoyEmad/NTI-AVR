/*
 * KeyPad_config.h
 *
 *  Created on: Jul 17, 2022
 *      Author: P4P4
 */


#ifndef KEYPAD_KEYPAD_CONFIG_H_
#define KEYPAD_KEYPAD_CONFIG_H_
/*
 * SIM or KIT
 */
#define MODE	KIT

#define ROW_PORT	DIO_PORTB
#define KEYPAD_R0_PIN	DIO_PIN4
#define KEYPAD_R1_PIN	DIO_PIN5
#define KEYPAD_R2_PIN	DIO_PIN6
#define KEYPAD_R3_PIN	DIO_PIN7

#define COL_PORT	DIO_PORTD
#define KEYPAD_C0_PIN	DIO_PIN2
#define KEYPAD_C1_PIN	DIO_PIN3
#define KEYPAD_C2_PIN	DIO_PIN4
#define KEYPAD_C3_PIN	DIO_PIN5

#define KEYPAD_ROWS	4
#define KEYPAD_COLS	4
#define KEYPAD_ARR	{{'1','2','3','+'},{'4','5','6','-'},{'7','8','9','*'},{'=','0','#','/'}}

#endif /* KEYPAD_KEYPAD_CONFIG_H_ */
