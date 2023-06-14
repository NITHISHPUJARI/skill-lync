/*
 * UART_RX.c
 *
 * Created: 18-04-2023 05:13:02 PM
 * Author : Nithish
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

void USART_Init (unsigned int baud){
	/* Set baud rate */
	UBRRH = (unsigned char) (baud>>8) ;
	UBRRL = (unsigned char)baud;
	/* Enable transmitter */
	UCSRB = (1<<RXEN)|(1<<TXEN) ;
	/* Set frame format: 8data, 2stop bit */
UCSRC = (1<<URSEL) | (1<<USBS) | (3<<UCSZ0);}

int  main()
{
	
	USART_Init (9600);
	unsigned char buffer;
	while(1)
	{
		while (! (UCSRA & (1 <<RXC)));
		buffer = UDR;
		//led data(buffer);
		while(! (UCSRA& (1<<5)));
		UDR=buffer;
		_delay_ms(10);
	}
}
