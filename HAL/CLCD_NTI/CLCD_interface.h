/*
 * CLCD_interface.h
 *
 *  Created on: Aug 16, 2023
 *      Author: Peter
 */

#ifndef CLCD_INTERFACE_H_
#define CLCD_INTERFACE_H_


void CLCD_voidSendData(u8 Copy_u8Data);
void CLCD_voidSendCommand(u8 Copy_u8Command);
void CLCD_voidInit(void);
void CLCD_voidSendString(char*Copy_pcString);
void CLCD_voidClear(void);
void CLCD_voidWriteSpecialCharacter(u8* Copy_u8Arr,u8 Copy_u8BlockNumber,u8 Copy_u8XPos,u8 Copy_u8YPos);
void CLCD_voidGoToXY(u8 Copy_u8XPosition , u8 Copy_u8YPosition);
#endif /* CLCD_INTERFACE_H_ */
