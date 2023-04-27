// Predict the Output of the following program with Fork() system call:
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    // Fork system call
    if (fork() == 0)
        // child process because return value zero
        printf("Hello from Child!\n");
    else
        // parent process because return value non-zero.
        printf("Hello from Parent!\n");
    return 0;
}
