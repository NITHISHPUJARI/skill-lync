#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Find Fibonacci with Recursion
int fib(int n)
{
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}

int main(int argc, char *argv[])
{
    if(argc < 2){
        printf("insufficient arguments!!\r\n");
        printf("Usage: ./demo_sampleCode <the number of terms>\r\n");
        return 0;
    }
    printf("Print %d-th Fibonacci Number:\r\n", atoi(argv[1]));
    printf("Output : %d\r\n", fib(atoi(argv[1])));

	return 0;
}
