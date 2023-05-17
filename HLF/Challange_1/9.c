#include <avr/io.h>
#include <util/delay.h>

#define F_CPU 8000000UL
#define BAUD 9600
#define UBRR_VALUE (F_CPU/16/BAUD-1)

void USART_Init() {
/* Set baud rate */
UBRRH = (unsigned char)(UBRR_VALUE>>8);
UBRRL = (unsigned char)UBRR_VALUE;
/* Enable receiver and transmitter */
UCSRB = (1<<RXEN)|(1<<TXEN);
/* Set frame format: 8data, 1stop bit */
UCSRC = (1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0);
}

void USART_Transmit(unsigned char data) {
/* Wait for empty transmit buffer */
while (!(UCSRA & (1<<UDRE)));
/* Put data into buffer, sends the data */
UDR = data;
}

int main(void) {
USART_Init();
while (1) {
USART_Transmit('S');
_delay_ms(100);
}
return 0;
}