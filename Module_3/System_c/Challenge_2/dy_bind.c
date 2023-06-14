#include <stdio.h>
#include <unistd.h>

// Timer structure
typedef struct {
    void (*start)();
    void (*stop)();
} Timer;

// Timer implementation for countdown
void countdownTimerStart() {
    printf("Countdown timer started.\n");
}

void countdownTimerStop() {
    printf("Countdown timer stopped.\n");
}

// Timer implementation for intervals
void intervalTimerStart() {
    printf("Interval timer started.\n");
}

void intervalTimerStop() {
    printf("Interval timer stopped.\n");
}

int main() {
    // Create timers
    Timer countdownTimer = {
        .start = countdownTimerStart,
        .stop = countdownTimerStop
    };

    Timer intervalTimer = {
        .start = intervalTimerStart,
        .stop = intervalTimerStop
    };

    // Start and stop timers
    Timer* timers[] = { &countdownTimer, &intervalTimer };
    size_t numTimers = sizeof(timers) / sizeof(timers[0]);

    for (size_t i = 0; i < numTimers; i++) {
        timers[i]->start();
        usleep(2000000);  // Simulated delay of 2 seconds
        timers[i]->stop();
        printf("\n");
    }

    return 0;
}
