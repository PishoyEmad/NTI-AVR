/*
 * EXTI_init.h
 *
 *  Created on: Jul 19, 2022
 *      Author: P4P4
 */

#ifndef EXTI_EXTI_INIT_H_
#define EXTI_EXTI_INIT_H_

#define INT0_ID	6
#define INT1_ID	7
#define INT2_ID	5

#define	RISE_EDGE	3
#define FALL_EDGE	2
#define ANY_CHANGE	1
#define LOW_LEVEL	0

void M_EXTI_void_Enable(u8 Copy_u8IntID,u8 Copy_u8Trigger);
void M_EXTI_void_Disable(u8 Copy_u8IntID);

void	M_EXTI_void_SetCallBack(void (*Copy_ptrFunction)(void),u8 Copy_u8IntID);

#endif /* EXTI_EXTI_INIT_H_ */
