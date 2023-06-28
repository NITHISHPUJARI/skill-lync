#include <stdio.h>
#include <assert.h>
#include "calculator.h"

void test_add() {
    assert(add(2, 3) == 5);
    assert(add(0, 0) == 0);
    assert(add(-5, 5) == 0);
    printf("Addition test passed.\n");
}

void test_subtract() {
    assert(subtract(5, 2) == 3);
    assert(subtract(0, 0) == 0);
    assert(subtract(10, 5) == 5);
    printf("Subtraction test passed.\n");
}

void test_multiply() {
    assert(multiply(3, 4) == 12);
    assert(multiply(0, 5) == 0);
    assert(multiply(-2, 6) == -12);
    printf("Multiplication test passed.\n");
}

void test_divide() {
    assert(divide(10, 2) == 5);
    assert(divide(0, 5) == 0);
    assert(divide(-12, 3) == -4);
    printf("Division test passed.\n");
}

int main() {
    test_add();
    test_subtract();
    test_multiply();
    test_divide();

    return 0;
}
