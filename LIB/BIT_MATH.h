/*
 * BIT_MATH.h
 *
 *  Created on: Jul 4, 2022
 *      Author: P4P4
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_


#define SET_BIT(VAR,BIT)	VAR |=  (1 << (BIT))
#define CLR_BIT(VAR,BIT)	VAR &= ~(1 << (BIT))
#define GET_BIT(VAR,BIT)	((VAR >> BIT) & 1  )
#define TOG_BIT(VAR,BIT)	VAR ^=  (1 << (BIT))




#endif /* BIT_MATH_H_ */
