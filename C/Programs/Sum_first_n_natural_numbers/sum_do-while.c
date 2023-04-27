#include <stdio.h>

int main() {
   int i =1, sum = 0;
   do{
    sum +=i;
    i++;
   }

   while(i<=10) ;

   printf("The sum of the first 10 natural numbers is %d", sum);
}
