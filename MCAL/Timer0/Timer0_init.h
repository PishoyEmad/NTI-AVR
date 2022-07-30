/*
 * Timer0.init.h
 *
 *  Created on: Jul 25, 2022
 *      Author: P4P4
 */

#ifndef TIMER0_TIMER0_INIT_H_
#define TIMER0_TIMER0_INIT_H_

#include "Timer0_config.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Timer0_privet.h"
#include "DIO_int.h"
#include <avr/interrupt.h>

void M_Timer0_Void_Init(void);
void M_Timer0_Void_SetTime(u32);
void M_Timer0_Void_Start(void);
void M_Timer0_Void_Stop(void);
void M_TIMER0_Void_SetCallBack(void (*CopyPtr)(void));

void M_Timer0_Void_PWM0Init(void);
void M_Timer0_Void_PWM0SetDutyCycle(u8);
void M_Timer0_Void_PWM0Start(void);
void M_Timer0_Void_PWM0Stop(void);


#endif /* TIMER0_TIMER0_INIT_H_ */
