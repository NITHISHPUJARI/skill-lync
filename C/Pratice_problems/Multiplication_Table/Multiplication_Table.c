#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "multiplication_table.h"

char* generate_multiplication_tables(int start_table, int end_table) {
    if (start_table <= 0 || end_table < start_table) {
        return NULL;
    }

    char* result = (char*)malloc(10000);
    if (result == NULL) {
        return NULL;
    }
    result[0] = '\0';

    char line_buffer[200];

    for (int i = start_table; i <= end_table; i += 5) {
        int column_widths[5] = {0};
        int tables_in_row = 0;
        char buffer[100];

        for (int k = i; k < i + 5 && k <= end_table; k++) {
            sprintf(buffer, "%d x 10 = %d", k, k * 10);
            column_widths[tables_in_row] = strlen(buffer);
            tables_in_row++;
        }

        for (int j = 1; j <= 10; j++) {
            line_buffer[0] = '\0';
            for (int k = 0; k < tables_in_row; k++) {
                int current_table_num = i + k;
                sprintf(buffer, "%d x %d = %d", current_table_num, j, current_table_num * j);
                char temp[100];
                sprintf(temp, "| %-*s ", column_widths[k], buffer);
                strcat(line_buffer, temp);
            }
            strcat(line_buffer, "|\n");
            strcat(result, line_buffer);
        }

        line_buffer[0] = '\0';
        for (int k = 0; k < tables_in_row; k++) {
            strcat(line_buffer, "|");
            for (int d = 0; d < column_widths[k] + 2; d++) {
                strcat(line_buffer, "-");
            }
        }
        strcat(line_buffer, "|\n\n");
        strcat(result, line_buffer);
    }

    return result;
}

#ifndef TESTING
int main() {
    int start_table, end_table;

    printf("Enter the starting table number: ");
    scanf("%d", &start_table);

    printf("Enter the ending table number: ");
    scanf("%d", &end_table);
    printf("\n");

    char* tables = generate_multiplication_tables(start_table, end_table);

    if (tables == NULL) {
        printf("Invalid input! 🚫\nPlease ensure the starting number is positive and less than or equal to the ending number.\n");
        return 1;
    }

    printf("%s", tables);
    free(tables);

    return 0;
}
#endif
