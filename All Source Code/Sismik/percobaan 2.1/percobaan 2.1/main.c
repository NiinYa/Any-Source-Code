/*
 * percobaan 2.1.c
 *
 * Created: 9/25/2021 11:39:59 PM
 * Author : KyuRinTao
 */ 

#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>
#include <avr/interrupt.h>

#define LED PORTC
#define LEDDir DDRC
int main(void)
{
	LEDDir = 0xFF;
	LED = 0xFF;
	DDRD = 0x00;
	PORTD = 0xFF;
	while (1)
	{
		LED = 0b00000001; _delay_ms(1000);
		LED = 0b00000010; _delay_ms(1000);
		LED = 0b00000100; _delay_ms(1000);
		LED = 0b00001000; _delay_ms(1000);
		LED = 0b00010000; _delay_ms(1000);
		LED = 0b00100000; _delay_ms(1000);
		LED = 0b01000000; _delay_ms(1000);
		LED = 0b10000000; _delay_ms(1000);
		
		if(PIND == 0b11110111){
			LED = 0xF0; _delay_ms(1000);
		}
	}
}
