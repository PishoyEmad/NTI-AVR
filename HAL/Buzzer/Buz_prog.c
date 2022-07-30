/*
 * Buz_prog.c
 *
 *  Created on: Jul 7, 2022
 *      Author: P4P4
 */



#include "../../LIB/STD_TYPES.h"
#include "DIO_int.h"
#include <avr/delay.h>
#include "Buz_privet.h"
#include "Buz_config.h"
#include "Buz_init.h"


void H_Buzzer_void_Init(void)
{
	M_DIO_void_SetPinDirection(BUZZER_PORT, BUZZER_PIN, OUTPUT);
}

void H_Buzzer_void_SetOn(void)
{
	M_DIO_void_SetPinValue(BUZZER_PORT, BUZZER_PIN,HIGH);
}
void H_Buzzer_void_SetOff(void)
{
	M_DIO_void_SetPinValue(BUZZER_PORT, BUZZER_PIN, LOW);
}
void H_Buzzer_void_Buzz(u8 Copy_Num)
{
	u8 Local_u8Counter;
	for(Local_u8Counter=1;Local_u8Counter<=Copy_Num;Local_u8Counter++)
	{
	H_Buzzer_void_SetOn();
	_delay_ms(BUZZER_DELAY);
	H_Buzzer_void_SetOff();
	_delay_ms(BUZZER_DELAY);
	}
}
