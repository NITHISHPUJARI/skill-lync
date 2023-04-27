/* Compile code With  optimization option */
#include <stdio.h>
int main(void)
{
    const volatile int Data = 10;
    int *ptrData = (int *)&Data;

    printf("Initial value of Data : %d \n", Data);

    *ptrData = 100;

    printf("Modified value of Data: %d \n", Data);

    return 0;
}
