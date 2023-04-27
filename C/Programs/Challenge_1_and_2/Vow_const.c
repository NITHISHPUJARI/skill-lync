#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char str[100];
    unsigned long int vowels = 0, consonants = 0, i;

    printf("Enter a string: ");
    scanf("%s", &str);

    for (i = 0; i < strlen(str); i++) {
        switch (tolower(str[i])) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                vowels++;
                break;
            default:
                consonants++;
                break;
        }
    }

    printf("Number of vowels: %ld\n", vowels);
    printf("Number of consonants: %ld\n", consonants);

    return 0;
}
