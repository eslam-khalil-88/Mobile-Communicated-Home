/*******************************************/
/* Author : Eslam Ibrahim Khalil           */
/* Project Name : Mobile Communicated Home */
/* Release Date : 26 August 2017           */
/*******************************************/
#include<AVR_int.h>
#include<util/delay.h>
#include<avr/interrupt.h>
#include<DIO.h>
#include<LCDFunc.h>
#include<USART.h>
#include<SW_TIMER0.h>
#include<ADC_Driv.h>
#include<Servo_Driv.h>
#include<Bluetooth_Driv.h>
#include<String_OPR.h>

/*********************************************/
/*Declaring Array of Pointers to Names       */
/*********************************************/
s8 *name[5]={"Eslam Ibrahim","Ahmed Assaf","Ahmed Ibrahim","Hussein Elsayed","Ahmed Gaber"};

/*********************************************/
/*Declaring Array of Pointers to Password    */
/*  of each person                           */
/*********************************************/
s8 *passw[5]={"1234","5863","4147","9073","3353"};

/*********************************************/
/*Declaring Array to show Welcome Screen     */
/* , Wrong Password ,and, Enter password     */
/*                              on LCD      */
/*********************************************/
s8 welcm[8]="Welcome",wrng_pass[25]="Wrong Password,Try Again",pass_req[16]=",Enter Password",
		lock_door[33]="You entered wrong Data 2 times!!";

/*********************************************/
/*Defining counters to loop through arrays   */
/*********************************************/
u8 i,count,tries;/*tries is used to give 2 chances for inputting name & password before locking*/

/******************************************************/
/*Defining an integer(16-bit) buffer to read ADC value*/
/******************************************************/
u16 ADC_Value=0;

/*********************************************/
/*Defining a buffer array to hold            */
/*               input Name & password       */
/*                                           */
/*********************************************/
s8 inp_name[17]={0},inp_pass[5]={0};
/*********************************************/
/*Declaring a buffer pointer for comparison  */
/*                  of Name & password       */
/*********************************************/
u8 *ptr='\0';


int main(){
	/****************/
	/*Initialization*/
	/****************/
	LCD_INITIALIZATION();/*LCD Initialization*/

	Servo_init();/*Servo Motor Initialization*/

	DIO_SETPINDIRECT(4,2,OUTPUT);/*LED Alarm Toggling in case of wrong input*/

	DIO_SETPINDIRECT(4,3,OUTPUT);/*Buzzer Alarm Toggle in case of wrong input*/

	ADC_init();/*ADC Initialization to take LDR Reading*/

	USART_init(19200);/*UART Peripheral Initialization for Bluetooth*/
	USART_Interrupt(3);/*Enable UART Interrupt in Receiving & Transmitting Direction*/

	Bluetooth_init();/*Bluetooth Module initialization*/

	SW_TIMER0_init();/*Initialize Timer 0 to work as delay generator*/

	ADC_startconv();/*ADC starts conversion of analog input signal*/

    sei();/*Activate Global Interrupt*/

    /*******************/
	/*While Application*/
	/*******************/
	while(1){

		/*************************/
		/*Printing Welcome Screen*/
		/*************************/
		LCDPrint_string(welcm,8);/*Show Welcome on LCD*/
	    USART_TransmitString(welcm,8);/*Show Welcome on Mobile Terminal*/
		for(i=0;i<8;i++){
			USART_transmit(welcm[i]);
			_delay_ms(50);
		                }
		USART_transmit('\n');/*Printing new line */


       /************************************/
       /*Receiving Input Name to compare it*/
       /************************************/
	   while(GETRxSTATUS()==0);/*stay in loop as long as no data is received via UART/Bluetooth*/

       for(i=0;i<15;i++){
    	   while(GETRxSTATUS()==0);
    	   inp_name[i]=USART_rece();
    	   if(inp_name[i]=='\r'){/*Check if user pressed Enter key meaning end of string*/
    		   i++;
    		   break;
    	                   }
                  }
       inp_name[i]='\0';/*Adding a terminating Null to Name array as an end indication*/

       /*****************************/
       /*Prompting to Enter password*/
       /*****************************/
       LCDPrint_string(pass_req,16);/*Show Enter Password on LCD*/
       USART_TransmitString(pass_req,16);/*Show Enter Password on Mobile Terminal*/
	   USART_transmit('\n');/*Printing new line */


       /************************************/
       /*Receiving Input password for house*/
       /************************************/
       while(GETRxSTATUS()==0);
       for(i=0;i<3;i++){
    	   inp_pass[i]=USART_rece();
    	   while(GETRxSTATUS()==0);
                    }
       inp_pass[4]='\0';/*Adding Terminating Null to pass array as an end indication*/


       /************************************************************/
       /*Comparing Name and Password to determine their correctness*/
       /************************************************************/
       tries=3;/*means you have 3 chances to enter wrong name & password before locking door*/
       while(1){

       /***************************************************************/
       /*In case input Name is ::Eslam Ibahim ,and, input pass is 1234*/
       /***************************************************************/
       if(String_comp(inp_name,13,name[0],13)==0 && String_comp(inp_pass,4,passw[0],4)==0){
        	   /*Open door by servo and light a led for a period of time*/
    	       Servo_move(10.0);
          /*Use Timer 0 to generate a delay of 5 seconds till user opens the door*/
    	  /*This delay is used to prevent system from locking door while user hasn't yet opened the door*/
    	       SW_TIMER0_start();
    	       while(1){
    	    	   if(GetTIMER0_count()==153){/*this value generates delay by 5 seconds with total period of 1 count = 256*(1024/16Mhz)*/
    	    		   SW_TIMER0_RESET();
    	    		   SW_TIMER0_stop();
    	    		   break;
    	    	             }
    	               }
    	       while(1){/*as long as photosensor giving zero reading door is opened*/
    	    	   ADC_Value=ADC_ReadFullvalue();
    	    	   if(ADC_Value<240 && ADC_Value>0){/*this means that door is closed*/
    	    		   break;
    	    	                  }
    	    	   else{/*As long as photosensor giving another reading , door is still open*/
    	    		   continue;
    	    	       }
    	                 }
    	       /*Lock door after user has closed it*/
    	       Servo_move(7.5);
        	   tries=2;/*Initialize no. of tries to 2 again*/
        	   break;
                                                }




       /**********************************************************/
       /*In case input Name is ::Ahmed Assaf ,and, input pass is */
       /**********************************************************/
       else if(String_comp(inp_name,11,name[1],11)==0 && String_comp(inp_pass,4,passw[1],4)==0){
    	           	   /*Open door by servo and light a led for a period of time*/
        	   tries=2;/*Initialize no. of tries to 2 again*/
    		   break;
    	                                                   }




       /***********************************************************/
       /*In case input Name is ::Ahmed Ibahim ,and, input pass is */
       /***********************************************************/
       else if(String_comp(inp_name,13,name[2],13)==0 && String_comp(inp_pass,4,passw[2],4)==0){
    	           	   /*Open door by servo and light a led for a period of time*/
        	   tries=2;/*Initialize no. of tries to 2 again*/
    		   break;
    	                                                   }




       /**************************************************************/
       /*In case input Name is ::Hussein Elsayed ,and, input pass is */
       /**************************************************************/
       else if(String_comp(inp_name,15,name[3],15)==0 && String_comp(inp_pass,4,passw[3],4)==0){
    	           	   /*Open door by servo and light a led for a period of time*/
        	   tries=2;/*Initialize no. of tries to 2 again*/
    		   break;
    	                                                   }




       /*************************************/
       /*In case input Name is ::Ahmed Gaber*/
       /*************************************/
       else if(String_comp(inp_name,11,name[4],11)==0 && String_comp(inp_pass,4,passw[4],4)==0){
    	           	   /*Open door by servo and light a led for a period of time*/
        	   tries=2;/*Initialize no. of tries to 2 again*/
    		   break;
    	                                                   }



       /*************************************************************/
       /*In case input Name or password is wrong you've 2 more tries*/
       /*************************************************************/
       else{
    	   while(tries==0){
    		   LCDPrint_string(lock_door,33);
    		   for(count=0;count<5;count++){
    		   DIO_SETPINVALUE(4,2,1);/*Toggling LED Alarm*/
    		   DIO_SETPINVALUE(4,3,1);/*Toggling Buzzer Alarm*/
    		   _delay_ms(500);
    		   DIO_SETPINVALUE(4,2,0);/*Toggling LED Alarm*/
    		   DIO_SETPINVALUE(4,3,0);/*Toggling Buzzer Alarm*/
    		   _delay_ms(500);
    		                                }
    		              }
    	   tries--;
    	   LCDPrint_string(wrng_pass,25);/*Show Wrong Password on LCD*/
    	   USART_TransmitString(wrng_pass,25);/*Show Wrong Password on Mobile Terminal*/
    	   continue;
                                 }
	        }
	}
     return 0;
     }
