#include <stdio.h>
#include <inttypes.h>

int64_t addNumbers(int64_t, int64_t);

int main() {
    printf("1 + 10  = %ld\n", addNumbers(1 , 10));
    printf("3 + 15  = %ld\n", addNumbers(3, 15));
    printf("2 + 3   = %ld\n", addNumbers(2, 3));
    printf("4 + 3   = %ld\n", addNumbers(4, 3));
    printf("2 + 100 = %ld\n", addNumbers(2, 100));
    printf("4 + 6   = %ld\n", addNumbers(4, 6));
    return 0;
}