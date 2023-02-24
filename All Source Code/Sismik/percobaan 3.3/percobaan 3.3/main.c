#include <avr/io.h>
#include <avr/interrupt.h>
int main(void)
{
	// Set Port C sebagai output
	DDRC=0xFF;
	// Set Port C sebagai output Active Low
	PORTC=0x00;
	// Set Port B sebagai input (T0 adalah PB0)
	DDRB=0x00;
	PORTB=0xFF;
	// Aktifkan Timer 0 sebagai interupsi trigger eksternal
	TCCR0=0x06;
	// Nilai Counter Pembanding Timer 0
	TCNT0=0xFC;
	OCR0=0x00;
	// Timer Overflow Flag akan di clear setelah interupsi jalan
	TIFR= 0x02;
	// Mengaktifkan Output Compare Interrupt di Timer 0
	TIMSK=0x02;
	// Global enable interrupts
	sei();
	while (1){}
}
// Timer 0 Output Comparator interrupt service routine
ISR (TIMER0_COMP_vect) {
	// Inisialisasi kembali Nilai Counter Pembanding Timer 0
	TCNT0=0xFC;
	OCR0=0x00;
	// Cek PIN C
	if (PINC==0) PORTC=0xFF;
	else PORTC=0x00;
}