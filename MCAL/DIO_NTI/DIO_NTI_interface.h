/*
 * DIO_NTI_interface.h
 *
 *  Created on: Oct 20, 2023
 *      Author: Peter
 */

#ifndef DIO_NTI_INTERFACE_H_
#define DIO_NTI_INTERFACE_H_

void DIO_voidSetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Direction); // asave copy mn elvalue ely gy

#define DIO_u8INPUT    0
#define DIO_u8OUTPUT   1


#define DIO_u8PORTA    1
#define DIO_u8PORTB    2
#define DIO_u8PORTC    3
#define DIO_u8PORTD    4

void DIO_voidSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value);

#define DIO_u8LOW           0
#define DIO_u8HIGH          1

void DIO_voidSetPortValue(u8 Copy_u8Port, u8 Copy_u8Value);
void DIO_voidSetPortDirection(u8 Copy_u8Port, u8 Copy_u8Direction);
u8   DIO_u8GetPinValue(u8 u8PortIdCopy, u8 u8PinIdCopy);
void DIO_voidTogglePinValue(u8 Copy_u8Port, u8 Copy_u8Pin);

#endif /* DIO_NTI_INTERFACE_H_ */
