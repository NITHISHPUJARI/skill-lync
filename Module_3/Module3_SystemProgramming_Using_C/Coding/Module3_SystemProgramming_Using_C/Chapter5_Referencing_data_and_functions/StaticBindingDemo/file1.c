#include <stdio.h>
#include "file1.h"
// Static variable:
static int StaticVariable = 10;

// static function:
static int AlterTheValueWithStatic(int a)
{
    printf("[%s:%d][%s]Value of a = %d\r\n", __FILE__, __LINE__, __func__, a);
    printf("[%s:%d][%s]Value of -> a * StaticVariable = %d\r\n", __FILE__, __LINE__, __func__, a * StaticVariable);
    return a * StaticVariable;
}

int ModifyTheVariable(int a)
{
    printf("[%s:%d][%s]Value of a = %d\r\n", __FILE__, __LINE__, __func__, a);

    return AlterTheValueWithStatic(a);
}
