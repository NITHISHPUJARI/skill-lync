/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */


#include <stm32g070xx.h>

void delay(unsigned int a);
int main()
{
	RCC->IOPENR = (1<<0);
	GPIOA->MODER |= (1<<10);
	GPIOA->MODER &= ~(1<<11);

	while(1)
	{
		GPIOA->ODR |= (1<<5);
		delay(1000);
		GPIOA->ODR &= ~(1<<5);
		delay(1000);
	}

}

void delay(unsigned int a)
{
	unsigned int i,j;
	for(i =0; i<a; i++)
		for (j = 0; j<1000; j++);
}