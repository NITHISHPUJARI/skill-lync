#include<stdio.h>

unsigned long int a[]= {1,2,3,4,5,4,2};

int main()
{
    for(int i = 0; i < sizeof(a)/sizeof(a[0]); i++)
    {
        for (int j = 1; j < sizeof(a)/sizeof(a[0]); j++)
        {
            //long int k = &(a[i] == a[j]);
            if (a[i] == a[j])
            printf("%ld\n", a[i]);
        }
    }
}