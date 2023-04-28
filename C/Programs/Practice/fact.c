#include<stdio.h>

int n, fact =1;
int main()
{
    printf("Enter the factorial number : ");
    scanf("%d",&n);

    for(int i=1; i<=n; i++)
    {
        fact = fact*i;
    }
    printf("The factorial of %d is : %d", n, fact);
}