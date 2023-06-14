/*
 * UART_TX.c
 *
 * Created: 18-04-2023 04:11:52 PM
 * Author : Nithish
 */ 

#define F_CPU 16000000UL 
#include <avr/io.h> 
#include <util/delay.h>

void USART_Init (unsigned int baud);
int main()
{
	USART_Init (9600);
	UDR='A';
	while(1)
	{
		/* Wait for empty transmit buffer */ 
		while ( ! ( UCSRA & (1<<UDRE)) );
		/* Put data into buffer, sends the data */
		UDR = 'Z';
	}
}

void USART_Init (unsigned int baud){
	/* Set baud rate */
	UBRRH = (unsigned char) (baud>>8) ;
	UBRRL = (unsigned char)baud;
	/* Enable transmitter */
	UCSRB = (1<<TXEN) ;
	/* Set frame format: 8data, 2stop bit */
	UCSRC = (1<<URSEL) | (1<<USBS) | (3<<UCSZ0);}
