/*
 * ADC_private.h
 *
 *  Created on: Jul 21, 2022
 *      Author: P4P4
 */

#ifndef ADC_ADC_PRIVATE_H_
#define ADC_ADC_PRIVATE_H_

#define	ADMUX	(*(volatile u8 *)0x27)
#define REFS1	7
#define REFS0	6
#define ADLAR	5

#define	ADCSRA	(*(volatile u8 *)0x26)
#define ADEN	7	//ADC Enable
#define ADSC	6	//ADC Start Conversion
#define ADATE	5	//Auto Trigger = 0
#define ADIF	4	//Conversion Flag
#define ADIE	3	//ADC Interrupt Enable
#define ADPS2	2	//Prescaler
#define ADPS1	1	//Prescaler
#define ADPS0	0	//Prescaler

//#define	ADCH	(*(volatile u8 *)0x25)
#define	ADMCL	(*(volatile u16 *)0x24)

#define	SFIOR	(*(volatile u8 *)0x50)
#define ADTS2	7
#define ADTS1	6
#define ADTS0	5

#define PRESCALER_MASK	0b11111000
#define VREF_MASK		0b00111111
#define CHANNEL_MASK	0b11100000


#endif /* ADC_ADC_PRIVATE_H_ */
