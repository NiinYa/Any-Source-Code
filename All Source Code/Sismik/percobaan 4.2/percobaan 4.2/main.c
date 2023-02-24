#include <avr/io.h>
#include <stdlib.h>
#ifndef F_CPU
#define F_CPU 1000000UL
#endif
#define BAUD 4800
#define BAUDRATE ((F_CPU)/(BAUD*16UL)-1)
void uart_init (void)
{
	UBRRH=(BAUDRATE>>8);
	UBRRL=BAUDRATE;
	UCSRB|=(1<<TXEN)|(1<<RXEN);
	UCSRC|=(1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1);
}
void uart_transmit (unsigned char data)
{
	while (!( UCSRA & (1<<UDRE)));
	UDR = data;
}
unsigned char uart_receive (void)
{
	while(!(UCSRA) & (1<<RXC));
	return UDR;
}
int main (void)
{
	unsigned char a;
	DDRB = 0xFF;
	PORTB = 0xFF;
	uart_init();
	while(1)
	{
		if ((UCSRA & (1<<RXC)) != 0)
		{
			a=uart_receive();
			uart_transmit(a);
			if (a == 'a')
			{
				PORTB = 0x00;
			}
			else if (a == 'b')
			{
				PORTB = 0xFF;
			}
		}
	}
	return 0;
}
