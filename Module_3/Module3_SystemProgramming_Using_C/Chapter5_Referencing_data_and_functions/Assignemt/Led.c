///
/// \file 				Led.c

#include "serial_print.h"

void Led_Init() {
    serial_puts("Led_Init()\r\n\0");
}

void Led_On() {
    serial_puts("LED ON\r\n\0");
}

void Led_Off() {
    serial_puts("LED OFF\r\n\0");
}

void Led_Idle() {
    serial_puts("LED IDLE\r\n\0");
}