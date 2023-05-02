/*#include<stdio.h>
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

    printf("Enter Name: ");
    fgets(Name, 50, stdin);
    //scanf(" %s[^\n]", Name);
    printf("Roll: ");
    scanf("%d", &Roll);
    printf("Div: ");
    scanf("%d", &Div);

    for(int i = 1; i <6 ; i++)
    {
        printf("Enter subject%d marks:", i);
        scanf("%d", &marks[i]);
    }

    printf("\nName: %sRoll: %d\nDiv: %d\n", Name, Roll, Div);
    for(int i = 1; i <6; i++)
    printf("Marks of subject%d: %d\n", i, marks[i]);
}*/

#include <stdio.h>
#include <string.h>

int main() {
    char Name[50];
    int Roll;
    int Div;
    int marks[5];

    printf("Enter Name: ");
    fgets(Name, 50, stdin);

    printf("Roll: ");
    scanf("%d", &Roll);

    printf("Div: ");
    scanf("%d", &Div);

    for(int i = 0; i < 5; i++) {
        printf("Enter subject%d marks: ", i+1);
        scanf("%d", &marks[i]);
    }

    printf("\nName: %sRoll: %d\nDiv: %d\n", Name, Roll, Div);
    for(int i = 0; i < 5; i++)
        printf("Marks of subject%d: %d\n", i+1, marks[i]);

    return 0;
}
