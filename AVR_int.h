
#ifndef AVR_INT_H_
#define AVR_INT_H_


#define EEARH   (*(volatile u8 *)(0X1F))
#define EEARL   (*(volatile u8 *)(0X1E))
#define EEDR   (*(volatile u8 *)(0X1D))
#define EECR  (*(volatile u8 *)(0X1C))



#define DDRD (*(volatile u8 *)(0X11))
#define PIND (*(volatile u8 *)(0X10))
#define PORTD (*(volatile u8 *)(0X12))

#define DDRA  (*(volatile u8 *)(0X1A))
#define PINA  (*(volatile u8 *)(0X19))
#define PORTA  (*(volatile u8 *)(0X1B))

#define DDRB  (*(volatile u8 *)(0X17))
#define PINB  (*(volatile u8 *)(0X16))
#define PORTB  (*(volatile u8 *)(0X18))

#define DDRC  (*(volatile u8 *)(0X14))
#define PINC  (*(volatile u8 *)(0X13))
#define PORTC  (*(volatile u8 *)(0X15))

#define SFIOR (*(volatile u8 *)(0X30))
#define SREG  (*(volatile u8 *)(0X3F))
#define TIMSK  (*(volatile u8 *)(0X39))
#define TIFR  (*(volatile u8 *)(0X38))
#define GICR  (*(volatile u8 *)(0X3B))
#define GIFR  (*(volatile u8 *)(0X3A))
#define MCUCR  (*(volatile u8 *)(0X35))
#define MCUCSR  (*(volatile u8 *)(0X34))

#define TCCR0  (*(volatile u8 *)(0X33))
#define TCNT0  (*(volatile u8 *)(0X32))
#define OCR0   (*(volatile u8 *)(0x3C))

#define TCCR1A (*(volatile u8 *)(0X2F))
#define TCCR1B (*(volatile u8 *)(0X2E))
#define TCNT1H (*(volatile u8 *)(0X2D))
#define TCNT1L (*(volatile u8 *)(0X2C))
#define OCR1AH (*(volatile u8 *)(0X2B))
#define OCR1AL  (*(volatile u8 *)(0X2A))
#define OCR1BH (*(volatile u8 *)(0X29))
#define OCR1BL  (*(volatile u8 *)(0X28))
#define ICR1H   (*(volatile u8 *)(0X27))
#define ICR1L  (*(volatile u8 *)(0X26))
#define TCCR2  (*(volatile u8 *)(0X25))
#define TCNT2  (*(volatile u8 *)(0X24))
#define OCR2 (*(volatile u8 *)(0X23))


#define UDR  (*(volatile u8 *)(0X0C))
#define UCSRA  (*(volatile u8 *)(0X0B))
#define UCSRB  (*(volatile u8 *)(0X0A))
#define UBRRL  (*(volatile u8 *)(0X09))

#define ACSR  (*(volatile u8 *)(0X08))
#define ADMUX  (*(volatile u8 *)(0X07))
#define ADCSRA  (*(volatile u8 *)(0X06))
#define ADCH  (*(volatile u8 *)(0X05))
#define ADCL (*(volatile u8 *)(0X04))


#define TWDR   (*(volatile u8 *)(0X03))
#define TWAR   (*(volatile u8 *)(0X02))
#define TWSR   (*(volatile u8 *)(0X01))
#define TWBR   (*(volatile u8 *)(0X00))

#define SPH   (*(volatile u8 *)(0X3E))
#define SPL   (*(volatile u8 *)(0X3D))
#define SPMCR   (*(volatile u8 *)(0X37))
#define SPDR  (*(volatile u8 *)(0X0F))
#define SPSR  (*(volatile u8 *)(0X0E))
#define SPCR  (*(volatile u8 *)(0X0D))
#define TWCR  (*(volatile u8 *)(0X36))

#define ASSR  (*(volatile u8 *)(0X22))
#define WDTCR  (*(volatile u8 *)(0X21))

#endif /* AVR_IO_H_ */
