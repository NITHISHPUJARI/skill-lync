// Compile with debug info:   $ gcc -Wall -g hello_memory_leak.c -o hello_memory_leak
// Test with  valgrind:       $ valgrind --tool=memcheck  --leak-check=full  ./hello_memory_leak 

#include <stdlib.h>
int main()
{
  char* ptr=malloc(10); 
  *ptr = 'a';
  return 0;
}