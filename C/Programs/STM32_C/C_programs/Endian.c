#include <stdio.h>

int main() {
    unsigned int num = 0x12345678;
    unsigned char *ptr = (unsigned char *)&num;

    if (*ptr == 0x78) {
        printf("Little Endian\n");
    } else {
        printf("Big Endian\n");
    }

    return 0;
}
