#include<AVR_int.h>
#include<avr/interrupt.h>
#include<avr/delay.h>
#include<DIO.h>
#include<Servo_Driv.h>


void Servo_init(void){
	DIO_SETPINDIRECT(4,5,OUTPUT);
	TCCR1A=0b10000010;
	TCCR1B=0b00011101;
	ICR1=313;//Total period is 20 msec for 16Mhz crystal
	ICR1=155;//Total period is 20msec for 8Mhz crystal with prescalar=1024

             }

void Servo_move(f32 duty_cycle){
	f32 f_duty=0.0;
	//f_duty=(duty_cycle) * 313;
	//f_duty=f_duty/100.0;
	f_duty=(duty_cycle/100.0);
	//f_duty*=313;//for 16 Mhz crsystal
	f_duty*=155;//for 8 Mhz crsystal
	OCR1A=f_duty;
             }

