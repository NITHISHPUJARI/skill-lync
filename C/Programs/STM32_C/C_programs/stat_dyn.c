#include <stdio.h>
#include <stdlib.h>

int main() {
   
    int static_var;
    printf("Static variable: %p\n", &static_var);

   
    int *dynamic_var = (int *)malloc(sizeof(int));
    if (dynamic_var == NULL) {
        printf("Dynamic memory allocation failed.\n");
        return 1;
    }
    printf("Dynamic variable: %p\n", dynamic_var);

   
    free(dynamic_var);

    return 0;
}
