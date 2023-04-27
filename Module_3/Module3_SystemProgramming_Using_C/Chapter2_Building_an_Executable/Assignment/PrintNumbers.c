#include <stdio.h>
#include <inttypes.h>

extern int64_t MaxCount;

int main() {

    for(int i = 0; i < MaxCount; i++)
    {
        printf("Number : %d\r\n", i);
    }
    return 0;
}