#include <stdio.h>

int main() {
   int n, i, square, cube;
   
   printf("Enter an integer n: ");
   scanf("%d", &n);
   
   for (i = 1; i <= n; i++) {
      square = i * i;
      cube = i * i * i;
      //printf("Value \t Square \t cube \t\n %d\t%d\t%d\n", i, square, cube);
      printf("Value %d\t Square %d\t Cube %d\n", i, square, cube);
   }
   
}
