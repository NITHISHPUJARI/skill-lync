#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

long long solve(int N, int *a)
{
 
    //Write your code here
    
    int sum = 0, N_sum= 0;
    for (int i = 0; i < N-1; i++)
    {
        for(int j = 1; j < N; j++)
        {
        if (a[i] > a[j]) 
        {
            a[i] = a[j];
        }
        }
      N_sum += a[i];
      sum = N_sum+ a[N-1];
    }
    
    
return sum;
}
 
int main()
{
int T;
scanf ("%d",&T);
for(int t_i = 0; t_i < T; t_i++)
{
int N;
scanf("%d",&N);
int i_a;
int *a = (int *)malloc(sizeof(int)*(N));
for(i_a = 0; i_a < N; i_a++)
scanf("%d", &a[i_a]);
long long out_ = solve(N,a);
printf("Output is %lld",out_);
}
}