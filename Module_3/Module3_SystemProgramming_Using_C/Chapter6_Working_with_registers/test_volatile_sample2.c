#include <stdio.h>
#include <signal.h>

volatile int Count = 5;

void handler(int sig)
{
    printf("\r\nIn Interrupt Handler: Count = %d\r\n", Count);
    --Count;
}

int main()
{
    signal(SIGINT, handler);
    while (Count > 0)
    {
        // Loop Expected to run unless:
        // Count > 0
    }
    printf("After Loop: Count = %d\r\n", Count);
    printf("Done!!!\r\n");
    return 0;
}
