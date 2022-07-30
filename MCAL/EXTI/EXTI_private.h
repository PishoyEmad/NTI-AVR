/*
 * EXTI_private.h
 *
 *  Created on: Jul 19, 2022
 *      Author: P4P4
 */

#ifndef EXTI_EXTI_PRIVATE_H_
#define EXTI_EXTI_PRIVATE_H_

#define EXTI_MCUCR	*((volatile u8*)0x55)	//Trigger Register
#define ISC00	0	//Interrupt Sense Control 0	Bit	0
#define ISC01	1	//Interrupt Sense Control 0	Bit	1
#define ISC10	2	//Interrupt Sense Control 0	Bit	2
#define ISC11	3	//Interrupt Sense Control 0	Bit	3

#define EXTI_MCUCSR	*((volatile u8*)0x54)	//Trigger Register
#define ISC2	6	//Interrupt Sense Control 2

#define EXTI_GICR	*((volatile u8*)0x5B)	//PIE	Register
#define  INT2	5
#define  INT0	6
#define  INT1	7

#define EXTI_GIFR	*((volatile u8*)0x5A)	// Flag Register
#define  INTF2	5
#define  INTF0	6
#define  INTF1	7

#define EXTI_INT0_TRIGGER_MASK	0b11111100
#define EXTI_INT1_TRIGGER_MASK	0b11110011
#define EXTI_INT2_TRIGGER_MASK	0b10111111

#endif /* EXTI_EXTI_PRIVATE_H_ */
