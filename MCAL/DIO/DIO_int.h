/*
 * DIO_int.h
 *
 *  Created on: Jul 4, 2022
 *      Author: P4P4
 */


#ifndef DIO_DIO_INT_H_
#define DIO_DIO_INT_H_

#include "DIO_privet.h"
#include "DIO_confih.h"
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"


/***********PORTID***********/
#define DIO_PORTA	0
#define DIO_PORTB	1
#define DIO_PORTC	2
#define DIO_PORTD	3

/***********PINID***********/
#define DIO_PIN0		0
#define DIO_PIN1		1
#define DIO_PIN2		2
#define DIO_PIN3		3
#define DIO_PIN4		4
#define DIO_PIN5		5
#define DIO_PIN6		6
#define DIO_PIN7		7

/***********PIN_DIRECTION***********/
#define INPUT		0
#define OUTPUT		1

/***********PIN_DIRECTION***********/
#define HIGH	1
#define LOW		0

void M_DIO_void_Init(void);
void M_DIO_void_SetPinDirection(u8 Copy_u8PortID,u8 Copy_u8PinID,u8 Copy_u8PinDirection);
void M_DIO_void_SetPinValue(u8 Copy_u8PortID,u8 Copy_u8PinID,u8 Copy_u8PinValue);
void M_DIO_void_GetPiValue(u8 port,u8 pin,u8 * ptrValue);
void M_DIO_void_TogglePinValue(u8 port,u8 pin);

#endif /* DIO_DIO_INT_H_ */
