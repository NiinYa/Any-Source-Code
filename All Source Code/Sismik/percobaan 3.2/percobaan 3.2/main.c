#include <avr/io.h>
#include <avr/interrupt.h>
int main(void)
{
	// Set Port C sebagai output
	DDRC=0xFF;
	// Mematikan lampu LED pada Port C
	PORTC=0x00;
	// Aktifkan Timer 1 sebagai sumber interupsi
	// Clock source: System Clock
	TCCR1B=0x05;
	// Nilai Counter Pembanding Timer 1B
	TCNT1H=0x00;
	TCNT1L=0x00;
	OCR1BH=0xFF;
	// Timer Overflow Flag akan di clear setelah interupsi jalan
	TIFR= 0x08;
	// Mengaktifkan Output Compare Interrupt di Timer 1B
	TIMSK=0x08;
	// Global enable interrupts
	sei();
	while (1){}

}
// Timer 1 Output Comparator interrupt service routine
ISR (TIMER1_COMPB_vect) {
	// Inisialisasi kembali Nilai Counter Pembanding Timer 1B
	TCNT1H=0x00;
	TCNT1L=0x00;
	OCR1BH=0xFF;
	OCR1BL=0xFF;
	// Cek PIN C
	if (PINC==0) PORTC=0xFF;
	else PORTC=0x00;
}
	

