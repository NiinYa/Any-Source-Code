#include <avr/io.h>
#include <stdlib.h>

#ifndef F_CPU
#define F_CPU 1000000UL
#endif
#define LED PORTB
#define LEDDir DDRB
#define BAUD 4800
#define BAUDRATE ((F_CPU)/(BAUD*16UL)-1)

void uart_init (void)
{
	UBRRH=(BAUDRATE>>8);
	UBRRL=BAUDRATE;
	UCSRB|=(1<<TXEN)|(1<<RXEN);
	UCSRC|=(1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1);
}

void ADC_init(void){
	ADMUX |=(0<<REFS1)|(1<<REFS0);
	ADCSRA|=(1<<ADEN)|(1<<ADSC)|(1<<ADPS2)|(1<<ADPS1);
	ADCSRA|=(1<<ADSC);
	while ((ADCSRA & (1<<ADSC)) != 0);
}

int main (void)
{
	DDRA = 0x00;
	PORTA = 0x00;
	LEDDir = 0xFF;
	LED = 0xFF;
	unsigned char a;
	ADC_init();
	uart_init();
	while(1){
		a = ADC;
		ADCSRA |= (1<<ADSC);
		while ((ADCSRA & (1<<ADSC)) != 0);
		LED=ADC;
		if (a != LED){
			UDR = ADC;
		}
	}
	return 0;
}
