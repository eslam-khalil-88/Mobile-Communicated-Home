
#include<avr/io.h>
#include<avr/delay.h>

#include<DIO.h>
#include<LCDFunc.h>

void LCD_INITIALIZATION(void){
	            _delay_ms(40);
				//DDRA=0b00000011;
		        DIO_SETPINDIRECT(4,7,OUTPUT);//RS pin of LCD
		        DIO_SETPINDIRECT(4,6,OUTPUT);//E pin of LCD
		        //DDRC=0b11111111;
		        SET_PORTDIRECTION(3,OUTPUT);

				LCD_sendinst(0x01);
				LCD_sendinst(0x38);
				LCD_sendinst(0x0F);
				LCD_sendinst(0x06);
	            _delay_ms(10);
                    }
void LCD_sendinst(u8 instr){
	            DIO_SETPINDIRECT(4,7,OUTPUT);
	            DIO_SETPINDIRECT(4,6,OUTPUT);
	            DIO_SETPINVALUE(4,7,0);//RS pin of LCD
                //DDRA=0xFF;
	            //CLR_BIT(PORTA,0);
	            PORTC=instr;
                //SET_PORTDIRECTION(3,OUTPUT);
	            //SET_PORTVALUE(3,instr);
	            DIO_SETPINVALUE(4,6,1);//E pin of LCD
	            //SET_BIT(PORTA,1);
	            _delay_ms(1);
	            DIO_SETPINVALUE(4,6,0);
                //CLR_BIT(PORTA,1);
	            _delay_ms(10);

                    }

void LCD_senddata(u8 data){
	            DIO_SETPINDIRECT(4,7,OUTPUT);
	            DIO_SETPINDIRECT(4,6,OUTPUT);
	            DIO_SETPINVALUE(4,7,1);//RS pin of LCD
	            DIO_SETPINVALUE(4,6,1);//E pin of LCD
	            PORTC=data;
                _delay_ms(2);
                DIO_SETPINVALUE(4,6,0);
                _delay_ms(10);
                    }

void CLEAR_DISP(void){
	LCD_sendinst(1);
}


void LCD_PrintNum(u32 num){
	u8 k=0,r=0,len=0;
	u32 n=0;
		u8 ptr[30]={0};
	    n=num;

		do{
			ptr[k]=(n%10)+'0';//Getting ASCII of digit
			k++;
		    }while((n/=10)>0);



		     ptr[k]='\0';//add terminating null at the end of array


		len=strg_len(ptr);
		reverse(len,ptr);

		for(r=0;ptr[r]!='\0';r++){
		    }


	     if(ptr[r]=='\0'){
            r++;
	    	 do{
	    	     LCD_senddata(ptr[r]);
	    	     r++;
	             }while(ptr[r]!='\0');
	       }
	}

u8 DO_OPR(u8 numA,u8 numB,u8 opr){
	switch (opr){
	    case 1:{
	    	return (numA+numB);
	    	break;
	    }
	    case 2:{
	    	return (numA-numB);
	    	break;
	    }
	    case 3:{
	    	return (numA*numB);
	    	break;
	    }
	    default:{

	    	return 0;
	         break;
	            }
	}
     }


u8 strg_len(u8 *p){
	u8 m=0;
	while(*p!='\0'){
		m++;
		p++;
	}
	return m;
    }

void reverse(u8 length,u8 *s){
	 u8 w=0,z=0,q=0;


	    for(w=length,z=0;z<w;w--,z++){
	    	q=*(s+w);
	        *(s+w)=*(s+z);
	        *(s+z)=q;
	    }
}





void LCD_Printfloat(f32 numb){
	u8 k=0,r=0,lenth=0,counter=0;
	u32 n=0;
		u8 ptr[30]={0};
		//numb=(numb * 5) / 1024;
	    //numb *= 10;
	    n=numb;

		do{
			ptr[k]=(n%10)+'0';//Getting ASCII of digit
			k++;
		    }while((n/=10)>0);



		     ptr[k]='\0';//add terminating null at the end of array


		lenth=strg_len(ptr);
		reverse(lenth,ptr);

		for(r=0;ptr[r]!='\0';r++){
		    }


	     if(ptr[r]=='\0'){
            r++;
	    	 do{
	    		 if(counter==0){
	    	     LCD_senddata(ptr[r]);
	    	     LCD_senddata('.');
	    	     r++;
	    	     counter++;
	    		        }
	    		 else{
	    			 LCD_senddata(ptr[r]);
	    			 r++;
	    		     }
	             }while(ptr[r]!='\0');
	       }
	}






/**********************************************/
/*Special Task to print a string on LCD*/
/**********************************************/

/*
void LCDPrint_string(u8 arr[],u8 size){
     u8 x_count=0;//counter to loop through string
     for(x_count=0;arr[x_count]!='\0';x_count++){
    	 LCD_senddata(arr[x_count]);
                             }
                        }                                   */
