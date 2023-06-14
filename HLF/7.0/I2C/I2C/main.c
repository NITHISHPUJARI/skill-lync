/*
 * I2C.c
 *
 * Created: 19-04-2023 02:31:07 PM
 * Author : Nithish
 */ 


#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

void I2c_Start()
{
	TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
	while ((TWCR & (1 << TWINT)) == 0);
}

void I2C_Stop()
{
	TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTO);
}

void I2C_Write(unsigned char data)
{
	TWDR = data;
	TWCR = (1 << TWINT) | (1 << TWEN);
	while ((TWCR & (1 << TWINT)) == 0);
}

void I2C_Init()
{
	TWSR = 0x00;
	TWBR = 0x48;
	TWCR = (1 << TWEN);
}

int main(void)
{
	I2C_Init();
	I2c_Start();
	
	I2C_Write('a');
    /* Replace with your application code */
    while (1) 
    I2C_Stop();
}

