#include<stdio.h>
int a= 0,b= 1;
int n, temp;
int main()
{
    printf("Number of values: ");
    scanf("%d",&n);

    printf("Fibanocci series of %d is : %d %d", n, a, b);
    temp = a + b;

    for(int i=3; i<=n; ++i)
    {
        printf(" %d", temp);
        a = b;
        b = temp;
        temp = a + b;
        
        
    }
}
