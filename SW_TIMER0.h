/*
 * SW_TIMER0.h
 *
 *  Created on: Aug 13, 2017
 *      Author: Solom
 */

#ifndef SW_TIMER0_H_
#define SW_TIMER0_H_

void SW_TIMER0_init(void);
void SW_TIMER0_start(void);
void SW_TIMER0_stop(void);
u16 GetTIMER0_count(void);
void SW_TIMER0_RESET(void);

#endif /* SW_TIMER0_H_ */
