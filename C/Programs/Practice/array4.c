#include <stdio.h>
#include <string.h>

int main() {
    char Name[50];
    int Roll[5];
    int Div[5];
    int marks[5];

    for(int i=0; i<5; i++)
    {
        printf("Enter Name%d: ", i);
        //fgets(Name[i], 50, stdin);
        scanf("%s", &Name[i]);
    }

    for(int i = 0; i < 5; i++)
    {
    printf("Roll%d: ", i);
    scanf("%d", &Roll[i]);
    }

    for(int i=0 ; i < 5; i++)
    {
    printf("Div%d: ", i);
    scanf("%d", &Div[i]);
    }

    for(int i = 0; i < 5; i++) {
        printf("Enter subject%d marks: ", i+1);
        scanf("%d", &marks[i]);
    }

    printf("\nName: %sRoll: %d\nDiv: %d\n", Name, Roll, Div);
    for(int i = 0; i < 5; i++)
        printf("Marks of subject%d: %d\n", i+1, marks[i]);

    return 0;
}