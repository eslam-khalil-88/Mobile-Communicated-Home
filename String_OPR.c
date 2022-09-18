/*
 * String_OPR.c
 *
 *  Created on: Aug 9, 2017
 *      Author: Solom
 */

#include<AVR_int.h>
#include<avr/delay.h>
#include<avr/interrupt.h>
#include<DIO.h>
#include<LCDFunc.h>
#include<USART.h>




/********************************************/
/*String_comp is used to compare two strings*/
/*    and returns 0 when both strings are   */
/*                                equal     */
/********************************************/
u8 String_comp(s8 arr_A[],u8 SIZE_A,s8 arr_B[],u8 SIZE_B){
   u8 counter=SIZE_A,var;
   for(var=0;arr_A[var]!='\0' || arr_B[var]!='\0';var++){
	   if(arr_A[var]==arr_B[var]){
		   counter--;
	                             }
	   else{
		   continue;
	       }
                                   }
   counter--;//decrement by 1 for null
   return counter;
                           }


/**********************************************/
/*Special Task to print a string on LCD*/
/**********************************************/


void LCDPrint_string(u8 arr[],u8 size){
     u8 x_count=0;//counter to loop through string
     for(x_count=0;arr[x_count]!='\0';x_count++){
    	 LCD_senddata(arr[x_count]);
                             }
                        }

