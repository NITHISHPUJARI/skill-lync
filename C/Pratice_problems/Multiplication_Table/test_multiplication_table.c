#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "multiplication_table.h"

void test_single_table() {
    char* expected_output = 
        "| 2 x 1 = 2   |\n"
        "| 2 x 2 = 4   |\n"
        "| 2 x 3 = 6   |\n"
        "| 2 x 4 = 8   |\n"
        "| 2 x 5 = 10 |\n"
        "| 2 x 6 = 12  |\n"
        "| 2 x 7 = 14  |\n"
        "| 2 x 8 = 16  |\n"
        "| 2 x 9 = 18  |\n"
        "| 2 x 10 = 20 |\n"
        "|-------------|\n\n"; // Added a missing newline character at the end

    char* actual_output = generate_multiplication_tables(2, 2);
    assert(strcmp(actual_output, expected_output) == 0);
    free(actual_output);
    printf("test_single_table passed.\n");
}

void test_table_range() {
    char* expected_output = 
        "| 3 x 1 = 3   | 4 x 1 = 4   |\n"
        "| 3 x 2 = 6   | 4 x 2 = 8   |\n"
        "| 3 x 3 = 9   | 4 x 3 = 12  |\n"
        "| 3 x 4 = 12  | 4 x 4 = 16  |\n"
        "| 3 x 5 = 15 | 4 x 5 = 20 |\n"
        "| 3 x 6 = 18  | 4 x 6 = 24  |\n"
        "| 3 x 7 = 21  | 4 x 7 = 28  |\n"
        "| 3 x 8 = 24  | 4 x 8 = 32  |\n"
        "| 3 x 9 = 27  | 4 x 9 = 36  |\n"
        "| 3 x 10 = 30 | 4 x 10 = 40 |\n"
        "|-------------|-------------|\n\n"; // Added a missing newline character at the end

    char* actual_output = generate_multiplication_tables(3, 4);
    assert(strcmp(actual_output, expected_output) == 0);
    free(actual_output);
    printf("test_table_range passed.\n");
}

void test_invalid_input_zero() {
    char* actual_output = generate_multiplication_tables(0, 4);
    assert(actual_output == NULL);
    printf("test_invalid_input_zero passed.\n");
}

void test_invalid_input_range() {
    char* actual_output = generate_multiplication_tables(5, 4);
    assert(actual_output == NULL);
    printf("test_invalid_input_range passed.\n");
}

int main() {
    test_single_table();
    test_table_range();
    test_invalid_input_zero();
    test_invalid_input_range();
    printf("All tests passed!\n");
    return 0;
}