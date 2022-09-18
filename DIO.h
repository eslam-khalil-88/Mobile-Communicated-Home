/*
 * DIO.h
 *
 *  Created on: May 27, 2017
 *      Author: Solom
 */
/*
 * DIO.h
 *
 *  Created on: May 20, 2017
 *      Author: Solom
 */

#ifndef DIO_H_
#define DIO_H_

#include "stdtypes.h"
#define SET_BIT(REG,BIT) REG|= (1<<BIT)
#define CLR_BIT(REG,BIT) REG&= ~(1<<BIT)
#define TOGGLE_BIT(REG,BIT) REG^=(1<<BIT)
#define TOGGLE_PORT(REG) REG^=0xFF
#define INPUT 0
#define OUTPUT 1

void DIO_SETPINDIRECT(u8 port,u8 pin,u8 direction);
void DIO_SETPINVALUE(u8 port,u8 pin,u8 pvalue);
u8 get_pinvalue(u8 port,u8 pin);
void SET_PORTDIRECTION(u8 port,u8 direction);
void SET_PORTVALUE(u8 port,u8 value);



#endif /* DIO_H_ */


