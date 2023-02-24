#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define LCD_Dir DDRB
#define LCD_Port PORTB
#define RS PB0
#define EN PB1

void LCD_Command(unsigned char cmnd)
{
	LCD_Port = (LCD_Port & 0x0F) | (cmnd & 0xF0);
	LCD_Port &= ~(1<<RS);
	LCD_Port |= (1<<EN);
	_delay_us(1);
	LCD_Port &= ~(1<<EN);
	_delay_us(200);
	
	LCD_Port = (LCD_Port & 0x0F) | (cmnd<<4);
	LCD_Port |= (1<<EN);
	_delay_us(1);
	LCD_Port &= ~(1<<EN);
	_delay_ms(2);
}

void LCD_Char(unsigned char data)
{
	LCD_Port = (LCD_Port & 0x0F) | (data & 0xF0);
	LCD_Port |= (1<<RS);
	LCD_Port |= (1<<EN);
	_delay_us(1);
	LCD_Port &= ~(1<<EN);
	_delay_us(200);
	
	LCD_Port = (LCD_Port & 0x0F) | (data<<4);
	LCD_Port |= (1<<EN);
	_delay_us(1);
	LCD_Port &= ~(1<<EN);
	_delay_ms(2);
}

void LCD_Init()
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

void LCD_String(char *str)
{
	int i;
	for(i=0;str[i]!=0;i++)
	{
		LCD_Char(str[i]);
	}
}

void LCD_String_xy(char row, char pos, char *str)
{
	if(row == 0 && pos < 16)
	LCD_Command((pos & 0x0F) | 0x80);
	else  if(row == 1 && pos < 16)
	LCD_Command((pos & 0x0F) | 0xC0);
	LCD_String(str);
}

void LCD_Clear()
{
	LCD_Command(0x01);
	_delay_ms(2);
	LCD_Command(0x80);
}

char str[] = "tes 1 2 3";
int shift = sizeof(str) - 1;
int a;

int main()
{
	DDRD = 0x00;
	PORTD = 0xFF;
	GICR = 1<<INT0 | 1<<INT1;
	MCUCR = 1<<ISC01 | 1<<ISC00 | 1<<ISC10 | 1<<ISC11;
	sei();
	
	LCD_Init();
	LCD_String(str);
	_delay_ms(2000);
	
	int i;
	while(1)
	{
		*(&a) = 0;
		for(i=0;i<*(&shift);i++)
		{
			if(a == 0)
			{
				LCD_Command(0x1c);
				_delay_ms(100);
			}
			else break;
		}
		if(shift <= 16)
		{
			*(&shift) += 16;
		}
		for(i=0;i<*(&shift);i++)
		{
			if(a == 0){
				LCD_Command(0x18);
				_delay_ms(100);
			}
			else break;
		}
	}
	return 0;
}

ISR(INT0_vect)
{
	char isi1[] = "ini tulisan";
	*(&shift) = sizeof(isi1) - 1;
	LCD_Clear();
	LCD_String(isi1);
	_delay_ms(2000);
	*(&a) = 1;
}

ISR(INT1_vect)
{
	char isi2[] = "tulisan lagi";
	*(&shift) = sizeof(isi2) - 1;
	LCD_Clear();
	LCD_String(isi2);
	_delay_ms(2000);
	*(&a) = 1;
}
