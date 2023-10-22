/*
 * CLCD_config.h
 *
 *  Created on: Aug 16, 2023
 *      Author: Peter
 */

#ifndef CLCD_CONFIG_H_
#define CLCD_CONFIG_H_

/* Options for selecting Data Port :
 *             1) DIO_u8PORTA
 *             2) DIO_u8PORTB
 *             3) DIO_u8PORTC
 *             4) DIO_u8PORTD
 */

#define CLCD_DataPort          DIO_u8PORTB

/* Options for selecting Control Port but not like Data Port :
 *             1) DIO_u8PORTA
 *             2) DIO_u8PORTB
 *             3) DIO_u8PORTC
 *             4) DIO_u8PORTD
 */

#define CLCD_ControlPort       DIO_u8PORTA

#define CLC_Rs_PIN                  3
#define CLC_RW_PIN                  1
#define CLC_E_PIN                   2

#endif /* CLCD_CONFIG_H_ */
