#include <stdio.h>

int main() {
   int lower, upper, num, sum, count = 0;
   
   // Prompt the user to enter a range of numbers
   printf("Enter lower and upper limits of the range: ");
   scanf("%d %d", &lower, &upper);
   
   // Check each number within the range for perfection
   printf("The perfect numbers in the range %d to %d are:\n", lower, upper);
   for (num = lower; num <= upper; num++) {
      sum = 0;
      for (int i = 1; i <= num/2; i++) {
         if (num % i == 0) {
            sum += i;
         }
      }
      if (sum == num) {
         count++;
         printf("%d\n", num);
      }
   }
   
   // Display the number of perfect numbers found
   printf("There are %d perfect numbers in the range %d to %d.", count, lower, upper);

}
