#include <stdio.h>
#include <string.h>

// Union
union Data
{
    int i;        // 1 byte
    float f;      // 4 bytes
    char str[20]; // 20 bytes
};

int main()
{
    // Declare the union variable
    union Data data, data2;

    // Asign all the values to the union members
    data.i = 10;
    data.f = 220.5;
    strcpy(data.str, "System Programing");

    printf("\r\nAssign values to all members at a time:\r\n");
    printf("data.i : %d\n", data.i);
    printf("data.f : %f\n", data.f);
    printf("data.str : %s\n", data.str);

    // Now lets use one member at a time:
    printf("\r\nNow we will use one variable at a time:\r\n");
    data2.i = 10;
    printf("data2.i : %d\r\n", data2.i);

    data2.f = 220.5;
    printf("data2.f : %f\r\n", data2.f);

    strcpy(data2.str, "System Programing");
    printf("data2.str : %s\r\n", data2.str);

    return 0;
}