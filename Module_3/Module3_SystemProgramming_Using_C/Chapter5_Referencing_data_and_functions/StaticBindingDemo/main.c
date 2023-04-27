// C program to illustrate the global scope

#include <stdio.h>
#include "file1.h"

// Global variable
int global = 5;

// Static variable:
static int StaticVariable = 50;

// static function:
static int AlterTheValueWithStatic(int a)
{
    printf("[%s:%d][%s]Value of a = %d\r\n", __FILE__, __LINE__, __func__, a);
    printf("[%s:%d][%s]Value of -> a * StaticVariable = %d\r\n", __FILE__, __LINE__, __func__, a * StaticVariable);
    return a * StaticVariable;
}

// global variable accessed from
// within a function
void display()
{
    printf("[%s:%d][%s]Value of global = %d\r\n", __FILE__, __LINE__, __func__, global);
}

// main function
int main()
{

    printf("[%s:%d][%s]Before change within main: \r\n", __FILE__, __LINE__, __func__);
    printf("[%s:%d][%s]Value of global = %d\r\n", __FILE__, __LINE__, __func__, global);
    display();

    // changing value of global
    // variable from main function
    printf("[%s:%d][%s]After change within main: \r\n", __FILE__, __LINE__, __func__);
    global = 10;
    display();

    {                     // Block A
        int global = 100; // New variable declared insided the block { Block A}
        printf("[%s:%d][%s]-----Inside Block A------: \r\n", __FILE__, __LINE__, __func__);
        printf("[%s:%d][%s]Value of global = %d\r\n", __FILE__, __LINE__, __func__, global);
        display();
        // Alter with function from file1.c/h
        global = ModifyTheVariable(global);
        printf("[%s:%d][%s]-----Block A Ends-----\r\n", __FILE__, __LINE__, __func__);
    }
    printf("[%s:%d][%s]After change within Block A: \r\n", __FILE__, __LINE__, __func__);
    display();

    // Alter with Static Function :
    global = AlterTheValueWithStatic(global);

    printf("[%s:%d][%s]After change value change using static function: \r\n", __FILE__, __LINE__, __func__);
    display();

    return 0;
}
