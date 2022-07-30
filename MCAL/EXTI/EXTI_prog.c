/*
 * EXTI_prog.c
 *
 *  Created on: Jul 19, 2022
 *      Author: P4P4
 */

#ifndef EXTI_EXTI_PROG_C_
#define EXTI_EXTI_PROG_C_

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "EXTI_private.h"
#include "EXTI_config.h"
#include "EXTI_init.h"
#include <avr/interrupt.h>


static void (*ptr_ArrCallBack[]) (void) = { NULL,NULL,NULL };


void M_EXTI_void_Enable(u8 Copy_u8IntID,u8 Copy_u8Trigger)
{
	// Enable PIE
	SET_BIT(EXTI_GICR,Copy_u8IntID);

	//Config Trigger
	switch(Copy_u8IntID)
	{
	case INT0_ID:
		EXTI_MCUCR &= EXTI_INT0_TRIGGER_MASK;
		EXTI_MCUCR |= Copy_u8Trigger;
		break;
	case INT1_ID:
		EXTI_MCUCR &= EXTI_INT1_TRIGGER_MASK;
		EXTI_MCUCR |= Copy_u8Trigger<<2;
		break;
	case INT2_ID:
		CLR_BIT(EXTI_MCUCSR,ISC2);
		EXTI_MCUCSR |= (Copy_u8Trigger&1)<<ISC2;
		break;
	default:
		break;
	}
}
void M_EXTI_void_Disable(u8 Copy_u8IntID)
{
	CLR_BIT(EXTI_GICR,Copy_u8IntID);
}


void	M_EXTI_void_SetCallBack(void (*Copy_ptrFunction)(void),u8 Copy_u8IntID)
{
	switch(Copy_u8IntID)
	{
	case INT0_ID:
		ptr_ArrCallBack[0]=Copy_ptrFunction;
		break;
	case INT1_ID:
		ptr_ArrCallBack[1]=Copy_ptrFunction;
		break;
	case INT2_ID:
		ptr_ArrCallBack[2]=Copy_ptrFunction;
		break;
	default:
		break;
	}
	//ptr_ArrCallBack[Copy_u8IntID-6]=Copy_ptrFunction;
}

ISR(INT0_vect)
{
	ptr_ArrCallBack[0]();
}
ISR(INT1_vect)
{
	ptr_ArrCallBack[1]();
}
ISR(INT2_vect)
{
	ptr_ArrCallBack[2]();
}


#endif /* EXTI_EXTI_PROG_C_ */
