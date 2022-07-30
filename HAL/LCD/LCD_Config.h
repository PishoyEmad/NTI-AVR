/*
 * LCD_Config.h
 *
 *  Created on: Jul 17, 2022
 *      Author: P4P4
 */

#ifndef LCD_LCD_CONFIG_H_
#define LCD_LCD_CONFIG_H_


/*
 * 	Choose LCD MODE :FOUR_BIT,EIGHT_BIT
 */
#define LCD_MODE	FOUR_BIT

#define RS_PIN     DIO_PIN1
#define RS_PORT    DIO_PORTA

#define RW_PIN     DIO_PIN0
#define RW_PORT    DIO_PORTA

#define EN_PIN      DIO_PIN2
#define EN_PORT     DIO_PORTA


/*
 * data pins
 * */
#define D7_PIN     DIO_PIN6
#define D7_PORT    DIO_PORTA

#define D6_PIN     DIO_PIN5
#define D6_PORT    DIO_PORTA

#define D5_PIN     DIO_PIN4
#define D5_PORT    DIO_PORTA

#define D4_PIN     DIO_PIN3
#define D4_PORT    DIO_PORTA


/*
 * not used
 * */
#define D3_PIN     DIO_PIN0
#define D3_PORT    DIO_PORTB

#define D2_PIN     DIO_PIN2
#define D2_PORT    DIO_PORTB

#define D1_PIN     DIO_PIN3
#define D1_PORT    DIO_PORTB

#define D0_PIN     DIO_PIN4
#define D0_PORT    DIO_PORTB


#endif /* LCD_LCD_CONFIG_H_ */
