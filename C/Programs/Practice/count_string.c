#include<stdio.h>
#include<string.h>

int main()
{
    int count = 0;
    int dig_count = 0;
    int space_count = 0;
    int vowel_count = 0;
    int constant_count = 0;
    char a[20];
    printf("enter the string: ");
    fgets(a,20,stdin);
    int i;

    for(i = 0; a[i] != '\0'; i++)
    {
        count++;
    
        if (a[i] >= '0' && a[i] <= '9')
        {
            dig_count++;
        }
        if (a[i] == ' ')
        {
            space_count++;
        }
        if (a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u')
        {
            vowel_count++;
        }
        if ((a[i] >= 'a' && a[i] <= 'z') || (a[i] >= 'A' && a[i] <= 'Z'))
        {
            if (a[i] != 'a' && a[i] != 'e' && a[i] != 'i' && a[i] != 'o' && a[i] != 'u')
            {
                constant_count++;
            }
        }
    }
    printf("No of integers: %d\n", dig_count);
    printf("No of characters entered is: %d\n",count);
    printf("No of Spaces: %d\n", space_count);
    printf("No of vowels: %d\n", vowel_count);
    printf("No of consonants: %d\n", constant_count);

    return 0;
}
