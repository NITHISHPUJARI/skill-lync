/** Example of Buffer Overflow  **/ 
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char buffer1[5] = "VXYZ";
    char buffer2[5] = "PQRS";
    // The argument is copied into buffer 2 without checking its size.
    // This flaw introduces a buffer overflow vulnerability. 
    strcpy(buffer2, argv[1]);

    printf("buffer1: %s, bufffer2: %s\n", buffer1, buffer2);
    return 0;
}