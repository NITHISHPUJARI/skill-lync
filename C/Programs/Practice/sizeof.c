#include<stdio.h>

int main()
{
    unsigned long int a[]={2,2,3,4,5,6,7,8,9, 0, 6, 7, 4, 8, 4 , 8, 9 ,9999 , 7 , 8 , 8, 8 , 4 , 6 , 8 , 8 , 8 , 8};

    printf("size of array: %ld\n", sizeof(a)/sizeof(a[0]));
}