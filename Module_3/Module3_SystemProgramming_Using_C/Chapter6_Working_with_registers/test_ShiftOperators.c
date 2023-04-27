#include<stdio.h>

// Shift Left Lnum number of bit positions:
#define SHIFT_LEFT(x, Lnum) (x << Lnum)

// Shift Right Rnum number of bit positions:
#define SHIFT_RIGHT(x, Rnum) (x >> Rnum)

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
	// a = 5(00000101), b = 9(00001001)
	unsigned char a = 5, b = 9;
	unsigned char result = 0;

	// Left shift a << 1 Pos
	result = SHIFT_LEFT(a, 1);
	printf("a = \t\t0b");
    bin(a);
	printf("a << 1 = \t0b");
	bin(result);
	printf("\r\n");

	// Left shift b << 4 Pos
	result = SHIFT_LEFT(b, 4);
	printf("b = \t\t0b");
    bin(b);
	printf("b << 4 = \t0b");
	bin(result);
	printf("\r\n");

	// Right shift a >> 1 Pos
	result = SHIFT_RIGHT(a, 1);
	printf("a = \t\t0b");
    bin(a);
	printf("a >> 1 = \t0b");
	bin(result);
	printf("\r\n");

	// Right shift b >> 2 Pos
	result = SHIFT_RIGHT(b, 2);
	printf("b = \t\t0b");
    bin(b);
	printf("b >> 2 = \t0b");
	bin(result);
	printf("\r\n");

	return 0;
}
