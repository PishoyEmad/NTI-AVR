/*
 * LCD_prog.c
 *
 *  Created on: Jul 17, 2022
 *      Author: P4P4
 */

#include "STD_TYPES.h"
#include "DIO_int.h"
#include "LCD_private.h"
#include "LCD_Config.h"
#include "LCD_init.h"
#include <avr/delay.h>



void H_LCD_void_Init(void)
{
	// step  : initialize Rs, EN, RW as output
	M_DIO_void_SetPinDirection(RS_PORT, RS_PIN, OUTPUT);
	M_DIO_void_SetPinDirection(RW_PORT, RW_PIN, OUTPUT);
	M_DIO_void_SetPinDirection(EN_PORT, EN_PIN, OUTPUT);

	// step 2 : initialize D4 -> D7 as output
	M_DIO_void_SetPinDirection(D4_PORT, D4_PIN, OUTPUT);
	M_DIO_void_SetPinDirection(D5_PORT, D5_PIN, OUTPUT);
	M_DIO_void_SetPinDirection(D6_PORT, D6_PIN, OUTPUT);
	M_DIO_void_SetPinDirection(D7_PORT, D7_PIN, OUTPUT);


#if (LCD_MODE == EIGHT_BIT)
	// step 3 : initialize D0 -> D3 as output

	M_DIO_void_SetPinDirection(D0_PORT, D0_PIN, OUTPUT);
	M_DIO_void_SetPinDirection(D1_PORT, D1_PIN, OUTPUT);
	M_DIO_void_SetPinDirection(D2_PORT, D2_PIN, OUTPUT);
	M_DIO_void_SetPinDirection(D3_PORT, D3_PIN, OUTPUT);

	_delay_ms(35);
	M_DIO_void_SetPinValue(RS_PORT, RS_PIN, LOW);
	H_LCD_void_writeNlatch(FUNTION_SET_8BIT_2LINES_5x7DOTS);

#elif (LCD_MODE == FOUR_BIT)
	//step 1 : choose rs -> 0
	M_DIO_void_SetPinValue(RS_PORT, RS_PIN, LOW);

	// select read write to be write
	M_DIO_void_SetPinValue(RW_PORT, RW_PIN, LOW);
		// deactivate enable pin
	M_DIO_void_SetPinValue(EN_PORT, EN_PIN, LOW);

	//step2 : send 0010 (first part of function set )
	M_DIO_void_SetPinValue(D7_PORT, D7_PIN, 0);
	M_DIO_void_SetPinValue(D6_PORT, D6_PIN, 0);
	M_DIO_void_SetPinValue(D5_PORT, D5_PIN, 1);
	M_DIO_void_SetPinValue(D4_PORT, D4_PIN, 0);

	//activate enable pin
	M_DIO_void_SetPinValue(EN_PORT, EN_PIN, HIGH);
	_delay_ms(1); // wait until message is transfered
	M_DIO_void_SetPinValue(EN_PORT, EN_PIN, LOW);  // deactivate enable
	_delay_ms(30); // allow LCD to process command / data

	//
	M_DIO_void_SetPinValue(RS_PORT, RS_PIN, LOW);
	//
	H_LCD_void_writeNlatch(FUNTION_SET_4BIT_2LINES_5x7DOTS);


#endif
	//display ON/OFF
	// step 1 : choose RS -> 0 -> instruction
	M_DIO_void_SetPinValue(RS_PORT, RS_PIN, LOW);
	//step 2 : set instruction
	H_LCD_void_writeNlatch(DISPLAY_ON_CURSOR_ON_BLink_OFF);

	//display clear
	M_DIO_void_SetPinValue(RS_PORT, RS_PIN, LOW);
	H_LCD_void_writeNlatch(DISPLAY_CLEAR);

	M_DIO_void_SetPinValue(RS_PORT, RS_PIN, LOW);
	H_LCD_void_writeNlatch(ENTERY_MODE_SET);

	H_LCD_void_Clear();

}

void H_LCD_void_SendData(u8 Copy_u8data)
{
	M_DIO_void_SetPinValue(RS_PORT, RS_PIN, HIGH);
	H_LCD_void_writeNlatch(Copy_u8data);
}
void H_LCD_void_SendCommand(u8 Copy_u8command)
{
	M_DIO_void_SetPinValue(RS_PORT, RS_PIN,LOW);
	H_LCD_void_writeNlatch(Copy_u8command);
}
void H_LCD_void_SendString(u8 *Copy_u8str)
{
	u32 i=0;
	while(Copy_u8str[i]!='\0')
	{
		H_LCD_void_SendData(Copy_u8str[i]);
		i++;
	}
}
void H_LCD_void_SendNumber(s32 Copy_s32num)
{
	u8 Local_Arr[10];
	s32 Local_Counter=0;
	if(Copy_s32num==0)
	{
		H_LCD_void_SendData('0');
		return;
	}
	if(Copy_s32num<0)
	{
		H_LCD_void_SendData('-');
		Copy_s32num*=-1;
	}
	while(Copy_s32num!=0)
	{
		Local_Arr[Local_Counter]= Copy_s32num % 10;
		Copy_s32num = Copy_s32num/10;
		Local_Counter++;
	}
	for(Local_Counter-=1;Local_Counter>=0;Local_Counter--)
	{
		H_LCD_void_SendData(Local_Arr[Local_Counter]+'0');
	}
}
void H_LCD_void_Clear(void)
{
	H_LCD_void_SendCommand(DISPLAY_CLEAR);
}
void H_LCD_void_GotoXY(u8 Copy_u8Row,u8 Copy_u8Col)
{
	if(Copy_u8Row>=0 && Copy_u8Row<=1 && Copy_u8Col>=0 && Copy_u8Col<=16)
	{
		u8 Local_Arr[2]={SET_R0_C0,SET_R1_C0};
		H_LCD_void_SendCommand(Local_Arr[Copy_u8Row]+Copy_u8Col);
	}
}
static void H_LCD_void_writeNlatch(u8 Copy_u8Byte)
{
#if(LCD_MODE==EIGHT_BIT)
	M_DIO_void_SetPinValue(RW_PORT,RW_PIN,LOW);
	M_DIO_void_SetPinValue(EN_PORT,EN_PIN,LOW);

	M_DIO_void_SetPinValue(D7_PORT, D7_PIN, (Copy_u8Byte>>7)&1);
	M_DIO_void_SetPinValue(D6_PORT, D6_PIN, (Copy_u8Byte>>6)&1);
	M_DIO_void_SetPinValue(D5_PORT, D5_PIN, (Copy_u8Byte>>5)&1);
	M_DIO_void_SetPinValue(D4_PORT, D4_PIN, (Copy_u8Byte>>4)&1);
	M_DIO_void_SetPinValue(D3_PORT, D3_PIN, (Copy_u8Byte>>3)&1);
	M_DIO_void_SetPinValue(D2_PORT, D2_PIN, (Copy_u8Byte>>2)&1);
	M_DIO_void_SetPinValue(D1_PORT, D1_PIN, (Copy_u8Byte>>1)&1);
	M_DIO_void_SetPinValue(D0_PORT, D0_PIN, (Copy_u8Byte>>0)&1);

	M_DIO_void_SetPinValue(EN_PORT,EN_PIN, HIGH);
	_delay_ms(1);
	M_DIO_void_SetPinValue(EN_PORT,EN_PIN, LOW);
	_delay_ms(5);


#elif(LCD_MODE==FOUR_BIT)
	// select read write to be write
	M_DIO_void_SetPinValue(RW_PORT, RW_PIN, LOW);
	// deactivate enable pin
	M_DIO_void_SetPinValue(EN_PORT, EN_PIN, LOW);

	//write msg into 2 messages
	//write message high nibble
	M_DIO_void_SetPinValue(D7_PORT, D7_PIN, (Copy_u8Byte>>7) & 1);
	M_DIO_void_SetPinValue(D6_PORT, D6_PIN, (Copy_u8Byte>>6) & 1);
	M_DIO_void_SetPinValue(D5_PORT, D5_PIN, (Copy_u8Byte>>5) & 1);
	M_DIO_void_SetPinValue(D4_PORT, D4_PIN, (Copy_u8Byte>>4) & 1);

	//activate enable pin
	M_DIO_void_SetPinValue(EN_PORT, EN_PIN, HIGH);
	_delay_ms(1); // wait until message is transfered
	M_DIO_void_SetPinValue(EN_PORT, EN_PIN, LOW);  // deactivate enable
	_delay_ms(5); // allow LCD to process command / data

	//msg low nibble
	M_DIO_void_SetPinValue(D7_PORT, D7_PIN, (Copy_u8Byte>>3) & 1);
	M_DIO_void_SetPinValue(D6_PORT, D6_PIN, (Copy_u8Byte>>2) & 1);
	M_DIO_void_SetPinValue(D5_PORT, D5_PIN, (Copy_u8Byte>>1) & 1);
	M_DIO_void_SetPinValue(D4_PORT, D4_PIN, (Copy_u8Byte>>0) & 1);


	//activate enable pin
	M_DIO_void_SetPinValue(EN_PORT, EN_PIN, HIGH);
	_delay_ms(1); // wait until message is transfered
	M_DIO_void_SetPinValue(EN_PORT, EN_PIN, LOW);  // deactivate enable
	_delay_ms(5); // allow LCD to process command / data



#else
#error("Wrong LCD Mode");
#endif
}


void H_LCD_void_SetCustomChar(u8 * Arr_Pattern,u8 Char_Code)
{
	u8 Local_Counter=0;
	H_LCD_void_SendCommand(SET_CGRAM_ADRESS+Char_Code*8);
	for(Local_Counter=0;Local_Counter<=7;Local_Counter++)
	{
		H_LCD_void_SendData(Arr_Pattern[Local_Counter]);
	}
	H_LCD_void_SendCommand(SET_DDRAM_ADRESS);
}


void H_LCD_void_DisplayCustomChar(u8 Char_Code)
{
	H_LCD_void_SendData(Char_Code);
}






