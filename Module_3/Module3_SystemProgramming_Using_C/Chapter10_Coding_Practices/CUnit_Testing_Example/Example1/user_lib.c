#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <string.h>

int MySum(int a1, int b1)
{
    int res1;
    res1 = a1 + b1;
    return res1;
}

int MyDiff(int a2, int b2)
{
    int res2;
    res2 = a2 - b2;
    return res2;
}

/*
    Compares the two numbers:
    Returns:
        0   -> number1 == number2
        1   -> number1 > number2
        -1  -> number1 < number2
*/
int MyCompare(int number1, int number2)
{
    // Variable to save result
    int Result;

    if (number1 >= number2)
    {
        if (number1 == number2)
        {
            printf("Result: %d == %d\r\n", number1, number2);
            Result = 0;
        }
        else
        {
            printf("Result: %d > %d\r\n", number1, number2);
            /*
                Expected to write: 1   -> number1 > number2
                But to Simulate error setting Result = 0
                This kind of error is can happen unknowingly when you write large 
                Nested IF -  ELSE IF conditions.
                This could affect the behaviour of other code using this function.
                With unit test we can get the exact condition the test fails.
            */
            Result = 0;
        }
    }
    else
    {
        printf("Result: %d < %d\r\n", number1, number2);
        Result = -1;
    }
    return Result;
}