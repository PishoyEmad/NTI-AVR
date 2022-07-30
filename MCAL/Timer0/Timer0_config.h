/*
 * Timer0.config.h
 *
 *  Created on: Jul 25, 2022
 *      Author: P4P4
 */

#ifndef TIMER0_TIMER0_CONFIG_H_
#define TIMER0_TIMER0_CONFIG_H_

/*
 * Choose Time0 Mode
 * (	NORMAL_MODE , CTC_MODE, FAST_PWM_MODE,PHASE_CORRECT
 */
#define TIMER0_MODE	PHASE_CORRECT

/*
 * For PWM Choose
 * INVERTED or NON_INVERTED
 */

#define TIMER0_PWM_MODE	 NON_INVERTED

/*
 * Choose
 * ( 1024 , 256 ,
 */
#define TIMER0_PRESCALER 1024


/*
 * Choose F_OSC Speed
 */
#define F_OSC	16


#endif /* TIMER0_TIMER0_CONFIG_H_ */
