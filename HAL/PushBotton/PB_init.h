/*
 * PB_init.h
 *
 *  Created on: Jul 7, 2022
 *      Author: P4P4
 */


#ifndef PUSHBOTTON_PB_INIT_H_
#define PUSHBOTTON_PB_INIT_H_

#include "../../LIB/STD_TYPES.h"

#define ACTIVE_HIGH	1
#define ACTIVE_LOW	0

#define ACTIVE_LOW_PRESED	0
#define ACTIVE_LOW_RELESED	1

#define ACTIVE_HIGH_PRESED	1
#define ACTIVE_HIGH_RELESED	0

typedef struct
{
	u8	PB_ID;
	u8	PB_Port;
	u8	PB_Pin;
	u8	PB_ActiveMode;
}PB_t;


void H_PB_void_Init(PB_t Copy_PB);
u8	 H_PB_u8_PBRead(PB_t Copy_PB);

#endif /* PUSHBOTTON_PB_INIT_H_ */
