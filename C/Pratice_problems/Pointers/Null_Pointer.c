// Create Null Pointer, Weak Pointer, Dangling Pointer, Void Pointer, and Smart Pointer examples in C
// This example demonstrates the use of a null pointer in C.

#include <stdio.h>

int main() {
    // Null Pointer
    int *nullPointer = NULL; // Initializing a null pointer
    if (nullPointer == NULL) {
        printf("The pointer is null.\n");
    } else {
        printf("The pointer is not null.\n");
    }

    // Weak Pointer (C does not have built-in weak pointers like C++)
    // In C, we can simulate weak pointers using a pointer that is not owning the resource.
    int *weakPointer = nullPointer; // This is just a copy of the null pointer

    // Dangling Pointer (not recommended to use, but for educational purposes)
    int *danglingPointer;
    {
        int temp = 42;
        danglingPointer = &temp; // danglingPointer now points to a local variable
    }
    // danglingPointer is now dangling since temp's scope has ended

    // Void Pointer
    void *voidPointer = nullPointer; // A void pointer can point to any data type
    if (voidPointer == NULL) {
        printf("The void pointer is also null.\n");
    }

    // Smart Pointer (C does not have smart pointers like C++)
    // We can simulate smart pointer behavior with manual memory management, but it's not idiomatic in C.

    // Print the addresses
    printf("Null Pointer Address: %p\n", (void *)nullPointer);
    printf("Weak Pointer Address: %p\n", (void *)weakPointer);
    printf("Dangling Pointer Address: %p\n", (void *)danglingPointer);
    printf("Void Pointer Address: %p\n", voidPointer);          

    // Attempting to dereference a null pointer (commented out to avoid runtime error)
    // printf("%d\n", *nullPointer); // This would cause undefined behavior

    return 0;
}

// To compile this code, use a C compiler with the C17 standard.
// Example: gcc -std=c17 Null_Pointer.c -o Null_Pointer
// Run the compiled program: ./Null_Pointer
// Note: This code is for educational purposes and should not be used in production without proper checks.  