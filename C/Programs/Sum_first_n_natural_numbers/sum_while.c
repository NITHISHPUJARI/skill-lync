#include <stdio.h>

int main() {
   int i =1, sum = 0;

   while(i<=10) {
    i++;
    sum += i;
   }
   printf("The sum of the first 10 natural numbers is %d", sum);
}
