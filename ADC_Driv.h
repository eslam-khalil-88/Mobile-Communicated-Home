/*
 * ADC_Driv.h
 *
 *  Created on: Jul 23, 2017
 *      Author: Solom
 */

#ifndef ADC_DRIV_H_
#define ADC_DRIV_H_

void ADC_init(void);
void ADC_startconv(void);
u8 ADC_status(void);
u16 ADC_Readvalue(void);
u16 ADC_ReadFullvalue(void);


#endif /* ADC_DRIV_H_ */
