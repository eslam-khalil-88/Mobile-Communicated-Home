/******************************************/
/*Author : Eslam Ibrahim                  */
/*Description : Code program and functions*/
/*                              to        */
/*             communicate with bluetooth */
/*                        Module HC-05    */
/******************************************/

#include<AVR_int.h>
#include<avr/delay.h>
#include<avr/interrupt.h>
#include<DIO.h>
#include<USART.h>
#include<String_OPR.h>
#define SIZE 6

void bluetooth_init(void){

	//u8 z=0;/*variable to carry comparison of response arrays*/
	DIO_SETPINDIRECT(2,0,OUTPUT);/*PIN34 or KEY to select AT commands mode or Communication Mode*/

     /*********************************/
	 /*Declaring three pointers one to*/
	 /*hold instructions () ,the      */
	 /*second to hold response        */
	 /* from hc-05 ,and, the third    */
	 /* is a buffer to hold received  */
	 /* response via UART             */
	/**********************************/
	s8 *instrc='\0',*resp='\0',buff[8]={0};

    /*Variable SIZE as counter to loop though arrays or pointers*/
	u8 ck_count;/*ck_count is counter to check correctness of hc-05 response*/

	/*****************************************/
	/*Test Command to check whether Bluetooth*/
	/*            module is working or not   */
	/*****************************************/
	//SIZE=6;
	instrc="AT\r\n";
	resp="OK\r\n";
	DIO_SETPINVALUE(2,0,1);/*Apply High level signal to KEY to enter AT commands mode*/
	while((*instrc)!='\0'){
		USART_transmit(*instrc);
		instrc++;
	                }
	for(ck_count=0;ck_count<SIZE;ck_count++){
		while(GETRxSTATUS()==0);
		  buff[ck_count]=USART_rece();
	                   }
    buff[ck_count]='\0';/*Insert Terminating Null at the end of string*/

    /**********************************************/
    /*Check if bluetooth responds correctly or not*/
    /**********************************************/
    while(String_comp(resp,SIZE,buff,SIZE)!=0){
    	while((*instrc)!='\0'){
    			USART_transmit(*instrc);
    			instrc++;
    		                }
    		for(ck_count=0;ck_count<SIZE;ck_count++){
    			while(GETRxSTATUS()==0);
    			  buff[ck_count]=USART_rece();
    		                   }
    	    buff[ck_count]='\0';/*Insert Terminating Null at the end of string*/

                          }
       /********************************************************************/
       /*In case Bluetooth responds by OK Set Parameters of Blutooth Module*/
       /********************************************************************/

       /*Empty Buffer array*/
        for(ck_count=0;ck_count<8;ck_count++){
        			  buff[ck_count]=0;
                           }
        buff[ck_count]='\0';

        /*Set Parameters of Blutooth Module::::::Baud Rate:9600,8-bit,1-stop,No parity*/
        //SIZE=6;
    	instrc="AT+UART=9600,1,0,\r\n";
    	//resp="OK\r\n";
    	/*Check if bluetooth is configured correctly or not*/
    	while(String_comp(resp,SIZE,buff,SIZE)!=0){
    	       while((*instrc)!='\0'){
    			      USART_transmit(*instrc);
    			      instrc++;
    		                }
    	       for(ck_count=0;ck_count<SIZE;ck_count++){
    			     while(GETRxSTATUS()==0);
    			       buff[ck_count]=USART_rece();
    		                   }
    	buff[ck_count]='\0';/*Insert Terminating Null at the end of string*/

    	//z=String_comp(resp,SIZE,buff,SIZE);
    	//while(z!=0);/*Stay in loop as long as the response is not correct*/
                      }

        /*Release KEY pin t start communication mode with bluetooth*/
    	DIO_SETPINVALUE(2,0,0);
                                      }










