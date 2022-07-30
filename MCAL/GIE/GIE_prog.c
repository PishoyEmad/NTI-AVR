/*
 * GIE_prog.c
 *
 *  Created on: Jul 19, 2022
 *      Author: P4P4
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GIE_privet.h"
#include "GIE_config.h"
#include "GIE_init.h"

void M_GIE_void_Enable(void)
{
	//SET_BIT(GIE_SREG,I_BIT);
	asm("SEI");
}

void M_GIE_void_Disable(void)
{
	//CLR_BIT(GIE_SREG,I_BIT);
	asm("CLI");
}

