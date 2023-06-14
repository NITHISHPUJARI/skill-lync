#include <stdio.h>
#include "add.h"

int main() {
    /*printf("Enter the first number to add: ");
    scanf("%d", &a);
    printf("Enter the second number to add: ");
    scanf("%d", &b); */

    int result = add(5, 7);
    printf("The sum of the numbers is: %d\n", result);

    return 0;
}
