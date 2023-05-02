#include<stdio.h>
#include<string.h>

int main()
{
    //char Name[50] = {"Pujari Nithish Kumar"};
    char Name[50];
    //int Roll = 183410259;
    int Roll;
    //int Div = 10;
    int Div;
    int marks[5];
    float sum = 0;
    float avg = 0;
    float percentange;

    printf("Enter Name: ");
    fgets(Name, 50, stdin);

    printf("Roll: ");
    scanf("%d", &Roll);

    printf("Div: ");
    scanf("%d", &Div);

    for(int i = 0; i < 5; i++)
    {
        printf("Enter subject%d marks:", i+1);
        scanf("%d", &marks[i]);
        sum += marks[i];
    }

    avg = sum/5;
    float a = sum*100;
    percentange = a/125;
    

    printf("\nName: %sRoll: %d\nDiv: %d\n", Name, Roll, Div);

    for(int i = 0; i < 5; i++)
    printf("Marks of subject%d: %d\n", i+1, marks[i]);

    printf("Sum: %.2f\nAverage: %.2f\nPercentage: %.2f", sum, avg, percentange);
}