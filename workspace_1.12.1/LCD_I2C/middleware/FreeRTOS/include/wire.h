/*
 * wire.h
 *
 *  Created on: Jun 29, 2023
 *      Author: nithish
 */

#ifndef WIRE_H
#define WIRE_H

#include "stm32g0xx_it.h"

#define I2C_TIMEOUT 1000

void Wire_begin(I2C_HandleTypeDef* hi2c);
void Wire_beginTransmission(uint8_t address);
void Wire_endTransmission(void);
size_t Wire_write(uint8_t data);
void Wire_writeCommand(uint8_t command);
void Wire_writeData(uint8_t data);

#endif /* WIRE_H */

