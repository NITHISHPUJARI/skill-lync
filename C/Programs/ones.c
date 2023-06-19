#include <stdio.h>

int main()
{
    int n, count =0;
    printf("Enter the Value of n: ");
    scanf("%d", &n);
    
    for(int i = 0; i<=n; i++)
    {
        int temp = i;
        while (temp > 0)
        {
            if(temp %10 == 1)
            {
                count++;
            }
            temp = temp/10;
        }
    }
    
    printf("Number of 1's present in the %d is: %d\n", n, count);
}