#include <stdio.h>

#define DEBUG 1

int main()
{
#if (DEBUG == 0)
    printf("This is Debug Level 0 Message\r\n");
#elif (DEBUG == 1)
    printf("This is Debug Level 1 Message\r\n");
#elif (DEBUG == 2)
    printf("This is Debug Level 2 Message\r\n");
#endif

    return 0;
}