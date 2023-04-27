// gcc -g illegal_write.c -o illegal_write
// $ valgrind  ./illegal_write 
#include <stdlib.h>
int main()
{
  // Pointing Zero memory addr
  int *ptr=0; 
  // Writing to Zero memory addr 
  // Note: address is not in program
  (*ptr)=33;  
  return 0;
} 