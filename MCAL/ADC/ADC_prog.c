/*
 * ADC_prog.c
 *
 *  Created on: Jul 21, 2022
 *      Author: P4P4
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ADC_private.h"
#include "ADC_config.h"
#include "ADC_init.h"

void M_ADC_void_init(Prescaler_Type Copy_u8Prescaler,Vref_Type Copy_u8Vref)
{
	ADCSRA &= PRESCALER_MASK;
	ADCSRA |=(u8) Copy_u8Prescaler;

	SET_BIT(ADCSRA,ADEN);

	CLR_BIT(ADCSRA,ADIE);

	CLR_BIT(ADCSRA,ADATE);

	CLR_BIT(ADMUX,ADLAR);

	ADMUX &= VREF_MASK;
	ADMUX |= (u8) Copy_u8Vref << REFS0;
}
u16	M_ADC_u16_GetValue(u8 Copy_u8Channel)
{
	//Chose Channel
	ADMUX &= CHANNEL_MASK;
	ADMUX |= Copy_u8Channel;
	//Start Conversion
	SET_BIT(ADCSRA,ADSC);
	//Wait For Conversion(Polling)
	while(GET_BIT(ADCSRA,ADIF)==0);
	//Return Digital Value
	return ADMCL;
}
