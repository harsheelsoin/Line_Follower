/*
 * GccApplication7.c
 *
 * Created: 02-12-2013 00:10:09
 *  Author: Sushant
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>

int main(void)
{
	DDRA=0;
	DDRB=255;
	DDRD=255;
	ADCSRA=0b10000111;
	while(1)
	{
		float s[5],t[5]={224.4,139.23,139.23,144.84,216.24}; //{4.4,2.73,2.73,2.84,4.24}x255/5={224.4,139.23,139.23,144.84,216.24}
		ADMUX=0b01100000;
		for (int i=0;i<5;i++)
		{
			ADCSRA=0b11000111;
			while (ADCSRA&(1<<ADSC))
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
		PORTB=0b00000000;
		PORTD=0b10001000;
		break;
		//er
		case 1 :	//0b00001 :
		case 3 :	//0b00011 :
		case 7 :	//0b00111 :
		PORTB=0b00001000;
		PORTD=0b00000100;
		break;
		//l
		case 8 :	//0b01000 :
		case 12 :	//0b01100 :
		PORTB=0b00000000;
		PORTD=0b10000000;
		break;
		//r
		case 6 :	//0b00110 :
		case 2 :	//0b00010 :
		PORTB=0b00000000;
		PORTD=0b00000100;
		break;
		//f
		case 4 :	//0b00100 :
		case 14 :	//0b01110 :
		PORTB=0b00000000;
		PORTD=0b10000100;
		break;
		//f
		default :
		PORTB=0b00000000;
		PORTD=0b10000100;
		break;
		}
	}
	return(0);
}