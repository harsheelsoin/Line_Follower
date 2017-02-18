/*
 * GccApplication4.c
 *
 * Created: 01-12-2013 11:40:42
 *  Author: Sushant
 */ 


#define F_CPU 16000000UL	
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRB=0xff;
	PORTB=0b00001000;
	TCCR0=0b01101001;
	OCR0=0;
    while(1)
    {
		 for (int i=0;i<255;i++)
		 {
			 _delay_ms(15);
			 OCR0++;
		 }
		 for (int i=0;i<=255;i++)
		 {
			 OCR0--;
			 _delay_ms(15);
		 }
		 
    }
}