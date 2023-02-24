#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>
#include <avr/interrupt.h>
int main(void)
{
	DDRC=0xFF;
	PORTC=0x00;
	TCCR0=0x03;
	TIFR=0x02;
	TIMSK=0x01;
	sei();
	while (1){}
}
ISR (TIMER0_OVF_vect) {
	if (PINC==0)
	{
		PORTC=0xFF;
	}
	else PORTC=0x00;
}