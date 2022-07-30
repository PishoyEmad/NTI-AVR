/*
 * WDT_prog.c
 *
 *  Created on: Jul 28, 2022
 *      Author: P4P4
 */
#include "WDT_init.h"

void M_WDT_Void_Enable(void)
{
	/* Enable Watchdog Time*/
	SET_BIT(WDTCR_REG,WDE);
	/*To Select 534 Second as window time */
	SET_BIT(WDTCR_REG,WDP0);
	SET_BIT(WDTCR_REG,WDP1);
	SET_BIT(WDTCR_REG,WDP2);
}

void M_WDT_Void_Disable(void)
{
	SET_BIT(WDTCR_REG,WDTOE);
	CLR_BIT(WDTCR_REG,WDE);
}

void M_WDT_Void_Refresh(void)
{
	asm("WDR");
}
