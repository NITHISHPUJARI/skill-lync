#include <stdio.h>
#include <stdlib.h>

/* function to show bytes in memory, from location start to start+n*/
void show_mem_rep(char *start, int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf(" %.2x", start[i]);
    printf("\n");
}

/*Main function to call above function for 0x01234567*/
int main()
{
    int Data = 0x01234567;
    char *startByte = (char*)&Data; // Pointer to First Byte address of int Data
    int NumBytes = sizeof(Data);    // Number of bytes used too store int Data
    printf("int Data = 0x%08X\r\n", Data);

    printf("\r\n    Address\t Data\r\n");
    for (int i = 0; i < NumBytes; i++)
        printf("%p\t 0x%.2X\r\n", (startByte + i), startByte[i]);

    printf("\r\n");

    return 0;
}
