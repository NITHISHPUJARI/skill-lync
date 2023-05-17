#include <stdio.h>

int main()
{
    int x = 0x12345678;
    char *ptr = &x;
    for (int i = 0; i < sizeof(x); i++)
    {
        printf("print(%d) = %x\n",i,  ptr[i]);
    }
}