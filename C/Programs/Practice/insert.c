#include<stdio.h>

int main()
{
    unsigned long int i;
    int n;
    int arr[n];

    printf("enter the size of array\n");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    scanf("%d", &arr[i]);
    

    for (i=0; i <n; i++)
    {
        if (arr[i] % 2 == 0)
        printf("%d ", arr[i]);
    }
    return 0;
}