/*
 * DIO.c
 *
 *  Created on: May 21, 2017
 *      Author: Solom
 */

#include<AVR_int.h>
#include<avr/delay.h>
#include<DIO.h>





void DIO_SETPINDIRECT(u8 port,u8 pin,u8 direction){
  switch(port){
         case 1:{
	        if(direction==OUTPUT){
	        	SET_BIT(DDRA,pin);
	              }
	        else{
	        	CLR_BIT(DDRA,pin);
	        }
	        break;
            }
         case 2:{
        	 if(direction==OUTPUT){
        	 	        	SET_BIT(DDRB,pin);
        	 	              }
        	 	        else{
        	 	        	CLR_BIT(DDRB,pin);
        	 	        }
        	 	        break;
        	             }
         case 3:{
        	 if(direction==OUTPUT){
        	 	        	SET_BIT(DDRC,pin);
        	 	              }
        	 	        else{
        	 	        	CLR_BIT(DDRC,pin);
        	 	        }
        	 	        break;
        	             }
         case 4:{
        	 if(direction==OUTPUT){
        	 	        	SET_BIT(DDRD,pin);
        	 	              }
        	 	        else{
        	 	        	CLR_BIT(DDRD,pin);
        	 	        }
        	 	        break;
        	             }
           }
         }




void DIO_SETPINVALUE(u8 port,u8 pin,u8 pvalue){
          switch(port){
          case 1:{
        	  SET_BIT(DDRA,pin);
        	    if(pvalue!=0){
        	    	SET_BIT(PORTA,pin);
        	        }
        	    else{
        	    	CLR_BIT(PORTA,pin);
        	        }
        	  break;
                  }
          case 2:{
        	  SET_BIT(DDRB,pin);
        	          	    if(pvalue!=0){
        	          	    	SET_BIT(PORTB,pin);
        	          	        }
        	          	    else{
        	          	    	CLR_BIT(PORTB,pin);
        	          	        }
        	  break;
                   }
          case 3:{
        	  SET_BIT(DDRC,pin);
        	          	    if(pvalue!=0){
        	          	    	SET_BIT(PORTC,pin);
        	          	        }
        	          	    else{
        	          	    	CLR_BIT(PORTC,pin);
        	          	        }
        	  break;
                   }
          case 4:{
        	  SET_BIT(DDRD,pin);
        	          	    if(pvalue!=0){
        	          	    	SET_BIT(PORTD,pin);
        	          	        }
        	          	    else{
        	          	    	CLR_BIT(PORTD,pin);
        	          	        }
        	  break;
                    }
                }
                 }


u8 get_pinvalue(u8 port,u8 pin){
	u8 inp_value=0;
	switch(port){
	          case 1:{
	        	  //DDRA=0x00;
	        	  CLR_BIT(DDRA,pin);
	        	  inp_value=PINA;
	        	  return inp_value;
	        	  break;
	               }
	          case 2:{
	        	  //DDRB=0x00;
	        	  CLR_BIT(DDRB,pin);
	        	  inp_value=PINB;
	        	  return inp_value;
	        	  break;
	                   }
	          case 3:{
	        	  //DDRC=0x00;
	        	  CLR_BIT(DDRC,pin);
	        	  inp_value=PINC;
	        	  return inp_value;
	        	  break;
	                  }
	          case 4:{
	        	  //DDRD=0x00;
	        	  CLR_BIT(DDRD,pin);
	        	  inp_value=PIND;
	        	  return inp_value;
	        	  break;
	                }
	          default:return 0;
	         }
             }


void SET_PORTDIRECTION(u8 port,u8 direction){
	switch(port){
	          case 1:{
	        	  if(direction!=INPUT){
	        		  DDRA=0xFF;
	        	  }
	        	  else{
	        		 DDRA=0x00;
	        	     }
	        	  break;
	                }
	          case 2:{
	        	  if(direction!=INPUT){
	        	  	        		  DDRB=0xFF;
	        	  	        	  }
	        	  	        	  else{
	        	  	        		 DDRB=0x00;
	        	  	        	     }
	        	  break;
	                   }
	          case 3:{
	        	  if(direction!=INPUT){
	        	  	        		  DDRC=0xFF;
	        	  	        	  }
	        	  	        	  else{
	        	  	        		 DDRC=0x00;
	        	  	        	     }
	        	  break;
	                    }
	          case 4:{
	        	  if(direction!=INPUT){
	        	  	        		  DDRD=0xFF;
	        	  	        	  }
	        	  	        	  else{
	        	  	        		 DDRD=0x00;
	        	  	        	     }
	        	  break;
	                   }
	                }
                 }


void SET_PORTVALUE(u8 port,u8 value){
	switch(port){
	          case 1:{
	        	  DDRA=0xFF;
	        	  PORTA=value;
	        	  break;
	                }
	          case 2:{
	        	  DDRB=0xFF;
	        	  PORTB=value;
	        	  break;
	                   }
	          case 3:{
	        	  DDRC=0xFF;
	        	  PORTC=value;
	        	  break;
	                    }
	          case 4:{
	        	  DDRD=0xFF;
	        	  PORTD=value;
	        	  break;
	                   }
	                }
             }
