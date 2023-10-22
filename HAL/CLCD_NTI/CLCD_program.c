/*
 * CLCD_program.c
 *
 *  Created on: Aug 16, 2023
 *      Author: Peter
 */

/* 1) func. tktb el7rf
 * 2) func. command
 * 3) 8albyt el7agat ely lyha config byt3mlha func. asmha init
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "CLCD_config.h"
#include "CLCD_interface.h"
#include "CLCD_private.h"
#include <util/delay.h>

static u8 init=0;

void CLCD_voidSendData(u8 Copy_u8Data)

{
		DIO_voidSetPinValue (CLCD_ControlPort, CLC_Rs_PIN ,DIO_u8HIGH);

		DIO_voidSetPinValue (CLCD_ControlPort, CLC_RW_PIN ,DIO_u8LOW);


		for(int i=0,j=4;i<4;i++)
			{
			DIO_voidSetPinValue(CLCD_DataPort,i,GET_BIT(Copy_u8Data,j));
			j++;
			}


			DIO_voidSetPinValue (CLCD_ControlPort, CLC_E_PIN ,DIO_u8HIGH);
			_delay_ms(1);
			DIO_voidSetPinValue (CLCD_ControlPort, CLC_E_PIN ,DIO_u8LOW);


		for(int i=0,j=0;i<4;i++)
			{
			DIO_voidSetPinValue(CLCD_DataPort,i,GET_BIT(Copy_u8Data,j));
			j++;
			}

			DIO_voidSetPinValue (CLCD_ControlPort, CLC_E_PIN ,DIO_u8HIGH);
			_delay_ms(1);
			DIO_voidSetPinValue (CLCD_ControlPort, CLC_E_PIN ,DIO_u8LOW);
			_delay_ms(2);
}

void CLCD_voidSendCommand(u8 Copy_u8Command)

	{
	DIO_voidSetPinValue (CLCD_ControlPort, CLC_Rs_PIN ,DIO_u8LOW);

	DIO_voidSetPinValue (CLCD_ControlPort, CLC_RW_PIN ,DIO_u8LOW);


	for(int i=0,j=4;i<4;i++)
		{
		DIO_voidSetPinValue(CLCD_DataPort,i,GET_BIT(Copy_u8Command,j));
		j++;
		}


		DIO_voidSetPinValue (CLCD_ControlPort, CLC_E_PIN ,DIO_u8HIGH);
		_delay_ms(1);
		DIO_voidSetPinValue (CLCD_ControlPort, CLC_E_PIN ,DIO_u8LOW);

	if(init)
	{
	for(int i=0,j=0;i<4;i++)
		{
		DIO_voidSetPinValue(CLCD_DataPort,i,GET_BIT(Copy_u8Command,j));
		j++;
		}
			DIO_voidSetPinValue (CLCD_ControlPort, CLC_E_PIN ,DIO_u8HIGH);
			_delay_ms(1);
			DIO_voidSetPinValue (CLCD_ControlPort, CLC_E_PIN ,DIO_u8LOW);
	}
		_delay_ms(2);
}

void CLCD_voidInit(void)
{
	_delay_ms(35);
	CLCD_voidSendCommand(0x20);

	CLCD_voidSendCommand(0x20);
	//N&F
	CLCD_voidSendCommand(0b10000000);//gwaha delay
	_delay_ms(1);

	CLCD_voidSendCommand(0x00);
	CLCD_voidSendCommand(0xF0);
	_delay_ms(1);

	CLCD_voidSendCommand(0x00);
	CLCD_voidSendCommand(0x10);
	_delay_ms(2);
	//ID&SH
	CLCD_voidSendCommand(0b00000000);
	CLCD_voidSendCommand(0b01100000);

	init=1;
	//entry mode malo4 lazma
}
void CLCD_voidSendString(char*Copy_pcString)
{
	u8 Local_u8Iterator=0;

	while((Copy_pcString[Local_u8Iterator])!='\0')
	{

		CLCD_voidSendData(Copy_pcString[Local_u8Iterator]);

		Local_u8Iterator++;

	}
}
void CLCD_voidClear(void)
{
	/*DIO_voidSetPinValue (CLCD_ControlPort, CLC_Rs_PIN ,DIO_u8LOW);

	DIO_voidSetPinValue (CLCD_ControlPort, CLC_RW_PIN ,DIO_u8LOW);*/

	CLCD_voidSendCommand(0b00000001);

}
void CLCD_voidWriteSpecialCharacter(u8* Copy_u8Arr,u8 Copy_u8BlockNumber,u8 Copy_u8XPos,u8 Copy_u8YPos)
{
	u8 Local_u8CGRAMAddress,Local_u8Iterator;
	//Calculate the CG RAM address whose each block is 8 Byte/
	Local_u8CGRAMAddress = Copy_u8BlockNumber*8;

	//Send CG RAM address command to LCD,With setting bit 6/
	CLCD_voidSendCommand(Local_u8CGRAMAddress+64);//64 in binary 0b01000000

	//Loop on the array and send the data or the array to the CGRAM/

	for(Local_u8Iterator=0;Local_u8Iterator<8;Local_u8Iterator++)
	{
		CLCD_voidSendData(Copy_u8Arr[Local_u8Iterator]);
	}

	//Go to DDRAM/
	CLCD_voidGoToXY(Copy_u8XPos,Copy_u8YPos);

	//Send the data on the DDRAM and the data is called by the Block number/
	CLCD_voidSendData(Copy_u8BlockNumber);

}
void CLCD_voidGoToXY(u8 Copy_u8XPosition , u8 Copy_u8YPosition)
{
	u8 Local_u8Address;
	if (Copy_u8XPosition==0)
	{
		Local_u8Address=Copy_u8YPosition;
	}
	else if (Copy_u8XPosition==1)
	{
		Local_u8Address=Copy_u8YPosition+0x40;
	}
	CLCD_voidSendCommand(Local_u8Address+128);

}
