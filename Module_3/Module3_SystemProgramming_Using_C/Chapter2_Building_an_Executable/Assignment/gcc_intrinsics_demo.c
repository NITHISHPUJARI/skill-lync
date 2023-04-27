#include <stdio.h>
#include <stdio.h>

// Print 32 Bit binary representation:
void bin(unsigned n)
{
    unsigned i;
    for (i = 1 << 31; i > 0; i = i / 2)
        (n & i) ? printf("1") : printf("0");

    printf("\r\n");
}

int main() {
    char CpuName[100];
    int n = 16;
    int i = -16;

    // This function returns a positive integer if the run-time CPU is of type cpuname and returns 0 otherwise.
    printf("CPU Is Intel = %d\r\n", __builtin_cpu_is("intel"));

    printf("\r\n");
    printf("Binary of %d  \t= ", n);
    bin(n);
    printf("Binary of %d  \t= ", i);
    bin(i);
    printf("\r\n");

    // This function is used to check the parity of a number. 
    // This function returns true(1) if the number has odd parity else it returns false(0) for even parity. 
    printf("Parity of %d  \t= %d\r\n",n, __builtin_parity(n));
    printf("Parity of %d  \t= %d\r\n",i, __builtin_parity(i));

    // This function is used to count the number of one’s(set bits) in an integer. 
    printf("Count of 1s in binary of %d = %d \r\n", n, __builtin_popcount(n));

    // This function is used to count the leading zeros of the integer. Note : clz = count leading zero’s 
    // Example: It counts number of zeros before the first occurrence of one(set bit). 
    printf("Count of leading zeros before 1 in %d = %d\r\n", n, __builtin_clz(n));

    // This function is used to count the trailing zeros of the given integer. Note : ctz = count trailing zeros. 
    // Example: Count no of zeros from last to first occurrence of one(set bit). 
    printf("Count of zeros from last to first occurrence of one = %d\r\n", __builtin_ctz(n));


    return 0;
}