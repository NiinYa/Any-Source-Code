
#include <avr/io.h>
#define F_CPU 1000000UL
#include <avr/interrupt.h>

int HITUNG = -1;

int main(void)
{
	DDRA = 0xFF;
	PORTA = 0x00;
	TCCR0 = 0x05;
	TCNT0 = 0x28;
	TIFR = 0x02;
	TIMSK = 0x01;
	sei();
	while (1){}
}
ISR (TIMER0_OVF_vect) {
	TCNT0=0x28;
	HITUNG++;
	switch(HITUNG)
	{
		case 0:
		PORTA = 0b00001000;
		break;
		case 1:
		PORTA = 0b00100000;
		break;
		case 2:
		PORTA = 0b00000000;
		break;
		case 3:
		PORTA = 0b10000000;
		break;
		case 4:
		PORTA = 0b00000100;
		break;
		default:
		HITUNG = 0;
		PORTA = 0b00000000;
		break;
	}
}
		

