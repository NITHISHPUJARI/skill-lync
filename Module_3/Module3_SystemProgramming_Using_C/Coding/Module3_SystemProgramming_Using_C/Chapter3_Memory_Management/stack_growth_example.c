// Program to check whether stack grows
// downward or upward.
#include <stdio.h>

void func(int *arg_addr)
{
    // Function Local Variable :
    int func_local = 2;
    // Compare address of argument with 
    // address function local variable 
    if (arg_addr < &func_local)
        printf("Stack grows upward\n");
    else
        printf("Stack grows downward\n");

    // Incr the variable:
    func_local++;
    // Call the function again to grow stack:
    func(&func_local);
}

int main()
{
    // Main local variable
    int main_local = 1;

    func(&main_local);
    return 0;
}
