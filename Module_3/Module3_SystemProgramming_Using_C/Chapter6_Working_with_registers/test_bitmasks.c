#include <stdio.h>

/*
Set single bit at pos to '1' by generating a mask
in the proper bit location and ORing (|) x with the mask.
*/
#define SET_BIT(x, pos) (x |= (1U << pos))

/*
Set single bit at pos to '0' by generating a mask
in the proper bit location and Anding x with the mask.
*/
#define CLEAR_BIT(x, pos) (x &= (~(1U << pos)))

/*
Set single bit at pos to '1' by generating a mask
in the proper bit location and ex-ORing x with the mask.
*/
#define TOGGLE_BIT(x, pos) x ^= (1U << pos)

/*
Set single bit at pos to '1' by generating a mask
in the proper bit location and Anding x with the mask.
It evaluates 1 if a bit is set otherwise 0.
*/
#define CHECK_BIT(x, pos) (x = (x & (1UL << pos)))

// Macro to Get bit from the given position
#define GET_BITS(x, pos) (x = ((x & (1 << pos)) >> pos))

// Print 32 Bit binary representation:
void bin(unsigned n)
{
    unsigned i;
    for (i = 1 << 31; i > 0; i = i / 2)
        (n & i) ? printf("1") : printf("0");

    printf("\r\n");
}

int main()
{

    char a = 0b01010101;
    char temp = a;

    // Get Value a in temp
    temp = a;

    // Set Bit 1:
    printf("Set Bit Pos 1 :\r\n");
    printf("a = \t\t0b");
    bin(a);
    SET_BIT(temp, 1);
    printf("Result = \t0b");
    bin(temp);
    printf("\r\n");

    // Get Value a in temp
    temp = a;

    // Clear Bit 2:
    printf("Clear Bit Pos 2:\r\n");
    printf("a = \t\t0b");
    bin(a);
    CLEAR_BIT(temp, 2);
    printf("Result = \t0b");
    bin(temp);
    printf("\r\n");

    // Get Value a in temp
    temp = a;

    // Toggel Bit Pos 0 :
    printf("Toggel Bit 0:\r\n");
    printf("a = \t\t0b");
    bin(a);
    TOGGLE_BIT(temp, 0);
    printf("Result = \t0b");
    bin(temp);
    printf("\r\n");

    // Get Value a in temp
    temp = a;

    // Check Bit 4:
    printf("Check Bit Pos 4:\r\n");
    printf("a = \t\t0b");
    bin(a);
    CHECK_BIT(temp, 4);
    printf("Result = \t0b");
    bin(temp);
    printf("\r\n");

    // Get Value a in temp
    temp = a;

    // Get  Bit 4:
    printf("Get Bit Pos 4:\r\n");
    printf("a = \t\t0b");
    bin(a);
    // Pass bits start position:
    GET_BITS(temp, 4);
    printf("Result = \t0b");
    bin(temp);
    printf("\r\n");

    return 0;
}