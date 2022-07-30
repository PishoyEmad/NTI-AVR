/*
 * PB_prog.c
 *
 *  Created on: Jul 7, 2022
 *      Author: P4P4
 */

#include "../../LIB/STD_TYPES.h"
#include "DIO_int.h"
#include "PB_privet.h"
#include "PB_config.h"
#include "PB_init.h"
#include <avr/delay.h>


void H_PB_void_Init(PB_t Copy_PB)
{

	M_DIO_void_SetPinDirection(Copy_PB.PB_Port, Copy_PB.PB_Pin, INPUT);

}


u8	 H_PB_u8_PBRead(PB_t Copy_PB)
{
	u8 Local_u8Reading;
	if(Copy_PB.PB_ActiveMode==ACTIVE_LOW)
	{
		Local_u8Reading=ACTIVE_LOW_RELESED;
		M_DIO_void_GetPiValue(Copy_PB.PB_Port, Copy_PB.PB_Pin, &Local_u8Reading);
		if(Local_u8Reading==ACTIVE_LOW_PRESED)
		{
			_delay_ms(40);
			M_DIO_void_GetPiValue(Copy_PB.PB_Port, Copy_PB.PB_Pin, &Local_u8Reading);
			if(Local_u8Reading==ACTIVE_LOW_PRESED)
			{
				while(Local_u8Reading==ACTIVE_LOW_PRESED)
				{
					M_DIO_void_GetPiValue(Copy_PB.PB_Port, Copy_PB.PB_Pin, &Local_u8Reading);
				}
				Local_u8Reading=ACTIVE_LOW_PRESED;
			}

		}
	}
	else if(Copy_PB.PB_ActiveMode==ACTIVE_HIGH)
		{
			Local_u8Reading=ACTIVE_HIGH_RELESED;
			M_DIO_void_GetPiValue(Copy_PB.PB_Port, Copy_PB.PB_Pin, &Local_u8Reading);
			if(Local_u8Reading==ACTIVE_HIGH_PRESED)
			{
				_delay_ms(40);
				M_DIO_void_GetPiValue(Copy_PB.PB_Port, Copy_PB.PB_Pin, &Local_u8Reading);
				if(Local_u8Reading==ACTIVE_HIGH_PRESED)
				{
					while(Local_u8Reading==ACTIVE_HIGH_PRESED)
					{
						M_DIO_void_GetPiValue(Copy_PB.PB_Port, Copy_PB.PB_Pin, &Local_u8Reading);
					}
					Local_u8Reading=ACTIVE_HIGH_PRESED;
				}

			}
		}

	return Local_u8Reading;
}

