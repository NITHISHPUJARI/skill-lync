#include "header.h" // Include common header file
#include <stdio.h>

/**
 * main - Entry Point
 */
int main(void)
{
    red();
    printf("4 + 2 = %d\n", calculator('+', 4, 2));
    yellow();
    printf("4 - 2 = %d\n", calculator('-', 4, 2));
    red();
    printf("4 * 2 = %d\n", calculator('*', 4, 2));
    yellow();
    printf("4 / 2 = %d\n", calculator('/', 4, 2));
    reset();
    return (0);
}