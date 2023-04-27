#include <stdio.h>

int main()
{

    unsigned int a = 60; /* 60 = 0011 1100 */
    unsigned int b = 13; /* 13 = 0000 1101 */
    int c = 0;

    printf("a = %d\r\n", a);
    printf("b = %d\r\n\r\n", b);
    c = a & b; /* 12 = 0000 1100 */
    printf("AND:\t a & b = %d\r\n", c);

    c = a | b; /* 61 = 0011 1101 */
    printf("OR:\t a | b = %d\r\n", c);

    c = a ^ b; /* 49 = 0011 0001 */
    printf("XOR:\t a ^ b = %d\r\n", c);

    c = ~a; /*-61 = 1100 0011 */
    printf("One's Compliment: ~a = %d\r\n", c);

    c = a << 2; /* 240 = 1111 0000 */
    printf("Left Shift: a << 2 = %d\r\n", c);

    c = a >> 2; /* 15 = 0000 1111 */
    printf("Right Shift: a >> 2 = %d\r\n", c);

    return 0;
}