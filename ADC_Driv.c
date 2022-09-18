/**
 *
 */
#include<AVR_int.h>
#include<util/delay.h>
#include<avr/interrupt.h>
#include<DIO.h>

static u16 adc_value=0;
u8 x=0;//variable to read value of ADCH
static u16 ADC_Buffer=0;
static u8 ADC_Flag=0;

ISR(ADC_vect){
	adc_value=0;
	ADC_Buffer=ADCL;
	x=ADCH;
	ADC_Flag=1;
	//adc_value=(x<<8);
	//adc_value|=ADC_Buffer;
	adc_value=(x<<8) | ADC_Buffer;

     }

void ADC_init(void){
	 DIO_SETPINDIRECT(1,0,INPUT);
	 DIO_SETPINDIRECT(1,1,INPUT);
     ADMUX=0b01000000;//Channel ADC0 is selected with Vref=5v
    //  ADMUX=0b01000001;//Channel ADC1 is selected
     //ADCSRA=0b10011110;//8-bit Resolution with prescalar at clk/32 i.e:500khz with AVCC=5v
     ADCSRA=0b10001111;//Vref with 1024 resolution
     //SET_BIT(SREG,7);
     _delay_us(200);
            }


void ADC_startconv(void){
     SET_BIT(ADCSRA,6);
	//ADCSRA|=0b01000000;

     while((ADCSRA & (0x10))==0);
     _delay_us(200);
            }


u8 ADC_status(void){

   return ADC_Flag;
            }


u16 ADC_Readvalue(void){
	ADC_Flag=0;
	return ADC_Buffer;
            }


u16 ADC_ReadFullvalue(void){
	return adc_value;
           }

