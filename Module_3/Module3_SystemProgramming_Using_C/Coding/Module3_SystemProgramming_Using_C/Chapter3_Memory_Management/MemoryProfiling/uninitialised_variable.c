// gcc -g uninitialised_variable.c -o uninitialised_variable
// valgrind --track-origins=yes ./uninitialised_variable
#include <stdlib.h>
#include <stdio.h>
int main()
{
    // Should be initialized (i.e. to zero).
    int number;
    if (number == 0)
    {
        printf("number is zero");
    }

    return 0;
}
