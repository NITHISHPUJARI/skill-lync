#include <avr/io.h>
#include <util/delay.h>

#define BAUDRATE 9600
#define BAUD_PRESCALER ((F_CPU/(BAUDRATE*16UL))-1)

void USART_init(void) {
UBRRH = (uint8_t)(BAUD_PRESCALER>>8);
UBRRL = (uint8_t)(BAUD_PRESCALER);
UCSRB |= (1<<RXEN) | (1<<TXEN);
UCSRC |= (1<<URSEL) | (1<<UCSZ1) | (1<<UCSZ0);
}

unsigned char USART_receive(void) {
while(!(UCSRA & (1<<RXC)));
return UDR;
}

void USART_send(unsigned char data) {
while(!(UCSRA & (1<<UDRE)));
UDR = data;
}

int main(void) {
USART_init();

while(1) {
unsigned char receivedChar = USART_receive();
if(receivedChar >= 'a' && receivedChar <= 'z') {
receivedChar -= 32;
}
USART_send(receivedChar);
}

return 0;
}