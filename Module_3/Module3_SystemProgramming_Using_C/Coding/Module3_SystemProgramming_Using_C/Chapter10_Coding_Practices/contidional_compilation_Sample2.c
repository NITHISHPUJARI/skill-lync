#include <stdio.h>

#define DEBUG 0

int main()
{
#if DEBUG
    printf("This is not printed\r\n");
#endif
    printf("This is printed\r\n");
    return 0;
}