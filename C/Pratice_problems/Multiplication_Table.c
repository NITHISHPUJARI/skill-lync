#include <stdio.h>
#include <string.h> // Required for strlen()
#include <stdlib.h> // Required for sprintf()

int main() {
    int start_table, end_table;

    // --- 1. Get User Input ---
    printf("Enter the starting table number: ");
    scanf("%d", &start_table);

    printf("Enter the ending table number: ");
    scanf("%d", &end_table);
    printf("\n");

    // --- 2. Input Validation ---
    if (start_table <= 0 || end_table < start_table) {
        printf("Invalid input! 🚫\nPlease ensure the starting number is positive and less than or equal to the ending number.\n");
        return 1; // Exit with an error
    }

    // --- 3. Generate Tables ---
    // The outer loop iterates through the tables in blocks of 5.
    for (int i = start_table; i <= end_table; i += 5) {
        
        int column_widths[5] = {0};
        int tables_in_row = 0;
        char buffer[100];

        // --- PASS 1: Calculate the maximum width for each column in this row ---
        for (int k = i; k < i + 5 && k <= end_table; k++) {
            // The longest string in a table is always the 'x 10' line
            sprintf(buffer, "%d x 10 = %d", k, k * 10);
            column_widths[tables_in_row] = strlen(buffer);
            tables_in_row++;
        }

        // --- PASS 2: Print the multiplication lines using the calculated widths ---
        for (int j = 1; j <= 10; j++) { // Multiplier loop (1 to 10)
            for (int k = 0; k < tables_in_row; k++) {
                int current_table_num = i + k;
                sprintf(buffer, "%d x %d = %d", current_table_num, j, current_table_num * j);
                // The `%-*s` format prints a string (s), left-aligned (-),
                // with a dynamic width passed as an argument (*).
                printf("| %-*s ", column_widths[k], buffer);
            }
            printf("|\n");
        }

        // --- PASS 3: Print the dynamically sized separator line ---
        for (int k = 0; k < tables_in_row; k++) {
            printf("|");
            // Print dashes matching the width of the column + padding spaces
            for (int d = 0; d < column_widths[k] + 2; d++) {
                printf("-");
            }
        }
        printf("|\n\n");
    }

    return 0;
}