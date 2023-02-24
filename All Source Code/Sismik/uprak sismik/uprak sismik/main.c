#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>

#define LCD_Dir DDRB
#define LCD_Port PORTB
#define RS PB0
#define EN PB1

#define BAUD 4800
#define BAUDRATE ((F_CPU)/(BAUD*16UL)-1)

void LCD_Command( unsigned char cmnd )
{
	LCD_Port = (LCD_Port & 0x0F) | (cmnd & 0xF0);
	LCD_Port &= ~ (1<<RS);
	LCD_Port |= (1<<EN);
	_delay_us(1);
	LCD_Port &= ~ (1<<EN);
	_delay_us(200);
	LCD_Port = (LCD_Port & 0x0F) | (cmnd << 4);
	LCD_Port |= (1<<EN);
	_delay_us(1);
	LCD_Port &= ~ (1<<EN);
	_delay_ms(2);
}
void LCD_Char( unsigned char data )
{
	LCD_Port = (LCD_Port & 0x0F) | (data & 0xF0);
	LCD_Port |= (1<<RS);
	LCD_Port|= (1<<EN);
	_delay_us(1);
	LCD_Port &= ~ (1<<EN);
	_delay_us(200);
	LCD_Port = (LCD_Port & 0x0F) | (data << 4);
	LCD_Port |= (1<<EN);
	_delay_us(1);
	LCD_Port &= ~ (1<<EN);
	_delay_ms(2);
}
void LCD_Init (void)
{
	LCD_Dir = 0xFF;
	_delay_ms(20);
	LCD_Command(0x02);
	LCD_Command(0x28);
	LCD_Command(0x0c);
	LCD_Command(0x06);
	LCD_Command(0x01);
	_delay_ms(2);
}
void LCD_String (const char *str)
{
	int i;
	for(i=0;str[i]!=0;i++)
	{
		LCD_Char (str[i]);
	}
}

void LCD_Clear()
{
	LCD_Command (0x01);
	_delay_ms(2);
	LCD_Command (0x80);
}

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

int main()
{
	LCD_Init();
	uart_init();
	char a;
	char b;
	LCD_String("UAP SISMIK");
	_delay_ms(2000);
	LCD_Clear();
	LCD_String("AkhmmadNizar");
	LCD_Command(0xC0);
	LCD_String("205150300111040");
	_delay_ms(2500);
	LCD_Clear();
	LCD_String("INPUT CHARACTER");
	while(1)
	{
		if ((UCSRA & (1<<RXC)) != 0)
		{
			a=uart_receive();
			uart_transmit(a);
			a= b;
	LCD_String(b);
}
	}
}
