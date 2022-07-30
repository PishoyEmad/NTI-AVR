/*
 * main.c
 *
 *  Created on: Jul 5, 2022
 *      Author: P4P4
 */
#include <avr/delay.h>
#include "DIO_int.h"
#include "LED_init.h"
#include "7_init.h"
#include "PB_init.h"
#include "Buz_init.h"
#include "KeyPad_init.h"
#include "LCD_init.h"
#include "EXTI_init.h"
#include "GIE_init.h"
#include <string.h>
#include "ADC_init.h"
#include "LM35_init.h"
#include "Timer0_init.h"
#include "Timer1_init.h"
#include "Servo_init.h"
#include "WDT_init.h"

/*********************************WDT************************************************/
/*
int main(void)
{
	_delay_ms(500);
	H_Led_void_LedInit(BLU_LED);
	H_Led_void_LedInit(RED_LED);
	H_Led_void_LedSetOn(BLU_LED);
	M_WDT_Void_Enable();
	//M_WDT_Void_Disable();
	while(1)
	{	H_Led_void_LedToggle(RED_LED);

		_delay_ms(1000);
		//M_WDT_Void_Refresh();
	}
}
 */
/***************************TaskTimer1PWM(Servo)******************************************/

void main (void)
{
	//H_KeyPad_void_init();
	H_Servo_void_Init();
	H_Servo_void_SetAngle(180);
	H_Servo_void_Start();
	_delay_ms(2000);
	H_Servo_void_SetAngle(0);
	H_Servo_void_Start();
	_delay_ms(2000);
	H_Servo_void_SetAngle(180);
	H_Servo_void_Start();
	H_LCD_void_Init();
	M_DIO_void_Init();
	M_DIO_void_SetPinDirection(DIO_PORTA, DIO_PIN0, INPUT);
	M_DIO_void_SetPinDirection(DIO_PORTA, DIO_PIN1, INPUT);
	M_DIO_void_SetPinValue(DIO_PORTA, DIO_PIN0,LOW );
	M_DIO_void_SetPinValue(DIO_PORTA, DIO_PIN1,LOW );
	u8 Angle=180, Key;
	H_LCD_void_Clear();
	H_LCD_void_SendNumber(Angle);
	while(1)
	{
		M_DIO_void_GetPiValue(DIO_PORTA, DIO_PIN0, &Key);
		if(Key==0)
		{
			Angle=+5;
			H_LCD_void_Clear();
			H_LCD_void_SendNumber(Angle);
			H_Servo_void_SetAngle(Angle);
			_delay_ms(1000);
		}
		M_DIO_void_GetPiValue(DIO_PORTA, DIO_PIN1, &Key);
		if(Key==0)
		{
			Angle=-5;
			H_LCD_void_Clear();
			H_LCD_void_SendNumber(Angle);
			H_Servo_void_SetAngle(Angle);
			_delay_ms(1000);
		}

		/*Key = H_KeyPad_u8_GetPressedKey();
					while(Key == NO_PRESSED_KEY)
					{
						Key = H_KeyPad_u8_GetPressedKey();
					}
		if(Key == '1')
		{
			Angle=+5;
			H_LCD_void_Clear();
			H_LCD_void_SendNumber(Angle);
			H_LCD_void_SendData(Key);
		}
		else if(Key == '2')
		{
			Angle=-5;
			H_LCD_void_Clear();
			H_LCD_void_SendNumber(Angle);
			H_LCD_void_SendData(Key);
		}
		H_Servo_void_SetAngle(Angle);

		for(u8 i=0 ;i<=180;i++ )
		{
		H_Servo_void_SetAngle(i);
		H_Servo_void_Start();
		H_LCD_void_Clear();
		H_LCD_void_SendNumber(i);
		_delay_ms(70);
		}*/


	}
}

/***************************TaskTimer1PWM******************************************/
/*
void main (void)
{

	M_Timer1_Void_PWM1Init();
	M_Timer1_Void_PWM1SetFrequancy(100);
	M_Timer1_Void_PWM1SetDutyCycle(1000);
	M_Timer1_Void_PWM1Start();
	while(1)
	{

	}
}

 */
/***************************TaskTimer0PWM******************************************/
/*
void A_Timer0Exc(void);

void main (void)
{
	M_TIMER0_Void_SetCallBack(A_Timer0Exc);

	M_Timer0_Void_PWM0Init();
	M_Timer0_Void_PWM0SetDutyCycle(255);
	M_Timer0_Void_PWM0Start();
	while(1)
	{

	}
}
void A_Timer0Exc(void)
{
	H_Led_void_LedToggle(BLU_LED);
	H_Led_void_LedToggle(RED_LED);
}

 */
/***************************Timer0CTCMode******************************************/
/*
void A_Timer0Exc(void);

void main (void)
{
	M_TIMER0_Void_SetCallBack(A_Timer0Exc);
	H_Led_void_LedInit(BLU_LED);
	H_Led_void_LedInit(RED_LED);
	M_GIE_void_Enable();
	M_Timer0_Void_Init();
	M_Timer0_Void_SetTime(500);
	M_Timer0_Void_Start();
	H_Led_void_LedSetOn(RED_LED);
	while(1)
	{

	}
}
void A_Timer0Exc(void)
{
	H_Led_void_LedToggle(BLU_LED);
	H_Led_void_LedToggle(RED_LED);
}

 */
/***************************Timer0_NoramalMode**************************************/
/*
void A_Timer0Exc(void);

void main (void)
{
	M_TIMER0_Void_SetCallBack(A_Timer0Exc);
	H_Led_void_LedInit(BLU_LED);
	H_Led_void_LedInit(RED_LED);
	M_GIE_void_Enable();
	M_Timer0_Void_Init();
	M_Timer0_Void_SetTime(500);
	M_Timer0_Void_Start();
	H_Led_void_LedSetOn(RED_LED);
	while(1)
	{

	}
}
void A_Timer0Exc(void)
{
	H_Led_void_LedToggle(BLU_LED);
	H_Led_void_LedToggle(RED_LED);
}
 */
/*******************Relay*******************/
/*
void main(void)
{
	M_DIO_void_SetPinDirection(DIO_PORTC, DIO_PIN4, OUTPUT);

	while(1)
	{
		for(u8 i=0;i<=2;i++)
		{
		M_DIO_void_SetPinValue(DIO_PORTC, DIO_PIN4, HIGH);
		_delay_ms(2000);
		M_DIO_void_SetPinValue(DIO_PORTC, DIO_PIN4, LOW);
		_delay_ms(2000);
		}
	}
}
 */
/***********LM35**********************/
/*
void main(void)
{
	H_LM_void_Init();

	M_ADC_void_init(Prescaler_128, Vref_AVCC);

	H_LCD_void_Init();
	u8	Temp;
	while(1)
	{
		H_LCD_void_Clear();
		Temp= H_LM_u8_Read();
		H_LCD_void_SendString("The Temp Is:");
		H_LCD_void_SendNumber(Temp);
		_delay_ms(500);
	}
}

 */
/******************Interrupt***************/
/*
void Action1(void)
{
	H_Led_void_LedToggle(BLU_LED);
}
void Action2(void)
{
	H_Led_void_LedToggle(RED_LED);
}



void main(void)
{
	M_DIO_void_SetPinDirection(DIO_PORTD, DIO_PIN2, INPUT);
	M_DIO_void_SetPinDirection(DIO_PORTD, DIO_PIN3, INPUT);

	H_Led_void_LedInit(BLU_LED);
	H_Led_void_LedInit(RED_LED);
	H_Led_void_LedInit(GRN_LED);

	M_EXTI_void_Enable(INT0_ID,LOW_LEVEL);
	M_EXTI_void_Enable(INT1_ID,ANY_CHANGE);

	M_EXTI_void_SetCallBack(Action1, INT0_ID);
	M_EXTI_void_SetCallBack(Action2, INT1_ID);

	M_GIE_void_Enable();


	while(1)
	{
		H_Led_void_LedToggle(GRN_LED);
		_delay_ms(1000);

	}
}

 */

/***************LCD Custom Characters***************************/
/*
void main(void)
{
	//u8 Smily[]={0x00,0x00,0x0A,0x00,0x11,0x0E,0x00,0x00};
	//u8 Heart[]={0x00,0x00,0x0A,0x15,0x11,0x0A,0x04,0x00};
	u8 Bh[]={0, 0, 2, 2, 30, 0, 8, 0};
	u8 Yh[]={0, 0, 2, 2, 31, 0, 20, 0};
	u8 Sh[]={4, 10, 21, 21, 31, 0, 0, 0};
	u8 Oo[]={0, 0, 14, 10, 15, 4, 8, 16};

	H_LCD_void_Init();
	H_LCD_void_SetCustomChar(Bh, 7);
	H_LCD_void_SetCustomChar(Yh, 6);
	H_LCD_void_SetCustomChar(Sh, 5);
	H_LCD_void_SetCustomChar(Oo, 4);
	H_LCD_void_SendString("Hello ");
	for(u8 i=4;i<=7;i++)
	{
	H_LCD_void_DisplayCustomChar(i);
	}
	while(1)
	{

	}
}
 */
/************LCD USER*********************/
/*
#define NUMBER_OF_USERS	3

void main(void)
{
	u8 ArrID[NUMBER_OF_USERS][4]={{'2','2','3','4'},{'5','6','7','8'},{'1','1','2','2'}};
	u8 ArrPass[NUMBER_OF_USERS][4]={{'5','0','6','0'},{'1','0','2','0'},{'0','0','0','0'}};
	u8 ArrName[NUMBER_OF_USERS][10]={{'A','h','m','e','d','\0'},{'P','i','s','h','o','\0'},{'C','A','\0'}};
	u8 ArrIN[4];
	u8 key,f=0 ;

	H_KeyPad_void_init();
	H_LCD_void_Init();
	H_LCD_void_Clear();

	while(1)
	{
		H_LCD_void_Clear();
		H_LCD_void_SendString("Enter ID:");
		for(u8 i=0;i<=3;i++)
		{
			key = H_KeyPad_u8_GetPressedKey();
			while(key == NO_PRESSED_KEY)
			{
				key = H_KeyPad_u8_GetPressedKey();
				if (key != NO_PRESSED_KEY)
				{
					H_LCD_void_SendData(key);
					ArrIN[i]=key;
				}
			}
		}
		for(s8 i=0; i<=NUMBER_OF_USERS-1;i++)
		{
			for(u8 j=0;j<=3;j++)
			{
				if(ArrIN[j]==ArrID[i][j])
				{
					f=0;

				}
				else
				{
					f=1;
					break;
				}
			}
			if(f==0)
			{
				H_LCD_void_Clear();
				H_LCD_void_SendString("Enter Pass:");
				for(u8 i=0;i<=3;i++)
				{
					key = H_KeyPad_u8_GetPressedKey();
					while(key == NO_PRESSED_KEY)
					{
						key = H_KeyPad_u8_GetPressedKey();
						if (key != NO_PRESSED_KEY)
						{
							H_LCD_void_SendData(key);
							ArrIN[i]=key;
						}
					}
				}
				for(u8 j=0;j<=3;j++)
				{
					if(ArrIN[j]==ArrPass[i][j])
					{
						f=0;
					}
					else
					{
						f=1;
						break;
					}
				}
				if(f==0)
				{
					H_LCD_void_Clear();
					H_LCD_void_SendString("Welcome ");
					H_LCD_void_SendString(ArrName[i]);
					f=0;
					break;


				}
				else
				{
					H_LCD_void_Clear();
					H_LCD_void_SendString("Wrong Password");
					f=0;
					break;
				}
			}
			else
			{
				f=1;
			}
		}
		if(f==1)
		{
			H_LCD_void_Clear();
			H_LCD_void_SendString("Wrong ID");
		}
		H_LCD_void_GotoXY(1,0);
		H_LCD_void_SendString("0 For New:");
		key = H_KeyPad_u8_GetPressedKey();
		while(key == NO_PRESSED_KEY)
		{
			key = H_KeyPad_u8_GetPressedKey();
			if (key == '0')
			{
				H_LCD_void_SendData(key);
				break;
			}
		}


	}
}
 */
//H_LCD_void_sendString("Hello world");
/*	H_LCD_void_GotoXY(0,6);
	H_LCD_void_sendString("Hello");
	H_LCD_void_GotoXY(1,6);
	H_LCD_void_sendString("World");
	_delay_ms(1000);
    H_LCD_void_Clear();
 */


// step 1 :
/*	H_SSD_void_Init();
	H_KEYPAD_void_Init();

	u8 key ;
	while (1)
	{

		key = H_KEYPAD_u8_getPressedKey();
		if (key != NO_PRESSED_KEY)
		{ // no action
		    H_SSD_void_DisplayNumber(key);

		}

	}*/


//set pin 0 in port output
/*	M_DIO_void_setPinDirection(PORTC_ID, PIN0, OUTPUT);
	M_DIO_void_Init();

	while(1)
	{
		M_DIO_setPinValue (PORTC_ID, PIN0, HIGH);
						//step 2: delay for 1 sec
		_delay_ms(1000);
						//step 3 : set value as low
		M_DIO_setPinValue (PORTC_ID, PIN0, LOW);
		_delay_ms(1000);

	}

	//H_SSD_void_Init();

	PB_t PB1 = {1, PORTD_ID, PIN2, ACTIVE_LOW};
	PB_t PB2 = {2, PORTD_ID, PIN3, ACTIVE_LOW};
	PB_t PB3 = {3, PORTD_ID, PIN4, ACTIVE_LOW};
	PB_t PB4 = {4, PORTD_ID, PIN5, ACTIVE_LOW};
	H_PB_void_Init(PB1);
	H_PB_void_Init(PB2);
	H_PB_void_Init(PB3);
	H_PB_void_Init(PB4);

	//H_PB_u8_PBread(PB1);
	H_Buzzzer_void_Init();


//	H_Led_void_LedInit(RED_LED);
//	H_Led_void_LedInit(GER_LED);
//	H_Led_void_LedInit(BLUE_LED);
	H_SSD_void_Init();
	//H_SSD_void_DisplayNumber(31);

	while(1)
	{


		H_Buzzer_voidBuzzOnce();
		_delay_ms(100);

 *
		if ((H_PB_u8_PBread(PB1)) == ACTIVE_LOW_PRESSED)
		{
			H_Buzzer_voidBuzzOnce();

			//H_SSD_void_DisplayNumber(PB1.PB_ID);

		}
		if ((H_PB_u8_PBread(PB2)) == ACTIVE_LOW_PRESSED)
		{
			//H_SSD_void_DisplayNumber(PB2.PB_ID);

		}
	 	if ((H_PB_u8_PBread(PB3)) == ACTIVE_LOW_PRESSED)
		{
			H_SSD_void_DisplayNumber(PB3.PB_ID);

		}
		if ((H_PB_u8_PBread(PB4)) == ACTIVE_LOW_PRESSED)
		{
			H_SSD_void_DisplayNumber(PB4.PB_ID);

		}
 */


//H_SSD_void_DisplayFloatNumber(3.1);
//step 1 :set value as high
//				M_DIO_setPinValue (PORTA_ID, PIN0, HIGH);
//step 2: delay for 1 sec
//				_delay_ms(1000);
//step 3 : set value as low
//				M_DIO_setPinValue (PORTA_ID, PIN0, LOW);
//				_delay_ms(1000);
//step 4 : delay for 1 sec
//	H_SSD_void_DisplayNumber(34);
//	}

#if 0
while(1)
{


	//step 1 :set value as high
	M_DIO_setPinValue (PORTC_ID, PIN0, HIGH);
	//step 2: delay for 1 sec
	_delay_ms(1000);
	//step 3 : set value as low
	M_DIO_setPinValue (PORTC_ID, PIN0, LOW);
	_delay_ms(1000);
	//step 4 : delay for 1 sec




	M_DIO_void_TogglePinValue(PORTC_ID, PIN0);
	M_DIO_void_TogglePinValue(PORTC_ID, PIN1);
	M_DIO_void_TogglePinValue(PORTC_ID, PIN2);
	_delay_ms(1000);

}
#endif




