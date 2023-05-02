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

    printf("Enter Name: ");
    fgets(Name, 50, stdin);
    printf("Roll: ");
    scanf("%d", &Roll);
    printf("Div: ");
    scanf("%d", &Div);

    printf("\nName: %sRoll: %d\nDiv: %d", Name, Roll, Div);
}