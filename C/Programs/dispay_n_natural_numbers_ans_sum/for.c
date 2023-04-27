#include<stdio.h>

int main()
{
    int i, n,  sum = 0;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    for(i=1;i<=n;i++) {
        printf("%d \n",i);
        sum += i;
    }
    printf("The sum of the first %d natural numbers is %f", n, (float) sum);

}

/* switch(expression) {
    case constant-expression:
        statatement;
        break;
    
    case constant-expression:
        staatement;
        break;
    
    default:
    statement;
    
} */