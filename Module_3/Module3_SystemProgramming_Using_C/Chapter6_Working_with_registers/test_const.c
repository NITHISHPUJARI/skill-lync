#include <stdio.h>

const int Data;

int main()
{
    const int MaxVal = 255;
    const float Temp1;
    const float Temp = 55.12;
    const char Message[] = "Bye World!!!";

    printf("The default value of  Data : %d\r\n", Data);
    printf("The default value of  Temp1 : %f\r\n", Temp1);

    printf("MaxVal: %d\r\n", MaxVal);
    printf("Temp: %f\r\n", Temp);
    printf("Message: %s\r\n", Message);

    return 0;
}