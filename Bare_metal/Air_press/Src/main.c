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
#include <stdarg.h>
#include <stdio.h>

/* Include necessary header files */
#include <stdint.h>
#include <math.h>  // Added math.h for pow function

/* Define the base addresses of the peripherals */
#define RCC_BASE_ADDRESS    0x40021000
#define GPIOB_BASE_ADDRESS  0x40010C00
#define I2C1_BASE_ADDRESS   0x40005400

/* Define the register offsets of the peripherals */
#define RCC_AHB1ENR_OFFSET  0x30
#define GPIOB_MODER_OFFSET  0x00
#define GPIOB_ODR_OFFSET    0x14
#define I2C1_CR1_OFFSET     0x00
#define I2C1_CR2_OFFSET     0x04
#define I2C1_OAR1_OFFSET    0x08
#define I2C1_DR_OFFSET      0x10
#define I2C1_SR1_OFFSET     0x14
#define I2C1_SR2_OFFSET     0x18
#define I2C1_CCR_OFFSET     0x1C
#define I2C1_TRISE_OFFSET   0x20

/* Define the bit positions and masks for the register fields */
#define RCC_AHB1ENR_GPIOBEN_BIT    1
#define GPIOB_MODER_MODE6_BIT      12
#define GPIOB_MODER_MODE7_BIT      14
#define GPIOB_ODR_OD7_BIT          7
#define I2C1_CR1_PE_BIT            0
#define I2C1_CR1_START_BIT         8
#define I2C1_CR1_STOP_BIT          9
#define I2C1_CR1_ACK_BIT            10
#define I2C1_SR1_SB_BIT            0
#define I2C1_SR1_ADDR_BIT          1
#define I2C1_SR1_TXE_BIT           7
#define I2C1_SR1_BTF_BIT           2
#define I2C1_SR1_RXNE_BIT          6
#define I2C1_SR2_BUSY_BIT          1

/* Define device addresses and other constants */
#define DEV_ADDR                  0xEE
#define STRT_ADD                  0x88

/* BMP280 calibration data */
#define dig_T1 (*((int16_t*)0x08080088))
#define dig_T2 (*((int16_t*)0x0808008A))
#define dig_T3 (*((int16_t*)0x0808008C))
#define dig_P1 (*((int16_t*)0x0808008E))
#define dig_P2 (*((int16_t*)0x08080090))
#define dig_P3 (*((int16_t*)0x08080092))
#define dig_P4 (*((int16_t*)0x08080094))
#define dig_P5 (*((int16_t*)0x08080096))
#define dig_P6 (*((int16_t*)0x08080098))
#define dig_P7 (*((int16_t*)0x0808009A))
#define dig_P8 (*((int16_t*)0x0808009C))
#define dig_P9 (*((int16_t*)0x0808009E))


/* Declare global variables */
uint8_t deviceid, statusvalue;
uint8_t buff_rx[24], buff_rx1[24], strt_add;
//unsigned short dig_T1, dig_P1;
//signed short dig_T2, dig_T3, dig_P2, dig_P3, dig_P4, dig_P5, dig_P6, dig_P7, dig_P8, dig_P9;

signed long temperature_raw, pressure_raw;
float temperature, pressure, altitude, init_height;

/* Function prototypes */
void I2C_DEVICE_Check(void);
void I2C_DEVICE_Init(void);
void I2C_DEVICE_cali(void);
void BMP280_calc_values(void);
void delay(uint32_t delay);

/* Function to initialize the system clock */
void SystemClock_Config(void)
{
    /* Configure the system clock as desired */
    /* ... */
}

/* Function to initialize GPIO and I2C peripherals */
void Peripherals_Init(void)
{
    /* Enable GPIOB and I2C1 clock */
    *((uint32_t*)(RCC_BASE_ADDRESS + RCC_AHB1ENR_OFFSET)) |= (1 << RCC_AHB1ENR_GPIOBEN_BIT);

    /* Configure PB6 and PB7 as alternate function mode for I2C1 */
    *((uint32_t*)(GPIOB_BASE_ADDRESS + GPIOB_MODER_OFFSET)) &= ~((3 << GPIOB_MODER_MODE6_BIT) | (3 << GPIOB_MODER_MODE7_BIT));
    *((uint32_t*)(GPIOB_BASE_ADDRESS + GPIOB_MODER_OFFSET)) |= ((2 << GPIOB_MODER_MODE6_BIT) | (2 << GPIOB_MODER_MODE7_BIT));

    /* Set GPIO pins 6 and 7 as alternate function mode (I2C1) */
        *((volatile uint32_t*)(GPIOB_BASE_ADDRESS + GPIOB_MODER_OFFSET)) &= ~((3 << (GPIOB_MODER_MODE6_BIT * 2)) | (3 << (GPIOB_MODER_MODE7_BIT * 2)));
        *((volatile uint32_t*)(GPIOB_BASE_ADDRESS + GPIOB_MODER_OFFSET)) |= ((2 << (GPIOB_MODER_MODE6_BIT * 2)) | (2 << (GPIOB_MODER_MODE7_BIT * 2)));

    /* Set the I2C1 timing registers based on desired clock frequency */
    *((uint32_t*)(I2C1_BASE_ADDRESS + I2C1_TRISE_OFFSET)) = 0x09;  /* Recommended value for standard mode */
    *((uint32_t*)(I2C1_BASE_ADDRESS + I2C1_CCR_OFFSET)) = 0x50;    /* Desired clock frequency (100 kHz) */

    /* Enable the I2C1 peripheral */
    *((uint32_t*)(I2C1_BASE_ADDRESS + I2C1_CR1_OFFSET)) |= (1 << I2C1_CR1_PE_BIT);
}

/* Function to initialize the BMP280 sensor */
void BMP280_Init(void)
{
    /* Initialize the I2C device */
    I2C_DEVICE_Init();

    /* Check the presence of the BMP280 sensor */
    I2C_DEVICE_Check();

    /* Perform calibration */
    I2C_DEVICE_cali();
}

/* Function to check the presence of the I2C device */
void I2C_DEVICE_Check(void)
{
    /* Send start condition */
    *((uint32_t*)(I2C1_BASE_ADDRESS + I2C1_CR1_OFFSET)) |= (1 << I2C1_CR1_START_BIT);
    while(!((*((uint32_t*)(I2C1_BASE_ADDRESS + I2C1_SR1_OFFSET))) & (1 << I2C1_SR1_SB_BIT)));

    /* Send device address */
    *((uint32_t*)(I2C1_BASE_ADDRESS + I2C1_DR_OFFSET)) = (DEV_ADDR << 1) | 0x01;
    while(!((*((uint32_t*)(I2C1_BASE_ADDRESS + I2C1_SR1_OFFSET))) & (1 << I2C1_SR1_ADDR_BIT)));
    statusvalue = *((uint32_t*)(I2C1_BASE_ADDRESS + I2C1_SR2_OFFSET));

    /* Send stop condition */
    *((uint32_t*)(I2C1_BASE_ADDRESS + I2C1_CR1_OFFSET)) |= (1 << I2C1_CR1_STOP_BIT);
}

/* Function to initialize the I2C device */
void I2C_DEVICE_Init(void)
{
    /* Configure I2C1 registers */
    *((uint32_t*)(I2C1_BASE_ADDRESS + I2C1_CR1_OFFSET)) = 0x0000;
    *((uint32_t*)(I2C1_BASE_ADDRESS + I2C1_CR2_OFFSET)) = 0x0000;
    *((uint32_t*)(I2C1_BASE_ADDRESS + I2C1_OAR1_OFFSET)) = 0x0000;
}

/* Function to perform calibration */
void I2C_DEVICE_cali(void)
{
    /* Send start condition */
    *((uint32_t*)(I2C1_BASE_ADDRESS + I2C1_CR1_OFFSET)) |= (1 << I2C1_CR1_START_BIT);
    while(!((*((uint32_t*)(I2C1_BASE_ADDRESS + I2C1_SR1_OFFSET))) & (1 << I2C1_SR1_SB_BIT)));

    /* Send device address */
    *((uint32_t*)(I2C1_BASE_ADDRESS + I2C1_DR_OFFSET)) = (DEV_ADDR << 1);
    while(!((*((uint32_t*)(I2C1_BASE_ADDRESS + I2C1_SR1_OFFSET))) & (1 << I2C1_SR1_ADDR_BIT)));
    statusvalue = *((uint32_t*)(I2C1_BASE_ADDRESS + I2C1_SR2_OFFSET));

    /* Send calibration address */
    *((uint32_t*)(I2C1_BASE_ADDRESS + I2C1_DR_OFFSET)) = STRT_ADD;
    while(!((*((uint32_t*)(I2C1_BASE_ADDRESS + I2C1_SR1_OFFSET))) & (1 << I2C1_SR1_TXE_BIT)));

    /* Send repeated start condition */
    *((uint32_t*)(I2C1_BASE_ADDRESS + I2C1_CR1_OFFSET)) |= (1 << I2C1_CR1_START_BIT);
    while(!((*((uint32_t*)(I2C1_BASE_ADDRESS + I2C1_SR1_OFFSET))) & (1 << I2C1_SR1_SB_BIT)));

    /* Send device address for reading */
    *((uint32_t*)(I2C1_BASE_ADDRESS + I2C1_DR_OFFSET)) = (DEV_ADDR << 1) | 0x01;
    while(!((*((uint32_t*)(I2C1_BASE_ADDRESS + I2C1_SR1_OFFSET))) & (1 << I2C1_SR1_ADDR_BIT)));
    statusvalue = *((uint32_t*)(I2C1_BASE_ADDRESS + I2C1_SR2_OFFSET));

    /* Read calibration data */
    for(uint8_t i = 0; i < 24; i++)
    {
        while(!((*((uint32_t*)(I2C1_BASE_ADDRESS + I2C1_SR1_OFFSET))) & (1 << I2C1_SR1_RXNE_BIT)));
        buff_rx[i] = *((uint32_t*)(I2C1_BASE_ADDRESS + I2C1_DR_OFFSET));
    }

    /* Send stop condition */
    *((uint32_t*)(I2C1_BASE_ADDRESS + I2C1_CR1_OFFSET)) |= (1 << I2C1_CR1_STOP_BIT);

    /* Store calibration values */
    dig_T1 = (buff_rx[1] << 8) | buff_rx[0];
    dig_T2 = (buff_rx[3] << 8) | buff_rx[2];
    dig_T3 = (buff_rx[5] << 8) | buff_rx[4];
    dig_P1 = (buff_rx[7] << 8) | buff_rx[6];
    dig_P2 = (buff_rx[9] << 8) | buff_rx[8];
    dig_P3 = (buff_rx[11] << 8) | buff_rx[10];
    dig_P4 = (buff_rx[13] << 8) | buff_rx[12];
    dig_P5 = (buff_rx[15] << 8) | buff_rx[14];
    dig_P6 = (buff_rx[17] << 8) | buff_rx[16];
    dig_P7 = (buff_rx[19] << 8) | buff_rx[18];
    dig_P8 = (buff_rx[21] << 8) | buff_rx[20];
    dig_P9 = (buff_rx[23] << 8) | buff_rx[22];
}

/* Function to calculate temperature, pressure, and altitude values */
void BMP280_calc_values(void)
{

	uint32_t temperature_raw;
	    uint32_t pressure_raw;
	    float pressure;


    /* Read temperature raw data */
    *((uint32_t*)(I2C1_BASE_ADDRESS + I2C1_DR_OFFSET)) = 0xFA;
    while(!((*((uint32_t*)(I2C1_BASE_ADDRESS + I2C1_SR1_OFFSET))) & (1 << I2C1_SR1_TXE_BIT)));

    /* Send repeated start condition */
    *((uint32_t*)(I2C1_BASE_ADDRESS + I2C1_CR1_OFFSET)) |= (1 << I2C1_CR1_START_BIT);
    while(!((*((uint32_t*)(I2C1_BASE_ADDRESS + I2C1_SR1_OFFSET))) & (1 << I2C1_SR1_SB_BIT)));

    /* Send device address for reading */
    *((uint32_t*)(I2C1_BASE_ADDRESS + I2C1_DR_OFFSET)) = (DEV_ADDR << 1) | 0x01;
    while(!((*((uint32_t*)(I2C1_BASE_ADDRESS + I2C1_SR1_OFFSET))) & (1 << I2C1_SR1_ADDR_BIT)));
    statusvalue = *((uint32_t*)(I2C1_BASE_ADDRESS + I2C1_SR2_OFFSET));

    /* Delay for conversion (adjust based on timing requirements) */
        for (int i = 0; i < 1000000; i++)
        {
            asm("nop");
        }

    /* Read temperature raw data */
    while(!((*((uint32_t*)(I2C1_BASE_ADDRESS + I2C1_SR1_OFFSET))) & (1 << I2C1_SR1_RXNE_BIT)));
    temperature_raw = *((uint32_t*)(I2C1_BASE_ADDRESS + I2C1_DR_OFFSET));
    temperature_raw <<= 8;
    temperature_raw |= *((uint32_t*)(I2C1_BASE_ADDRESS + I2C1_DR_OFFSET));
    temperature_raw <<= 8;
    temperature_raw |= *((uint32_t*)(I2C1_BASE_ADDRESS + I2C1_DR_OFFSET));

    /* Send stop condition */
    *((uint32_t*)(I2C1_BASE_ADDRESS + I2C1_CR1_OFFSET)) |= (1 << I2C1_CR1_STOP_BIT);

    /* Read pressure raw data */
    *((uint32_t*)(I2C1_BASE_ADDRESS + I2C1_DR_OFFSET)) = 0xF7;
    while(!((*((uint32_t*)(I2C1_BASE_ADDRESS + I2C1_SR1_OFFSET))) & (1 << I2C1_SR1_TXE_BIT)));

    /* Send repeated start condition */
    *((uint32_t*)(I2C1_BASE_ADDRESS + I2C1_CR1_OFFSET)) |= (1 << I2C1_CR1_START_BIT);
    while(!((*((uint32_t*)(I2C1_BASE_ADDRESS + I2C1_SR1_OFFSET))) & (1 << I2C1_SR1_SB_BIT)));

    /* Send device address for reading */
    *((uint32_t*)(I2C1_BASE_ADDRESS + I2C1_DR_OFFSET)) = (DEV_ADDR << 1) | 0x01;
    while(!((*((uint32_t*)(I2C1_BASE_ADDRESS + I2C1_SR1_OFFSET))) & (1 << I2C1_SR1_ADDR_BIT)));
    statusvalue = *((uint32_t*)(I2C1_BASE_ADDRESS + I2C1_SR2_OFFSET));

    /* Read pressure raw data */
    while(!((*((uint32_t*)(I2C1_BASE_ADDRESS + I2C1_SR1_OFFSET))) & (1 << I2C1_SR1_RXNE_BIT)));
    pressure_raw = *((uint32_t*)(I2C1_BASE_ADDRESS + I2C1_DR_OFFSET));
    pressure_raw <<= 8;
    pressure_raw |= *((uint32_t*)(I2C1_BASE_ADDRESS + I2C1_DR_OFFSET));
    pressure_raw <<= 8;
    pressure_raw |= *((uint32_t*)(I2C1_BASE_ADDRESS + I2C1_DR_OFFSET));

    /* Send stop condition */
    *((uint32_t*)(I2C1_BASE_ADDRESS + I2C1_CR1_OFFSET)) |= (1 << I2C1_CR1_STOP_BIT);

    /* Calculate temperature in degrees Celsius */
    int32_t var1, var2;
    var1 = ((((temperature_raw >> 3) - ((int32_t)dig_T1 << 1))) * ((int32_t)dig_T2)) >> 11;
    var2 = (((((temperature_raw >> 4) - ((int32_t)dig_T1)) * ((temperature_raw >> 4) - ((int32_t)dig_T1))) >> 12) *
            ((int32_t)dig_T3)) >> 14;
    int32_t t_fine = var1 + var2;
    temperature = (float)((t_fine * 5 + 128) >> 8) / 100.0;

    /* Calculate pressure in Pa */
    int64_t var3, var4, var5 ;//var6, var7;
    var3 = ((int64_t)t_fine) - 128000;
    var4 = var3 * var3 * (int64_t)dig_P6;
    var4 = var4 + ((var3 * (int64_t)dig_P5) << 17);
    var4 = var4 + (((int64_t)dig_P4) << 35);
    var3 = ((var3 * var3 * (int64_t)dig_P3) >> 8) + ((var3 * (int64_t)dig_P2) << 12);
    var3 = (((((int64_t)1) << 47) + var3)) * ((int64_t)dig_P1) >> 33;
    if(var3 == 0)
    {
        pressure = 0;
    }
    else
    {
        var5 = 1048576 - pressure_raw;
        var5 = ((var5 << 31) - var4) * 3125 / var3;
        var3 = ((int64_t)dig_P9 * (var5 >> 13) * (var5 >> 13)) >> 25;
        var4 = ((int64_t)dig_P8 * var5) >> 19;
        var5 = ((var5 + var3 + var4) >> 8) + (((int64_t)dig_P7) << 4);
        pressure = (float)var5 / 256.0;
    }

    /* Calculate altitude in meters */
    float init_height = 0.0;  // Default initialization value
    altitude = 44330 * (1 - pow((double)(pressure / 1013.25), 0.1903)) + init_height;


}

/* Function to introduce delay */
void delay(uint32_t delay)
{
    for(uint32_t i = 0; i < delay; i++);
}

int main(void)
{
    /* Initialize the system clock */
    SystemClock_Config();

    /* Initialize the GPIO and I2C peripherals */
    Peripherals_Init();

    /* Initialize the BMP280 sensor */
    BMP280_Init();

    /* Set initial height */
    init_height = 0;

    while(1)
    {
        /* Calculate temperature, pressure, and altitude values */
        BMP280_calc_values();

        /* Delay before next calculation */
                for (int i = 0; i < 1000000; i++)
                {
                    asm("nop");
                }
    }
}