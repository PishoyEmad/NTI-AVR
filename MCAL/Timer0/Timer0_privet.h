/*
 * Timer0_privet.h
 *
 *  Created on: Jul 25, 2022
 *      Author: P4P4
 */

#ifndef TIMER0_TIMER0_PRIVET_H_
#define TIMER0_TIMER0_PRIVET_H_




#define TCCR0_REG		*((volatile u8 *)0x53)
#define FOC0			7
#define WGM00			6
#define COM01			5
#define COM00			4
#define WGM01			3
#define CS02			2
#define CS01			1
#define CS00			0

#define NORMAL_MODE		1
#define CTC_MODE		2
#define FAST_PWN_MODE	3
#define PHASE_CORRECT	4

#define NON_INVERTED	0
#define	INVERTED		1

#define TIMSK_REG		*((volatile u8 *)0x59)
#define OCIE0			1
#define TOIE0			0

#define TCNT0_REG		*((volatile u8 *)0x52)

#define OCR0_REG   		*((volatile u8 *)0x5C)


#endif /* TIMER0_TIMER0_PRIVET_H_ */
