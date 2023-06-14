/*
 * LCD.cpp
 *
 * Created: 15-05-2023 03:56:12 PM
 * Author : Nithish
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


#define LCD_DATA_PORT PORTB  // LCD data port
#define CTRL_PORT PORTD      // Control port
#define EN PD2               // Enable signal
#define RW PD1               // Read/write signal
#define RS PD0               // Register select signal

void LCD_cmd(unsigned char cmd);
void LCD_init();
void LCD_write(unsigned char data);
void LCD_write_string(const char *str);

int main()
{
	DDRB = 0xFF;            // Set PORTB as output
	DDRD |= (1 << EN) | (1 << RW) | (1 << RS);  // Set EN, RW, RS as output

	LCD_init();             // Initialize the LCD
	_delay_ms(500);          // Delay for stabilization
	

	while (1)
	{
		// Your code here
		LCD_write_string("Hello, World!");  // Print the string on the LCD
		_delay_ms(1000);
		LCD_cmd(0x01);          // Clear the display
		_delay_ms(1000);
	}

	return 0;
}

void LCD_init()
{
	LCD_cmd(0x38);          // Initialize the LCD in 8-bit mode, 2 lines, 5x8 font size
	_delay_ms(1);
	LCD_cmd(0x01);          // Clear the display
	_delay_ms(1);
	LCD_cmd(0x0E);          // Turn on the display, cursor blinking off
	_delay_ms(1);
	LCD_cmd(0x80);          // Set the cursor to the beginning of the first line
	_delay_ms(1);
}

void LCD_cmd(unsigned char cmd)
{
	LCD_DATA_PORT = cmd;    // Assign the command to the data port
	CTRL_PORT &= ~(1 << RS);  // RS = 0 (command mode)
	CTRL_PORT &= ~(1 << RW);  // RW = 0 (write mode)
	CTRL_PORT |= (1 << EN);   // EN = 1
	_delay_us(1);
	CTRL_PORT &= ~(1 << EN);  // EN = 0
	_delay_ms(2);
}

void LCD_write(unsigned char data)
{
	LCD_DATA_PORT = data;   // Assign the data to the data port
	CTRL_PORT |= (1 << RS);  // RS = 1 (data mode)
	CTRL_PORT &= ~(1 << RW); // RW = 0 (write mode)
	CTRL_PORT |= (1 << EN);  // EN = 1
	_delay_us(1);
	CTRL_PORT &= ~(1 << EN); // EN = 0
	_delay_ms(2);
}

void LCD_write_string(const char *str)
{
	while (*str != '\0')
	{
		LCD_write(*str);
		str++;
		
		
		
	}
}

