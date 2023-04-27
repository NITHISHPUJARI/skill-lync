#include <stdio.h>

int main() {
    unsigned int num, flipped_num;
    int bit_pos;

    printf("Enter a number: ");
    scanf("%u", &num);

    printf("Enter the bit position to flip (0-31): ");
    scanf("%d", &bit_pos);

    flipped_num = num ^ (1 << bit_pos);

    printf("Original number: %u\n", num);
    printf("Flipped number: %u\n", flipped_num);

    return 0;
}
