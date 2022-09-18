/*
 * USART.h
 *
 *  Created on: Jul 6, 2017
 *      Author: Solom
 */

#ifndef USART_H_
#define USART_H_

#include<stdtypes.h>
#define RECEIVE 0
#define TRANSMIT 1
#define TR_RE  2


void USART_init(u32 baud);
void USART_transmit(u8 data);
u8 USART_rece(void);
void USART_Interrupt(u8 direction);
u8 GETRxSTATUS(void);
void USART_TransmitString(u8 str[],u8 str_size);

#endif /* USART_H_ */
