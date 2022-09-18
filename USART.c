/*
 * USART.c
 *
 *  Created on: Jul 5, 2017
 *      Author: Solom
 */
#include<AVR_int.h>
#include<avr/delay.h>
#include<avr/interrupt.h>
#include<USART.h>
#include<DIO.h>

static u8 RxFlag=0;
static u8 RxBuffer=0;

ISR(USART_RXC_vect){
	RxFlag=1;
	RxBuffer=UDR;
              }


void USART_init(u32 baud){
  // UCSRB=0b00011000;
   SET_BIT(UCSRB,3);
   SET_BIT(UCSRB,4);
   UCSRC=0b10000110;   /*No Parity is selected :Bit 5,4*/ /*1-stop bit :Bit 3*/
   //SET_BIT(UCSRC,7);   /*Write to UCSRC with Asynchronous mode selected*/
   //SET_BIT(UCSRC,2);   /*8-bit transmission selected with UCSZ2=0*/
   //SET_BIT(UCSRC,1);   /*8-bit transmission selected with UCSZ2=0*/

   //UBRRH=0b00000000;/*may be used at high baud rates*/
   //UBRRL=baud;
   switch (baud){       /*Baud Rate selection*/
      case 2400:{
    	  UBRRH=0x01;
    	  UBRRL=0xA0;
    	  break;
              }
      case 4800:{
    	  UBRRH=0x00;
    	  UBRRL=0xCF;
    	  break;
              }
      case 9600:{
    	  UBRRH=0x00;
    	  UBRRL=0x67;
    	  break;
              }
      case 14400:{
    	  UBRRH=0x00;
    	  UBRRL=0x44;
    	  break;
              }
      case 19200:{
    	  UBRRH=0x00;
    	  UBRRL=0x33;
    	  break;
              }
      case 28800:{
    	  UBRRH=0x00;
    	  UBRRL=0x22;
    	  break;
              }
      case 38400:{
    	  UBRRH=0x00;
    	  UBRRL=0x19;
    	  break;
              }
      case 57600:{
    	  UBRRH=0x00;
    	  UBRRL=0x10;
    	  break;
              }
      default:
    	  UBRRH=0x01;
    	  UBRRL=0xA0;
          break;
          }
}

void USART_transmit(u8 data){
	while((UCSRA & (1<<UDRE))==0);

	UDR=data;
}

u8 USART_rece(void){
	//while((UCSRA & (1<<RXC))==0);
    RxFlag=0;
	return RxBuffer;
}



void USART_Interrupt(u8 direction){
	//SET_BIT(SREG,7);//global interrupt enable
	switch(direction){

	case 1:{
		SET_BIT(UCSRB,7);//enable Receive Interrupt
        break;
	      }
	case 2:{
		SET_BIT(UCSRB,6);//enable transmit interrupt
	    break;
	       }
	case 3:{
		SET_BIT(UCSRB,6);//enable transmit interrupt
		SET_BIT(UCSRB,7);//enable Receive Interrupt
		break;
	    }
	default:break;
   }


}


u8 GETRxSTATUS(void){
	return RxFlag;
                }



void USART_TransmitString(u8 str[],u8 str_size){
	 u8 st_count;
	 for(st_count=0;str[st_count]!='\0';st_count++){
		 USART_transmit(str[st_count]);
		 _delay_ms(50);/*add delay to give UART time to send data*/
	                                       }
                          }
