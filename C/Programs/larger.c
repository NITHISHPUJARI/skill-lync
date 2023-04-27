#include <stdio.h>


int main()
{
    int a, b, c;
    printf("Enter the 3 values :");
    scanf("%d %d %d", &a, &b, &c);
    if (a > b && b > c)
    printf ("%d is greater than %d and %d ", a, b, c);
    else if (b > a && a > c)
    printf("%d is greater than %d and %d ", b, a, c);
    else printf("%d is greater than %d and %d", c, a, b);

    if (a>b)
    { if (a>c)
    printf ("%d is greater than %d and %d ", a, b, c);
    else printf("%d is greater than %d and %d", c, a, b);}
    else if (b>a)
    printf("%d is greater than %d and %d ", b, a, c);
    else printf("%d is greater than %d and %d", c, a, b);
}
