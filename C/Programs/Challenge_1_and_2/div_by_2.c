#include <stdio.h>

int main() {
    unsigned int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (num & 1) {
        printf("%d is not divisible by 2\n", num);
    } else {
        printf("%d is divisible by 2\n", num);
    }

    return 0;
}
