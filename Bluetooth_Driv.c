/******************************************/
/*Author : Eslam Ibrahim                  */
/*Description : Code program and functions*/
/*                                     to */
/*              communicate with bluetooth*/
/*                            Module HC-05*/
/*Version : V2                            */
/******************************************/
#include<AVR_int.h>
#include<avr/delay.h>
#include<avr/interrupt.h>
#include<DIO.h>
#include<USART.h>
#include<String_OPR.h>



/*****************************************************************/
/*Bluetooth Inititalization by feeding Vcc and PIN34 or EN or KEY*/
/*NOTE : Bluetooth Module works at Baud Rate 19200*/
/*****************************************************************/
void Bluetooth_init(void){
	DIO_SETPINDIRECT(2,0,OUTPUT);/*PIN34 or KEY(EN) is low to select AT commands mode or Communication Mode*/
	DIO_SETPINDIRECT(2,4,OUTPUT);/*Vcc pin for hc-05 biasing*/

	DIO_SETPINVALUE(2,0,1);/*Apply High level signal to KEY(EN) to enter AT commands mode*/
	_delay_ms(50);
	DIO_SETPINVALUE(2,4,1);/*Apply High level to act as Vcc for module*/
                         }
