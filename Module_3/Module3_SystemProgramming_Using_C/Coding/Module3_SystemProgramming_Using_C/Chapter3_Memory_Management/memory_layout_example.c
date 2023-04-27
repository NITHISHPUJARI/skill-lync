#include <stdio.h>

/* global variables stored in the read-write part of
   initialized data segment
 */
int global_var = 50;
char *hello = "Hello World";

/* global variables stored in the read-only part of
   initialized data segment
 */
const int global_var2 = 30;

// Uninitialized global variable stored in the bss segment
int global_variable; 

void foo() {
    // local variables stored in the stack
    // when the function call is made
    int a, b;
}

int main()
{
  // static variable stored in initialized data segment
  static int a = 10;
  
  // Uninitialized static variable stored in bss
  static int static_variable;

  // memory allocated in heap segment
  char *var = (char*) malloc ( sizeof(char) ); 

  // local variables stored in the stack
  int local = 5;
  char name[26];

  foo();

  // ...
  return 0;
}
