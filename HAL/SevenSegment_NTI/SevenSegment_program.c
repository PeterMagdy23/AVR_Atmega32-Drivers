/*
 * SevenSegment_program.c
 *
 *  Created on: Oct 20, 2023
 *      Author: Peter
 */
#include"BIT_MATH.h"
#include"STD_TYPES.h"
#include"DIO_NTI_config.h"
#include"DIO_NTI_interface.h"
#include"DIO_NTI_private.h"
#include"SevenSegment_interface.h"

void SS_voidDispNum(u8 Copy_u8AnodePort,u8 Copy_u8CathodePort,u8 Copy_u8Number)
{

	switch (Copy_u8Number)
	{
	case 0 :DIO_voidSetPortValue(Copy_u8AnodePort,(0b00000000));break;
	case 1 :DIO_voidSetPortValue(Copy_u8AnodePort,(0b00000001));break;
	case 2 :DIO_voidSetPortValue(Copy_u8AnodePort,(0b00000010));break;
	case 3 :DIO_voidSetPortValue(Copy_u8AnodePort,(0b00000011));break;
	case 4 :DIO_voidSetPortValue(Copy_u8AnodePort,(0b00000100));break;
	case 5 :DIO_voidSetPortValue(Copy_u8AnodePort,(0b00000101));break;
	case 6 :DIO_voidSetPortValue(Copy_u8AnodePort,(0b00000110));break;
	case 7 :DIO_voidSetPortValue(Copy_u8AnodePort,(0b00000111));break;
	case 8 :DIO_voidSetPortValue(Copy_u8AnodePort,(0b00010000));break;
	case 9 :DIO_voidSetPortValue(Copy_u8AnodePort,(0b00010001));break;
	}
}

