#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>
#include <avr/interrupt.h>
int main(void)
{
	DDRC=0xFF;
	PORTC=0x00;
	DDRB=0x00;
	PORTB=0xFF;
	TCCR1B=0x06;
	TCNT1H=0xFF;
	TCNT1L=0xFE;

	TIFR=(1<<TOV1);
	TIMSK=(1<<TOIE1);
	sei();
	while (1){}
}
ISR (TIMER1_OVF_vect) {
	TCNT1H=0xFF;
	TCNT1L=0xFE;

	if (PINC==0) PORTC=0xFF;
	else PORTC=0x00;
}
