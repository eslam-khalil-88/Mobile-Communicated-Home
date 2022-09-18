/******************************************/
/* Description : Software Timer 0 Driver  */
/*                to use it as a delay or */
/*                counter                 */
/* Created on: Aug 13, 2017               */
/*      Author: Solom                     */
/******************************************/
#include<AVR_int.h>
#include<util/delay.h>
#include<avr/interrupt.h>
#include<DIO.h>


u16 ctr=0;

ISR(TIMER0_COMP_vect){
	ctr++;
             }



void SW_TIMER0_init(void){
	 TCCR0=0b00001101;/*CTC Mode is activated Bit 6 ,3*/
     OCR0=0xFF;
                }


void SW_TIMER0_start(void){
     TIMSK=0x02;
                }

void SW_TIMER0_stop(void){
	 TIMSK=0x00;
                }

u16 GetTIMER0_count(void){
	return ctr;
          }


void SW_TIMER0_RESET(void){
	 ctr=0;
                 }
