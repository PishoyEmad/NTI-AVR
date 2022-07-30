/*
 * DIO_prog.c
 *
 *  Created on: Jul 4, 2022
 *      Author: P4P4
 */


#include "DIO_privet.h"
#include "DIO_confih.h"
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "DIO_int.h"


void M_DIO_void_Init(void)
{
	DDRA_REG=CONC(PA0,PA1,PA2,PA3,PA4,PA5,PA6,PA7);
	DDRB_REG=CONC(PB0,PB1,PB2,PB3,PB4,PB5,PB6,PB7);
	DDRC_REG=CONC(PC0,PC1,PC2,PC3,PC4,PC5,PC6,PC7);
	DDRD_REG=CONC(PD0,PD1,PD2,PD3,PD4,PD5,PD6,PD7);
}


void M_DIO_void_SetPinDirection(u8 Copy_u8PortID,u8 Copy_u8PinID,u8 Copy_u8PinDirection)
{
	switch (Copy_u8PortID) {
	case DIO_PORTA:
		CLR_BIT(DDRA_REG,Copy_u8PinID);
		DDRA_REG |=Copy_u8PinDirection << Copy_u8PinID;
		break;

	case DIO_PORTB:
		CLR_BIT(DDRB_REG,Copy_u8PinID);
		DDRB_REG |=Copy_u8PinDirection << Copy_u8PinID;
		break;

	case DIO_PORTC:
		CLR_BIT(DDRC_REG,Copy_u8PinID);
		DDRC_REG |=Copy_u8PinDirection << Copy_u8PinID;
		break;

	case DIO_PORTD:
		CLR_BIT(DDRD_REG,Copy_u8PinID);
		DDRD_REG |=Copy_u8PinDirection << Copy_u8PinID;
		break;

	default:
		break;
	}

}


void M_DIO_void_SetPinValue(u8 Copy_u8PortID,u8 Copy_u8PinID,u8 Copy_u8PinValue)
{
	switch (Copy_u8PortID) {
	case DIO_PORTA:
		CLR_BIT(PORTA_REG,Copy_u8PinID);
		PORTA_REG |=Copy_u8PinValue << Copy_u8PinID;
		break;

	case DIO_PORTB:
		CLR_BIT(PORTB_REG,Copy_u8PinID);
		PORTB_REG |=Copy_u8PinValue << Copy_u8PinID;
		break;

	case DIO_PORTC:
		CLR_BIT(PORTC_REG,Copy_u8PinID);
		PORTC_REG |=Copy_u8PinValue << Copy_u8PinID;
		break;

	case DIO_PORTD:
		CLR_BIT(PORTD_REG,Copy_u8PinID);
		PORTD_REG |=Copy_u8PinValue << Copy_u8PinID;
		break;

	default:
		break;
	}

}


void M_DIO_void_GetPiValue(u8 Copy_u8PortID,u8 Copy_u8PinID,u8 * ptrValue)
{
	switch (Copy_u8PortID) {
	case DIO_PORTA:
		*ptrValue=GET_BIT(PINA_REG,Copy_u8PinID);
		break;

	case DIO_PORTB:
		*ptrValue=GET_BIT(PINB_REG,Copy_u8PinID);
		break;

	case DIO_PORTC:
		*ptrValue=GET_BIT(PINC_REG,Copy_u8PinID);
		break;

	case DIO_PORTD:
		*ptrValue=GET_BIT(PIND_REG,Copy_u8PinID);
		break;

	default:
		break;
	}




}


void M_DIO_void_TogglePinValue(u8 Copy_u8PortID,u8 Copy_u8PinID)
{
	switch (Copy_u8PortID) {
	case DIO_PORTA:
		TOG_BIT(PORTA_REG,Copy_u8PinID);
		break;

	case DIO_PORTB:
		TOG_BIT(PORTB_REG,Copy_u8PinID);
		break;

	case DIO_PORTC:
		TOG_BIT(PORTC_REG,Copy_u8PinID);
		break;

	case DIO_PORTD:
		TOG_BIT(PORTD_REG,Copy_u8PinID);
		break;

	default:
		break;
	}


}


