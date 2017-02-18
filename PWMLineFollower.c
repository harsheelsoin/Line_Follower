/*
 * GccApplication10.c
 *
 * Created: 02-12-2013 15:26:25
 *  Author: Sushant
 */


#define F_CPU 16000000UL
#include <avr/io.h>


int main(void)
{
	DDRA=0;
	DDRC=255;
	DDRD=255;
	PORTD=0b00110000;
	TCCR1A=0b10100001;
	TCCR1B=0b00001001;
	OCR1AL=0b01111111;
	OCR1BL=0b01111111;
	ADCSRA=0b10000111;
	while(1)
	{
		float s[5],t[5]={224.4,139.23,139.23,144.84,216.24}; //{4.4,2.73,2.73,2.84,4.24}x255/5={224.4,139.23,139.23,144.84,216.24}
		ADMUX=0b01100000;
		for (int i=0;i<5;i++)
		{
			ADCSRA=0b11000111;
			while (ADCSRA&(1<<ADSC)!=0)
			{
			}
			s[i]=ADCH;
			if (s[i]>t[i]) s[i]=1;
			else s[i]=0;
			ADMUX++;
		}
		int in=(s[0]*16)+(s[1]*8)+(s[2]*4)+(s[3]*2)+(s[4]*1);
		switch (in)
		{
			//el
			case 16 :	//0b10000 :
			case 24 :	//0b11000 :
			case 28 :	//0b11100 :
			PORTC=0b00011000;
			break;
			//er
			case 1 :	//0b00001 :
			case 3 :	//0b00011 :
			case 7 :	//0b00111 :
			PORTC=0b00100100;
			break;
			//l
			case 8 :	//0b01000 :
			case 12 :	//0b01100 :
			PORTC=0b00010000;
			break;
			//r
			case 6 :	//0b00110 :
			case 2 :	//0b00010 :
			PORTC=0b00000100;
			break;
			//f
			case 4 :	//0b00100 :
			case 14 :	//0b01110 :
			PORTC=0b00010100;
			break;
			//f
			default :
			PORTC=0b00010100;
			break;
		}
	}
	return(0);
}
