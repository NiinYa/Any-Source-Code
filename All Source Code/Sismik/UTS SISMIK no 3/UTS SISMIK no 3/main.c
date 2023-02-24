/*
 * UTS SISMIK no 3.c
 *
 * Created: 10/14/2021 11:01:41 AM
 * Author : KyuRinTao
 */ 

#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>
#define LAMPU PORTA
int main(void)
{
	DDRA = 0xFF;
	LAMPU = 0x00;
	while(1)
	{
		LAMPU = 0b00001000; // N = 3
		_delay_ms(1000); 
		LAMPU = 0b00100000; // I = 5
		_delay_ms(1000);
		LAMPU = 0b00000001; // Z = 0
		_delay_ms(1000);
		LAMPU = 0b10000000; // A = 7 
		_delay_ms(1000);
		LAMPU = 0b00000100; // R = 2
		_delay_ms(800);
	}
}
