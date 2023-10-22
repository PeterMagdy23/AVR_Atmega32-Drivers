/*****************************************************************************/
/*                          Author: Peter Magdy                              */
/*                            Date: Oct 20, 2023                             */
/*                         version: 1.0v                                     */
/*                     Description: DIO_NTI REGISTERS                        */
/*****************************************************************************/

#ifndef DIO_NTI_PRIVATE_H_
#define DIO_NTI_PRIVATE_H_

/////////////GROUP PORTA////////////////

#define PORTA           *((volatile u8*)(0x3B))     //* DEREFRENCE FOR ACCESS, U8* POINTER CASTING, VOLATILE TO AVOID OPTIMIZATION
#define DDRA            *((volatile u8*)(0x3A))
#define PINA            *((volatile u8*)(0x39))

/////////////GROUP PORTB////////////////

#define PORTB           *((volatile u8*)(0x38))
#define DDRB            *((volatile u8*)(0x37))
#define PINB            *((volatile u8*)(0x36))

/////////////GROUP PORTC////////////////

#define PORTC           *((volatile u8*)(0x35))
#define DDRC            *((volatile u8*)(0x34))
#define PINC            *((volatile u8*)(0x33))

/////////////GROUP PORTD////////////////

#define PORTD           *((volatile u8*)(0x32))
#define DDRD            *((volatile u8*)(0x31))
#define PIND            *((volatile u8*)(0x30))

#endif /* DIO_NTI_PRIVATE_H_ */
