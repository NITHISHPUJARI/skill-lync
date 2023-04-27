#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <string.h>
#include "CUnit/Basic.h"
#include "user_lib.h"

int init_suite(void) { return 0; }
int clean_suite(void) { return 0; }

// Test Cases for MySum()
void test_MySum(void)
{
    CU_ASSERT(4 == MySum(2, 2));
    CU_ASSERT(8 == MySum(5, 3));
    CU_ASSERT(2 == MySum(-2, 4));
    CU_ASSERT(7 == MySum(0, 7));
}
// Test Cases for MyDiff()
void test_MyDiff(void)
{
    CU_ASSERT(3 == MyDiff(5, 2));
    CU_ASSERT(-4 == MyDiff(4, 8));
    CU_ASSERT(-7 == MyDiff(-3, 4));
    CU_ASSERT(-9 == MyDiff(0, 9));
}

// Test Cases for MyCompare()
void test_MyCompare(void)
{
    CU_ASSERT(0 == MyCompare(50, 50));
    CU_ASSERT(1 == MyCompare(50, 8));
    CU_ASSERT(-1 == MyCompare(3, 4));
}


int main(void)
{
    CU_pSuite pSuite1, pSuite2 = NULL;

    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    pSuite1 = CU_add_suite("Test Suite1", init_suite, clean_suite);
    if (NULL == pSuite1)
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    if ((NULL == CU_add_test(pSuite1, "\r\nMySum() function Testing\r\n", test_MySum)))
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    if ((NULL == CU_add_test(pSuite1, "\r\nMyDiff() function Testing\r\n", test_MyDiff)))
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    if ((NULL == CU_add_test(pSuite1, "\r\nMyCompare() function Testing\r\n", test_MyCompare)))
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
