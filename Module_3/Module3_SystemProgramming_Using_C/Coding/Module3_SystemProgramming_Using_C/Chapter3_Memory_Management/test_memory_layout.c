#include <stdio.h>

int Global; /* Uninitialized variable stored in bss*/
 
int main(void)
{
    static int i; /* Uninitialized static variable stored in bss */
	static int Count = 100; /* Initialized static variable stored in data */
    return 0;
}
