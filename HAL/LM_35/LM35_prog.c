/*
 * LM35_prog.c
 *
 *  Created on: Jul 21, 2022
 *      Author: P4P4
 */


#include "STD_TYPES.h"
#include "LM35_private.h"
#include "LM35_config.h"
#include "LM35_init.h"
#include "DIO_int.h"
#include "ADC_init.h"



void H_LM_void_Init(void)
{
	M_DIO_void_SetPinDirection(DIO_PORTA, SENSOR_CHANNEL, INPUT);
}
u8	H_LM_u8_Read(void)
{
	u16	ADC_Read	=	M_ADC_u16_GetValue(SENSOR_CHANNEL);

	u32 Read_mv	=	((u32)ADC_Read * LM35_VREF)/LM35_RESLUTION;

	u8 Temp =	Read_mv/10;

	return	Temp;
}
