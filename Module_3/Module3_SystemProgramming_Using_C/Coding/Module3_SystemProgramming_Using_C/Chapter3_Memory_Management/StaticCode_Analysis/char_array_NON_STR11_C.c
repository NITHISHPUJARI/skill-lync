// Example code not compliant with 
// STR11-C. 
// Do not specify the bound of a character array initialized with a string literal
#include <stdio.h>

// Hello Message :
static const char message[5] = "Hello";

int main(){
    printf("%s World!!\r\n", message);

    return 0;
}