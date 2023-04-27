#include <stdio.h>

int main() {
    unsigned int num, temp;
    int ones = 0, zeros = 0;

    printf("Enter a number: ");
    scanf("%d", &num);

    temp = num;

    while (temp > 0) {
        if (temp & 1) {
            ones++;
        } else {
            zeros++;
        }
        temp >>= 1;
    }

    printf("Number of ones in %d: %d\n", num, ones);
    printf("Number of zeros in %d: %d\n", num, zeros);

    return 0;
}
