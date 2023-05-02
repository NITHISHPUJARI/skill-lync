#include<stdio.h>
#include <string.h>

typedef struct {
    char name[50] ;
    int roll;
    int div;
} Nithish;

int main()
{
    Nithish a;
    strcpy(a.name, "Pujari Nithish Kumar");
    a.roll = 183410259;
    a.div = 10;

    printf("Name: %s\nRoll: %d\nDiv: %d\n", a.name, a.roll, a.div);

}