/*
 * Timer1.init.h
 *
 *  Created on: Jul 28, 2022
 *      Author: P4P4
 */

#ifndef TIMER1_TIME1_INIT_H_
#define TIMER1_TIMER1_INIT_H_

#include "Timer1_config.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Timer1_privet.h"
#include "DIO_int.h"
/*
void M_Timer0_Void_Init(void);
void M_Timer0_Void_SetTime(u32);
void M_Timer0_Void_Start(void);
void M_Timer0_Void_Stop(void);
void M_TIMER0_Void_SetCallBack(void (*CopyPtr)(void));
*/
void M_Timer1_Void_PWM1Init(void);
void M_Timer1_Void_PWM1SetFrequancy(u32);
void M_Timer1_Void_PWM1SetDutyCycle(f32);
void M_Timer1_Void_PWM1Start(void);
void M_Timer1_Void_PWM1Stop(void);


#endif /* TIMER1_TIMER1_INIT_H_ */
