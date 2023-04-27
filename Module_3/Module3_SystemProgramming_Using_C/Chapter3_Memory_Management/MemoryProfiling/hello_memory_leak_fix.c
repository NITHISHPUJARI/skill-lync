// Compile with debug info: $ gcc -g hello_memory_leak_fix.c -o hello_memory_leak_fix
// Test with  valgrind:     $  valgrind --tool=memcheck  --leak-check=full  ./hello_memory_leak_fix
//
#include <stdlib.h>
int main()
{
  void* ptr=malloc(10); 
  free(ptr);
  return 0;
} 