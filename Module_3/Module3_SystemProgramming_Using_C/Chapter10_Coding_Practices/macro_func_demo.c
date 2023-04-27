#include <stdio.h>
// Macro defination to calculate square of argument:
#define SQUARE(x) (x * x)
// Function to calculate the square of argument:
int sqr(int x)
{
    return x * x;
}
int main()
{
    printf("Use of Func : sqr()    - The value of sqr(8+2)   : %d\r\n", sqr(8 + 2));
    printf("Use of Macro: SQUARE() - The value of SQUARE(8+2): %d\r\n", SQUARE(8 + 2));
    return 0;
}