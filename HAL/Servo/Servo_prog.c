/*
 * Servo_prog.c
 *
 *  Created on: Jul 28, 2022
 *      Author: P4P4
 */


#include "Servo_init.h"




void H_Servo_void_Init(void)
{
	M_Timer1_Void_PWM1Init();
	M_Timer1_Void_PWM1SetFrequancy(50);
}

void H_Servo_void_SetAngle(u8 Copy_u8Angle)
{
	f32	Local_f32Value	= ((5* Copy_u8Angle)/(f32)180)+5;
	M_Timer1_Void_PWM1SetDutyCycle(Local_f32Value);
}

void H_Servo_void_Start(void)
{
	M_Timer1_Void_PWM1Start();
}

void H_Servo_void_Stop(void)
{
	M_Timer1_Void_PWM1Stop();
}

