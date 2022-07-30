/*
 * ADC_init.h
 *
 *  Created on: Jul 21, 2022
 *      Author: P4P4
 */

#ifndef ADC_ADC_INIT_H_
#define ADC_ADC_INIT_H_

typedef	enum
{
	Prescaler_2 = 1	,
	Prescaler_4		,
	Prescaler_8		,
	Prescaler_16	,
	Prescaler_32	,
	Prescaler_64	,
	Prescaler_128	,

}Prescaler_Type;

typedef	enum
{
	Vref_AREF		,
	Vref_AVCC		,
	Vref_Internal=3	,
}Vref_Type;

void M_ADC_void_init(Prescaler_Type Copy_u8Prescaler,Vref_Type Copy_u8Vref);
u16	M_ADC_u16_GetValue(u8 Copy_u8Channel);

#endif /* ADC_ADC_INIT_H_ */
