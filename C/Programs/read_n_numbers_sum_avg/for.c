#include <stdio.h>

int main() {
   int i, num, n;
   float sum = 0, avg;
   
   printf("Enter the value of n: ");
   scanf("%d", &n);

   for (i = 1; i <= n; i++) {
      printf("Enter number %d: ", i);
      scanf("%d", &num);
      sum += num;
   }
   
   avg = sum / n;
   
   printf("The sum of the %d numbers is %.2f\n", n, sum);
   printf("The average of the %d numbers is %.2f", n, avg);
   
}
