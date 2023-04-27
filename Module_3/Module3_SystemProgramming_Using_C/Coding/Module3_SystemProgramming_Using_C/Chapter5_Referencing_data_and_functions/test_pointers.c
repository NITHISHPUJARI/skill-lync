#include <stdio.h>

int main()
{
    int myVariable = 85;    // Variable declaration
    int *ptr = &myVariable; // Pointer declaration

    // Print the address of both variables:
    printf("Address of ptr = %p\r\n", &ptr);
    printf("Address of myVariable = %p\r\n", &myVariable);

    // Output the memory address of myVariable with the ptr:
    printf("Value at ptr = %p\r\n", ptr);

    // Output the value stored in myVariable:
    printf("Value at myVariable = %d\r\n", myVariable);

    // Output the value of myVariable with the ptr
    printf("Value at *ptr = %d\r\n", *ptr);
    return 0;
}