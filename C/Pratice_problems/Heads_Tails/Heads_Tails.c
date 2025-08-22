#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h> // Required for usleep()

// Function to clear the terminal screen
void clearScreen() {
    // Uses ANSI escape codes to clear the screen and move the cursor to the top-left
    printf("\033[2J\033[H");
}

// Function to display the spinning animation
void animateFlip() {
    char spinner[] = "|/-\\";
    printf("Flipping the coin... ");
    for (int i = 0; i < 20; i++) {
        printf("%c", spinner[i % 4]);
        fflush(stdout); // Force output to be written to the screen
        usleep(100000); // Sleep for 100,000 microseconds (0.1 seconds)
        printf("\b"); // Move the cursor back one space
    }
}

// Function to display the result with ASCII art
void displayResult(int result) {
    clearScreen();
    printf("=====================\n");
    printf("    COIN TOSS\n");
    printf("=====================\n\n");
    printf("The coin landed on:\n\n");

    if (result == 0) { // Heads
        printf("    /───────\\\n");
        printf("   /   HEADS   \\\n");
        printf("  /   ( O )   \\\n");
        printf("  \\           /\n");
        printf("   \\         /\n");
        printf("    \\───────/\n");
    } else { // Tails
        printf("    /───────\\\n");
        printf("   /   TAILS   \\\n");
        printf("  /   ( X )   \\\n");
        printf("  \\           /\n");
        printf("   \\         /\n");
        printf("    \\───────/\n");
    }
    printf("\n=====================\n");
}

int main() {
    // Seed the random number generator with the current time.
    srand(time(NULL));

    char input;

    do {
        clearScreen();
        printf("=====================\n");
        printf("    COIN TOSS\n");
        printf("=====================\n\n");
        printf("Press ENTER to flip the coin (or 'q' to quit): ");
        
        input = getchar();
        // Consume any extra characters in the buffer, like the newline from pressing Enter
        if (input != '\n' && input != 'q' && input != 'Q') {
            while (getchar() != '\n');
        }

        if (input == 'q' || input == 'Q') {
            break;
        }

        clearScreen();
        animateFlip();

        // Generate a random number, either 0 or 1.
        int coin_toss = rand() % 2;

        displayResult(coin_toss);

        printf("\nPress ENTER to flip again (or 'q' to quit): ");
        input = getchar();
        if (input != '\n' && input != 'q' && input != 'Q') {
             while (getchar() != '\n');
        }
       
    } while (input != 'q' && input != 'Q');

    clearScreen();
    printf("Thanks for playing!\n");

    return 0; // Indicate that the program executed successfully.
}
