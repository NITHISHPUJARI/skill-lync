/*
 * SPI.c
 *
 * Created: 18-04-2023 05:40:22 PM
 * Author : Nithish
 */ 

#define F_CPU 16000000UL 
#include <avr/io.h> 
#include <util/delay.h>
// #include "uart _header.h"
//#include "Icd header.h" 
#define MOSI 5
#define SCK 7
#define SS 4

int main(void)
{
	//DDRB&=~ (1<<4);
	DDRB|= (1<< MOSI) | (1<<SCK); //PB5, PB7
	SPCR=(1<<SPE) | (1<<MSTR) | (1<<SPR0) ; 
	//ENABLE SPI MASTER //led_init();
	//UART_init(9600);
	
	while (1)
	{
		SPDR=0b10111100;//load data
		while(!(SPSR&(1<<SPIF)));//WAIT TO FINISH
		//uint8_t val=SPDR;
	}
}
