#include <stdint.h>
#include <stdio.h>
// Function to calculate the factorial
// Uses loop:
uint32_t factorial(uint32_t n)
{
  uint32_t result = 1;
  for (; n > 1; --n)
  {
    result *= n;   
  }

  return result;
}

// Function to calculate the factorial
// Uses recursion: 
uint32_t factorialRecursive(uint32_t n)
{
  return n > 1 ? n * factorialRecursive(n - 1) : 1;
}


int main(){
    uint32_t Number = 5;
    uint32_t FactFunc;
    uint32_t FactRec;

    FactFunc = factorial(Number);
    FactRec = factorialRecursive(Number);

    printf("Factorial using: factorial(%d)          :  %d\r\n", Number, FactFunc);
    printf("Factorial using: factorialRecursive(%d) :  %d\r\n", Number, FactRec);


}