#include <stdio.h>
#include <arpa/inet.h>
int main() {
    int i;
    int Value = 0x0100A8C0; // Value
    unsigned char *ptr1 = (char *) &Value; // Byte pointer

    /* Value in host byte order */
    printf("Value in hex: 0x%02X\r\n", Value);
    printf("Value by bytes: ");

    for (i=0; i < sizeof(long); i++)
        printf("%02X\t", ptr1[i]);
    printf("\r\n");

    /* Value in network byte order */
    Value = htonl(Value);
    printf("\r\nAfter htonl()\r\n");
    printf("Value in hex: 0x%02X\r\n", Value);
    printf("Value by bytes: ");

    for (i=0; i < sizeof(long); i++)
        printf("%02X\t", ptr1[i]);
    printf("\r\n");

    return 0;
}