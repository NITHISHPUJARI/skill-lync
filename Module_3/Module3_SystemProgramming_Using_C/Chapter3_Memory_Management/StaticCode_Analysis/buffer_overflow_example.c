#include <stdio.h>
#include <string.h>

int main(void)
{
    char buff[15];
    int pass = 0;

    printf("\r\nEnter the password :\r\n");
    gets(buff);

    if(strcmp(buff, "MySafePassword"))
    {
        printf ("Wrong Password \r\n");
    }
    else
    {
        printf ("Correct Password\r\n");
        pass = 1;
    }

    if(pass)
    {
       /* Now Give root or admin rights to user*/
        printf ("Root privileges given to the user\r\n");
    }

    return 0;
}