/*
 * 7_prog.c
 *
 *  Created on: Jul 6, 2022
 *      Author: P4P4
 */



#include "../../LIB/STD_TYPES.h"
#include "DIO_int.h"
#include <avr/delay.h>
#include "7_privet.h"
#include "7_config.h"
#include "7_init.h"
#include <math.h>

void H_SSD_void_Init(void)
{
	M_DIO_void_SetPinDirection(SSD_A_PORT, SSD_A_PIN, OUTPUT);
	M_DIO_void_SetPinDirection(SSD_B_PORT, SSD_B_PIN, OUTPUT);
	M_DIO_void_SetPinDirection(SSD_C_PORT, SSD_C_PIN, OUTPUT);
	M_DIO_void_SetPinDirection(SSD_D_PORT, SSD_D_PIN, OUTPUT);
	M_DIO_void_SetPinDirection(SSD_E_PORT, SSD_E_PIN, OUTPUT);
	M_DIO_void_SetPinDirection(SSD_F_PORT, SSD_F_PIN, OUTPUT);
	M_DIO_void_SetPinDirection(SSD_G_PORT, SSD_G_PIN, OUTPUT);
	M_DIO_void_SetPinDirection(SSD_DOT_PORT, SSD_DOT_PIN, OUTPUT);

	M_DIO_void_SetPinDirection(EN1_PORT, EN1_PIN, OUTPUT);
	M_DIO_void_SetPinDirection(EN2_PORT, EN2_PIN, OUTPUT);

}


void H_SSD_void_DisplayNumber(u8 Copy_u8Nuber)
{
	u8 Local_u8Unit,Local_u8Tens;
	u16 i;
	Local_u8Unit=Copy_u8Nuber%10;
	Local_u8Tens=Copy_u8Nuber/10;
for(i=0;i<40;i++)
{

	switch(Local_u8Unit)
	{
	case 0:
		M_DIO_void_SetPinValue(SSD_A_PORT, SSD_A_PIN, HIGH);
		M_DIO_void_SetPinValue(SSD_B_PORT, SSD_B_PIN, HIGH);
		M_DIO_void_SetPinValue(SSD_C_PORT, SSD_C_PIN, HIGH);
		M_DIO_void_SetPinValue(SSD_D_PORT, SSD_D_PIN, HIGH);
		M_DIO_void_SetPinValue(SSD_E_PORT, SSD_E_PIN, HIGH);
		M_DIO_void_SetPinValue(SSD_F_PORT, SSD_F_PIN, HIGH);
		M_DIO_void_SetPinValue(SSD_G_PORT, SSD_G_PIN, LOW);
		break;

	case 1:
		M_DIO_void_SetPinValue(SSD_A_PORT, SSD_A_PIN, LOW);
		M_DIO_void_SetPinValue(SSD_B_PORT, SSD_B_PIN, HIGH);
		M_DIO_void_SetPinValue(SSD_C_PORT, SSD_C_PIN, HIGH);
		M_DIO_void_SetPinValue(SSD_D_PORT, SSD_D_PIN, LOW);
		M_DIO_void_SetPinValue(SSD_E_PORT, SSD_E_PIN, LOW);
		M_DIO_void_SetPinValue(SSD_F_PORT, SSD_F_PIN, LOW);
		M_DIO_void_SetPinValue(SSD_G_PORT, SSD_G_PIN, LOW);
		break;

	case 2:
		M_DIO_void_SetPinValue(SSD_A_PORT, SSD_A_PIN, HIGH);
		M_DIO_void_SetPinValue(SSD_B_PORT, SSD_B_PIN, HIGH);
		M_DIO_void_SetPinValue(SSD_C_PORT, SSD_C_PIN, LOW);
		M_DIO_void_SetPinValue(SSD_D_PORT, SSD_D_PIN, HIGH);
		M_DIO_void_SetPinValue(SSD_E_PORT, SSD_E_PIN, HIGH);
		M_DIO_void_SetPinValue(SSD_F_PORT, SSD_F_PIN, LOW);
		M_DIO_void_SetPinValue(SSD_G_PORT, SSD_G_PIN, HIGH);
		break;

	case 3:
		M_DIO_void_SetPinValue(SSD_A_PORT, SSD_A_PIN, HIGH);
		M_DIO_void_SetPinValue(SSD_B_PORT, SSD_B_PIN, HIGH);
		M_DIO_void_SetPinValue(SSD_C_PORT, SSD_C_PIN, HIGH);
		M_DIO_void_SetPinValue(SSD_D_PORT, SSD_D_PIN, HIGH);
		M_DIO_void_SetPinValue(SSD_E_PORT, SSD_E_PIN, LOW);
		M_DIO_void_SetPinValue(SSD_F_PORT, SSD_F_PIN, LOW);
		M_DIO_void_SetPinValue(SSD_G_PORT, SSD_G_PIN, HIGH);
		break;

	case 4:
		M_DIO_void_SetPinValue(SSD_A_PORT, SSD_A_PIN, LOW);
		M_DIO_void_SetPinValue(SSD_B_PORT, SSD_B_PIN, HIGH);
		M_DIO_void_SetPinValue(SSD_C_PORT, SSD_C_PIN, HIGH);
		M_DIO_void_SetPinValue(SSD_D_PORT, SSD_D_PIN, LOW);
		M_DIO_void_SetPinValue(SSD_E_PORT, SSD_E_PIN, LOW);
		M_DIO_void_SetPinValue(SSD_F_PORT, SSD_F_PIN, HIGH);
		M_DIO_void_SetPinValue(SSD_G_PORT, SSD_G_PIN, HIGH);
		break;

	case 5:
		M_DIO_void_SetPinValue(SSD_A_PORT, SSD_A_PIN, HIGH);
		M_DIO_void_SetPinValue(SSD_B_PORT, SSD_B_PIN, LOW);
		M_DIO_void_SetPinValue(SSD_C_PORT, SSD_C_PIN, HIGH);
		M_DIO_void_SetPinValue(SSD_D_PORT, SSD_D_PIN, HIGH);
		M_DIO_void_SetPinValue(SSD_E_PORT, SSD_E_PIN, LOW);
		M_DIO_void_SetPinValue(SSD_F_PORT, SSD_F_PIN, HIGH);
		M_DIO_void_SetPinValue(SSD_G_PORT, SSD_G_PIN, HIGH);
		break;

	case 6:
		M_DIO_void_SetPinValue(SSD_A_PORT, SSD_A_PIN, HIGH);
		M_DIO_void_SetPinValue(SSD_B_PORT, SSD_B_PIN, LOW);
		M_DIO_void_SetPinValue(SSD_C_PORT, SSD_C_PIN, HIGH);
		M_DIO_void_SetPinValue(SSD_D_PORT, SSD_D_PIN, HIGH);
		M_DIO_void_SetPinValue(SSD_E_PORT, SSD_E_PIN, HIGH);
		M_DIO_void_SetPinValue(SSD_F_PORT, SSD_F_PIN, HIGH);
		M_DIO_void_SetPinValue(SSD_G_PORT, SSD_G_PIN, HIGH);
		break;

	case 7:
		M_DIO_void_SetPinValue(SSD_A_PORT, SSD_A_PIN, HIGH);
		M_DIO_void_SetPinValue(SSD_B_PORT, SSD_B_PIN, HIGH);
		M_DIO_void_SetPinValue(SSD_C_PORT, SSD_C_PIN, HIGH);
		M_DIO_void_SetPinValue(SSD_D_PORT, SSD_D_PIN, LOW);
		M_DIO_void_SetPinValue(SSD_E_PORT, SSD_E_PIN, LOW);
		M_DIO_void_SetPinValue(SSD_F_PORT, SSD_F_PIN, LOW);
		M_DIO_void_SetPinValue(SSD_G_PORT, SSD_G_PIN, LOW);
		break;

	case 8:
		M_DIO_void_SetPinValue(SSD_A_PORT, SSD_A_PIN, HIGH);
		M_DIO_void_SetPinValue(SSD_B_PORT, SSD_B_PIN, HIGH);
		M_DIO_void_SetPinValue(SSD_C_PORT, SSD_C_PIN, HIGH);
		M_DIO_void_SetPinValue(SSD_D_PORT, SSD_D_PIN, HIGH);
		M_DIO_void_SetPinValue(SSD_E_PORT, SSD_E_PIN, HIGH);
		M_DIO_void_SetPinValue(SSD_F_PORT, SSD_F_PIN, HIGH);
		M_DIO_void_SetPinValue(SSD_G_PORT, SSD_G_PIN, HIGH);
		break;

	case 9:
		M_DIO_void_SetPinValue(SSD_A_PORT, SSD_A_PIN, HIGH);
		M_DIO_void_SetPinValue(SSD_B_PORT, SSD_B_PIN, HIGH);
		M_DIO_void_SetPinValue(SSD_C_PORT, SSD_C_PIN, HIGH);
		M_DIO_void_SetPinValue(SSD_D_PORT, SSD_D_PIN, HIGH);
		M_DIO_void_SetPinValue(SSD_E_PORT, SSD_E_PIN, LOW);
		M_DIO_void_SetPinValue(SSD_F_PORT, SSD_F_PIN, HIGH);
		M_DIO_void_SetPinValue(SSD_G_PORT, SSD_G_PIN, HIGH);
		break;
	}
	M_DIO_void_SetPinValue(EN1_PORT, EN1_PIN, HIGH);

	_delay_ms(1);

	M_DIO_void_SetPinValue(EN1_PORT, EN1_PIN, LOW);

	switch(Local_u8Tens)
	{
	case 0:
		M_DIO_void_SetPinValue(SSD_A_PORT, SSD_A_PIN, HIGH);
		M_DIO_void_SetPinValue(SSD_B_PORT, SSD_B_PIN, HIGH);
		M_DIO_void_SetPinValue(SSD_C_PORT, SSD_C_PIN, HIGH);
		M_DIO_void_SetPinValue(SSD_D_PORT, SSD_D_PIN, HIGH);
		M_DIO_void_SetPinValue(SSD_E_PORT, SSD_E_PIN, HIGH);
		M_DIO_void_SetPinValue(SSD_F_PORT, SSD_F_PIN, HIGH);
		M_DIO_void_SetPinValue(SSD_G_PORT, SSD_G_PIN, LOW);
		break;

	case 1:
		M_DIO_void_SetPinValue(SSD_A_PORT, SSD_A_PIN, LOW);
		M_DIO_void_SetPinValue(SSD_B_PORT, SSD_B_PIN, HIGH);
		M_DIO_void_SetPinValue(SSD_C_PORT, SSD_C_PIN, HIGH);
		M_DIO_void_SetPinValue(SSD_D_PORT, SSD_D_PIN, LOW);
		M_DIO_void_SetPinValue(SSD_E_PORT, SSD_E_PIN, LOW);
		M_DIO_void_SetPinValue(SSD_F_PORT, SSD_F_PIN, LOW);
		M_DIO_void_SetPinValue(SSD_G_PORT, SSD_G_PIN, LOW);
		break;

	case 2:
		M_DIO_void_SetPinValue(SSD_A_PORT, SSD_A_PIN, HIGH);
		M_DIO_void_SetPinValue(SSD_B_PORT, SSD_B_PIN, HIGH);
		M_DIO_void_SetPinValue(SSD_C_PORT, SSD_C_PIN, LOW);
		M_DIO_void_SetPinValue(SSD_D_PORT, SSD_D_PIN, HIGH);
		M_DIO_void_SetPinValue(SSD_E_PORT, SSD_E_PIN, HIGH);
		M_DIO_void_SetPinValue(SSD_F_PORT, SSD_F_PIN, LOW);
		M_DIO_void_SetPinValue(SSD_G_PORT, SSD_G_PIN, HIGH);
		break;

	case 3:
		M_DIO_void_SetPinValue(SSD_A_PORT, SSD_A_PIN, HIGH);
		M_DIO_void_SetPinValue(SSD_B_PORT, SSD_B_PIN, HIGH);
		M_DIO_void_SetPinValue(SSD_C_PORT, SSD_C_PIN, HIGH);
		M_DIO_void_SetPinValue(SSD_D_PORT, SSD_D_PIN, HIGH);
		M_DIO_void_SetPinValue(SSD_E_PORT, SSD_E_PIN, LOW);
		M_DIO_void_SetPinValue(SSD_F_PORT, SSD_F_PIN, LOW);
		M_DIO_void_SetPinValue(SSD_G_PORT, SSD_G_PIN, HIGH);
		break;

	case 4:
		M_DIO_void_SetPinValue(SSD_A_PORT, SSD_A_PIN, LOW);
		M_DIO_void_SetPinValue(SSD_B_PORT, SSD_B_PIN, HIGH);
		M_DIO_void_SetPinValue(SSD_C_PORT, SSD_C_PIN, HIGH);
		M_DIO_void_SetPinValue(SSD_D_PORT, SSD_D_PIN, LOW);
		M_DIO_void_SetPinValue(SSD_E_PORT, SSD_E_PIN, LOW);
		M_DIO_void_SetPinValue(SSD_F_PORT, SSD_F_PIN, HIGH);
		M_DIO_void_SetPinValue(SSD_G_PORT, SSD_G_PIN, HIGH);
		break;

	case 5:
		M_DIO_void_SetPinValue(SSD_A_PORT, SSD_A_PIN, HIGH);
		M_DIO_void_SetPinValue(SSD_B_PORT, SSD_B_PIN, LOW);
		M_DIO_void_SetPinValue(SSD_C_PORT, SSD_C_PIN, HIGH);
		M_DIO_void_SetPinValue(SSD_D_PORT, SSD_D_PIN, HIGH);
		M_DIO_void_SetPinValue(SSD_E_PORT, SSD_E_PIN, LOW);
		M_DIO_void_SetPinValue(SSD_F_PORT, SSD_F_PIN, HIGH);
		M_DIO_void_SetPinValue(SSD_G_PORT, SSD_G_PIN, HIGH);
		break;

	case 6:
		M_DIO_void_SetPinValue(SSD_A_PORT, SSD_A_PIN, HIGH);
		M_DIO_void_SetPinValue(SSD_B_PORT, SSD_B_PIN, LOW);
		M_DIO_void_SetPinValue(SSD_C_PORT, SSD_C_PIN, HIGH);
		M_DIO_void_SetPinValue(SSD_D_PORT, SSD_D_PIN, HIGH);
		M_DIO_void_SetPinValue(SSD_E_PORT, SSD_E_PIN, HIGH);
		M_DIO_void_SetPinValue(SSD_F_PORT, SSD_F_PIN, HIGH);
		M_DIO_void_SetPinValue(SSD_G_PORT, SSD_G_PIN, HIGH);
		break;

	case 7:
		M_DIO_void_SetPinValue(SSD_A_PORT, SSD_A_PIN, HIGH);
		M_DIO_void_SetPinValue(SSD_B_PORT, SSD_B_PIN, HIGH);
		M_DIO_void_SetPinValue(SSD_C_PORT, SSD_C_PIN, HIGH);
		M_DIO_void_SetPinValue(SSD_D_PORT, SSD_D_PIN, LOW);
		M_DIO_void_SetPinValue(SSD_E_PORT, SSD_E_PIN, LOW);
		M_DIO_void_SetPinValue(SSD_F_PORT, SSD_F_PIN, LOW);
		M_DIO_void_SetPinValue(SSD_G_PORT, SSD_G_PIN, LOW);
		break;

	case 8:
		M_DIO_void_SetPinValue(SSD_A_PORT, SSD_A_PIN, HIGH);
		M_DIO_void_SetPinValue(SSD_B_PORT, SSD_B_PIN, HIGH);
		M_DIO_void_SetPinValue(SSD_C_PORT, SSD_C_PIN, HIGH);
		M_DIO_void_SetPinValue(SSD_D_PORT, SSD_D_PIN, HIGH);
		M_DIO_void_SetPinValue(SSD_E_PORT, SSD_E_PIN, HIGH);
		M_DIO_void_SetPinValue(SSD_F_PORT, SSD_F_PIN, HIGH);
		M_DIO_void_SetPinValue(SSD_G_PORT, SSD_G_PIN, HIGH);
		break;

	case 9:
		M_DIO_void_SetPinValue(SSD_A_PORT, SSD_A_PIN, HIGH);
		M_DIO_void_SetPinValue(SSD_B_PORT, SSD_B_PIN, HIGH);
		M_DIO_void_SetPinValue(SSD_C_PORT, SSD_C_PIN, HIGH);
		M_DIO_void_SetPinValue(SSD_D_PORT, SSD_D_PIN, HIGH);
		M_DIO_void_SetPinValue(SSD_E_PORT, SSD_E_PIN, LOW);
		M_DIO_void_SetPinValue(SSD_F_PORT, SSD_F_PIN, HIGH);
		M_DIO_void_SetPinValue(SSD_G_PORT, SSD_G_PIN, HIGH);
		break;

	}
	M_DIO_void_SetPinValue(EN2_PORT, EN2_PIN,HIGH);
	_delay_ms(1);
	M_DIO_void_SetPinValue(EN2_PORT, EN2_PIN,LOW);

}
}




void H_SSD_void_DisplayFloatNumber(f32 Copy_f32Number)
{
	u8 Local_u8IntNumber =(u8)Copy_f32Number;
	//u8 Local_u8FloatNumber=((u8)(Copy_f32Number*10)%10);
	u8 Local_u8FloatNumber=fmod(Copy_f32Number*10,10);
	u8 i;

	for(i=0;i<40;i++)
	{

		switch(Local_u8FloatNumber)
		{
		case 0:
			M_DIO_void_SetPinValue(SSD_A_PORT, SSD_A_PIN, HIGH);
			M_DIO_void_SetPinValue(SSD_B_PORT, SSD_B_PIN, HIGH);
			M_DIO_void_SetPinValue(SSD_C_PORT, SSD_C_PIN, HIGH);
			M_DIO_void_SetPinValue(SSD_D_PORT, SSD_D_PIN, HIGH);
			M_DIO_void_SetPinValue(SSD_E_PORT, SSD_E_PIN, HIGH);
			M_DIO_void_SetPinValue(SSD_F_PORT, SSD_F_PIN, HIGH);
			M_DIO_void_SetPinValue(SSD_G_PORT, SSD_G_PIN, LOW);
			break;

		case 1:
			M_DIO_void_SetPinValue(SSD_A_PORT, SSD_A_PIN, LOW);
			M_DIO_void_SetPinValue(SSD_B_PORT, SSD_B_PIN, HIGH);
			M_DIO_void_SetPinValue(SSD_C_PORT, SSD_C_PIN, HIGH);
			M_DIO_void_SetPinValue(SSD_D_PORT, SSD_D_PIN, LOW);
			M_DIO_void_SetPinValue(SSD_E_PORT, SSD_E_PIN, LOW);
			M_DIO_void_SetPinValue(SSD_F_PORT, SSD_F_PIN, LOW);
			M_DIO_void_SetPinValue(SSD_G_PORT, SSD_G_PIN, LOW);
			break;

		case 2:
			M_DIO_void_SetPinValue(SSD_A_PORT, SSD_A_PIN, HIGH);
			M_DIO_void_SetPinValue(SSD_B_PORT, SSD_B_PIN, HIGH);
			M_DIO_void_SetPinValue(SSD_C_PORT, SSD_C_PIN, LOW);
			M_DIO_void_SetPinValue(SSD_D_PORT, SSD_D_PIN, HIGH);
			M_DIO_void_SetPinValue(SSD_E_PORT, SSD_E_PIN, HIGH);
			M_DIO_void_SetPinValue(SSD_F_PORT, SSD_F_PIN, LOW);
			M_DIO_void_SetPinValue(SSD_G_PORT, SSD_G_PIN, HIGH);
			break;

		case 3:
			M_DIO_void_SetPinValue(SSD_A_PORT, SSD_A_PIN, HIGH);
			M_DIO_void_SetPinValue(SSD_B_PORT, SSD_B_PIN, HIGH);
			M_DIO_void_SetPinValue(SSD_C_PORT, SSD_C_PIN, HIGH);
			M_DIO_void_SetPinValue(SSD_D_PORT, SSD_D_PIN, HIGH);
			M_DIO_void_SetPinValue(SSD_E_PORT, SSD_E_PIN, LOW);
			M_DIO_void_SetPinValue(SSD_F_PORT, SSD_F_PIN, LOW);
			M_DIO_void_SetPinValue(SSD_G_PORT, SSD_G_PIN, HIGH);
			break;

		case 4:
			M_DIO_void_SetPinValue(SSD_A_PORT, SSD_A_PIN, LOW);
			M_DIO_void_SetPinValue(SSD_B_PORT, SSD_B_PIN, HIGH);
			M_DIO_void_SetPinValue(SSD_C_PORT, SSD_C_PIN, HIGH);
			M_DIO_void_SetPinValue(SSD_D_PORT, SSD_D_PIN, LOW);
			M_DIO_void_SetPinValue(SSD_E_PORT, SSD_E_PIN, LOW);
			M_DIO_void_SetPinValue(SSD_F_PORT, SSD_F_PIN, HIGH);
			M_DIO_void_SetPinValue(SSD_G_PORT, SSD_G_PIN, HIGH);
			break;

		case 5:
			M_DIO_void_SetPinValue(SSD_A_PORT, SSD_A_PIN, HIGH);
			M_DIO_void_SetPinValue(SSD_B_PORT, SSD_B_PIN, LOW);
			M_DIO_void_SetPinValue(SSD_C_PORT, SSD_C_PIN, HIGH);
			M_DIO_void_SetPinValue(SSD_D_PORT, SSD_D_PIN, HIGH);
			M_DIO_void_SetPinValue(SSD_E_PORT, SSD_E_PIN, LOW);
			M_DIO_void_SetPinValue(SSD_F_PORT, SSD_F_PIN, HIGH);
			M_DIO_void_SetPinValue(SSD_G_PORT, SSD_G_PIN, HIGH);
			break;

		case 6:
			M_DIO_void_SetPinValue(SSD_A_PORT, SSD_A_PIN, HIGH);
			M_DIO_void_SetPinValue(SSD_B_PORT, SSD_B_PIN, LOW);
			M_DIO_void_SetPinValue(SSD_C_PORT, SSD_C_PIN, HIGH);
			M_DIO_void_SetPinValue(SSD_D_PORT, SSD_D_PIN, HIGH);
			M_DIO_void_SetPinValue(SSD_E_PORT, SSD_E_PIN, HIGH);
			M_DIO_void_SetPinValue(SSD_F_PORT, SSD_F_PIN, HIGH);
			M_DIO_void_SetPinValue(SSD_G_PORT, SSD_G_PIN, HIGH);
			break;

		case 7:
			M_DIO_void_SetPinValue(SSD_A_PORT, SSD_A_PIN, HIGH);
			M_DIO_void_SetPinValue(SSD_B_PORT, SSD_B_PIN, HIGH);
			M_DIO_void_SetPinValue(SSD_C_PORT, SSD_C_PIN, HIGH);
			M_DIO_void_SetPinValue(SSD_D_PORT, SSD_D_PIN, LOW);
			M_DIO_void_SetPinValue(SSD_E_PORT, SSD_E_PIN, LOW);
			M_DIO_void_SetPinValue(SSD_F_PORT, SSD_F_PIN, LOW);
			M_DIO_void_SetPinValue(SSD_G_PORT, SSD_G_PIN, LOW);
			break;

		case 8:
			M_DIO_void_SetPinValue(SSD_A_PORT, SSD_A_PIN, HIGH);
			M_DIO_void_SetPinValue(SSD_B_PORT, SSD_B_PIN, HIGH);
			M_DIO_void_SetPinValue(SSD_C_PORT, SSD_C_PIN, HIGH);
			M_DIO_void_SetPinValue(SSD_D_PORT, SSD_D_PIN, HIGH);
			M_DIO_void_SetPinValue(SSD_E_PORT, SSD_E_PIN, HIGH);
			M_DIO_void_SetPinValue(SSD_F_PORT, SSD_F_PIN, HIGH);
			M_DIO_void_SetPinValue(SSD_G_PORT, SSD_G_PIN, HIGH);
			break;

		case 9:
			M_DIO_void_SetPinValue(SSD_A_PORT, SSD_A_PIN, HIGH);
			M_DIO_void_SetPinValue(SSD_B_PORT, SSD_B_PIN, HIGH);
			M_DIO_void_SetPinValue(SSD_C_PORT, SSD_C_PIN, HIGH);
			M_DIO_void_SetPinValue(SSD_D_PORT, SSD_D_PIN, HIGH);
			M_DIO_void_SetPinValue(SSD_E_PORT, SSD_E_PIN, LOW);
			M_DIO_void_SetPinValue(SSD_F_PORT, SSD_F_PIN, HIGH);
			M_DIO_void_SetPinValue(SSD_G_PORT, SSD_G_PIN, HIGH);
			break;
		}
		M_DIO_void_SetPinValue(EN1_PORT, EN1_PIN, HIGH);

		_delay_ms(1);

		M_DIO_void_SetPinValue(EN1_PORT, EN1_PIN, LOW);
		M_DIO_void_SetPinValue(SSD_DOT_PORT, SSD_DOT_PIN, HIGH);
		switch(Local_u8IntNumber)
		{
		case 0:
			M_DIO_void_SetPinValue(SSD_A_PORT, SSD_A_PIN, HIGH);
			M_DIO_void_SetPinValue(SSD_B_PORT, SSD_B_PIN, HIGH);
			M_DIO_void_SetPinValue(SSD_C_PORT, SSD_C_PIN, HIGH);
			M_DIO_void_SetPinValue(SSD_D_PORT, SSD_D_PIN, HIGH);
			M_DIO_void_SetPinValue(SSD_E_PORT, SSD_E_PIN, HIGH);
			M_DIO_void_SetPinValue(SSD_F_PORT, SSD_F_PIN, HIGH);
			M_DIO_void_SetPinValue(SSD_G_PORT, SSD_G_PIN, LOW);
			break;

		case 1:
			M_DIO_void_SetPinValue(SSD_A_PORT, SSD_A_PIN, LOW);
			M_DIO_void_SetPinValue(SSD_B_PORT, SSD_B_PIN, HIGH);
			M_DIO_void_SetPinValue(SSD_C_PORT, SSD_C_PIN, HIGH);
			M_DIO_void_SetPinValue(SSD_D_PORT, SSD_D_PIN, LOW);
			M_DIO_void_SetPinValue(SSD_E_PORT, SSD_E_PIN, LOW);
			M_DIO_void_SetPinValue(SSD_F_PORT, SSD_F_PIN, LOW);
			M_DIO_void_SetPinValue(SSD_G_PORT, SSD_G_PIN, LOW);
			break;

		case 2:
			M_DIO_void_SetPinValue(SSD_A_PORT, SSD_A_PIN, HIGH);
			M_DIO_void_SetPinValue(SSD_B_PORT, SSD_B_PIN, HIGH);
			M_DIO_void_SetPinValue(SSD_C_PORT, SSD_C_PIN, LOW);
			M_DIO_void_SetPinValue(SSD_D_PORT, SSD_D_PIN, HIGH);
			M_DIO_void_SetPinValue(SSD_E_PORT, SSD_E_PIN, HIGH);
			M_DIO_void_SetPinValue(SSD_F_PORT, SSD_F_PIN, LOW);
			M_DIO_void_SetPinValue(SSD_G_PORT, SSD_G_PIN, HIGH);
			break;

		case 3:
			M_DIO_void_SetPinValue(SSD_A_PORT, SSD_A_PIN, HIGH);
			M_DIO_void_SetPinValue(SSD_B_PORT, SSD_B_PIN, HIGH);
			M_DIO_void_SetPinValue(SSD_C_PORT, SSD_C_PIN, HIGH);
			M_DIO_void_SetPinValue(SSD_D_PORT, SSD_D_PIN, HIGH);
			M_DIO_void_SetPinValue(SSD_E_PORT, SSD_E_PIN, LOW);
			M_DIO_void_SetPinValue(SSD_F_PORT, SSD_F_PIN, LOW);
			M_DIO_void_SetPinValue(SSD_G_PORT, SSD_G_PIN, HIGH);
			break;

		case 4:
			M_DIO_void_SetPinValue(SSD_A_PORT, SSD_A_PIN, LOW);
			M_DIO_void_SetPinValue(SSD_B_PORT, SSD_B_PIN, HIGH);
			M_DIO_void_SetPinValue(SSD_C_PORT, SSD_C_PIN, HIGH);
			M_DIO_void_SetPinValue(SSD_D_PORT, SSD_D_PIN, LOW);
			M_DIO_void_SetPinValue(SSD_E_PORT, SSD_E_PIN, LOW);
			M_DIO_void_SetPinValue(SSD_F_PORT, SSD_F_PIN, HIGH);
			M_DIO_void_SetPinValue(SSD_G_PORT, SSD_G_PIN, HIGH);
			break;

		case 5:
			M_DIO_void_SetPinValue(SSD_A_PORT, SSD_A_PIN, HIGH);
			M_DIO_void_SetPinValue(SSD_B_PORT, SSD_B_PIN, LOW);
			M_DIO_void_SetPinValue(SSD_C_PORT, SSD_C_PIN, HIGH);
			M_DIO_void_SetPinValue(SSD_D_PORT, SSD_D_PIN, HIGH);
			M_DIO_void_SetPinValue(SSD_E_PORT, SSD_E_PIN, LOW);
			M_DIO_void_SetPinValue(SSD_F_PORT, SSD_F_PIN, HIGH);
			M_DIO_void_SetPinValue(SSD_G_PORT, SSD_G_PIN, HIGH);
			break;

		case 6:
			M_DIO_void_SetPinValue(SSD_A_PORT, SSD_A_PIN, HIGH);
			M_DIO_void_SetPinValue(SSD_B_PORT, SSD_B_PIN, LOW);
			M_DIO_void_SetPinValue(SSD_C_PORT, SSD_C_PIN, HIGH);
			M_DIO_void_SetPinValue(SSD_D_PORT, SSD_D_PIN, HIGH);
			M_DIO_void_SetPinValue(SSD_E_PORT, SSD_E_PIN, HIGH);
			M_DIO_void_SetPinValue(SSD_F_PORT, SSD_F_PIN, HIGH);
			M_DIO_void_SetPinValue(SSD_G_PORT, SSD_G_PIN, HIGH);
			break;

		case 7:
			M_DIO_void_SetPinValue(SSD_A_PORT, SSD_A_PIN, HIGH);
			M_DIO_void_SetPinValue(SSD_B_PORT, SSD_B_PIN, HIGH);
			M_DIO_void_SetPinValue(SSD_C_PORT, SSD_C_PIN, HIGH);
			M_DIO_void_SetPinValue(SSD_D_PORT, SSD_D_PIN, LOW);
			M_DIO_void_SetPinValue(SSD_E_PORT, SSD_E_PIN, LOW);
			M_DIO_void_SetPinValue(SSD_F_PORT, SSD_F_PIN, LOW);
			M_DIO_void_SetPinValue(SSD_G_PORT, SSD_G_PIN, LOW);
			break;

		case 8:
			M_DIO_void_SetPinValue(SSD_A_PORT, SSD_A_PIN, HIGH);
			M_DIO_void_SetPinValue(SSD_B_PORT, SSD_B_PIN, HIGH);
			M_DIO_void_SetPinValue(SSD_C_PORT, SSD_C_PIN, HIGH);
			M_DIO_void_SetPinValue(SSD_D_PORT, SSD_D_PIN, HIGH);
			M_DIO_void_SetPinValue(SSD_E_PORT, SSD_E_PIN, HIGH);
			M_DIO_void_SetPinValue(SSD_F_PORT, SSD_F_PIN, HIGH);
			M_DIO_void_SetPinValue(SSD_G_PORT, SSD_G_PIN, HIGH);
			break;

		case 9:
			M_DIO_void_SetPinValue(SSD_A_PORT, SSD_A_PIN, HIGH);
			M_DIO_void_SetPinValue(SSD_B_PORT, SSD_B_PIN, HIGH);
			M_DIO_void_SetPinValue(SSD_C_PORT, SSD_C_PIN, HIGH);
			M_DIO_void_SetPinValue(SSD_D_PORT, SSD_D_PIN, HIGH);
			M_DIO_void_SetPinValue(SSD_E_PORT, SSD_E_PIN, LOW);
			M_DIO_void_SetPinValue(SSD_F_PORT, SSD_F_PIN, HIGH);
			M_DIO_void_SetPinValue(SSD_G_PORT, SSD_G_PIN, HIGH);
			break;

		}
		M_DIO_void_SetPinValue(EN2_PORT, EN2_PIN,HIGH);
		_delay_ms(1);
		M_DIO_void_SetPinValue(SSD_DOT_PORT, SSD_DOT_PIN, LOW);

		M_DIO_void_SetPinValue(EN2_PORT, EN2_PIN,LOW);

	}
}
