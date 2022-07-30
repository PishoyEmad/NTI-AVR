/*
 * KeyPad_prog.c
 *
 *  Created on: Jul 17, 2022
 *      Author: P4P4
 */


#include "STD_TYPES.h"
#include "DIO_int.h"
#include "KeyPad_private.h"
#include "KeyPad_config.h"
#include "KeyPad_init.h"
#include <avr/delay.h>

void H_KeyPad_void_init(void)
{
	//Config Col as inputs
	M_DIO_void_SetPinDirection(COL_PORT, KEYPAD_C0_PIN, INPUT);
	M_DIO_void_SetPinDirection(COL_PORT, KEYPAD_C1_PIN, INPUT);
	M_DIO_void_SetPinDirection(COL_PORT, KEYPAD_C2_PIN, INPUT);
	M_DIO_void_SetPinDirection(COL_PORT, KEYPAD_C3_PIN, INPUT);

	//M_DIO_void_SetPinDirection(DIO_PORTC, DIO_PIN0, OUTPUT);

	//config row as outputs
	M_DIO_void_SetPinDirection(ROW_PORT, KEYPAD_R0_PIN, OUTPUT);
	M_DIO_void_SetPinDirection(ROW_PORT, KEYPAD_R1_PIN, OUTPUT);
	M_DIO_void_SetPinDirection(ROW_PORT, KEYPAD_R2_PIN, OUTPUT);
	M_DIO_void_SetPinDirection(ROW_PORT, KEYPAD_R3_PIN, OUTPUT);

	//config init values of rows high
	M_DIO_void_SetPinValue(ROW_PORT, KEYPAD_R0_PIN,HIGH);
	M_DIO_void_SetPinValue(ROW_PORT, KEYPAD_R1_PIN,HIGH);
	M_DIO_void_SetPinValue(ROW_PORT, KEYPAD_R2_PIN,HIGH);
	M_DIO_void_SetPinValue(ROW_PORT, KEYPAD_R3_PIN,HIGH);

#if MODE == SIM
	M_DIO_void_SetPinValue(COL_PORT, KEYPAD_C0_PIN, HIGH);
	M_DIO_void_SetPinValue(COL_PORT, KEYPAD_C1_PIN, HIGH);
	M_DIO_void_SetPinValue(COL_PORT, KEYPAD_C2_PIN, HIGH);
	M_DIO_void_SetPinValue(COL_PORT, KEYPAD_C3_PIN, HIGH);
#endif
}


u8 H_KeyPad_u8_GetPressedKey(void)
{
	u8	Loc_u8ReturnValue = NO_PRESSED_KEY;
	u8	Loc_u8Row_index;
	u8	Loc_u8Col_index;
	u8	Loc_u8PBState=0;
	u8	Loc_u8KeyArr[KEYPAD_ROWS][KEYPAD_COLS]=KEYPAD_ARR;

	for(Loc_u8Row_index=KEYPAD_R0_PIN ;Loc_u8Row_index<=KEYPAD_R3_PIN; Loc_u8Row_index++)
	{
		M_DIO_void_SetPinValue(ROW_PORT,Loc_u8Row_index,LOW);
		for(Loc_u8Col_index=KEYPAD_C0_PIN;Loc_u8Col_index<=KEYPAD_C3_PIN;Loc_u8Col_index++)
		{

			M_DIO_void_GetPiValue(COL_PORT, Loc_u8Col_index,&Loc_u8PBState);
			if(Loc_u8PBState==PRESSED)
			{
				_delay_ms(200);
				M_DIO_void_GetPiValue(COL_PORT, Loc_u8Col_index,&Loc_u8PBState);
				if(Loc_u8PBState==PRESSED)
				{
					while(Loc_u8PBState==PRESSED)
					{
						M_DIO_void_GetPiValue(COL_PORT, Loc_u8Col_index,&Loc_u8PBState);
					}
					Loc_u8ReturnValue=Loc_u8KeyArr[Loc_u8Row_index-KEYPAD_R0_PIN][Loc_u8Col_index-KEYPAD_C0_PIN];
				}
			}
		}
		M_DIO_void_SetPinValue(ROW_PORT,Loc_u8Row_index,HIGH);
	}

	return Loc_u8ReturnValue;
}

