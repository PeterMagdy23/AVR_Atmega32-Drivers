/*
 * DIO_NTI_program.c
 *
 *  Created on: Oct 20, 2023
 *      Author: Peter
 */
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_NTI_config.h"
#include "DIO_NTI_interface.h"
#include "DIO_NTI_private.h"


void DIO_voidSetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Direction)
{
if(Copy_u8Direction==DIO_u8INPUT && Copy_u8Pin<=7)       //input   >>>> 0
{
	switch(Copy_u8Port)
	    {
	    case DIO_u8PORTA : CLR_BIT(DDRA,Copy_u8Pin);break;
	    case DIO_u8PORTB : CLR_BIT(DDRB,Copy_u8Pin);break;
	    case DIO_u8PORTC : CLR_BIT(DDRC,Copy_u8Pin);break;
	    case DIO_u8PORTD : CLR_BIT(DDRD,Copy_u8Pin);break;
	    }
}
else if(Copy_u8Direction==DIO_u8OUTPUT && Copy_u8Pin<=7)  //output  >>>> 1
{
	switch(Copy_u8Port)
		{
		case DIO_u8PORTA : SET_BIT(DDRA,Copy_u8Pin);break;
		case DIO_u8PORTB : SET_BIT(DDRB,Copy_u8Pin);break;
		case DIO_u8PORTC : SET_BIT(DDRC,Copy_u8Pin);break;
		case DIO_u8PORTD : SET_BIT(DDRD,Copy_u8Pin);break;
		}
}
}

void DIO_voidSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value)
{
	if( Copy_u8Value==DIO_u8LOW && Copy_u8Pin<=7 )       //LOW   >>>> 0
   {
	switch(Copy_u8Port)
		    {
		    case DIO_u8PORTA : CLR_BIT(PORTA,Copy_u8Pin);break;
		    case DIO_u8PORTB : CLR_BIT(PORTB,Copy_u8Pin);break;
		    case DIO_u8PORTC : CLR_BIT(PORTC,Copy_u8Pin);break;
		    case DIO_u8PORTD : CLR_BIT(PORTD,Copy_u8Pin);break;
		    }
	}
	else if(Copy_u8Value==DIO_u8HIGH && Copy_u8Pin<=7)  //HIGH  >>>> 1
	{
		switch(Copy_u8Port)
			{
			case DIO_u8PORTA : SET_BIT(PORTA,Copy_u8Pin);break;
			case DIO_u8PORTB : SET_BIT(PORTB,Copy_u8Pin);break;
			case DIO_u8PORTC : SET_BIT(PORTC,Copy_u8Pin);break;
			case DIO_u8PORTD : SET_BIT(PORTD,Copy_u8Pin);break;
			}
	}
}
void DIO_voidSetPortDirection(u8 Copy_u8Port, u8 Copy_u8Direction)
{
	switch(Copy_u8Port)
				{
				case DIO_u8PORTA : DDRA=Copy_u8Direction;break;
				case DIO_u8PORTB : DDRB=Copy_u8Direction;break;
				case DIO_u8PORTC : DDRC=Copy_u8Direction;break;
				case DIO_u8PORTD : DDRD=Copy_u8Direction;break;
				}
}
void DIO_voidSetPortValue(u8 Copy_u8Port, u8 Copy_u8Value)
{
	switch(Copy_u8Port)
					{
					case DIO_u8PORTA : PORTA=Copy_u8Value;break;
					case DIO_u8PORTB : PORTB=Copy_u8Value;break;
					case DIO_u8PORTC : PORTC=Copy_u8Value;break;
					case DIO_u8PORTD : PORTD=Copy_u8Value;break;
					}
}
u8 DIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin)
{

	u8 u8ResultLocal;

	if (Copy_u8Port <= PORTD && Copy_u8Pin<=7)
	{

		switch (Copy_u8Port)
		{
			case DIO_u8PORTA: u8ResultLocal= GET_BIT(PINA,Copy_u8Pin); break;
			case DIO_u8PORTB: u8ResultLocal= GET_BIT(PINB,Copy_u8Pin); break;
			case DIO_u8PORTC: u8ResultLocal= GET_BIT(PINC,Copy_u8Pin); break;
			case DIO_u8PORTD: u8ResultLocal= GET_BIT(PIND,Copy_u8Pin); break;
		}
	}

	else
	{
		/* return 0xff in case of error in the Pin ID or PORT ID */
		u8ResultLocal = 0xFF;
	}

	return u8ResultLocal;
}
void DIO_voidTogglePinValue(u8 Copy_u8Port, u8 Copy_u8Pin)
{
if(Copy_u8Pin<=7)
{

		switch(Copy_u8Port)
			    {
			    case DIO_u8PORTA : TOGGL_BIT(PORTA,Copy_u8Pin);break;
			    case DIO_u8PORTB : TOGGL_BIT(PORTB,Copy_u8Pin);break;
			    case DIO_u8PORTC : TOGGL_BIT(PORTC,Copy_u8Pin);break;
			    case DIO_u8PORTD : TOGGL_BIT(PORTD,Copy_u8Pin);break;
			    }
}
}
