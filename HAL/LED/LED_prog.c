/*
 * LED_prog.c
 *
 *  Created on: Jul 6, 2022
 *      Author: P4P4
 */

#include "../../LIB/STD_TYPES.h"
#include "DIO_int.h"
#include "LED_privet.h"
#include "LED_config.h"
#include "LED_init.h"
void H_Led_void_LedInit(u8 Copy_u8LedID)
{
	switch (Copy_u8LedID)
	{
	case RED_LED:
		M_DIO_void_SetPinDirection(RED_LED_PORT,RED_LED_PIN,OUTPUT);
		break;

	case GRN_LED:
		M_DIO_void_SetPinDirection(GRN_LED_PORT,GRN_LED_PIN,OUTPUT);
		break;

	case BLU_LED:
		M_DIO_void_SetPinDirection(BLU_LED_PORT,BLU_LED_PIN,OUTPUT);
		break;

	default: break;
	}


}

void H_Led_void_LedSetOn(u8 Copy_u8LedID)
{
	switch (Copy_u8LedID)
	{
	case RED_LED:
#if(RED_LED_MODE==FORWARD)
		M_DIO_void_SetPinValue(RED_LED_PORT,RED_LED_PIN,HIGH);
#elif(RED_LED_MODE==REVERSE)
		M_DIO_void_SetPinValue(RED_LED_PORT,RED_LED_PIN,LOW);
#else
	#error("Wrong Led Mode")
#endif
		break;

	case GRN_LED:
#if(GRN_LED_MODE==FORWARD)
		M_DIO_void_SetPinValue(GRN_LED_PORT,GRN_LED_PIN,HIGH);
#elif(GRN_LED_MODE==REVERSE)
		M_DIO_void_SetPinValue(GRN_LED_PORT,GRN_LED_PIN,LOW);
#else
	#error("Wrong Led Mode")
#endif
		break;

	case BLU_LED:
#if(BLU_LED_MODE==FORWARD)
		M_DIO_void_SetPinValue(BLU_LED_PORT,BLU_LED_PIN,HIGH);
#elif(BLU_LED_MODE==REVERSE)
		M_DIO_void_SetPinValue(BLU_LED_PORT,BLU_LED_PIN,LOW);
#else
	#error("Wrong Led Mode")
#endif
		break;

	default: break;
	}

}
void H_Led_void_LedSetOff(u8 Copy_u8LedID)
{
	switch (Copy_u8LedID)
	{
	case RED_LED:
#if(RED_LED_MODE==FORWARD)
		M_DIO_void_SetPinValue(RED_LED_PORT,RED_LED_PIN,LOW);
#elif(RED_LED_MODE==REVERSE)
		M_DIO_void_SetPinValue(RED_LED_PORT,RED_LED_PIN,HIGH);
#else
	#error("Wrong Led Mode")
#endif
		break;

	case GRN_LED:
#if(GRN_LED_MODE==FORWARD)
		M_DIO_void_SetPinValue(GRN_LED_PORT,GRN_LED_PIN,LOW);
#elif(GRN_LED_MODE==REVERSE)
		M_DIO_void_SetPinValue(GRN_LED_PORT,GRN_LED_PIN,HIGH);
#else
	#error("Wrong Led Mode")
#endif
		break;

	case BLU_LED:
#if(BLU_LED_MODE==FORWARD)
		M_DIO_void_SetPinValue(BLU_LED_PORT,BLU_LED_PIN,LOW);
#elif(BLU_LED_MODE==REVERSE)
		M_DIO_void_SetPinValue(BLU_LED_PORT,BLU_LED_PIN,HIGH);
#else
	#error("Wrong Led Mode")
#endif
		break;

	default: break;
	}

}
void H_Led_void_LedToggle(u8 Copy_u8LedID)
{
	switch (Copy_u8LedID)
	{
	case RED_LED:
		M_DIO_void_TogglePinValue(RED_LED_PORT,RED_LED_PIN);
		break;

	case GRN_LED:
		M_DIO_void_TogglePinValue(GRN_LED_PORT,GRN_LED_PIN);
		break;

	case BLU_LED:
		M_DIO_void_TogglePinValue(BLU_LED_PORT,BLU_LED_PIN);
		break;

	default: break;
	}

}

