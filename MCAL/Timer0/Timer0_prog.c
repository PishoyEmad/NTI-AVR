/*
 * Timer0_prog.c
 *
 *  Created on: Jul 25, 2022
 *      Author: P4P4
 */

#include "Timer0_init.h"

u32 Timer0_u32Num_of_ov=0;
u8 Timer0_u8RemTicks=0;
u32 Timer0_u32Num_of_Cm=0;
void (*CallBack)(void);

void M_Timer0_Void_Init(void)
{
#if TIMER0_MODE	==	NORMAL_MODE
	CLR_BIT(TCCR0_REG,WGM00);
	CLR_BIT(TCCR0_REG,WGM01);
	//To Enable Timer0 OverFlow
	SET_BIT(TIMSK_REG,TOIE0);
#elif TIMER0_MODE == CTC_MODE
	CLR_BIT(TCCR0_REG,WGM00);
	SET_BIT(TCCR0_REG,WGM01);
	//To Enable Timer0 OverFlow
	SET_BIT(TIMSK_REG,OCIE0);

#endif

}

void M_Timer0_Void_SetTime(u32 Copy_u32DesiredTime_ms)
{
	u32	Local_u32TickTime 	= TIMER0_PRESCALER / F_OSC;// Result in micro sec
	u32 Local_u32TotalTicks	= Copy_u32DesiredTime_ms*1000/Local_u32TickTime;
#if TIMER0_MODE	==	NORMAL_MODE
	Timer0_u32Num_of_ov		= Local_u32TotalTicks/256;
	Timer0_u8RemTicks				= Local_u32TotalTicks%256;
	TCNT0_REG= Timer0_u8RemTicks;
	if(Timer0_u8RemTicks!=0)
	{
		TCNT0_REG = 256 - Timer0_u8RemTicks;
		Timer0_u32Num_of_ov++;
	}
#elif TIMER0_MODE	==	CTC_MODE
	u8 Local_Counter=255;
	while(Local_u32TotalTicks%Local_Counter)
	{
		Local_Counter--;
	}
	Timer0_u32Num_of_Cm = Local_u32TotalTicks / Local_Counter;
	OCR0	 =Local_Counter-1;
#endif

}


void M_Timer0_Void_Start(void)
{
#if	TIMER0_PRESCALER	== 1024
	SET_BIT(TCCR0_REG,CS00);
	CLR_BIT(TCCR0_REG,CS01);
	SET_BIT(TCCR0_REG,CS02);

#elif IMER0_PRESCALER == 256
	CLR_BIT(TCCR0_REG,CS00);
	CLR_BIT(TCCR0_REG,CS01);
	SET_BIT(TCCR0_REG,CS02);
#endif
}

void M_Timer0_Void_Stop(void)
{
	CLR_BIT(TCCR0_REG,CS00);
	CLR_BIT(TCCR0_REG,CS01);
	CLR_BIT(TCCR0_REG,CS02);
}

void M_Timer0_Void_PWM0Init(void)
{

	M_DIO_void_SetPinDirection( DIO_PORTB ,DIO_PIN3 , OUTPUT);
#if TIMER0_MODE == FAST_PWM_MODE
	SET_BIT(TCCR0_REG,WGM00);
	SET_BIT(TCCR0_REG,WGM01);

#if TIMER0_PWM_MODE	== NON_INVERTED
	CLR_BIT(TCCR0_REG,COM00);
	SET_BIT(TCCR0_REG,COM01);
#elif TIMER0_PWM_MODE == INVERTED
	SET_BIT(TCCR0_REG,COM00);
	SET_BIT(TCCR0_REG,COM01);
#endif

#elif TIMER0_MODE == PHASE_CORRECT
	SET_BIT(TCCR0_REG,WGM00);
	CLR_BIT(TCCR0_REG,WGM01);

#if TIMER0_PWM_MODE	== NON_INVERTED
	CLR_BIT(TCCR0_REG,COM00);
	SET_BIT(TCCR0_REG,COM01);
#elif TIMER0_PWM_MODE == INVERTED
	SET_BIT(TCCR0_REG,COM00);
	SET_BIT(TCCR0_REG,COM01);
#endif
#endif


}

void M_Timer0_Void_PWM0SetDutyCycle(u8	Copy_u8DeutyCycle)
{
#if TIMER0_MODE == FAST_PWM_MODE

#if TIMER0_PWM_MODE	== NON_INVERTED
	OCR0_REG=(Copy_u8DeutyCycle*256/100)-1;
#elif TIMER0_PWM_MODE	== NON_INVERTED
	OCR0_REG=255-(Copy_u8DeutyCycle*256/(100));
#endif

#elif TIMER0_MODE == PHASE_CORRECT
#if TIMER0_PWM_MODE	== NON_INVERTED
	OCR0_REG=(Copy_u8DeutyCycle*255/100);
#elif TIMER0_PWM_MODE	== NON_INVERTED
	OCR0_REG=255-(Copy_u8DeutyCycle*256/(100));
#endif

#endif

}

void M_Timer0_Void_PWM0Start(void)
{
	M_Timer0_Void_Start();
}

void M_Timer0_Void_PWM0Stop(void)
{
	M_Timer0_Void_Stop();
}




void M_TIMER0_Void_SetCallBack(void (*CopyPtr)(void))
{
	CallBack=CopyPtr;
}
#if TIMER0_MODE	==	NORMAL_MODE

ISR(TIMER0_OVF_vect)
{
	static u32 Local_32Counter=0;
	Local_32Counter++;
	if(Local_32Counter==Timer0_u32Num_of_ov)
	{
		//H_Led_void_LedToggle(BLU_LED);
		CallBack();
		Local_32Counter=0;
		TCNT0_REG = 256 - Timer0_u8RemTicks;
	}
}
#elif TIMER0_MODE == CTC_MODE
ISR(TIMER0_COMP_vect)
{
	static u32 Local_32Counter=0;
	Local_32Counter++;
	if(Local_32Counter==Timer0_u32Num_of_Cm)
	{
		//H_Led_void_LedToggle(BLU_LED);
		CallBack();
		Local_32Counter=0;
	}
}
#endif

