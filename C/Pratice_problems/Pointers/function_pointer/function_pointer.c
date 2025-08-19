#include<stdio.h>

float add(float a, float b) 
{
    return a+b;
}
float sub(float a, float b)
{
    return a-b;
}
float mul(float a, float b)
{
    return a*b;
}
float divi(float a, float b)
{
    return a/b;
}


typedef struct {
    char op;
    float (*function) (float, float);
} calulation;


int main()

{
    
    float num1, num2;
    char ope;
    
    calulation oper [] = {
        {'+' , add}, {'-' , sub}, {'*', mul}, {'/', divi}
    };
    
    
    printf("enter the 1st num: " );
    scanf("%f", &num1);
    
    printf("enter the operator: " );
    scanf(" %c", &ope);
    
    printf("enter the 2nd num: " );
    scanf("%f", &num2);
    
    
    for (int i = 0; i<4; i++)
    {
        if (oper[i].op == ope)
        {
            float result = oper[i].function (num1, num2);
            printf("result %f", result);
        }
    }
    
    return 0;
    
}