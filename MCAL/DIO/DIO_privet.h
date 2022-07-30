/*
 * DIO_privet.h
 *
 *  Created on: Jul 4, 2022
 *      Author: P4P4
 */

#ifndef DIO_DIO_PRIVET_H_
#define DIO_DIO_PRIVET_H_

#define PORTA_REG	*((volatile u8*)0x3B)
#define PORTB_REG	*((volatile u8*)0x38)
#define PORTC_REG	*((volatile u8*)0x35)
#define PORTD_REG	*((volatile u8*)0x32)

#define DDRA_REG	*((volatile u8*)0x3A)
#define DDRB_REG	*((volatile u8*)0x37)
#define DDRC_REG	*((volatile u8*)0x34)
#define DDRD_REG	*((volatile u8*)0x31)

#define PINA_REG	*((volatile u8*)0x39)
#define PINB_REG	*((volatile u8*)0x36)
#define PINC_REG	*((volatile u8*)0x33)
#define PIND_REG	*((volatile u8*)0x30)


#define CONC(b0,b1,b2,b3,b4,b5,b6,b7)		CONC_HELP(b0,b1,b2,b3,b4,b5,b6,b7)
#define	CONC_HELP(b0,b1,b2,b3,b4,b5,b6,b7)	0b##b7##b6##b5##b4##b3##b2##b1##b0


#endif /* DIO_DIO_PRIVET_H_ */
