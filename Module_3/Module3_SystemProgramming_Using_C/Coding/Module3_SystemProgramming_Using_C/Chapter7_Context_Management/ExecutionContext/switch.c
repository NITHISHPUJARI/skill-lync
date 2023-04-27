/* This example shows the usage of getcontext() and setcontext()*/
#include <stdio.h>
#include <ucontext.h>

int x = 0;
ucontext_t context, *cp = &context;
void func(void)
{
    x++;// Incr the x value

    setcontext(cp); // set context to pointed by cp
    // The function never comes here because we switched back to context pointed by cp
    printf("How did i reach here!!!!\r\n");
}

int main(void)
{   
    // saves the context of main with the getcontext() statement.
    getcontext(cp);
    if (!x){
        printf("[%s:%d]\t[Value X = %d]\tgetcontext has been called\r\n",__FUNCTION__,__LINE__,x);
        func();
    }
    else{
        printf("[%s:%d]\t[Value X = %d]\tsetcontext has been called\r\n", __FUNCTION__, __LINE__,x);
    }
    printf("[%s:%d]\tFinnaly Exiting!!!\r\n",__FUNCTION__,__LINE__);
    return 0;
}

