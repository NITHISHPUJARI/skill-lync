#include <stdio.h>

int main() {
    int num, n, bit;

    printf("Enter a number: ");
    scanf("%d", &num);
    printf("Enter bit position to get (0-31): ");
    scanf("%d", &n);

    bit = (num >> n) & 1;
    printf("The %dth bit of %d is %d\n", n, num, bit);

    return 0;
}
