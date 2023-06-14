#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char str[100], new_str[100],j;
    printf("Enter a String: ");
    fgets(str,100, stdin);

    for (int i = 0; str[i] != '\0'; i++)
    {
        str[i] = tolower(str[i]);
        if(str[i] != 'a' && str[i] != 'e' && str[i] != 'i' && str[i] != 'o' && str[i] != 'u')
        {
            new_str[j] = str[i];
            j++;
        }   
        
    }
    

    printf("String after removing vowels: %s\n", new_str);

    return 0;
}