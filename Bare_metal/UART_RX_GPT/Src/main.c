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

#include "stm32g070xx.h"

void uart_str(char *ptr);
void delay(unsigned int a);

volatile char received_data;

int main()
{
    RCC->IOPENR = (1U << 0);

    GPIOA->MODER |= (1U << 5) | (1U << 7);
    GPIOA->MODER &= ~((1U << 4) | (1U << 6));

    GPIOA->AFR[0] |= (1 << 8) | (1 << 12);

    RCC->APBENR1 |= (1U << 17);
    USART2->BRR = 139;

    // Enable USART2 receive interrupt
    USART2->CR1 = (1U << 2) | (1U << 5) | (1U << 7);
   // NVIC_EnableIRQ(USART2_IRQn); // Enable USART2 interrupt

    while (1)
    {
    	if (USART2->ISR & (1U << 5)) // Check if data is received
    	    {
    	        received_data = USART2->RDR; // Read received data

    	        // Process the received data as needed

    	        // Echo the received data back
    	        while (!(USART2->ISR & (1U << 7))); // Wait until transmit data register is empty
    	        USART2->TDR = received_data;
    	    }
        //uart_str("%d \r\n", received_data);
       // delay(200);
       // uart_str("Embedded\r\n");
       // delay(200);
    }
}


void uart_str(char *ptr)
{
    while (*ptr)
    {
        while (!(USART2->ISR & (1U << 7))); // Wait until transmit data register is empty
        USART2->TDR = (*ptr);
        ptr++;
    }
}

void delay(unsigned int a)
{
    unsigned int i, j;
    for (i = 0; i < a; i++)
        for (j = 0; j < 6000; j++);
}
