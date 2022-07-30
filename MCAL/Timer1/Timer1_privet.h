/*
 * Timer0_privet.h
 *
 *  Created on: Jul 25, 2022
 *      Author: P4P4
 */

#ifndef TIMER1_TIMER1_PRIVET_H_
#define TIMER1_TIMER1_PRIVET_H_




#define TCCR1A_REG		*((volatile u8 *)0x4F)
#define COM1A1			7
#define COM1A0			6
/*
#define COM1B1			5
#define COM1B0			4
#define FOC1A			3
#define FOC1B			2
*/
#define WGM11			1
#define WGM10			0

#define TCCR1B_REG		*((volatile u8 *)0x4E)
/*
#define ICNC1			7
#define ICES1			6
*/
#define WGM13			4
#define WGM12			3
#define CS12			2
#define CS11			1
#define CS10			0

/*
#define NORMAL_MODE		1
#define CTC_MODE		2
#define FAST_PWN_MODE	3
#define PHASE_CORRECT	4
*/
/*
#define NON_INVERTED	0
#define	INVERTED		1
*/
/*
#define TIMSK_REG		*((volatile u8 *)0x59)
#define OCIE1			1
#define TOIE1			0

#define TCNT1_REG		*((volatile u8 *)0x52)
*/
#define OCR1A_REG   	*((volatile u16 *)0x4A)
#define ICR1_REG   		*((volatile u16 *)0x46)


#endif /* TIMER1_TIMER1_PRIVET_H_ */
