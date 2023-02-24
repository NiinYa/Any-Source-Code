#include <avr/io.h>
void ADC_init(void)
{
	ADMUX |= (0<<REFS1) | (1<<REFS0);
	ADCSRA |= (1<<ADEN) | (1<<ADSC) | (1<<ADPS2) | (1<<ADPS1);
	ADCSRA |= (1<<ADSC);
	while ((ADCSRA & (1<<ADSC)) != 0);
}
int main(void)
{
	DDRA = 0x00;
	PORTA = 0x00;
	DDRB = 0xFF;
	PORTB = 0xFF;
	ADC_init();
	while (1)
	{
		ADCSRA |= (1<<ADSC);
		while ((ADCSRA & (1<<ADSC)) != 0);
		PORTB = ~ADC;
	}
}

