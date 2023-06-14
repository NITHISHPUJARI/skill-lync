/*
 * led_on.c
 *
 * Created: 17-04-2023 05:18:03 PM
 * Author : Nithish
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>



int main(void)
{
	DDRB |= (170<<0);
	
    /* Replace with your application code */
    while (1) 
    {
		PORTB |= (170<<0);
		_delay_ms(1000);
		PORTB &= ~(170<<0);
		_delay_ms(1000);
    }
}

