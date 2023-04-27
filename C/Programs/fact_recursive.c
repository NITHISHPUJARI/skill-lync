#include <stdio.h>

int factorial(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}

int main()
{
    int n;
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    if (n < 0)
    {
        printf("Error: factorial of a negative integer does not exist.");
    }
    else
    {
        int result = factorial(n);
        printf("%d! = %d", n, result);
    }
    return 0;
}
