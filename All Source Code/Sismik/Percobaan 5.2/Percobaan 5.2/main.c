#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
#define LCD_Dir DDRB
#define LCD_Port PORTB
#define RS PB0
#define EN PB1
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
void LCD_String_xy (char row, char pos, char *str)
{
	if (row == 0 && pos<16)
	LCD_Command((pos & 0x0F)|0x80);
	else if (row == 1 && pos<16)
	LCD_Command((pos & 0x0F)|0xC0);
	LCD_String(str);
}
void LCD_Clear()
{
	LCD_Command (0x01);
	_delay_ms(2);
	LCD_Command (0x80);
}
int main()
{
	int i;
	LCD_Init();
	LCD_String("Running Text");
	_delay_ms(2000);
	
	char str[]="Running Text";
	int shift = sizeof(str)/sizeof (str[0]);
	
	while(1)
	{
		for(i=0;i<shift;i++)
		{
			LCD_Command(0x1c);
			_delay_ms(500);
		}
		shift=shift+16;
		for(i=0;i<shift;i++)
		{
			LCD_Command(0x18);
			_delay_ms(500);
		}
	}
	return 0;
}
	
	