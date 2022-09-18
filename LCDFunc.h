/*
 * LCDFunc.h
 *
 *  Created on: May 28, 2017
 *      Author: Solom
 */

#ifndef LCDFUNC_H_
#define LCDFUNC_H_

void LCD_INITIALIZATION(void);
void LCD_sendinst(u8 instr);
void LCD_senddata(u8 data);
void CLEAR_DISP(void);
void LCD_PrintNum(u32 num);
u8 DO_OPR(u8 numA,u8 numB,u8 opr);
void reverse(u8 length,u8 *s);
u8 strg_len(u8 *p);
void LCD_Printfloat(f32 numb);
//void LCDPrint_string(u8 arr[],u8 size);
#endif /* LCDFUNC_H_ */
