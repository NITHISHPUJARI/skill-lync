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

#include "stm32g0xx.h"

void EXTI4_15_IRQHandler(void);

int main(void) {
  // Enable GPIOA, GPIOB, GPIOC peripherals
  RCC->IOPENR |= RCC_IOPENR_GPIOAEN | RCC_IOPENR_GPIOBEN | RCC_IOPENR_GPIOCEN;

  // Configure internal LED (PA5) as output
  GPIOA->MODER &= ~GPIO_MODER_MODE5_Msk;
  GPIOA->MODER |= GPIO_MODER_MODE5_0;

  // Configure external LED (PB14) as output
  GPIOB->MODER &= ~GPIO_MODER_MODE14_Msk;
  GPIOB->MODER |= GPIO_MODER_MODE14_0;

  // Configure user switch (PC13) as input with pull-up
  GPIOC->MODER &= ~GPIO_MODER_MODE13_Msk;
  GPIOC->PUPDR &= ~GPIO_PUPDR_PUPD13_Msk;
  GPIOC->PUPDR |= GPIO_PUPDR_PUPD13_0;

  // Enable SYSCFG peripheral
  RCC->APBENR2 |= RCC_APBENR2_SYSCFGEN;

  // Configure EXTI line 13 (connected to PC13) for rising edge trigger
  EXTI->RTSR1 |= EXTI_RTSR1_RT13;
  EXTI->FTSR1 &= ~EXTI_FTSR1_FT13;

  // Enable EXTI line 13 interrupt
  EXTI->IMR1 |= EXTI_IMR1_IM13;

  while (1) {
    // Toggle internal LED (PA5)
    GPIOA->ODR ^= GPIO_ODR_OD5;

    // Delay for some time
    for (volatile uint32_t i = 0; i < 1000000; ++i) {
      // Delay loop
    }
  }
}

void EXTI4_15_IRQHandler(void) {
  if (EXTI->RPR1 & EXTI_RPR1_RPIF13) {
    // Clear the pending interrupt flag for EXTI line 13
    EXTI->RPR1 = EXTI_RPR1_RPIF13;

    // Toggle external LED (PB14)
    GPIOB->ODR ^= GPIO_ODR_OD14;

    // Disable EXTI line 13 interrupt
    EXTI->IMR1 &= ~EXTI_IMR1_IM13;
  }
}